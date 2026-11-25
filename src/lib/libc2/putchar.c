#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc2/putchar", func_800104B4);

extern s32 D_80063D34;
extern u8 D_8006CE40[];
s32 write(s32, void *, s32);
void func_800105B0(void) {
    if (D_80063D34 > 0) {
        write(1, D_8006CE40, D_80063D34);
        D_80063D34 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libc2/putchar", func_800105EC);
