#!/usr/bin/env python3
"""decomp.py FUNC... [-a CANDS.c] [--raw] -- first-draft C from m2c.

For each function: builds its context with m2ctx.py (plus tools/match/m2c_extra.h
for prototypes the sources don't declare yet), runs tools/m2c on its .s, and prints
the result as a "// @@FUNC" candidate block (or appends it to CANDS.c with -a), ready
for try.sh / trycc.py. m2c's "?" placeholder types become s32 so the block
compiles; the draft still needs a human pass (types, struct fields, loops).
"""
import argparse, glob, os, re, subprocess, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m2ctx

ROOT = m2ctx.ROOT
EXTRA = os.path.join(ROOT, "tools", "match", "m2c_extra.h")


def asm_path(func):
    hits = glob.glob(f"{ROOT}/asm/**/nonmatchings/**/{func}.s", recursive=True)
    if not hits:
        sys.exit(f"{func}: no .s under asm/*/nonmatchings")
    return hits[0]


def extra_decls(ctx):
    if not os.path.exists(EXTRA):
        return ""
    have = set(re.findall(r"\b(func_[0-9A-F]{8}|D_[0-9A-F]{8})\b", ctx))
    keep = []
    text = re.sub(r"/\*.*?\*/", "", open(EXTRA).read(), flags=re.S)
    for line in text.splitlines():
        line = line.strip()
        if not line or line.startswith(("//", "/*", "#")):
            continue
        names = re.findall(r"\b(func_[0-9A-F]{8}|D_[0-9A-F]{8})\b", line)
        if names and names[0] in have:
            continue
        keep.append(line)
    return "\n".join(keep) + "\n"


def split_args(s, i):
    """s[i] is just after '('; return (args, index after the matching ')')."""
    depth, args, cur = 0, [], ""
    while True:
        c = s[i]
        if c == "(":
            depth += 1
        elif c == ")":
            if depth == 0:
                args.append(cur.strip())
                return args, i + 1
            depth -= 1
        elif c == "," and depth == 0:
            args.append(cur.strip())
            cur = ""
            i += 1
            continue
        cur += c
        i += 1


def house_style(code):
    """m2c --valid-syntax output -> the project's style: untyped pointers are u8 *,
    unknown fields are *(T *)(p + off)."""
    code = re.sub(r"\bvoid\*", "u8*", code)
    code = re.sub(r"\bM2C_UNK8\b", "s8", code)
    code = re.sub(r"\bM2C_UNK16\b", "s16", code)
    code = re.sub(r"\bM2C_UNK(32)?\b", "s32", code)
    while True:
        i = code.rfind("M2C_FIELD(")             # innermost first
        if i < 0:
            break
        (expr, tptr, off), j = split_args(code, i + len("M2C_FIELD("))
        tptr = re.sub(r"\s*(\*+)\s*$", lambda m: " " + m.group(1), tptr.strip())
        if re.fullmatch(r"[A-Za-z_]\w*", expr):
            base = expr
        elif re.fullmatch(r"\*\(u8 \*\*\)\(.*\)", expr) and expr.count("(") == expr.count(")"):
            base = expr                                     # already a u8 * (nested field)
        else:
            base = f"(u8 *)({expr})"
        acc = f"*({tptr})({base} + {off})" if off not in ("0", "0x0") else f"*({tptr}){base}"
        code = code[:i] + acc + code[j:]
    while True:
        i = code.find("M2C_BITWISE(")
        if i < 0:
            break
        (t, e), j = split_args(code, i + len("M2C_BITWISE("))
        code = code[:i] + f"(({t})({e}))" + code[j:]
    code = re.sub(r"\b(\w+)\*\* ?", r"\1 **", code)       # "u8** x" -> "u8 **x"
    code = re.sub(r"\b(\w+)\* ", r"\1 *", code)          # "u8* x" -> "u8 *x"
    code = re.sub(r"\b(\w+)\*([,)])", r"\1 *\2", code)   # "(s32*, s32*)" -> "(s32 *, s32 *)"
    # functions m2c only saw used as addresses (callbacks): declare them as functions
    for f in re.findall(r"^extern \w+ (func_[0-9A-F]{8});$", code, re.M):
        code = code.replace(f"extern s32 {f};", f"void {f}();")
        code = re.sub(r"&" + f + r"\b", f, code)
    return code


