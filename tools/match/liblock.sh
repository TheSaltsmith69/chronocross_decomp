#!/bin/bash
# liblock.sh CANDS.c -- trycc --keep for lib functions, then the full build; revert src/lib on any mismatch.
# Remove blocks for functions that are already C first: trycc stops when a block has no INCLUDE_ASM.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1")
cd "$ROOT" || exit 1
"$PY" "$M/trycc.py" "$C" 2.8.1 --keep 2>&1 | grep -E '^gcc|OK:|DIFF:'
if make -s -j8 > /tmp/liblock.log 2>&1; then
  echo "FULL BUILD MATCH"
else
  grep -E 'MISMATCH|rror' /tmp/liblock.log | grep -v warning
  echo "FULL BUILD MISMATCH - reverting"; git checkout src/lib
fi
git diff --stat | tail -1
