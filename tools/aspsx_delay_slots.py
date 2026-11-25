#!/usr/bin/env python3
"""Fill branch delay slots the way Sony's ASPSX does for gcc 2.7.2 output.

gcc 2.7.2 leaves some jumps to the assembler in reorder mode, e.g.

        sw      $2,0($3)                lw      $31,20($sp)
        jal     func                    lw      $16,16($sp)
                                        addu    $sp,$sp,24
                                        j       $31

ASPSX moves the instruction just before such a jump into its delay slot.
maspsx always pads the slot with a nop instead, so this filter does the
move first, writing the pair as an explicit noreorder block. The
instruction is left where it is when:
  - it is a load, a branch, or a multi-instruction macro (other than `la`);
  - the jump reads the register it writes;
  - the jump is a jal and the instruction uses $31;
  - moving it would leave a load right before a jump that reads the loaded
    register (e.g. `lw $31` followed by `j $31`).
For `la`, only its final addiu moves into the slot.
Reads stdin, writes stdout.
"""
import re
import sys

JUMP = re.compile(r'^\t(j|jal|jr)\t(\S+)$')
INSN = re.compile(r'^\t([a-z][a-z0-9.]*)\t?(.*)$')
LOADS = {'lw', 'lh', 'lhu', 'lb', 'lbu', 'lwl', 'lwr', 'lwc2', 'ulw', 'ulh', 'ulhu'}
NO_MOVE = LOADS | {'j', 'jal', 'jr', 'jalr', 'b', 'beq', 'bne', 'beqz', 'bnez', 'blez',
                   'bgtz', 'bltz', 'bgez', 'bal', 'div', 'divu', 'mult', 'multu',
                   'mflo', 'mfhi', 'mtlo', 'mthi', 'mfc0', 'mtc0', 'mfc2', 'mtc2',
                   'cfc2', 'ctc2', 'syscall', 'break', 'nop', 'rem', 'remu'}
REG = re.compile(r'\$(\d+|sp|fp|ra)')


def regs(text):
    out = []
    for r in REG.findall(text):
        out.append({'sp': '29', 'fp': '30', 'ra': '31'}.get(r, r))
    return out


def parse(line):
    m = INSN.match(line)
    if not m:
        return None
    op, args = m.group(1), m.group(2).split('#')[0].strip()
    return op, args


def dest_reg(op, args):
    if op in ('sw', 'sh', 'sb', 'swl', 'swr', 'swc2', 'usw', 'ush'):
        return None
    r = regs(args.split(',')[0])
    return r[0] if r else None


def simple_li(args):
    v = args.split(',')[1].strip()
    try:
        n = int(v, 0)
    except ValueError:
        return False
    return -0x8000 <= n <= 0xFFFF or (n & 0xFFFF) == 0


lines = sys.stdin.read().split('\n')
out = []
reorder = True
for line in lines:
    s = line.strip()
    if s == '.set\tnoreorder' or s == '.set noreorder':
        reorder = False
    elif s == '.set\treorder' or s == '.set reorder':
        reorder = True
    jm = JUMP.match(line) if reorder else None
    if jm:
        # the previous real instruction, with nothing but comments in between
        k = len(out) - 1
        while k >= 0 and (out[k].strip() == '' or out[k].lstrip().startswith('#')):
            k -= 1
        prev = parse(out[k]) if k >= 0 else None
        ok = prev is not None and not out[k].strip().endswith(':')
        if ok:
            op, args = prev
            jop, jarg = jm.group(1), jm.group(2)
            jreads = regs(jarg)  # `j $31` / `jr $31`; labels have no registers
            d = dest_reg(op, args)
            if op in NO_MOVE or op.startswith('.'):
                ok = False
            elif op == 'li' and not simple_li(args):
                ok = False
            elif d is not None and d in jreads:
                ok = False
            elif jop == 'jal' and '31' in regs(args):
                ok = False
            else:
                # the instruction that would end up next to the jump
                w = k - 1
                while w >= 0 and (out[w].strip() == '' or out[w].lstrip().startswith('#')):
                    w -= 1
                wp = parse(out[w]) if w >= 0 else None
                if wp is None and w >= 0 and not out[w].strip().endswith(':'):
                    ok = False  # a directive: leave things alone
                elif wp and wp[0] in LOADS and dest_reg(*wp) in jreads:
                    ok = False
        if ok:
            op, args = prev
            moved = out[k]
            if op == 'la':
                r, sym = [a.strip() for a in args.split(',', 1)]
                out[k] = '\tlui\t%s,%%hi(%s)' % (r, sym)
                moved = '\taddiu\t%s,%s,%%lo(%s)' % (r, r, sym)
            else:
                del out[k]
            out += ['\t.set\tnoreorder', '\t.set\tnomacro', line, moved,
                    '\t.set\tmacro', '\t.set\treorder']
            continue
    out.append(line)
sys.stdout.write('\n'.join(out))
