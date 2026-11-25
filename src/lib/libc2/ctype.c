#include "common.h"

extern u8 D_80063CA1[];
char toupper(char c) {
    if (D_80063CA1[(u8)c] & 2) {
        c -= 0x20;
    }
    return c;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc2/ctype", tolower);
