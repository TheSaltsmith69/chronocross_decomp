#include "common.h"

extern void *D_80063F80;
extern void *D_80063F84;
extern void *D_80063F88;
void func_800176B8(void);
void func_80017B0C(void);
void func_800177C8(void);
void _padInitDirSeq(void) {
    D_80063F80 = func_800176B8;
    D_80063F84 = func_80017B0C;
    D_80063F88 = func_800177C8;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_800176B8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_800177C8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_80017A2C);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_80017B0C);
