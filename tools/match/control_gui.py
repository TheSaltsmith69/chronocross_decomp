#!/usr/bin/env python3
"""control_gui.py [--port 8765] -- web control panel for the permuter and the local-LLM loop.

Serves tools/match/gui/index.html at http://localhost:PORT/ and runs, one each at a time:
  * the permuter      tools/match/permute_all.sh QUEUE MIN JOBS [fresh] [stall=M]
  * the LLM loop      tools/match/llm_iterate.py ...
  * m2c drafting      tools/match/refill_queue.py [FUNC...] (drafts go to permuter/cands + queue.txt)
Each job gets its own pseudo-terminal, so permwatch.py and the LLM's streamed thinking behave
exactly as in a console window; the output is kept in memory for the page and appended to
permuter/gui/<job>.log.

What a job works on is either the squares picked on the page (in pick order) or an ordered list:
  permuter/queue.txt                      the permuter queue ("CANDS.c FUNC [IDX]" lines)
  tools/match/parked_<ov>.txt             the parked lists
  "permuter results"                      what llm_iterate.py --permuted would do
  permuter/lists/<name>.txt               lists saved from the page (one FUNC per line; queue-style
                                          "CANDS.c FUNC IDX" lines work too)
The permuter can only take functions that have a candidate (a queue line or an existing
permuter/nonmatchings/FUNC folder); others are skipped and reported. A picked selection runs with
its own resume file (permuter/gui/resume_selection.txt), so permuter/resume.txt keeps tracking the
main queue.

Settings from the page are saved in permuter/gui/settings.json; permuter weights are written to
tools/match/permuter_weights.toml (line by line, comments kept), LLM tips to tools/match/llm_tips.md.
Stdlib only. Start it with C:\\Users\\...\\ChronoCross\\run_gui.bat.
"""
import argparse, codecs, csv, fcntl, glob, json, os, re, shlex, signal, struct, subprocess, sys, termios
import threading, time
from collections import deque
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import fnotes, gui_diff, gui_hw, pauseclock

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
HERE = os.path.dirname(os.path.abspath(__file__))
PY = os.path.join(ROOT, ".venv", "bin", "python3")
GUI = os.path.join(ROOT, "permuter", "gui")
LISTS = os.path.join(ROOT, "permuter", "lists")
NONM = os.path.join(ROOT, "permuter", "nonmatchings")
QUEUE = os.path.join(ROOT, "permuter", "queue.txt")
WEIGHTS = os.path.join(HERE, "permuter_weights.toml")
DEFAULT_WEIGHTS = os.path.join(ROOT, "tools", "decomp-permuter", "default_weights.toml")
TIPS = os.path.join(HERE, "llm_tips.md")
SETTINGS = os.path.join(GUI, "settings.json")
CURL_EXE = "/mnt/c/Windows/System32/curl.exe"
DRAFT_MATCH = re.compile(r"\bratio 1\.0+\b")     # refill_queue.py's note on a draft that matches
FUNC_RE = re.compile(r"\b(func_[0-9A-Fa-f]{8}|[A-Za-z_]\w*)\b")

DEFAULTS = {
    "perm": {"minutes": 20, "threads": 8, "stall": 5, "nice": 19, "fresh": False, "every": False,
             "auto_draft": True, "from_draft": False, "keep_prob": 0.6, "speed": 100, "stack_diffs": False, "profile": "balanced"},
    "llm": {"compiles": 40, "minutes": 30, "think": 8000, "think_mode": "budget", "variants": 3,
            "temperature": 0.6, "ctx": 131072, "examples": 2, "skip_done": True, "quiet": False,
            "rounds": 0, "model": "", "base_url": ""},
    "m2c": {"min_ratio": 0.3, "limit": 0, "nice": 10, "dry_run": False},
    # CPU guard: pause the chosen engines while OTHER programs (Windows load minus WSL's own) use
    # at least `threshold` % for `trigger_secs`; resume once below `resume_below` % for `resume_secs`
    "guard": {"enabled": False, "threshold": 40, "trigger_secs": 10, "resume_below": 25, "resume_secs": 30,
              "perm": True, "m2c": True, "llm": False},
    "hw": {"cpu_idle_w": 15, "cpu_max_w": 250, "price": 0.15, "currency": "$"},
    # night shift: stages run one after another, each for up to `hours` (paused time not counted)
    "night": {"start_at": "", "stages": [
        {"engine": "m2c", "on": True, "source": {"type": "list", "list": "parked:ov_battle"}, "hours": 0.5},
        {"engine": "perm", "on": True, "source": {"type": "list", "list": "queue"}, "hours": 6},
        {"engine": "llm", "on": True, "source": {"type": "list", "list": "permuted"}, "hours": 2},
    ]},
}
os.makedirs(GUI, exist_ok=True)
os.makedirs(LISTS, exist_ok=True)


def read(path, default=""):
    try:
        with open(path, encoding="utf-8", errors="replace") as f:
            return f.read()
    except OSError:
        return default


def load_settings():
    s = json.loads(json.dumps(DEFAULTS))
    try:
        saved = json.loads(read(SETTINGS, "{}"))
        for k in s:
            s[k].update({kk: vv for kk, vv in saved.get(k, {}).items() if kk in s[k]})
    except ValueError:
        pass
    return s


def save_settings(s):
    tmp = SETTINGS + ".tmp"
    with open(tmp, "w") as f:
        json.dump(s, f, indent=2)
    os.replace(tmp, SETTINGS)


# ---------------------------------------------------------------- jobs (pty-backed processes)

ANSI_K = re.compile(r"\x1b\[[0-9]*[KJHG]|\x1b\[\?[0-9;]*[hl]")
ANSI_ALL = re.compile(r"\x1b\[[0-9;?]*[A-Za-z]")


def session_pgids(sid):
    """Process groups of every process in session SID (a job runs in its own session, and
    ptimeout.py puts the permuter in a group of its own inside it)."""
    groups = set()
    for d in os.listdir("/proc"):
        if not d.isdigit():
            continue
        try:
            with open(f"/proc/{d}/stat") as f:
                fields = f.read().rsplit(")", 1)[1].split()
        except (OSError, IndexError):
            continue
        if int(fields[3]) == sid:              # state ppid pgrp session ...
            groups.add(int(fields[2]))
    return groups


def signal_session(sid, sig):
    for g in session_pgids(sid):
        try:
            os.killpg(g, sig)
        except (ProcessLookupError, PermissionError):
            pass


