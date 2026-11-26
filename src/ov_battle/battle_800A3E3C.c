#include "common.h"

/* ---- shared declarations ---- */
typedef struct {
    u8 * p; u8 pad0[0x50]; u32 w54; u8 pad1[0x19]; u8 b71; u8 pad2[0x2];
    u16 h74;
} S800DDC28;
extern S800DDC28 D_800DDC28;
typedef struct {
    u8 pad0[0x6B]; u8 b6B; u8 pad1[0x7A]; u8 bE6; u8 bE7; u8 bE8;
    u8 pad2[0x3]; u8 bEC; u8 bED; u8 bEE; u8 bEF; u8 bF0;
    u8 bF1; u8 bF2; u8 bF3; u8 bF4; u8 bF5; u8 bF6;
    u8 bF7; u8 pad3[0x9]; u8 b101; u8 pad4[0x8]; u8 b10A; u8 pad5[0x5];
    u16 h110; u8 pad6[0x6]; u8 b118; u8 pad7[0x1]; u8 b11A; u8 pad8[0x8];
    u8 b123; u8 pad9[0x1F]; u8 b143;
} S800DAF20;
extern S800DAF20 D_800DAF20;
/* 0x30-byte records, indexed by D_800DDC96 / D_800DDC97 */
typedef struct { u8 pad0[0x10]; s16 h10; u16 h12; u8 pad1[0x1C]; } S800DDD38;
extern S800DDD38 D_800DDD38[];
extern u8 D_800DDC96;
extern u8 D_800DDC97;
extern u8 *D_800DDB30;
extern u8 D_800D9624[];
/* ---- end shared declarations ---- */

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A3E3C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A3FA4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A40F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A4354);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A45E0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A487C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A4ADC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A5C90);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A7018);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A77FC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A8048);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A80B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A82C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A852C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A8798);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A8D98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A94F4);

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

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9A98);

extern u8 D_800D868C;
void func_800A9838(void);
void func_800A9AE4(void) {
    D_800D868C = 1;
    func_800A9838();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9B0C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9BF0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9D10);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9D9C);

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

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9E6C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800A9EE0);

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

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA544);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA698);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA7BC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA94C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AA9DC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AAB98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AB030);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AB82C);

s32 func_800ABCEC(u8 *p) {
    *(s32 *)(p + 0x108) += 2;
    return 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ABD04);

void func_80096180(s32);
void func_800961A4(s32, s32);
s32 func_800ABD4C(s32 a0) {
    func_80096180(a0);
    func_800961A4(a0, 0x1C);
    return 1;
}

void func_800ABD80(void) {
}

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3308);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ABD88);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ABE24);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ABEB0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ABF4C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ABFE8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC0F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC1D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC2F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC484);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC60C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC788);

s32 func_800AC8A4(void) {
    return 5;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC8AC);

s32 func_800AC93C(void) {
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AC944);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ACADC);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3364);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3394);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ACDB0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ACE44);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ACFB0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD018);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD150);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD288);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD36C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD564);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD6A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD880);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AD9D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ADBEC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ADD8C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800ADF14);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE02C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE11C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE1C0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE264);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE2C0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE31C);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A343C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE3FC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE674);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AE7B0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AEA48);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AEB98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AEC64);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AED98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AEE04);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF024);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF070);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF1D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF3A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF458);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF4F4);

s32 func_800AF688(void) {
    return 3;
}

void func_8009789C(s32, s32, s32);
void func_800AF690(u8 *p) {
    func_8009789C(**(s32 **)(p + 0x10), *(s32 *)(p + 0x14), *(s32 *)(p + 0xC) + 0x1C4);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF6C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF83C);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A34D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF8B8);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3508);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AF954);

s32 func_800AFA2C(void) {
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFA34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFAC8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFB5C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFBF4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFC88);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFD1C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFDB0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFE44);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFED8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800AFF6C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0000);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0098);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B012C);

s16 *func_8009AAE0(u8 *, s32);
s32 func_800B0184(u8 *p) {
    s16 *r = func_8009AAE0(p, *(s16 *)(*(u8 **)(p + 0x108) + 2));
    *r = *(u16 *)(p + 0x146);
    return 2;
}

