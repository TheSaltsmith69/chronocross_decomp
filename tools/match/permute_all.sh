#!/bin/bash
# permute_all.sh QUEUE [MINUTES] [JOBS] [all] [fresh] [draft] [stall=M] -- run decomp-permuter on each
# queued function in turn, unattended. QUEUE has one job per line: "CANDS.c FUNC [IDX]" (a
# candidate file and the variant to start from; # starts a comment). Each function gets MINUTES
# (default 30) on JOBS threads (default 16). An existing permuter/nonmatchings/FUNC is reused, so
# a rerun continues from the same base. Improvements land in
# permuter/nonmatchings/FUNC/output-SCORE-N/source.c (score 0 = full match);
# permuter/summary.txt gets the best score per visit.
#
# Stall timer: when a function goes M minutes (default 5, stall=M to change, stall=0 to turn it
# off) without beating its best score so far (counting earlier runs), it is stopped and moved to
# the back of the line with the rest of its MINUTES, and the next function starts. A function
# leaves the line when its MINUTES are used up or it matches; the run ends when the line is empty.
#
# Progress goes to the console through permwatch.py: the base score, every improvement, and a
# status line updated on each compile (compile count, latest and best score, time left).
# Pass "all" for one console line per compile. The raw permuter output still goes to
# permuter/FUNC.log.
#
# Starting point: each visit starts from the function's best output so far (copied over base.c;
# the original draft stays in base.orig.c). Pass "draft" to start from the original draft again.
#
# Randomization weights: tools/match/permuter_weights.toml is copied into each function's
# settings.toml before every visit (it turns off the changes that make wrong C).
# PERM_EXTRA (env): more decomp-permuter options, e.g. "--keep-prob=0.8 --speed=50 --stack-diffs"
# (the control panel sets it from the chosen tuning profile).
#
# Resume: permuter/resume.txt remembers where the first pass through the queue is. A run that was
# stopped (window closed, Ctrl+C) starts again on the function it was working on; a function
# whose visit ended normally (time used, stalled or matched) is recorded as done, so the next run
# starts after it. Functions before that point in the queue are skipped. When the whole queue
# has been through once, the next run starts from the top. "fresh" ignores resume.txt.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
Q=$(abspath "$1"); MIN=${2:-30}; J=${3:-16}
EVERY=; FRESH=; FROM_DRAFT=; STALL_MIN=5
for a in "${@:4}"; do
  case "$a" in
    all) EVERY=--every-compile ;;
    fresh) FRESH=1 ;;
    stall=*) STALL_MIN=${a#stall=} ;;
    draft) FROM_DRAFT=1 ;;
    '') ;;
    *) echo "permute_all.sh: unknown option '$a' (expected all, fresh, draft or stall=MINUTES)" >&2; exit 2 ;;
  esac
done
cd "$ROOT"
mkdir -p permuter
STATE=${PERM_STATE:-permuter/resume.txt}   # control_gui.py uses its own for picked selections
JOBS=$(grep -v '^\s*\(#\|$\)' "$Q" | tr -d '\r')
STALL=$(awk -v m="$STALL_MIN" 'BEGIN {printf "%d", m * 60}')

# resume.txt holds "running FUNC" (stopped while FUNC ran: start on it) or "done FUNC" (FUNC's
# visit ended normally: start on the next one).
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

# the line: "cands func idx" entries; budget left per function in seconds
LINE=(); declare -A LEFT
while read -r cands func idx _; do
  [ -n "$func" ] || continue
  if [ -n "$SKIP_TO" ]; then
    [ "$func" = "$SKIP_TO" ] || continue
    SKIP_TO=
  elif [ -n "$SKIP_PAST" ]; then
    [ "$func" = "$SKIP_PAST" ] && SKIP_PAST=
    continue
  fi
  [ -n "${LEFT[$func]}" ] && continue
  LINE+=("$cands $func ${idx:-0}")
  LEFT[$func]=$(awk -v m="$MIN" 'BEGIN {printf "%d", m * 60}')
done <<< "$JOBS"
if [ -n "$SKIP_TO$SKIP_PAST" ]; then
  echo "resume: did not find the saved function in the queue; nothing to run (pass 'fresh')"
  exit 0
