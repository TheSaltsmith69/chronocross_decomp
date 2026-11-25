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

extern u8 D_8006E7D0[];
s32 func_80022964_p(void) asm("func_80022964");
s32 func_80022974_p(void) asm("func_80022974");
s32 ChangeClearRCnt_p(s32, s32) asm("ChangeClearRCnt");
s32 SysDeqIntRP_p(s32, void *) asm("SysDeqIntRP");
void func_80016670(void) {
    func_80022964_p();
    ChangeClearRCnt_p(3, 1);
    SysDeqIntRP_p(2, D_8006E7D0);
    func_80022974_p();
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", _padInitSioMode);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_800169E8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016AD8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016CE8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padmain", func_80016F60);

extern volatile u16 *D_80063FCC;
void _padWaitRXready(void) {
    while (!(D_80063FCC[2] & 2)) {
    }
}