def alias_clashes(code, func):
    """Globals and typedefs m2c declares in the draft that the source file also declares
    (usually further down, with another type) would be 'conflicting types': rename them in
    the draft. A global becomes an asm alias (extern T D_x_m2c asm("D_x");, so it still
    links to the same symbol), a typedef just gets another name."""
    src_text = open(m2ctx.find_source(func)[0]).read()
    m = re.search(r"^.*\b" + func + r"(_m)?\(.*\) \{$", code, re.M)
    if not m:
        return code
    pre, body = code[: m.start()], code[m.start():]

    def fresh(name):
        new = name + "_m2c"
        while re.search(r"\b" + new + r"\b", src_text):
            new += "_"
        return new

    # struct typedefs m2c writes (often a copy of the file's with fields it inferred) go first,
    # since the externs m2c lists before them may use them
    blocks = re.findall(r"^typedef\s+(?:struct|union)\b[^;{]*\{.*?^\}\s*\w+\s*;[^\n]*\n?", pre, re.M | re.S)
    for b in blocks:
        pre = pre.replace(b, "", 1)
    pre = "".join(blocks) + pre
    renames = {}
    for t in re.findall(r"^\}\s*(\w+)\s*;", pre, re.M) + re.findall(r"^typedef\s[^{;]*?\b(\w+)\s*;", pre, re.M):
        if re.search(r"(?:\}\s*|typedef\s[^{;]*?\b)" + re.escape(t) + r"\s*;", src_text):
            renames[t] = fresh(t)
    for t, new in renames.items():
        pre = re.sub(r"\b" + re.escape(t) + r"\b", new, pre)
        body = re.sub(r"\b" + re.escape(t) + r"\b", new, body)
    out = []
    for l in pre.split("\n"):
        mm = re.match(r"^extern\s+(?!.*\basm\s*\()(.*?)\b(\w+)\s*((?:\[[^\]]*\])*)\s*;$", l)
        if mm and not mm.group(2).startswith("func_") and re.search(
                r"^[A-Za-z_][^;(\n]*\b" + re.escape(mm.group(2)) + r"\s*(\[[^\]]*\])*\s*(=|;)", src_text, re.M):
            name, new = mm.group(2), fresh(mm.group(2))
            body = re.sub(r"\b" + re.escape(name) + r"\b", new, body)
            l = f'extern {mm.group(1).strip()} {new}{mm.group(3)} asm("{name}");'
        out.append(l)
    return "\n".join(out) + body


BASIC = {"void", "char", "short", "int", "long", "signed", "unsigned", "struct", "union",
         "const", "volatile", "enum"}


def later_protos(name, at=None):
    """Prototypes of NAME (not asm aliases) in the source file of function AT
    (default NAME itself), after AT's position. A function that is already C further
    down counts too: its definition's header, as a prototype."""
    src, before = m2ctx.find_source(at or name)
    after = open(src).read()[len(before):]
    pat = re.compile(r"^[A-Za-z_][\w \t\*]*\b" + re.escape(name) + r"\s*\(([^;{}()]*)\)\s*(;|\{)", re.M)
    return [m.group(0)[:-1].rstrip() + ";" for m in pat.finditer(after)]


def resolvable(proto, ctx):
    for word in re.findall(r"[A-Za-z_]\w*", proto.split("(", 1)[0].rsplit(None, 1)[0] + " "
                           + proto.split("(", 1)[1]):
        if word in BASIC or re.match(r"func_|[a-z]\d*$", word):
            continue
        if not re.search(r"\b" + re.escape(word) + r"\s*;", ctx):
            return False
    return True