class Job:
    def __init__(self, name):
        self.name = name
        self.proc = None
        self.lines = deque(maxlen=5000)
        self.seq = 0                  # number of lines ever committed
        self.partial = ""             # the line being written (status lines overwrite it)
        self.lock = threading.Lock()
        self.started = self.ended = None
        self.exit = None
        self.desc = ""
        self.cmd = []
        self.current = None           # function being worked on
        self.best = {}                # func -> best text seen this run
        self.order = []               # the run's functions, in order
        self.done = set()
        self.stopping = False
        self.log = os.path.join(GUI, f"{name}.log")
        self.ledger = os.path.join(GUI, f"{name}.pause")     # see pauseclock.py
        self.pause_total = 0.0
        self.pause_since = 0.0
        self.paused_by = None         # None, "you", "guard" or "night"

    def running(self):
        return self.proc is not None and self.proc.poll() is None

    def paused(self):
        return self.running() and self.pause_since > 0

    def paused_now(self):
        """seconds spent paused in this run so far"""
        return self.pause_total + (time.time() - self.pause_since if self.pause_since > 0 else 0.0)

    def active_elapsed(self):
        return (time.time() - self.started - self.paused_now()) if self.started else 0.0

    def _signal_all(self, sig):
        signal_session(self.proc.pid, sig)

    def pause(self, by="you"):
        if not self.running() or self.pause_since > 0:
            return False
        self.pause_since = time.time()
        pauseclock.write(self.ledger, self.pause_total, self.pause_since)
        self._signal_all(signal.SIGSTOP)
        self.paused_by = by
        with self.lock:
            self._commit(f"\x1b[33m{time.strftime('%H:%M:%S')} -- paused"
                         + (" by the CPU guard" if by == "guard" else "") + "\x1b[0m")
        EVENTS.add("job", None, f"{NAMES[self.name]} paused" + (" by the CPU guard" if by == "guard" else ""))
        return True

    def resume(self, by=None):
        """by: only resume if it was paused by that (the guard won't undo your own pause)"""
        if not self.running() or self.pause_since <= 0 or (by and self.paused_by != by):
            return False
        self.pause_total += time.time() - self.pause_since
        self.pause_since = 0.0
        pauseclock.write(self.ledger, self.pause_total, 0)
        self._signal_all(signal.SIGCONT)
        self.paused_by = None
        with self.lock:
            self._commit(f"\x1b[33m{time.strftime('%H:%M:%S')} -- resumed\x1b[0m")
        if by is None:
            EVENTS.add("job", None, f"{NAMES[self.name]} resumed")
        return True

    def _commit(self, line):
        self.lines.append(line)
        self.seq += 1
        self.parse(ANSI_ALL.sub("", line))
        try:
            with open(self.log, "a", encoding="utf-8") as f:
                f.write(ANSI_ALL.sub("", line) + "\n")
        except OSError:
            pass

    def parse(self, line):        # overridden
        pass

    def start(self, argv, env, desc, order):
        if self.running():
            raise RuntimeError(f"{self.name} is already running")
        master, slave = os.openpty()
        fcntl.ioctl(slave, termios.TIOCSWINSZ, struct.pack("HHHH", 60, 240, 0, 0))
        self.pause_total, self.pause_since, self.paused_by = 0.0, 0.0, None
        pauseclock.write(self.ledger, 0, 0)
        full_env = dict(os.environ, TERM="xterm-256color", COLUMNS="240", PYTHONUNBUFFERED="1",
                        PAUSE_LEDGER=self.ledger, **env)
        self.proc = subprocess.Popen(argv, cwd=ROOT, stdin=subprocess.DEVNULL, stdout=slave, stderr=slave,
                                     env=full_env, start_new_session=True, close_fds=True)
        os.close(slave)
        with self.lock:
            self.lines.clear()
            self.partial = ""
            self.started, self.ended, self.exit = time.time(), None, None
            self.desc, self.cmd, self.current = desc, argv, None
            self.best, self.order, self.done, self.total = {}, list(order), set(), None
            self.stopping = False
            self._commit(f"\x1b[2m{time.strftime('%H:%M:%S')} $ {' '.join(argv)}\x1b[0m")
        threading.Thread(target=self._reader, args=(master, self.proc), daemon=True).start()
        threading.Thread(target=self._reap, args=(self.proc,), daemon=True).start()
        EVENTS.add("job", None, f"{NAMES[self.name]} started: {desc}")

    def _reap(self, proc):
        """Once the job's own process has exited, kill whatever it left in its session
        (orphaned workers would keep the pty open, so the reader would never finish)."""
        proc.wait()
        time.sleep(2)
        signal_session(proc.pid, signal.SIGKILL)

    def _reader(self, fd, proc):
        dec = codecs.getincrementaldecoder("utf-8")(errors="replace")
        cr = False
        while True:
            try:
                data = os.read(fd, 65536)
            except OSError:
                data = b""
            if not data:
                break
            text = ANSI_K.sub("", dec.decode(data))
            with self.lock:
                for ch in text:
                    if cr:
                        cr = False
                        if ch == "\n":
                            self._commit(self.partial)
                            self.partial = ""
                            continue
                        self.partial = ""         # a bare \r: the status line is being rewritten
                    if ch == "\r":
                        cr = True
                    elif ch == "\n":
                        self._commit(self.partial)
                        self.partial = ""
                    else:
                        self.partial += ch
                        if len(self.partial) > 20000:     # streamed thinking with no newline
                            self._commit(self.partial)
                            self.partial = ""
        os.close(fd)
        code = proc.wait()
        with self.lock:
            if self.partial:
                self._commit(self.partial)
                self.partial = ""
            self.exit, self.ended = code, time.time()
            if self.pause_since > 0:
                self.pause_total += time.time() - self.pause_since
                self.pause_since = 0.0
            self.paused_by = None
            self._commit(f"\x1b[2m{time.strftime('%H:%M:%S')} -- exited with code {code}\x1b[0m")
            self.current = None
        EVENTS.add("job", None, f"{NAMES[self.name]} finished ({self.desc}, exit {code})")
        WATCH.poke()
        INSNS.poke()

    def stop(self):
        if not self.running():
            return False
        self.stopping = True
        proc = self.proc
        if self.pause_since > 0:          # a stopped process can't act on SIGINT: wake it first
            self.resume()

        def escalate():
            for sig, wait in ((signal.SIGINT, 20), (signal.SIGTERM, 15), (signal.SIGKILL, 0)):
                if sig == signal.SIGKILL:
                    signal_session(proc.pid, sig)       # every group, incl. ptimeout's child group
                else:
                    try:
                        os.killpg(proc.pid, sig)        # the job's own group; ptimeout passes it on
                    except ProcessLookupError:
                        return
                for _ in range(wait * 4):
                    if proc.poll() is not None:
                        signal_session(proc.pid, signal.SIGKILL)    # leftovers holding the pty
                        return
                    time.sleep(0.25)
        threading.Thread(target=escalate, daemon=True).start()
        return True

    def state(self, since):
        with self.lock:
            first = self.seq - len(self.lines)
            since = max(since, first)
            new = list(self.lines)[since - first:] if since < self.seq else []
            return {"running": self.running(), "stopping": self.stopping and self.running(),
                    "paused": self.paused(), "paused_by": self.paused_by if self.paused() else None,
                    "active": round(self.active_elapsed()), "paused_secs": round(self.paused_now()),
                    "pid": self.proc.pid if self.proc else None, "started": self.started,
                    "ended": self.ended, "exit": self.exit, "desc": self.desc, "current": self.current,
                    "best": self.best, "order": self.order, "done": sorted(self.done),
                    "total": getattr(self, "total", None),
                    "seq": self.seq, "lines": new, "partial": self.partial, "reset": since == first and since > 0}


