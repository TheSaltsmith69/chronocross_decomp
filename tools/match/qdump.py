#!/usr/bin/env python3
"""qdump.py MAXBYTES [SKIP] [N] -- asm of unmatched boot-to-title quest functions up to MAXBYTES,
smallest first, minus parked_main.txt. SKIP/N page through the list."""
import csv, glob, os, re, sys

M = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(M, '..', '..'))
maxb = int(sys.argv[1]); skip = int(sys.argv[2]) if len(sys.argv) > 2 else 0
rows = list(csv.DictReader(open(f"{ROOT}/progress/quest_boot_to_title.csv")))
asmfiles = {os.path.basename(p)[:-2]: p for p in glob.glob(f"{ROOT}/asm/nonmatchings/game/*/*.s")}
SKIP = set(open(os.path.join(M, 'parked_main.txt')).read().split())
todo = sorted((int(r['bytes']), r['name'], r['file']) for r in rows
              if r['category'] == 'game' and r['matched'] == '0' and int(r['bytes']) <= maxb)
inc = set(re.findall(r'INCLUDE_ASM\("[^"]+",\s*(\w+)\)', ''.join(open(p).read() for p in glob.glob(f"{ROOT}/src/**/*.c", recursive=True))))
todo = [t for t in todo if t[1] in asmfiles and t[1] in inc and t[1] not in SKIP][skip:]
if len(sys.argv) > 3:
    todo = todo[:int(sys.argv[3])]
print(len(todo), "candidates")
for b, n, f in todo:
    print(f"\n## {n} ({f}, {b} B)")
    for l in open(asmfiles[n]):
        if l.startswith(('glabel', 'nonmatching', 'endlabel', '.size')) or not l.strip():
            continue
        print(re.sub(r'/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/', r'\1', l.rstrip()))
