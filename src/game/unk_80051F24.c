#include "common.h"
#include "sound.h"

/* sound system state */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C;
    u8 unk4D;
    u8 pad4E[2];
    s32 unk50;
    s32 unk54;
    s32 unk58;
} Unk8008E3A8;
extern Unk8008E3A8 D_8008E3A8;

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80051F24);

void func_80051F44(u32 *src, u32 *dst, u32 n) {
    u32 a, b, c, d;
    n >>= 2;
    while (n >> 2) {
        a = src[0];
        b = src[1];
        c = src[2];
        d = src[3];
        dst[0] = a;
        dst[1] = b;
        dst[2] = c;
        dst[3] = d;
        src += 4;
        dst += 4;
        n -= 4;
    }
    while (n != 0) {
        *dst++ = *src++;
        n--;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80051FC4);

typedef struct {
    u8 pad0[4];
    s32 u4;
    u8 pad8[0x4C];
    s32 u54;
    s32 u58;
    s16 u5C;
    u8 pad5E[2];
    s32 u60;
    s32 u64;
    s16 u68;
} S203C;
typedef struct {
    u8 pad0[0x54];
    s32 u54;
    s32 u58;
    u8 pad5C[0x24];
    u16 u80;
    u16 u82;
    u8 pad84[0x16];
    u16 u9A;
    u8 pad9C[4];
    u16 uA0;
    u8 padA2[0x4C];
    s16 uEE;
    s16 uF0;
    s16 uF2;
    u8 padF4[0x18];
    s32 u10C;
    u8 pad110[0x14];
} C203C;
extern s32 D_8008E38C;
extern s16 D_8008BE6C;
extern s32 D_8008BF00;
extern s32 D_8008BE68;
extern u32 D_8008E39C;
extern s16 D_8006B808;
extern s16 D_8008ADCA;
extern s32 D_8008E394;
extern s32 D_8008AD44;
extern s16 D_8008ADC8;
extern s32 D_8008E390;
extern s32 D_8008AD40;
extern C203C D_80087980_c[] asm("D_80087980");
extern C203C D_80089E40_c[] asm("D_80089E40");
extern S203C *D_8008ABF8_s asm("D_8008ABF8");
extern void *D_8008ABF4_p asm("D_8008ABF4");
extern s32 D_8008BEB0[];
extern s32 D_8008BEE0;
void func_80051F24(void);
void func_8004BDE0(s32, s16, s16, s32);
void func_8004ED00(S203C *, void *);
void func_80050E94(s32 *);
#define CUR203C ((S203C *)D_8008BE50)
void func_8005203C(void) {
    s32 v;
    s32 nv;
    s32 i;
    C203C *p;
    u32 m;
    u32 bit;
    s16 l;
    D_8008E38C = (D_8008E38C + 1) & 0xFF;
    if (D_8008BE6C != 0) {
        D_8008BE6C--;
        D_8008BF00 += D_8008BE68;
        func_80051F24();
    }
    if (D_8008E3A8.unkC != 0 && D_8008E3A8.unk48 != 0) {
        D_8008E3A8.unk48--;
        v = D_8008E3A8.unk40;
        nv = v + D_8008E3A8.unk44;
        if ((nv & 0xFF00) != (v & 0xFF00)) {
            if (D_8008E39C & 2) {
                l = (v * D_8006B808) >> 16;
                func_8004BDE0(D_8008E3A8.unk10, l, l, 0);
                func_8004BDE0(D_8008E3A8.unk10 + 1, l, l, 0);
            } else {
                l = nv >> 1;
                func_8004BDE0(D_8008E3A8.unk10, l, 0, 0);
                func_8004BDE0(D_8008E3A8.unk10 + 1, 0, l, 0);
            }
        }
        D_8008E3A8.unk40 = (u16)nv;
    }
    if (D_8008ADCA != 0) {
        D_8008ADCA--;
        D_8008E394 += D_8008AD44;
    }
    if (D_8008ADC8 != 0) {
        D_8008ADC8--;
        nv = D_8008E390 + D_8008AD40;
        if ((nv & 0xFF0000) != (D_8008E390 & 0xFF0000)) {
            for (bit = 32, p = D_80087980_c; bit != 0; bit--, p++) {
                p->u10C |= 0x10;
            }
        }
        D_8008E390 = nv;
    }
    if (CUR203C->u4 != 0) {
        if (CUR203C->u5C != 0) {
            CUR203C->u5C--;
            nv = CUR203C->u54 + CUR203C->u58;
            if ((nv & 0x7F0000) != (CUR203C->u54 & 0x7F0000)) {
                func_8004ED00(CUR203C, D_80087980_c);
            }
            CUR203C->u54 = nv;
        }
        if (CUR203C->u68 != 0) {
            CUR203C->u68--;
            nv = CUR203C->u60 + CUR203C->u64;
            if ((nv & 0x7F0000) != (CUR203C->u60 & 0x7F0000)) {
                func_8004ED00(CUR203C, D_80087980_c);
            }
            CUR203C->u60 = nv;
        }
    }
    if (D_8008ABF8_s != NULL && D_8008ABF8_s->u4 != 0) {
        if (D_8008ABF8_s->u5C != 0) {
            D_8008ABF8_s->u5C--;
            nv = D_8008ABF8_s->u54 + D_8008ABF8_s->u58;
            if ((nv & 0x7F0000) != (D_8008ABF8_s->u54 & 0x7F0000)) {
                func_8004ED00(D_8008ABF8_s, D_8008ABF4_p);
            }
            D_8008ABF8_s->u54 = nv;
        }
        if (D_8008ABF8_s->u68 != 0) {
            D_8008ABF8_s->u5C--;
            nv = D_8008ABF8_s->u60 + D_8008ABF8_s->u64;
            if ((nv & 0x7F0000) != (D_8008ABF8_s->u60 & 0x7F0000)) {
                func_8004ED00(D_8008ABF8_s, D_8008ABF4_p);
            }
            D_8008ABF8_s->u60 = nv;
        }
    }
    if (D_8008BEB0[0] != 0) {
        m = D_8008BEB0[0];
        p = D_80089E40_c;
        bit = 0x1000;
        do {
            if (m & bit) {
                if (p->uA0 != 0) {
                    p->uA0--;
                    nv = p->uF0 + p->uF2;
                    if ((nv & 0xFF00) != (p->uF0 & 0xFF00)) {
                        p->u10C |= 3;
                    }
                    p->uF0 = nv;
                    if ((D_8008E398[0] & 0x10000) && p->uA0 == 0 && m == bit) {
                        func_80050E94(&D_8008BEE0);
                        D_8008E398[0] &= ~0x10000;
                    }
                }
                if (p->u82 != 0) {
                    p->u82--;
                    nv = p->u80 + p->uEE;
                    if ((nv & 0xFF00) != (p->u80 & 0xFF00)) {
                        p->u10C |= 3;
                    }
                    p->u80 = nv;
                }
                if (p->u9A != 0) {
                    p->u9A--;
                    nv = p->u54 + p->u58;
                    if ((nv & 0xFF00) != (p->u54 & 0xFF00)) {
                        p->u10C |= 0x10;
                    }
                    p->u54 = nv;
                }
                m ^= bit;
            }
            bit <<= 1;
            p++;
        } while (m != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80052518);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800527BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80052850);

extern u8 D_8006B53C[];
extern u8 D_8006B59C[];
#define CH_B0(ch) (*(u16 *)&(ch)->padAA[6])
#define CH_14(ch) (*(u8 **)(ch)->pad14)

s32 func_80052E64(Unk80051F24 *ch) {
    u8 *p = ch->unk0;
    s32 d = ch->unkE4;
    u32 op;
    s32 len;

    for (;;) {
        if (*p < 0x9A) {
            if (*p >= 0x8F) {
                CH_B0(ch) &= 0xFFFA;
            }
            return *p;
        }
        if (*p < 0xA0) {
            return 0xA0;
        }
        op = *p;
        len = D_8006B53C[op - 0xA0];
        if (len != 0) {
            p += len;
            continue;
        }
        switch (op) {
        case 0xF0: case 0xF1: case 0xF2: case 0xF3: case 0xF4: case 0xF5:
        case 0xF6: case 0xF7: case 0xF8: case 0xF9: case 0xFA: case 0xFB:
            return 0x83;
        case 0xFC:
            return 0x84;
        case 0xFD:
            return 0x8F;
        case 0xFE:
            p++;
            op = *p;
            len = D_8006B59C[op];
            if (len != 0) {
                p += len;
                continue;
            }
            switch (op) {
            case 8:
            case 9:
                p++;
                if (*p == (u16)ch->unk86[d] + 1) {
                    p++;
                    d--;
                    d &= 3;
                    goto rel;
                }
                p += 3;
                continue;
            case 6:
            case 14:
                p++;
                goto rel;
            case 7:
                p++;
                if (*p++ > *(u16 *)((u8 *)D_8008BE50 + 0x70)) {
                    goto skip;
                }
            rel:
                op = p[0] + (p[1] << 8);
                p += (s16)op;
                continue;
            skip:
                p += 2;
                continue;
            case 15:
                p = CH_14(ch);
                continue;
            }
            continue;
        case 0xC9:
            p++;
            if (*p == (u16)ch->unk86[d] + 1) {
                p++;
                d--;
                d &= 3;
                continue;
            }
            p = ch->unk4[d];
            continue;
        case 0xCB:
        case 0xCD:
        case 0xD1:
        case 0xDB:
            CH_B0(ch) &= 0xFFFA;
            p++;
            continue;
        case 0xCA:
            if (ch->unk34 & 0x200000) {
                goto def;
            }
            p = ch->unk4[d];
            continue;
        default:
        def:
            CH_B0(ch) &= 0xFFFA;
            return 0xA0;
        }
    }
}

extern Unk8008ADD0 D_8008ADD0_g[] asm("D_8008ADD0");

void func_80053078(Unk80051F24 *ch, u32 key) {
    u8 *z;
    Unk8008ADD0 *s;
    s32 flags;
    u32 idx;
    if ((u32)ch->unkFA < key || ch->unkFA == 0xFF) {
        z = ch->unk18;
        while (z[13] != 0 && z[2] < key) {
            z += 8;
        }
    } else if (key < (u32)ch->unkFA) {
        z = ch->unk18;
        while (z[13] != 0 && key >= z[9]) {
            z += 8;
        }
    } else {
        return;
    }
    flags = ch->unk34;
    idx = z[0];
    ch->unk7E = idx;
    s = &D_8008ADD0_g[idx];
    ch->unk110 = s->unk0;
    ch->unk114 = s->unk4;
    if (!(flags & 0x1000000)) {
        ch->unk11A = z[3] << 8;
    } else {
        ch->unk11A &= 0x7F00;
    }
    ch->unk11A |= s->unkC & 0x80FF;
    if (!(flags & 0x8000000)) {
        ch->unk11C &= 0x201F;
        ch->unk11C |= z[4] << 6;
    } else {
        ch->unk11C &= 0x3FDF;
    }
    switch (z[5]) {
    case 3:
        ch->unk11C |= 0x4000;
        break;
    case 5:
        ch->unk11C |= 0x8000;
        break;
    case 7:
        ch->unk11C |= 0xC000;
        break;
    }
    if (!(flags & 0x10000000)) {
        ch->unk11C &= 0xFFE0;
        ch->unk11C |= z[6];
    }
    ch->unk11C |= s->unkE & 0x20;
    ch->unk11E = z[7];
}

typedef struct {
    u8 pad0[8];
    s16 unk8;
    s16 unkA;
} Unk800532A0;
extern u32 D_8006B5D8[];

u16 func_800532A0(Unk800532A0 *t, s32 note, u32 vel, s32 *out) {
    s32 i;
    s32 f;
    i = note - t->unkA;
    while (i < 0) {
        i += 12;
    }
    i %= 12;
    if (t->unk8 == 0) {
        f = D_8006B5D8[i] << 8;
    } else if (t->unk8 < 0) {
        f = (D_8006B5D8[i] * (u16)t->unk8) >> 8;
    } else {
        f = (D_8006B5D8[i] * t->unk8) >> 7;
        f += D_8006B5D8[i] << 8;
    }
    vel &= 0xFF;
    if (vel != 0) {
        if (vel < 0x80) {
            *out = (u32)(f * vel) >> 7;
        } else {
            *out = ((u32)(f * vel) >> 8) - f;
        }
    }
    if (note < t->unkA) {
        do {
            *out >>= 1;
            f >>= 1;
            note += 12;
        } while (note < t->unkA);
    } else {
        i = (note - t->unkA) / 12;
        if (i != 0) {
            f <<= i;
            *out <<= i;
        }
    }
    *out >>= 8;
    f >>= 8;
    return f;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053430);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800536A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053DDC);

void func_80053E50(Unk80051F24 *arg0, Unk8008ADD0 *arg1, s32 arg2) {
    arg0->unk110 = arg2;
    arg0->unk114 = arg1->unk4;
    arg0->unk11A = arg1->unkC;
    arg0->unk11C = arg1->unkE;
    arg0->unk10C |= 0x1FF80;
}

extern Unk8008ADD0 D_8008ADD0[];
void func_80053E84(Unk80051F24 *arg0, s32 arg1) {
    Unk8008ADD0 *e;
    arg0->unk7E = arg1;
    e = &D_8008ADD0[arg1];
    func_80053E50(arg0, e, e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053EBC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053F28);

void func_80053FFC(Unk80051F24 *arg0) {
    Unk80051F24 *ch = D_8008BE50;
    ch->unk24 = arg0->unk0[0] << 16;
    ch->unk24 |= arg0->unk0[1] << 24;
    arg0->unk0 += 2;
    ch->unk6C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054048);

void func_800540E8(Unk80051F24 *arg0) {
    Unk80051F24 *cur = D_8008BE50;
    u8 *p = arg0->unk0;
    s32 hi = (s8)p[1];
    s32 lo = p[0];
    arg0->unk0 = p + 2;
    cur->unk6A = 0;
    hi <<= 20;
    lo <<= 12;
    hi |= lo;
    D_8008E398[2] |= 0x80;
    cur->unk4C = hi;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054130);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800541D8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054204);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005425C);

