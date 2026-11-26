#!/bin/bash
# realdiff.sh OUT.txt [SKIPFUNC...] -- from saved trycc --show output, print diff lines that aren't
# scratchpad-literal relocation noise (0x1f80 addresses, 4/16(reg) vs 0(reg))
f=$1; shift
awk -v skip="$*" '
/^---/ { h=$0; name=$2; show=(index(skip,name)==0); next }
/^\*/ {
  if (!show) next
  split($0, parts, "|"); o=parts[2]
  if (o ~ /0x1f80/) next
  if (o ~ /[ ,](4|16)\((s[0-9]|v[01]|a[0-3])\)[ ]*$/ && parts[1] ~ /[ ,]0\(/) next
  if (h != "") { print h; h="" }
  print
}' "$f"
