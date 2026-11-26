#!/bin/bash
# next.sh [N] [SHOW...] -- list the next N overlay candidates (skipping parked_$OV.txt and skip_$OV.txt),
# then print the asm of the SHOW functions. `next.sh 16 all` shows all N.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
cd "$ROOT" && git log --oneline -1
L=$(bash "$M/ovnext.sh" ${1:-10} $(cat "$M/parked_$OV.txt" "$M/skip_$OV.txt" 2>/dev/null) | cut -d' ' -f2)
echo $L
shift
[ "$1" = all ] && set -- $L
[ $# -gt 0 ] && bash "$M/showmany.sh" "$@"