s32 func_800B01C8(u8 *p) {
    *(u16 *)(p + 0x146) = *(u16 *)(*(u8 **)(p + 0x108) + 2);
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B01E4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0268);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B02EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B03B0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0434);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B04B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B053C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B05D0);

extern u16 D_1F800010_u asm("D_1F800010");
void func_800B05D0(u8 *, s32);
void func_800B06D4(u8 *p) {
    s16 v = *(u16 *)(p + 0x12) - D_1F800010_u;
    *(s16 *)(p + 0x12) = v;
    if (v < 0) {
        func_800B05D0(p, 8);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0718);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0828);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B08C8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0910);

void func_800961B8(s32, s32);
s32 func_800B0964(s32 a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    func_800961B8(a0, *(u16 *)(q + 2) | (*(s16 *)(q + 4) << 16));
    return 3;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0998);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0A08);

s32 func_800B0A50(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    *(u16 *)(p + 0x76) = (*(u16 *)(q + 4) << 6) | ((*(u16 *)(q + 2) >> 4) & 0x3F);
    return 3;
}

void func_80096190(s32, s32);
s32 func_800B0A7C(s32 a0) {
    func_80096190(a0, 0x200);
    return 1;
}

void func_800961A4(s32, s32);
s32 func_800B0A9C(s32 a0) {
    func_800961A4(a0, 0x200);
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0ABC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0B10);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0B68);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0BE8);

void func_800989A4(s32, s32);
s32 func_800B0C5C(s32 a0) {
    func_800961A4(a0, 0x400);
    func_800989A4(a0, 0);
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0C94);

void func_80032D78(s32);
s32 func_800B0D40(void) {
    func_80032D78(0);
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0D60);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0E2C);

extern s32 D_800A32DC;
s32 func_800B0ED0(void) {
    D_800A32DC = 0;
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B0EE0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B10D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B12F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B1460);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B1790);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B1940);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B1D0C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B1EA4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B21C8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2268);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2320);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2390);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2548);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B26A4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B26F0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2748);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B282C);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3784);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2A3C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2AD0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2B64);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2C2C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2E1C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B2F28);

s32 func_800B31D0(u8 *p) {
    u8 *r = *(u8 **)(p + 0xB4) + *(s16 *)(*(u8 **)(p + 0x108) + 2) * 0x6C;
    *(s16 *)(r + 0x5C) = *(s16 *)(r + 0x5E) = *(s16 *)(r + 0x60) = 0x1000;
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3214);

s32 func_800B33C0(void) {
    return 3;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B33C8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3460);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B34C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3528);

s32 func_800B3574(u8 *p) {
    if (*(s32 *)(p + 0x10C) == 0) {
        return 0;
    }
    *(s32 *)(p + 0x10C) = 0;
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3594);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3614);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3694);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3714);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3820);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800A3E3C", D_800A3840);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3794);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3860);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3914);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B39B4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3A54);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3B64);

extern u16 D_800D9B20[];
s32 func_800B3D0C(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    D_800D9B20[0] = *(u16 *)(q + 2);
    D_800D9B20[1] = *(u16 *)(q + 4);
    D_800D9B20[2] = *(u16 *)(q + 6);
    D_800D9B20[3] = *(u16 *)(q + 8);
    return 5;
}

extern u16 D_800D9B28[];
s32 func_800B3D4C(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    D_800D9B28[0] = *(u16 *)(q + 2);
    D_800D9B28[1] = *(u16 *)(q + 4);
    D_800D9B28[2] = *(u16 *)(q + 6);
    D_800D9B28[3] = *(u16 *)(q + 8);
    return 5;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3D8C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3E58);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B3F7C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4058);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B409C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B417C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B41EC);

extern s32 D_800D9B3C;
void func_8009C944(u8 *);
void func_8009C920(s32, u8 *);
void func_800B4280(u8 *p) {
    func_8009C944(p);
    func_8009C920(D_800D9B3C, p);
    *(s32 *)(p + 8) = 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B42B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4354);

