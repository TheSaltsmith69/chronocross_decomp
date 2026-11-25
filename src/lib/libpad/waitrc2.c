#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libpad/waitrc2", setRC2wait);

extern u32 D_8006EA60_w asm("D_8006EA60");
extern u32 D_8006EA64_w asm("D_8006EA64");
s32 func_800185F4(void) {
    u32 v = *(volatile u16 *)0x1F801120;
    if (v < D_8006EA60_w) {
        if (*(volatile u16 *)0x1F801128 != 0) {
            v += *(volatile u16 *)0x1F801128;
        } else {
            v += 0x10000;
        }
    }
    if (*(volatile u16 *)0x1F801124 & 0x200) {
        return !((v - D_8006EA60_w) < D_8006EA64_w);
    }
    return !(((v - D_8006EA60_w) >> 3) < D_8006EA64_w);
}
