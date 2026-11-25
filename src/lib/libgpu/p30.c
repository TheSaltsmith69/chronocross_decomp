#include "common.h"

void SetLineG3(u8 *p) {
    p[3] = 7;
    p[7] = 0x58;
    *(u32 *)(p + 0x1C) = 0x55555555;
    p[0x17] = 0;
}
