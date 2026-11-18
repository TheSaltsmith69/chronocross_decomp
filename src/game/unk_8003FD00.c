#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8003FD00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800404F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040780);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040928);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040DD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800413F8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041820);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041AEC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041C0C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041E2C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041EAC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041EB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041F0C);

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
    s32 unkC;
} Unk80041F6C;
void *func_80041F6C(Unk80041F6C *arg0) {
    if (!(arg0->unk8 >> 7)) {
        return &arg0->unkC;
    }
    return (void *)arg0->unkC;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041F94);

void DrawSync(s32);
void func_80041820(s32);
void func_80041FD4(s32 arg0) {
    DrawSync(0);
    func_80041820(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042004);

void func_8004206C(s32 *arg0) {
    arg0[2] |= 0x80000000;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042080);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004208C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800420FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800421E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042214);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004227C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800422E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042364);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004247C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800424AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004257C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042928);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800429B4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042A10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042AE0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042AE8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042B10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042B20);

void func_80043B28(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043B30);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043F0C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043F90);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044190);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044304);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044484);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044630);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800448C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044924);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044A08);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044A88);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044B0C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044BF8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044CD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044D9C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044DD4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044EE0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044F6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80044FCC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800450F8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004515C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800452E4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800455A0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800455E4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004582C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800458BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800458F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800459D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80045ACC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80045CCC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80045E78);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80045F14);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004600C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80046388);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80046698);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800468AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80046BC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80046FB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800475C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80047724);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80047760);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80047844);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800479AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80047E18);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80047F44);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004803C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80048140);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800489A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80048B44);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80048C00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80048E6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004928C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80049960);
