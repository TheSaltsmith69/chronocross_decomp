#include "common.h"

extern s32 D_8006ADA0;
extern s32 D_8006AE2C;
void SpuSetTransferMode(s32 mode) {
    s32 v;
    switch (mode) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    default:
        v = 0;
        break;
    }
    D_8006ADA0 = mode;
    D_8006AE2C = v;
}
