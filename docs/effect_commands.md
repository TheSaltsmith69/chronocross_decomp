# Battle effect scripts

Names from `Chronodata\debug.prg` in the Radical Dreamers Edition (see `overlays.md`): the
developers' effect editor has a table of every effect-script command (name, length in bytes,
opcode, labels for up to three arguments) at 0x80344C3C, and a table of particle-generator
codes at 0x803449E0. `debug.prg` was linked against the Japanese build, so only the numbering
and layouts carry over, not addresses.

## Effect script commands

The interpreter is **`func_8002CEB4`** in the main EXE (`unk_8002B070`): a switch on the
command code (`jtbl_80062B54`, codes 2..0x7B; case index = code - 2). The names fit what each
case does:

- every `CASTER_*` case calls `func_8003099C`, every `TARGET_*` case `func_800309D0` and the
  `ACTOR_*` cases `func_80030934` (the caster / target / actor lookups);
- `BG_FAR/NEAR/RING/ROOF_ON` and `_OFF` call matching pairs of functions
  (`func_8002CBCC`/`func_8002CB18`, `func_8002CBA8`/`func_8002CAF4`, `func_8002CB84`/`func_8002CB3C`,
  `func_8002CBF0`/`func_8002CB60`), and `BG_ON`/`BG_OFF` call all four;
- `MUSIC_VOL` calls `func_8004A87C` and `SYS_SE` calls `func_8004A18C` (sound), `JOUTYU_RELOAD`
  loads files, `SCH_END` / `scheduler` / `SEP` work on the scheduler lists.

Codes 2..0x21, `WAIT`, `CDWAIT`, `NEXT_TARGET`, `LOOP_TARGET`, `WAIT_CASTER_SEQ`, `FRAME_BLOCK`
and `WAIT_MUSIC_LOAD` share the default case (`.L8002E204`): they are handled by the caller
(waits, flow control). `include/battle_effect.h` has these as `enum EffectCmd`.

Argument labels are the editor's (`s` short, `b` byte, `k`/`v`/`l`/`m` look like target,
visibility, light and music selectors).

