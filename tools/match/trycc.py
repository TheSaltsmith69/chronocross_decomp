"""Substitute C candidates into src files, compile, and compare each function's
instructions against the original asm (relocated fields masked).

Candidate file: blocks headed `// @@func_name`; the same name may appear several
times (variants), tried in rounds. The src file holding that function's
INCLUDE_ASM is found automatically. A name that several overlays share needs the
overlay: `// @@func_801EE000@ov_party2` (see funcref.py).

usage: trycc.py CANDS.c [VERSION] [--keep] [--show]
"""
import glob, os, re, subprocess, sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import funcref

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
args = sys.argv[1:]
cands_path = args[0]
keep = "--keep" in args
showdiff = "--show" in args
vers = [a for a in args[1:] if not a.startswith("--")]
V = vers[0] if vers else "2.8.1"

blocks = re.split(r'^// @@(\S+)\n', open(cands_path).read(), flags=re.M)[1:]
variants = {}
for name, code in zip(blocks[0::2], blocks[1::2]):
    variants.setdefault(name, []).append(code)

srcs = {p: open(p).read() for p in glob.glob(f"{ROOT}/src/**/*.c", recursive=True)}
unit_of = {}            # block name (plain or NAME@MODULE) -> its source file
for name in variants:
    unit_of[name] = funcref.find(name, srcs)
bare = funcref.name_of


def make(target):
    return subprocess.run(["make", "-C", ROOT, f"CC_VERSION={V}", target], capture_output=True, text=True)


def obj_of(src):
    return src.replace(f"{ROOT}/src/", f"{ROOT}/build/src/")[:-2] + ".o"


def disasm(obj):
    out = subprocess.run(["mips-linux-gnu-objdump", "-d", "-r", "-z", obj], capture_output=True, text=True).stdout
    funcs, cur = {}, None
    for l in out.splitlines():
        m = re.match(r'^[0-9a-f]+ <(\S+)>:', l)
        if m:
            cur = m.group(1); funcs[cur] = []; continue
        m = re.match(r'^\s+([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', l)
        if m and cur:
            funcs[cur].append([int(m.group(2), 16), False, re.sub(r'\s+', ' ', m.group(3)).split(' <')[0]]); continue
        if re.match(r'^\s+[0-9a-f]+: R_MIPS_', l) and cur and funcs[cur]:
            funcs[cur][-1][1] = True
    return funcs


def norm(ins):
    res = []
    for w, rel, txt in ins:
        if rel:
            w &= 0xFC000000 if (w >> 26) in (2, 3) else 0xFFFF0000
        res.append(w)
    return res


def eq(g, e):
    """g = our insn, e = original; a relocated insn of ours matches any immediate."""
    if g[1]:
        m = 0xFC000000 if (g[0] >> 26) in (2, 3) else 0xFFFF0000
        return g[0] & m == e[0] & m
    return norm([g]) == norm([e])


def same_func(g, e):
    return len(g) == len(e) and all(eq(a, b) for a, b in zip(g, e))


def subst(t, chosen):
    for name, code in chosen.items():
        t = re.sub(r'INCLUDE_ASM\("[^"]+",\s*' + re.escape(bare(name)) + r'\);', lambda m: code.strip(), t)
    return t


units = sorted(set(unit_of.values()))
refs = {}
for u in units:
    subprocess.run(["rm", "-f", obj_of(u)])
    r = make(obj_of(u).replace(ROOT + "/", ""))
    assert r.returncode == 0, r.stderr
    refs[u] = disasm(obj_of(u))

matched = {}  # name -> code
best = {}     # name -> (ndiff, text)
rounds = max(len(v) for v in variants.values())
try:
    for k in range(rounds):
        for u in units:
            chosen = {n: v[k] for n, v in variants.items() if unit_of[n] == u and len(v) > k and v[k].strip() and n not in matched}
            if not chosen:
                continue
            open(u, "w").write(subst(srcs[u], chosen))
            subprocess.run(["rm", "-f", obj_of(u)])
            r = make(obj_of(u).replace(ROOT + "/", ""))
            if r.returncode != 0:
                print(f"[v{k}] {u}: COMPILE FAILED\n" + "\n".join(l for l in r.stderr.splitlines() if 'warning' not in l and 'In function' not in l and 'At top level' not in l)[:1500])
                continue
            got = disasm(obj_of(u))
            for name in chosen:
                g, e = got.get(bare(name)), refs[u].get(bare(name))
                if g is not None and same_func(g, e):
                    matched[name] = chosen[name]
                    print(f"[v{k}] {name}: OK")
                    continue
                if g is None:
                    continue
                lines = []
                nd = 0
                for i in range(max(len(g), len(e))):
                    a = g[i][2] if i < len(g) else ""
                    b = e[i][2] if i < len(e) else ""
                    same = i < len(g) and i < len(e) and eq(g[i], e[i])
                    nd += not same
                    lines.append(("  " if same else "* ") + f"{a:<40} | {b}")
                txt = f"--- {name} [v{k}] ({nd} diff, {len(g)} vs {len(e)}): ours | original\n" + "\n".join(lines)
                if name not in best or nd < best[name][0]:
                    best[name] = (nd, txt)
finally:
    for u in units:
        t = srcs[u]
        if keep:
            t = subst(t, {n: c for n, c in matched.items() if unit_of[n] == u})
        open(u, "w").write(t)

if showdiff:
    for name in variants:
        if name not in matched and name in best:
            print(best[name][1])
print(f"gcc {V}: {len(matched)}/{len(variants)} match")
print("  OK:  ", " ".join(n for n in variants if n in matched))
print("  DIFF:", " ".join(n for n in variants if n not in matched))