void func_80054294(s32 *arg0) {
    arg0[0] = arg0[5];
}

void func_800542A0(Unk80051F24 *arg0) {
    u8 v = *arg0->unk0++;
    arg0->unk10C |= 3;
    arg0->unk96 = v << 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800542C8);

void func_8005434C(Unk80051F24 *arg0) {
    s32 v = *((s8 *)arg0->unk0)++;
    arg0->unk9C = 0;
    arg0->unk10C |= 3;
    arg0->unk9E = 0;
    *(s32 *)&arg0->unk5C = v << 23;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005437C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054408);

void func_80054498(u8 *arg0) {
    *(s32 *)(arg0 + 0x34) |= 0x40;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800544AC);

void func_800544C0(Unk80051F24 *arg0) {
    s32 v = *arg0->unk0++;
    arg0->unkA4 = 0;
    arg0->unk10C |= 3;
    arg0->unkA2 = ((v + 0x40) & 0xFF) << 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800544F4);

void func_80054580(Unk80051F24 *arg0) {
    arg0->unkA8 = *arg0->unk0++;
}

void func_8005459C(Unk80051F24 *arg0) {
    arg0->unkA8 = (arg0->unkA8 + 1) & 0xF;
}

void func_800545B4(Unk80051F24 *arg0) {
    arg0->unkA8 = (arg0->unkA8 - 1) & 0xF;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800545CC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054640);

