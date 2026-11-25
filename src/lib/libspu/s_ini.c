#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libspu/s_ini", _SpuInit);

extern s32 D_8006AE00_s asm("D_8006AE00");
extern s32 D_8006AD98_s asm("D_8006AD98");
s32 func_80022964_s2(void) asm("func_80022964");
s32 func_80022974_s2(void) asm("func_80022974");
void func_80029474_s(void *) asm("func_80029474");
void _spu_FiDMA(void);
s32 OpenEvent_s(u32, s32, s32, s32) asm("OpenEvent");
s32 EnableEvent_s(s32) asm("EnableEvent");
void SpuStart(void) {
    s32 ev;
    if (D_8006AE00_s == 0) {
        D_8006AE00_s = 1;
        func_80022964_s2();
        func_80029474_s(_spu_FiDMA);
        ev = OpenEvent_s(0xF0000009, 0x20, 0x2000, 0);
        D_8006AD98_s = ev;
        EnableEvent_s(ev);
        func_80022974_s2();
    }
}
