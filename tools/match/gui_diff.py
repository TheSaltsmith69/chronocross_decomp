"""gui_diff.py -- side-by-side asm diffs, "overall best" and score trends for control_gui.py.

Everything is compiled inside the function's permuter folder (permuter/nonmatchings/FUNC), with
its compile.sh (the object's real recipe) and target.o (the original), so it never touches src/.
Sources that can be compared:
  perm  the permuter's best output (output-SCORE-N/source.c)
  base  the permuter's starting C (base.c)
  llm   the LLM loop's best.c, spliced into base.c in place of the function
  cand  the queue candidate block, spliced the same way
Differences are counted per instruction (relocation targets compared by symbol), so the
sources can be ranked against each other: that's the "overall best".
"""
import difflib, glob, os, re, subprocess, tempfile, threading, time

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
NONM = os.path.join(ROOT, "permuter", "nonmatchings")
LLM = os.path.join(ROOT, "permuter", "llm")
OBJDUMP = "mips-linux-gnu-objdump"
_cache, _lock = {}, threading.Lock()


def permdir(func):
    for d in (os.path.join(NONM, func), os.path.join(NONM, func + ".matched")):
        if os.path.isdir(d):
            return d
    return None


def best_output(d):
    outs = []
    for o in glob.glob(os.path.join(d, "output-*", "source.c")):
        m = re.search(r"output-(\d+)-(\d+)", o)
        if m:
            outs.append((int(m.group(1)), int(m.group(2)), o))
    return min(outs)[2] if outs else None


# ---------------------------------------------------------------- splicing

def find_def(text, func):
    """(start, end) of the definition of func (or an asm-alias definition named func_X...)."""
    for name in (re.escape(func), re.escape(func) + r"\w*"):
        m = re.search(r"^[^\n;#{}]*\b" + name + r"\s*\([^;{}]*\)\s*(?:asm\s*\([^)]*\)\s*)?\{", text, re.M)
        if m:
            break
    else:
        return None
    i, depth, q = m.end() - 1, 0, None
    while i < len(text):
        c = text[i]
        if q:
            if c == "\\":
                i += 1
            elif c == q:
                q = None
        elif c in "\"'":
            q = c
        elif c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return m.start(), i + 1
        i += 1
    return None


BASIC_TYPES = {"u8": "unsigned char", "s8": "signed char", "u16": "unsigned short", "s16": "short",
               "u32": "unsigned int", "s32": "int"}


def top_statements(text):
    """Split declarations at top-level semicolons (braces and comments respected)."""
    text = re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)
    out, depth, cur = [], 0, ""
    for c in text:
        cur += c
        if c in "{(":
            depth += 1
        elif c in "})":
            depth -= 1
        elif c == ";" and depth == 0:
            out.append(cur.strip())
            cur = ""
    return [s for s in out if s and not s.startswith("#")]


def declared(st):
    s = re.sub(r'\basm\s*\("[^"]*"\)', "", st)
    if s.startswith("typedef") or re.match(r"(struct|union|enum)\s+\w*\s*\{", s):
        m = re.search(r"(\w+)\s*(\[[^\]]*\])*\s*;$", s)
        if m and not s.rstrip(";").rstrip().endswith("}"):
            return m.group(1)
        m = re.match(r"(?:struct|union|enum)\s+(\w+)", s)
        return m.group(1) if m else None
    m = re.search(r"(\w+)\s*\(", s) if "(" in s.split("=")[0] else None
    if m:
        return m.group(1)
    m = re.search(r"(\w+)\s*(\[[^\]]*\])*\s*(=.*)?;$", s, re.S)
    return m.group(1) if m else None


