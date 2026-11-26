#!/bin/bash
# findmis.sh CANDS.c -- substitute, build, name the first functions whose bytes differ in the overlay ($OV), revert
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1")
cd "$ROOT" || exit 1
backup_src
"$PY" "$M/subst.py" "$C" "$ROOT" >/dev/null
if ! build_ov; then echo "BUILD ERROR (builderr.sh shows why)"; restore_src; make >/dev/null 2>&1; exit 1; fi
cmp -l "$OV_BIN" "$OV_ISO" | head -2000 | awk -v b=$((OV_VRAM)) '{printf "%X\n", $1-1+b}' > /tmp/misaddr.txt
echo "$(wc -l < /tmp/misaddr.txt) differing bytes (first 2000 checked)"
mips-linux-gnu-nm -n "$OV_ELF" | awk '$2 ~ /[Tt]/ {print $1, $3}' > /tmp/missyms.txt
python3 - <<'EOF'
syms = [(int(a, 16), n) for a, n in (l.split() for l in open('/tmp/missyms.txt'))]
seen = []
for l in open('/tmp/misaddr.txt'):
    a = int(l, 16); best = None
    for sa, n in syms:
        if sa <= a: best = (sa, n)
        else: break
    if best and best[1] not in seen:
        seen.append(best[1]); print(hex(a), best[1], '+' + hex(a - best[0]))
    if len(seen) >= 6: break
EOF
restore_src
