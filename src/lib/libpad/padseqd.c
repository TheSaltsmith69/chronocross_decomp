#include "common.h"

extern void *D_80063F80;
extern void *D_80063F84;
extern void *D_80063F88;
void func_800176B8(void);
s32 func_80017B0C();
void func_800177C8(void);
void _padInitDirSeq(void) {
    D_80063F80 = func_800176B8;
    D_80063F84 = func_80017B0C;
    D_80063F88 = func_800177C8;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_800176B8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_800177C8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_80017A2C);

s32 func_80017B0C(u8 *p) {
    if (*(u16 *)(p + 0xE6) == 0 || p[0x46] != 0xFF) {
        return 1;
    }
    return 0;
}
