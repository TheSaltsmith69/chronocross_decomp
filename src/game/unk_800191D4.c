#include "common.h"

typedef struct {
    u8 pad0[0x2DE7];
    u8 unk2DE7;
    u8 pad2DE8[0x30AC - 0x2DE8];
    s16 unk30AC;
    s16 unk30AE;
    s32 unk30B0;
} Unk8006EBC8;
extern Unk8006EBC8 D_8006EBC8;

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_800191D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_800192E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019510);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019550);

extern u16 D_8006EBB6;
extern u8 D_80064030[];

u16 func_80019690(u16 lo, u16 hi) {
    s32 range;
    if (lo == 0xFFFF) {
        return 0xFFFF;
    }
    if (hi == 0) {
        return 0;
    }
    if (lo == hi) {
        return lo;
    }
    if (hi >= 0x100) {
        range = hi - lo;
        if (range > 0xFFFE) {
            return rand();
        }
        return lo + (u16)rand() % (range + 1);
    }
    if (++D_8006EBB6 >= 0x100) {
        D_8006EBB6 = 0;
    }
    return lo + D_80064030[D_8006EBB6] % (hi - lo + 1);
}

typedef struct {
    s32 count;
    s32 offsets[1];
} Unk8005783C;
extern Unk8005783C D_8005783C;
u8 *func_80019794(s32 arg0, s32 arg1) {
    u8 *p = (u8 *)&D_8005783C + D_8005783C.offsets[arg0];
    return p + ((u16 *)p)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_800197C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019A00);

extern u32 D_8006EB58;

u32 func_80019CD4(s32 arg0) {
    u32 t = (u16)func_80019690(1, 999);
    u32 m = arg0 * 1000;
    t *= m;
    t /= D_8006EB58;
    t *= 2;
    if (t % 1000000 > 499999) {
        t += 1000000;
    }
    return t / 1000000;
}

typedef struct {
    u8 pad0[0x16];
    s16 unk16;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[0xBC - 0x1E];
    u16 unkBC;
    u16 unkBE;
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
    u8 unkC8;
    u8 unkC9;
    u8 unkCA;
    u8 unkCB;
} Char80019DA0;
extern u32 D_8006EB58;
extern s32 D_8006EB4C;

void func_80019DA0(void) {
    s32 i;
    Char80019DA0 *c;
    u8 *g;
    i = 0;
    c = (Char80019DA0 *)&D_8006EBC8;
    D_8006EB58 = 0x65 - D_8006EBC8.unk30AC;
    for (; i < 44; i++) {
        c = &((Char80019DA0 *)&D_8006EBC8)[i];
        g = (u8 *)D_8006EB4C + i * 8;
        c->unkBC = c->unk16;
        c->unkC0 = c->unk18;
        c->unkC2 = c->unk1A;
        c->unkC4 = c->unk19;
        c->unkC6 = c->unk1B;
        c->unkC8 = c->unk1C;
        c->unkCA = c->unk1D;
        c->unkBE = func_80019CD4(*(u16 *)g - c->unk16) + 2;
        c->unkC1 = func_80019CD4(g[2] - c->unk18);
        c->unkC3 = func_80019CD4(g[4] - c->unk1A);
        c->unkC5 = func_80019CD4(g[3] - c->unk19);
        c->unkC7 = func_80019CD4(g[5] - c->unk1B);
        c->unkC9 = func_80019CD4(g[6] - c->unk1C);
        c->unkCB = func_80019CD4(g[7] - c->unk1D);
    }
}

extern s32 D_8006EB20[];
extern s32 D_8006EB48;
extern s32 D_8006EB4C;
extern s32 D_8006EB50;
extern s32 D_8006EB54;

void func_80019ED8(u16 id) {
    func_8004582C(6);
    D_8006EB48 = func_8003D8F4(func_80044924(id), 1, 3);
    D_8006EB20[0] = id;
    D_8006EB20[1] = D_8006EB48;
    D_8006EB4C = func_8003D8F4(func_80044924(id + 1), 1, 3);
    D_8006EB20[2] = id + 1;
    D_8006EB20[3] = D_8006EB4C;
    D_8006EB50 = func_8003D8F4(func_80044924(id + 2), 1, 3);
    D_8006EB20[4] = id + 2;
    D_8006EB20[5] = D_8006EB50;
    D_8006EB54 = func_8003D8F4(func_80044924(0x8F), 1, 3);
    D_8006EB20[6] = 0x8F;
    D_8006EB20[7] = D_8006EB54;
    D_8006EB20[8] = 0;
    D_8006EB20[9] = 0;
    func_80046698(D_8006EB20, 0x80);
    func_80044EE0(0);
}

extern s32 D_8006EB4C;
extern s32 D_8006EB50;
extern s32 D_8006EB54;

void func_80019FE4(void) {
    func_80019ED8(0x79);
    func_80019A00(1);
    D_8006EBC8.unk30B0 = 2;
    D_8006EBC8.unk30AE = 20;
    D_8006EBC8.unk30AC = 20;
    D_8006EBC8.unk2DE7 = 0xFF;
    func_80019DA0();
    func_800197C0(0);
    func_8003D504(D_8006EB4C);
    func_8003D504(D_8006EB50);
    func_8003D504(D_8006EB54);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A06C);

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
} Unk80072418;
extern Unk80072418 D_80072418[];
void func_80029D9C(void);
void func_8001A0E0(s32 arg0, s32 arg1, u32 arg2) {
    Unk80072418 *p;
    if (arg2 >= 16) {
        func_80029D9C();
    }
    p = &D_80072418[arg2];
    p->unk0 = arg0;
    p->unk4 = arg1;
    p->unk8 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A14C);

typedef struct {
    s16 x, y, w, h;
} RECT_8001A350;
typedef struct {
    s16 v[4];
} Unk80062314;
extern s32 D_80042AE4;
extern Unk80062314 D_80062314;

void func_8001A350(void) {
    RECT_8001A350 r;
    Unk80062314 buf;
    ResetGraph(0);
    VSync(0);
    r.x = 0;
    r.y = 0;
    r.w = 0x400;
    r.h = 0x200;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
    VSync(0);
    SetDispMask(0);
    VSync(0);
    if (D_80042AE4 == 0) {
        SsUtReverbOff();
    }
    func_80049F90();
    InitGeom();
    func_8001C12C();
    func_8002B5C0();
    buf = D_80062314;
    func_80029C3C(&buf);
    func_8001C164();
    func_8003D92C(0x80120000, 0xDF000);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A448);

typedef struct {
    s16 x, y, w, h;
} RECT_8001;
void func_8003F7D4(void);
void func_800306AC(s32, s32);
void func_8003073C(s32, s32, s32, s32, s32, s32);
void VSyncCallback(void (*)());
void func_8003F414();
extern u8 D_8006B394;
void func_8001A654(void) {
    RECT_8001 unused;
    func_8003F7D4();
    func_800306AC(0x3C0, 0x1F7);
    func_8003073C(0x10, 0x10, 0x140, 0xF0, 0, 0x200);
    VSyncCallback(func_8003F414);
    D_8006B394 = 0;
}