void func_800B4434(u8 *p, s32 i) {
    p += i * 2;
    *(s16 *)(p + 0x1A8) = -1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4448);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4614);

void func_800B4448(s32, s32);
s32 func_800B46C0(s32 a0) {
    func_800B4448(a0, 0);
    return 3;
}

s32 func_800B46E0(s32 a0) {
    func_800B4448(a0, 1);
    return 3;
}

void func_800B4614(s32, s32);
s32 func_800B4700(s32 a0) {
    func_800B4614(a0, 0);
    return 1;
}

void func_800B4614(s32, s32);
s32 func_800B4720(s32 a0) {
    func_800B4614(a0, 1);
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4740);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4A04);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4B34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4D98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B4E88);

s32 func_800B53FC(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    *(s32 *)(p + 0x1B0) = *(u16 *)(q + 2) | (*(s16 *)(q + 4) << 16);
    *(s32 *)(p + 0x1B4) = *(u16 *)(q + 6) | (*(s16 *)(q + 8) << 16);
    return 5;
}

s32 func_800B5434(u8 *p) {
    *(u16 *)(p + 0x1AC) = *(u16 *)(*(u8 **)(p + 0x108) + 2);
    return 2;
}

s32 func_800B5450(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    *(s32 *)(p + 0x1B8) = *(u16 *)(q + 2) | (*(s16 *)(q + 4) << 16);
    return 3;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5474);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B54D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5550);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B55D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5624);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B56BC);

extern s32 D_800D9C78;
extern s32 D_800D9C7C;
void func_800B56FC(void) {
    D_800D9C78 = 0;
    D_800D9C7C = 0;
}

void func_800B5710(void) {
    D_800D9C78 = (D_800D9C78 + 1) & 3;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B572C);

extern s32 D_800D86FC;
void func_8003D504(s32);
void func_800B582C(void) {
    if (D_800D86FC) {
        func_8003D504(D_800D86FC);
        D_800D86FC = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5864);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B59D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5A64);

s32 func_800B5AD4(s32 x) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (x & 1) {
            return i;
        }
        x >>= 1;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5AFC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B5C9C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B600C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B6088);

extern s32 D_800D9C70;
void func_800B6188(void) {
    D_800D9C70 = 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B6194);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B61EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B63B4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B66C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B6940);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B6BE4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B6EDC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B7210);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B72D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B738C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B7898);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B8070);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B81EC);

void func_800B738C(void);
void func_800B7898(void);
void func_800B81EC(void);
void func_800B829C(void) {
    func_800B738C();
    func_800B7898();
    func_800B81EC();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B82CC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B8614);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B89BC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B8AC4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B8BD8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B8C98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B8D74);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B918C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B9248);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B95A0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B98A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B9DA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800B9FB4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA100);

typedef struct { u8 b0[5]; u8 b5; u8 b6; } S800DA980;
extern S800DA980 D_800DA980;
void func_800BA14C(void) {
    D_800DA980.b5 = 1;
    D_800DA980.b6 = 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA164);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA24C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA2C8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA3B0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA418);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA480);

extern u8 D_800DA61C[];
u8 *func_800BA4E8(void) {
    return D_800DA61C;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA4F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA54C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA6EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA780);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BA89C);

S800DDD38 *func_800BAC18(u8 i) {
    if (i == 0xFF) {
        return 0;
    }
    return &D_800DDD38[i];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BAC48);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BB01C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BB320);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BB720);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BB948);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BBF74);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC130);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC274);

extern s32 D_800DAB08[];
extern s32 D_800DA620;
void func_80041F6C(s32);
void func_800BC368(u8 i) {
    s32 v = D_800DAB08[i >> 2];
    D_800DA620 = v;
    func_80041F6C(v);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC3A0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC3F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC450);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC4A0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC4F8);

extern u16 D_800D8D3C[];
u16 func_800BC54C(u8 i) {
    return D_800D8D3C[i];
}

extern u16 D_800D8D3C[];
u16 func_800BC56C(u8 i) {
    return ~D_800D8D3C[i];
}

u16 func_800BC594(u16 m, u8 i) {
    return D_800D8D3C[i] & m;
}

