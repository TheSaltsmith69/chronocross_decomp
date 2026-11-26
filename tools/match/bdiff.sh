#!/bin/bash
# bdiff.sh CANDS.c -- substitute, build the main EXE, list differing byte ranges against the original, revert
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1")
cd "$ROOT" || exit 1
backup_src
"$PY" "$M/subst.py" "$C" "$ROOT" >/dev/null
make build/SLUS_010.41 > /tmp/bd.log 2>&1 || tail -5 /tmp/bd.log
python3 - <<'EOF'
a = open('build/SLUS_010.41', 'rb').read(); b = open('iso/SLUS_010.41', 'rb').read()
print('sizes', len(a), len(b))
r = []; i = 0; n = min(len(a), len(b))
while i < n:
    if a[i] != b[i]:
        j = i
        while j < n and a[j] != b[j]: j += 1
        r.append((i, j)); i = j
    else: i += 1
print(len(r), 'ranges')
for s, e in r[:25]: print(hex(s - 0x800 + 0x80010000), e - s, a[s:e][:16].hex(), b[s:e][:16].hex())
EOF
restore_src
