#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_init);

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", func_80028BB4);

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_FiDMA);

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_Fr_);

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_t);

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_Fw);

extern u16 D_8006AE28_q asm("D_8006AE28");
extern s32 D_8006AE38;
void _spu_t_q(s32, ...) asm("_spu_t");
s32 _spu_Fr(void *addr, s32 size) {
    _spu_t_q(2, D_8006AE28_q << D_8006AE38);
    _spu_t_q(0);
    _spu_t_q(3, addr, size);
    return size;
}

extern u16 *D_8006AE10_n asm("D_8006AE10");
extern s32 D_8006AE38;
void _spu_FsetRXX(s32 reg, u32 val, s32 mode) {
    if (mode == 0) {
        D_8006AE10_n[reg] = val;
    } else {
        D_8006AE10_n[reg] = val >> D_8006AE38;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_FsetRXXa);

extern u16 *D_8006AE10_n asm("D_8006AE10");
extern s32 D_8006AE38;
s32 _spu_FgetRXXa(s32 reg, s32 mode) {
    u16 v = D_8006AE10_n[reg];
    if (mode == -1) {
        return v;
    }
    return v << D_8006AE38;
}

extern u32 *D_8006AE20_r asm("D_8006AE20");
void _spu_FsetPCR(s32 on) {
    *D_8006AE20_r &= 0xFFF8FFFF;
    if (on) {
        *D_8006AE20_r |= 0x30000;
    } else {
        *D_8006AE20_r |= 0x50000;
    }
}

extern volatile u32 *D_8006AE24;
void func_800293BC(void) {
    *D_8006AE24 = (*D_8006AE24 & 0xF0FFFFFF) | 0x20000000;
}

void func_800293E4(void) {
    *D_8006AE24 = (*D_8006AE24 & 0xF0FFFFFF) | 0x22000000;
}

INCLUDE_ASM("asm/nonmatchings/lib/libspu/spu", _spu_Fw1ts);