| Code | Name | Bytes | Arguments | Handler |
|---|---|---|---|---|
| 0x20 | `WAIT` | 8 | s time | default |
| 0x22 | `SCH_END` | 16 | r res | `.L8002D08C` |
| 0x23 | `GEN` | 16 | r res | `.L8002E1F0` |
| 0x24 | `FOG_ON` | 8 | s | `.L8002D95C` |
| 0x25 | `FOG_OFF(mukou)` | 8 | s | `.L8002E220` |
| 0x26 | `BG_ON` | 8 | v | `.L8002D880` |
| 0x27 | `BG_OFF` | 8 | v | `.L8002D8A8` |
| 0x28 | `VIB_R` | 8 | p | `.L8002D28C` |
| 0x29 | `VIB_L` | 12 | s p | `.L8002D200` |
| 0x2b | `flash_mask0` | 12 | cccc s | `.L8002DC2C` |
| 0x2c | `flash_mask1` | 12 | cccc s | `.L8002DC2C` |
| 0x2d | `fog` | 16 | s | `.L8002DA38` |
| 0x2e | `shake` | 12 | s | `.L8002D940` |
| 0x2f | `scheduler` | 16 |  | `.L8002CF9C` |
| 0x30 | `ACTOR_ON` | 8 | v | `.L8002DD44` |
| 0x31 | `ACTOR_OFF` | 8 | v | `.L8002DD00` |
| 0x32 | `TEAMMAIT_ON` | 8 | v | `.L8002E0F0` |
| 0x33 | `TEAMMAIT_OFF` | 8 | v | `.L8002E05C` |
| 0x34 | `ENEMY_ON` | 8 | v | `.L8002DE1C` |
| 0x35 | `ENEMY_OFF` | 8 | v | `.L8002DD88` |
| 0x36 | `BG_FAR_ON` | 8 | v | `.L8002D8D0` |
| 0x37 | `BG_FAR_OFF` | 8 | v | `.L8002D8E0` |
| 0x38 | `BG_NEAR_ON` | 8 | v | `.L8002D8F0` |
| 0x39 | `BG_NEAR_OFF` | 8 | v | `.L8002D900` |
| 0x3a | `BG_RING_ON` | 8 | v | `.L8002D898` |
| 0x3b | `BG_RING_OFF` | 8 | v | `.L8002D8C0` |
| 0x3c | `BG_ROOF_ON` | 8 | v | `.L8002D910` |
| 0x3d | `BG_ROOF_OFF` | 8 | v | `.L8002D920` |
| 0x3e | `BLUR_ON` | 8 | s | `.L8002D97C` |
| 0x3f | `BLUR_OFF` | 8 | s | `.L8002DA2C` |
| 0x40 | `BLUR` | 28 | s | `.L8002DADC` |
| 0x41 | `FIRE_MAGIC` | 8 |  | `.L8002D930` |
| 0x42 | `CDWAIT` | 8 |  | default |
| 0x43 | `CASTER_ALL_SEQ` | 12 | s number: k | `.L8002D6F4` |
| 0x44 | `TARGET_ALL_SEQ` | 12 | s number: k | `.L8002D734` |
| 0x45 | `CASTER_SEQ` | 16 | s number: k | `.L8002D774` |
| 0x46 | `TARGET_SEQ` | 16 | s number: k | `.L8002D128` |
| 0x47 | `DAM_VALUE` | 12 | b | `.L8002D6A4` |
| 0x48 | `DAM_VALUE_ALL` | 8 | b | `.L8002D6CC` |
| 0x49 | `ACTOR_FOG_OFF` | 8 | s | `.L8002D4D0` |
| 0x4a | `TARGET_FOG_OFF` | 8 | s | `.L8002D528` |
| 0x4b | `CASTER_FOG_OFF` | 8 | s | `.L8002D4FC` |
| 0x4c | `SEP` | 24 | rLssL m | `.L8002DCA8` |
| 0x4d | `NEXT_TARGET` | 12 | b | default |
| 0x4e | `LOOP_TARGET` | 12 | b | default |
| 0x4f | `CASTER_SYS_SEQ` | 16 | s number k | `.L8002D7B4` |
| 0x50 | `WAIT_CASTER_SEQ` | 12 | k | default |
| 0x51 | `SYS_SE` | 16 | sccl m | `.L8002DCE0` |
| 0x52 | `SUB_SEMA` | 8 | b | `.L8002DC80` |
| 0x53 | `ADD_SEMA` | 8 | b | `.L8002DC98` |
| 0x54 | `MUSIC_VOL` | 12 | s volume m | `.L8002D868` |
| 0x55 | `KILL_GENERATER` | 16 | g Generater | `.L8002DF44` |
| 0x56 | `OLD-SLOW` | 12 | ss s | `.L8002D4A4` |
| 0x57 | `TARGET_SYS_SEQ` | 16 | s seq-num k | `.L8002D7F0` |
| 0x58 | `TARGET_COLOR` | 16 | ccc s | `.L8002DEB0` |
| 0x59 | `TARGET_MOTION` | 16 | ssss k | `.L8002D828` |
| 0x5a | `DELETE_GENERATER` | 16 | g Generater | `.L8002DF64` |
| 0x5b | `TARGET_ON` | 8 | v | `.L8002DFD8` |
| 0x5c | `TARGET_OFF` | 8 | v | `.L8002DF94` |
| 0x5d | `CASTER_ON` | 8 | v | `.L8002E030` |
| 0x5e | `CASTER_OFF` | 8 | v | `.L8002E004` |
| 0x5f | `BG_DECORE_ON` | 8 | v | `.L8002D9E4` |
| 0x60 | `BG_DECORE_OFF` | 8 | v | `.L8002DA08` |
| 0x61 | `TARGET_LIGHT_ON` | 12 | l | `.L8002D3F4` |
| 0x62 | `TARGET_LIGHT_OFF` | 12 | l | `.L8002D420` |
| 0x63 | `CASTER_LIGHT_ON` | 12 | l | `.L8002D44C` |
| 0x64 | `CASTER_LIGHT_OFF` | 12 | l | `.L8002D478` |
| 0x65 | `AMBIENT_LIGHT` | 16 | ccc l | `.L8002D304` |
| 0x66 | `LIGHT_CLEAR` | 8 | l | `.L8002D37C` |
| 0x67 | `FRAME_BLOCK` | 8 |  | default |
| 0x68 | `ACTOR_LIGHT_ON` | 12 | l | `.L8002D39C` |
| 0x69 | `ACTOR_LIGHT_OFF` | 12 | l | `.L8002D3C8` |
| 0x6a | `JOUTYU_RELOAD` | 8 | b | `.L8002D298` |
| 0x6b | `CASTER_VALUE` | 8 | b | `.L8002DFC0` |
| 0x6c | `MAJI_FOG_OFF` | 8 | s | `.L8002D96C` |
| 0x6d | `RING_OT` | 12 | s ot_ofs v | `.L8002D164` |
| 0x6e | `RING_OT_DEFAULT` | 8 | v | `.L8002D1B4` |
| 0x6f | `TARGET_FREEZE` | 12 | k | `.L8002D554` |
| 0x70 | `TARGET_UNFREEZE` | 12 | k | `.L8002D5A8` |
| 0x71 | `ALL_TARGET_FREEZE` | 12 | k | `.L8002D5D4` |
| 0x72 | `ALL_TARGET_UNFREEZE` | 12 | k | `.L8002D674` |
| 0x73 | `BOSS_MODE` | 8 |  | `.L8002D118` |
| 0x74 | `ALL_TARGET_SHADOW_OFF` | 8 | v | `.L8002D604` |
| 0x75 | `ALL_TARGET_SHADOW_ON` | 8 | v | `.L8002D63C` |
| 0x76 | `FACE_DIRECTION_RESET` | 8 | v | `.L8002CF04` |
| 0x77 | `CASTER_FREEZE` | 12 | k | `.L8002D568` |
| 0x78 | `CASTER_UNFREEZE` | 12 | k | `.L8002D594` |
| 0x79 | `NEW_SLOW` | 12 | s slow-rate s | `.L8002D4C0` |
| 0x7a | `WAIT_MUSIC_LOAD` | 8 | m | default |
| 0x7b | `DONT_VOLUME_RESET` | 8 |  | `.L8002DC1C` |