class PermJob(Job):
    START = re.compile(r"^\d\d:\d\d (\w+): permuting for")
    DONE = re.compile(r"^(\w+): base (\S+) best (\S+)")
    LIVE = re.compile(r"best (\d+)")

    def parse(self, line):
        m = self.START.search(line) or DraftJob.STEP.search(line)
        if m:
            self.current = m.group(1) if m.re is self.START else m.group(3)
            return
        m = self.DONE.search(line)
        if m:
            self.best[m.group(1)] = f"best {m.group(3)} (base {m.group(2)})"
            self.done.add(m.group(1))


class LlmJob(Job):
    TURN = re.compile(r"^\d\d:\d\d:\d\d (func_\w+)(?::| turn| round)")
    RATIO = re.compile(r"\b([01]\.\d{3,})\b")

    def parse(self, line):
        m = self.TURN.search(line)
        if not m:
            return
        f = m.group(1)
        if self.current and self.current != f:
            self.done.add(self.current)
        self.current = f
        if self.best.get(f) == "MATCH":
            return
        if "MATCH" in line:
            self.best[f] = "MATCH"
            return
        rs = [float(x) for x in self.RATIO.findall(line)]
        if rs:
            self.best[f] = f"{max(rs + [float(self.best.get(f) or 0)]):.4f}"


class DraftJob(Job):
    STEP = re.compile(r"^\[(\d+)/(\d+)\] (\w+): (.*)")

    def parse(self, line):
        m = self.STEP.search(line)
        if m:
            f, what = m.group(3), m.group(4)
            self.total = int(m.group(2))
            self.done.add(f)
            self.current = f
            self.best[f] = ("MATCH" if "MATCHES" in what else
                            re.sub(r" \(\d+s\)$", "", what))


JOBS = {"perm": PermJob("perm"), "llm": LlmJob("llm"), "m2c": DraftJob("m2c")}
NAMES = {"perm": "Permuter", "llm": "LLM", "m2c": "m2c"}


# ---------------------------------------------------------------- project data

_cache = {"t": 0, "data": None}
_cache_lock = threading.Lock()


def asm_funcs():
    """Functions still INCLUDE_ASM in src/ (live, unlike functions.csv)."""
    out = set()
    pat = re.compile(r'INCLUDE_ASM\(\s*"[^"]*"\s*,\s*(\w+)\s*\)')
    for p in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
        out.update(pat.findall(read(p)))
    return out


def queue_lines(path=QUEUE):
    out = {}
    for l in read(path).splitlines():
        body, _, comment = l.partition("#")
        p = body.split()
        if len(p) >= 2:
            out.setdefault(p[1], {"cands": p[0], "idx": int(p[2]) if len(p) > 2 and p[2].isdigit() else 0,
                                  "note": comment.strip()})
    return out


def perm_info():
    info = {}
    summ = {}
    for l in read(os.path.join(ROOT, "permuter", "summary.txt")).splitlines():
        m = re.match(r"(\w+): base (\S+) best (\S+)", l)
        if m and m.group(2) != "?":
            summ[m.group(1)] = int(m.group(2))
    for d in glob.glob(os.path.join(NONM, "*")):
        name = os.path.basename(d)
        matched = name.endswith(".matched")
        func = name[:-8] if matched else name
        scores = []
        for o in glob.glob(os.path.join(d, "output-*")):
            m = re.search(r"output-(\d+)-\d+$", o)
            if m:
                scores.append(int(m.group(1)))
        base = read(os.path.join(d, "base.score")).strip()     # original draft's score (permute_all.sh)
        base = int(base) if base.isdigit() else summ.get(func)
        if base is None:
            m = re.search(r"base score = (\d+)", read(os.path.join(ROOT, "permuter", f"{func}.log"))[:65536])
            base = int(m.group(1)) if m else None
        info[func] = {"base": base, "best": 0 if matched else (min(scores) if scores else None),
                      "outputs": len(scores), "matched": matched, "dir": name}
    return info


def llm_info():
    info = {}
    for l in read(os.path.join(ROOT, "permuter", "llm", "summary.txt")).splitlines():
        m = re.search(r"(func_\w+): (MATCH|best ([0-9.]+))", l)
        if m:
            r = 1.0 if m.group(2) == "MATCH" else float(m.group(3))
            prev = info.get(m.group(1))
            if not prev or r >= prev["ratio"]:
                info[m.group(1)] = {"ratio": r, "match": m.group(2) == "MATCH", "line": l.strip()}
    for d in glob.glob(os.path.join(ROOT, "permuter", "llm", "func_*")):
        f = os.path.basename(d)
        info.setdefault(f, {"ratio": None, "match": False, "line": "started"})
    return info


def parked():
    out = {}
    for p in glob.glob(os.path.join(HERE, "parked_*.txt")):
        ov = os.path.basename(p)[7:-4]
        for l in read(p).splitlines():
            if l.strip():
                out[l.strip()] = ov
    return out


def functions():
    with _cache_lock:
        if _cache["data"] and time.time() - _cache["t"] < 4:
            return _cache["data"]
        asm = asm_funcs()
        q = queue_lines()
        pi, li, pk, nt = perm_info(), llm_info(), parked(), fnotes.listing()
        rows = []
        with open(os.path.join(ROOT, "progress", "functions.csv"), newline="") as f:
            for r in csv.DictReader(f):
                n = r["function"]
                src = os.path.exists(os.path.join(ROOT, "src", r["file"] + ".c"))
                matched = (n not in asm) if src else r["matched"] == "1"
                rows.append({"n": n, "a": r["addr"], "f": r["file"], "c": r["category"], "b": int(r["bytes"]),
                             "m": matched, "pk": n in pk, "q": q.get(n), "p": pi.get(n), "l": li.get(n),
                             "i": INSNS.get(n),       # [matched insns, total, source, diffs] or None
                             "nt": nt.get(n)})        # notes/FUNC.md mtime, if it has notes
        _cache.update(t=time.time(), data=rows)
        return rows


