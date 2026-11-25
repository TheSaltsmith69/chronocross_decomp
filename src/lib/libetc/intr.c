#include "common.h"

typedef s32 (*IFN_a)();
extern IFN_a *D_8006ACF8_a asm("D_8006ACF8");
s32 ResetCallback(void) {
    return D_8006ACF8_a[3]();
}

typedef struct { void *f0; s32 (*dma)(s32, void *); s32 (*intr)(s32, void *); } IntrFuncs;
extern IntrFuncs *D_8006ACF8;
s32 InterruptCallback(s32 i, void *f) {
    return D_8006ACF8->intr(i, f);
}

s32 DMACallback(s32 i, void *f) {
    return D_8006ACF8->dma(i, f);
}

typedef s32 (*IFN_e)();
extern IFN_e *D_8006ACF8_e asm("D_8006ACF8");
s32 VSyncCallback(void *f) {
    return D_8006ACF8_e[5](4, f);
}

typedef s32 (*IFN_c)();
extern IFN_c *D_8006ACF8_c asm("D_8006ACF8");
s32 VSyncCallbacks(s32 i, void *f) {
    return D_8006ACF8_c[5](i, f);
}

/* StopCallback */
typedef s32 (*IFN_d)();
extern IFN_d *D_8006ACF8_d asm("D_8006ACF8");
s32 func_80027BE8(void) {
    return D_8006ACF8_d[4]();
}

typedef s32 (*IFN_b)();
extern IFN_b *D_8006ACF8_b asm("D_8006ACF8");
s32 RestartCallback(void) {
    return D_8006ACF8_b[6]();
}

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

void func_80028190(s32 *p, s32 n) {
    while (--n != -1) {
        *p++ = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_800281B4);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr", func_800281BC);