void func_800546AC(Unk80051F24 *ch) {
    u8 idx = *ch->unk0++;
    u16 *tbl = (u16 *)D_8008BE50->unk34;
    if (tbl != NULL) {
        if (tbl[idx] > 0x8000) {
            ch->unk34 &= ~0x1000;
            ch->unk11E = 0;
            return;
        }
        ch->unk18 = (u8 *)tbl + tbl[idx] + 0x20;
        ch->unkFA = 0xFF;
        ch->unk34 = (ch->unk34 & 0xE6FFEFF7) | 0x1000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054740);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054788);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800547AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800547D8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054820);

void func_80054858(u8 *arg0) {
    *(s16 *)(arg0 + 0xAE) = 0;
}

void func_80054860(Unk80051F24 *ch) {
    u32 t;
    s32 v;
    ch->unkF8 = (s8)*ch->unk0++;
    t = ch->unk2C * (u8)ch->unkF8;
    if (ch->unkF8 < 0) {
        v = (t >> 8) - ch->unk2C;
    } else {
        v = t >> 7;
    }
    *(s32 *)&ch->pad60[8] = v;
    ch->unk10C |= 0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800548C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054924);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054A24);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054A84);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054AF0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054B50);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054B74);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054C2C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054C50);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054CC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054D20);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054D44);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054DB8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054DD8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054E44);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054EA4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054EC8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054F28);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054F90);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055004);