def builtin_lists():
    out = [{"id": "queue", "name": "Permuter queue", "kind": "builtin",
            "funcs": list(queue_lines().keys()), "path": "permuter/queue.txt"}]
    for p in sorted(glob.glob(os.path.join(HERE, "parked_*.txt"))):
        ov = os.path.basename(p)[7:-4]
        out.append({"id": f"parked:{ov}", "name": f"Parked: {ov}", "kind": "builtin",
                    "funcs": [l.strip() for l in read(p).splitlines() if l.strip()],
                    "path": f"tools/match/parked_{ov}.txt"})
    pi = perm_info()
    pj = sorted((v["best"], k) for k, v in pi.items() if not v["matched"] and v["best"] is not None)
    out.append({"id": "permuted", "name": "Permuter results (best first)", "kind": "builtin",
                "funcs": [k for _, k in pj], "path": "permuter/nonmatchings/"})
    return out


def parse_list_file(path):
    funcs = []
    for l in read(path).splitlines():
        body = l.split("#")[0].split()
        if not body:
            continue
        funcs.append(body[1] if len(body) >= 2 and body[0].endswith(".c") else body[0])
    return funcs


def user_lists():
    out = []
    for p in sorted(glob.glob(os.path.join(LISTS, "*.txt"))):
        name = os.path.basename(p)[:-4]
        out.append({"id": f"user:{name}", "name": name, "kind": "user", "funcs": parse_list_file(p),
                    "path": f"permuter/lists/{name}.txt",
                    "queue_style": any(l.split("#")[0].split()[:1] and l.split()[0].endswith(".c")
                                       for l in read(p).splitlines() if l.split("#")[0].strip())})
    return out


def all_lists():
    return builtin_lists() + user_lists()


def safe_name(name):
    name = re.sub(r"[^\w.\- ]", "", name).strip().replace(" ", "_")
    if not name:
        raise ValueError("give the list a name")
    return name


# ---------------------------------------------------------------- weights / models

def default_weights():
    sec, base, gcc = None, {}, {}
    for l in read(DEFAULT_WEIGHTS).splitlines():
        l = l.split("#")[0].strip()
        if l.startswith("["):
            sec = l.strip("[]")
        elif "=" in l and sec in ("base", "gcc"):
            k, v = (x.strip() for x in l.split("=", 1))
            (base if sec == "base" else gcc)[k] = float(v)
    base.update(gcc)
    return base


WEIGHT_LINE = re.compile(r"^\s*(perm_\w+)\s*=\s*([0-9.eE+-]+)")


def weights():
    d = default_weights()
    cur = {}
    for l in read(WEIGHTS).splitlines():
        m = WEIGHT_LINE.match(l)
        if m:
            cur[m.group(1)] = float(m.group(2))
    return [{"name": k, "default": d[k], "value": cur.get(k)} for k in d] + \
           [{"name": k, "default": None, "value": v} for k, v in cur.items() if k not in d]


def save_weights(changes):
    lines = read(WEIGHTS).splitlines()
    for k, v in changes.items():
        if not re.fullmatch(r"perm_\w+", k):
            continue
        idx = [i for i, l in enumerate(lines) if (m := WEIGHT_LINE.match(l)) and m.group(1) == k]
        if v is None or v == "":
            for i in reversed(idx):
                del lines[i]
            continue
        v = float(v)
        txt = f"{k} = {int(v) if v == int(v) else v}"
        if idx:
            lines[idx[0]] = txt
        else:
            lines.append(txt)
    with open(WEIGHTS + ".tmp", "w") as f:
        f.write("\n".join(lines).rstrip("\n") + "\n")
    os.replace(WEIGHTS + ".tmp", WEIGHTS)


def current_weights():
    return {w["name"]: w["value"] for w in weights() if w["value"] is not None}


# ---------------------------------------------------------------- permuter tuning profiles
# A profile is a set of perm settings (TUNE_KEYS) plus the full set of weight overrides
# (written to permuter_weights.toml when it is applied). Built-ins live here; profiles you save
# from the panel go to permuter/gui/perm_profiles.json.

PROFILES_FILE = os.path.join(GUI, "perm_profiles.json")
TUNE_KEYS = ("minutes", "threads", "stall", "keep_prob", "speed", "stack_diffs")

from perm_profiles import BUILTIN_PROFILES      # also used by permute_all.sh (Auto)


def user_profiles():
    try:
        v = json.loads(read(PROFILES_FILE, "[]"))
        return [p for p in v if isinstance(p, dict) and p.get("id", "").startswith("user:")]
    except ValueError:
        return []


def write_user_profiles(ps):
    with open(PROFILES_FILE + ".tmp", "w") as f:
        json.dump(ps, f, indent=2)
    os.replace(PROFILES_FILE + ".tmp", PROFILES_FILE)


def all_profiles():
    return [dict(p, builtin=True) for p in BUILTIN_PROFILES] + [dict(p, builtin=False) for p in user_profiles()]


def _same(p, perm, cur):
    def eq(a, b):
        return (a == b) if isinstance(a, bool) or isinstance(b, bool) else abs(float(a) - float(b)) < 1e-9
    if any(k in p["perm"] and not eq(p["perm"][k], perm.get(k)) for k in TUNE_KEYS):
        return False
    w = p.get("weights", {})
    return set(w) == set(cur) and all(eq(w[k], cur[k]) for k in w)


def profiles_state():
    s, cur = load_settings()["perm"], current_weights()
    ps = all_profiles()
    match = [p["id"] for p in ps if _same(p, s, cur)]
    active = s.get("profile") if s.get("profile") in match else (match[0] if match else s.get("profile", ""))
    return {"profiles": ps, "current": active, "modified": not match,
            "settings": {k: s[k] for k in TUNE_KEYS}, "weights": cur}


def apply_profile(pid):
    p = next((p for p in all_profiles() if p["id"] == pid), None)
    if not p:
        raise ValueError(f"no profile {pid!r}")
    s = load_settings()
    s["perm"].update({k: v for k, v in p["perm"].items() if k in TUNE_KEYS})
    s["perm"]["profile"] = pid
    save_settings(s)
    changes = {k: None for k in current_weights()}
    changes.update(p.get("weights", {}))
    save_weights(changes)
    return profiles_state()


def save_profile(name, desc=""):
    name = name.strip()[:40]
    if not name:
        raise ValueError("give the profile a name")
    pid = "user:" + re.sub(r"[^\w-]+", "_", name).strip("_").lower()
    s = load_settings()
    prof = {"id": pid, "name": name, "desc": desc.strip()[:300] or "Saved from the panel.",
            "perm": {k: s["perm"][k] for k in TUNE_KEYS}, "weights": current_weights()}
    ps = [p for p in user_profiles() if p["id"] != pid] + [prof]
    write_user_profiles(ps)
    s["perm"]["profile"] = pid
    save_settings(s)
    return profiles_state()


