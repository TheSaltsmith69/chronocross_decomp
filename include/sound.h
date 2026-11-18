#ifndef SOUND_H
#define SOUND_H

#include "common.h"

/* Instrument / sample table entry (D_8008ADD0, 16 bytes each). */
typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ u16 unkC;
    /* 0xE */ u16 unkE;
} Unk8008ADD0;

/* Sound sequence channel. Channels sit in arrays with a 0x124-byte stride;
 * unk0 is the channel's script read pointer. */
typedef struct {
    /* 0x000 */ u8 *unk0;
    /* 0x004 */ u8 *unk4[4];      /* script return stack, indexed by unkE4 */
    /* 0x014 */ u8 pad14[4];
    /* 0x018 */ u8 *unk18;
    /* 0x01C */ u8 pad1C[8];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ s32 unk2C;
    /* 0x030 */ u8 pad30[4];
    /* 0x034 */ s32 unk34;
    /* 0x038 */ u8 pad38[4];
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ u8 pad40[4];
    /* 0x044 */ s32 unk44;
    /* 0x048 */ u8 pad48[4];
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ u8 pad50[4];
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05C */ s16 unk5C;
    /* 0x05E */ u8 pad5E[2];
    /* 0x060 */ u8 pad60[0xA];
    /* 0x06A */ s16 unk6A;
    /* 0x06C */ s16 unk6C;
    /* 0x06E */ u16 unk6E;
    /* 0x070 */ u8 pad70[4];
    /* 0x074 */ s16 unk74;
    /* 0x076 */ s16 unk76;
    /* 0x078 */ s16 unk78;
    /* 0x07A */ s16 unk7A;
    /* 0x07C */ s16 unk7C;
    /* 0x07E */ s16 unk7E;
    /* 0x080 */ u8 pad80[4];
    /* 0x084 */ s16 unk84;
    /* 0x086 */ s16 unk86[4];
    /* 0x08E */ s16 unk8E[4];
    /* 0x096 */ s16 unk96;
    /* 0x098 */ u8 pad98[4];
    /* 0x09C */ s16 unk9C;
    /* 0x09E */ s16 unk9E;
    /* 0x0A0 */ s16 unkA0;
    /* 0x0A2 */ s16 unkA2;
    /* 0x0A4 */ s16 unkA4;
    /* 0x0A6 */ s16 unkA6;
    /* 0x0A8 */ u16 unkA8;
    /* 0x0AA */ u8 padAA[0x3A];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0xA];
    /* 0x0F0 */ u16 unkF0;
    /* 0x0F2 */ s16 unkF2;
    /* 0x0F4 */ u8 padF4[4];
    /* 0x0F8 */ s16 unkF8;
    /* 0x0FA */ s16 unkFA;
    /* 0x0FC */ u8 padFC[0xC];
    /* 0x108 */ u32 unk108;
    /* 0x10C */ s32 unk10C;
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ s16 unk118;
    /* 0x11A */ s16 unk11A;
    /* 0x11C */ s16 unk11C;
    /* 0x11E */ s16 unk11E;
    /* 0x120 */ u8 pad120[4];
} Unk80051F24; /* size 0x124 */

extern Unk80051F24 *D_8008BE50; /* channel currently being processed */
extern s32 D_8008E398[];

#endif /* SOUND_H */
