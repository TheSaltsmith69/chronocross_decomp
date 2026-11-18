#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8002FE30);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800301CC);

extern s32 D_8006B1EC;
extern s16 D_8007EC20[];
extern s16 D_8007EB08[];
void func_80030680(void) {
    D_8006B1EC = 0;
    D_8007EB08[0] = D_8007EC20[0];
    D_8007EB08[1] = D_8007EC20[1];
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800306AC);

extern s32 D_8007EC1C;
void func_800307CC(u8 arg0);
void func_8003073C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_8007EC1C = 0x80808080;
    D_8007EC20[0] = arg0;
    D_8007EC20[1] = arg1;
    D_8007EC20[2] = arg2;
    D_8007EC20[3] = arg3;
    func_800307CC(0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030784);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800307AC);

extern u8 D_8006B1E9;
extern u8 D_8006B1EA;
void func_800307CC(u8 arg0) {
    D_8006B1E9 = arg0;
    if (arg0) {
        D_8006B1EA = 6;
    } else {
        D_8006B1EA = 8;
    }
}

extern s32 D_8007EC18;
void func_800307F8(s32 arg0) {
    D_8007EC18 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030804);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030814);

extern s32 D_8006B208;
extern s32 D_8006B204;
extern s32 D_8006B1FC;
extern s32 D_8006B1F8;
extern s32 D_8006B1F4;
extern s32 D_8006B20C;
extern s32 D_8006B200;
void func_800308A4(void) {
    D_8006B208 = 0;
    D_8006B204 = 0;
    D_8006B1FC = 0;
    D_8006B1F8 = 0;
    D_8006B1F4 = 0;
    D_8006B20C = 0;
    D_8006B200 = 0;
}

extern s32 D_8006B1F4;
void func_800308E0(s32 arg0) {
    D_8006B1F4 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800308EC);

extern s32 D_8006B1F8;
void func_800308F8(s32 arg0) {
    D_8006B1F8 = arg0;
}

extern s32 D_8006B1FC;
void func_80030904(s32 arg0) {
    D_8006B1FC = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030910);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003091C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030928);

s32 func_80030934(void) {
    if (D_8006B1F4 != 0) {
        return ((s32 (*)(void))D_8006B1F4)();
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030968);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003099C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800309D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030A04);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030A38);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030A6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030AA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030B98);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80031074);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800314D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800318BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80031AC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800321B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800324F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003276C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800328F0);

s32 func_80041F0C(s32, s32);
void *func_80041F6C(void *);
void func_80031074(void *, s32);
extern s32 D_8006B23C;
void func_800329B8(s32 arg0) {
    s32 v = func_80041F0C(0xC, arg0);
    if (v != 0) {
        func_80031074(func_80041F6C((void *)v), arg0);
        D_8006B23C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032A08);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032A54);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032AAC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032B54);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032C5C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032D40);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032D78);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032DD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032E60);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032EB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032FAC);

extern s32 D_8006B234;
void func_80033074(s32 arg0) {
    D_8006B234 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033080);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800331AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003324C);

void func_80033324(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003332C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033530);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033588);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033654);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033940);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033974);

s32 func_800339DC(s32 *arg0) {
    return arg0[1];
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800339E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800339F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033A80);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033B58);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033B70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033D80);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033F20);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80034024);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800342B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800369FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80036F4C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037320);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037B40);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037CA8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037E68);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038554);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038AD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038D28);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038ED4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80039038);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003944C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800395D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800399FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80039C70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003A118);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003A1F8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003A4C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003AFE4);

void func_8003B12C(s32 *arg0, s32 arg1) {
    arg0[-1] = arg1;
}

void func_8003B134(s32 *arg0, s32 arg1) {
    arg0[-2] = arg1;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B13C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B210);

typedef struct Unk8003B238 {
    struct Unk8003B238 *next;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    u16 unkC;
} Unk8003B238;
extern Unk8003B238 *D_8006B248;
void func_8003B238(Unk8003B238 *arg0) {
    arg0->next = D_8006B248;
    D_8006B248 = arg0;
    arg0->unk8 = 0;
    arg0->unkC = arg0->unkA;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B258);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B2B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B2E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B330);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B420);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B490);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B4F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B550);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B594);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B610);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B660);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B720);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B7BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B8C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B9A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BA64);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BAF0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BB78);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BBC8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BC80);

void func_8003BD2C(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BD34);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BE00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BEA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BEC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BF6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C048);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C138);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C22C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C304);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C354);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C42C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C4B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C52C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C630);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C714);

void func_80043B30();
void func_8003C7D0(s32 *arg0) {
    func_8003B134(arg0, (s32)func_80043B30);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C7F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C8CC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C930);

void SetFogNearFar(s32, s32, s32);
extern s16 D_8007EDE8;
extern s16 D_8007EDE2;
void func_8003C988(s32 arg0, s32 arg1, s32 arg2) {
    SetFogNearFar(arg0, arg1, arg2);
    D_8007EDE8 = arg0;
    D_8007EDE2 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C9C8);
