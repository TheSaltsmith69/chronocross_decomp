#include "common.h"

s32 _spu_FsetRXXa(s32, u32);
s32 SpuSetIRQAddr(u32 addr) {
    if (addr > 0x7FFF8) {
        return 0;
    }
    return _spu_FsetRXXa(0xD2, addr);
}
