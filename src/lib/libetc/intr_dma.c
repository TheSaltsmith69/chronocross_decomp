#include "common.h"

extern u8 D_8006AD4C[];
extern volatile u32 *D_8006AD48_r asm("D_8006AD48");
void func_8002859C_r(void *, s32) asm("func_8002859C");
void *InterruptCallback_r(s32, void *) asm("InterruptCallback");
void func_80028370(void);
void func_800284F0(void);
void *func_80028324(void) {
    func_8002859C_r(D_8006AD4C, 8);
    *D_8006AD48_r = 0;
    InterruptCallback_r(3, func_80028370);
    return func_800284F0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_dma", func_80028370);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_dma", func_800284F0);

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_dma", func_8002859C);
