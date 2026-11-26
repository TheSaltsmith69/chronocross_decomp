#!/bin/bash
# permute_all.sh QUEUE [MINUTES] [JOBS] -- run decomp-permuter on each queued function in turn,
# unattended. QUEUE has one job per line: "CANDS.c FUNC [IDX]" (a candidate file and the
# variant to start from; # starts a comment). Each function gets MINUTES (default 30) on JOBS
# threads (default 16). An existing permuter/nonmatchings/FUNC is reused, so a rerun continues
# from the same base. Improvements land in permuter/nonmatchings/FUNC/output-SCORE-N/source.c
# (score 0 = full match); permuter/summary.txt gets the best score per function.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
Q=$(abspath "$1"); MIN=${2:-30}; J=${3:-16}
cd "$ROOT"
mkdir -p permuter
grep -v '^\s*\(#\|$\)' "$Q" | while read -r cands func idx; do
  dir=permuter/nonmatchings/$func
  if [ ! -d "$dir" ]; then
    "$PY" tools/match/permute.py "$cands" "$func" ${idx:-0} > "permuter/$func.import.log" 2>&1 \
      || { echo "$func: import failed (permuter/$func.import.log)" | tee -a permuter/summary.txt; continue; }
  fi
  echo "$(date +%H:%M) $func: permuting for ${MIN}m"
  timeout --signal=INT "${MIN}m" "$PY" tools/decomp-permuter/permuter.py "$dir" -j"$J" --best-only \
    < /dev/null > "permuter/$func.log" 2>&1 || true
  best=$(ls -d "$dir"/output-* 2>/dev/null | sed 's/.*output-\([0-9]*\)-.*/\1/' | sort -n | head -1)
  base=$(tr '\r' '\n' < "permuter/$func.log" | grep -o 'base score = [0-9]*' | head -1 | grep -o '[0-9]*$')
  echo "$func: base ${base:-?} best ${best:-none}" | tee -a permuter/summary.txt
done
