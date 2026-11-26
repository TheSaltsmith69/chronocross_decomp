import sys, re, difflib
# adiff.py OUT : alignment diff of trycc --show output (ours | original columns)
lines = open(sys.argv[1]).read().split('\n')
ours, orig = [], []
for l in lines[1:]:
    if not l.startswith(('  ', '* ')):
        if l.startswith('gcc'):
            break
        continue
    body = l[2:]
    if '|' not in body:
        continue
    a, b = body.split('|', 1)
    a = a.strip(); b = b.strip()
    if a: ours.append(a)
    if b: orig.append(b)
norm = lambda s: re.sub(r'\b[0-9a-f]{3,5}\b$', 'T', s)  # branch targets
na = [norm(x) for x in ours]; nb = [norm(x) for x in orig]
sm = difflib.SequenceMatcher(None, na, nb, autojunk=False)
ctx = int(sys.argv[2]) if len(sys.argv) > 2 else 2
n = 0
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        continue
    n += 1
    print('--- %s ours[%d:%d] orig[%d:%d]' % (tag, i1, i2, j1, j2))
    for k in range(max(0, i1 - ctx), i1):
        print('   ', ours[k])
    for k in range(i1, i2):
        print('  -', ours[k])
    for k in range(j1, j2):
        print('  +', orig[k])
print('blocks:', n, 'ratio', round(sm.ratio(), 4))
