#!/bin/bash
# showf.sh CANDS.c FUNC... -- full trycc diff for the chosen functions only
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1"); shift
out=$("$PY" "$M/trycc.py" "$C" --show 2>&1)
for n in "$@"; do
  echo "$out" | awk -v n="$n" '/^--- /{p = index($0, n) > 0} /^gcc /{p=0} p'
done
