#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_c2;
s32 LoadImage(void *, u32 *);
u16 GetClut_c2(s32, s32) asm("GetClut");
u16 LoadClut2(u32 *clut, s32 x, s32 y) {
    RECT_c2 r;
    r.x = x;
    r.y = y;
    r.w = 16;
    r.h = 1;
    LoadImage(&r, clut);
    return GetClut_c2(x, y);
}