def delete_profile(pid):
    if not pid.startswith("user:"):
        raise ValueError("built-in profiles can't be deleted")
    write_user_profiles([p for p in user_profiles() if p["id"] != pid])
    return profiles_state()


def perm_flags(p):
    """extra decomp-permuter options from the perm settings"""
    out = []
    kp = float(p.get("keep_prob", 0.6))
    if abs(kp - 0.6) > 1e-9:
        out.append(f"--keep-prob={min(max(kp, 0.0), 1.0):g}")
    sp = int(p.get("speed", 100))
    if sp < 100:
        out.append(f"--speed={max(sp, 1)}")
    if p.get("stack_diffs"):
        out.append("--stack-diffs")
    return out


def llm_base(s):
    return (s["llm"].get("base_url") or os.environ.get("LLM_BASE_URL") or "http://127.0.0.1:47831/v1").rstrip("/")


def llm_key():
    return os.environ.get("LLM_API_KEY") or os.environ.get("STRATA_API_KEY") or ""


def list_models():
    base = llm_base(load_settings())
    args = [CURL_EXE if os.path.exists(CURL_EXE) else "curl", "-s", "--max-time", "4"]
    if llm_key():
        args += ["-H", f"Authorization: Bearer {llm_key()}"]
    try:
        r = subprocess.run(args + [base + "/models"], capture_output=True, text=True, timeout=8)
        data = json.loads(r.stdout or "{}")
        return {"ok": True, "base": base, "models": [m.get("id") for m in data.get("data", [])]}
    except Exception as e:
        return {"ok": False, "base": base, "models": [], "error": str(e)}


# ---------------------------------------------------------------- starting jobs

def resolve_source(src):
    """-> (kind, funcs, list) where kind is 'selection' or the list id."""
    if src.get("type") == "selection":
        funcs = [f for f in src.get("funcs", []) if FUNC_RE.fullmatch(f)]
        if not funcs:
            raise ValueError("no functions picked")
        return "selection", funcs, None
    lid = src.get("list")
    for l in all_lists():
        if l["id"] == lid:
            if not l["funcs"]:
                raise ValueError(f"{l['name']} is empty")
            return lid, l["funcs"], l
    raise ValueError(f"unknown list {lid}")


SEL_QUEUE = "permuter/gui/selection_queue.txt"


def build_queue(funcs, extra_queue=None):
    """-> (queue lines, functions in them, functions with no candidate)"""
    q = queue_lines()
    if extra_queue:
        q.update(queue_lines(extra_queue))
    out, order, skipped = [], [], []
    for f in dict.fromkeys(funcs):
        if f in q:
            out.append(f"{q[f]['cands']} {f} {q[f]['idx']}")
        elif os.path.isdir(os.path.join(NONM, f)):
            out.append(f"- {f} 0")
        else:
            skipped.append(f)
            continue
        order.append(f)
    return out, order, skipped


def write_queue(path, lines, label):
    with open(os.path.join(ROOT, path), "w") as fh:
        fh.write(f"# written by control_gui.py for: {label}\n" + "".join(l + "\n" for l in lines))


def start_perm(src, s):
    kind, funcs, lst = resolve_source(src)
    p = s["perm"]
    env, skipped, opts = {}, [], []
    tail = []
    nice = ["nice", "-n", str(int(p["nice"]))]
    pre = None                          # m2c drafting to run before the permuter
    if kind == "queue":
        qfile = "permuter/queue.txt"
        order = funcs
        if p["fresh"]:
            opts.append("fresh")
    else:
        extra = os.path.join(ROOT, lst["path"]) if lst and lst.get("queue_style") else None
        out, order, skipped = build_queue(funcs, extra)
        if skipped and p.get("auto_draft"):
            # draft the missing ones first, then rebuild the queue with whatever got drafted
            pre = (nice + [PY, "tools/match/refill_queue.py", "--min-ratio", "0"] + skipped,
                   [PY, "tools/match/control_gui.py", "--make-queue", SEL_QUEUE]
                   + (["--extra-queue", extra] if extra else []) + list(dict.fromkeys(funcs)))
            order = list(dict.fromkeys(funcs))
        elif not out:
            raise ValueError("none of these functions has a permuter candidate (queue line or "
                             "permuter/nonmatchings folder): draft them with m2c first, or turn on "
                             "'Draft missing with m2c first' in the permuter's Tune section")
        else:
            write_queue(SEL_QUEUE, out, kind)
        qfile = SEL_QUEUE
        env["PERM_STATE"] = "permuter/gui/resume_selection.txt"
        opts.append("fresh")
    opts.append(f"stall={p['stall']}")
    if p["every"]:
        opts.append("all")
    if p.get("from_draft"):
        opts.append("draft")
    if any(x["id"] == p.get("profile") and x.get("auto") for x in all_profiles()):
        opts.append("auto")             # weights picked per function (perm_profiles.py --auto)
    env["PERM_EXTRA"] = " ".join(perm_flags(p))
    perm = nice + ["bash", "tools/match/permute_all.sh", qfile, str(p["minutes"]), str(int(p["threads"]))] + opts
    if pre:
        script = (f"echo '== m2c: drafting {len(skipped)} function(s) without a candidate'\n"
                  f"{shlex.join(pre[0])}\n"
                  f"echo; echo '== permuter'\n"
                  f"{shlex.join(pre[1])} || exit 1\n"
                  f"exec {shlex.join(perm)}\n")
        argv = ["bash", "-c", script]
    else:
        argv = perm
    name = lst["name"] if lst else f"{len(order)} picked"
    JOBS["perm"].start(argv, env, name, order)
    return {"skipped": [] if pre else skipped, "drafting": skipped if pre else [], "count": len(order)}


