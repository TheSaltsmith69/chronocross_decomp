#!/usr/bin/env python3
"""pickblk.py OUT.c DIR name:idx... -- build a lock file from candidate blocks: block idx of each name,
counting over all lib*.c files in DIR (sorted by name)."""
import glob, os, re, sys

out_path, d = sys.argv[1], sys.argv[2]
blocks = {}
for f in sorted(glob.glob(os.path.join(d, 'lib*.c'))):
    for b in re.split(r'(?m)^(?=// @@)', open(f).read()):
        m = re.match(r'// @@(\S+)', b)
        if m:
            blocks.setdefault(m.group(1), []).append(b)
out = []
for spec in sys.argv[3:]:
    n, i = spec.split(':')
    out.append(blocks[n][int(i)])
open(out_path, 'w').write(''.join(out))
print(len(out), 'blocks')
