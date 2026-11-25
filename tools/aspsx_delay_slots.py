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
For `la` and stores to a symbol, only the final instruction moves into the
slot. A `move` that the branch reads is propagated into the branch.
Reads stdin, writes stdout.
"""
import re
import sys

JUMP = re.compile(r'^\t(j|jal|jr|beq|bne|beqz|bnez|bgez|bltz|blez|bgtz)\t(\S+)$')
INSN = re.compile(r'^\t([a-z][a-z0-9.]*)\t?(.*)$')
LOADS = {'lw', 'lh', 'lhu', 'lb', 'lbu', 'lwl', 'lwr', 'lwc2', 'ulw', 'ulh', 'ulhu'}
NO_MOVE = LOADS | {'j', 'jal', 'jr', 'jalr', 'b', 'beq', 'bne', 'beqz', 'bnez', 'blez',
                   'bgtz', 'bltz', 'bgez', 'bal', 'div', 'divu', 'mult', 'multu',
                   'mflo', 'mfhi', 'mtlo', 'mthi', 'mfc0', 'mtc0', 'mfc2', 'mtc2',
                   'cfc2', 'ctc2', 'syscall', 'break', 'nop', 'rem', 'remu'}
REG = re.compile(r'\$(\d+|sp|fp|ra)')
# `sw $4,sym` / `sb $4,sym($2)` / `sw $4,sym+8`: stores the assembler expands
SYM_STORE = re.compile(r'^\t(sw|sh|sb)\t(\$\d+),([A-Za-z_.][\w.]*(?:[+-]\d+)?)(?:\((\$\d+)\))?\s*(?:#.*)?$')


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


# `lbu $3,sym($2)`: ASPSX builds the address in the destination register
# (lui $3 / addu $3,$3,$2 / lbu $3,%lo(sym)($3)); maspsx would use $at.
SYM_LOAD = re.compile(r'^\t(lw|lh|lhu|lb|lbu)\t(\$\d+),([A-Za-z_.][\w.]*(?:[+-]\d+)?)\((\$\d+)\)\s*(?:#.*)?$')


def expand_sym_loads(lines):
    res = []
    for line in lines:
        m = SYM_LOAD.match(line)
        if m and m.group(2) != m.group(4) and m.group(2) != '$0':
            op, rd, sym, rb = m.groups()
            res += ['\tlui\t%s,%%hi(%s)' % (rd, sym),
                    '\taddu\t%s,%s,%s' % (rd, rd, rb),
                    '\t%s\t%s,%%lo(%s)(%s)' % (op, rd, sym, rd)]
        else:
            res.append(line)
    return res


# This gcc 2.7.2 build reserves stack space it never uses in some leaf
# functions with loops (`.frame $sp,16 # vars= 16, regs= 0/0`); the
# original compiler did not. Drop such a frame when nothing else in the
# function touches $sp.
FRAME = re.compile(r'^\t\.frame\t\$sp,(\d+),\$31\t\t# vars= (\d+), regs= 0/0, args= 0, extra= 0$')


def drop_unused_frames(lines):
    res = []
    i = 0
    while i < len(lines):
        if lines[i].startswith('\t.ent\t'):
            j = i
            while j < len(lines) and not lines[j].startswith('\t.end\t'):
                j += 1
            body = lines[i:j + 1]
            fr = [k for k, l in enumerate(body) if FRAME.match(l)]
            if fr:
                n = FRAME.match(body[fr[0]]).group(1)
                adj = {'\tsubu\t$sp,$sp,%s' % n, '\taddu\t$sp,$sp,%s' % n}
                others = [l for l in body if '$sp' in l and l not in adj and not l.startswith('\t.frame')]
                if n != '0' and not others:
                    body = [l for l in body if l not in adj]
                    body = [re.sub(r'^\t\.frame\t\$sp,\d+,\$31\t\t# vars= \d+',
                                   '\t.frame\t$sp,0,$31\t\t# vars= 0', l) for l in body]
            res += body
            i = j + 1
        else:
            res.append(lines[i])
            i += 1
    return res


lines = expand_sym_loads(drop_unused_frames(sys.stdin.read().split('\n')))
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
                # ASPSX propagates a copy into the branch: `move $2,$4; bgez $2,L`
                # becomes `bgez $4,L` with the move in the delay slot
                src = regs(args)[1:] if op == 'move' else []
                if src and src[0] != d:
                    line = re.sub(r'\$%s\b' % d, '$' + src[0], line)
                else:
                    ok = False
            elif jop == 'jal' and '31' in regs(args):
                ok = False
            else:
                # the instruction that would end up next to the jump
                w = k - 1
                while w >= 0 and (out[w].strip() == '' or out[w].lstrip().startswith('#') or
                                  out[w].lstrip().startswith('.')):
                    w -= 1  # comments and directives (incl. the end of a noreorder block)
                wp = parse(out[w]) if w >= 0 else None
                if wp is None and w >= 0 and not out[w].strip().endswith(':'):
                    ok = False  # a directive: leave things alone
                elif wp and wp[0] in LOADS and dest_reg(*wp) in jreads:
                    ok = False
        if ok:
            op, args = prev
            moved = out[k]
            sm = SYM_STORE.match(out[k])
            if op == 'la':
                r, sym = [a.strip() for a in args.split(',', 1)]
                out[k] = '\tlui\t%s,%%hi(%s)' % (r, sym)
                moved = '\taddiu\t%s,%s,%%lo(%s)' % (r, r, sym)
            elif sm:
                # a store to a symbol is a macro (lui $at [+ addu $at,base]);
                # only the final store goes into the slot
                sop, r, sym, base = sm.groups()
                pre = ['\tlui\t$1,%%hi(%s)' % sym]
                if base:
                    pre.append('\taddu\t$1,$1,%s' % base)
                out[k:k + 1] = pre
                moved = '\t%s\t%s,%%lo(%s)($1)' % (sop, r, sym)
                out += ['\t.set\tnoreorder', '\t.set\tnomacro', line, moved,
                        '\t.set\tmacro', '\t.set\treorder']
                continue
            else:
                del out[k]
            out += ['\t.set\tnoreorder', '\t.set\tnomacro', line, moved,
                    '\t.set\tmacro', '\t.set\treorder']
            continue
    out.append(line)


def reads(op, args):
    r = regs(args)
    d = dest_reg(op, args)
    if d is not None and r and r[0] == d:
        r = r[1:]
    return r


# Load delay across a label: for `lw $3,x` / `$L:` / `lhu $2,4($3)` ASPSX
# puts the nop before the label, maspsx after it (inside a loop, that
# moves the branch target). Write the nop out explicitly.
final = []
reorder = True
for i, line in enumerate(out):
    final.append(line)
    s = line.strip()
    if s in ('.set\tnoreorder', '.set noreorder'):
        reorder = False
    elif s in ('.set\treorder', '.set reorder'):
        reorder = True
    p = parse(line) if reorder else None
    if not p or p[0] not in LOADS:
        continue
    d = dest_reg(*p)
    j = i + 1
    saw_label = False
    while j < len(out) and (out[j].strip() == '' or out[j].lstrip().startswith('#')
                            or out[j].strip().endswith(':')):
        saw_label = saw_label or out[j].strip().endswith(':')
        j += 1
    if saw_label and j < len(out):
        q = parse(out[j])
        if q and d in reads(*q):
            final.append('\tnop')
sys.stdout.write('\n'.join(final))
