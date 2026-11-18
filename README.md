# Chrono Cross decompilation

A work-in-progress, byte-matching decompilation of **Chrono Cross (USA)** for the PlayStation.

This repository does **not** contain any game data. You need your own copy of the game.

## Target

| File          | SHA1                                       |
|---------------|--------------------------------------------|
| `SLUS_010.41` | `9ac369fbda85651d13e1d2ebdd619becee068ad2` |

## Setup (Linux / WSL)

```bash
sudo apt install build-essential binutils-mips-linux-gnu python3-venv ninja-build
python3 -m venv .venv
.venv/bin/pip install "splat64[mips]"
```

Copy `SLUS_010.41` from your disc into `iso/`, then:

```bash
make split   # disassemble with splat
make         # rebuild and compare against the original
```

## Layout

- `slus_010.41.yaml` – splat config describing how the EXE is split
- `symbol_addrs.txt` – known function/data names
- `undefined_funcs.txt` – hand-maintained external symbols
- `asm/`, `assets/`, `build/` – generated, not committed

## Status

- Main executable round-trips byte-for-byte from disassembly.
- The module at `0x8008E488` is still an undisassembled binary blob.
