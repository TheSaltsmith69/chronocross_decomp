#!/usr/bin/env python3
"""cdkscan.py DIR [NAME...] -- run each named (default: libskip.txt) lib function that has a draft in DIR/lib*.c through libcmp_cdk (psx vs cdk)."""
import glob, os, re, subprocess, sys

S = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
HDR = ('typedef signed char s8; typedef unsigned char u8; typedef short s16; '
       'typedef unsigned short u16; typedef int s32; typedef unsigned int u32;\n')

D = sys.argv[1]
names = sys.argv[2:] or open(os.path.join(S, 'libskip.txt')).read().split()
blocks = {}
for f in sorted(glob.glob(os.path.join(D, 'lib*.c'))):
    for b in re.split(r'(?m)^(?=// @@)', open(f).read()):
        m = re.match(r'// @@(\S+)', b)
        if m:
            blocks.setdefault(m.group(1), []).append(re.sub(r'(?m)^//.*$', '', b))

for n in names:
    if n not in blocks:
        continue
    hits = glob.glob(f'{ROOT}/asm/nonmatchings/lib/**/{n}.s', recursive=True)
    if not hits:
        continue
    obj = os.path.relpath(os.path.dirname(hits[0]), f'{ROOT}/asm/nonmatchings/lib')
    ref = f'{ROOT}/build/asm/lib/{obj}.o'
    if not os.path.exists(ref):
        print(f'{n}: no ref {ref}')
        continue
    best = None
    for i, b in enumerate(blocks[n]):
        p = f'/tmp/cdkscan_{n}_{i}.c'
        open(p, 'w').write(HDR + b)
        out = subprocess.run([f'{ROOT}/.venv/bin/python3', os.path.join(S, 'libcmp_cdk.py'), p, ref],
                             cwd=ROOT, capture_output=True, text=True).stdout
        m = re.search(rf'^{re.escape(n)}: (OK|DIFF (\d+)) \(best: (.*)\)$', out, re.M)
        if not m:
            continue
        d = 0 if m.group(1) == 'OK' else int(m.group(2))
        if best is None or d < best[0]:
            best = (d, m.group(3), i)
    print(f'{n} [{obj}]: {best}')
