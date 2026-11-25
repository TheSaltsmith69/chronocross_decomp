#include "common.h"

extern s32 (*D_80063F80_r)(u8 *) asm("D_80063F80");
extern s32 D_80063F38;
void func_80016AD8_r(u8 *, s32) asm("func_80016AD8");
void func_80015C24(u8 *p) {
    s32 r = D_80063F80_r(p);
    u8 *q = *(u8 **)(p + 0x3C);
    D_80063F38 = r;
    *q = 0;
    func_80016AD8_r(p, -2);
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padif", func_80015C6C);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padif", func_80015D44);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padif", func_80015DF0);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padif", func_80015EB4);
