#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_sm;
void SetDrawMode(u8 *p, s32 dfe, s32 dtd, s32 tpage, RECT_sm *tw) {
    p[3] = 2;
    *(u32 *)(p + 4) = 0xE1000000 | (dtd ? 0x200 : 0) | (dfe ? 0x400 : 0) | (tpage & 0x9FF);
    if (tw) {
        *(u32 *)(p + 8) = 0xE2000000 | (((tw->y & 0xFF) >> 3) << 15) | (((tw->x & 0xFF) >> 3) << 10) |
                          ((((-tw->h) & 0xFF) >> 3) << 5) | (((-tw->w) & 0xFF) >> 3);
    } else {
        *(u32 *)(p + 8) = 0;
    }
}
