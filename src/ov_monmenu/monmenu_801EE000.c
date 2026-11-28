#include "common.h"

/* a textured quad (PsyQ POLY_FT4) */
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 u0, v0;
    u16 clut;
    s16 x1, y1;
    u8 u1, v1;
    u16 tpage;
    s16 x2, y2;
    u8 u2, v2;
    u16 pad1;
    s16 x3, y3;
    u8 u3, v3;
    u16 pad2;
} PolyFT4;
extern PolyFT4 D_801F1844[];

/* prim i: an 8x8 textured quad at (x, y + 4), texture rows picked by n, added to ot */
void func_801EE000(s32 x, s32 y, u32 *ot, s32 i, s32 n) {
    PolyFT4 *p;
    PolyFT4 *b = D_801F1844;

    p = &b[i];
    y += 4;
    p->x0 = x;
    p->y0 = y;
    p->x1 = x + 8;
    p->y1 = y;
    p->x2 = x;
    p->y2 = y + 8;
    p->x3 = x + 8;
    p->y3 = y + 8;
    p->u0 = 0x80;
    p->v0 = n * 12 - 0x80;
    p->u1 = 0x88;
    p->v1 = n * 12 - 0x80;
    p->u2 = 0x80;
    p->v2 = n * 12 - 0x73;
    p->u3 = 0x88;
    p->v3 = n * 12 - 0x73;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);         /* addPrim(ot, p) */
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
}

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EE0C0);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EE168);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EE1C8);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EE1F4);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EE254);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EEAAC);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EED80);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EEEEC);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EEF50);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801EF514);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801F002C);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801F0258);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801F029C);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801F03F4);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801F04CC);

INCLUDE_ASM("asm/ov_monmenu/nonmatchings/monmenu_801EE000", func_801F07BC);
