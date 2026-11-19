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

typedef struct V8004BF8C {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 pad16;
    s16 unk18;
    s16 unk1A;
} V8004BF8C;
void func_8004BF8C(s32 voice, V8004BF8C *v, s32 scale) {
    u16 *p;
    s32 l;
    s32 r;
    v->unk4 = 0;
    p = (u16 *)(0x1F801C00 + voice * 16);
    if (scale == 0) {
        l = v->unk18;
        r = v->unk1A;
    } else {
        l = v->unk18 * scale;
        r = v->unk1A * scale;
        l >>= 7;
        r >>= 7;
    }
    *p = l & 0x7FFF;
    p++;
    *p = r & 0x7FFF;
    p++;
    *p = v->unk10;
    p++;
    *p = v->unk8 >> 3;
    p++;
    *p = v->unk12;
    p++;
    *p = v->unk14;
    p += 2;
    *p = v->unkC >> 3;
}

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

typedef struct {
    u8 pad0[0x1C];
    s16 *u1C;
    s16 *u20;
    s16 *u24;
    u8 pad28[4];
    u32 u2C;
    s32 u30;
    u8 pad34[4];
    s32 u38;
    s32 u3C;
    s32 u40;
    s32 u44;
    s32 u48;
    s32 u4C;
    u8 pad50[0xC];
    s32 u5C;
    s32 u60;
    s32 u64;
    u8 pad68[0x2E];
    u16 u96;
    u16 u98;
    u8 pad9A[2];
    u16 u9C;
    u8 pad9E[4];
    u16 uA2;
    u16 uA4;
    u16 uA6;
    u8 padA8[0xC];
    u16 uB4;
    u16 uB6;
    u16 uB8;
    u8 padBA[2];
    u16 uBC;
    u16 uBE;
    u16 uC0;
    u16 uC2;
    u8 padC4[2];
    u16 uC6;
    u16 uC8;
    u16 uCA;
    u8 padCC[2];
    u16 uCE;
    u16 uD0;
    u16 uD2;
    u16 uD4;
    u16 uD6;
    u8 padD8[2];
    u16 uDA;
    u16 uDC;
    u16 uDE;
    u16 uE0;
    u16 uE2;
    u8 padE4[8];
    s16 uEC;
    u8 padEE[6];
    s16 uF4;
    u8 padF6[0xA];
    s16 u100;
    s16 u102;
    s16 u104;
    u8 pad106[6];
    s32 u10C;
} C154;
extern s32 D_8008BEB0[];
void func_8004C154(Unk80051F24 *ch_, u32 bit, s32 flag) {
#define ch ((C154 *)ch_)
    s32 v;
    s16 *p;
    u16 t;
    u32 k;
    if (ch->u9C != 0) {
        ch->u9C--;
        v = ch->u5C + ch->u60;
        if ((v & 0xFFE00000) != (ch->u5C & 0xFFE00000)) {
            ch->u10C |= 3;
        }
        ch->u5C = v;
    }
    if (flag == 0 && ch->u98 != 0) {
        ch->u98--;
        v = ch->u96 + ch->uEC;
        if ((v & 0x7F00) != (ch->u96 & 0x7F00)) {
            ch->u10C |= 3;
        }
        ch->u96 = v;
    }
    if (ch->uA4 != 0) {
        ch->uA4--;
        v = ch->uA2 + ch->uF4;
        if ((v & 0xFF00) != (ch->uA2 & 0xFF00)) {
            ch->u10C |= 3;
        }
        ch->uA2 = v;
    }
    if (ch->uB4 != 0) {
        ch->uB4--;
    }
    if (ch->uC6 != 0) {
        ch->uC6--;
    }
    if (ch->uB6 != 0) {
        ch->uB6--;
        ch->u38 += ch->u3C;
    }
    if (ch->uC8 != 0) {
        ch->uC8--;
        ch->u40 += ch->u44;
    }
    if (ch->uD4 != 0) {
        ch->uD4--;
        ch->u48 += ch->u4C;
    }
    if (ch->uE0 != 0) {
        if (--ch->uE0 == 0) {
            if (flag == 0) {
                ((s32 *)D_8008BE50)[0x10] ^= bit;
            } else {
                D_8008BEB0[7] ^= bit;
            }
            D_8008E398[2] |= 0x110;
        }
    }
    if (ch->uE2 != 0) {
        if (--ch->uE2 == 0) {
            if (flag == 0) {
                ((s32 *)D_8008BE50)[0x12] ^= bit;
            } else {
                D_8008BEB0[9] ^= bit;
            }
            D_8008E398[2] |= 0x100;
        }
    }
    if (ch->uC0 != 0) {
        ch->uC0--;
        t = ch->uBE + ch->uC2;
        ch->uBE = t;
        k = (t & 0x7F00) >> 8;
        if (t & 0x8000) {
            t = (k * ch->u2C) >> 7;
        } else {
            t = (k * ((ch->u2C * 15) >> 8)) >> 7;
        }
        ch->uBC = t;
        if (ch->uB4 == 0 && ch->uB8 != 1) {
            p = ch->u1C;
            if (p[0] == 0 && p[1] == 0) {
                p += p[2];
            }
            v = (ch->uBC * *p) >> 16;
            if (v != ch->u100) {
                ch->u100 = v;
                ch->u10C |= 0x10;
                if (v >= 0) {
                    ch->u100 = v << 1;
                }
            }
        }
    }
    if (ch->uD0 != 0) {
        ch->uD0--;
        ch->uCE += ch->uD2;
        if (ch->uC6 == 0 && ch->uCA != 1) {
            p = ch->u20;
            if (p[0] == 0 && p[1] == 0) {
                p += p[2];
            }
            v = (s16)((((((s16 *)ch)[0x2F] * (ch->u96 >> 8)) >> 7) * (ch->uCE >> 8)) >> 7);
            v = (v * *p) >> 15;
            if (v != ch->u102) {
                ch->u102 = v;
                ch->u10C |= 3;
            }
        }
    }
    if (ch->uDC != 0) {
        ch->uDC--;
        ch->uDA += ch->uDE;
        if (ch->uD6 != 1) {
            p = ch->u24;
            if (p[0] == 0 && p[1] == 0) {
                p += p[2];
            }
            v = ((ch->uDA >> 8) * *p) >> 15;
            if (v != ch->u104) {
                ch->u104 = v;
                ch->u10C |= 3;
            }
        }
    }
    if (ch->uA6 != 0) {
        ch->uA6--;
        v = ch->u30 + ch->u64;
        if ((v & 0xFFFF0000) != (ch->u30 & 0xFFFF0000)) {
            ch->u10C |= 0x10;
        }
        ch->u30 = v;
    }
#undef ch
}

