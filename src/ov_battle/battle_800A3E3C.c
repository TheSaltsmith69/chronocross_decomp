#include "common.h"

/* ---- shared declarations ---- */
typedef struct {
    u8 * p; u8 pad0[0x48]; u32 w4C; u8 pad1[0x4]; u32 w54; u32 w58;
    u32 w5C; u8 pad2[0x6]; s16 h66; u8 pad2b[0x4]; u8 b6C; u8 pad3[0x1]; u8 b6E; u8 b6F;
    u8 b70; u8 b71; u8 pad4[0x2]; u16 h74; u8 pad5[0x6]; s16 h7C; s16 h7E; u8 pad5b[0x1]; u8 b81;
    u8 pad6[0x1]; u8 b83; u8 b84; u8 b85;
} S800DDC28;
extern S800DDC28 D_800DDC28;
typedef struct {
    u8 pad0[0x6B]; u8 b6B; u8 pad1[0x7A]; u8 bE6; u8 bE7; u8 bE8;
    u8 pad2[0x3]; u8 bEC; u8 bED; u8 bEE; u8 bEF; u8 bF0;
    u8 bF1; u8 bF2; u8 bF3; u8 bF4; u8 bF5; u8 bF6;
    u8 bF7; u8 pad3[0x2]; u8 bFA; u8 pad3b[0x5]; u8 b100; u8 b101; u8 pad4[0x1]; u8 b103; u8 pad4b[0x5]; u8 b109; u8 b10A;
    u8 pad5[0x5]; u16 h110; u8 b112; u8 pad6[0x2]; u8 b115; s16 h116; u8 b118; u8 b119;
    u8 b11A; u8 b11B; u8 pad8[0x7]; u8 b123; u8 pad9[0x4]; u8 b128[7]; u8 b12F; u8 b130; u8 pad9b[0x3]; u8 b134; u8 pad9c[0xE]; u8 b143;
    u8 pad10[0x8]; u16 h14C;
} S800DAF20;
extern S800DAF20 D_800DAF20;
/* 0x30-byte records, indexed by D_800DDC96 / D_800DDC97 */
typedef struct { u8 pad0[0xE]; u16 hE; s16 h10; u16 h12; u32 w14; u8 pad1[0x8]; u32 w20; u8 pad1b[0x6]; u16 h2A; u8 pad2[0x4]; } S800DDD38;
extern S800DDD38 D_800DDD38[];
extern u8 D_800DDC96;
extern u8 D_800DDC97;
extern u8 *D_800DDB30;
extern u8 D_800D9624[];
typedef struct {
    u16 h0; u8 b2; u8 pad1[0x1]; u8 b4; u8 b5; u8 b6; u8 pad2[0x13]; u8 b1A; u8 pad3[0x11];
    u8 b2C;
} S800DA980;
extern S800DA980 D_800DA980;
extern s32 D_800DA620;
extern u8 *D_80086FB4;
void func_80042928(s16, s16, s32, s32, void *, s32, s32);
extern s32 D_800D9B48[];
extern s32 D_800D9C78;
extern s32 D_800D86FC;
void *func_800309D0(s32);
extern u8 D_800DAE54;
s32 func_8003D8F4(s32, s32, s32);
void func_8003DB78(char *);
/* 0x438-byte records */
typedef struct {
    u8 pad0[0x1]; u8 b1; u8 pad0x[0xA6]; u32 wA8; u32 wAC; u32 wB0; u32 wB4; s16 hB8; u8 pad0c[0x12]; u16 hCC[80]; s16 h16C; s16 h16E; u8 pad0a[0x10]; s32 w180; u8 pad0e[0xC]; u8 *p190; u8 pad0d[0xA]; s16 h19E; u8 pad0b[0x10]; u32 w1B0;
    u32 w1B4; u8 pad1[0x4]; s16 h1BC; u8 pad2[0x1]; u8 b1BF; u8 pad2c[0x8]; u16 h1C8; s16 h1CA; u16 h1CC; u8 pad2b[0x1]; u8 b1CF; u8 pad2d[0x4]; u16 h1D4[80]; u8 pad2e[0x1C0]; u8 b434; u8 b435; u8 pad3[0x2];
} S800DB078;
typedef struct { s16 h0; s16 h2; u8 pad1[0x20]; u8 *p24; u8 pad1b[0x7]; u8 b2F; u8 pad1c[0x2]; s16 h32; u8 pad2[0x1F]; u8 b53; u8 pad2b[0x3E4]; } S800DB1E4;
extern S800DB1E4 D_800DB1E4[];
extern S800DB078 D_800DB078[];
/* the same 0x438-byte records, with the 0x16C..0x1D4 block as its own struct
 * (code takes &D_800DB078[i].s and reads fields through it) */
