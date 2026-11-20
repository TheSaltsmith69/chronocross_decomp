#include "common.h"

extern s32 D_8007EE20[];
extern s32 D_1F80000C;
extern s32 D_1F800014;
extern s32 D_8007EE1C;
extern u8 D_800635E4[];
extern s32 D_8007EE40[];
extern u8 D_805F5F78[];
extern u8 D_806097F8[];
extern s32 D_8007EE38;
extern s32 D_8006B3FC;

void func_8003CB78(s32 size, s32 arg1) {
    s32 p;
    D_8007EE1C = size;
    func_8003DB78(D_800635E4);
    p = func_8003D8F4(size * 2, arg1, 1);
    D_8007EE20[0] = p;
    D_8007EE20[1] = p + size;
    D_8007EE40[0] = (s32)D_805F5F78;
    D_8007EE40[1] = (s32)D_806097F8;
    D_1F800014 = p;
    D_8007EE38 = p;
    D_8006B3FC = 0;
    D_1F80000C = p + D_8007EE1C;
}

extern s32 D_8007EE30[];
extern s32 D_8007EE28[];
extern s32 D_8007EE18;
void func_8003CC2C(s32 i) {
    s32 v;
    D_8007EE30[1] = D_8007EE38;
    D_8007EE30[0] = D_1F800014;
    v = D_8007EE20[i];
    D_8007EE28[0] = i;
    D_8007EE18 = D_8007EE40[i];
    D_1F800014 = v;
    D_8007EE38 = v;
    D_1F80000C = v + D_8007EE1C - D_8006B3FC - 0x400;
}

extern s32 D_8007EE20[];
extern s32 D_1F80000C;
extern s32 D_1F800014;
void func_8003D504(s32);
void func_8003CCB0(void) {
    func_8003D504(D_8007EE20[0]);
    D_8007EE20[0] = 0;
    D_8007EE20[1] = 0;
    D_1F80000C = 0;
    D_1F800014 = 0;
}

typedef struct { s32 a, b; } P8CCF8;
extern P8CCF8 *D_1F800014_p asm("D_1F800014");
void f_AddPrim_a(void *, void *) asm("AddPrim");
void func_8003CCF8(void *arg0, P8CCF8 *arg1) {
    P8CCF8 *p = D_1F800014_p;
    *p = *arg1;
    D_1F800014_p = p + 1;
    f_AddPrim_a(arg0, p);
}

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_800635E4);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_800635F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003CD38);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D070);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_80063674);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8003CB78", D_8006368C);

typedef struct Hdr8003D370 {
    struct Hdr8003D370 *next;
    u32 prev : 21;
    u32 used : 3;
    u32 rest : 8;
} Hdr8003D370;
extern u8 D_8006B3F4;
extern s8 D_8006B3EC;
extern Hdr8003D370 *D_8007EE54_ asm("D_8007EE54");
extern char D_80063674[];
extern char D_8006368C[];

void func_8003D370(u8 *p, s32 size) {
    Hdr8003D370 *h;
    Hdr8003D370 *nx;
    Hdr8003D370 *n;
    if (D_8006B3F4 != 0 && D_8006B3EC != 0) {
        Hdr8003D370 *r;
        u8 found = 0;
        func_8033B4B4();
        for (r = D_8007EE54_; r != NULL; r = r->next) {
            if (r == (Hdr8003D370 *)(p - 8)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            func_80029DD8(D_80063674, p);
            return;
        }
    }
    nx = ((Hdr8003D370 *)(p - 8))->next;
    h = (Hdr8003D370 *)(p - 8);
    if ((u8 *)nx - p < size) {
        func_80029DD8(D_8006368C);
        return;
    }
    n = (Hdr8003D370 *)((u8 *)h + (size + 8));
    if (nx == n || (u32)((u8 *)nx - (u8 *)n) < 8) {
        return;
    }
    n->used = h->used;
    n->next = ((Hdr8003D370 *)(p - 8))->next;
    n->prev = ((u32)h & 0x7FFFFF) >> 2;
    nx->prev = ((u32)n & 0x7FFFFF) >> 2;
    ((Hdr8003D370 *)(p - 8))->next = n;
    if (D_8006B3F4 != 0 && D_8006B3EC != 0) {
        func_8033CAA0();
    }
    func_8003D504((s32)(n + 1));
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D504);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003D704);

extern u8 D_8007EE5C;
void func_8003D8A8(s32 arg0) {
    D_8007EE5C = arg0;
}

extern s32 D_8007EE50;
s32 func_8003CD38(s32, s32);

s32 func_8003D8B4(s32 size, s32 a1, s32 a2) {
    s32 ra;
    __asm__ volatile("sw $ra, 0(%0)" : : "r"(&ra));
    a2 = 7;
    D_8007EE5C = a2;
    D_8007EE50 = ra;
    return func_8003CD38(size, 1);
}

