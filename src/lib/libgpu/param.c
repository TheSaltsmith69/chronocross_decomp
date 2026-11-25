#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/param", GetDrawEnv2);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/param", GetDrawMode);

u32 func_80011BF8(s32);
void GetTexWindow(u32 *p) {
    p[1] = func_80011BF8(2) | 0xE2000000;
}

u32 func_80011BF8(s32 x);
void GetDrawArea(u32 *p) {
    p[1] = func_80011BF8(3) | 0xE3000000;
    p[2] = func_80011BF8(4) | 0xE4000000;
}

u32 func_80011BF8(s32);
void GetDrawOffset(u32 *p) {
    p[1] = func_80011BF8(5) | 0xE5000000;
}

extern volatile u32 *D_80063D84;
extern volatile u32 *D_80063D80;
u32 func_80011BF8(s32 x) {
    *D_80063D84 = x | 0x10000000;
    return *D_80063D80 & 0xFFFFFF;
}
