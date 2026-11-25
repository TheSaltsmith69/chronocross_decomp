#include "common.h"

extern s32 D_8006AE48_p asm("D_8006AE48");
extern s32 D_8006AE44_p asm("D_8006AE44");
void _spu_Fw_p(void *, u32) asm("_spu_Fw");
u32 func_8004BCC4(void *addr, u32 size) {
    if (size > 0x7EFF0) {
        size = 0x7EFF0;
    }
    _spu_Fw_p(addr, size);
    if (D_8006AE48_p == 0) {
        D_8006AE44_p = 0;
    }
    return size;
}
