import re, sys
# adddecl.py file.c func "decl text" : prepend decl text to every block of func
path, func, decl = sys.argv[1], sys.argv[2], sys.argv[3].replace('\\n', '\n')
t = open(path).read()
parts = re.split(r'(^// @@\S+\n)', t, flags=re.M)
out = []
for i, p in enumerate(parts):
    out.append(p)
    if p.strip() == '// @@' + func:
        out.append(decl if decl.endswith('\n') else decl + '\n')
open(path, 'w').write(''.join(out))