def fix_compile(code, func, ctx):
    """Make m2c's draft compile. A prototype m2c guessed for a callee that the same
    source file declares further down would conflict with that declaration: use the
    file's own declaration instead when its types are known here, else drop the
    guess. Stack slots m2c reads but never declared get declared."""
    lines = []
    for l in code.split("\n"):
        # top-level prototypes only: an indented line is a call statement in the body
        m = re.match(r"^(?![ \t])[\w \*]+?\b(func_[0-9A-F]{8})\(.*\);$", l)
        if m and m.group(1) != func:
            later = later_protos(m.group(1), func)
            if later:
                if resolvable(later[0], ctx):
                    lines.append(later[0])
                continue
        lines.append(l)
    code = "\n".join(lines)
    m = re.search(r"^.*\b" + func + r"(_m)?\(.*\) \{\n", code, re.M)
    if not m:
        return code
    body = code[m.end():]
    used = sorted(set(re.findall(r"\b((?:unk)?sp[0-9A-F]+)\b", body)))
    missing = [v for v in used if not re.search(r"^\s+[\w \*]+\b" + v + r"(\[|;)", body, re.M)]
    if missing:
        decl = "".join(f"    s32 {v}; /* m2c: undeclared stack slot */\n" for v in missing)
        code = code[: m.end()] + decl + body
    return code


_RECIPES = {}
WORK = os.path.join(ROOT, "build", "fwork")   # WSL-native: the 32-bit cpp can't stat /mnt/c files


def compile_errors(func, body):
    """Compile the source file with FUNC's INCLUDE_ASM replaced by BODY, using the object's
    real make recipe. Returns None if it compiles, else [(line, msg)] where line is the
    1-based line in BODY (or None when the error is elsewhere in the file)."""
    src = m2ctx.find_source(func)[0]
    text = open(src).read()
    m = re.search(r'^INCLUDE_ASM\("[^"]+", ' + func + r'\);$', text, re.M)
    if not m:
        return None
    rel = os.path.relpath(src, ROOT)
    if rel not in _RECIPES:
        dry = subprocess.run(["make", "--always-make", "--dry-run", "build/" + rel[:-2] + ".o"],
                             cwd=ROOT, capture_output=True, text=True).stdout.splitlines()
        _RECIPES[rel] = next((l for l in dry if rel in l and " -o " in l), None)
    line = _RECIPES[rel]
    if not line:
        return None
    os.makedirs(WORK, exist_ok=True)
    tmp = os.path.join(WORK, f"{func}_{os.path.basename(src)}")
    open(tmp, "w").write(text[: m.start()] + body + text[m.end():])
    cmd = line.replace(rel, tmp, 1).replace("/cpp ", f"/cpp -I{os.path.dirname(rel)} ", 1)
    cmd = cmd[: cmd.rindex(" -o ")] + f" -o {WORK}/{func}.o"
    r = subprocess.run(["bash", "-c", "set -o pipefail; " + cmd], cwd=ROOT, capture_output=True, text=True)
    os.remove(tmp)
    if r.returncode == 0:
        return None
    first = text[: m.start()].count("\n")
    nbody = body.count("\n") + 1
    errs = []
    for l in (r.stderr + r.stdout).splitlines():
        mm = re.match(re.escape(tmp) + r":(\d+): (.*)", l)
        if not mm or mm.group(2).startswith("warning"):
            continue
        n = int(mm.group(1)) - first
        errs.append((n if 1 <= n <= nbody else None, mm.group(2)))
    return errs or [(None, (r.stderr or r.stdout).strip()[-200:])]


def param_count(name, code, func):
    """How many parameters NAME's declaration has (from the draft's preamble, then the
    source file, then include/), or None."""
    pat = re.compile(r"\b" + re.escape(name) + r"\s*\(([^;{}()]*)\)\s*;")
    texts = [code, open(m2ctx.find_source(func)[0]).read()]
    texts += [open(h, errors="replace").read() for h in glob.glob(f"{ROOT}/include/**/*.h", recursive=True)]
    for t in texts:
        mm = pat.search(t)
        if mm:
            ps = mm.group(1).strip()
            return 0 if ps in ("", "void") else len(split_args(ps + ")", 0)[0])
    return None


