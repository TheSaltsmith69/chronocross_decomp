import re, sys
# join.py base.c out.c [func=file:k ...]  -- first block of each func from base, overrides from other files
S = ""
def blocks(f):
    b = re.split(r'^// @@(\S+)\n', open(S + f).read(), flags=re.M)[1:]
    return list(zip(b[0::2], b[1::2]))
base = {}
for n, c in blocks(sys.argv[1]):
    base.setdefault(n, c)
for o in sys.argv[3:]:
    n, rest = o.split('=')
    f, k = rest.split(':')
    if f == '-':
        del base[n]
        continue
    base[n] = [c for nn, c in blocks(f) if nn == n][int(k)]
open(S + sys.argv[2], 'w').write(''.join('// @@' + n + '\n' + c for n, c in base.items()))
print(len(base))
