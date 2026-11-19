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

typedef struct Ent800197C0 {
    u8 pad0[3];
    u8 unk3;
    u8 pad4[0x2C];
    u16 unk30[8];
    u16 unk40[0x30];
    u8 padA0[0x2C];
} Ent800197C0;
typedef struct G800197C0 {
    Ent800197C0 ent[0x2C];
    u8 pad2310[0x30AC - 0x2310];
    s16 n;
    s16 pad30AE;
    s32 pad30B0;
    u16 masks[0x2C][8];
    u8 unk3374[0x420];
} G800197C0;
extern G800197C0 D_8006EBC8_h asm("D_8006EBC8");
extern s32 D_8006EB20[];
extern s32 D_8006EB50;
void func_8004582C(s32);
s32 func_80044924(s32);
s32 func_8003D8F4(s32, s32, s32);
void func_80046698(s32 *, s32);
void func_80044EE0(s32);
void func_8003D504(s32);

void func_800197C0(u8 load) {
    s32 i;
    s32 j;
    s32 b;
    s32 k;
    u8 *data;
    u8 v;
    Ent800197C0 *e;
    u16 *m;
    if (load) {
        func_8004582C(6);
        D_8006EB50 = func_8003D8F4(func_80044924(0x7F), 1, 3);
        D_8006EB20[0] = 0x7F;
        D_8006EB20[1] = D_8006EB50;
        D_8006EB20[2] = 0;
        D_8006EB20[3] = 0;
        func_80046698(D_8006EB20, 0x80);
        func_80044EE0(0);
    }
    for (i = 0; i < 0x2C; i++) {
        e = &D_8006EBC8_h.ent[i];
        m = D_8006EBC8_h.masks[i];
        for (j = 0; j < D_8006EBC8_h.n; j++) {
            v = ((u8 *)D_8006EB50)[e->unk3 + j * 8];
            if (v != 0xFF) {
                m[(u8)(v / 10)] |= 1 << (v % 10);
            }
        }
        for (j = 0; j < 0x30; j++) {
            e->unk40[j] |= 0x4000;
        }
        for (j = 0, k = 0; j < 8; j++) {
            for (b = 0; b < 10; b++) {
                if ((e->unk30[j] >> b) & 1) {
                    if ((m[j] >> b) & 1) {
                        e->unk40[k] &= 0xBFFF;
                    } else {
                        e->unk40[k] |= 0x4000;
                    }
                    k++;
                }
            }
        }
    }
    if (!load) {
        u8 *p;
        u8 c = 0x55;
        i = 0x41F;
        for (p = (u8 *)&D_8006EBC8_h + i; i >= 0; i--) {
            p[0x3374] = c;
            p--;
        }
    } else {
        func_8003D504(D_8006EB50);
    }
}

typedef struct E80019A00 {
    u8 pad0[0x16];
    u16 unk16;
    u8 pad18[0x17];
    u8 unk2F;
    u8 pad30[0x88];
    u16 unkB8;
    u8 padBA[0x12];
} E80019A00;
typedef struct G80019A00 {
    E80019A00 ent[0x2C];
    u16 unk2310[0x204];
    u16 unk2718[0x180];
    u8 unk2A18[0x180];
    u16 unk2B98[0xC0];
    u8 unk2D18[0xC0];
    u8 pad2DD8[8];
    s32 unk2DE0;
    u8 pad2DE4[4];
    u8 names[0x2C][0x10];
    s32 unk30A8;
    u8 pad30AC[8];
    u16 masks[0x2C][8];
    u8 unk3374[0x420];
    u8 pad3794[0x10];
    u8 bits[0x18];
} G80019A00;
extern G80019A00 D_8006EBC8_a asm("D_8006EBC8");
extern s32 D_8006EB48;
extern u16 D_80064020[];
extern s32 D_8006EB54;
extern u8 D_8006EBC0;
extern u8 D_8006EB5D;
extern u8 D_80072410;
extern u8 D_8006EB5C;
extern u16 D_80064130[];
extern s16 D_800712AA;
void bzero(void *, s32);
void *memmove(void *, void *, s32);

