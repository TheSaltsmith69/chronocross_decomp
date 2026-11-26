#!/bin/bash
# cmpat.sh CANDS.c ADDRHEX -- substitute, build, list differing overlay bytes, disassemble ours and the original around ADDR, revert.
# Don't pipe this into head: an early exit skips the revert (then: git checkout src).
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1"); A=$((0x$2))
cd "$ROOT" || exit 1
backup_src
"$PY" "$M/subst.py" "$C" "$ROOT" >/dev/null
if ! build_ov; then echo "BUILD ERROR (builderr.sh shows why)"; restore_src; make >/dev/null 2>&1; exit 1; fi
cmp -l "$OV_BIN" "$OV_ISO" | awk -v b=$((OV_VRAM)) '{printf "%X %o %o\n", $1-1+b, $2, $3}' | head -40
mips-linux-gnu-objdump -d "$OV_ELF" --start-address=$((A-24)) --stop-address=$((A+24)) | tail -12
echo ORIG
grep -rn -B6 -A6 "$(printf '%X' $A)" "asm/$OV/nonmatchings" | head -20
restore_src