extern u32 D_800D8D5C[];
u32 func_800BC5B4(u8 i) {
    return D_800D8D5C[i];
}

extern u32 D_800D8D5C[];
u32 func_800BC5D4(u8 i) {
    return ~D_800D8D5C[i];
}

u32 func_800BC5F4(u32 m, u8 i) {
    return m & D_800D8D5C[i];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC614);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC6C4);

u32 func_800BC744(u32 *p) {
    u32 n = p[0];
    u32 i;
    for (i = 0; i < n; i++) {
        p[i + 1] = (u32)p + p[i + 1];
    }
    return n;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC77C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC8DC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BC940);

void func_800BCC7C(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BCC84);

void func_800C85DC(void);
void func_800BCC84(void);
void func_800BCD44(void) {
    func_800C85DC();
    func_800BCC84();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BCD6C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BD2BC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BD414);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BD548);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BD598);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BD780);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BD980);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BDACC);

void func_800BDACC(s32, s32, s32, s32, u8, s32, s32, s32, s32);
void func_800BDD54(s32 a0, s32 a1, s32 a2, s32 a3, u8 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    func_800BDACC(a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BDD98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BDDE8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BE098);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BE51C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BE630);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BE688);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BE6E0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BEBEC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BED70);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BEEEC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BF078);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BF4A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BF578);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BF5EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BF660);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BF714);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BFA80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800BFBA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C011C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C04D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C07D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C0A18);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C0B7C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C0D94);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C0EE4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1058);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1228);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C14F8);

void func_800C1058(void);
void func_800C1228(void);
void func_800C3B80(void);
void func_800C1944(void) {
    s32 pad[2];
    D_800DAF20.h110 += 2;
    func_800C1058();
    func_800C1228();
    func_800C3B80();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1988);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C19E8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1B34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1BA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1D08);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1E80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C1FC4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C2044);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C2114);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C21D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C23D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C25D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C2BE0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C303C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3188);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3250);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C32E0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C333C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3A48);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3AFC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3B80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3D98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3E60);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C3F5C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C421C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4500);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C476C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C47C8);

void func_800C4810(void) {
    D_800DDD38[D_800DDC97].h10 = 2;
}

extern u8 D_800DDCA9;
void func_800C47C8(void);
void func_800C483C(void) {
    if (!D_800DDCA9) {
        func_800C47C8();
    }
}

void func_800C4868(void) {
    if (!D_800DDCA9) {
        func_800C4810();
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4894);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4908);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4968);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C49AC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4A68);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4D08);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4D68);

void func_800C4DB0(void) {
    u32 m = D_800DDC28.w54 & 0xE007FFFF;
    if (*(u32 *)(D_800DDC28.p + 0x1C) & m) {
        D_800DDC28.b71 = 1;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C4DE8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C50AC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C52F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C542C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C5658);

void func_800C5658(void);
void func_800C50AC(s32);
void func_800C5964(void) {
    func_800C5658();
    func_800C50AC(1);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C598C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C5ACC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C5CC4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C5D64);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C5F0C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C61A4);

void func_800C61A4(s32);
void func_800C6284(void) {
    func_800C61A4(*(s16 *)(D_800DDC28.p + 0xA));
}

void func_800C62B0(void) {
    func_800C61A4(*(s16 *)(D_800DDC28.p + 0xC));
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C62DC);

void func_800C62DC(s32);
void func_800C6494(void) {
    func_800C62DC(*(s16 *)(D_800DDC28.p + 0x8));
}

void func_800C64C0(void) {
    D_800DDC28.h74 = *(u16 *)(D_800DDC28.p + 0xA);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C64DC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C6528);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C65B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C6670);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C67F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C692C);

void func_800C6B9C(void) {
}

s32 func_800C692C();
u8 func_800C6BA4(void) {
    return func_800C692C(*(s32 *)(D_800DDC28.p + 0x18), *(u32 *)(D_800DDC28.p + 0x1C) & 0xE007FFFF);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C6BDC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C6C4C);

