#include "common.h"

void SetDrawStp(u8 *p, s32 pbw) {
    p[3] = 2;
    *(u32 *)(p + 4) = pbw ? 0xe6000001 : 0xe6000000;
    *(u32 *)(p + 8) = 0;
}
