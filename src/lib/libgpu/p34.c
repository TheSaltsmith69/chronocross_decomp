#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_m;
void SetDrawMove(u32 *p, RECT_m *r, s32 x, s32 y) {
    s32 len = 5;
    if (r->w == 0 || r->h == 0) {
        len = 0;
    }
    p[1] = 0x01000000;
    p[2] = 0x80000000;
    ((u8 *)p)[3] = len;
    p[3] = *(u32 *)&r->x;
    p[4] = (y << 16) | (x & 0xFFFF);
    p[5] = *(u32 *)&r->w;
}
