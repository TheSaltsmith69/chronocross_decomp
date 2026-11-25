#include "common.h"

extern void *D_80063F80;
extern void *D_80063F84;
extern void *D_80063F88;
void func_80017B78(void);
void func_8001851C(void);
void func_80017DE8(void);
void _padInitMtapSeq(void) {
    D_80063F80 = func_80017B78;
    D_80063F84 = func_8001851C;
    D_80063F88 = func_80017DE8;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqm", func_80017B78);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqm", func_80017DE8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqm", func_800181D0);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqm", func_8001851C);
