#!/bin/bash
# fullbuild.sh CANDS.c -- substitute every block, run the full `make` (EXE + overlays); keep on match, revert otherwise.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1")
cd "$ROOT" || exit 1
backup_src
"$PY" "$M/subst.py" "$C" "$ROOT" >/dev/null
if make -s > /tmp/fullbuild.log 2>&1; then
  echo "FULLBUILD MATCH"; rm -rf "$_SRC_BAK"
else
  grep -vE '^mips|^python|^\.venv|warning' /tmp/fullbuild.log | tail -5
  echo "FULLBUILD FAIL - reverting"; restore_src
fi
