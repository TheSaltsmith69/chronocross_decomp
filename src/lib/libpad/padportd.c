#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padportd", PadInitDirect);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padportd", func_80017184);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padportd", func_800171EC);

void func_800172E0(u8 *p) {
    u8 v = p[0x37];
    p[0x37] = 0;
    p[0x38] = v;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padportd", func_800172F0);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padportd", func_800173AC);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padportd", func_80017628);

extern u8 D_8006E880[];
u8 *func_80017660(s32 port) {
    u8 *p = D_8006E880;
    if (port & 0xF0) {
        p += 0xF0;
    }
    return p;
}
