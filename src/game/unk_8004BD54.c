#include "common.h"
#include "sound.h"

void func_8004BD54(u32 arg0) {
    *(u16 *)0x1F801D88 = arg0;
    *(u16 *)0x1F801D8A = arg0 >> 16;
}

void func_8004BD70(u32 arg0) {
    *(u16 *)0x1F801D8C = arg0;
    *(u16 *)0x1F801D8E = arg0 >> 16;
}

void func_8004BD8C(u32 arg0) {
    *(u16 *)0x1F801D98 = arg0;
    *(u16 *)0x1F801D9A = arg0 >> 16;
}

void func_8004BDA8(u32 arg0) {
    *(u16 *)0x1F801D94 = arg0;
    *(u16 *)0x1F801D96 = arg0 >> 16;
}

void func_8004BDC4(u32 arg0) {
    *(u16 *)0x1F801D90 = arg0;
    *(u16 *)0x1F801D92 = arg0 >> 16;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004BDE0);

void func_8004BE28(s32 voice, u16 arg1) {
    ((u16 *)0x1F801C04)[voice * 8] = arg1;
}

void func_8004BE40(s32 voice, u32 arg1) {
    ((u16 *)0x1F801C06)[voice * 8] = arg1 >> 3;
}

void func_8004BE5C(s32 voice, u32 arg1) {
    ((u16 *)0x1F801C0E)[voice * 8] = arg1 >> 3;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004BE78);

void func_8004BE90(s32 voice, u16 arg1) {
    ((u16 *)0x1F801C0A)[voice * 8] = arg1;
}

void func_8004BEA8(s32 voice, s32 arg1, u32 arg2) {
    u16 *reg = &((u16 *)0x1F801C08)[voice * 8];
    *reg = (*reg & 0xFF) | (((arg2 >> 2) << 15) | (arg1 << 8));
}

void func_8004BED8(s32 voice, s32 arg1) {
    u16 *reg = &((u16 *)0x1F801C08)[voice * 8];
    *reg = (*reg & 0xFF0F) | (arg1 << 4);
}

void func_8004BF00(s32 voice, s32 arg1) {
    u16 *reg = &((u16 *)0x1F801C08)[voice * 8];
    *reg = (*reg & 0xFFF0) | arg1;
}

void func_8004BF28(s32 voice, s32 arg1, u32 arg2) {
    u16 *reg = &((u16 *)0x1F801C0A)[voice * 8];
    *reg = (*reg & 0x3F) | (((arg2 >> 1) << 14) | (arg1 << 6));
}

void func_8004BF5C(s32 voice, s32 arg1, u32 arg2) {
    u16 *reg = &((u16 *)0x1F801C0A)[voice * 8];
    *reg = (*reg & 0xFFC0) | (((arg2 >> 2) << 5) | arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004BF8C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004C038);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004C154);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004C664);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004CADC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004CF6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004D01C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004D084);

extern s32 D_8008ABF8;
extern Unk80051F24 *D_8008ABF4;
void func_8004D2D4(Unk80051F24 *ch, u32 arg1) {
    u32 i;
    for (i = 0; i < 32; i++, ch++) {
        if (arg1 == ch->unk108) {
            ch->unk108 = 24;
        }
    }
    if (D_8008ABF8 != 0) {
        ch = D_8008ABF4;
        for (i = 0; i < 32; i++, ch++) {
            if (arg1 == ch->unk108) {
                ch->unk108 = 24;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004D354);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004D434);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004D484);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004D494);

void func_8004D9D8(Unk80051F24 *ch, u32 *out, u32 mask, u32 keep) {
    u32 bit = 1;
    do {
        if (mask & bit) {
            if (ch->unk108 < 0x18) {
                *out |= 1 << ch->unk108;
            }
        }
        mask &= ~bit;
        ch++;
        bit <<= 1;
    } while (mask != 0);
    *out &= keep;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004DA38);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004BD54", func_8004DBE4);