def splice(base, block, func):
    block = re.sub(r"^// @@\w+.*\n?", "", block, flags=re.M)
    nd = find_def(block, func)
    bd = find_def(base, func)
    if not nd or not bd:
        raise ValueError("couldn't find the function definition to splice")
    rest = base[: bd[0]] + base[bd[1]:]
    keep = []
    for st in top_statements(block[: nd[0]]):
        name = declared(st)
        if name and re.search(r"\b" + re.escape(name) + r"\b", rest):
            continue               # base.c already declares it
        keep.append(st)
    new_text = "\n".join(keep) + "\n" + block[nd[0]: nd[1]]
    types = "".join(f"typedef {c} {t};\n" for t, c in BASIC_TYPES.items()
                    if re.search(r"\b" + t + r"\b", new_text) and not re.search(r"typedef[^;]*\b" + t + r"\s*;", rest))
    return base[: bd[0]] + types + new_text + base[bd[1]:]


def cand_block(func):
    q = os.path.join(ROOT, "permuter", "queue.txt")
    try:
        for l in open(q):
            p = l.split("#")[0].split()
            if len(p) >= 2 and p[1] == func:
                text = open(os.path.join(ROOT, p[0])).read()
                blocks = text.split("// @@" + func + "\n")[1:]
                idx = int(p[2]) if len(p) > 2 else 0
                return blocks[idx].split("\n// @@")[0] if idx < len(blocks) else None
    except OSError:
        pass
    return None


def source_for(func, kind):
    """-> (C text, path it came from, mtime) or raises"""
    d = permdir(func)
    if not d:
        raise ValueError("no permuter folder yet: draft it (m2c) or run the permuter on it once")
    base_p = os.path.join(d, "base.c")
    if kind == "base":
        return open(base_p).read(), base_p, os.path.getmtime(base_p)
    if kind == "perm":
        o = best_output(d)
        if not o:
            raise ValueError("the permuter hasn't saved an output yet")
        return open(o).read(), o, os.path.getmtime(o)
    if kind == "llm":
        p = os.path.join(LLM, func, "best.c")
        if not os.path.exists(p):
            raise ValueError("no LLM best.c yet")
        return splice(open(base_p).read(), open(p).read(), func), p, os.path.getmtime(p)
    if kind == "cand":
        b = cand_block(func)
        if not b:
            raise ValueError("no queue candidate")
        return splice(open(base_p).read(), b, func), "queue candidate", os.path.getmtime(base_p)
    raise ValueError(f"unknown source {kind}")


# ---------------------------------------------------------------- disassembly

LINE = re.compile(r"^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$")
RELOC = re.compile(r"^\s*([0-9a-f]+):\s+(R_MIPS_\w+)\s+(\S+)")


def disasm(obj, func):
    r = subprocess.run([OBJDUMP, "-drz", "--no-show-raw-insn", f"--disassemble={func}", obj],
                       capture_output=True, text=True)
    insns, start = [], None
    for l in r.stdout.splitlines():
        m = RELOC.match(l)
        if m and insns:
            off, typ, sym = int(m.group(1), 16), m.group(2), m.group(3)
            sym = re.sub(r"\+0x0$", "", sym)
            i = insns[-1]
            short = {"R_MIPS_HI16": "%hi", "R_MIPS_LO16": "%lo", "R_MIPS_26": "", "R_MIPS_GPREL16": "%gp_rel"}.get(typ, typ)
            if typ == "R_MIPS_26":
                i[2] = sym
            else:
                i[2] = re.sub(r"(-?0x[0-9a-f]+|-?\d+)(?=\(|$)", f"{short}({sym})", i[2], count=1)
            continue
        m = LINE.match(l)
        if m and not l.rstrip().endswith(">:"):
            off = int(m.group(1), 16)
            if start is None:
                start = off
            ops = m.group(3).split("#")[0].strip()
            # branch targets relative to the function start
            ops = re.sub(r"[0-9a-f]+ <([\w.]+)(\+0x[0-9a-f]+)?>",
                         lambda mm: f".+{int(mm.group(2)[3:], 16) if mm.group(2) else 0:#x}", ops)
            insns.append([off - start, m.group(2), ops])
    return [scratch(f"{mn} {ops}".strip()) for _, mn, ops in insns]