extern s32 D_8008BEB0[];
void func_8005506C(Unk80051F24 *ch, s32 arg1) {
    if ((u16)ch->unk78 == 0) {
        D_8008BE50->unk44 |= arg1;
    } else {
        D_8008BEB0[8] |= arg1;
    }
    D_8008E398[2] |= 0x100;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800550CC);

void func_8005512C(u8 *arg0) {
    *(s16 *)(arg0 + 0xB0) = 1;
}

void func_80055138(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055140);

void func_8005515C(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055164);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055200);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055244);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055278);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800552A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800552EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005532C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055370);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800553E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005542C);

extern u8 *D_8008BE50_t asm("D_8008BE50");
void func_8005544C(void) {
    *(s32 *)(D_8008BE50_t + 0x3C) = 0;
}

void func_8005545C(Unk80051F24 *arg0) {
    arg0->unkE4 = (arg0->unkE4 + 1) & 3;
    arg0->unk4[arg0->unkE4] = arg0->unk0;
    arg0->unk86[arg0->unkE4] = 0;
    arg0->unk8E[arg0->unkE4] = arg0->unk84;
}

void func_800554AC(Unk80051F24 *ch) {
    u32 n = *ch->unk0++;
    if (n == 0) {
        n = 0x100;
    }
    if ((u16)++ch->unk86[ch->unkE4] != n) {
        ch->unk0 = ch->unk4[ch->unkE4];
        ch->unk84 = ch->unk8E[ch->unkE4];
    } else {
        ch->unkE4 = (ch->unkE4 - 1) & 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055540);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800555AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055628);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005567C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800556A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800556EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055724);

