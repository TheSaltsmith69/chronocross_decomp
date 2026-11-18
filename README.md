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

Download the PS1 compilers (gcc 2.7.2/2.8.0/2.8.1 from decompals/old-gcc) and maspsx:

```bash
bash tools/setup_tools.sh
```

Copy `SLUS_010.41` from your disc into `iso/`, then:

```bash
make split   # disassemble with splat
make         # rebuild and compare against the original
```

## Compiler

Game code is built with **GCC 2.8.1 (PsyQ)** at `-O2 -G0`, piped through
[maspsx](https://github.com/mkst/maspsx) and GNU `as`. Small functions in
`src/game/main.c` match with both 2.8.0 and 2.8.1; 2.7.2 does not match.
Override with `make CC_VERSION=2.8.0`.

## Booting and tracing

- `tools/patch_disc.py` writes `build/SLUS_010.41` into a copy of your disc BIN
  (MODE2/2352) and fixes EDC/ECC; with a matching build the output is identical
  to the original disc.
- `tools/ds_trace.py` connects to DuckStation's GDB server (enable it, and
  StartPaused, in DuckStation's settings), breaks on every main-EXE function and
  logs the first time each one runs. `tools/trace_funcs.py` makes its function list.
- `tools/quest.py <trace>` turns `progress/traces/<trace>.csv` into
  `progress/quest_<trace>.csv` with each function's file, size and matched status.

First quest: `progress/traces/boot_to_title.csv`, everything the main EXE runs
from power-on to the title screen (opening movie skipped with START).

## Contributing a function

1. Find it in `src/<file>.c` as `INCLUDE_ASM(...)`.
2. Replace that line with equivalent C.
3. `make` must still print `OK`.

## Layout

- `slus_010.41.yaml` – splat config describing how the EXE is split
- `symbol_addrs.txt` – known function/data names
- `undefined_funcs.txt` – hand-maintained external symbols
- `asm/`, `assets/`, `build/` – generated, not committed

## Status

- Main executable round-trips byte-for-byte.
- Main text is split into one file per PsyQ library object; `src/game/main.c` is compiled C.
- 5 functions decompiled to matching C.
- The module at `0x8008E488` is still an undisassembled binary blob.
