#include "common.h"

void func_80019FE4(void);
void func_800221E0(void);
void func_8001A0E0(u8 *, u8 *, s32);
void func_8001BF6C(s32, s32, s32);

INCLUDE_ASM("asm/nonmatchings/game/main", main);

void func_8001A994(void) {
    func_80019FE4();
    func_800221E0();
}

extern u8 D_800623EC[];
extern u8 D_800A3AA8[];
extern u8 D_8006CE20[];
extern u8 D_800A343C[];
void func_8001A9BC(void) {
    func_8001A0E0(D_800623EC, D_800A3AA8, 3);
    func_8001A0E0(D_8006CE20, D_800A343C, 5);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AA04);

extern u8 D_8006B43E;
extern s32 D_8007257C;
extern s32 D_800724DC;
extern u8 D_800724D9;
void func_8001AA14(s32 arg0) {
    D_8006B43E = 0;
    D_800724DC = D_8007257C;
    D_8007257C = 1;
    func_8001BF6C(arg0, 0, 0);
    D_800724D9 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AA64);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AAB8);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AB08);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AB50);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001ABA4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001ABF0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AD30);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B058);

extern u16 D_8007E69E;
void func_8001B0F8(s32 arg0) {
    D_8006B43E = 0;
    D_8007E69E |= 1 << arg0;
}

void func_8001B11C(s32 arg0) {
    D_8007E69E &= ~(1 << arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B13C);

void func_8001B4FC(void) {
}

void func_8001B504(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B50C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B53C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B5A0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B638);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B788);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B7D4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B848);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B8B0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001BF48);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001BF6C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001BF94);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C09C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C0E4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C12C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C164);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C184);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C244);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C29C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C31C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C388);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C4A0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C918);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001CF00);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001D558);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001DCC4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001E55C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001EA4C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001EFA8);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001F274);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001F958);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800201C4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020478);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020488);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020494);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800204B4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800204C0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800205B0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8002096C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020D30);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020E94);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020EDC);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021518);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021B54);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021C0C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021C38);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021E9C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022128);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800221E0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022238);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8002232C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022474);

void func_80022508(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022510);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800225A4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800225BC);
