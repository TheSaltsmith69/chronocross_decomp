#!/usr/bin/env python3
"""rank.py [OV] [OUT] -- rank an overlay's remaining INCLUDE_ASM functions for easiest-first work.

For each: insn count, backward branches (loops), jal/jr counts, GTE ops, and the most
similar already-matched function ("sibling", difflib ratio of opcode sequences).
Writes OUT (default /tmp/rank_<OV>.txt); parked functions (parked_<OV>.txt) are tagged PARKED.
"""
import difflib, glob, os, re, sys

M = os.path.dirname(os.path.abspath(__file__))
R = os.path.abspath(os.path.join(M, '..', '..'))
OV = sys.argv[1] if len(sys.argv) > 1 else 'ov_field'
OUT = sys.argv[2] if len(sys.argv) > 2 else f'/tmp/rank_{OV}.txt'
srcs = glob.glob(f'{R}/src/{OV}/*.c')
todo, dirs = [], {}
for s in srcs:
    for d, f in re.findall(r'INCLUDE_ASM\("([^"]+)",\s*(\w+)\);', open(s).read()):
        todo.append(f); dirs[f] = f'{R}/{d}/'
pf = os.path.join(M, f'parked_{OV}.txt')
parked = set(open(pf).read().split()) if os.path.exists(pf) else set()
GTE = {'mtc2', 'mfc2', 'ctc2', 'cfc2', 'lwc2', 'swc2', 'NCLIP', 'MVMVA', 'AVSZ3', 'AVSZ4', 'RTPS', 'RTPT', 'SQR',
       'OP', 'GPF', 'GPL', 'NCDS', 'NCCS', 'DPCS', 'INTPL'}


def ops(path):
    return [m.group(1) for l in open(path) for m in [re.search(r'\*/\s+(\w+)', l)] if m]


allf = {}
for d in glob.glob(f'{R}/asm/{OV}/nonmatchings/*/'):
    for p in glob.glob(d + '*.s'):
        allf[os.path.basename(p)[:-2]] = p
done = sorted(set(allf) - set(todo))
dops = {f: ops(allf[f]) for f in done}
rows = []
for f in todo:
    path = dirs[f] + f + '.s'
    if not os.path.exists(path):
        continue
    o = ops(path); n = len(o)
    txt = open(path).read()
    pos, idx = {}, 0
    for l in txt.splitlines():
        m = re.match(r'\s*\.(L[0-9A-F]+):', l)
        if m: pos[m.group(1)] = idx
        if re.search(r'\*/\s+\w', l): idx += 1
    back = idx = 0
    for l in txt.splitlines():
        if re.search(r'\*/\s+\w', l):
            m = re.search(r'\.(L[0-9A-F]+)\s*$', l)
            if m and m.group(1) in pos and pos[m.group(1)] <= idx and re.search(r'\*/\s+b', l): back += 1
            idx += 1
    gte = sum(1 for x in o if x in GTE or x.startswith('RT'))
    best, bs = '', 0.0
    for d, dop in dops.items():
        if abs(len(dop) - n) > n * 0.25: continue
        sm = difflib.SequenceMatcher(None, o, dop, autojunk=False)
        if sm.quick_ratio() < max(bs, 0.8): continue
        r = sm.ratio()
        if r > bs: best, bs = d, r
    rows.append((f, n, back, o.count('jal'), o.count('jr'), gte, best, bs, f in parked))
rows.sort(key=lambda r: (-r[7], r[1]))
with open(OUT, 'w') as fh:
    for r in rows:
        fh.write('%s n=%d loops=%d jal=%d jr=%d gte=%d sib=%s %.2f %s\n' % (r[0], r[1], r[2], r[3], r[4], r[5], r[6] or '-', r[7], 'PARKED' if r[8] else ''))
up = [r for r in rows if not r[8]]
print(f'{OUT}: todo', len(rows), 'unparked', len(up))
print('unparked with sibling>=0.85:', sum(1 for r in up if r[7] >= 0.85))
print('unparked no loops:', sum(1 for r in up if r[2] == 0), ' with jr>1 (jump table):', sum(1 for r in up if r[4] > 1), ' gte:', sum(1 for r in up if r[5]))
