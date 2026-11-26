#!/bin/bash
# dump.sh CANDS.c SRCFILE OUTDIR -- apply CANDS to a temp copy of src, compile SRCFILE (e.g. src/game/unk_8002B070.c)
# with cc1 -dl -dg -dc -dj (RTL dumps: .lreg/.greg show register allocation), copy x.* to OUTDIR.
# CC=tools/gcc-2.7.2-psx and FLAGS=... override the main-EXE game defaults.
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1"); OUT=$(abspath "$3")
mkdir -p "$OUT"
cd "$ROOT" || exit 1
T=$(mktemp -d)
cp -r src include "$T"/
"$PY" "$M/subst.py" "$C" "$T" >/dev/null
CC=${CC:-tools/gcc-2.8.1-psx}
FLAGS=${FLAGS:--quiet -O2 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker -funsigned-char}
"$CC/cpp" -undef -lang-c -nostdinc -I"$T/include" -I"$T/src" -Iinclude -Isrc -D_LANGUAGE_C -DUSE_INCLUDE_ASM "$T/$2" > "$T/x.i"
(cd "$T" && "$ROOT/$CC/cc1" $FLAGS -dl -dg -dc -dj x.i -o x.s 2>/dev/null)
cp "$T"/x.* "$OUT"/ 2>/dev/null
ls "$OUT"
rm -rf "$T"
