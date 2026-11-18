#include "common.h"

void func_8004B750(void);
s32 func_80049F90(void) {
    func_8004B750();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_80049FB0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_80049FD0);

extern s32 D_8008BEE0;
void func_8005134C(s32);
void func_8004A030(s32 arg0) {
    D_8008BEE0 = arg0;
    func_8005134C(0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A058);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A080);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A0B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A0D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A0F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A124);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A15C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A18C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A1DC);

void func_8004A26C(s32 arg0, s32 arg1) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1 & 0xFFFFFF;
    func_8005134C(0x21);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A2A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A2D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A33C);

extern s32 D_8008BEB0[];
s32 func_8004A3A8(s32 arg0) {
    u32 v = D_8008BEB0[11] & ~0xF;
    D_8008BEB0[11] = v;
    switch (arg0) {
    case -2:
        D_8008BEB0[11] = v | 1;
        break;
    case -1:
        D_8008BEB0[11] = v | 2;
        break;
    case 1:
        D_8008BEB0[11] = v | 4;
        break;
    case 2:
        D_8008BEB0[11] = v | 8;
        break;
    default:
        arg0 = 0;
        break;
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A428);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A45C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A484);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A4AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A518);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A584);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A5B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A5E4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A628);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A670);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A69C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A6D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A714);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A75C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A788);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A7BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A800);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A848);

void func_8004A87C(s32 arg0, s32 arg1, s32 arg2) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1;
    (&D_8008BEE0)[2] = arg2 & 0x7F;
    func_8005134C(0xC1);
}

void func_8004A8B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1;
    (&D_8008BEE0)[2] = arg2 & 0x7F;
    (&D_8008BEE0)[3] = arg3 & 0x7F;
    func_8005134C(0xC2);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A8F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A928);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A960);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A988);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A9B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A9EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AA18);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AA4C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AA88);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AAB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AAE8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AB24);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AB50);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AB84);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004ABC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004ABE0);

s32 func_8004B3A0(s32, s32);
void func_8004A2A8(s32);
s32 func_8004AC00(s32 arg0, s32 arg1) {
    s32 r;
    do {
        r = func_8004B3A0(arg0, arg1);
    } while (r == 1);
    if (r == -1) {
        func_8004A2A8(0x18);
    }
    return r;
}

extern s32 D_8008BE20;
s32 func_8004AC70(void) {
    return D_8008BE20;
}

extern s32 D_8008E398;
extern s32 D_8008E46C;
s32 func_8004AC80(void) {
    D_8008E46C = 0;
    D_8008E398 |= 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004ACA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AEC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AEE0);

void func_8004AF74(void) {
    func_8005134C(0xE2);
}

void func_8004AF94(s32 arg0) {
    D_8008BEE0 = (arg0 & 0x7F) << 8;
    func_8005134C(0xE4);
}

void func_8004AFC4(s32 arg0, s32 arg1) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = (arg1 & 0x7F) << 8;
    func_8005134C(0xE5);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AFFC);

extern u8 D_8006B4FC[];
void func_8005134C(s32);
void SpuSetTransferMode(s32);
u32 SpuSetTransferStartAddr(u32);
void func_8004B2E8(u8 *, s32);
void func_8004B374(void);
s32 func_8004B048(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return -1;
    }
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1;
    func_8005134C(0xE8);
    SpuSetTransferMode(0);
    SpuSetTransferStartAddr(0xF0C0);
    func_8004B2E8(D_8006B4FC, 0x40);
    func_8004B374();
    return 0;
}

typedef struct {
    u8 pad0[8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad14[0xC];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    u32 unk3C;
} Unk8008E3A8;
extern Unk8008E3A8 D_8008E3A8;
extern s32 D_8008E3DC;

s32 func_8004B0B4(void) {
    D_8008E3A8.unk24++;
    D_8008E3A8.unk38++;
    if (D_8008E3A8.unk3C - 1 < D_8008E3A8.unk38) {
        D_8008E3A8.unk38 = 0;
    }
    if ((D_8008E3A8.unk8 & 0x1000000) && D_8008E3A8.unk38 >= 2) {
        func_80055F20();
    }
    return D_8008E3DC;
}

s32 func_8004B138(s32 arg0) {
    D_8008BEE0 = arg0;
    func_8005134C(0xAE);
    return arg0;
}

s32 func_8004B16C(s32 arg0) {
    D_8008BEE0 = arg0;
    func_8005134C(0xAF);
    return arg0;
}
