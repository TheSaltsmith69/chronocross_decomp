#!/bin/bash
# fcount.sh CANDS.c [CANDS2.c ...] -- for each: substitute, full build, count bytes differing in the overlay ($OV), revert
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
files=(); for f in "$@"; do files+=("$(abspath "$f")"); done
cd "$ROOT" || exit 1
for f in "${files[@]}"; do
  backup_src
  "$PY" "$M/subst.py" "$f" "$ROOT" >/dev/null
  if build_ov; then
    echo "$(basename "$f"): $(cmp -l "$OV_BIN" "$OV_ISO" | wc -l) bytes differ ($OV)"
  else
    echo "$(basename "$f"): BUILD ERROR (builderr.sh shows why)"
  fi
  restore_src
done
make >/dev/null 2>&1
