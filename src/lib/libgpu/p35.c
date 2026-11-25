#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_dl;
typedef struct { u32 tag; u32 code[3]; u32 p[13]; } DRL;
void SetDrawLoad(DRL *p, RECT_dl *r) {
    u32 len = (r->w * r->h + 1) / 2;
    u32 l = len + 4;
    if (len > 12) {
        l = 0;
    }
    ((u8 *)p)[3] = l;
    p->code[0] = 0xA0000000;
    p->code[1] = *(u32 *)&r->x;
    p->code[2] = *(u32 *)&r->w;
    p->code[l - 1] = 0x01000000;
}
