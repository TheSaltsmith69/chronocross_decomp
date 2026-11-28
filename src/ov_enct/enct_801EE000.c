#include "common.h"

extern s32 D_8007ED6C;
void func_800C3D98(void);
void func_800C3E60(void);
void SetRotMatrix(s32);
void SetTransMatrix(s32);

void func_801EE000(void) {
    while (1) {
        func_800C3D98();
        SetRotMatrix(D_8007ED6C);
        SetTransMatrix(D_8007ED6C);
        func_800C3E60();
    }
}

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE040);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE0A0);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE0E4);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE120);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE140);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE178);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE2F4);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE364);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE5A8);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EE850);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EEC54);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EED70);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EEE64);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EF858);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EFB78);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801EFC00);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F0914);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F0B08);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F0CEC);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F117C);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F15A8);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F15F0);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F1864);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F1A28);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F1BD8);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F20F4);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F213C);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F24A0);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F25B4);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F2AF8);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F2B40);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F2D90);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F2E44);

INCLUDE_ASM("asm/ov_enct/nonmatchings/enct_801EE000", func_801F2F34);
