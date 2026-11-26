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


BASIC = {"void", "char", "short", "int", "long", "signed", "unsigned", "struct", "union",
         "const", "volatile", "enum"}


def later_protos(name, at=None):
    """Prototypes of NAME (not asm aliases) in the source file of function AT
    (default NAME itself), after AT's position."""
    src, before = m2ctx.find_source(at or name)
    after = open(src).read()[len(before):]
    pat = re.compile(r"^[A-Za-z_][\w \t\*]*\b" + re.escape(name) + r"\s*\(([^;{}()]*)\)\s*;", re.M)
    return [m.group(0) for m in pat.finditer(after)]


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
        m = re.match(r"^[\w \*]+?\b(func_[0-9A-F]{8})\(.*\);$", l)
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


def draft(func, raw=False):
    ctx = m2ctx.context(func)
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
    a = ap.parse_args()
    for f in a.funcs:
        block, err = draft(f, a.raw)
        if block is None:
            print(f"{f}: m2c failed: {err}", file=sys.stderr)
            continue
        if err:
            print(f"{f}: {err}", file=sys.stderr)
        if a.append:
            with open(a.append, "a") as fh:
                fh.write(block)
            print(f"{f}: appended to {a.append}", file=sys.stderr)
        else:
            sys.stdout.write(block)
