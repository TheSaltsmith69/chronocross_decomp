#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", ResetCallback);

typedef struct { void *f0; s32 (*dma)(s32, void *); s32 (*intr)(s32, void *); } IntrFuncs;
extern IntrFuncs *D_8006ACF8;
s32 InterruptCallback(s32 i, void *f) {
    return D_8006ACF8->intr(i, f);
}

s32 DMACallback(s32 i, void *f) {
    return D_8006ACF8->dma(i, f);
}

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", VSyncCallback);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", VSyncCallbacks);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80027BE8);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", RestartCallback);

extern u16 D_80069C72;
s32 CheckCallback(void) {
    return D_80069C72;
}

extern volatile u16 *D_8006AD00;
s32 GetIntrMask(void) {
    return *D_8006AD00;
}

s32 SetIntrMask(s32 mask) {
    s32 old = *D_8006AD00;
    *D_8006AD00 = mask;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80027C88);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80027D60);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80027F30);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80028078);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80028118);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_80028190);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_800281B4);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_800281BC);
