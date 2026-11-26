#!/bin/bash
# Downloads the PS1-era GCC builds, maspsx, decomp-permuter and m2c into tools/.
# Run from the repo root:  bash tools/setup_tools.sh
set -euo pipefail

OLD_GCC_TAG=0.17
MASPSX_COMMIT=4ffa8b5106f9780d5d4aa7609f184949433ddbbc
M2C_COMMIT=c632946b8cfbe8fce442b522dba92dfa72f1f317
PERMUTER_COMMIT=860b6d95b5350c2677c89b0c195c7bf3bb6bad0b
VERSIONS="2.7.2-psx 2.8.0-psx 2.8.1-psx 2.7.2-cdk"

cd "$(dirname "$0")"

for v in $VERSIONS; do
  dir="gcc-$v"
  if [ -x "$dir/cc1" ]; then echo "$dir already present"; continue; fi
  mkdir -p "$dir"
  url="https://github.com/decompals/old-gcc/releases/download/$OLD_GCC_TAG/gcc-$v.tar.gz"
  echo "Downloading $url"
  curl -fsSL "$url" | tar -xz -C "$dir"
done

if [ ! -d maspsx/.git ]; then
  git clone -q https://github.com/mkst/maspsx.git maspsx
fi
git -C maspsx fetch -q origin "$MASPSX_COMMIT" 2>/dev/null || true
git -C maspsx checkout -q "$MASPSX_COMMIT"
echo "maspsx at $(git -C maspsx rev-parse --short HEAD)"

# decomp-permuter (tools/match/permute.py, permute_all.sh); needs toml + Levenshtein in .venv
if [ ! -d decomp-permuter/.git ]; then
  git clone -q https://github.com/simonlindholm/decomp-permuter.git decomp-permuter
fi
git -C decomp-permuter fetch -q origin "$PERMUTER_COMMIT" 2>/dev/null || true
git -C decomp-permuter checkout -q "$PERMUTER_COMMIT"
echo "decomp-permuter at $(git -C decomp-permuter rev-parse --short HEAD)"

# m2c decompiler (tools/match/decomp.py); needs pycparser + graphviz in .venv
if [ ! -d m2c/.git ]; then
  git clone -q https://github.com/matt-kempster/m2c.git m2c
fi
git -C m2c fetch -q origin "$M2C_COMMIT" 2>/dev/null || true
git -C m2c checkout -q "$M2C_COMMIT"
echo "m2c at $(git -C m2c rev-parse --short HEAD)"
