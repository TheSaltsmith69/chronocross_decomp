#include "common.h"

void SetPriority(u8 *p, s32 pbc, s32 pbw) {
    p[3] = 2;
    *(u32 *)(p + 4) = (pbc ? 0xE6000002 : 0xE6000000) | (pbw != 0);
    *(u32 *)(p + 8) = 0;
}