void func_80019A00(u8 arg0) {
    s32 i;
    s32 j;
    E80019A00 *e;
    u8 *s;
    u8 *f;
    u8 *p;
    u8 *src = (u8 *)D_8006EB48;
    for (i = 0; i < 0x2C; i++, src += 0xB0) {
        e = &D_8006EBC8_a.ent[i];
        bzero(e, 0xCC);
        memmove(e, src, 0xB0);
        e->unk2F = 1;
        e->unkB8 = e->unk16;
        if (arg0) {
            for (j = 0; j < 0x10; j++) {
                D_8006EBC8_a.names[i][j] = 0;
            }
            s = func_80019794(1, i);
            for (j = 0; j < 0xC; j++) {
                D_8006EBC8_a.names[i][j] = *s;
                if (*s == 0) {
                    break;
                }
                s++;
            }
        }
        for (j = 0; j < 8; j++) {
            D_8006EBC8_a.masks[0][i * 8 + j] = D_80064020[j];
        }
    }
    func_8003D504(D_8006EB48);
    for (i = 0; i < 0x180; i++) {
        D_8006EBC8_a.unk2A18[i] = 0;
        D_8006EBC8_a.unk2718[i] = 0;
    }
    for (i = 0; i < 0xC0; i++) {
        D_8006EBC8_a.unk2D18[i] = 0;
        D_8006EBC8_a.unk2B98[i] = 0;
    }
    {
        u8 *q;
        i = 0x41F;
        for (q = (u8 *)&D_8006EBC8_a + i; i >= 0; i--) {
            q[0x3374] = 0;
            q--;
        }
    }
    i = 0x17;
    p = (u8 *)&D_8006EBC8_a + i;
    f = (u8 *)D_8006EB54;
    D_8006EBC8_a.unk2DE0 = 100;
    D_8006EBC0 = 0;
    D_8006EB5D = 0;
    D_80072410 = 0;
    D_8006EBC8_a.unk30A8 = 0;
    D_8006EB5C = 0;
    for (; i >= 0; i--) {
        p[0x37A4] = 0;
        p--;
    }

    for (i = 0; i < 0xC0; i++) {
        if (f[0xA] & 0x40) {
            D_8006EBC8_a.bits[i / 8] |= 1 << (i % 8);
        }
        f += 0x10;
    }
    for (i = 0; i < 0x18; i++) {
        D_8006EBC8_a.unk2310[i + 0x1E8] = D_80064130[i];
    }
    D_800712AA = 0x3F;
}

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

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_8005783C);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_800622E8);

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

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_80062314);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_8006231C);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_80062324);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_80062338);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_8006234C);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_80062354);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_80062368);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_8006237C);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_80062390);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_800623A4);

INCLUDE_RODATA("asm/nonmatchings/game/unk_800191D4", D_800623A8);

typedef struct {
    s32 w0, w1, w2, w3, w4, w5;
    s16 h;
    s16 pad;
    s32 x;
} Unk80064160;
typedef struct {
    s32 fat;
    s32 fid;
    s32 addr;
    Unk80064160 cfg;
} Args8001A448;
extern char D_8006231C[], D_80062324[], D_80062338[], D_8006234C[], D_80062354[], D_80062368[], D_8006237C[], D_80062390[], D_800623A4[], D_800623A8[];
extern u8 D_8006B3F5;
extern u8 D_8006B47A;
extern Unk80064160 D_80064160;

void func_8001A448(void) {
    Args8001A448 a;
    u8 hdr[0x38];
    s32 fd;
    char *path;
    s32 v;
    if (D_8006B3F5 == 0) {
        func_8003DB78(D_8006231C);
        if (D_8006B47A == 2) {
            a.fat = func_80048C00(D_80062324, 0);
        } else {
            a.fat = func_80048C00(D_80062338, 0);
        }
        func_8003DB78(D_8006234C);
        if (D_8006B47A == 2) {
            a.fid = func_80048C00(D_80062354, 0);
        } else {
            a.fid = func_80048C00(D_80062368, 0);
        }
        a.addr = 0x80780000;
        if (D_8006B47A == 2) {
            fd = PCopen(D_8006237C, 0, 0);
        } else {
            fd = PCopen(D_80062390, 0, 0);
        }
        PCread(fd, 0x80780000, func_8033C948(fd));
        func_80028614(fd);
    } else {
        func_8003DB78(D_800623A4);
        a.fat = func_8003D8F4(0x60E0, 1, 1);
        func_8003DB78(D_800623A8);
        a.fid = func_8003D8F4(0x22, 1, 1);
        a.addr = 0;
    }
    a.cfg.w0 = D_80064160.w0;
    a.cfg.w1 = D_80064160.w1;
    a.cfg.w2 = D_80064160.w2;
    a.cfg.w3 = D_80064160.w3;
    a.cfg.w4 = D_80064160.w4;
    a.cfg.w5 = D_80064160.w5;
    a.cfg.h = D_80064160.h;
    func_80043F90(&a);
    if (D_8006B3F5 != 0) {
        func_80045E78(0x17, hdr, 0x2C, 0);
        func_80044EE0(0);
        if (*(s32 *)(hdr + 0x20) == 0x4F524843 && *(s32 *)(hdr + 0x24) == 0x52434F4E) {
            v = hdr[0];
            if (v == 1) {
                D_8006B47A = v;
            }
            if (v == 2) {
                D_8006B47A = v;
            }
        }
    }
}

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