typedef struct {
    s16 h0; s16 h2; u8 pad0[0x10]; s32 w14; u8 pad1[0xC]; u8 *p24; u8 pad2[0xA]; s16 h32;
    u8 pad3[0x10]; u32 w44; u32 w48; u8 pad4[0x1C];
} S800DB078_16C;
typedef struct {
    u8 pad0[0x1]; u8 b1; u8 pad1[0x12]; u16 h14; u8 pad2[0xA]; u16 h20; u8 pad3[0xB]; u8 b2D;
    u8 pad4[0x7A]; u32 wA8; u8 pad5[0x20]; u16 hCC[80]; S800DB078_16C s; u16 h1D4[80];
    u8 pad6[0x1C0]; u8 b434; u8 b435; u8 pad7[0x2];
} S800DB078x;
extern S800DB078x D_800DB078x[] asm("D_800DB078");
/* error report: func_80029DD8(D_800A3364 format, function name, value) */
extern char D_800A3364[];
void func_80029DD8(char *, char *, s32);
extern s32 D_800A0F04;
extern s32 D_800A0F08;
extern u8 *D_1F800014;
typedef struct { u16 a, b, c, d; u8 pad[5]; u8 bD, bE, bF; u8 pad2[0x10]; u16 h20; u8 pad3[2]; } SAC50;
extern SAC50 D_800DAC50[];
typedef struct { u8 pad[4]; u8 b4; u8 b5; u8 b6; u8 pad2; } SA648;
extern SA648 D_800DA648[];
extern u8 D_800DDF4C;
/* ---- end shared declarations ---- */

s32 func_800A40F4(s32, u16, s32, s32);
s32 func_800A4354(s32, u16, s32, s32);
s32 func_800A45E0(s32, u16, s32, s32);
s32 func_800A487C(s32, u16, s32, s32);
s32 func_800A4ADC(s32, s32, s32);
s32 func_800A5C90(s32, s32, s32);
s32 func_800A7018(s32, s32, s32);
s32 func_800A77FC(s32, s32, s32);
void *memset(void *, s32, s32);
extern u8 D_8006B30C;
extern u16 D_800D8688;
extern u16 D_800D9AA8;
extern s16 D_800D9AAA;
extern s16 D_800D9AAC;
extern s32 D_800D9AB0;

void func_800A3E3C(u8 *arg0, s32 arg1) {
    u8 buf[8];
    u8 c[4];
    u16 f;

    memset(buf, 0, 8);
    f = *(u16 *)(arg0 + 0x12);
    if (!(f & 1)) {
        D_800D9AAA = f & 2;
        D_800D9AAC = 0;
        c[0] = arg0[0x14];
        c[1] = arg0[0x15];
        c[2] = arg0[0x16];
        D_800D9AA8 = D_800D8688;
        D_800D9AB0 = *(s32 *)c;
        if (D_8006B30C != 0) {
            func_800A487C(*(s32 *)arg0, *(u16 *)(arg0 + 0x10), *(s32 *)(arg0 + 4), arg1);
            if (*(u16 *)(arg0 + 0x12) & 0x8000) {
                func_800A77FC(*(s32 *)(arg0 + 8), arg1, (s32)buf);
            } else {
                func_800A5C90(*(s32 *)(arg0 + 8), arg1, (s32)buf);
            }
            func_800A45E0(*(s32 *)arg0, *(u16 *)(arg0 + 0x1E), *(s32 *)(arg0 + 0x20), arg1);
            return;
        }
        func_800A40F4(*(s32 *)arg0, *(u16 *)(arg0 + 0x10), *(s32 *)(arg0 + 4), arg1);
        if (*(u16 *)(arg0 + 0x12) & 0x8000) {
            func_800A7018(*(s32 *)(arg0 + 8), arg1, (s32)buf);
        } else {
            func_800A4ADC(*(s32 *)(arg0 + 8), arg1, (s32)buf);
        }
        func_800A4354(*(s32 *)arg0, *(u16 *)(arg0 + 0x1E), *(s32 *)(arg0 + 0x20), arg1);
    }
}