extern Unk80051F24 *D_8008BE50;
void func_8005573C(Unk80051F24 *arg0) {
    Unk80051F24 *ch = D_8008BE50;
    ch->unk78 = *arg0->unk0++;
    ch->unk74 = *arg0->unk0++;
    ch->unk7A = 0;
    ch->unk76 = 0;
}

void func_80055774(Unk80051F24 *arg0) {
    Unk80051F24 *ch = D_8008BE50;
    ch->unk7C = *arg0->unk0++;
    ch->unk7C |= *arg0->unk0++ << 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800557B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800557EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055830);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055860);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800558A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800558D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005593C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055950);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055964);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055978);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005598C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A04);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A18);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A2C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A4C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A6C);

void func_80055A88(u8 *arg0) {
    *(s16 *)(arg0 + 0xE6) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A90);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055AB0);

extern s32 D_8008BEB0[];

void func_80055AD0(void) {
    s32 m;
    if (D_8008E3A8.unkC != 0) {
        SpuSetIRQ(0);
        SpuSetIRQCallback(0);
        func_8004BD70(D_8008E3A8.unkC);
        func_8004BE5C(D_8008E3A8.unk10, 0x1030);
        func_8004BE5C(D_8008E3A8.unk10 + 1, 0x1030);
        m = D_8008E3A8.unkC;
        D_8008E3A8.unkC = 0;
        D_8008BEB0[8] &= ~m;
        D_8008E398[2] |= 0x100;
    }
}

extern s32 D_8008BEB0[];

