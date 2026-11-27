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

## Overlays

Most of the game's code is not in the EXE. It is loaded from disc at runtime;
see [docs/overlays.md](docs/overlays.md). Each overlay is split and rebuilt on
its own:

| Overlay | Disc file | Load address | SHA1 |
|---|---|---|---|
| `ov_field` (field engine, title) | #3 | `0x800A3308` | `ed96f819aa8ba1982bda8b767cdff9164d1c2fa5` |
| `ov_battle` (battle engine) | #5 | `0x800A3308` | `67825d31d9ad59b1cc939fbd39e7c03a1b073598` |
| `ov_menu` (menu, runs on top of the field engine) | #39 | `0x801D2800` | `0c8bf75bab12d78b468027142453fe4311acbc72` |
| `ov_enct` (battle effect module, loaded with the battle engine) | #7 | `0x801EE000` | `915042e00a30849a789682832e8fef7ceab3abc9` |
| `ov_result` (after-battle results screen) | #8 | `0x801EA000` | `1f2ad7deff356a6e60232be50ccd09ee1c1cb6fa` |
| `ov_name` (name entry, runs on top of the field engine) | #37 | `0x801D2800` | `c6e6e0dfb7083938b5196b0f5cf1f58806d8e213` |
| `ov_shop` (Element shop and smith, on top of the field engine) | #225 | `0x801D2800` | `53aefadb0fa980d295fc75c0db1cd85d6cdfd68e` |

```bash
python3 tools/extract_files.py "<disc 1>.bin" iso/files 3 5 39 7 8 37 225   # extract the overlays
for o in field battle menu enct result name shop; do make split-ov_$o; done  # disassemble them
make                                                              # now also checks the overlays
```

`tools/find_overlays.py` finds the disc's other code files and tells which of
them a RAM dump has loaded (see docs/overlays.md).

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
- `ov_*.yaml` – splat configs for the overlays (disc files #3, #5, #39, #7, #8, #37, #225)
- `symbol_addrs.txt` – known function/data names
- `undefined_funcs.txt` – hand-maintained external symbols
- `asm/`, `assets/`, `build/` – generated, not committed

## Status

- Main executable round-trips byte-for-byte.
- Main text is split into one file per PsyQ library object; `src/game/main.c` is compiled C.
- 5 functions decompiled to matching C.
- The module at `0x8008E488` is still an undisassembled binary blob.
