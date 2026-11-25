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

extern s32 D_80063F38;
extern void (*D_80063F80_d)(u8 *) asm("D_80063F80");
extern s32 D_80063FB4_d asm("D_80063FB4");
extern s32 D_80063F30_d asm("D_80063F30");
s32 func_80016CE8_d(u8 *, s32) asm("func_80016CE8");
s32 func_80015D44(u8 *p) {
    s32 r;
    s32 t;
    if (D_80063F38 != 0) {
        D_80063F80_d(*(u8 **)(p + 0xC) + 0x1E0);
        D_80063F80_d(*(u8 **)(p + 0xC) + 0x2D0);
    }
    r = func_80016CE8_d(p, p[0x37] == 0 ? D_80063FB4_d : 0);
    if (r < 0) {
        return r;
    }
    t = (r & 0xF) * 2;
    D_80063F30_d = t;
    if (t == 0) {
        D_80063F30_d = 0x20;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padif", func_80015DF0);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padif", func_80015EB4);
