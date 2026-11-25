#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", PadEnableCom);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", _padSetVsyncParam);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016398);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016400);

extern s32 D_80063FD0;
s32 _padChkVsync(void) {
    s32 old = D_80063FD0;
    D_80063FD0 = 0;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_800165A4);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016670);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", _padInitSioMode);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_800169E8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016AD8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016CE8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016F60);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", _padWaitRXready);