def start_llm(src, s):
    kind, funcs, lst = resolve_source(src)
    p = s["llm"]
    argv = [PY, "tools/match/llm_iterate.py"]
    if kind == "queue":
        argv += ["--queue", "permuter/queue.txt"]
    elif kind.startswith("parked:"):
        argv += ["--parked", kind[7:]]
    elif kind == "permuted":
        argv += ["--permuted"]
    elif lst and lst.get("queue_style"):
        argv += ["--queue", lst["path"]]
    else:
        argv += list(dict.fromkeys(funcs))
    argv += ["--compiles", str(int(p["compiles"])), "--minutes", str(p["minutes"]),
             "--variants", str(int(p["variants"])), "--temperature", str(p["temperature"]),
             "--ctx", str(int(p["ctx"])), "--examples", str(int(p["examples"]))]
    if p["think_mode"] == "off":
        argv += ["--no-think", "--think", "1500"]
    elif p["think_mode"] == "unlimited":
        argv += ["--think", "0"]
    else:
        argv += ["--think", str(int(p["think"]))]
    if int(p.get("rounds") or 0) > 0:
        argv += ["--rounds", str(int(p["rounds"]))]
    if p["skip_done"]:
        argv.append("--skip-done")
    if p["quiet"]:
        argv.append("--quiet")
    env = {}
    if p.get("model"):
        env["LLM_MODEL"] = p["model"]
    if p.get("base_url"):
        env["LLM_BASE_URL"] = p["base_url"]
    name = lst["name"] if lst else f"{len(funcs)} picked"
    JOBS["llm"].start(argv, env, name, list(dict.fromkeys(funcs)))
    return {"skipped": [], "count": len(funcs)}


def start_m2c(src, s):
    kind, funcs, lst = resolve_source(src)
    p = s["m2c"]
    # functions picked by hand are queued whenever their draft compiles (on tiny functions one
    # wrong instruction already sinks the ratio); the minimum ratio only filters whole lists
    argv = ["nice", "-n", str(int(p["nice"])), PY, "tools/match/refill_queue.py",
            "--min-ratio", str(0 if kind == "selection" else p["min_ratio"]), "--limit", str(int(p["limit"]))]
    if p["dry_run"]:
        argv.append("--dry-run")
    if kind.startswith("parked:"):
        argv += ["--ov", kind[7:]]
    else:
        argv += list(dict.fromkeys(funcs))
    name = lst["name"] if lst else f"{len(funcs)} picked"
    JOBS["m2c"].start(argv, {}, name, list(dict.fromkeys(funcs)))
    return {"skipped": [], "count": len(set(funcs))}


STARTERS = {"perm": start_perm, "llm": start_llm, "m2c": start_m2c}


# ---------------------------------------------------------------- events, alerts, score history

class Events:
    """Activity feed (permuter/gui/events.jsonl): kinds match, improved, queued, job, guard, night."""
    def __init__(self):
        self.path = os.path.join(GUI, "events.jsonl")
        self.lock = threading.Lock()
        self.items = []
        for l in read(self.path).splitlines()[-2000:]:
            try:
                self.items.append(json.loads(l))
            except ValueError:
                pass
        self.next = (self.items[-1]["id"] + 1) if self.items else 1

    def add(self, kind, func, text):
        with self.lock:
            e = {"id": self.next, "t": round(time.time(), 1), "kind": kind, "func": func, "text": text}
            self.next += 1
            self.items.append(e)
            del self.items[:-2000]
            try:
                with open(self.path, "a") as f:
                    f.write(json.dumps(e) + "\n")
            except OSError:
                pass
        return e

    def after(self, i, limit=300):
        with self.lock:
            return [e for e in self.items if e["id"] > i][-limit:]


class Watcher:
    """Every 20 s (and when a job ends) compares permuter/LLM results with the last snapshot:
    new best scores go to the score history (permuter/gui/history.jsonl, for the trend charts),
    and matches / improvements / newly queued drafts become events."""
    HISTORY = os.path.join(GUI, "history.jsonl")

    def __init__(self):
        self.path = os.path.join(GUI, "snapshot.json")
        self.ev = threading.Event()

    def poke(self):
        self.ev.set()

    def start(self):
        threading.Thread(target=self._run, daemon=True).start()

    def _run(self):
        while True:
            try:
                self.check()
            except Exception as e:
                print("watcher:", e, flush=True)
            self.ev.wait(20)
            self.ev.clear()

    def check(self):
        try:
            prev = json.loads(read(self.path, "{}"))
        except ValueError:
            prev = {}
        first = not prev
        pi, li, q = perm_info(), llm_info(), queue_lines()
        snap = {"perm": {f: [v["best"], v["matched"], v["base"]] for f, v in pi.items()},
                "llm": {f: [v["ratio"], v["match"]] for f, v in li.items()},
                "queue": sorted(q)}
        hist = []
        if not first:
            pp, pl, pq = prev.get("perm", {}), prev.get("llm", {}), set(prev.get("queue", []))
            for f, (best, matched, base) in snap["perm"].items():
                old = pp.get(f, [None, False, None])
                if best is not None and (old[0] is None or best < old[0]):
                    hist.append({"t": time.time(), "f": f, "s": "perm", "v": best})
                    if best == 0 or (matched and not old[1]):
                        EVENTS.add("match", f, f"{f}: the permuter found a MATCH")
                    else:
                        EVENTS.add("improved", f, f"{f}: permuter best {old[0] if old[0] is not None else base} -> {best}")
            for f, (ratio, match) in snap["llm"].items():
                old = pl.get(f, [None, False])
                if match and not old[1]:
                    hist.append({"t": time.time(), "f": f, "s": "llm", "v": 1.0})
                    EVENTS.add("match", f, f"{f}: the LLM found a MATCH")
                elif ratio is not None and (old[0] is None or ratio > old[0]):
                    hist.append({"t": time.time(), "f": f, "s": "llm", "v": ratio})
                    EVENTS.add("improved", f, f"{f}: LLM best {old[0] if old[0] is not None else '-'} -> {ratio:.4f}")
            for f in sorted(set(snap["queue"]) - pq):
                if DRAFT_MATCH.search(q[f].get("note", "")):
                    EVENTS.add("match", f, f"{f}: the m2c draft MATCHES as it is")
                else:
                    EVENTS.add("queued", f, f"{f}: new m2c draft queued for the permuter")
        if hist:
            with open(self.HISTORY, "a") as fh:
                fh.write("".join(json.dumps(h) + "\n" for h in hist))
        tmp = self.path + ".tmp"
        with open(tmp, "w") as fh:
            json.dump(snap, fh)
        os.replace(tmp, self.path)


EVENTS = Events()
WATCH = Watcher()


# ---------------------------------------------------------------- night shift

