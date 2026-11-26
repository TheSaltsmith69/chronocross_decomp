#!/usr/bin/env python3
"""easy.py [RANK.txt] [N] -- easiest-first order from rank.py output: fewest loops, no GTE, no jump table,
closest matched sibling, then size. Skips PARKED rows and ov_field's libpress (func_800A3*/A4*)."""
import re, sys

path = sys.argv[1] if len(sys.argv) > 1 else '/tmp/rank_ov_field.txt'
N = int(sys.argv[2]) if len(sys.argv) > 2 else 25
rows = []
for l in open(path):
    if 'PARKED' in l or ('ov_field' in path and re.match(r'func_800A[34]', l)):
        continue
    d = dict(re.findall(r'(\w+)=(\S+)', l))
    sim = float(l.split()[-1])
    rows.append((int(d['loops']), int(d['gte']), int(d['jr']) > 1, -round(sim, 1), int(d['n']), l.split()[0], d.get('sib', '-'), sim, int(d['jal'])))
rows.sort()
print('unparked:', len(rows))
for r in rows[:N]:
    print('%s n=%d loops=%d gte=%d jtbl=%s jal=%d sib=%s %.2f' % (r[5], r[4], r[0], r[1], r[2], r[8], r[6], r[7]))
