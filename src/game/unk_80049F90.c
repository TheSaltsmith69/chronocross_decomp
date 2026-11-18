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

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A26C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A2A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A2D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A33C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A3A8);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A8B4);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AC00);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004B048);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004B0B4);

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
