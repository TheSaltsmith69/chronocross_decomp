#include "common.h"

void SetLineF4(u8 *p) {
    p[3] = 6;
    p[7] = 0x4C;
    *(u32 *)(p + 0x18) = 0x55555555;
}