## Particle generator codes

Each code is a command of a particle generator ("generater" in the editor); the number is its
index in the table, the size is the editor's (bytes, probably). A leading `!` marks codes the
editor lists as disabled. The interpreter for these hasn't been found yet (it isn't in the code
split so far; `func_8002AD1C`'s 80-entry switch on `(w & 0x1FF) - 0x21` is a scheduler helper).

| Code | Name | Size |
|---|---|---|
| 0 | `CODE_END` | 8 |
| 1 | `CODE_NULL` | 6 |
| 2 | `!CODE_ALPHA` | 6 |
| 3 | `CODE_OT_OFS` | 6 |
| 4 | `CODE_PTN_CHANGE_INTERVAL` | 6 |
| 5 | `CODE_GRA_RESOURCE` | 2 |
| 6 | `CODE_STATUS` | 8 |
| 7 | `!CODE_SHAPE_NO` | 3 |
| 8 | `CODE_POS` | 8 |
| 9 | `CODE_POS_SIN` | 6 |
| 10 | `CODE_VELOCITY` | 8 |
| 11 | `CODE_VELOCITY_RAND` | 6 |
| 12 | `CODE_GRA` | 8 |
| 13 | `CODE_GRA_SIN` | 8 |
| 14 | `CODE_GRA_RAND` | 6 |
| 15 | `CODE_LIFE` | 8 |
| 16 | `CODE_LIFE_RAND` | 8 |
| 17 | `CODE_LIFE_SIN` | 6 |
| 18 | `CODE_SCALE` | 8 |
| 19 | `CODE_SCALE_RAND` | 8 |
| 20 | `CODE_SCALE_SIN` | 6 |
| 21 | `CODE_SCALE_VEC` | 8 |
| 22 | `CODE_SCALE_VEC_SIN` | 10 |
| 23 | `!CODE_SCALE_FIN` | 8 |
| 24 | `CODE_SCALE_VEC_RAND` | 6 |
| 25 | `CODE_ROT` | 8 |
| 26 | `CODE_ROT_RAND` | 6 |
| 27 | `CODE_ROT_VEC` | 8 |
| 28 | `CODE_ROT_SIN` | 10 |
| 29 | `!CODE_ROT_FIN` | 8 |
| 30 | `CODE_ROT_VEC_RAND` | 8 |
| 31 | `CODE_ROT_VEC_SIN` | 5 |
| 32 | `CODE_RGB` | 8 |
| 33 | `CODE_RGB_SIN` | 6 |
| 34 | `CODE_RGB_VEC` | 8 |
| 35 | `CODE_RGB_VEC_SIN` | 10 |
| 36 | `!CODE_RGB_FIN` | 8 |
| 37 | `CODE_RGB_RAND` | 8 |
| 38 | `CODE_RGB_VEC_RAND` | 5 |
| 39 | `CODE_LENGE` | 5 |
| 40 | `CODE_LENGE_EXTEND` | 8 |
| 41 | `!CODE_LENGE_SCALE` | 8 |
| 42 | `!CODE_LENGE_ROT` | 8 |
| 43 | `!CODE_LENGE_SIN` | 8 |
| 44 | `!CODE_SPEED` | 8 |
| 45 | `!CODE_SPEED_SIN` | 8 |
| 46 | `!CODE_SPEED_RAND` | 8 |
| 47 | `CODE_VELOCITY_SIN` | 2 |
| 48 | `CODE_REF_MATRIX` | 8 |
| 49 | `CODE_BOUND_RATE` | 8 |
| 50 | `CODE_BOUND_OFFSET` | 8 |
| 51 | `CODE_REBORN` | 10 |
| 52 | `CODE_EXPLODE` | 9 |
| 53 | `CODE_LSTATUS` | 10 |
| 54 | `CODE_LUV_SCROLL` | 10 |
| 55 | `CODE_LMIME` | 11 |
| 56 | `CODE_REVERSE_MOVE` | 2 |
| 57 | `CODE_HARITUKE` | 10 |
| 58 | `CODE_ACCELE` | 8 |
| 59 | `CODE_SOUTAI_ROT` | 8 |
| 60 | `CODE_MOVE_SYNC` | 4 |
| 61 | `CODE_GPATHLINE` | 10 |
| 62 | `!CODE_PPATHLINE` | 10 |
| 63 | `!CODE_EXTEND_CASTER` | 10 |
| 64 | `!CODE_EXTEND_TARGET` | 10 |
| 65 | `!CODE_VECTOL` | 8 |
| 66 | `CODE_SOUTAI_ROT2` | 10 |
| 67 | `!SCALE_GRA` | 10 |
| 68 | `!ROT_GRA` | 8 |
| 69 | `CODE_BORN_SYNC` | 8 |
| 70 | `CODE_BORN_SYNC` | 10 |
| 71 | `CODE_SOUTAI_ROT3` | 10 |
| 72 | `CODE_SCALE_FIT` | 10 |
| 73 | `CODE_EXTEND_DRAW` | 10 |
| 74 | `CODE_MOTION_STATUS` | ? |

