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
import argparse, codecs, csv, fcntl, glob, json, os, re, signal, struct, subprocess, sys, termios
import threading, time
from collections import deque
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

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
FUNC_RE = re.compile(r"\b(func_[0-9A-Fa-f]{8}|[A-Za-z_]\w*)\b")

DEFAULTS = {
    "perm": {"minutes": 20, "threads": 8, "stall": 5, "nice": 19, "fresh": False, "every": False},
    "llm": {"compiles": 40, "minutes": 30, "think": 8000, "think_mode": "budget", "variants": 3,
            "temperature": 0.6, "ctx": 131072, "examples": 2, "skip_done": True, "quiet": False,
            "rounds": 0, "model": "", "base_url": ""},
    "m2c": {"min_ratio": 0.3, "limit": 0, "nice": 10, "dry_run": False},
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

    def running(self):
        return self.proc is not None and self.proc.poll() is None

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
        full_env = dict(os.environ, TERM="xterm-256color", COLUMNS="240", PYTHONUNBUFFERED="1", **env)
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
            self._commit(f"\x1b[2m{time.strftime('%H:%M:%S')} -- exited with code {code}\x1b[0m")
            self.current = None

    def stop(self):
        if not self.running():
            return False
        self.stopping = True
        proc = self.proc

        def escalate():
            for sig, wait in ((signal.SIGINT, 20), (signal.SIGTERM, 15), (signal.SIGKILL, 0)):
                try:
                    os.killpg(proc.pid, sig)
                except ProcessLookupError:
                    return
                for _ in range(wait * 4):
                    if proc.poll() is not None:
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
        m = self.START.search(line)
        if m:
            self.current = m.group(1)
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
        base = summ.get(func)
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
        pi, li, pk = perm_info(), llm_info(), parked()
        rows = []
        with open(os.path.join(ROOT, "progress", "functions.csv"), newline="") as f:
            for r in csv.DictReader(f):
                n = r["function"]
                src = os.path.exists(os.path.join(ROOT, "src", r["file"] + ".c"))
                matched = (n not in asm) if src else r["matched"] == "1"
                rows.append({"n": n, "a": r["addr"], "f": r["file"], "c": r["category"], "b": int(r["bytes"]),
                             "m": matched, "pk": n in pk, "q": q.get(n), "p": pi.get(n), "l": li.get(n)})
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


def start_perm(src, s):
    kind, funcs, lst = resolve_source(src)
    p = s["perm"]
    env, skipped, opts = {}, [], []
    if kind == "queue":
        qfile = "permuter/queue.txt"
        order = funcs
        if p["fresh"]:
            opts.append("fresh")
    else:
        q = queue_lines()
        if lst and lst.get("queue_style"):
            q.update(queue_lines(os.path.join(ROOT, lst["path"])))
        out, order = [], []
        for f in dict.fromkeys(funcs):
            if f in q:
                out.append(f"{q[f]['cands']} {f} {q[f]['idx']}")
            elif os.path.isdir(os.path.join(NONM, f)):
                out.append(f"- {f} 0")
            else:
                skipped.append(f)
                continue
            order.append(f)
        if not out:
            raise ValueError("none of these functions has a permuter candidate (queue line or "
                             "permuter/nonmatchings folder): run refill or let the LLM draft them")
        qfile = "permuter/gui/selection_queue.txt"
        with open(os.path.join(ROOT, qfile), "w") as fh:
            fh.write(f"# written by control_gui.py for: {kind}\n" + "\n".join(out) + "\n")
        env["PERM_STATE"] = "permuter/gui/resume_selection.txt"
        opts.append("fresh")
    opts.append(f"stall={p['stall']}")
    if p["every"]:
        opts.append("all")
    argv = ["nice", "-n", str(int(p["nice"])), "bash", "tools/match/permute_all.sh", qfile,
            str(p["minutes"]), str(int(p["threads"]))] + opts
    name = lst["name"] if lst else f"{len(order)} picked"
    JOBS["perm"].start(argv, env, name, order)
    return {"skipped": skipped, "count": len(order)}


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
    argv = ["nice", "-n", str(int(p["nice"])), PY, "tools/match/refill_queue.py",
            "--min-ratio", str(p["min_ratio"]), "--limit", str(int(p["limit"]))]
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
                return self.send(dict(out, key=bool(llm_key()), now=time.time()))
            if u.path == "/api/functions":
                return self.send(functions())
            if u.path == "/api/lists":
                return self.send(all_lists())
            if u.path == "/api/settings":
                return self.send(load_settings())
            if u.path == "/api/weights":
                return self.send(weights())
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
            m = re.fullmatch(r"/api/(\w+)/(start|stop)", u.path)
            if m and m.group(1) in JOBS:
                job = m.group(1)
                if m.group(2) == "stop":
                    return self.send({"ok": JOBS[job].stop()})
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
    a = ap.parse_args()
    srv = ThreadingHTTPServer((a.host, a.port), H)
    srv.daemon_threads = True
    print(f"control panel on http://localhost:{a.port}/  (Ctrl+C here stops it and any running job)", flush=True)

    def bye(*_):
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
