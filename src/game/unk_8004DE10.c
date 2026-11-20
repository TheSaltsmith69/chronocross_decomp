#include "common.h"
#include "sound.h"

typedef struct { u8 pad[0x7E]; u16 h7E; u8 pad80[0x110 - 0x80]; s32 w110; s32 w114; } S4DE10;
u16 func_8004DE10(s32 arg0, S4DE10 *arg1) {
    if ((arg0 & 0x20) && (u32)(arg1->h7E - 0x20) < 0x40) {
        arg1->w110 += 0x30000;
        arg1->w114 += 0x30000;
        arg1->h7E += 0x20;
    }
    return arg1->h7E;
}

typedef struct { u8 pad[0x7E]; u16 h7E; u8 pad80[0x110 - 0x80]; s32 w110; s32 w114; } S4DE64;
u16 func_8004DE64(s32 arg0, S4DE64 *arg1) {
    if ((arg0 & 0x20) && (u32)(arg1->h7E - 0x20) < 0x40) {
        arg1->w110 -= 0x30000;
        arg1->w114 -= 0x30000;
        arg1->h7E -= 0x20;
    }
    return arg1->h7E;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DEB8);

s32 func_8004DF98(u32 *arg0) {
    s32 n = 0;
    u32 m = 1;
    if (arg0[1] != 0) {
        u32 v = arg0[1];
        do {
            if (v & m) {
                n++;
            }
            m <<= 1;
        } while (m != 0 && m <= v);
    }
    return n;
}

void f_53E84_e(void *, s32) asm("func_80053E84");
void func_8004DFDC(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x96) = 0x6E00;
    *(s32 *)(arg0 + 0x5C) = 0x32000000;
    *(s32 *)(arg0 + 0x0) = arg1;
    *(u16 *)(arg0 + 0xF6) = 0;
    *(u16 *)(arg0 + 0xF8) = 0;
    *(u16 *)(arg0 + 0xAE) = 0;
    *(s32 *)(arg0 + 0x30) = 0;
    *(u16 *)(arg0 + 0xFC) = 0;
    *(u16 *)(arg0 + 0xA6) = 0;
    *(u16 *)(arg0 + 0xEA) = 0;
    *(u16 *)(arg0 + 0xE8) = 0;
    *(u16 *)(arg0 + 0x9C) = 0;
    *(s32 *)(arg0 + 0x68) = 0;
    *(u16 *)(arg0 + 0xE6) = 0;
    *(u16 *)(arg0 + 0xE4) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(u16 *)(arg0 + 0x104) = 0;
    *(u16 *)(arg0 + 0xB0) = 0;
    *(u16 *)(arg0 + 0x84) = 0xFFFF;
    *(u16 *)(arg0 + 0x11E) = 0;
    *(u16 *)(arg0 + 0xDA) = 0;
    *(u16 *)(arg0 + 0xCE) = 0;
    *(u16 *)(arg0 + 0xBE) = 0;
    *(u16 *)(arg0 + 0xDC) = 0;
    *(u16 *)(arg0 + 0xD0) = 0;
    *(u16 *)(arg0 + 0xC0) = 0;
    *(u16 *)(arg0 + 0xD4) = 0;
    *(u16 *)(arg0 + 0xC8) = 0;
    *(u16 *)(arg0 + 0xB6) = 0;
    *(u16 *)(arg0 + 0xE2) = 0;
    *(u16 *)(arg0 + 0xE0) = 0;
    f_53E84_e(arg0, 0);
}