## Other editor tables

**Easing / timing curves** (0x80347e14, index order): 0=`normal`, 1=`fast-slow`, 2=`slow-fast`, 3=`fast-slow-fast`, 4=`slow-fast-slow`, 5=`eye`, 6=`at`, 7=`projection`, 8=`warikomi`, 9=`atokara`, 10=`yaranai`, 11=`loop`, 12=`one`

**Blend modes** (0x80348104, index order): 0=`nothing`, 1=`half`, 2=`normal`, 3=`negative`, 4=`quarter`, 5=`half`, 6=`normal`, 7=`negative`, 8=`quarter`

**Resource types** (0x803483b8, index order): 0=`null`, 1=`resource`, 2=`model`, 3=`shape`, 4=`tim`, 5=`wave`, 6=`se`, 7=`bin`, 8=`ltd`, 9=`ctd`, 10=`generater`

**Attach points (model joints)** (0x80350924, index order): 0=`GENTEN`, 1=`SINCHO-`, 2=`HEAD`, 3=`MOUTH`, 4=`NECK`, 5=`R_SHOULDER`, 6=`L_SHOULDER`, 7=`R_ELBOW`, 8=`L_ELBOW`, 9=`R_HAND`, 10=`L_HAND`, 11=`WAIST`, 12=`R_KNEE`, 13=`L_KNEE`, 14=`R_ANKLE`, 15=`L_ANKLE`, 16=`CURSOR`, 17=`lenge`, 18=`HIT_POS`, 19=`FIRE_POS`, 20=`ELEM_18`, 21=`ELEM_19`, 22=`ELEM_20`, 23=`ELEM_21`, 24=`ELEM_22`, 25=`ELEM_23`, 26=`ELEM_24`, 27=`ELEM_25`, 28=`ELEM_26`, 29=`ELEM_27`, 30=`ELEM_28`, 31=`ELEM_29`, 32=`ELEM_30`, 33=`ELEM_31`, 34=`JIMEN`

**Target points** (0x803509b8, index order): 0=`NASHI`, 1=`CASTER_POINT`, 2=`TARGET_POINT`, 3=`ALL_CASTER_POINT`, 4=`ALL_TARGET_POINT`, 5=`ALL_ACTOR_POINT`, 6=`SYOUKAN_POINT`, 7=`WORLD_POINT(IMA-MUKOU)`, 8=`CASTER_POINT-1`, 9=`CASTER_POINT0`, 10=`CASTER_POINT1`, 11=`CASTER_POINT2`, 12=`TARGET_POINT-1`, 13=`TARGET_POINT0`, 14=`TARGET_POINT1`, 15=`TARGET_POINT2`, 16=`TARGET_POINT3`, 17=`TARGET_POINT4`, 18=`TARGET_POINT5`, 19=`TARGET_POINT6`, 20=`TARGET_POINT7`, 21=`TARGET_POINT8`, 22=`ALL_TARGET_JIMEN_POINT`, 23=`ALL_TARGET_TATI_POINT`, 24=`HESO`, 25=`CASTER_AREA_CENTER`, 26=`TARGET_AREA_CENTER`, 27=`ACTOR_POINT`

