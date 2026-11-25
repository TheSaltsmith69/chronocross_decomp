#include "common.h"

void SetDrawTPage(u8 *p, s32 dfe, s32 dtd, s32 tpage) {
    p[3] = 1;
    *(u32 *)(p + 4) = (dtd ? 0xe1000200 : 0xe1000000) | (dfe ? 0x400 : 0) | (tpage & 0x9ff);
}