s32 func_8003D8F4(s32 size, s32 arg1, s32 arg2) {
    s32 ra;
    __asm__ volatile("sw $ra, 0(%0)" : : "r"(&ra));
    D_8007EE5C = arg2;
    D_8007EE50 = ra;
    return func_8003CD38(size, arg1);
}

typedef struct MemBlk8003D92C {
    struct MemBlk8003D92C *next;
    u32 prev : 21;
    u32 used : 3;
    u32 rest : 8;
} MemBlk8003D92C;
extern MemBlk8003D92C *D_8007EE54_b asm("D_8007EE54");
extern MemBlk8003D92C *D_8007EE48_b asm("D_8007EE48");
extern u8 D_8007EE5C;
extern u8 D_8006B3F7;

void func_8003D92C(MemBlk8003D92C *heap, s32 size) {
    MemBlk8003D92C *end;
    D_8007EE54_b = heap;
    end = (MemBlk8003D92C *)((u8 *)heap + size) - 1;
    heap->prev = 0;
    heap->next = end;
    heap->used = 0;
    D_8007EE48_b = end;
    end->prev = ((u32)heap & 0x7FFFFF) >> 2;
    D_8007EE5C = 1;
    end->next = NULL;
    end->used = 1;
    if (D_8006B3F7 == 0) {
        func_80336E48();
        func_8033CAA0();
    }
}

typedef struct Blk3D9E0 { struct Blk3D9E0 *next; u32 flags; } Blk3D9E0;
extern Blk3D9E0 *D_8007EE54_z9 asm("D_8007EE54");
extern s32 D_8006B430_z9 asm("D_8006B430");
extern s32 D_8006B434_z9 asm("D_8006B434");
extern void *D_8006B438_z9 asm("D_8006B438");
s32 func_8003D9E0(void) {
    Blk3D9E0 *b = D_8007EE54_z9;
    D_8006B430_z9 = 0;
    D_8006B434_z9 = 0;
    for (; b != NULL; b = b->next) {
        s32 sz = ((u8 *)b->next - (u8 *)b) & 0x7FFFFF;
        if (b->next == NULL) {
            sz = 0;
        }
        if (((b->flags >> 21) & 7) == 0) {
            if (D_8006B434_z9 < sz) {
                D_8006B438_z9 = (u8 *)b + 0x40;
                D_8006B434_z9 = sz;
            }
            D_8006B430_z9 += sz;
        }
    }
    return D_8006B434_z9 - 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DA88);

extern u8 D_8006B3F4_b asm("D_8006B3F4");
extern s8 D_8006B3EC_c asm("D_8006B3EC");
u8 f_33B4B4_a(void) asm("func_8033B4B4");
u8 func_8003DB34(void) {
    if (D_8006B3F4_b != 0 && D_8006B3EC_c != 0) {
        return f_33B4B4_a();
    }
}

extern s32 D_8007EE4C;
void func_8003DB78(s32 arg0) {
    D_8007EE4C = arg0;
}

extern char D_800635F4[];
void VSync(s32);
void func_803395E8(void);
void func_8003DB84(MemBlk8003D92C *n) {
    MemBlk8003D92C *b = D_8007EE54_b;
    MemBlk8003D92C *next;
    u32 t;
    if (D_8006B3F4 != 0 && (u32)b->next < (u32)(n + 1)) {
        func_80029DD8(D_800635F4);
        VSync(60);
        func_803395E8();
        VSync(60);
        func_803395E8();
        return;
    }
    t = ((u32)n & 0x7FFFFF) >> 2;
    next = b->next;
    b = n;
    next->prev = t;
    D_8007EE54_b = b;
    b->prev = 0;
    b->next = next;
    b->used = 0;
    if (D_8006B3F4 != 0) {
        func_8033CAA0();
    }
}

s32 func_8003DC64(s32 *arg0) {
    return arg0[-2] - (s32)arg0;
}

void func_8003DC70(void) {
    Blk3D9E0 *b = D_8007EE54_z9;
    D_8006B430_z9 = 0;
    D_8006B434_z9 = 0;
    for (; b != NULL; b = b->next) {
        s32 sz = ((u8 *)b->next - (u8 *)b) & 0x7FFFFF;
        if (b->next == NULL) {
            sz = 0;
        }
        if (((b->flags >> 21) & 7) == 0) {
            if (D_8006B434_z9 < sz) {
                D_8006B438_z9 = (u8 *)b + 0x40;
                D_8006B434_z9 = sz;
            }
            D_8006B430_z9 += sz;
        }
    }
}

void f_3D504_t(void) asm("func_8003D504");
void func_8003DD14(void) {
    f_3D504_t();
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003CB78", func_8003DD34);
