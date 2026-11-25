#include "common.h"

void SetLineF3(u8 *p) {
    p[3] = 5;
    p[7] = 0x48;
    *(u32 *)(p + 0x14) = 0x55555555;
}