def scratch(s):
    """Scratchpad symbols (D_1F80xxxx) as the literal address the original uses, so
    %hi(D_1F800010) == 0x1f80 and %lo(D_1F800010)(a0) == 16(a0) (not a real difference)."""
    s = re.sub(r"%hi\(D_1F80[0-9A-Fa-f]{4}\)", "0x1f80", s)
    return re.sub(r"%lo\(D_1F80([0-9A-Fa-f]{4})\)", lambda m: str(int(m.group(1), 16)), s)


def compile_obj(func, text):
    d = permdir(func)
    fd, src = tempfile.mkstemp(suffix=".c", dir=os.path.join(ROOT, "permuter", "gui"))
    os.close(fd)
    out = src[:-2] + ".o"
    try:
        open(src, "w").write(text)
        r = subprocess.run(["nice", "-n", "10", "bash", os.path.join(d, "compile.sh"), src, "-o", out], cwd=ROOT,
                           capture_output=True, text=True, timeout=120)
        if r.returncode or not os.path.exists(out):
            err = [l for l in (r.stderr + r.stdout).splitlines() if "error" in l.lower() or ": " in l]
            raise ValueError("compile failed: " + ("\n".join(err[:8]) or "(no message)"))
        return disasm(out, func)
    finally:
        for p in (src, out):
            try:
                os.remove(p)
            except OSError:
                pass


def regs_only(a, b):
    ta, tb = a.split(None, 1), b.split(None, 1)
    if not ta or not tb or ta[0] != tb[0]:
        return False
    norm = lambda s: re.sub(r"\b(?:zero|at|v[01]|a[0-3]|t\d|s[0-8]|k[01]|gp|sp|fp|ra)\b", "R", s)
    return norm(a) == norm(b)