typedef struct {
    u8 pad0[0x1C];
    s16 *u1C;
    s16 *u20;
    s16 *u24;
    u8 pad28[4];
    s32 u2C;
    u8 pad30[2];
    s16 u32;
    u32 u34;
    u32 u38;
    u8 pad3C[4];
    u32 u40;
    u8 pad44[4];
    u32 u48;
    u8 pad4C[0xA];
    u16 u56;
    u8 pad58[6];
    s16 u5E;
    u8 pad60[2];
    s16 u62;
    u8 pad64[4];
    u16 u68;
    u8 pad6A[0x2C];
    u16 u96;
    u8 pad98[0xA];
    u16 uA2;
    u8 padA4[0x10];
    u16 uB4;
    u8 padB6[2];
    u16 uB8;
    u8 padBA[2];
    u16 uBC;
    u8 padBE[8];
    u16 uC6;
    u8 padC8[2];
    u16 uCA;
    u8 padCC[2];
    u16 uCE;
    u8 padD0[6];
    u16 uD6;
    u8 padD8[2];
    u16 uDA;
    u8 padDC[0x24];
    s16 u100;
    s16 u102;
    s16 u104;
    u8 pad106[6];
    s32 u10C;
    u8 pad110[8];
    u16 u118;
    u8 pad11A[6];
    s16 u120;
    s16 u122;
} C664;
extern u32 D_8008E39C;
extern u32 D_8008E390;
extern s16 D_8006B808;
extern s16 D_8006B708[];
void func_8004C664(Unk80051F24 *ch_, u32 bit) {
#define ch ((C664 *)ch_)
    u32 f;
    s32 vol;
    s32 v;
    s32 d;
    s16 *p;
    vol = (ch->u5E * (ch->u96 >> 8)) >> 7;
    f = ch->u34;
    if (f & 1) {
        if (ch->uB4 == 0) {
            if (--ch->uB8 == 0) {
                ch->uB8 = ch->u38 >> 10;
                p = ch->u1C;
                if (p[0] == 0 && p[1] == 0) {
                    ch->u1C = p + p[2];
                }
                d = *ch->u1C++;
                v = (ch->uBC * d) >> 16;
                if (v != ch->u100) {
                    ch->u100 = v;
                    ch->u10C |= 0x10;
                    if (v >= 0) {
                        ch->u100 = v << 1;
                    }
                }
            }
        }
    }
    if (f & 2) {
        if (ch->uC6 == 0) {
            if (--ch->uCA == 0) {
                ch->uCA = ch->u40 >> 10;
                p = ch->u20;
                if (p[0] == 0 && p[1] == 0) {
                    ch->u20 = p + p[2];
                }
                v = (s16)((vol * (ch->uCE >> 8)) >> 7);
                d = *ch->u20++;
                v = (v * d) >> 15;
                if (v != ch->u102) {
                    ch->u102 = v;
                    ch->u10C |= 3;
                }
            }
        }
    }
    if (f & 4) {
        if (--ch->uD6 == 0) {
            ch->uD6 = ch->u48 >> 10;
            p = ch->u24;
            if (p[0] == 0 && p[1] == 0) {
                ch->u24 = p + p[2];
            }
            d = *ch->u24++;
            v = ((ch->uDA >> 8) * d) >> 15;
            if (v != ch->u104) {
                ch->u104 = v;
                ch->u10C |= 3;
            }
        }
    }
    if (f & 0x20) {
        vol = ((s16)((ch - 1)->u118 << 1) * (ch->u96 >> 8)) >> 7;
        ch->u10C |= 3;
    }
    if (ch->u10C & 3) {
        vol += ch->u102;
        d = (s32)D_8008BE50;
        vol = (vol * (((C664 *)d)->u56 & 0x7F)) >> 7;
        v = (ch->uA2 >> 8) + ch->u104;
        v = (v + ((C664 *)d)->u62 - 0x40) & 0xFF;
        if (D_8008E39C & 2) {
            ch->u120 = ch->u122 = (vol * D_8006B808) >> 15;
        } else {
            ch->u120 = (vol * D_8006B708[v]) >> 15;
            ch->u122 = (vol * D_8006B708[v ^ 0xFF]) >> 15;
        }
    }
    if (f & 0x10) {
        d = (ch - 1)->u118 + ch->u100 + ch->u32;
        v = D_8008E390 & 0xFF0000;
        if (v != 0) {
            v >>= 16;
            if (v < 0x80) {
                d += (d * v) >> 7;
            } else {
                d = (d * v) >> 8;
            }
        }
        ch->u118 = (ch->u68 + d) & 0x3FFF;
        ch->u10C |= 0x10;
    } else if (ch->u10C & 0x10) {
        d = ch->u2C + ch->u100 + ch->u32;
        v = D_8008E390 & 0xFF0000;
        if (v != 0) {
            v >>= 16;
            if (v < 0x80) {
                d += (d * v) >> 7;
            } else {
                d = (d * v) >> 8;
            }
        }
        ch->u118 = (ch->u68 + d) & 0x3FFF;
    }
}
#undef ch

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
void func_8004BF8C();
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

extern s32 D_8008BE64_t asm("D_8008BE64");
void func_8004D484(u8 *arg0) {
    *(s32 *)(arg0 + 0x54) = D_8008BE64_t;
}

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
