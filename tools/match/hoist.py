#!/usr/bin/env python3
"""hoist.py [--file SRC.c] LINE... -- move declaration lines to the top of a C file (right after
`#include "common.h"`), so earlier functions can use them. Each LINE must occur exactly once.
Default file: src/ov_field/field_800A39B4.c."""
import os, sys

M = os.path.dirname(os.path.abspath(__file__))
args = sys.argv[1:]
p = os.path.join(M, '..', '..', 'src', 'ov_field', 'field_800A39B4.c')
if args[:1] == ['--file']:
    p, args = args[1], args[2:]
s = open(p).read()
hdr = '#include "common.h"\n\n'
assert s.startswith(hdr), 'file must start with #include "common.h" and a blank line'
for line in args:
    line = line.replace('\\n', '\n') + '\n'
    assert s.count(line) == 1, line
    s = s.replace(line, '')
    s = hdr + line + s[len(hdr):]
open(p, 'w').write(s)
print('ok')
