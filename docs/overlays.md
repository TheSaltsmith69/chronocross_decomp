# Chrono Cross (USA, Disc 1) overlay map

Derived from PCSX-Redux RAM dumps (title, menu, field, battle), the
retail SLUS_010.41 and the Disc 1 .bin.

**Status:** `ov_field` (file #3), `ov_battle` (file #5) and `ov_menu` (file #39)
are split and rebuild byte-for-byte. Extract disc files with
`tools/extract_files.py`.

`tools/find_overlays.py --scan <disc.bin>` lists every file in the disc's file
table that contains code (77 on Disc 1, 92 on Disc 2), with the load address its
own `jal` targets point to. `tools/find_overlays.py <disc.bin> <dump_ram.bin>...`
says which of them are in a RAM dump and where. That run on the battle dump found
file #7 (28 KB, 36 functions) at 0x801EE000 next to the battle engine. Not split yet.
Other code files not yet seen in a dump: #8 (~0x801EA000), #37 and #225 (both
built for 0x801D2800, the menu's slot), #2053-2057 (~0x801EE000), and about 60
small modules at ~0x801C5E00 (#4338-#5946).

The menu overlay's layout differs from field/battle: one data word, code from
0x801D2804, then its rodata (strings + jump tables, 0x801F1B7C-0x801F317C), then
data. It calls field functions (0x800DCxxx), so it runs on top of the field engine.

## Memory layout at a glance

| Range | What | Changes at runtime? |
|---|---|---|
| 0x80010000-0x8006CE28 | main EXE code + rodata + data (what we're decompiling) | code is identical in all 4 dumps, apart from the buffer below |
| 0x80042B20-0x80043B30 | **not a function.** A 4 KB zero-filled buffer inside .text (splat calls it `func_80042B20`) | yes, filled at runtime |
| 0x8006CE28-0x8008E488 | main BSS | yes |
| 0x8008E488-0x800A3800 | `blob_8008E488`, the second module baked into the EXE (code + data) | code stays the same; its tail gets overwritten (below) |
| **0x800A3308-~0x800E7000** | **overlay slot A**: loaded from disc, starts 0x4F8 bytes *before* the EXE image ends | swapped between field and battle |
| 0x801B3308-... | battle only: a second copy of the battle overlay (staging buffer, ~57% still matches) | |
| **0x801D2800-0x801F5000** | **overlay slot B**: menu overlay | menu only |
| 0x801F8F1C-0x801FEDC8 | disc file table (6059 entries) | loaded at boot |

## Overlays found

| Disc file # | LBA | Size | Load addr | Code range | ~Funcs | Loaded in |
|---|---|---|---|---|---|---|
| 3 | 335 | 0x43800 (135 sectors) | 0x800A3308 | 0x800A3AA4-0x800E0524 | ~858 | title, menu, field |
| 5 | 472 | 0x3B000 (118 sectors) | 0x800A3308 | 0x800A3E3C-0x800D8688 | ~781 | battle |
| 39 | 929 | 0x22800 (69 sectors) | 0x801D2800 | 0x801D2DB4-0x801F1B7C | ~241 | menu |

Files are stored **uncompressed** and loaded byte-for-byte: RAM matches the
disc sectors 97-99% (the rest is data and BSS that changed after loading).
So we can extract each overlay straight from the .bin and split it with
splat like the EXE.

File 3 starts with MDEC error strings ("MDEC_rest:bad option..."). Its first
~0x79C bytes are rodata, and code follows from 0x800A3AA4.

## Disc file table

Only `SLUS_010.41` and `SYSTEM.CNF` appear in the ISO9660 directory.
Everything else is addressed through the game's own table, a u32 per file
(found in RAM at 0x801F8F1C, presumably also on disc near LBA 334-335):

- bits 0-22: start LBA
- bit 23: set on empty/placeholder entries (they repeat the next file's LBA)
- bits 24-31: probably the byte count of the last sector / 8 (unconfirmed)

File size is roughly `(next_lba - lba) * 2048`.

## What this means for the decomp

1. `func_80042B20` in `unk_8003FD00` should become a data/bss buffer, not code.
2. Two (likely more) overlays can be added as splat segments with their own
   vram: field engine (file 3) and battle (file 5) share 0x800A3308, and the
   menu (file 39) sits at 0x801D2800. That's ~1,900 more functions than the
   main EXE has.
3. Dumps from other game states (world map, cutscenes, shops, Disc 2) would
   probably turn up more files that load into slot A or B.
