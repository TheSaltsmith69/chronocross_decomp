#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_tw;
void SetTexWindow(u8 *p, RECT_tw *tw) {
    p[3] = 2;
    if (tw) {
        *(u32 *)(p + 4) = 0xE2000000 | (((tw->y & 0xFF) >> 3) << 15) | (((tw->x & 0xFF) >> 3) << 10) |
                          ((((-tw->h) & 0xFF) >> 3) << 5) | (((-tw->w) & 0xFF) >> 3);
    } else {
        *(u32 *)(p + 4) = 0;
    }
    *(u32 *)(p + 8) = 0;
}
