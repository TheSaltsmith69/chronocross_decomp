#!/bin/bash
# adv.sh CANDS.c FUNC -- try each variant of FUNC on its own; print its alignment-diff block count
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1"); T=$(mktemp -d)
python3 - "$C" "$2" "$T" <<'EOF'
import sys
f, fn, t = sys.argv[1:]
for i, v in enumerate(open(f).read().split('// @@' + fn)[1:]):
    v = v.split('\n// @@')[0]
    open(f'{t}/v{i}.c', 'w').write('// @@' + fn + v)
EOF
for x in "$T"/v*.c; do
  i=$(basename "$x" .c)
  "$PY" "$M/trycc.py" "$x" --show > "$T/$i.out" 2>&1
  echo "$i: $(python3 "$M/adiff.py" "$T/$i.out" 0 | tail -1) match=$(grep -c '1/1 match' "$T/$i.out")"
done
rm -rf "$T"
