#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", ResetGraph);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetGraphDebug);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetGraphQueue);

extern u8 D_80063DE2;
s32 GetGraphDebug(void) {
    return D_80063DE2;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawSyncCallback);

typedef struct { u8 ver, x, lvl, y; } GENV_m;
extern volatile GENV_m D_80063DE0_m asm("D_80063DE2-2");
extern s32 (*D_80063DDC_g)(char *, ...) asm("D_80063DDC");
typedef struct { void *f[16]; } GPUFN_dm;
extern GPUFN_dm *D_80063DD8_dm asm("D_80063DD8");
extern char D_80056648[];
void func_80014B3C(u8 *, s32, s32);
void SetDispMask(s32 mask) {
    if (D_80063DE0_m.lvl >= 2) {
        D_80063DDC_g(D_80056648, mask);
    }
    if (mask == 0) {
        func_80014B3C((u8 *)&D_80063DE0_m + 0x6C, -1, 0x14);
    }
    ((void (*)(u32))D_80063DD8_dm->f[4])(mask ? 0x03000000 : 0x03000001);
}

typedef struct { void *f[16]; } GPUFN_D;
extern GPUFN_D *D_80063DD8_D asm("D_80063DD8");
extern u8 D_80063DE2;
extern s32 (*D_80063DDC_D)(char *, ...) asm("D_80063DDC");
extern char D_8005665C[];
s32 DrawSync(s32 mode) {
    if (D_80063DE2 >= 2) {
        D_80063DDC_D(D_8005665C, mode);
    }
    return ((s32 (*)(s32))D_80063DD8_D->f[15])(mode);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80012018);

typedef struct { void *f[16]; } GPUFN_C;
extern GPUFN_C *D_80063DD8_C asm("D_80063DD8");
extern char D_80056694[];
void func_80012018_C(char *, void *) asm("func_80012018");
s32 ClearImage(void *rect, u8 r, u8 g, u8 b) {
    func_80012018_C(D_80056694, rect);
    return ((s32 (*)(void *, void *, s32, u32))D_80063DD8_C->f[2])(D_80063DD8_C->f[3], rect, 8,
                                                                    (b << 16) | (g << 8) | r);
}

typedef struct { void *f[16]; } GPUFN_C2;
extern GPUFN_C2 *D_80063DD8_C2 asm("D_80063DD8");
extern char D_800566A0[];
void func_80012018_C2(char *, void *) asm("func_80012018");
s32 ClearImage2(void *rect, u8 r, u8 g, u8 b) {
    func_80012018_C2(D_800566A0, rect);
    return ((s32 (*)(void *, void *, s32, u32))D_80063DD8_C2->f[2])(D_80063DD8_C2->f[3], rect, 8,
                                                                     0x80000000 | (b << 16) | (g << 8) | r);
}

typedef struct { void *f[16]; } GPUFN_L;
extern GPUFN_L *D_80063DD8_L asm("D_80063DD8");
extern char D_800566AC[];
void func_80012018_L(char *, void *) asm("func_80012018");
s32 LoadImage(void *rect, u32 *p) {
    func_80012018_L(D_800566AC, rect);
    return ((s32 (*)(void *, void *, s32, u32 *))D_80063DD8_L->f[2])(D_80063DD8_L->f[8], rect, 8, p);
}

