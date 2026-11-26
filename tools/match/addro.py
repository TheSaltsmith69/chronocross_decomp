import sys
path, func = sys.argv[1], sys.argv[2]
syms = sys.argv[3:]
t = open(path).read()
folder = 'asm/nonmatchings/game/' + path.split('/')[-1][:-2]
anchor = f'INCLUDE_ASM("{folder}", {func});'
assert anchor in t, anchor
lines = ''.join(f'INCLUDE_RODATA("{folder}", {s});\n\n' for s in syms)
t = t.replace(anchor, lines + anchor)
open(path, 'w').write(t)
print('ok')
