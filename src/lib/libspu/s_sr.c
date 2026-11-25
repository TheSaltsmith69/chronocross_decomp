#include "common.h"

extern u16 *D_8006AE10_n asm("D_8006AE10");
extern s32 D_8006ADA4_r asm("D_8006ADA4");
extern s32 D_8006ADA8_r asm("D_8006ADA8");
extern s32 D_8006ADAC_r asm("D_8006ADAC");
s32 _SpuIsInAllocateArea__r(s32) asm("_SpuIsInAllocateArea_");
s32 SpuSetReverb(s32 on) {
    switch (on) {
    case 0:
        D_8006ADA4_r = 0;
        D_8006AE10_n[0xD5] &= ~0x80;
        break;
    case 1:
        if (D_8006ADA8_r != on && _SpuIsInAllocateArea__r(D_8006ADAC_r)) {
            D_8006ADA4_r = 0;
            D_8006AE10_n[0xD5] &= ~0x80;
        } else {
            D_8006ADA4_r = on;
            D_8006AE10_n[0xD5] |= 0x80;
        }
        break;
    }
    return D_8006ADA4_r;
}
