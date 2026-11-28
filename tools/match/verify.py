"""Test each Codex C function individually against the clean main repo.

usage: verify.py CODEX.c ROOT OUTDIR
For each function that is INCLUDE_ASM in ROOT's field file but defined in CODEX.c,
substitute the Codex definition (plus the decl lines preceding it in CODEX.c) alone,
compile the overlay object, and compare instructions (relocs masked) with the original.
Writes OUTDIR/results.txt and OUTDIR/ok_blocks.c (trycc format) / diffs.
"""
import re, subprocess, sys, os

codex_path, ROOT, OUT = sys.argv[1:4]
SRC = f"{ROOT}/src/ov_field/field_800A39B4.c"
OBJ = "build/src/ov_field/field_800A39B4.o"
os.makedirs(OUT, exist_ok=True)


def chunks(text):
    """Split into top-level chunks: (kind, name, text). kind: 'func' or 'other'."""
    out, i, n, start, depth = [], 0, len(text), 0, 0
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            i = text.find("\n", i); i = n if i < 0 else i; continue
        if text.startswith("/*", i):
            i = text.find("*/", i) + 2; continue
        if c in "\"'":
            j = i + 1
            while text[j] != c:
                j += 2 if text[j] == "\\" else 1
            i = j + 1; continue
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                # end of a brace group at top level; include trailing ';' if struct
                j = i + 1
                m = re.match(r'[^;{}]*;', text[j:]) if re.match(r'\s*[A-Za-z_*\s\[\]0-9,]*;', text[j:j+200] or "") else None
                seg = text[start:j]
                if m and not re.search(r'\)\s*\{', seg.split("{")[0] + "{"):
                    j += m.end()
                    seg = text[start:j]
                out.append(seg); start = j
        elif c == ";" and depth == 0:
            out.append(text[start:i+1]); start = i + 1
        i += 1
    out.append(text[start:])
    res = []
    for s in out:
        head = s.split("{")[0]
        m = re.search(r'(\w+)\s*\([^;]*\)\s*$', head)
        if "{" in s and m and "typedef" not in head and "=" not in head and not head.strip().startswith("struct"):
            res.append(("func", m.group(1), s))
        else:
            res.append(("other", None, s))
    return res


codex = open(codex_path).read()
main = open(SRC).read()
asm_funcs = set(re.findall(r'INCLUDE_ASM\("[^"]+",\s*(\w+)\);', main))

cands = {}  # name -> block text (preceding decls + def)
pending = []
for kind, name, s in chunks(codex):
    if kind == "func":
        if name in asm_funcs:
            pre = "".join(p for p in pending if "INCLUDE_ASM" not in p and p.strip() not in main)
            cands[name] = (pre + s).strip() + "\n"
        pending = []
    else:
        # drop INCLUDE_ASM and blank parts; keep decls
        pending.append(re.sub(r'INCLUDE_ASM\([^;]*;', "", s))
print(f"{len(cands)} candidates:", " ".join(sorted(cands)))


def make():
    subprocess.run(["rm", "-f", f"{ROOT}/{OBJ}"])
    return subprocess.run(["make", "-C", ROOT, OBJ], capture_output=True, text=True)


def disasm():
    out = subprocess.run(["mips-linux-gnu-objdump", "-d", "-r", "-z", f"{ROOT}/{OBJ}"], capture_output=True, text=True).stdout
    funcs, cur = {}, None
    for l in out.splitlines():
        m = re.match(r'^[0-9a-f]+ <(\S+)>:', l)
        if m:
            cur = m.group(1); funcs[cur] = []; continue
        m = re.match(r'^\s+([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', l)
        if m and cur:
            funcs[cur].append([int(m.group(2), 16), False, re.sub(r'\s+', ' ', m.group(3)).split(' <')[0]]); continue
        m = re.match(r'^\s+[0-9a-f]+: (R_MIPS_\w+)\s+(\S+)', l)
        if m and cur and funcs[cur]:
            funcs[cur][-1][1] = (m.group(1), m.group(2))
    return funcs


def norm(ins):
    """Relocated fields masked, but a call (jal/j) keeps the name of the function it calls, so a
    call to the wrong function is not a match."""
    out = []
    for w, rel, _ in ins:
        if not rel:
            out.append(w)
        elif rel[0] == "R_MIPS_26" and not rel[1].startswith("."):
            out.append((w & 0xFC000000, rel[1].split("+")[0]))
        else:
            out.append(w & (0xFC000000 if (w >> 26) in (2, 3) else 0xFFFF0000))
    return out


r = make(); assert r.returncode == 0, r.stderr
ref = disasm()
results, ok = [], []
try:
    only = os.environ.get("ONLY", "").split()
    for name in sorted(cands):
        if only and name not in only:
            continue
        code = cands[name]
        base = main
        if os.environ.get("FIXPROTO"):
            # drop other prototypes of this function, put the codex signature at the top
            base = re.sub(r'^[^\n(]*\b' + re.escape(name) + r'\s*\([^;{]*\);[ \t]*$', "", base, flags=re.M)
            base = re.sub(r'(\n\s+)[^\n(]*\b' + re.escape(name) + r'\s*\([^;{)]*\);', r'\1', base)
            sig = re.search(r'^([^\n]*\b' + re.escape(name) + r'\s*\([^)]*\))\s*\{', code, flags=re.M).group(1)
            base = base.replace('#include "common.h"\n', '#include "common.h"\n' + sig + ';\n' + os.environ.get("EXTRA", "") + "\n", 1)
        t = re.sub(r'INCLUDE_ASM\("[^"]+",\s*' + re.escape(name) + r'\);', lambda m: code.strip(), base)
        open(SRC, "w").write(t)
        r = make()
        if r.returncode != 0:
            err = "\n".join(l for l in r.stderr.splitlines() if "warning" not in l and ": In function" not in l and "At top level" not in l)[:900]
            results.append(f"{name}: COMPILE FAILED\n{err}")
            print(name, "COMPILE FAILED", flush=True); continue
        g, e = disasm().get(name), ref.get(name)
        if g is not None and norm(g) == norm(e):
            results.append(f"{name}: OK"); ok.append(name)
            print(name, "OK", flush=True); continue
        nd = sum(1 for i in range(max(len(g or []), len(e))) if not (i < len(g or []) and i < len(e) and norm([g[i]]) == norm([e[i]])))
        results.append(f"{name}: DIFF {nd} ({len(g or [])} vs {len(e)} insns)")
        print(name, "DIFF", nd, flush=True)
finally:
    open(SRC, "w").write(main)
open(f"{OUT}/results.txt", "w").write("\n".join(results) + "\n")
with open(f"{OUT}/ok_blocks.c", "w") as f:
    for n in ok:
        f.write(f"// @@{n}\n{cands[n]}\n")
with open(f"{OUT}/all_blocks.c", "w") as f:
    for n in sorted(cands):
        f.write(f"// @@{n}\n{cands[n]}\n")
print(f"{len(ok)}/{len(cands)} OK:", " ".join(ok))
