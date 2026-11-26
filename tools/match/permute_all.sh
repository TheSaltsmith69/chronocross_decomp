#!/bin/bash
# permute_all.sh QUEUE [MINUTES] [JOBS] [all] [fresh] -- run decomp-permuter on each queued function
# in turn, unattended. QUEUE has one job per line: "CANDS.c FUNC [IDX]" (a candidate file and the
# variant to start from; # starts a comment). Each function gets MINUTES (default 30) on JOBS
# threads (default 16). An existing permuter/nonmatchings/FUNC is reused, so a rerun continues
# from the same base. Improvements land in permuter/nonmatchings/FUNC/output-SCORE-N/source.c
# (score 0 = full match); permuter/summary.txt gets the best score per function.
# Progress goes to the console through permwatch.py: the base score, every improvement, and a
# status line updated on each compile (compile count, latest and best score, time left).
# Pass "all" for one console line per compile. The raw permuter output still goes to
# permuter/FUNC.log.
#
# Resume: permuter/resume.txt remembers where the run is. A run that was stopped (window closed,
# Ctrl+C) starts again on the function it was working on, with its full MINUTES; a function whose
# time ran out is recorded as done, so the next run starts after it. Functions before that point
# in the queue are skipped. When the whole queue finishes, resume.txt is removed and the next run
# starts from the top. Pass "fresh" to ignore resume.txt and start from the top anyway.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
Q=$(abspath "$1"); MIN=${2:-30}; J=${3:-16}
EVERY=; FRESH=
for a in "${@:4}"; do
  case "$a" in
    all) EVERY=--every-compile ;;
    fresh) FRESH=1 ;;
    '') ;;
    *) echo "permute_all.sh: unknown option '$a' (expected all or fresh)" >&2; exit 2 ;;
  esac
done
cd "$ROOT"
mkdir -p permuter
STATE=permuter/resume.txt
JOBS=$(grep -v '^\s*\(#\|$\)' "$Q" | tr -d '\r')

# resume.txt holds "running FUNC" (stopped while FUNC ran: start on it) or "done FUNC" (FUNC used
# its full time: start on the next one).
SKIP_TO=; SKIP_PAST=
if [ -z "$FRESH" ] && [ -s "$STATE" ]; then
  read -r st sfunc _ < "$STATE"
  if ! awk -v f="$sfunc" '$2 == f {found=1} END {exit !found}' <<< "$JOBS"; then
    echo "resume: $sfunc is no longer in the queue, starting from the top"
  elif [ "$st" = done ] && [ "$(tail -n 1 <<< "$JOBS" | awk '{print $2}')" = "$sfunc" ]; then
    echo "resume: $sfunc was the last function and it finished, starting from the top"
  elif [ "$st" = done ]; then
    SKIP_PAST=$sfunc
    echo "resume: $sfunc finished last time, continuing after it (pass 'fresh' to start from the top)"
  else
    SKIP_TO=$sfunc
    echo "resume: stopped during $sfunc last time, starting there (pass 'fresh' to start from the top)"
  fi
fi

while read -r cands func idx _; do
  if [ -n "$SKIP_TO" ]; then
    [ "$func" = "$SKIP_TO" ] || continue
    SKIP_TO=
  elif [ -n "$SKIP_PAST" ]; then
    [ "$func" = "$SKIP_PAST" ] && SKIP_PAST=
    continue
  fi
  echo "running $func" > "$STATE"
  dir=permuter/nonmatchings/$func
  if [ ! -d "$dir" ]; then
    "$PY" tools/match/permute.py "$cands" "$func" ${idx:-0} > "permuter/$func.import.log" 2>&1 \
      || { echo "$func: import failed (permuter/$func.import.log)" | tee -a permuter/summary.txt
           echo "done $func" > "$STATE"; continue; }
  fi
  echo
  echo "$(date +%H:%M) $func: permuting for ${MIN}m on $J threads"
  # SIGINT lets the permuter stop cleanly, but it can then hang on exit (a queue thread blocks
  # writing to workers that are gone), so it is killed if still running 30 s later.
  start=$(date +%s)
  PYTHONUNBUFFERED=1 timeout --signal=INT --kill-after=30s "${MIN}m" \
    "$PY" tools/decomp-permuter/permuter.py "$dir" \
    -j"$J" --best-only < /dev/null 2>&1 \
    | "$PY" tools/match/permwatch.py "$func" "$MIN" "permuter/$func.log" $EVERY || true
  best=$(ls -d "$dir"/output-* 2>/dev/null | sed 's/.*output-\([0-9]*\)-.*/\1/' | sort -n | head -1)
  base=$(tr '\r' '\n' < "permuter/$func.log" | grep -o 'base score = [0-9]*' | head -1 | grep -o '[0-9]*$')
  echo "$func: base ${base:-?} best ${best:-none}" | tee -a permuter/summary.txt
  # Only a function that used (nearly) its whole time, or reached a full match, counts as done;
  # an early exit from Ctrl+C leaves "running FUNC" so the next run picks it up again.
  if [ "$best" = 0 ] || awk -v e=$(( $(date +%s) - start )) -v m="$MIN" 'BEGIN {exit !(e >= m * 60 - 5)}'; then
    echo "done $func" > "$STATE"
  fi
done <<< "$JOBS"

if [ -n "$SKIP_TO$SKIP_PAST" ]; then
  echo "resume: did not find the saved function in the queue; nothing was run (pass 'fresh')"
else
  rm -f "$STATE"
fi