fi
FIRST_PASS=${#LINE[@]}     # entries still on their first visit (they keep resume.txt up to date)
FIRST_PASS_TOTAL=$FIRST_PASS

# best_score DIR: lowest output-SCORE-N score so far, empty if none
best_score() { ls -d "$1"/output-* 2>/dev/null | sed 's/.*output-\([0-9]*\)-.*/\1/' | sort -n | head -1; }
# best_output DIR: the folder holding that score (oldest N on a tie)
best_output() {
  ls -d "$1"/output-* 2>/dev/null | sed 's/.*output-\([0-9]*\)-\([0-9]*\)$/\1 \2 &/' | sort -n -k1,1 -k2,2 \
    | head -1 | cut -d' ' -f3-
}

# start_from_best DIR FUNC: make DIR/base.c the best output so far, so a visit carries on from
# where the last one got to instead of from the original draft. The first time, the original
# is kept as base.orig.c and its score as base.score (for the panel's base -> best); base.from
# holds the score base.c now has.
start_from_best() {
  local dir=$1 func=$2 best out cur orig
  best=$(best_score "$dir"); [ -n "$best" ] || return 0
  cur=$(cat "$dir/base.from" 2> /dev/null)
  [ -z "$cur" ] || [ "$best" -lt "$cur" ] || return 0
  out=$(best_output "$dir"); [ -f "$out/source.c" ] || return 0
  if [ ! -f "$dir/base.orig.c" ]; then
    cp "$dir/base.c" "$dir/base.orig.c"
    orig=$(tr '\r' '\n' < "permuter/$func.log" 2> /dev/null | grep -o 'base score = [0-9]*' | head -1 | grep -o '[0-9]*$')
    [ -n "$orig" ] && [ ! -f "$dir/base.score" ] && echo "$orig" > "$dir/base.score"
  fi
  cp "$out/source.c" "$dir/base.c"
  echo "$best" > "$dir/base.from"
  echo "$func: starting from its best so far, $(basename "$out") (original draft kept as base.orig.c)"
}

# apply_weights DIR: replace the [weight_overrides] section of DIR/settings.toml
apply_weights() {
  local w=tools/match/permuter_weights.toml s="$1/settings.toml"
  [ -f "$w" ] && [ -f "$s" ] || return 0
  { sed '/^\[weight_overrides\]/,$d' "$s"; echo "[weight_overrides]"; grep -v '^\s*\[' "$w"; } > "$s.new" \
    && mv "$s.new" "$s"
}

# active_now: epoch seconds minus the time this run spent paused from the control panel
# (PAUSE_LEDGER, see pauseclock.py), so budgets and the stall timer skip paused time
active_now() {
  if [ -n "$PAUSE_LEDGER" ] && [ -f "$PAUSE_LEDGER" ]; then
    awk -v now="$(date +%s)" '{t = $1; if ($2 > 0) t += now - $2; printf "%d\n", now - t; exit}' "$PAUSE_LEDGER"
  else
    date +%s
  fi
}

# watch_stall DIR PRIOR: background watcher; stops the permuter on DIR after STALL seconds
# without a score below PRIOR (the best before this visit; empty = no output yet)
watch_stall() {
  local dir=$1 prior=$2 last cur pat
  last=$(active_now)
  pat="decomp-permuter/permuter.py $dir "
  while sleep 10; do
    cur=$(best_score "$dir")
    if [ -n "$cur" ] && { [ -z "$prior" ] || [ "$cur" -lt "$prior" ]; }; then
      prior=$cur; last=$(active_now)
    fi
    if [ $(( $(active_now) - last )) -ge "$STALL" ]; then
      touch "$dir/.stalled"
      pkill -INT -f "$pat"
      # the permuter can hang on exit after SIGINT (see below): TERM after 30 s, KILL after 40 s
      for k in 1 2 3 4; do
        sleep 10; pgrep -f "$pat" > /dev/null || return 0
        [ "$k" = 3 ] && pkill -TERM -f "$pat"
      done
      pkill -KILL -f "$pat"
      return 0
    fi
  done
}

while [ ${#LINE[@]} -gt 0 ]; do
  read -r cands func idx <<< "${LINE[0]}"
  LINE=("${LINE[@]:1}")
  first=; [ "$FIRST_PASS" -gt 0 ] && { first=1; FIRST_PASS=$((FIRST_PASS - 1)); }
  [ -n "$first" ] && echo "running $func" > "$STATE"
  dir=permuter/nonmatchings/$func
  if [ ! -d "$dir" ]; then
    "$PY" tools/match/permute.py "$cands" "$func" "$idx" > "permuter/$func.import.log" 2>&1 \
      || { echo "$func: import failed (permuter/$func.import.log)" | tee -a permuter/summary.txt
           [ -n "$first" ] && echo "done $func" > "$STATE"; continue; }
  fi
  apply_weights "$dir"
  if [ -z "$FROM_DRAFT" ]; then
    start_from_best "$dir" "$func"
  elif [ -f "$dir/base.orig.c" ]; then
    cp "$dir/base.orig.c" "$dir/base.c"; rm -f "$dir/base.from"
    echo "$func: starting from the original draft (draft option)"
  fi
  rem=${LEFT[$func]}
  rem_min=$(awk -v s="$rem" 'BEGIN {printf "%.4g", s / 60}')
  prior=$(best_score "$dir")
  rm -f "$dir/.stalled"
  echo
  echo "$(date +%H:%M) $func: permuting for ${rem_min}m on $J threads (best so far ${prior:-none})"
  watcher=
  if [ "$STALL" -gt 0 ]; then
    watch_stall "$dir" "$prior" &
    watcher=$!
  fi
  # SIGINT lets the permuter stop cleanly, but it can then hang on exit (a queue thread blocks
  # writing to workers that are gone), so it is killed if still running 30 s later.
  # ptimeout.py = timeout --signal=INT --kill-after=30s, minus paused time.
  usedf=permuter/.used.$$
  rm -f "$usedf"
  start=$(active_now)
  PYTHONUNBUFFERED=1 "$PY" tools/match/ptimeout.py "$rem" --used-file "$usedf" -- \
    "$PY" tools/decomp-permuter/permuter.py "$dir" \
    -j"$J" --best-only --stop-on-zero $PERM_EXTRA < /dev/null 2>&1 \
    | "$PY" tools/match/permwatch.py "$func" "$rem_min" "permuter/$func.log" $EVERY || true
  [ -n "$watcher" ] && { kill "$watcher" 2> /dev/null; wait "$watcher" 2> /dev/null; }
  used=$(cat "$usedf" 2> /dev/null || echo $(( $(active_now) - start )))
  rm -f "$usedf"
  LEFT[$func]=$(( rem - used ))
  best=$(best_score "$dir")
  base=$(cat "$dir/base.score" 2> /dev/null)      # the original draft's score, if base.c moved on
  [ -n "$base" ] || base=$(tr '\r' '\n' < "permuter/$func.log" | grep -o 'base score = [0-9]*' | head -1 | grep -o '[0-9]*$')
  echo "$func: base ${base:-?} best ${best:-none}" | tee -a permuter/summary.txt
  stalled=; [ -f "$dir/.stalled" ] && stalled=1
  rm -f "$dir/.stalled"
  if [ "$best" = 0 ]; then
    ended=1
  elif [ -n "$stalled" ]; then
    ended=1
    if [ "${LEFT[$func]}" -ge 60 ]; then
      LINE+=("$cands $func $idx")
      echo "$func: no improvement for ${STALL_MIN}m, moved to the back of the line ($(( LEFT[$func] / 60 ))m left)"
    else
      echo "$func: no improvement for ${STALL_MIN}m and under a minute left, done"
    fi
  elif [ "$used" -ge $(( rem - 5 )) ]; then
    ended=1
  else
    ended=      # stopped early (Ctrl+C): leave "running FUNC" for the next run
  fi
  [ -n "$first" ] && [ -n "$ended" ] && echo "done $func" > "$STATE"
done

# the queue has been through once: the next run starts from the top
[ "$FIRST_PASS_TOTAL" -gt 0 ] && rm -f "$STATE"