u32 func_8004E084(u8 *arg0, u32 arg1) {
    u32 i;
    u32 r;
    i = 0;
    r = 0;
    for (; i < 32; i++, arg0 += 0x124) {
        if (arg1 & (1 << i)) {
            u32 v = *(u32 *)(arg0 + 0x108);
            if (v < 24) {
                r |= 1 << v;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E0D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E464);

typedef struct {
    u8 pad0[0x28];
    s32 unk28;
    u8 pad2C[8];
    u32 unk34;
    u8 pad38[0x18];
    s32 unk50;
    u8 pad54[0x18];
    s32 unk6C;
    u8 pad70[0xB4];
} C8004E538;
extern C8004E538 D_80089E40_c[] asm("D_80089E40");
void func_80053EBC();
extern s32 D_8008BEB0[];
void func_8004E538(s32 id, s32 flags) {
    u32 bit = 0x1000;
    C8004E538 *ch = D_80089E40_c;
    u32 mask = D_8008BEB0[0] | D_8008BEB0[4];
    u32 i;
    s32 max;
    if (flags & 0x0FFFFFFF) {
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if ((mask & bit) && (ch->unk28 & flags)) {
                if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
            }
        }
    } else if (flags < 0) {
        ch = &D_80089E40_c[id];
        bit <<= id;
        if (mask & bit) {
            func_8004E538(ch->unk50, 0);
        }
        bit <<= 1;
        ch++;
        if (mask & bit) {
            func_8004E538(ch->unk50, 0);
        }
        return;
    } else if (flags & 0x40000000) {
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if (ch->unk28 != 0) {
                mask &= ~bit;
            }
        }
        ch = D_80089E40_c;
        bit = 0x1000;
        max = 0;
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if ((mask & bit) && max < ch->unk6C) {
                max = ch->unk6C;
            }
        }
        ch = D_80089E40_c;
        bit = 0x1000;
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if ((mask & bit) && max == ch->unk6C) {
                if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
            }
        }
    } else {
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if (mask & bit) {
                if (id == -1) {
                    if (ch->unk50 < 0) {
                        if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
                    }
                } else if (ch->unk50 == id) {
                    if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
                }
            }
        }
    }
    D_8008E398[2] |= 0x110;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E898);

