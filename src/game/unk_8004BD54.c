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

void func_8004BDE0(s32 voice, u32 l, u32 r, u32 scale) {
    u16 *p;
    if (scale != 0) {
        l *= scale;
        l >>= 7;
        r *= scale;
        r >>= 7;
    }
    p = (u16 *)(0x1F801C00 + voice * 16);
    p[0] = l & 0x7FFF;
    p[1] = r & 0x7FFF;
}

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

typedef struct Env8004D01C {
    s32 unk0;
    s16 unk4;
    s16 unk6;
} Env8004D01C;
extern Env8004D01C D_8008AC00_d[] asm("D_8008AC00");
s32 func_8004D01C(s32 i) {
    Env8004D01C *e;
    if (i != 0) {
        i = 0;
    } else {
        i = D_8008BE50->unk3C;
    }
    e = &D_8008AC00_d[i];
    while (e->unk4 != 0) {
        i++;
        if (i >= 0x18) {
            break;
        }
        e++;
    }
    return i;
}

typedef struct Cur8004D084 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Cur8004D084;
typedef struct Env8004D084 {
    s32 unk0;
    s16 unk4;
    s16 unk6;
} Env8004D084;
extern Env8004D084 D_8008AC00_i[] asm("D_8008AC00");
extern u32 D_8008BF04;
extern Unk80051F24 *D_8008E408[];
void func_8004C664(Unk80051F24 *, u32);
s32 func_8004D01C(s32);
s32 func_8004CF6C(s32);
void func_8004BF8C(s32, void *, s32);
void func_8004C038_i(s32, void *, s32) asm("func_8004C038");
#define CUR ((Cur8004D084 *)D_8008BE50)
#define CH120(c) (*(s16 *)&(c)->pad120[0])
#define CH122(c) (*(s16 *)&(c)->pad120[2])

void func_8004D084(Unk80051F24 *ch, u32 mask, u32 direct, u32 *out_) {
    u32 *out = out_;
    u32 bit = 1;
    s32 i = 0;
    u32 keyon = mask & CUR->unk10;
    s32 alt;
    s32 v;
    do {
        if (mask & bit) {
            func_8004C664(ch, bit);
            if (ch->unk10C != 0) {
                if (D_8008BF04 & bit) {
                    CH122(ch) = 0;
                    CH120(ch) = 0;
                }
                if (keyon & bit) {
                    if (direct & bit) {
                        *out |= 1 << i;
                        ch->unk108 = i;
                    } else {
                        alt = (CUR->unk8 & bit) != 0;
                        v = func_8004D01C(alt);
                        if (v == 0x18) {
                            CUR->unk0 |= 2;
                            v = func_8004CF6C(alt);
                            if (v == 0x18) {
                                ch->unk108 = v;
                                CUR->unk0 |= 1;
                                goto start;
                            }
                        }
                        *out |= 1 << v;
                        ch->unk108 = v;
                        D_8008AC00_i[v].unk4 = 0x7FFF;
                    }
                start:
                    if ((u32)ch->unk108 < 0x18) {
                        func_8004BF8C(ch->unk108, &ch->unk108, (u16)ch->unk11E);
                        D_8008E408[ch->unk108] = D_8008BE50;
                        D_8008E398[2] |= 0x100;
                    }
                } else {
                    if ((u32)ch->unk108 < 0x18) {
                        func_8004C038_i(ch->unk108, &ch->unk108, ch->unk34);
                    }
                }
            }
            mask &= ~bit;
        }
        bit <<= 1;
        ch++;
        i++;
    } while (mask != 0);
}

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

typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u8 padC[0x10];
    u32 unk1C;
} Unk8004DA38;
extern s32 D_8008BEB0[];
extern u32 D_8008E3B4;

void func_8004DA38(void) {
    u32 acc;
    u32 keep;
    u32 s1;
    u32 s0;
    u32 act = D_8008BEB0[0] | D_8008BEB0[4];
    s1 = 0;
    acc = 0;
    keep = ~(act | D_8008E3B4);
    if (D_8008ABF8 != 0) {
        s1 = ((Unk8004DA38 *)D_8008ABF8)->unk1C;
        if (s1 & ((Unk8004DA38 *)D_8008ABF8)->unk8) {
            func_8004D9D8(D_8008ABF4, &acc, s1 & ((Unk8004DA38 *)D_8008ABF8)->unk8, keep);
            ((Unk8004DA38 *)D_8008ABF8)->unk1C &= ~((Unk8004DA38 *)D_8008ABF8)->unk8;
            s1 &= ~((Unk8004DA38 *)D_8008ABF8)->unk8;
        }
    }
    s0 = ((Unk8004DA38 *)D_8008BE50)->unk1C;
    if (s0 & ((Unk8004DA38 *)D_8008BE50)->unk8) {
        func_8004D9D8((Unk80051F24 *)D_80087980, &acc, s0 & ((Unk8004DA38 *)D_8008BE50)->unk8, keep);
        ((Unk8004DA38 *)D_8008BE50)->unk1C &= ~((Unk8004DA38 *)D_8008BE50)->unk8;
        s0 &= ~((Unk8004DA38 *)D_8008BE50)->unk8;
    }
    if (D_8008ABF8 != 0 && s1 != 0) {
        func_8004D9D8(D_8008ABF4, &acc, s1, keep);
        ((Unk8004DA38 *)D_8008ABF8)->unk1C = 0;
    }
    if (s0 != 0) {
        func_8004D9D8((Unk80051F24 *)D_80087980, &acc, s0, keep);
        ((Unk8004DA38 *)D_8008BE50)->unk1C = 0;
    }
    acc |= D_8008BEB0[3];
    D_8008BEB0[3] = 0;
    if (acc != 0) {
        func_8004BD70(acc);
    }
}

extern s32 D_8008BEB0[];
extern u32 D_8008E3B4;

void func_8004DBE4(u32 *out, u32 m1, u32 m0, u32 extra) {
    u32 acc;
    u32 keep;
    u32 s1;
    u32 s0;
    u32 act = D_8008BEB0[0] | D_8008BEB0[4];
    s1 = 0;
    acc = 0;
    keep = ~(act | D_8008E3B4);
    if (D_8008ABF8 != 0) {
        s1 = ((Unk8004D354 *)D_8008ABF8)->unk4 & m1;
        if (s1 & ((Unk8004D354 *)D_8008ABF8)->unk8) {
            func_8004D9D8(D_8008ABF4, &acc, s1 & ((Unk8004D354 *)D_8008ABF8)->unk8, keep);
            s1 &= ~((Unk8004D354 *)D_8008ABF8)->unk8;
        }
    }
    s0 = ((Unk8004D354 *)D_8008BE50)->unk4 & m0;
    if (s0 & ((Unk8004D354 *)D_8008BE50)->unk8) {
        func_8004D9D8((Unk80051F24 *)D_80087980, &acc, s0 & ((Unk8004D354 *)D_8008BE50)->unk8, keep);
        s0 &= ~((Unk8004D354 *)D_8008BE50)->unk8;
    }
    if (D_8008ABF8 != 0 && s1 != 0) {
        func_8004D9D8(D_8008ABF4, &acc, s1, keep);
    }
    if (s0 != 0) {
        func_8004D9D8((Unk80051F24 *)D_80087980, &acc, s0, keep);
    }
    acc |= extra;
    *out = acc;
    D_8008E398[2] |= 0x100;
}
