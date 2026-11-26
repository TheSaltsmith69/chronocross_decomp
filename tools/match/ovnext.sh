#!/bin/bash
# ovnext.sh [N] [SKIP...] -- next N smallest overlay ($OV) functions, minus the given names.
# For ov_field, libpress (func_800A3*/800A4*) is skipped: it is a different compiler.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
N=${1:-20}; if (( $# )); then shift; fi
skip=" $* "
bash "$M/small.sh" 100000 | grep " asm/$OV/" | { if [ "$OV" = ov_field ]; then grep -v 'func_800A[34]'; else cat; fi; } | while read n d f; do
  case "$skip" in *" $f "*) ;; *) echo "$n $f" ;; esac
done | head -$N