s32 func_80055B70(void) {
    s32 i;
    u32 mask;
    u32 bits;
    do {
        mask = 0xC00000;
        bits = D_8008BEB0[0] | D_8008BEB0[4];
        for (i = 11; i != 0; i--, mask >>= 1) {
            if (!(bits & mask)) {
                break;
            }
        }
        if (i != 0) {
            return i + 11;
        }
        func_8004E538(0, 0x40000000);
    } while (bits != (D_8008BEB0[0] | D_8008BEB0[4]));
    return -1;
}

extern s16 D_8006B708[];
void func_8004BDE0(s32, s16, s16, s32);
void func_8004BE28(s32, s32);
void func_8004BE40(s32, s32);
void func_8004BE5C(s32, s32);
void func_8004BEA8(s32, s32, s32);
void func_8004BED8(s32, s32);
void func_8004BF00(s32, s32);
void func_8004BF28(s32, s32, s32);
void func_8004BF5C(s32, s32, s32);
void func_80055C00(s32 voice, s32 mode, s32 a2, s32 a3) {
    s16 l;
    s16 r;
    s16 h;
    if (D_8008E398[1] & 2) {
        l = r = (D_8008E3A8.unk40 * D_8006B708[0x80]) >> 16;
    } else if (mode == 1) {
        l = D_8008E3A8.unk40 >> 1;
        r = 0;
    } else if (mode == 2) {
        l = 0;
        r = D_8008E3A8.unk40 >> 1;
    } else if (mode == 3) {
        h = D_8008E3A8.unk40 >> 1;
        l = r = (h >> 1) + (h >> 2);
    } else {
        u32 p = D_8008E3A8.unk4D;
        l = (D_8008E3A8.unk40 * D_8006B708[p]) >> 16;
        p ^= 0xFF;
        r = (D_8008E3A8.unk40 * D_8006B708[p]) >> 16;
    }
    func_8004BDE0(voice, l, r, 0);
    func_8004BE28(voice, D_8008E3A8.unk58);
    func_8004BE40(voice, a2);
    func_8004BE5C(voice, a3);
    func_8004BEA8(voice, 0, 1);
    func_8004BED8(voice, 0xF);
    func_8004BF00(voice, 0xF);
    func_8004BF28(voice, 0x7F, 3);
    func_8004BF5C(voice, 6, 3);
}

void func_80055AD0(void);
void func_80055DBC(void) {
    func_80055AD0();
}

void func_8004BDE0(s32, s16, s16, s32);
void func_80055DDC(s32 *arg0) {
    s32 v = *arg0;
    D_8008E3A8.unk48 = 0;
    D_8008E3A8.unk40 = v;
    if (D_8008E3A8.unkC != 0) {
        func_8004BDE0(D_8008E3A8.unk10, (s16)(v >> 1), 0, 0);
        func_8004BDE0(D_8008E3A8.unk10 + 1, 0, (s16)(D_8008E3A8.unk40 >> 1), 0);
    }
}

void func_80055E4C(s32 *arg0) {
    s16 d;
    if (arg0[0] == 0) {
        d = 1;
    } else {
        d = arg0[0];
    }
    D_8008E3A8.unk44 = (s16)((s16)(arg0[1] - D_8008E3A8.unk40) / d);
    D_8008E3A8.unk48 = d;
}

u32 func_80055ECC(u32 *arg0) {
    D_8008E3A8.unk28++;
    (*arg0)++;
    if (D_8008E3A8.unk3C - 1 < *arg0) {
        *arg0 = 0;
    }
    return *arg0;
}

extern s32 D_8008BEB0[];
extern volatile s32 D_8008BE20;
void func_80056198(void);
void func_8004AFC4(s32, s32);
void func_8004BCC4(s32, s32);

