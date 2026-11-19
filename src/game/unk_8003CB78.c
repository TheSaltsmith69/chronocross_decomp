#include "common.h"

extern s32 D_8007EE20[];
extern s32 D_1F80000C;
extern s32 D_1F800014;
extern s32 D_8007EE1C;
extern u8 D_800635E4[];
extern s32 D_8007EE40[];
extern u8 D_805F5F78[];
extern u8 D_806097F8[];
extern s32 D_8007EE38;
extern s32 D_8006B3FC;

void func_8003CB78(s32 size, s32 arg1) {
    s32 p;
    D_8007EE1C = size;
    func_8003DB78(D_800635E4);
    p = func_8003D8F4(size * 2, arg1, 1);
    D_8007EE20[0] = p;
    D_8007EE20[1] = p + size;
    D_8007EE40[0] = (s32)D_805F5F78;
    D_8007EE40[1] = (s32)D_806097F8;
    D_1F800014 = p;
    D_8007EE38 = p;
    D_8006B3FC = 0;
    D_1F80000C = p + D_8007EE1C;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003CC2C);

extern s32 D_8007EE20[];
extern s32 D_1F80000C;
extern s32 D_1F800014;
void func_8003D504(s32);
void func_8003CCB0(void) {
    func_8003D504(D_8007EE20[0]);
    D_8007EE20[0] = 0;
    D_8007EE20[1] = 0;
    D_1F80000C = 0;
    D_1F800014 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003CCF8);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_800635E4);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_800635F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003CD38);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D070);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_80063674);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_8006368C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D370);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D504);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D704);

extern u8 D_8007EE5C;
void func_8003D8A8(s32 arg0) {
    D_8007EE5C = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D8B4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D8F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D92C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D9E0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DA88);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DB34);

extern s32 D_8007EE4C;
void func_8003DB78(s32 arg0) {
    D_8007EE4C = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DB84);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DC64);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DC70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DD14);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DD34);
