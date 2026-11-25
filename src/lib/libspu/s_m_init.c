#include "common.h"

extern s32 D_8006AE38;
extern u32 *D_8006AE78_p asm("D_8006AE78");
extern s32 D_8006AE74_p asm("D_8006AE74");
extern s32 D_8006AE70_p asm("D_8006AE70");
s32 SpuInitMalloc(s32 num, u32 *top) {
    if (num > 0) {
        s32 sh = D_8006AE38;
        top[0] = 0x40001010;
        D_8006AE78_p = top;
        D_8006AE74_p = 0;
        D_8006AE70_p = num;
        top[1] = (0x10000 << sh) - 0x1010;
        return num;
    }
    return 0;
}