def fix_calls(line, name, n):
    """Pad (with 0) or trim every call of NAME on LINE to N arguments."""
    out, i = "", 0
    for mm in re.finditer(r"\b" + re.escape(name) + r"\(", line):
        if mm.start() < i:
            continue
        args, j = split_args(line, mm.end())
        args = [a for a in args if a]
        args = (args + ["0"] * n)[:n]
        out += line[i: mm.end()] + ", ".join(args) + ")"
        i = j
    return out + line[i:]


def repair(func, block, passes=8):
    """Compile the draft in its file and patch what m2c's type guesses break:
    a deref of an integer expression gets an (s32 *) cast, calls get the declared
    argument count, a prototype that contradicts the file's goes, M2C_UNALIGNED32 is
    dropped. Patched lines are marked /* m2c-fix */. Returns (block, remaining errors)."""
    head, body = block.split("\n", 1)
    errs = None
    for _ in range(passes):
        errs = compile_errors(func, body)
        if not errs:
            return head + "\n" + body, []
        L = body.split("\n")
        changed = False
        for n, msg in errs:
            fn = re.search(r"arguments to function `(\w+)'", msg)
            if fn and n is None:
                # a call elsewhere in the file disagrees with the prototype m2c guessed
                k = next((k for k, l in enumerate(L)
                          if re.match(r"^(?![ \t])[\w \*]+?\b" + fn.group(1) + r"\(.*\);$", l)), None)
                if k is not None:
                    del L[k]
                    changed = True
                    break
                continue
            if n is None:
                continue
            l = L[n - 1]
            new = l
            if fn:
                cnt = param_count(fn.group(1), "\n".join(L[: n - 1]), func)
                if cnt is not None:
                    new = fix_calls(l, fn.group(1), cnt)
            elif "unary *" in msg or "incompatible type for argument" in msg:
                # *(expr) with no cast right after the '*' (binary * is written "a * b")
                new = re.sub(r"(?<![\w)\]])\*\((?![\w ]+\*+\))", "*(s32 *)(", l)
            elif "M2C_UNALIGNED32" in l:
                new = l.replace("M2C_UNALIGNED32(", "(")
            elif "incompatible types in assignment" in msg:
                # m2c writes a store to a struct local's first member as "sp10 = x;"
                mm = re.match(r"^(\s*)(\w+) = (.*);(.*)$", l)
                if mm:
                    rhs = mm.group(3)
                    t = "s32"
                    dm = re.search(r"\b([su](?:8|16|32))\s+" + re.escape(rhs) + r"\b", "\n".join(L))
                    if dm:
                        t = dm.group(1)
                    elif re.match(r"\((?:[su](8|16|32))\)", rhs):
                        t = rhs[1:rhs.index(")")]
                    new = f"{mm.group(1)}*({t} *)&{mm.group(2)} = {rhs};{mm.group(4)}"
            if new != l:
                L[n - 1] = new + ("" if "m2c-fix" in new else " /* m2c-fix */")
                changed = True
        if not changed:
            break
        body = "\n".join(L)
    errs = compile_errors(func, body)
    return head + "\n" + body, errs or []