void func_80055F20(void) {
    s32 v;
    s32 *h;
    s32 vol;
    u32 m;
    v = func_80055B70();
    if (v != -1) {
        SpuSetIRQ(0);
        SpuSetIRQCallback(0);
        h = (s32 *)(D_8008E3A8.unk2C + 0x80);
        if (h[10] != 0 && D_8008E3A8.unk48 == 0) {
            vol = D_8008E3A8.unk40;
            D_8008E3A8.unk40 = 0;
            func_8004AFC4(h[10], vol >> 8);
        }
        D_8008E3A8.unk0 = D_8008E3A8.unk2C;
        D_8008E3A8.unk14 = h[4];
        D_8008E3A8.unk18 = h[8];
        D_8008E3A8.unk10 = v;
        D_8008E3A8.unkC = (1 << v) | (1 << (v + 1));
        D_8008E3A8.unk34 = 0;
        func_8004BE5C(v, 0x1030);
        func_8004BE5C(v + 1, 0x1030);
        func_8004BD70(D_8008E3A8.unkC);
        D_8008E3A8.unk8 = h[6];
        D_8008E3A8.unk58 = ((u16 *)h)[14];
        SpuSetTransferMode(0);
        SpuSetTransferStartAddr(0xF100);
        D_8008BE20 = 1;
        func_8004BD24(func_80056198);
        func_8004BCC4(D_8008E3A8.unk0 + 0xD0, 0x2000);
        func_80055ECC((u32 *)&D_8008E3A8.unk34);
        func_80055ECC((u32 *)&D_8008E3A8.unk34);
        D_8008BEB0[8] &= ~D_8008E3A8.unkC;
        D_8008BEB0[9] &= ~D_8008E3A8.unkC;
        D_8008BEB0[7] &= ~D_8008E3A8.unkC;
        D_8008E398[2] |= 0x100;
    }
}

extern volatile s32 D_8008BE20;
void func_800560D0(s32 arg0, s32 addr, void (*cb)()) {
    if (D_8008E3A8.unkC != 0) {
        func_8004BD24(0);
        D_8008BE20 = 0;
        if (D_8008E3A8.unk14 > 0xE60) {
            D_8008E3A8.unk0 += arg0;
            SpuSetIRQCallback(cb);
        } else {
            SpuSetIRQCallback(func_80055AD0);
            addr = 0x1030;
        }
        SpuSetIRQAddr(addr + 8);
        func_8004BD54(D_8008E3A8.unkC);
        SpuSetIRQ(1);
    }
}

void func_80055C00(s32, s32, s32, s32);
void func_800560D0(s32, s32, void (*)());
void func_80056364();
void func_80056198(void) {
    func_80055C00(D_8008E3A8.unk10, 1, 0xF100, 0x10100);
    func_80055C00(D_8008E3A8.unk10 + 1, 2, 0xF900, 0x10900);
    func_800560D0(0x2000, 0x10100, func_80056364);
}

void func_8004B2B8(void);
void func_8004BCC4(s32, s32);

s32 func_80056208(s32 addr, s32 addr2, s32 size, void (*cb)()) {
    s32 *h;
    if (D_8008E3A8.unkC != 0) {
        h = (s32 *)(D_8008E3A8.unk0 + 0x80);
        if (*h == 0x4F414B41) {
            SpuSetIRQ(0);
            SpuSetTransferStartAddr(addr);
            func_8004B2B8();
            func_80055ECC((u32 *)&D_8008E3A8.unk34);
            func_8004BCC4(D_8008E3A8.unk0 + 0xD0, size - 0xD0);
            D_8008E3A8.unk20 = h[1];
            D_8008E3A8.unk18 = h[8];
            if ((u32)h[4] > (u32)h[8]) {
                SpuSetIRQCallback(cb);
                D_8008E3A8.unk0 += size;
                if (D_8008E3A8.unk34 == 0) {
                    D_8008E3A8.unk0 = D_8008E3A8.unk2C;
                }
            } else {
                SpuSetIRQCallback(func_80055AD0);
                addr2 = 0x1030;
                addr = addr2;
            }
            func_8004BE5C(D_8008E3A8.unk10, addr);
            func_8004BE5C(D_8008E3A8.unk10 + 1, addr2);
            SpuSetIRQAddr(addr + 8);
            SpuSetIRQ(1);
        }
    }
    return addr;
}

s32 func_80056208(s32, s32, s32, void (*)());
void func_80056394();
void func_80056364(void) {
    func_80056208(0xF100, 0xF900, 0x1000, func_80056394);
}

void func_80056394(void) {
    func_80056208(0x10100, 0x10900, 0x1000, func_80056364);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800563CC);