class NightShift:
    """Runs the enabled stages one after another (m2c -> permuter -> LLM by default), each until
    its engine finishes or its hours (paused time not counted) are used up, optionally starting
    at a set time of day. Uses each engine's saved tuning."""
    def __init__(self):
        self.thread = None
        self.stop_flag = threading.Event()
        self.state = {"running": False, "stage": None, "stages": [], "waiting_until": None,
                      "stage_started": None, "stage_active": 0, "log": []}

    def note(self, text):
        self.state["log"] = (self.state["log"] + [f"{time.strftime('%H:%M')} {text}"])[-30:]
        EVENTS.add("night", None, "Night shift: " + text)

    def start(self, cfg):
        if self.thread and self.thread.is_alive():
            raise RuntimeError("the night shift is already running")
        stages = [s for s in cfg.get("stages", []) if s.get("on") and float(s.get("hours") or 0) > 0]
        if not stages:
            raise ValueError("no stages switched on")
        self.stop_flag.clear()
        self.state.update(running=True, stage=None, stages=stages, waiting_until=None, log=[])
        self.thread = threading.Thread(target=self._run, args=(cfg, stages), daemon=True)
        self.thread.start()

    def stop(self):
        self.stop_flag.set()

    def _wait_until(self, hhmm):
        h, m = (int(x) for x in hhmm.split(":"))
        now = time.localtime()
        target = time.mktime((now.tm_year, now.tm_mon, now.tm_mday, h, m, 0, 0, 0, -1))
        if target <= time.time():
            target += 86400
        self.state["waiting_until"] = target
        self.note(f"waiting until {hhmm}")
        while time.time() < target:
            if self.stop_flag.wait(5):
                return False
        self.state["waiting_until"] = None
        return True

    def _run(self, cfg, stages):
        try:
            if cfg.get("start_at") and re.fullmatch(r"\d{1,2}:\d\d", cfg["start_at"]):
                if not self._wait_until(cfg["start_at"]):
                    self.note("cancelled before it started")
                    return
            self.note("started (" + " -> ".join(f"{NAMES[s['engine']]} {s['hours']}h" for s in stages) + ")")
            for i, st in enumerate(stages):
                if self.stop_flag.is_set():
                    break
                eng, job = st["engine"], JOBS[st["engine"]]
                self.state.update(stage=i, stage_started=time.time(), stage_active=0)
                if not job.running():
                    try:
                        STARTERS[eng](st["source"], load_settings())
                    except Exception as e:
                        self.note(f"{NAMES[eng]} couldn't start: {e}")
                        continue
                self.note(f"stage {i + 1}: {NAMES[eng]} for up to {st['hours']} h")
                budget = float(st["hours"]) * 3600
                p0, t0 = job.paused_now(), time.time()
                while job.running():
                    self.state["stage_active"] = round(time.time() - t0 - (job.paused_now() - p0))
                    if self.stop_flag.is_set() or self.state["stage_active"] >= budget:
                        if not self.stop_flag.is_set():
                            self.note(f"{NAMES[eng]}: time up, stopping it")
                        job.stop()
                        for _ in range(120):
                            if not job.running():
                                break
                            time.sleep(1)
                        break
                    time.sleep(2)
            self.note("stopped" if self.stop_flag.is_set() else "finished")
        finally:
            self.state.update(running=False, stage=None, waiting_until=None)


NIGHT = NightShift()


# ---------------------------------------------------------------- CPU guard

class Guard:
    def __init__(self):
        self.over_since = self.under_since = None
        self.tripped = False
        self.last_other = None

    def on_sample(self, now):
        g = load_settings()["guard"]
        other = now.get("other_load")
        self.last_other = other
        engines = [e for e in JOBS if g.get(e)]
        if not g["enabled"] or other is None:
            if self.tripped:
                for e in JOBS:
                    JOBS[e].resume(by="guard")
                self.tripped = False
            self.over_since = self.under_since = None
            return
        t = time.time()
        if other >= g["threshold"]:
            self.under_since = None
            self.over_since = self.over_since or t
            if t - self.over_since >= g["trigger_secs"]:
                hit = [e for e in engines if JOBS[e].running() and not JOBS[e].paused() and JOBS[e].pause(by="guard")]
                if hit and not self.tripped:
                    EVENTS.add("guard", None, f"CPU guard: other programs at {other:.0f}% for "
                               f"{g['trigger_secs']}s, paused {', '.join(NAMES[e] for e in hit)}")
                self.tripped = self.tripped or bool(hit)
        else:
            self.over_since = None
            if other < g["resume_below"]:
                self.under_since = self.under_since or t
                if self.tripped and t - self.under_since >= g["resume_secs"]:
                    back = [e for e in JOBS if JOBS[e].resume(by="guard")]
                    if back:
                        EVENTS.add("guard", None, f"CPU guard: load down to {other:.0f}%, resumed "
                                   + ", ".join(NAMES[e] for e in back))
                    self.tripped = False
            else:
                self.under_since = None

    def state(self):
        return {"tripped": self.tripped, "other": self.last_other,
                "over_for": round(time.time() - self.over_since) if self.over_since else 0}


GUARD = Guard()
HW = None          # gui_hw.Hardware, created in main()
INSNS = gui_diff.InsnCounts(os.path.join(GUI, "insns.json"))    # started in main()


# ---------------------------------------------------------------- code viewer

def code_for(func, kind):
    if not FUNC_RE.fullmatch(func):
        raise ValueError("bad name")
    if kind == "llm":
        p = os.path.join(ROOT, "permuter", "llm", func, "best.c")
        return {"path": os.path.relpath(p, ROOT), "text": read(p, "(no LLM best.c yet)")}
    if kind == "perm":
        for d in (os.path.join(NONM, func), os.path.join(NONM, func + ".matched")):
            outs = sorted(glob.glob(os.path.join(d, "output-*", "source.c")),
                          key=lambda o: (int(re.search(r"output-(\d+)-", o).group(1)), o))
            if outs:
                return {"path": os.path.relpath(outs[0], ROOT), "text": read(outs[0])}
            if os.path.exists(os.path.join(d, "base.c")):
                return {"path": os.path.relpath(os.path.join(d, "base.c"), ROOT),
                        "text": read(os.path.join(d, "base.c"))}
        return {"path": "", "text": "(no permuter output yet)"}
    if kind == "asm":
        for p in glob.glob(os.path.join(ROOT, "asm", "**", f"{func}.s"), recursive=True):
            return {"path": os.path.relpath(p, ROOT), "text": read(p)}
        return {"path": "", "text": "(no .s file: already matched or not split)"}
    raise ValueError("kind must be perm, llm or asm")


# ---------------------------------------------------------------- HTTP