def draft(func, raw=False):
    ctx = m2ctx.context(func)
    plain = dict(m2ctx.ALIASED)      # globals the file only declares under asm aliases
    ctx += extra_decls(ctx)
    alias = False
    protos = later_protos(func)
    if protos:
        if resolvable(protos[0], ctx):
            ctx += protos[0] + "\n"       # m2c then uses that signature
        else:
            alias = True                  # its types aren't defined yet at this point
    os.makedirs(f"{ROOT}/build/m2c", exist_ok=True)
    cf = f"{ROOT}/build/m2c/{func}.ctx.c"
    open(cf, "w").write(ctx)
    r = subprocess.run([sys.executable, f"{ROOT}/tools/m2c/m2c.py", "-t", "mipsel-gcc-c",
                        "-P", "4", "--pointer-style", "left", "--context", cf]
                       + ([] if raw else ["--valid-syntax"]) + [asm_path(func)],
                       capture_output=True, text=True)
    out = r.stdout
    if r.returncode or not out.strip():
        return None, (r.stderr or out).strip()
    if not raw:
        lines = []
        for l in out.splitlines():
            if l.endswith("/* extern */") or l.startswith("extern ? "):
                l = re.sub(r"\s*/\* extern \*/$", "", l)
                l = re.sub(r"(?<![\w*])\?", "s32", l)
            else:
                l = re.sub(r"(?<![\w*])\?(?= )", "s32", l)
            lines.append(l)
        out = house_style("\n".join(lines)).strip() + "\n"
        out = fix_compile(out, func, ctx)
        # globals the file only knows under asm aliases (it may also declare the plain name
        # further down with another type): give the block its own alias, typed like the
        # nearest one, e.g. extern s16 D_800E57A0_m2c[] asm("D_800E57A0");
        src_text = open(m2ctx.find_source(func)[0]).read()
        decls = []
        for s, d in plain.items():
            if not re.search(r"\b" + s + r"\b", out):
                continue
            new = s + "_m2c"
            while re.search(r"\b" + new + r"\b", src_text):
                new += "_"
            # m2c's own plain extern for it would become an unaliased duplicate
            out = re.sub(r"^extern [^;\n]*\b" + s + r"\b[^;\n]*;\n", "", out, flags=re.M)
            out = re.sub(r"\b" + s + r"\b", new, out)
            d = re.sub(r"\b" + s + r"\b", new, d, count=1)
            decls.append(d[:-1].rstrip() + f' asm("{s}");')
        if decls:
            out = "\n".join(decls) + "\n" + out
        # after the plain-alias decls, so their struct types get the same _m2c renames
        out = alias_clashes(out, func)
        if alias:
            # define it under another C name so the later, differently typed
            # prototype doesn't conflict (the project's usual asm-alias pattern)
            m = re.search(r"^(.*\b)" + func + r"(\(.*\)) \{$", out, re.M)
            if m:
                head = f"{m.group(1)}{func}_m{m.group(2)}"
                out = out.replace(m.group(0), head + " {", 1)
                out = re.sub(r"^((?:.*\n)*?)(?=.*\b" + func + r"_m\()",
                             lambda mm: mm.group(1) + f'{head} asm("{func}");\n', out, count=1)
    return f"// @@{func}\n{out}", r.stderr.strip()


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("funcs", nargs="+")
    ap.add_argument("-a", "--append", help="append the blocks to this candidate file")
    ap.add_argument("--raw", action="store_true", help="m2c output as is")
    ap.add_argument("--no-repair", action="store_true",
                    help="skip the compile-and-patch pass (it compiles the draft in its file)")
    a = ap.parse_args()
    for f in a.funcs:
        block, err = draft(f, a.raw)
        if block is None:
            print(f"{f}: m2c failed: {err}", file=sys.stderr)
            continue
        if err:
            print(f"{f}: {err}", file=sys.stderr)
        if not a.raw and not a.no_repair:
            block, left = repair(f, block)
            if "m2c-fix" in block:
                print(f"{f}: patched {block.count('m2c-fix')} line(s) so it compiles (marked /* m2c-fix */)",
                      file=sys.stderr)
            for n, msg in left[:3]:
                print(f"{f}: still doesn't compile: {'line ' + str(n) + ': ' if n else ''}{msg}", file=sys.stderr)
        if a.append:
            with open(a.append, "a") as fh:
                fh.write(block)
            print(f"{f}: appended to {a.append}", file=sys.stderr)
        else:
            sys.stdout.write(block)