typedef struct { void *f[16]; } GPUFN_S;
extern GPUFN_S *D_80063DD8_S asm("D_80063DD8");
extern char D_800566B8[];
void func_80012018_S(char *, void *) asm("func_80012018");
s32 StoreImage(void *rect, u32 *p) {
    func_80012018_S(D_800566B8, rect);
    return ((s32 (*)(void *, void *, s32, u32 *))D_80063DD8_S->f[2])(D_80063DD8_S->f[7], rect, 8, p);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", MoveImage);

typedef struct { unsigned addr : 24; unsigned len : 8; } TAG_c;
typedef struct { void *f[16]; } GPUFN_T;
extern u8 D_80063DE2;
extern s32 (*D_80063DDC_T)(char *, ...) asm("D_80063DDC");
extern char D_800566D0[];
extern u32 D_80063EA0;
extern u8 D_80063E8C[];
u32 *ClearOTag(u32 *ot, s32 n) {
    u32 *t;
    if (D_80063DE2 >= 2) {
        D_80063DDC_T(D_800566D0, ot, n);
    }
    while (--n) {
        ((TAG_c *)ot)->len = 0;
        ((TAG_c *)ot)->addr = (u32)(ot + 1);
        ot++;
    }
    t = &D_80063EA0;
    *t = ((u32)D_80063E8C & 0xFFFFFF) | 0x04000000;
    *ot = (u32)t & 0xFFFFFF;
    return ot;
}

typedef struct { void *f[16]; } GPUFN_R;
extern GPUFN_R *D_80063DD8_R asm("D_80063DD8");
extern u8 D_80063DE2;
extern s32 (*D_80063DDC_R)(char *, ...) asm("D_80063DDC");
extern char D_800566E8[];
extern u32 D_80063EA0;
extern u8 D_80063E8C[];
u32 *ClearOTagR(u32 *ot, s32 n) {
    u32 *t;
    if (D_80063DE2 >= 2) {
        D_80063DDC_R(D_800566E8, ot, n);
    }
    ((void (*)(u32 *, s32))D_80063DD8_R->f[11])(ot, n);
    t = &D_80063EA0;
    *t = ((u32)D_80063E8C & 0xFFFFFF) | 0x04000000;
    *ot = (u32)t & 0xFFFFFF;
    return ot;
}

typedef struct { void (*f[16])(); } GPUFN_d;
extern GPUFN_d *D_80063DD8_d asm("D_80063DD8");
void DrawPrim(u8 *p) {
    s32 n = p[3];
    D_80063DD8_d->f[15](0);
    D_80063DD8_d->f[5](p + 4, n);
}

typedef struct { void *f[16]; } GPUFN_O;
extern GPUFN_O *D_80063DD8_O asm("D_80063DD8");
extern u8 D_80063DE2;
extern s32 (*D_80063DDC_O)(char *, ...) asm("D_80063DDC");
extern char D_80056700[];
void DrawOTag(u32 *ot) {
    if (D_80063DE2 >= 2) {
        D_80063DDC_O(D_80056700, ot);
    }
    ((void (*)(void *, u32 *, s32, s32))D_80063DD8_O->f[2])(D_80063DD8_O->f[6], ot, 0, 0);
}

typedef struct { u8 ver, x, lvl, y; } GENV_p;
extern volatile GENV_p D_80063DE0_p asm("D_80063DE2-2");
extern s32 (*D_80063DDC_g)(char *, ...) asm("D_80063DDC");
typedef struct { void *f[16]; } GPUFN_pd;
extern GPUFN_pd *D_80063DD8_pd asm("D_80063DD8");
extern char D_80056714[];
void func_80012FF4_p(void *, void *) asm("func_80012FF4");
void *memcpy(void *, void *, s32);
u8 *PutDrawEnv(u8 *env) {
    GPUFN_pd *g;
    if (D_80063DE0_p.lvl >= 2) {
        D_80063DDC_g(D_80056714, env);
    }
    func_80012FF4_p(env + 0x1C, env);
    g = D_80063DD8_pd;
    *(u32 *)(env + 0x1C) |= 0xFFFFFF;
    ((void (*)(void *, void *, s32, s32))g->f[2])(g->f[6], env + 0x1C, 0x40, 0);
    memcpy((u8 *)&D_80063DE0_p + 0x10, env, 0x5C);
    return env;
}

typedef struct { u8 ver, x, lvl, y; } GENV_o;
extern volatile GENV_o D_80063DE0_o asm("D_80063DE2-2");
extern s32 (*D_80063DDC_g)(char *, ...) asm("D_80063DDC");
typedef struct { void *f[16]; } GPUFN_od;
extern GPUFN_od *D_80063DD8_od asm("D_80063DD8");
extern char D_8005672C[];
void func_80012FF4_o(void *, void *) asm("func_80012FF4");
void *memcpy(void *, void *, s32);
void DrawOTagEnv(u32 *ot, u8 *env) {
    GPUFN_od *g;
    if (D_80063DE0_o.lvl >= 2) {
        D_80063DDC_g(D_8005672C, ot, env);
    }
    func_80012FF4_o(env + 0x1C, env);
    g = D_80063DD8_od;
    *(u32 *)(env + 0x1C) = (*(u32 *)(env + 0x1C) & 0xFF000000) | ((u32)ot & 0xFFFFFF);
    ((void (*)(void *, void *, s32, s32))g->f[2])(g->f[6], env + 0x1C, 0x40, 0);
    memcpy((u8 *)&D_80063DE0_o + 0x10, env, 0x5C);
}

extern u8 D_80063DF0[];
void *memcpy(void *, void *, s32);
void *GetDrawEnv(void *env) {
    memcpy(env, D_80063DF0, 0x5C);
    return env;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", PutDispEnv);

extern u8 D_80063E4C[];
void *GetDispEnv(void *env) {
    memcpy(env, D_80063E4C, 0x14);
    return env;
}

typedef struct { u8 pad[0x38]; u32 (*status)(void); } GpuFuncs;
extern GpuFuncs *D_80063DD8;
u32 GetODE(void) {
    return D_80063DD8->status() >> 31;
}

typedef struct { s16 x, y, w, h; } RECT_da;
u32 func_80013284_a(s32, s32) asm("func_80013284");
u32 func_8001331C_a(s32, s32) asm("func_8001331C");
void SetDrawArea(u32 *p, RECT_da *r) {
    ((u8 *)p)[3] = 2;
    p[1] = func_80013284_a(r->x, r->y);
    p[2] = func_8001331C_a((s16)(r->x + r->w - 1), (s16)(r->y + r->h - 1));
}

u32 func_800133B4_s(s32, s32) asm("func_800133B4");
void SetDrawOffset(u8 *p, s16 *ofs) {
    p[3] = 2;
    *(u32 *)(p + 4) = func_800133B4_s(ofs[0], ofs[1]);
    *(u32 *)(p + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetDrawEnv);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80012FF4);

/* _get_mode */
u32 func_80013264(s32 dfe, s32 dtd, s32 tpage) {
    return (dtd ? 0xe1000200 : 0xe1000000) | (dfe ? 0x400 : 0) | (tpage & 0x9ff);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013284);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_8001331C);

u32 func_800133B4(u16 x, u16 y) {
    return 0xe5000000 | ((y & 0x7ff) << 11) | (x & 0x7ff);
}

typedef struct { s16 x, y, w, h; } RECT_gt;
u32 func_800133D0(RECT_gt *tw) {
    s32 pat[4];
    if (tw) {
        pat[0] = (tw->x & 0xFF) >> 3;
        pat[2] = ((-tw->w) & 0xFF) >> 3;
        pat[1] = (tw->y & 0xFF) >> 3;
        pat[3] = ((-tw->h) & 0xFF) >> 3;
        return 0xE2000000 | (pat[1] << 15) | (pat[0] << 10) | (pat[3] << 5) | pat[2];
    }
    return 0;
}

extern volatile u32 *D_80063EE8;
u32 func_80013450(void) {
    return *D_80063EE8;
}

extern volatile u32 *D_80063F04_t asm("D_80063F04");
extern volatile u32 *D_80063F00_t asm("D_80063F00");
extern volatile u32 *D_80063EF8_t asm("D_80063EF8");
extern volatile u32 *D_80063EFC_t asm("D_80063EFC");
void func_800144E4(void);
s32 func_80014518(void);
s32 func_80013468(u32 *a, s32 n) {
    *D_80063F04_t |= 0x08000000;
    *D_80063F00_t = 0;
    *D_80063EF8_t = (u32)&a[n - 1];
    *D_80063EFC_t = n;
    *D_80063F00_t = 0x11000002;
    func_800144E4();
    while (*D_80063F00_t & 0x01000000) {
        if (func_80014518()) {
            return -1;
        }
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013548);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013778);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800139B4);

