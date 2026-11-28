# Chrono Cross (USA, Disc 1) overlay map

Derived from PCSX-Redux RAM dumps (title, menu, field, battle), the
retail SLUS_010.41 and the Disc 1 .bin.

**Status:** `ov_field` (file #3), `ov_battle` (file #5), `ov_menu` (file #39),
`ov_enct` (file #7), `ov_result` (file #8), `ov_name` (file #37), `ov_shop`
(file #225), `ov_party` (file #2053), `ov_monmenu` (file #2054) and `ov_party2`
(file #2057) are split and rebuild byte-for-byte.
Both discs carry byte-identical copies of every code file under the same file
numbers, so Disc 1 is the extraction source for all of them.

The three slot-B programs (menu, name entry, shop) start with a header word
(0xA, 0xB, 0xC), kept as a `textbin` subsegment. Its name must be different in each
yaml (`menu_header`, ...) because splat writes it to `assets/<name>.textbin.bin`. Extract disc files with
`tools/extract_files.py`.

`tools/find_overlays.py --scan <disc.bin>` lists every file in the disc's file
table that contains code (77 on Disc 1, 92 on Disc 2), with the load address its
own `jal` targets point to. `tools/find_overlays.py <disc.bin> <dump_ram.bin>...`
says which of them are in a RAM dump and where. That run on the battle dump found
file #7 (28 KB, 35 functions) at 0x801EE000 next to the battle engine, now
`ov_enct`: a battle effect module (it holds the path
`c:\work\cdrom\battle\effects\enct.prd`, probably the encounter transition). Code
0x801EE000-0x801F3034, then a jump table + that string (rodata), then data.
Dumps from more game states (2026-11-27) placed three more:

| File | Size | Load address | What |
|---|---|---|---|
| #8 → `ov_result` | 0xC000 | 0x801EA000 | after-battle results screen (victory and boss "star up"), runs with the field engine |
| #37 → `ov_name` | 0x4000 | 0x801D2800 (slot B) | name-entry screen |
| #225 → `ov_shop` | 0xE000 | 0x801D2800 (slot B) | Element shop and smith |

Save/load screens are the menu overlay. Both world maps, cutscenes, the game
over screen, sailing and the mini-game dumped are plain field engine. Disc 2's
field, battle and menu use the same files as Disc 1.

A second batch (mostly Disc 2, possibly New Game+) placed #2053 at 0x801EE000:
the party swap screen, now `ov_party` (code 0x0-0x4204, 14 functions, matches the
dump 100%; rodata is one jump table, then data). #2057 is a close variant of
it (60% of words identical). #2054 is unrelated and not seen yet. Both call
only field-engine (and main-EXE) functions and are built for 0x801EE000, inside
the menu's code range, so they run from the field rather than the menu. The
in-field item menu, chest dialogue and the start-menu screen load no extra code
(field engine, plus the menu for the latter). The status screen and the
insert-disc prompt are both the menu overlay (#39); dumped from DuckStation with
`tools/ds_dump.py`, since the status screen crashes PCSX-Redux.

#2054 and #2057 are now set up too, from their own `jal` targets (0x801EE000), without
a dump: `ov_monmenu` (code to 0x2C94, then data; 17 functions) and `ov_party2` (code to
0x4050, a 10-entry jump table, then data; 14 functions). The battle-start dump confirms
#7 (`ov_enct`) is the transition into battle.

## Developer file names (Radical Dreamers Edition)

The 2022 PC release ships the PS1 data as loose files. Its `Chronodata\cdrom.fnd`
(Disc 1) and `cdrom2.fnd` (Disc 2) hold the original path of every disc file, 64 bytes
each, e.g. `c:\work\cdrom\prog\field.prg`. **Entry `i + 1` names USA disc file `i`**;
checked against 106 code files matched by content, and the Japanese and USA tables
both have 6059 entries. `cdrom.mde` is the Japanese LBA table in the same format as
ours. The two discs' name tables differ in 581 entries.

Every code file on both discs is a `.prg` (528 table entries on Disc 1, 555 on
Disc 2, 107 different files), and the PC release has all of them in
`Chronodata\prog\`, uncompressed. So no code file is still missing. Names for the
ones above: field.prg #3, miyatest.prg #4 (a 3D grid test program for slot A),
battle.prg #5, title.prg #6 (a developer boot menu), btlinit.prg #7, btlexit.prg #8,
namemenu.prg #37, menutest.prg #39, shopmenu.prg #225, memmenu.prg #2053,
monmenu.prg #2054, playinit.prg #2056, memmenu2.prg #2057.

Battle effects come in pairs: `battle\effects\<kind>\X.prd` (data), then `prog\X.prg`
(code for 0x801C5E00, header word = effect id). The PC release's big overlays were
relinked (11-48% byte-identical, same instructions), so they serve as names and
reference, not as matching targets. The effect code is 93-100% identical to the disc.
Six effects exist only on Disc 2: lasdes1 #5862, darkfeit #5868, dorured #5880,
dorublue #5883, lasbos #5913, bgchng #5916.

The last two code files' load addresses come from the code itself, so no dump is needed (or
possible: neither stays in RAM):

- **#6 title.prg loads at 0x800A3308** (slot A). Its `lui`/`addiu` pairs point at
  0x800A330C and up, and its first string sits at file offset 4. It is the developers' boot
  selector ("cd mode / pc mode / emulator mode", disk 1/2, loading `c:\work\cdrom\title.prd`
  and `.ltd` from a PC), which the retail game never loads.
- **#2056 playinit.prg loads at 0x801EE000.** The field overlay's `func_800A8EA0` loads it with
  `func_800A8DF4(3)`, calls its main function `func_801EE0B0` (file offset 0xB0) and frees it;
  it reads and writes field globals (0x800E39E1, 0x800E4184) and its own data at 0x801EE4F8.

File ids in the code are relative to a directory: `func_8004582C(dir)` sets the base
(`D_8008787C = D_80087954[dir]`, a u16 table read from disc at boot, at 0x801F8EEC in RAM),
and `func_80044924(id)` etc. use `base + id`. The game numbers files one higher than
`tools/extract_files.py` (like `cdrom.fnd`). Directory 5's base is 0xED, so
`func_800A8DF4(n)` loads disc file 2053 + n: 0 memmenu (`ov_party`), 1 monmenu, 3 playinit,
4 memmenu2 (`ov_party2`). The RDE's `cdrom.fid` is this same directory table.

`Chronodata\debug.prg` (3.2 MB, not on the retail discs) is the dev-kit debug module
for 0x80300000. All 19 calls the main EXE makes above 2 MB (`undefined_funcs.txt`,
0x8031A7C8-0x8033D044) land on function starts in it. It was linked against the
Japanese EXE, though (140 of its 205 call targets into the EXE are function starts
in `slps_023.64`, only 23 in SLUS_010.41). Its data is still useful: the effect editor's
command and particle-code tables name the battle effect script (`effect_commands.md`), and the
field debug screens print labelled game state (map, scenario flag, party/member masks, and an
actor's position, angle, animation numbers and status flags).

Battle effects: during Element/Tech/boss animations there is code at 0x801C5E00
that matches no single disc file, even with j/jal/lui words ignored. About 500
small files in #4300-#6000 start with a header word (mostly 0x4A/0x4C) and code,
so they are probably compressed or assembled at load time. Pinning them down
needs a trace of the game's file loader, not RAM dumps.

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
