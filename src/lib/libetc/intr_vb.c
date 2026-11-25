#include "common.h"

extern volatile u32 *D_8006AD3C_r asm("D_8006AD3C");
extern s32 D_8006AD38_r asm("D_8006AD38");
void func_800282F4_r(void *, s32) asm("func_800282F4");
void *InterruptCallback_v(s32, void *) asm("InterruptCallback");
void func_8002825C(void);
extern s32 D_8006AD18[];
void func_800282C8(s32 i, s32 f);
void *startIntrVSync(void) {
    *D_8006AD3C_r = 0x100;
    D_8006AD38_r = 0;
    func_800282F4_r(D_8006AD18, 8);
    InterruptCallback_v(0, func_8002825C);
    return func_800282C8;
}

extern s32 D_8006AD38_c asm("D_8006AD38");
extern void (*D_8006AD18_c[8])(void) asm("D_8006AD18");
void func_8002825C(void) {
    s32 i;
    D_8006AD38_c++;
    for (i = 0; i < 8; i++) {
        if (D_8006AD18_c[i] != 0) {
            D_8006AD18_c[i]();
        }
    }
}

extern s32 D_8006AD18[];
void func_800282C8(s32 i, s32 f) {
    if (f != D_8006AD18[i]) {
        D_8006AD18[i] = f;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libetc/intr_vb", func_800282F4);
