#include "common.h"

extern volatile u16 D_8006AE28_p asm("D_8006AE28");
extern s32 D_8006AE38;
s32 _spu_FsetRXXa_p(s32, u32) asm("_spu_FsetRXXa");
u32 SpuSetTransferStartAddr(u32 addr) {
    if (addr - 0x1010 > 0x7EFE8) {
        return 0;
    }
    D_8006AE28_p = _spu_FsetRXXa_p(-1, addr);
    return D_8006AE28_p << D_8006AE38;
}
