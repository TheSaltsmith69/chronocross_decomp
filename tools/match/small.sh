#!/bin/bash
# small.sh [N] -- smallest functions still INCLUDE_ASM anywhere in src (insn count, asm dir, name)
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
cd "$ROOT" || exit 1
grep -rhoE 'INCLUDE_ASM\("[^"]+", *[A-Za-z0-9_]+\)' src | sed -E 's/INCLUDE_ASM\("([^"]+)", *([A-Za-z0-9_]+)\)/\1 \2/' | while read d f; do
  a="$d/$f.s"
  [ -f "$a" ] || continue
  echo "$(grep -cE '^ */\* [0-9A-F]+ ' "$a") $d $f"
done | sort -n | head -${1:-40}
