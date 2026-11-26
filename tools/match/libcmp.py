#!/usr/bin/env python3
"""libcmp.py CANDS.c REF.o [--show]

Compile CANDS.c under several toolchain setups and compare every function it
defines with the same-named function in REF.o (an object assembled from the
original asm). Relocated instructions compare by mnemonic only.
"""
import os, re, subprocess, sys, tempfile

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
CROSS = 'mips-linux-gnu-'
cands, ref = sys.argv[1], sys.argv[2]
show = '--show' in sys.argv
# the 32-bit PsyQ tools cannot stat files on /mnt/c
_tmp = tempfile.mkdtemp() + '/cands.c'
open(_tmp, 'w').write(open(cands).read())
cands = _tmp

SETUPS = []
for cc in ('2.7.2', '2.8.1'):
    for uchar in (False, True):
        for filt in (True, False):
            SETUPS.append((cc, uchar, filt))


def disasm(obj):
    out = subprocess.run([CROSS + 'objdump', '-dr', '-z', '-M', 'no-aliases', obj],
                         capture_output=True, text=True).stdout
    funcs, cur = {}, None
    for line in out.split('\n'):
        m = re.match(r'^[0-9a-f]+ <(\S+)>:$', line)
        if m:
            cur = m.group(1)
            funcs[cur] = []
            continue
        if cur is None:
            continue
        m = re.match(r'^\s+[0-9a-f]+:\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$', line)
        if m:
            funcs[cur].append([m.group(2), m.group(3), False])
        elif re.match(r'^\s+[0-9a-f]+: R_MIPS', line) and funcs[cur]:
            funcs[cur][-1][2] = True
    return funcs


def norm(ins):
    op, args, rel = ins
    if rel:
        return op
    args = re.sub(r'\s*<[^>]*>', '', args)
    if op in ('b', 'beq', 'bne', 'bgez', 'bltz', 'blez', 'bgtz', 'j', 'beqz', 'bnez'):
        args = re.sub(r',?[0-9a-f]+$', '', args)  # branch targets are section offsets
    return op + ' ' + args


def build(setup):
    cc, uchar, filt = setup
    d = tempfile.mkdtemp()
    flags = '-quiet -O2 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker'
    if uchar:
        flags += ' -funsigned-char'
    filt_cmd = '.venv/bin/python3 tools/aspsx_delay_slots.py' if filt else 'cat'
    cmd = (f"tools/gcc-2.8.1-psx/cpp -undef -lang-c -nostdinc -Iinclude -Isrc -D_LANGUAGE_C {cands} | "
           f"tools/gcc-{cc}-psx/cc1 {flags} | {filt_cmd} | "
           f".venv/bin/python3 tools/maspsx/maspsx.py --aspsx-version=2.79 | "
           f"{CROSS}as -EL -I. -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -o {d}/c.o")
    r = subprocess.run(['bash', '-o', 'pipefail', '-c', cmd], cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        return None, r.stderr[-800:]
    return disasm(f'{d}/c.o'), ''


reff = disasm(ref)
names = None
best = {}
for setup in SETUPS:
    ours, err = build(setup)
    if ours is None:
        print(setup, 'COMPILE FAILED', err)
        continue
    if names is None:
        names = [n for n in ours if n in reff]
    for n in names:
        a = [norm(i) for i in ours.get(n, [])]
        b = [norm(i) for i in reff[n]]
        # ignore the object's trailing padding nops in the reference
        while b and b[-1] == 'sll zero,zero,0x0' and len(b) > len(a):
            b.pop()
        diff = sum(1 for x, y in zip(a, b) if x != y) + abs(len(a) - len(b))
        if n not in best or diff < best[n][0]:
            best[n] = (diff, setup, a, b)
tag = lambda s: f"gcc{s[0]}{' uchar' if s[1] else ''}{' fill' if s[2] else ''}"
for n in names or []:
    diff, setup, a, b = best[n]
    print(f"{n}: {'OK' if diff == 0 else 'DIFF %d' % diff} (best: {tag(setup)})")
    if show and diff:
        for i in range(max(len(a), len(b))):
            x = a[i] if i < len(a) else ''
            y = b[i] if i < len(b) else ''
            print(f"  {'*' if x != y else ' '} {x:40} | {y}")
# which setups give a match for every OK function
print('per setup:')
for setup in SETUPS:
    ours, err = build(setup)
    if ours is None:
        continue
    ok = []
    for n in names:
        a = [norm(i) for i in ours.get(n, [])]
        b = [norm(i) for i in reff[n]]
        while b and b[-1] == 'sll zero,zero,0x0' and len(b) > len(a):
            b.pop()
        if a == b:
            ok.append(n)
    print(f"  {tag(setup):22} {len(ok)}/{len(names)} {' '.join(ok)}")