void func_800C6C4C(s32, u32, s32);
void func_800C6CE4(void) {
    func_800C6C4C(*(s32 *)(D_800DDC28.p + 0x18), *(u32 *)(D_800DDC28.p + 0x1C) & 0xE007FFFF, 0);
}

s32 func_800C692C();
u8 func_800C6D20(void) {
    return func_800C692C();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C6D40);

void func_800C6D94(void) {
}

void func_800C6D9C(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C6DA4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C71CC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C7274);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C7300);

void func_800CC358(void);
void func_800C3AFC(void);
void func_800C3A48(void);
void func_800C80B8(void) {
    func_800CC358();
    func_800C3AFC();
    func_800C3A48();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C80E8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C80F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8144);

void func_800C8190(void) {
    D_800DAF20.bE8 = 0;
    D_800DAF20.bE7 = 0;
    D_800DAF20.b6B = 0;
    D_800DAF20.bE6 = 5;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C81B0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C82AC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8338);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8580);

void func_80032D78(s32);
void func_80029F58(s32);
void func_800C85DC(void) {
    func_80032D78(0);
    func_80029F58(0);
}

void func_800AA94C(void);
void func_800B6188(void);
void func_800C8338(void);
void func_800C8604(void) {
    func_800AA94C();
    func_800B6188();
    func_800C8338();
    *(u16 *)(D_800DDB30 + 0xE0) = 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8644);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8748);

void func_800C87C0(void) {
    D_800DAF20.bEE = 0xFF;
    D_800DAF20.bED = 0xFF;
    D_800DAF20.bEC = 0xFF;
    D_800DAF20.bF7 = 0xFF;
    D_800DAF20.bF6 = 0xFF;
    D_800DAF20.bF5 = 0xFF;
    D_800DAF20.bF4 = 0xFF;
    D_800DAF20.bF3 = 0xFF;
    D_800DAF20.bF2 = 0xFF;
    D_800DAF20.bF1 = 0xFF;
    D_800DAF20.bF0 = 0xFF;
    D_800DAF20.bEF = 0xFF;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8800);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8A5C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8BB8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8D64);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8F04);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C8F98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C91FC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C92F0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C99D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C9A94);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C9B7C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C9CE0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C9E40);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800C9EBC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CA270);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CA60C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CA670);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CAB14);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CAB90);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CABDC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CAC98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CB3F0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CB780);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CB9A4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CBA30);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CBAE0);

s32 func_800C9A94(s32, s32);
void func_800BC6C4(s32);
void func_800CBCF4(void) {
    D_800DAF20.b10A = func_800C9A94(D_800DAF20.b101, 0) + 1;
    func_800BC6C4(0x16);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CBD34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CBE20);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CBE90);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CBF84);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC060);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC0A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC0F0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC164);

u8 func_800CC1C0(u8 *s) {
    s32 n = 0;
    while (1) {
        u8 c = *s;
        if (c < 0x20) {
            break;
        }
        if (c >= 0xF8) {
            s++;
        }
        s++;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC1F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC358);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC6B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC9AC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CC9F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD058);

void func_800CD160(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD168);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD1E0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD29C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD31C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD3A4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD418);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD75C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD7E4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD8B4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CD9FC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDA94);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDB04);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDB80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDBEC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDCA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDD00);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDD6C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDDC4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CDE28);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE01C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE0E4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE1C0);

void func_800CE5EC(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE5F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE644);

void func_800CE6FC(void) {
}

void func_800C4DE8(s32);
void func_800C5F0C(void);
void func_800C5ACC(void);
void func_800CE704(void) {
    func_800C4DB0();
    func_800C4DE8(1);
    func_800C5F0C();
    func_800C5ACC();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE73C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE7C8);

void func_800CE878(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CE880);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CEA5C);

void func_800CEB04(void) {
    D_800DDD38[D_800DDC96].h12 = *(u16 *)(D_800DDB30 + 0xDE);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CEB38);

void func_800C64C0(void);
void func_800C5CC4(void);
void func_800CECB4(void) {
    func_800C64C0();
    func_800C5CC4();
}

