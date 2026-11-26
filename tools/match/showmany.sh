#!/bin/bash
# showmany.sh FUNC... -- print each function's original asm, address columns stripped
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
cd "$ROOT" || exit 1
for f in "$@"; do
  a=$(find asm -path '*nonmatchings*' -name "$f.s" | head -1)
  echo "=== $f"
  grep -vE '^\s*$|glabel|endlabel|nonmatching' "$a" | sed 's/^ *\/\* [0-9A-F]* [0-9A-F]* [0-9A-F]* \*\/ *//'
done
