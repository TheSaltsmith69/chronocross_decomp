#!/bin/bash
# libnext.sh [N] [LIBREGEX] -- asm of the N smallest INCLUDE_ASM lib functions, skipping libskip.txt and
# libapi/libsn/libgte/libmath/2mbyte (BIOS stubs, hand asm)
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
cd "$ROOT" || exit 1
N=${1:-10}; RE=${2:-.}
SKIP=" $(tr '\n' ' ' < "$M/libskip.txt") "
grep -rhoE 'INCLUDE_ASM\("asm/nonmatchings/lib/[^"]+", *[A-Za-z_0-9]+\)' src/lib | sed -E 's/INCLUDE_ASM\("([^"]+)", *([A-Za-z_0-9]+)\)/\1 \2/' | grep -E "$RE" | grep -vE 'libapi|libsn|libgte|libmath|2mbyte' | while read d f; do
  case "$SKIP" in *" $f "*) continue ;; esac
  echo "$(grep -cE '^\s+/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/' $d/$f.s) $d $f"
done | sort -n | head -$N > /tmp/libnext.txt
cat /tmp/libnext.txt
while read n d f; do
  echo "=== $f ($d, $n)"
  grep -vE '^\s*$|^/\*|\.size|\.align|^\.section|^\.include|\.set|nonmatching|glabel|endlabel' $d/$f.s | sed -E 's|/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/||'
done < /tmp/libnext.txt