void func_800C4968(void);
void func_800CECDC(void) {
    func_800C4968();
    D_800DAF20.bEC = 0;
    D_800DAF20.bED = 4;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CED10);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CED70);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CEE10);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CEF34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CF4C0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CF57C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CF67C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CF8C0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CF97C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CF9C8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CFA34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800CFA98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D0508);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D058C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D06A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D09A0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D0A14);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D0B1C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D0BD8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D14EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D1728);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D1AB0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D1C18);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D1D20);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D1DD0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D1E88);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D27FC);

u16 func_800D294C(u8 *p) {
    s32 i;
    s32 j;
    u32 m;
    i = 0;
    m = 0xFF;
    for (; i < 0x20; i++) {
        if ((p + i)[0x40] < m) {
            j = i;
        }
    }
    p[0x80] = j;
    p[0x81] = (p + j)[0x60];
    return *(u16 *)(p + (j << 1));
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D29A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2B78);

u16 func_800D2CEC(u8 *p) {
    s32 i;
    for (i = 1; i < 0x20; i++) {
        if ((p + i)[0x40] == 0xFF) {
            break;
        }
    }
    return i;
}

extern u8 D_800D9624[];
u8 func_800D2D20(s32 a0, u8 *a1) {
    return D_800D9624[*a1];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2D3C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2DC0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2E04);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2EB8);

void func_800D2F44(void) {
}

void func_800D2F4C(void) {
}

void func_800D2F54(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2F5C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D2FB8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3078);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D30E8);

u8 func_800D312C(s32 a0, u8 *a1) {
    u8 *b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = 0;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D316C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D31E8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3264);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D32F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D338C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D33D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3424);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D34A0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D351C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3598);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3620);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D36A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D370C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3798);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D381C);

void func_800D38A0(void) {
}

void func_800D38A8(void) {
}

void func_800D38B0(void) {
}

void func_800D38B8(void) {
}

void func_800D38C0(void) {
}

void func_800D38C8(void) {
}

void func_800D38D0(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D38D8);

void func_800D399C(void) {
}

void func_800D39A4(void) {
}

void func_800D39AC(void) {
}

void func_800D39B4(void) {
}

extern s32 D_800DDFDC;
extern u8 D_800D9624[];
u8 func_800D39BC(s32 a0, u8 *a1) {
    D_800DDFDC = 0x20;
    return D_800D9624[*a1];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D39E4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3AA8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3B28);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3C50);

u8 func_800D3CE0(s32 a0, u8 *a1) {
    D_800DAF20.b143 = 0;
    D_800DAF20.b118 = 0;
    D_800DAF20.b11A = 0xFF;
    D_800DAF20.b123 = 0;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D3D18);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D40C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4138);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4188);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D421C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4288);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4300);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D44D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4570);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4658);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4710);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4804);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D48DC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4A38);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4AD8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4B8C);

void func_800D4C9C(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4CA4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4D34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D4FB8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5014);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5194);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5348);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D53E4);

void func_800D548C(void) {
}

void func_800D5494(void) {
}

void func_800D549C(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D54A4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D55A8);

void func_800D5638(void) {
}

void func_800D5640(void) {
}

void func_800D5648(void) {
}

void func_800D5650(void) {
}

void func_800D5658(void) {
}

void func_800D5660(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5668);

s32 func_800D5668(s32, s32, s32);
u16 func_800D57EC(s32 a0, s32 a1) {
    return func_800D5668(a0, a1, 0);
}

u16 func_800D580C(s32 a0, s32 a1) {
    return func_800D5668(a0, a1, 1);
}

void func_800D582C(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5834);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D58D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5954);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5B74);

void func_800D5C98(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5CA0);

void func_80029F58(s32);
u8 func_800D5D00(s32 a0, u8 *a1) {
    func_80029F58(0);
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5D3C);

void func_80032D78(s32);
u8 func_800D5D9C(s32 a0, u8 *a1) {
    func_80032D78(0);
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5DD8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5E44);

void func_800D5EB0(void) {
}

extern u8 D_800DB064;
u8 func_800D5EB8(s32 a0, u8 *a1) {
    D_800DB064 = a1[1];
    return D_800D9624[a1[0]];
}