s32 func_800A40F4(s32, u16, s32, s32);
s32 func_800A4354(s32, u16, s32, s32);
s32 func_800A45E0(s32, u16, s32, s32);
s32 func_800A487C(s32, u16, s32, s32);
s32 func_800A4ADC(s32, s32, s32);
s32 func_800A5C90(s32, s32, s32);
s32 func_800A7018(s32, s32, s32);
s32 func_800A77FC(s32, s32, s32);
extern u8 D_8006B30C;
extern u16 D_800D8688;
extern u16 D_800D9AA8;
extern s16 D_800D9AAA;
extern s16 D_800D9AAC;
extern s32 D_800D9AB0;

void func_800A3FA4(u8 *arg0, s32 arg1, s32 arg2) {
    u8 c[4];

    D_800D9AAC = 0;
    D_800D9AAA = *(u16 *)(arg0 + 0x12) & 2;
    c[0] = arg0[0x14];
    c[1] = arg0[0x15];
    c[2] = arg0[0x16];
    D_800D9AA8 = D_800D8688;
    D_800D9AB0 = *(s32 *)c;
    if (D_8006B30C != 0) {
        func_800A487C(*(s32 *)arg0, *(u16 *)(arg0 + 0x10), *(s32 *)(arg0 + 4), arg1);
        if (*(u16 *)(arg0 + 0x12) & 0x8000) {
            func_800A77FC(*(s32 *)(arg0 + 8), arg1, arg2);
        } else {
            func_800A5C90(*(s32 *)(arg0 + 8), arg1, arg2);
        }
        func_800A45E0(*(s32 *)arg0, *(u16 *)(arg0 + 0x1E), *(s32 *)(arg0 + 0x20), arg1);
        return;
    }
    func_800A40F4(*(s32 *)arg0, *(u16 *)(arg0 + 0x10), *(s32 *)(arg0 + 4), arg1);
    if (*(u16 *)(arg0 + 0x12) & 0x8000) {
        func_800A7018(*(s32 *)(arg0 + 8), arg1, arg2);
    } else {
        func_800A4ADC(*(s32 *)(arg0 + 8), arg1, arg2);
    }
    func_800A4354(*(s32 *)arg0, *(u16 *)(arg0 + 0x1E), *(s32 *)(arg0 + 0x20), arg1);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A40F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A4354);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A45E0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A487C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A4ADC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A5C90);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A7018);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A77FC);

void func_800A8048(void **p) {
    func_8003D504((s32)p[0]);
    if (p[1]) {
        func_8003D504((s32)p[1]);
    }
    if (p[8]) {
        func_8003D504((s32)p[8]);
    }
    func_8003D504((s32)p[2]);
    func_8003D504((s32)p);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A80B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A82C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A852C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A8798);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A8D98);

typedef struct N94F4 { struct N94F4 *next; } N94F4;
extern N94F4 *D_800D8690;
void func_80033F20(N94F4 *);
void func_800A94F4(u8 *a) {
    N94F4 *n = (N94F4 *)a;
    N94F4 *p = D_800D8690;
    N94F4 *prev = 0;
    while (p) {
        if (p == n) {
            if (prev) {
                prev->next = n->next;
            } else {
                D_800D8690 = n->next;
            }
        }
        p = p->next;
    }
    func_80033F20(n);
}

