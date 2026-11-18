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

typedef struct {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    s16 unk18;
    s16 unk1A;
} Attr8004C038;

void func_8004C038(s32 voice, Attr8004C038 *a) {
    u32 m = a->unk4;
    if (m == 0) {
        return;
    }
    a->unk4 = 0;
    if (m & 0x10) {
        m &= ~0x10;
        func_8004BE28(voice, a->unk10);
        if (m == 0) {
            return;
        }
    }
    if (m & 3) {
        m &= ~3;
        func_8004BDE0(voice, a->unk18, a->unk1A, a->unk16);
        if (m == 0) {
            return;
        }
    }
    if (m & 0x80) {
        m &= ~0x80;
        func_8004BE40(voice, a->unk8);
        if (m == 0) {
            return;
        }
    }
    if (m & 0x10000) {
        m &= ~0x10000;
        func_8004BE5C(voice, a->unkC);
        if (m == 0) {
            return;
        }
    }
    if (m & 0x6600) {
        m &= ~0x6600;
        func_8004BE90(voice, a->unk14);
        if (m == 0) {
            return;
        }
    }
    if (m & 0x9900) {
        func_8004BE78(voice, a->unk12);
    }
}

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

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unk8004D354;
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
} Env8004D354;
extern Env8004D354 D_8008AC00[];
extern u8 D_80087980[];

void func_8004D354(u32 arg0) {
    Unk8004D354 *s = (Unk8004D354 *)D_8008BE50;
    Unk8004D354 *t;
    u32 mask = (s->unk4 & s->unkC) | arg0;
    u32 i;
    Env8004D354 *e;
    t = (Unk8004D354 *)D_8008ABF8;
    if (t != NULL) {
        mask |= t->unk4 & t->unkC;
    }
    e = D_8008AC00;
    for (i = 0; i < 24; i++, e++) {
        if (mask & (1 << i)) {
            e->unk4 = 0x7FFF;
        } else {
            SpuGetVoiceEnvelope(i, &e->unk4);
            if (e->unk4 == 0) {
                func_8004D2D4(D_80087980, i);
            }
        }
    }
}

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
