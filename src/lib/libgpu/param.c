#include "common.h"

extern volatile u32 *D_80063D84_e asm("D_80063D84");
u32 func_80011BF8(s32 x);
void GetDrawEnv2(u8 *p) {
    u32 s = *D_80063D84_e;
    p[3] = 5;
    *(u32 *)(p + 4) = func_80011BF8(3) | 0xE3000000;
    *(u32 *)(p + 8) = func_80011BF8(4) | 0xE4000000;
    *(u32 *)(p + 0xC) = func_80011BF8(5) | 0xE5000000;
    *(u32 *)(p + 0x10) = 0xE1000000 | (s & 0x7FF) | ((s & 0x8000) >> 4);
    *(u32 *)(p + 0x14) = func_80011BF8(2) | 0xE2000000;
}

extern volatile u32 *D_80063D84_g asm("D_80063D84");
u32 func_80011BF8(s32 x);
void GetDrawMode(u32 *p) {
    u32 v = *D_80063D84_g;
    p[1] = 0xE1000000 | (v & 0x7FF) | ((v & 0x8000) >> 4);
    p[2] = func_80011BF8(2) | 0xE2000000;
}

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
