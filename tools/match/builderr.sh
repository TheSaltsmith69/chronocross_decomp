#!/bin/bash
# builderr.sh CANDS.c -- substitute blocks, make, print the real (non-warning) compile errors, revert
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1")
cd "$ROOT" || exit 1
backup_src
"$PY" "$M/subst.py" "$C" "$ROOT" >/dev/null
make 2>&1 | grep -viE 'warning|previous implicit|In function|At top level|Assembler messages|^mips|^\.venv|^tools/|^[0-9a-f]{40} |^OK:' | head -20
restore_src