extern u8 D_8006CEB8[];
void func_80013C34(u32 x) {
    *D_80063EE8 = x;
    D_8006CEB8[x >> 24] = x;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013C58);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013C6C);

extern volatile u32 *D_80063EE8_r asm("D_80063EE8");
extern volatile u32 *D_80063EEC_r asm("D_80063EEC");
extern volatile u32 *D_80063EF0_r asm("D_80063EF0");
extern volatile u32 *D_80063EF4_r asm("D_80063EF4");
void func_80013CAC(u32 x) {
    *D_80063EE8_r = 0x04000002;
    *D_80063EEC_r = x;
    *D_80063EF0_r = 0;
    *D_80063EF4_r = 0x01000401;
}

extern volatile u32 *D_80063EE8_f asm("D_80063EE8");
extern volatile u32 *D_80063EE4;
u32 func_80013CF4(u32 x) {
    *D_80063EE8_f = x | 0x10000000;
    return *D_80063EE4 & 0xFFFFFF;
}

void func_80013D48(s32, s32, s32, s32);
void func_80013D24(s32 a, s32 b, s32 c) {
    func_80013D48(a, b, 0, c);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013D48);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013FF8);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80014258);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800143A8);

s32 VSync(s32);
extern s32 D_80063F1C;
extern s32 D_80063F20;
void func_800144E4(void) {
    D_80063F1C = VSync(-1) + 0xF0;
    D_80063F20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80014518);

