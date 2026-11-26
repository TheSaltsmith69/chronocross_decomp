#!/usr/bin/env python3
"""subst.py CANDS.c [ROOT] -- put candidate blocks into src/ in place of their INCLUDE_ASM.

CANDS.c holds blocks headed `// @@func_name`. The first block for each name wins
(later variants find the INCLUDE_ASM already gone). Prints the files changed.
"""
import glob, os, re, sys

cands = sys.argv[1]
root = sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..')
b = re.split(r'^// @@(\S+)\n', open(cands).read().replace('\r\n', '\n'), flags=re.M)[1:]
srcs = {p: open(p).read() for p in glob.glob(os.path.join(root, 'src', '**', '*.c'), recursive=True)}
changed = set()
for name, code in zip(b[0::2], b[1::2]):
    pat = r'INCLUDE_ASM\("[^"]+",\s*' + re.escape(name) + r'\);'
    for p, t in srcs.items():
        if re.search(pat, t):
            srcs[p] = re.sub(pat, lambda m: code.strip(), t, count=1)
            changed.add(p)
            break
    else:
        print(f'{name}: no INCLUDE_ASM (already C?)', file=sys.stderr)
for p in sorted(changed):
    open(p, 'w').write(srcs[p])
    print(os.path.relpath(p, root))
