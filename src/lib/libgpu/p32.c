#include "common.h"

void SetLineG4(u8 *p) {
    p[3] = 9;
    p[7] = 0x5C;
    *(u32 *)(p + 0x24) = 0x55555555;
    p[0x17] = 0;
    p[0x1F] = 0;
}