extern volatile u32 *D_80063EE8_q asm("D_80063EE8");
extern volatile u32 *D_80063EE4_q asm("D_80063EE4");
s32 func_8001465C(s32 mode) {
    *D_80063EE8_q = 0x10000007;
    if ((*D_80063EE4_q & 0xFFFFFF) != 2) {
        *D_80063EE4_q = (*D_80063EE8_q & 0x3FFF) | 0xE1001000;
        *D_80063EE4_q;
        return 0;
    }
    if (!(mode & 8)) {
        return 1;
    }
    *D_80063EE8_q = 0x09000001;
    return 2;
}

typedef struct { void *f[16]; } GPUFN_L2;
extern GPUFN_L2 *D_80063DD8_L2 asm("D_80063DD8");
extern char D_80056794[];
extern volatile u32 *D_80063EF4_l asm("D_80063EF4");
extern volatile u32 *D_80063EE8_l asm("D_80063EE8");
extern s32 D_80063F1C_l asm("D_80063F1C");
extern s32 D_80063F20_l asm("D_80063F20");
void func_80012018_L2(char *, void *) asm("func_80012018");
s32 VSync_l(s32) asm("VSync");
s32 func_80014518(void);
void DMACallback_l(s32, void *) asm("DMACallback");
void _GPU_ResetCallback(void);
s32 LoadImage2(void *r, u32 *p) {
    func_80012018_L2(D_80056794, r);
    D_80063F1C_l = VSync_l(-1) + 0xF0;
    D_80063F20_l = 0;
    while ((*D_80063EF4_l & 0x01000000) || !(*D_80063EE8_l & 0x04000000)) {
        if (func_80014518()) {
            return -1;
        }
    }
    DMACallback_l(2, _GPU_ResetCallback);
    ((void (*)(void *, u32 *))D_80063DD8_L2->f[8])(r, p);
    return 0;
}

typedef struct { void *f[16]; } GPUFN_S2;
extern GPUFN_S2 *D_80063DD8_S2 asm("D_80063DD8");
extern char D_800566B8[];
extern volatile u32 *D_80063EF4_l asm("D_80063EF4");
extern volatile u32 *D_80063EE8_l asm("D_80063EE8");
extern s32 D_80063F1C_l asm("D_80063F1C");
extern s32 D_80063F20_l asm("D_80063F20");
void func_80012018_S2(char *, void *) asm("func_80012018");
s32 VSync_l(s32) asm("VSync");
s32 func_80014518(void);
void DMACallback_l(s32, void *) asm("DMACallback");
void _GPU_ResetCallback(void);
s32 StoreImage2(void *r, u32 *p) {
    func_80012018_S2(D_800566B8, r);
    D_80063F1C_l = VSync_l(-1) + 0xF0;
    D_80063F20_l = 0;
    while ((*D_80063EF4_l & 0x01000000) || !(*D_80063EE8_l & 0x04000000)) {
        if (func_80014518()) {
            return -1;
        }
    }
    DMACallback_l(2, _GPU_ResetCallback);
    ((void (*)(void *, u32 *))D_80063DD8_S2->f[7])(r, p);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", MoveImage2);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawOTag2);

void DMACallback(s32, void (*)(void));
void func_80013FF8(void);
void _GPU_ResetCallback(void) {
    DMACallback(2, func_80013FF8);
}

void func_80014B3C(u8 *p, s32 c, s32 n) {
    while (--n != -1) {
        *p++ = c;
    }
}
