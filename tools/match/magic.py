#!/usr/bin/env python3
"""magic.py MAGIC SHIFT [MAXD] -- find the divisor d behind a gcc magic-number division
(mult by MAGIC, then sra by SHIFT on the hi word). Example: magic.py 0x7AD773E3 9"""
import sys

m, s = int(sys.argv[1], 0), int(sys.argv[2], 0)
maxd = int(sys.argv[3]) if len(sys.argv) > 3 else 100000
for d in range(2, maxd):
    if (2 ** (32 + s) + d - 1) // d == m or 2 ** (32 + s) // d + 1 == m:
        print(hex(m), s, d)
