# Sourced by the tools/match scripts. Sets M (this folder) and ROOT (the repo),
# and helpers for candidate files and overlays.
M=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
ROOT=$(cd -- "$M/../.." && pwd)
PY="$ROOT/.venv/bin/python3"
[ -x "$PY" ] || PY=python3

# abspath FILE: candidate files may be given relative to where the script was started
abspath() { case "$1" in /*) printf '%s\n' "$1" ;; *) printf '%s\n' "$PWD/$1" ;; esac; }

# The overlay the byte-level tools look at: OV=ov_field (default) or another entry of OVERLAYS in the Makefile.
OV=${OV:-ov_field}
OV_FILE=$(awk -v k="${OV}_FILE" '$1 == k {print $3}' "$ROOT/Makefile")
OV_BIN="build/files/$OV_FILE.bin"
OV_ISO="iso/files/$OV_FILE.bin"
OV_ELF="build/$OV.elf"
OV_VRAM=${OV_VRAM:-0x800A3308}

# build_ov: full make (-k, so the overlay is built even if another check fails). Returns 1 when the overlay
# binary wasn't produced (a compile or link error), so callers never compare a stale binary.
build_ov() { rm -f "$ROOT/$OV_BIN"; make -C "$ROOT" -k > /tmp/match_build.log 2>&1; [ -f "$ROOT/$OV_BIN" ]; }

# backup_src / restore_src: keep a copy of src/ while candidates are substituted in
backup_src() { _SRC_BAK=$(mktemp -d); cp -r "$ROOT/src" "$_SRC_BAK/"; }
restore_src() { rm -rf "$ROOT/src"; cp -r "$_SRC_BAK/src" "$ROOT/src"; rm -rf "$_SRC_BAK"; }
