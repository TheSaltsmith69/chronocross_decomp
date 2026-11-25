#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libetc/vsync", VSync);

extern volatile s32 D_8006AD38_w asm("D_8006AD38");
extern char D_8006278C[];
void puts(char *);
void ChangeClearPAD_w(s32) asm("ChangeClearPAD");
void ChangeClearRCnt_w(s32, s32) asm("ChangeClearRCnt");
void func_80027A5C(s32 n, s32 t) {
    volatile s32 cnt = t << 15;
    while (D_8006AD38_w < n) {
        if (--cnt == -1) {
            puts(D_8006278C);
            ChangeClearPAD_w(0);
            ChangeClearRCnt_w(3, 0);
            return;
        }
    }
}