extern u8 *D_8008BE50_y asm("D_8008BE50");
void func_8004EA34(u8 *arg0, u32 arg1) {
    u32 i;
    u8 *cur;
    u32 k;
    if (arg1 < 24) {
        for (i = 0, k = 24, cur = D_8008BE50_y; i < 32; i++, arg0 += 0x124) {
            if (*(u32 *)(arg0 + 0x108) == arg1) {
                *(u32 *)(arg0 + 0x108) = k;
                *(u32 *)(cur + 0x14) &= ~(1 << i);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EA90);

extern u16 *D_8008BE1C_p asm("D_8008BE1C");
extern s32 D_8008BE28_w asm("D_8008BE28");
#define LK(i) (D_8008BE1C_p[i] != 0xFFFF ? D_8008BE28_w + D_8008BE1C_p[i] : 0)
void func_8004EC88(s32 *arg0, s32 *arg1, u32 arg2) {
    arg2 &= 0x3FF;
    arg2 <<= 1;
    *arg0 = LK(arg2);
    arg2++;
    *arg1 = LK(arg2);
}

void func_8004ED00(s32 *arg0, Unk80051F24 *ch) {
    u32 mask;
    s32 bit;
    if (arg0[1] != 0) {
        mask = arg0[1];
        bit = 1;
        do {
            if (mask & bit) {
                ch->unk10C |= 3;
                mask ^= bit;
            }
            ch++;
            bit <<= 1;
        } while (mask != 0);
    }
}

typedef struct { u8 pad[0x10C]; u32 unk10C; u8 pad2[0x124 - 0x110]; } S4ED48;
extern S4ED48 D_80089E40_s[] asm("D_80089E40");
extern u32 D_8008BEB0_w asm("D_8008BEB0");
void func_8004ED48(void) {
    u32 m;
    u32 bit;
    S4ED48 *p;
    if (D_8008BEB0_w != 0) {
        m = D_8008BEB0_w;
        bit = 0x1000;
        p = D_80089E40_s;
        do {
            if (m & bit) {
                m ^= bit;
                p->unk10C |= 3;
            }
            p++;
            bit <<= 1;
        } while (m != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004ED9C);

extern Unk80051F24 D_8008AD48;
void func_8004ED9C(s32, s32);
void func_8004E0D0(s32, s32);
void func_8004F04C(s32 *arg0) {
    if (D_8008AD48.unk6E != 0 && D_8008AD48.unk6E == arg0[2]) {
        func_8004ED9C(arg0[0], 0);
    } else {
        func_8004E0D0(arg0[0], -1);
        D_8008BE50->unk6E = arg0[2];
    }
}

typedef struct { u8 pad[0x6E]; u16 h6E; } S4F0C8;
extern S4F0C8 D_8008AD48_s asm("D_8008AD48");
extern S4F0C8 *D_8008BE50_m asm("D_8008BE50");
void f_4ED9C_a(s32, s32) asm("func_8004ED9C");
void f_4E0D0_a(s32, s32) asm("func_8004E0D0");
void func_8004F0C8(s32 *arg0) {
    if (D_8008AD48_s.h6E != 0 && D_8008AD48_s.h6E == arg0[2]) {
        f_4ED9C_a(arg0[0], 0);
    } else {
        f_4E0D0_a(arg0[0], arg0[3]);
        D_8008BE50_m->h6E = arg0[2];
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F148);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F1F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F2B8);

void f_4F04C_a(void *) asm("func_8004F04C");
extern s32 D_8008BE18_w asm("D_8008BE18");
void func_8004F484(s32 *arg0) {
    s32 r;
    f_4F04C_a(arg0);
    if (arg0[3] == 0) {
        r = 0;
    } else {
        r = arg0[3] - 1;
    }
    D_8008BE18_w = r;
}

void f_4EA90_a(void *, s32, s32, s32) asm("func_8004EA90");
void func_8004F4C4(s32 *arg0) {
    s32 a = arg0[0];
    s32 b = arg0[1];
    arg0[0] = 0x400;
    arg0[1] = 0x1000000;
    arg0[2] = 0x80;
    arg0[3] = 0x7F;
    arg0[4] = 0;
    f_4EA90_a(arg0, a, b, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F510);

extern u16 *D_8008E388_z8 asm("D_8008E388");
void f_4EA90_z8(s32 *, s32, s32, s32) asm("func_8004EA90");
void f_4EC88_z8(s32 *, s32 *, s32) asm("func_8004EC88");
void func_8004F5D8(s32 *arg0) {
    s32 a;
    s32 b;
    u32 n = D_8008E388_z8[arg0[0]];
    s32 i;
    arg0[4] = 0;
    f_4EC88_z8(&a, &b, arg0[0]);
    f_4EA90_z8(arg0, a, b, 0);
    if (n != 0) {
        i = 1;
        do {
            f_4EC88_z8(&a, &b, arg0[0] + i);
            n--;
            f_4EA90_z8(arg0, a, b, 1);
            i++;
        } while (n != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F688);

void func_8004E538(s32, s32);
void func_8004F7A8(s32 *arg0) {
    func_8004E538(arg0[0], arg0[1]);
}

extern u8 *D_8008BE50_z8 asm("D_8008BE50");
extern u8 D_80087980_z8[] asm("D_80087980");
extern u8 *D_8008ABF8_z8 asm("D_8008ABF8");
extern void *D_8008ABF4_z8 asm("D_8008ABF4");
void f_4ED00_z8(void *, void *) asm("func_8004ED00");
void func_8004F7D4(u32 *arg0) {
    u32 v = arg0[0];
    u8 *b;
    if (v == 0 || v == *(u16 *)(D_8008BE50_z8 + 0x6E)) {
        *(s32 *)(D_8008BE50_z8 + 0x54) = (arg0[1] & 0x7F) << 16;
        *(u16 *)(D_8008BE50_z8 + 0x5C) = 0;
        f_4ED00_z8(D_8008BE50_z8, D_80087980_z8);
    } else {
        b = D_8008ABF8_z8;
        if (b != NULL && v != 0 && v == *(u16 *)(b + 0x6E)) {
            s32 t;
            void *c = D_8008ABF4_z8;
            t = (arg0[1] & 0x7F) << 16;
            *(u16 *)(b + 0x5C) = 0;
            *(s32 *)(b + 0x54) = t;
            f_4ED00_z8(b, c);
        }
    }
}

extern Unk80051F24 *D_8008ABF8;
extern u8 *D_8008ABF4;
extern u8 D_80087980[];
void func_8004F888(s32 *arg) {
    s32 n = 1;
    Unk80051F24 *ch;
    s32 v;
    s32 cur;
    if (arg[1] != 0) {
        n = arg[1];
    }
    v = ((arg[2] & 0x7F) << 16) | 0x8000;
    arg = (s32 *)arg[0];
    if (arg == 0 || (s32)arg == D_8008BE50->unk6E) {
        cur = D_8008BE50->unk54;
        cur &= 0xFFFF0000;
        cur |= 0x8000;
        v -= cur;
        v /= n;
        D_8008BE50->unk5C = n;
        D_8008BE50->unk54 = cur;
        D_8008BE50->unk58 = v;
        func_8004ED00(D_8008BE50, D_80087980);
    } else {
        ch = D_8008ABF8;
        if (ch != NULL && arg != 0 && (s32)arg == ch->unk6E) {
            cur = ch->unk54;
            cur &= 0xFFFF0000;
            cur |= 0x8000;
            v -= cur;
            v /= n;
            ch->unk5C = n;
            ch->unk54 = cur;
            ch->unk58 = v;
            func_8004ED00(ch, D_8008ABF4);
        }
    }
}

extern Unk80051F24 *D_8008ABF8;
extern u8 *D_8008ABF4;
extern u8 D_80087980[];

void func_8004F9C4(s32 *arg) {
    s32 n = 1;
    Unk80051F24 *ch;
    u8 *tbl;
    s32 v;
    if (arg[1] != 0) {
        n = arg[1];
    }
    if (arg[0] == 0 || arg[0] == D_8008BE50->unk6E) {
        ch = D_8008BE50;
        tbl = D_80087980;
    } else if (D_8008ABF8 != NULL && arg[0] != 0 && arg[0] == D_8008ABF8->unk6E) {
        ch = D_8008ABF8;
        tbl = D_8008ABF4;
    } else {
        return;
    }
    v = ((arg[2] & 0x7F) << 16) | 0x8000;
    ch->unk54 = v;
    ch->unk58 = ((((arg[3] & 0x7F) << 16) | 0x8000) - v) / n;
    ch->unk5C = n;
    func_8004ED00(ch, tbl);
}

void func_8004FAC4(u32 *arg0) {
    u32 v = arg0[0];
    u8 *b;
    if (v == 0 || v == *(u16 *)(D_8008BE50_z8 + 0x6E)) {
        *(s32 *)(D_8008BE50_z8 + 0x60) = (arg0[1] & 0x7F) << 16;
        *(u16 *)(D_8008BE50_z8 + 0x68) = 0;
        f_4ED00_z8(D_8008BE50_z8, D_80087980_z8);
    } else {
        b = D_8008ABF8_z8;
        if (b != NULL && v != 0 && v == *(u16 *)(b + 0x6E)) {
            s32 t;
            void *c = D_8008ABF4_z8;
            t = (arg0[1] & 0x7F) << 16;
            *(u16 *)(b + 0x68) = 0;
            *(s32 *)(b + 0x60) = t;
            f_4ED00_z8(b, c);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FB78);

extern s16 D_8008BE6C_h asm("D_8008BE6C");
extern s32 D_8008BF00_w asm("D_8008BF00");
void f_51F24_v(void) asm("func_80051F24");
void func_8004FC98(u16 *arg0) {
    D_8008BE6C_h = 0;
    D_8008BF00_w = *arg0 << 16;
    f_51F24_v();
}

extern s16 D_8008BE6C_x asm("D_8008BE6C");
extern s32 D_8008BE68_x asm("D_8008BE68");
extern s32 D_8008BF00_x asm("D_8008BF00");
void func_8004FCCC(s32 *arg0) {
    s32 d = 1;
    s32 q;
    if (arg0[0] != 0) {
        d = arg0[0];
    }
    q = ((*(u16 *)(arg0 + 1) << 16) - D_8008BF00_x) / d;
    D_8008BE6C_x = d;
    D_8008BE68_x = q;
}

void func_8004FD34(s32 *arg0) {
    s32 d = 1;
    s32 t;
    s32 q;
    if (arg0[0] != 0) {
        d = arg0[0];
    }
    q = ((*(u16 *)(arg0 + 2) << 16) - (t = *(u16 *)(arg0 + 1) << 16)) / d;
    D_8008BE6C_x = d;
    D_8008BF00_x = t;
    D_8008BE68_x = q;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FDA4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FE8C);

typedef struct {
    u8 pad0[0x28];
    u32 unk28;
    u8 pad2C[0xA0 - 0x2C];
    s16 unkA0;
    u8 padA2[0xF0 - 0xA2];
    s16 unkF0;
    u8 padF2[0x10C - 0xF2];
    u32 unk10C;
    u8 pad110[0x124 - 0x110];
} S5000C;
extern S5000C D_80089E40_x[] asm("D_80089E40");
extern u32 D_8008BEB0_e asm("D_8008BEB0");
void func_8005000C(u16 *arg0) {
    u32 bit = 0x1000;
    u32 m = D_8008BEB0_e;
    u32 i;
    S5000C *p = D_80089E40_x;
    for (i = 0; i < 12; i++, p++, bit <<= 1) {
        if ((m & bit) && !(p->unk28 & 0x2000000)) {
            p->unkF0 = (*arg0 & 0x7F) << 8;
            p->unkA0 = 0;
            p->unk10C |= 3;
        }
    }
}

extern s32 D_8008BEB0[];
extern Unk80051F24 D_80089E40[];

void func_80050088(s32 *arg0) {
    u32 mask = 0x1000;
    s32 active = D_8008BEB0[0];
    u32 i;
    Unk80051F24 *ch = D_80089E40;
    s16 n;
    for (i = 0; i < 12; i++, ch++, mask <<= 1) {
        if ((active & mask) && !(ch->unk28 & 0x2000000)) {
            n = 1;
            if (arg0[0] != 0) {
                n = arg0[0];
            }
            ch->unkF2 = (s16)(((((u16 *)arg0)[2] & 0x7F) << 8) - ch->unkF0) / n;
            ch->unkA0 = n;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050150);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050230);

typedef struct {
    u8 pad0[0x28];
    u32 unk28;
    u8 pad2C[0x80 - 0x2C];
    s16 unk80;
    s16 unk82;
    u8 pad84[0x10C - 0x84];
    u32 unk10C;
    u8 pad110[0x124 - 0x110];
} S503A8;
extern S503A8 D_80089E40_w[] asm("D_80089E40");
extern u32 D_8008BEB0_d asm("D_8008BEB0");
void func_800503A8(u8 *arg0) {
    u32 bit = 0x1000;
    u32 m = D_8008BEB0_d;
    u32 i;
    S503A8 *p = D_80089E40_w;
    for (i = 0; i < 12; i++, p++, bit <<= 1) {
        if ((m & bit) && !(p->unk28 & 0x2000000)) {
            p->unk80 = *arg0 << 8;
            p->unk82 = 0;
            p->unk10C |= 3;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050420);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800504E4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800505C4);

typedef struct {
    u8 pad0[0x28];
    u32 unk28;
    u8 pad2C[0x54 - 0x2C];
    s32 unk54;
    u8 pad58[0x9A - 0x58];
    s16 unk9A;
    u8 pad9C[0x10C - 0x9C];
    u32 unk10C;
    u8 pad110[0x124 - 0x110];
} S5074C;
extern S5074C D_80089E40_t[] asm("D_80089E40");
void func_8005074C(u8 *arg0) {
    s32 i;
    S5074C *p = D_80089E40_t;
    for (i = 12; i != 0; i--, p++) {
        if (!(p->unk28 & 0x2000000)) {
            p->unk54 = *arg0 << 8;
            p->unk9A = 0;
            p->unk10C |= 0x10;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800507A4);

extern s16 D_8008ADCA_t asm("D_8008ADCA");
extern s32 D_8008E394_t asm("D_8008E394");
void func_80050870(s8 *arg0) {
    s32 v = *arg0;
    D_8008ADCA_t = 0;
    D_8008E394_t = v << 16;
}

extern s16 D_8008ADCA_x asm("D_8008ADCA");
extern s32 D_8008AD44_x asm("D_8008AD44");
extern s32 D_8008E394_x asm("D_8008E394");
void func_8005088C(s32 *arg0) {
    s32 d = 1;
    s32 q;
    if (arg0[0] != 0) {
        d = arg0[0];
    }
    q = ((*(s8 *)(arg0 + 1) << 16) - D_8008E394_x) / d;
    D_8008ADCA_x = d;
    D_8008AD44_x = q;
}

void func_800508F4(s32 *arg0) {
    s32 d = 1;
    s32 t;
    s32 q;
    if (arg0[1] != 0) {
        d = arg0[0];
    }
    t = *(s8 *)(arg0 + 1) << 16;
    D_8008E394_x = t;
    q = ((*(s8 *)(arg0 + 2) << 16) - t) / d;
    D_8008ADCA_x = d;
    D_8008AD44_x = q;
}

extern s16 D_8008ADC8_t asm("D_8008ADC8");
extern s32 D_8008E390_t asm("D_8008E390");
void func_80050968(s8 *arg0) {
    s32 v = *arg0;
    D_8008ADC8_t = 0;
    D_8008E390_t = v << 16;
}

extern s16 D_8008ADC8_x asm("D_8008ADC8");
extern s32 D_8008AD40_x asm("D_8008AD40");
extern s32 D_8008E390_x asm("D_8008E390");
void func_80050984(s32 *arg0) {
    s32 d = 1;
    s32 q;
    if (arg0[0] != 0) {
        d = arg0[0];
    }
    q = ((*(s8 *)(arg0 + 1) << 16) - D_8008E390_x) / d;
    D_8008ADC8_x = d;
    D_8008AD40_x = q;
}

void func_800509EC(s32 *arg0) {
    s32 d = 1;
    s32 t;
    s32 q;
    if (arg0[1] != 0) {
        d = arg0[0];
    }
    t = *(s8 *)(arg0 + 1) << 16;
    D_8008E390_x = t;
    q = ((*(s8 *)(arg0 + 2) << 16) - t) / d;
    D_8008ADC8_x = d;
    D_8008AD40_x = q;
}

void f_4E464_a(void *, void *, s32) asm("func_8004E464");
extern u8 D_80087980_u[] asm("D_80087980");
extern void *D_8008BE50_q asm("D_8008BE50");
extern void *D_8008ABF8_q asm("D_8008ABF8");
extern void *D_8008ABF4_q asm("D_8008ABF4");
void func_80050A60(void) {
    f_4E464_a(D_8008BE50_q, D_80087980_u, 0);
    if (D_8008ABF8_q != NULL) {
        f_4E464_a(D_8008ABF8_q, D_8008ABF4_q, 0);
    }
}

void func_80050AB0(s32 *arg0) {
    f_4E464_a(D_8008BE50_q, D_80087980_u, *arg0);
    if (D_8008ABF8_q != NULL && *arg0 != 0) {
        f_4E464_a(D_8008ABF8_q, D_8008ABF4_q, *arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050B18);

void f_4ED00_a(void *, void *) asm("func_8004ED00");
void func_8004ED48(void);
extern s32 D_8008E39C_w asm("D_8008E39C");
void func_80050BF4(void) {
    D_8008E39C_w = 1;
    f_4ED00_a(D_8008BE50_q, D_80087980_u);
    if (D_8008ABF8_q != NULL) {
        f_4ED00_a(D_8008ABF8_q, D_8008ABF4_q);
    }
    func_8004ED48();
}

void func_80050C54(void) {
    D_8008E39C_w = 2;
    f_4ED00_a(D_8008BE50_q, D_80087980_u);
    if (D_8008ABF8_q != NULL) {
        f_4ED00_a(D_8008ABF8_q, D_8008ABF4_q);
    }
    func_8004ED48();
}

typedef struct { u8 pad[0x10C]; u32 unk10C; u8 pad2[0x124 - 0x110]; } S50CB4;
extern S50CB4 D_80087980_s[] asm("D_80087980");
extern s32 D_8008BF04_w asm("D_8008BF04");
void func_80050CB4(s32 *arg0) {
    u32 i;
    S50CB4 *p;
    D_8008BF04_w = *arg0;
    for (i = 0, p = D_80087980_s; i < 32; i++, p++) {
        p->unk10C |= 3;
    }
}

extern u8 *D_8008BE50_u asm("D_8008BE50");
void func_80050CF4(u16 *arg0) {
    *(u16 *)(D_8008BE50_u + 0x70) = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050D08);

extern S503A8 D_80087980_r[] asm("D_80087980");
extern u32 D_8008E398_s[] asm("D_8008E398");
extern u32 D_8008E404_s asm("D_8008E404");
void func_80050DF8(void) {
    u32 m;
    u32 bit;
    S503A8 *p;
    if (*(u32 *)(D_8008BE50_q + 0x20) != 0) {
        m = *(u32 *)(D_8008BE50_q + 0x20);
        bit = 1;
        p = D_80087980_r;
        do {
            if (m & bit) {
                m &= ~bit;
                p->unk10C |= 0x2B13;
            }
            bit <<= 1;
            p++;
        } while (m != 0);
        {
            u8 *b = D_8008BE50_q;
            u32 t = *(u32 *)(b + 0x20);
            *(u32 *)(b + 0x20) = 0;
            *(u32 *)(b + 4) = t;
        }
        D_8008E398_s[2] |= 0x100;
    }
    D_8008E404_s &= ~1;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050E94);

extern u32 D_8008BEC0_r asm("D_8008BEC0");
extern u32 D_8008BEB0_r[] asm("D_8008BEB0");
extern u32 D_8008E398_r[] asm("D_8008E398");
extern u32 D_8008E404_r asm("D_8008E404");
void func_80050FB0(void *arg0) {
    u32 m;
    u32 bit;
    S503A8 *p;
    if (D_8008BEC0_r != 0) {
        m = D_8008BEC0_r;
        bit = 0x1000;
        p = D_80089E40_w;
        do {
            if (m & bit) {
                m &= ~bit;
                p->unk10C |= 0x2B13;
            }
            bit <<= 1;
            p++;
        } while (m != 0);
        m = D_8008BEB0_r[4];
        D_8008BEB0_r[4] = 0;
        D_8008BEB0_r[0] |= m;
        D_8008E398_r[2] |= 0x100;
    }
    D_8008E404_r &= ~2;
}

extern s32 D_8008E3A8_a[] asm("D_8008E3A8");
void f_4BE28_a(s32, s32) asm("func_8004BE28");
void f_4BDE0_a(s32, s32, s32, s32) asm("func_8004BDE0");
void func_80051044(void) {
    s32 *s = D_8008E3A8_a;
    if (s[3] != 0) {
        f_4BE28_a(s[4], 0);
        f_4BE28_a(s[4] + 1, 0);
        f_4BDE0_a(s[4], 0, 0, 0);
        f_4BDE0_a(s[4] + 1, 0, 0, 0);
    }
}

void func_800510C0(void) {
    s32 *s = D_8008E3A8_a;
    if (s[3] != 0) {
        s32 v;
        f_4BE28_a(s[4], s[22]);
        f_4BE28_a(s[4] + 1, s[22]);
        v = (s[16] << 15) >> 16;
        f_4BDE0_a(s[4], v, 0, 0);
        f_4BDE0_a(s[4] + 1, 0, v, 0);
    }
}

extern s32 D_80089E08[];
extern Unk80051F24 D_80089E40[];
extern s32 D_8008BEB0[];
void func_80050088(s32 *);
void func_80051154(s32 *arg0) {
    u32 i;
    for (i = 0; i < 12; i++) {
        D_80089E08[i] = (s16)D_80089E40[i].unkF0 >> 8;
    }
    arg0[1] = 0;
    func_80050088(arg0);
    if (D_8008BEB0[0] != 0) {
        D_8008E398[0] |= 0x10000;
    }
}

extern s32 D_80089E08[];
extern Unk80051F24 D_80089E40[];
extern s32 D_8008BEB0[];

void func_800511D0(s32 *arg0) {
    u32 mask;
    s32 active;
    u32 i;
    Unk80051F24 *ch;
    s32 *p;
    s16 n;
    D_8008E398[0] &= ~0x10000;
    if (D_8008BEB0[4] != 0) {
        D_8008E398[0] &= ~0x10000;
        func_80050FB0(arg0);
        mask = 0x1000;
        ch = D_80089E40;
        n = 1;
        active = D_8008BEB0[0];
        if (arg0[0] != 0) {
            n = arg0[0];
        }
        for (i = 0; i < 12; i++, ch++, mask <<= 1) {
            if ((active & mask) && !(ch->unk28 & 0x2000000)) {
                ch->unkF2 = (s16)((D_80089E08[i] << 8) + 0x80) / n;
                ch->unkF0 = 0;
                ch->unkA0 = n;
            }
        }
    }
}

void func_800512F4(void) {
}

void func_80051F14(s32 *);
void SpuSetReverb(s32);
void SpuSetReverbModeType(s32);
void func_800512FC(s32 arg0) {
    s32 mode;
    func_80051F14(&mode);
    if (mode != arg0) {
        SpuSetReverb(0);
        SpuSetReverbModeType(arg0 | 0x100);
        SpuSetReverb(1);
    }
}

typedef struct { s32 unk0, unk4, unk8, unkC, unk10, unk14; } A8005134C;
typedef struct { u8 pad0[4]; u16 unk4; u8 pad6[2]; u16 unk8; } P8005134C;
extern s32 D_8006B4E0;
extern A8005134C D_8008BDD0;
extern s32 D_8008BEE0[];
extern s32 D_8008E404;
extern void (*D_8006C16C[])(A8005134C *);
int DisableEvent();
int EnableEvent();
s32 func_8004B280();
s32 func_8005134C(u32 cmd) {
    s32 ret = 0;
    P8005134C *p;
    s32 v;
    A8005134C *a;
    s32 *q;
    DisableEvent(D_8006B4E0);
    cmd &= 0xFF;
    a = &D_8008BDD0;
    switch (cmd) {
    case 0x01:
        D_8008E404 ^= 0x100;
        break;
    case 0x10:
    case 0x12:
    case 0x14:
    case 0x19:
    case 0x1A:
        q = D_8008BEE0;
        if (func_8004B280(q[0]) == 0) {
            ret = q[0];
            if (D_8008BE50->unk6E != ((P8005134C *)ret)->unk4 || (D_8008ABF8 != NULL && D_8008ABF8->unk6E != D_8008BE50->unk6E)) {
                if (cmd != 0x19) {
                    func_800512FC(((P8005134C *)ret)->unk8);
                }
                a->unk0 = ret;
                a->unk8 = ((P8005134C *)ret)->unk4;
                switch (cmd) {
                case 0x14:
                    a->unkC = q[1] != 0 ? q[1] | 1 : -1;
                    break;
                case 0x12:
                    a->unkC = q[1];
                    break;
                case 0x19:
                    a->unk10 = q[1];
                    break;
                case 0x1A:
                    a->unk10 = q[1];
                    a->unk14 = q[2];
                    break;
                }
                ret = ((P8005134C *)ret)->unk4;
            } else {
                cmd = 0;
                ret = 0;
            }
        } else {
            cmd = 0;
            ret = -1;
        }
        break;
    case 0xD8:
        a->unk0 = D_8008BEE0[0];
        D_8006C16C[0xD0](a);
        cmd = 0xD4;
        break;
    case 0xD9:
        a->unk0 = D_8008BEE0[0];
        a->unk4 = D_8008BEE0[1];
        D_8006C16C[0xD1](a);
        cmd = 0xD5;
        break;
    case 0xDA:
        a->unk0 = D_8008BEE0[0];
        a->unk4 = D_8008BEE0[1];
        a->unk8 = D_8008BEE0[2];
        D_8006C16C[0xD2](a);
        cmd = 0xD6;
        break;
    case 0x99:
        D_8006C16C[0x9B](a);
        D_8006C16C[0x9D](a);
        cmd = 0x9F;
        break;
    case 0x98:
        D_8006C16C[0x9A](a);
        D_8006C16C[0x9C](a);
        cmd = 0x9E;
        break;
    default:
        a->unk0 = D_8008BEE0[0];
        a->unk4 = D_8008BEE0[1];
        a->unk8 = D_8008BEE0[2];
        a->unkC = D_8008BEE0[3];
        a->unk10 = D_8008BEE0[4];
        a->unk14 = D_8008BEE0[5];
        break;
    }
    D_8006C16C[cmd](a);
    EnableEvent(D_8006B4E0);
    return ret;
}