extern u8 D_800DAC48;
u8 func_800D5EE0(s32 a0, u8 *a1) {
    D_800DAC48 = a1[1];
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D5F08);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D60C0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6478);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D64B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D651C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D65C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6680);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6738);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6854);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D68FC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D69D4);

void func_800D6A68(void) {
}

void func_800D6A70(void) {
}

void func_800D6A78(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6A80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6AE4);

extern u8 D_8006EBBC;
u8 func_800D6B60(s32 a0, u8 *a1) {
    D_8006EBBC = 1;
    return D_800D9624[a1[0]];
}

u8 func_800D6B88(s32 a0, u8 *a1) {
    D_800DDB30[0x831] = a1[1];
    return D_800D9624[a1[0]];
}

extern u8 D_800DDD31;
u8 func_800D6BB8(s32 a0, u8 *a1) {
    D_800DDD31 = a1[1];
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6BE0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6C40);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6D00);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6DAC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6E88);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6F68);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D6FCC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7090);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7104);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D724C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D72B0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7320);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D737C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D741C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7678);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7748);

void func_800D78F0(void) {
}

void func_800D78F8(void) {
}

void func_800D7900(void) {
}

void func_800D7908(void) {
}

void func_800D7910(void) {
}

void func_800D7918(void) {
}

void func_800D7920(void) {
}

void func_800D7928(void) {
}

void func_800D7930(void) {
}

void func_800D7938(void) {
}

void func_800D7940(void) {
}

void func_800D7948(void) {
}

void func_800D7950(void) {
}

void func_800D7958(void) {
}

void func_800D7960(void) {
}

void func_800D7968(void) {
}

void func_800D7970(void) {
}

void func_800D7978(void) {
}

void func_800D7980(void) {
}

void func_800D7988(void) {
}

void func_800D7990(void) {
}

void func_800D7998(void) {
}

void func_800D79A0(void) {
}

void func_800D79A8(void) {
}

void func_800D79B0(void) {
}

void func_800D79B8(void) {
}

void func_800D79C0(void) {
}

void func_800D79C8(void) {
}

void func_800D79D0(void) {
}

void func_800D79D8(void) {
}

void func_800D79E0(void) {
}

void func_800D79E8(void) {
}

void func_800D79F0(void) {
}

void func_800D79F8(void) {
}

void func_800D7A00(void) {
}

void func_800D7A08(void) {
}

void func_800D7A10(void) {
}

void func_800D7A18(void) {
}

void func_800D7A20(void) {
}

void func_800D7A28(void) {
}

void func_800D7A30(void) {
}

void func_800D7A38(void) {
}

void func_800D7A40(void) {
}

void func_800D7A48(void) {
}

void func_800D7A50(void) {
}

void func_800D7A58(void) {
}

void func_800D7A60(void) {
}

void func_800D7A68(void) {
}

void func_800D7A70(void) {
}

void func_800D7A78(void) {
}

void func_800D7A80(void) {
}

void func_800D7A88(void) {
}

void func_800D7A90(void) {
}

void func_800D7A98(void) {
}

void func_800D7AA0(void) {
}

void func_800D7AA8(void) {
}

void func_800D7AB0(void) {
}

void func_800D7AB8(void) {
}

void func_800D7AC0(void) {
}

void func_800D7AC8(void) {
}

void func_800D7AD0(void) {
}

void func_800D7AD8(void) {
}

void func_800D7AE0(void) {
}

void func_800D7AE8(void) {
}

void func_800D7AF0(void) {
}

void func_800D7AF8(void) {
}

void func_800D7B00(void) {
}

void func_800D7B08(void) {
}

void func_800D7B10(void) {
}

void func_800D7B18(void) {
}

void func_800D7B20(void) {
}

void func_800D7B28(void) {
}

void func_800D7B30(void) {
}

void func_800D7B38(void) {
}

void func_800D7B40(void) {
}

void func_800D7B48(void) {
}

void func_800D7B50(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7B58);

void func_800D7C38(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7C40);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7D7C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D7E38);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D80B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D823C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800A3E3C", func_800D8484);
