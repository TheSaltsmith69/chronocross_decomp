#include "common.h"

s32 MargePrim(u8 *p0, u8 *p1) {
    s32 len = p0[3] + p1[3] + 1;
    if (len > 0x10) {
        return -1;
    }
    p0[3] = len;
    *(u32 *)p1 = 0;
    return 0;
}
