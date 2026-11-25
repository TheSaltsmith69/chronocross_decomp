#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_vb", startIntrVSync);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_vb", func_8002825C);

extern s32 D_8006AD18[];
void func_800282C8(s32 i, s32 f) {
    if (f != D_8006AD18[i]) {
        D_8006AD18[i] = f;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_vb", func_800282F4);
