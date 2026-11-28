#!/usr/bin/env python3
"""subst.py CANDS.c [ROOT] -- put candidate blocks into src/ in place of their INCLUDE_ASM.

CANDS.c holds blocks headed `// @@func_name` (or `// @@func_name@ov_x` for a name several
overlays share, see funcref.py). The first block for each name wins (later variants find
the INCLUDE_ASM already gone). Prints the files changed.
"""
import glob, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import funcref

cands = sys.argv[1]
root = sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..')
funcref.ROOT = os.path.abspath(root)
b = re.split(r'^// @@(\S+)\n', open(cands).read().replace('\r\n', '\n'), flags=re.M)[1:]
srcs = {p: open(p).read() for p in glob.glob(os.path.join(funcref.ROOT, 'src', '**', '*.c'), recursive=True)}
changed = set()
for ref, code in zip(b[0::2], b[1::2]):
    name = funcref.name_of(ref)
    pat = r'INCLUDE_ASM\("[^"]+",\s*' + re.escape(name) + r'\);'
    try:
        p = funcref.find(ref, srcs)
    except funcref.Ambiguous as e:
        sys.exit(str(e))
    except SystemExit:
        print(f'{ref}: no INCLUDE_ASM (already C?)', file=sys.stderr)
        continue
    srcs[p] = re.sub(pat, lambda m: code.strip(), srcs[p], count=1)
    changed.add(p)
for p in sorted(changed):
    open(p, 'w').write(srcs[p])
    print(os.path.relpath(p, funcref.ROOT))
