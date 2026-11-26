#!/usr/bin/env python3
"""m2ctx.py FUNC [-o OUT] -- m2c context for one function.

The context is what FUNC can see where it sits in its source file: the file up to
FUNC's INCLUDE_ASM line (or its C definition), with its includes, preprocessed
with the project's cpp. Function bodies become prototypes, and GCC-only syntax
m2c's parser doesn't take is removed: `asm("name")` labels on declarations
(an alias declaration is kept under the real name only when nothing declares
that name directly), __asm__ blocks and __attribute__s.
"""
import argparse, glob, os, re, subprocess, sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
CPP = [f"{ROOT}/tools/gcc-2.8.1-psx/cpp", "-undef", "-lang-c", "-nostdinc",
       f"-I{ROOT}/include", f"-I{ROOT}/src", "-D_LANGUAGE_C", "-DM2CTX"]


def find_source(func):
    """(source path, text before FUNC) for the file that holds FUNC."""
    inc = re.compile(r'^INCLUDE_ASM\("[^"]+", ' + re.escape(func) + r'\);', re.M)
    dfn = re.compile(r'^[A-Za-z_][\w \t\*]*\b' + re.escape(func) + r'\s*\([^;]*$', re.M)
    for src in sorted(glob.glob(f"{ROOT}/src/**/*.c", recursive=True)):
        text = open(src).read()
        m = inc.search(text) or dfn.search(text)
        if m:
            return src, text[: m.start()]
    sys.exit(f"{func}: not found under src/")


def toplevel(text):
    """Split C text into top-level items: ('pp'|'func'|'decl', text)."""
    out, cur, depth, i, n = [], "", 0, 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("/*", i):
            i = text.index("*/", i) + 2
            continue
        if text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        if c in "\"'":
            j = i + 1
            while text[j] != c:
                j += 2 if text[j] == "\\" else 1
            cur += text[i : j + 1]
            i = j + 1
            continue
        if c == "#" and depth == 0 and cur.strip() == "":
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(("pp", text[i:j]))
            cur, i = "", j
            continue
        cur += c
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                head = cur[: cur.index("{")]
                # (a body may be followed by a bare ";" -- an INCLUDE_ASM that preprocessed away)
                if ("(" in head and "=" not in head
                        and not re.match(r"\s*(typedef|struct|union|enum|extern)\b", head)):
                    out.append(("func", cur))
                    cur = ""
        elif c == ";" and depth == 0:
            out.append(("decl", cur))
            cur = ""
        i += 1
    return out


ASM_LABEL = re.compile(r'\s*\b(?:__)?asm(?:__)?\s*\(\s*"([^"]+)"\s*\)')


def declared_name(decl):
    """The identifier a simple declaration declares (best effort)."""
    d = re.sub(r"\[[^\]]*\]", "", decl)
    d = re.sub(r"\([^()]*\)\s*$", "", d.strip())        # parameter list of a prototype
    m = re.findall(r"([A-Za-z_]\w*)\s*\)?\s*$", d)
    return m[-1] if m else None


def context(func, keep_aliases=False):
    """keep_aliases: leave asm("...") labels as they are (declarations exactly as the
    source has them, for code that is compiled in that file rather than parsed by m2c)."""
    src, before = find_source(func)
    pre = subprocess.run(CPP, input=before, capture_output=True, text=True, cwd=os.path.dirname(src))
    if pre.returncode:
        sys.exit(pre.stderr)
    items = []
    for kind, t in toplevel(pre.stdout):
        t = t.strip()
        if kind == "pp" or not t or t == ";":
            continue
        if kind == "func":
            t = t[: t.index("{")].strip() + ";"
        if re.match(r"(__asm__|asm)\s*\(", t):
            continue
        t = re.sub(r"__attribute__\s*\(\(.*?\)\)", "", t)
        t = re.sub(r"\b__inline__\b|\binline\b", "", t)
        items.append(t if t.endswith(";") else t + ";")
    if keep_aliases:
        return "\n".join(items) + "\n"

    # asm-labelled aliases: rename to the real symbol unless it is declared directly
    direct = set()
    for t in items:
        if not ASM_LABEL.search(t) and not t.startswith("typedef"):
            n = declared_name(t[:-1])
            if n:
                direct.add(n)
    out, seen = [], set()
    for t in items:
        m = ASM_LABEL.search(t)
        if m:
            real = m.group(1)
            if real in direct or real in seen:
                continue
            body = ASM_LABEL.sub("", t)
            alias = declared_name(body[:-1])
            if not alias:
                continue
            t = re.sub(r"\b" + re.escape(alias) + r"\b", real, body, count=1)
            seen.add(real)
        out.append(t)
    return "\n".join(out) + "\n"


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("func")
    ap.add_argument("-o", "--output")
    a = ap.parse_args()
    ctx = context(a.func)
    if a.output:
        open(a.output, "w").write(ctx)
    else:
        sys.stdout.write(ctx)
