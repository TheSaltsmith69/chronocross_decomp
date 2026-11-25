#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/break", BreakDraw);

extern volatile u32 *D_80063D70_g asm("D_80063D70");
s32 IsIdleGPU(s32 max) {
    s32 i = 0;
    while (!(*D_80063D70_g & 0x04000000)) {
        if (max < i++) {
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/break", ContinueDraw);