def diff(func, kind):
    text, path, mt = source_for(func, kind)
    tgt = os.path.join(permdir(func), "target.o")
    key = (func, kind, mt, os.path.getmtime(tgt))
    with _lock:
        if key in _cache:
            return _cache[key]
    mine = compile_obj(func, text)
    target = disasm(tgt, func)
    rows, bad = [], 0
    sm = difflib.SequenceMatcher(None, target, mine, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == "equal":
            rows += [[target[i], mine[j1 + k], "eq"] for k, i in enumerate(range(i1, i2))]
            continue
        n = max(i2 - i1, j2 - j1)
        for k in range(n):
            a = target[i1 + k] if i1 + k < i2 else None
            b = mine[j1 + k] if j1 + k < j2 else None
            kind_ = "del" if b is None else "ins" if a is None else "reg" if regs_only(a, b) else "diff"
            rows.append([a, b, kind_])
            bad += 1
    res = {"func": func, "kind": kind, "path": os.path.relpath(path, ROOT) if path.startswith("/") else path,
           "rows": rows, "diffs": bad, "total": len(target), "match": bad == 0,
           "regs_only": sum(1 for r in rows if r[2] == "reg")}
    with _lock:
        _cache[key] = res
    return res


def overall(func):
    out = {}
    for k in ("perm", "llm", "cand", "base"):
        try:
            r = diff(func, k)
            out[k] = {"diffs": r["diffs"], "total": r["total"], "regs_only": r["regs_only"], "path": r["path"],
                      "eq": sum(1 for row in r["rows"] if row[2] == "eq")}
        except Exception as e:
            out[k] = {"error": str(e)}
    ok = {k: v for k, v in out.items() if "diffs" in v}
    best = min(ok, key=lambda k: (ok[k]["diffs"], ok[k]["diffs"] - ok[k]["regs_only"])) if ok else None
    return {"sources": out, "best": best}


# ---------------------------------------------------------------- matched-instruction counts

class InsnCounts:
    """Per function with a permuter folder: how many of the original's instructions the closest
    version (permuter best, LLM best, candidate or base) reproduces exactly, i.e. the "eq" rows
    of its diff. Kept in permuter/gui/insns.json and refreshed in the background when a
    source changes (one compile per source, niced)."""

    def __init__(self, path):
        self.path = path
        self.lock = threading.Lock()
        try:
            import json
            self.data = json.load(open(path))
        except (OSError, ValueError):
            self.data = {}
        self.poke_ev = threading.Event()

    @staticmethod
    def signature(func):
        d = permdir(func)
        files = [os.path.join(d, "base.c"), os.path.join(d, "target.o"), best_output(d) or "",
                 os.path.join(LLM, func, "best.c"), os.path.join(ROOT, "permuter", "queue.txt")]
        return [round(os.path.getmtime(p), 2) if p and os.path.exists(p) else 0 for p in files]

    def get(self, func):
        with self.lock:
            e = self.data.get(func)
        return [e["m"], e["t"], e["src"]] if e and "m" in e else None

    def poke(self):
        self.poke_ev.set()

    def refresh_one(self, func):
        sig = self.signature(func)
        with self.lock:
            e = self.data.get(func)
            if e and e.get("sig") == sig:
                return False
        o = overall(func)
        ok = {k: v for k, v in o["sources"].items() if "diffs" in v}
        best = None
        for k in ok:
            r = diff(func, k)                         # cached by overall()
            m = sum(1 for row in r["rows"] if row[2] == "eq")
            if best is None or m > best[0]:
                best = (m, r["total"], k)
        entry = {"sig": sig, "m": best[0], "t": best[1], "src": best[2]} if best else {"sig": sig}
        with self.lock:
            self.data[func] = entry
        return True

    def save(self):
        import json
        with self.lock:
            tmp = self.path + ".tmp"
            json.dump(self.data, open(tmp, "w"))
            os.replace(tmp, self.path)

    def run(self, every=60):
        while True:
            changed = False
            for d in sorted(glob.glob(os.path.join(NONM, "func_*"))):
                func = os.path.basename(d).replace(".matched", "")
                try:
                    changed |= self.refresh_one(func)
                except Exception:
                    pass
            if changed:
                self.save()
            self.poke_ev.wait(every)
            self.poke_ev.clear()

    def start(self):
        threading.Thread(target=self.run, daemon=True).start()


# ---------------------------------------------------------------- trends

def trend(func, history_file):
    perm, llm = [], []
    d = permdir(func)
    if d:
        base_c = os.path.join(d, "base.c")
        m = re.search(r"base score = (\d+)", _head(os.path.join(ROOT, "permuter", f"{func}.log")))
        if m and os.path.exists(base_c):
            perm.append([os.path.getmtime(base_c), int(m.group(1))])
        for o in glob.glob(os.path.join(d, "output-*")):
            mm = re.search(r"output-(\d+)-\d+$", o)
            if mm:
                perm.append([os.path.getmtime(o), int(mm.group(1))])
        if d.endswith(".matched"):
            perm.append([os.path.getmtime(d), 0])
    ld = os.path.join(LLM, func)
    hand = _read(os.path.join(ld, "handoffs.txt"))
    for m in re.finditer(r"^=== turn (\d+) \(([^)]*(?:\([^)]*\)[^)]*)*)\)", hand, re.M):
        t = os.path.join(ld, f"turn{int(m.group(1)):02d}.txt")
        rs = [float(x) for x in re.findall(r"ratio ([01]\.\d+)", m.group(2))]
        if "MATCH" in m.group(2):
            rs.append(1.0)
        if rs and os.path.exists(t):
            llm.append([os.path.getmtime(t), max(rs)])
    for l in _read(history_file).splitlines():
        if f'"{func}"' in l:
            try:
                import json
                e = json.loads(l)
                (perm if e["s"] == "perm" else llm).append([e["t"], e["v"]])
            except (ValueError, KeyError):
                pass
    return {"perm": sorted(perm), "llm": sorted(llm)}


def _read(p):
    try:
        return open(p, errors="replace").read()
    except OSError:
        return ""


def _head(p, n=65536):
    try:
        with open(p, errors="replace") as f:
            return f.read(n)
    except OSError:
        return ""