extern s16 D_1F800010;
void func_800A94F4(u8 *);
void func_800A9560(u8 *p) {
    s32 v = *(s32 *)(p + 4) - D_1F800010;
    *(s32 *)(p + 4) = v;
    if (v < 0) {
        func_800A94F4(p);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A959C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9838);

extern u8 D_800D868C;
void *func_800309D0(s32);
void func_800A9838_p(u8 *) asm("func_800A9838");
void func_800A9A98(u8 *p) {
    if (func_800309D0(1)) {
        D_800D868C = 1;
    } else {
        D_800D868C = 0;
    }
    func_800A9838_p(p);
}

extern u8 D_800D868C;
void func_800A9838(void);
void func_800A9AE4(void) {
    D_800D868C = 1;
    func_800A9838();
}

u8 func_8003B9A8(u8 *);
extern u8 *D_800DDF38;
u8 *func_80041F6C_a9(s32) asm("func_80041F6C");
u8 *func_80034024(u8 *);
void func_8003B210(u8 *);
void func_80043B30(u8 *);
typedef struct { s16 a[3]; } S6A9;
void func_800A9B0C(u8 *a0) {
    if (func_8003B9A8(a0)) {
        u8 *p = func_80034024(func_80041F6C_a9(func_8004227C(0xA, 0x326D6164, *(s32 *)(D_800DDF38 + 8) & 0x3F)));
        if (p) {
            *(s32 *)(p + 0) = 0;
            *(s32 *)(p + 4) = 0;
            *(s32 *)(p + 8) = 0;
            *(s16 *)(p + 0x50) = 0x1000;
            *(s16 *)(p + 0x52) = 0x1000;
            *(s16 *)(p + 0x54) = 0x1000;
            *(s32 *)(p + 0) = *(s32 *)(a0 + 0);
            *(s32 *)(p + 4) = *(s32 *)(a0 + 4);
            *(s32 *)(p + 8) = *(s32 *)(a0 + 8);
            *(s32 *)(p + 0x1C) = *(s32 *)(a0 + 0x1C);
            *(s16 *)(p + 0x7A) = *(s16 *)(a0 + 0x7A);
            *(S6A9 *)(p + 0x68) = *(S6A9 *)(a0 + 0x68);
            func_8003B210(p);
        }
    }
    func_80043B30(a0);
}

void func_8003B134(u8 *, void (*)(u8 *));
extern s16 D_1F800010_s asm("D_1F800010");
void func_800A9BF0(u8 *a0) {
    s16 t = *(s16 *)(a0 + 0x82);
    if (t > 0) {
        t -= D_1F800010_s;
        if (t < 0) t = 0;
        *(s16 *)(a0 + 0x82) = t;
        return;
    }
    if (func_8003B9A8(a0)) {
        u8 *p = func_80034024(func_80041F6C_a9(func_8004227C(0xA, 0x316D6164, *(s32 *)(D_800DDF38 + 8) & 0x3F)));
        if (p) {
            *(s32 *)(p + 0) = *(s32 *)(a0 + 0);
            *(s32 *)(p + 4) = *(s32 *)(a0 + 4);
            *(s32 *)(p + 8) = 0;
            *(s16 *)(p + 0x50) = 0x1000;
            *(s16 *)(p + 0x52) = 0x1000;
            *(s16 *)(p + 0x54) = 0x1000;
            *(s32 *)(p + 0x1C) = *(s32 *)(a0 + 0x1C);
            *(s16 *)(p + 0x7A) = *(s16 *)(a0 + 0x7A);
            *(S6A9 *)(p + 0x68) = *(S6A9 *)(a0 + 0x68);
            func_8003B134(p, func_800A9B0C);
            func_8003B210(p);
        }
    }
    func_80043B30(a0);
}

s32 func_8004208C(s32, s32, s32);
u8 *func_80041F6C_(s32) asm("func_80041F6C");
void func_8003BEC4(u8 *, s32);
void func_8002CA14(s32);
extern u8 D_8006B440;
extern u8 D_800D8698;
void func_800A9D10(void) {
    s32 h;
    func_8002CA14(0x30697462);
    h = 0;
    while ((h = func_8004208C(h, 10, 0x30697462)) != 0) {
        u8 *e = func_80041F6C_(h);
        if (!(*(s32 *)(e + 0x10) & 1)) {
            func_8003BEC4(e, 1);
        }
    }
    D_8006B440 = 1;
    D_800D8698 = 0;
}

s32 func_8004208C(s32, s32, s32);
u8 *func_80041F6C_(s32) asm("func_80041F6C");
void func_8003BEC4(u8 *, s32);
void func_8002CA80(s32);
extern u8 D_8006B440;
void func_800A9D9C(void) {
    s32 h;
    func_8002CA80(0x30697462);
    h = 0;
    while ((h = func_8004208C(h, 10, 0x30697462)) != 0) {
        u8 *e = func_80041F6C_(h);
        if (*(s32 *)(e + 0x10) & 1) {
            func_8003BEC4(e, 0);
        }
    }
    D_8006B440 = 0;
}

s32 func_800A9E1C(void) {
    return 0;
}

extern s32 D_800D9AE8[];
s32 *func_800A9E24(void) {
    if (D_800D9AE8[0] == 0) {
        return 0;
    }
    return D_800D9AE8;
}

extern s32 D_800D9AB8[];
s32 *func_800A9E48(void) {
    if (D_800D9AB8[0] == 0) {
        return 0;
    }
    return D_800D9AB8;
}

void func_8003F884_(void *, s32) asm("func_8003F884");
void func_800A9E6C(s32 a0, s32 a1) {
    s32 *s = D_800D9AE8;
    func_8003F884_(s, 0x30);
    D_800D9AE8[0] = a0;
    if (a1) {
        s[5] |= 0x80;
    } else {
        s[5] &= ~0x80;
    }
}

void func_8003F884_(void *, s32) asm("func_8003F884");
void func_800A9EE0(s32 a0, s32 a1) {
    s32 *s = D_800D9AB8;
    func_8003F884_(s, 0x30);
    D_800D9AB8[0] = a0;
    if (a1) {
        s[5] |= 0x80;
    } else {
        s[5] &= ~0x80;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9F54);

extern s8 D_8006B47C;
extern s8 D_8006B47D;
void VSync(s32);
void func_800AA188(void) {
    s32 m;
    if (D_8006B47C == 0 || (m = D_8006B47D) == 1) {
        m = 0;
    }
    VSync(m);
}

extern s32 D_800D8694;
void func_80041C0C(s32);
void func_800AA1CC(void) {
    if (D_800D8694) {
        func_80041C0C(D_800D8694);
        D_800D8694 = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA204);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA380);

s32 func_8002A1DC(u8 *, s32);
s32 func_8002A228(s32);
s32 func_8002AAAC(s32, s32);
s32 func_8002AD1C(u8 *, s32, s32);
s32 func_8002BC6C();
s32 func_8002E660(s32);
s16 *func_80030968();
u8 *func_8003099C(s32);
s32 func_80041AEC(s32);
s32 func_80041F0C(s32, s32);
s32 func_80042004(s32);
s32 func_800AA204();
s32 func_800B600C();
extern s32 D_8006AF54;
extern u8 D_800D9B18;

void func_800AA544(void) {
    s32 key;
    s32 h;
    s32 e;
    s32 i;
    u8 c;

    if (D_8006AF54 != 0) {
        key = 0x30306863;
        key += D_800D9B18 << 24;
        func_80041AEC(D_8006AF54);
        i = 1;
        func_80042004(D_8006AF54);
        func_8002A228(key);
        func_800AA204();
        h = func_80041F0C(0x10, key);
        while (func_8003099C(i) != NULL) {
            e = func_8002AAAC(h, 1);
            func_8002AD1C(func_80041F6C(e), i, 0);
            func_8002A1DC(func_80041F6C(e), *(s32 *)(e + 4));
            i++;
        }
        c = func_8003099C(0)[0x2F];
        if (c != 0x3F && c != 0) {
            func_800B600C();
        }
    }
    if (func_80030968() != NULL && *func_80030968() == 2) {
        func_8002E660(*(s16 *)(func_8003099C(0) + 0xE) - 1);
        if (D_8006AF54 == 0) {
            func_8002BC6C();
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA698);

extern u8 D_8006B3F4;
extern s32 D_800A125C;
extern s32 D_800D9B1C;
extern u8 D_803483BC;

void func_800AA7BC(void) {
    s32 i;
    u8 *e;
    u8 *o;
    u8 *p;

    if (D_8006B3F4 == 0 || D_803483BC == 0) {
        func_8002C130();
    }
    e = (u8 *)func_8003099C(0);
    if (func_80030968() != NULL && *(s16 *)func_80030968() == 2) {
        D_800D8688 = 100;
        D_800A125C = D_800D9B1C;
        if (D_800D8698 == 0) {
            func_8004A87C(0, 0x60, 0x7F);
        }
        if (e != NULL) {
            func_8009B0D8(*(u8 **)e, 0xB, 0);
        }
    }
    i = 0;
    if (*(s16 *)func_80030968() == 2) {
        while ((e = (u8 *)func_80030934(i)) != NULL) {
            o = *(u8 **)e;
            if (e[0x17] & 1) {
                *(u16 *)(o + 0x7E) = *(u16 *)(o + 0x7E) | 0x200;
            } else {
                *(u16 *)(o + 0x7E) = *(u16 *)(o + 0x7E) & 0xFDFF;
            }
            if (*(s32 *)(o + 0x1FC) != 0) {
                func_800957BC(o);
            }
            if (!(*(s32 *)(e + 0x14) & 1)) {
                func_8009B0D8(o, 1, 0);
            }
            p = *(u8 **)(o + 0xBC);
            if (p != NULL) *(s16 *)(p + 0x26) = 0;
            p = *(u8 **)(o + 0xE0);
            if (p != NULL) *(s16 *)(p + 0x26) = 0;
            i++;
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA94C);
