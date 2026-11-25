#include "common.h"

extern u32 D_8006CE60;
s32 rand(void) {
    D_8006CE60 = D_8006CE60 * 1103515245 + 12345;
    return (D_8006CE60 >> 16) & 0x7FFF;
}

/* srand */
void func_800107A4(u32 seed) {
    D_8006CE60 = seed;
}
