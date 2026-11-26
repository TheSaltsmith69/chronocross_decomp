#!/bin/bash
# tryd.sh CANDS.c [SKIP] [N] -- trycc --show, differing lines only; skip the first SKIP lines, show N
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1")
"$PY" "$M/trycc.py" "$C" --show 2>&1 | grep -v '^  ' | tail -n +$((${2:-0}+1)) | head -${3:-150}
