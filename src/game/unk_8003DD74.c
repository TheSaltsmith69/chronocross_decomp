#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003DD74);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003E074);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003E444);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003EC44);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003EE10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F2A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F414);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F528);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", .L8003F63C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F7D4);

void func_8003F884(u8 *arg0, u32 arg1) {
    while (arg1 > 4) {
        *(s32 *)arg0 = 0;
        arg1 -= 4;
        arg0 += 4;
    }
    while (arg1 != 0) {
        *arg0 = 0;
        arg1--;
        arg0++;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F8C4);

extern s32 *D_8006B48C;
void func_8003F920(s32 *arg0) {
    arg0[1] = (s32)D_8006B48C;
    D_8006B48C = arg0;
}

void func_8003F934(void) {
    D_8006B48C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F940);

extern s16 D_80086FBC[];
extern s16 D_80086FB8[];
extern s32 D_80086FA8;
void func_8003F9AC(void) {
    D_80086FBC[1] = 0;
    D_80086FBC[0] = 0;
    D_80086FB8[1] = 0;
    D_80086FB8[0] = 0;
    D_80086FA8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F9D8);

void func_80022964(void);
void func_80022974(void);
void func_80042B20(void);
void func_8003FA64(void) {
    s32 *p = (s32 *)func_80042B20;
    s32 i;
    func_80022964();
    for (i = 0; i != 0x400; i++) {
        *p++ = 0;
    }
    func_80042B20();
    func_80022974();
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003FAB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003FB60);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003FC70);