class H(BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def send(self, obj, code=200, ctype="application/json"):
        body = obj if isinstance(obj, bytes) else json.dumps(obj).encode()
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(body)

    def body(self):
        n = int(self.headers.get("Content-Length") or 0)
        return json.loads(self.rfile.read(n) or b"{}")

    def do_GET(self):
        u = urlparse(self.path)
        q = {k: v[0] for k, v in parse_qs(u.query).items()}
        try:
            if u.path in ("/", "/index.html"):
                return self.send(open(os.path.join(HERE, "gui", "index.html"), "rb").read(), ctype="text/html; charset=utf-8")
            if u.path == "/api/state":
                out = {k: j.state(int(q.get(k, 0))) for k, j in JOBS.items()}
                return self.send(dict(out, key=bool(llm_key()), now=time.time(),
                                      events=EVENTS.after(int(q.get("ev", 0))), last_event=EVENTS.next - 1,
                                      night=NIGHT.state, guard=GUARD.state(),
                                      hw=HW.now if HW else {}))
            if u.path == "/api/events":
                return self.send(EVENTS.after(int(q.get("after", 0)), limit=int(q.get("limit", 500))))
            if u.path == "/api/hw":
                return self.send(HW.state(float(q.get("since", 0))) if HW else {})
            if u.path == "/api/diff":
                return self.send(gui_diff.diff(q.get("func", ""), q.get("kind", "perm")))
            if u.path == "/api/overall":
                return self.send(gui_diff.overall(q.get("func", "")))
            if u.path == "/api/trend":
                return self.send(gui_diff.trend(q.get("func", ""), Watcher.HISTORY))
            if u.path == "/api/functions":
                return self.send(functions())
            if u.path == "/api/lists":
                return self.send(all_lists())
            if u.path == "/api/settings":
                return self.send(load_settings())
            if u.path == "/api/weights":
                return self.send(weights())
            if u.path == "/api/profiles":
                return self.send(profiles_state())
            if u.path == "/api/notes":
                f = q.get("func", "")
                return self.send({"func": f, "text": fnotes.read(f), "mtime": fnotes.mtime(f),
                                  "path": os.path.relpath(fnotes.path(f), ROOT)})
            if u.path == "/api/tips":
                return self.send({"text": read(TIPS)})
            if u.path == "/api/models":
                return self.send(list_models())
            if u.path == "/api/code":
                return self.send(code_for(q.get("func", ""), q.get("kind", "perm")))
            self.send({"error": "not found"}, 404)
        except Exception as e:
            self.send({"error": str(e)}, 400)

    def do_POST(self):
        u = urlparse(self.path)
        try:
            b = self.body()
            if u.path == "/api/settings":
                s = load_settings()
                for k in s:
                    s[k].update({kk: vv for kk, vv in b.get(k, {}).items() if kk in s[k]})
                save_settings(s)
                return self.send(s)
            if u.path == "/api/night/start":
                s = load_settings()
                if "night" in b:
                    s["night"].update({k: v for k, v in b["night"].items() if k in s["night"]})
                    save_settings(s)
                NIGHT.start(s["night"])
                return self.send({"ok": True})
            if u.path == "/api/night/stop":
                NIGHT.stop()
                return self.send({"ok": True})
            if u.path == "/api/hw/reset":
                HW.reset()
                return self.send({"ok": True})
            m = re.fullmatch(r"/api/(\w+)/(start|stop|pause|resume)", u.path)
            if m and m.group(1) in JOBS:
                job = m.group(1)
                if m.group(2) == "stop":
                    return self.send({"ok": JOBS[job].stop()})
                if m.group(2) == "pause":
                    return self.send({"ok": JOBS[job].pause("you")})
                if m.group(2) == "resume":
                    return self.send({"ok": JOBS[job].resume()})
                s = load_settings()
                if "settings" in b:
                    s[job].update({k: v for k, v in b["settings"].items() if k in s[job]})
                    save_settings(s)
                r = STARTERS[job](b.get("source", {}), s)
                return self.send(dict(r, ok=True))
            if u.path == "/api/lists/save":
                name = safe_name(b.get("name", ""))
                funcs = [f for f in b.get("funcs", []) if FUNC_RE.fullmatch(f)]
                with open(os.path.join(LISTS, name + ".txt"), "w") as f:
                    f.write("".join(x + "\n" for x in funcs))
                return self.send({"ok": True, "id": f"user:{name}"})
            if u.path == "/api/lists/delete":
                name = safe_name(b.get("name", ""))
                p = os.path.join(LISTS, name + ".txt")
                if os.path.exists(p):
                    os.replace(p, p + ".deleted")       # keep a copy, just in case
                return self.send({"ok": True})
            if u.path == "/api/weights":
                save_weights(b)
                return self.send(weights())
            if u.path == "/api/notes":
                f = b.get("func", "")
                # someone else (the LLM loop, Claude, an editor) changed it since you opened it
                if b.get("mtime") is not None and abs(fnotes.mtime(f) - float(b["mtime"])) > 0.01:
                    return self.send({"conflict": True, "text": fnotes.read(f), "mtime": fnotes.mtime(f)}, 409)
                fnotes.write(f, b.get("text", ""))
                with _cache_lock:
                    _cache["t"] = 0
                return self.send({"ok": True, "mtime": fnotes.mtime(f)})
            if u.path == "/api/profiles/apply":
                return self.send(apply_profile(b.get("id", "")))
            if u.path == "/api/profiles/save":
                return self.send(save_profile(b.get("name", ""), b.get("desc", "")))
            if u.path == "/api/profiles/delete":
                return self.send(delete_profile(b.get("id", "")))
            if u.path == "/api/tips":
                with open(TIPS + ".tmp", "w") as f:
                    f.write(b.get("text", ""))
                os.replace(TIPS + ".tmp", TIPS)
                return self.send({"ok": True})
            self.send({"error": "not found"}, 404)
        except Exception as e:
            self.send({"error": str(e)}, 400)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--port", type=int, default=8765)
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--make-queue", metavar="OUT", help="(used by chained runs) write a permuter queue for FUNCs")
    ap.add_argument("--extra-queue", help="with --make-queue: another queue file to take candidates from")
    ap.add_argument("funcs", nargs="*")
    a = ap.parse_args()
    if a.make_queue:
        out, order, skipped = build_queue(a.funcs, a.extra_queue)
        for f in skipped:
            print(f"{f}: still no candidate (its draft failed), left out")
        if not out:
            sys.exit("nothing left to permute")
        write_queue(a.make_queue, out, "picked")
        print(f"permuter queue: {len(out)} function(s)")
        return
    global HW
    HW = gui_hw.Hardware(GUI, load_settings, GUARD.on_sample)
    WATCH.start()
    INSNS.start()
    srv = ThreadingHTTPServer((a.host, a.port), H)
    srv.daemon_threads = True
    print(f"control panel on http://localhost:{a.port}/  (Ctrl+C here stops it and any running job)", flush=True)

    def bye(*_):
        NIGHT.stop()
        try:
            HW.save()
        except OSError:
            pass
        for j in JOBS.values():
            j.stop()
        deadline = time.time() + 40
        while any(j.running() for j in JOBS.values()) and time.time() < deadline:
            time.sleep(0.5)
        os._exit(0)
    signal.signal(signal.SIGTERM, bye)
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        print("stopping jobs...", flush=True)
        bye()


if __name__ == "__main__":
    main()
