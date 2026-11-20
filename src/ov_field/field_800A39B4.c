#include "common.h"

typedef struct { u8 p[0x3374]; u8 t[1]; } S8006EBC8h;
extern S8006EBC8h D_8006EBC8_h asm("D_8006EBC8");
extern u8 *D_800E4190[];
extern u8 D_800E3A04[];
typedef struct { u8 p[0x5C]; u32 f[1]; } S800E3A50_5C;
extern S800E3A50_5C D_800E3A50_5C asm("D_800E3A50");
typedef struct { u8 p[0x1A4]; s32 a; s32 b; s32 c; u8 q[0x2FC - 0x1B0]; s16 h; } S800E3A50_h;
extern S800E3A50_h D_800E3A50_h asm("D_800E3A50");
void func_800AD2C0(s32, s32, s32, s32, s32, s32);
extern s32 D_8007E6C0[];
extern s32 D_800E6480;
extern u8 *D_1F800004;
typedef struct { u16 h0; u16 a[20]; u16 b[20]; u16 h52; u16 h54; } S800E6910;
extern S800E6910 D_800E6910;

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A39B4);

void ResetCallback(void);
void func_800A3D58(s32);

/* PsyQ libpress DecDCTReset */
void func_800A3AA4(s32 mode) {
    if (mode == 0) {
        ResetCallback();
    }
    func_800A3D58(mode);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3AD8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3B64);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3BFC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3C78);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3C98);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3CD4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3D10);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3D34);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3D58);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3E48);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3ED8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3F64);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A3FF8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A408C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A40A4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4124);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4154);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A44A4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4518);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4574);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4874);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A49E4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4AC4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4C4C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4DB0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4DE4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4E0C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A4F44);

typedef struct { u8 pad[0x64]; s16 x64; s16 x66; s16 x68; s16 x6A; u8 rest[0x4090 - 0x6C]; } S8007EE88;
extern S8007EE88 D_8007EE88_s[2] asm("D_8007EE88");
void func_800A5150(void) {
    D_8007EE88_s[0].x66 = 10;
    D_8007EE88_s[1].x66 = 10;
    D_8007EE88_s[0].x68 = 0x100;
    D_8007EE88_s[1].x68 = 0x100;
    D_8007EE88_s[0].x64 = 0;
    D_8007EE88_s[1].x64 = 0;
    D_8007EE88_s[0].x6A = 0xD8;
    D_8007EE88_s[1].x6A = 0xD8;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A5188);

void ResetGraph(s32);
void InitGeom(void);
void func_80026784(s32, s32);
void func_800267A4(s32);
void func_800A5188(void);
void SetFarColor(s32, s32, s32);
void SetFogNear(s32, s32);
void SetBackColor(s32, s32, s32);
void func_800A5240(void) {
    ResetGraph(1);
    InitGeom();
    func_80026784(0xA0, 0x78);
    func_800267A4(0x80);
    func_800A5188();
    SetFarColor(0xFF, 0xFF, 0xFF);
    SetFogNear(0xBB8, 0x500);
    SetBackColor(0, 0, 0);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A52B0);

void func_800A544C(u32 *p, s32 n) {
    n = n / 2;
    while (--n != -1) {
        *p++ |= 0x80008000;
    }
}

void func_800A5490(u32 *p, s32 n) {
    n = n / 2;
    while (--n != -1) {
        *p++ &= 0x7FFF7FFF;
    }
}

void func_80033588(s32, s32, s32, s32, s32);
void func_800A54D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80033588(arg0, arg3, arg4, arg1, arg2);
    DrawSync(0);
}

void func_8004582C(s32);
s32 func_80044924(s32);
void func_80045F14(s32, u8 *, s32);
extern u8 *D_800724E8;
void func_800A550C(s32 arg0) {
    s32 n;
    u8 *p;
    func_8004582C(5);
    n = arg0 * 3 + 0x85;
    p = func_8003D8F4(func_80044924(n), 1, 2);
    D_800724E8 = p;
    func_80045F14(n, p, 0);
}

extern s16 D_8007E6A8;
s32 func_80044DD4(void);
s32 func_800A5578(void) {
    if (func_80044DD4() != 0) {
        return -1;
    }
    D_8007E6A8 = -1;
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A55B4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A565C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A570C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A58B4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A593C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A5A28);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A5B14);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A5C00);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A66A0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A67EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A6E0C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A6F74);

extern u16 D_800E417E;
extern s16 D_800E4180;
extern s16 D_800E5620;
extern s16 D_800E5622;
extern s16 D_800E5758;
extern s16 D_800E575C;
extern u16 D_800E39BC;
extern s16 D_800E61F2;
void func_800A7164(void) {
    D_800E417E = 0;
    D_800E4180 = 0;
    D_800E5620 = 0;
    D_800E5622 = 0;
    D_800E5758 = 0;
    D_800E575C = 0;
    D_800E39BC = 0;
    D_800E61F2 = 0x18;
}

extern u8 D_800E39E8;
extern u8 D_800E5464;
extern s32 D_800E3A44;
void func_800A7164(void);
void func_800A5C00(void);
void func_800D8378(void);
void func_800A71AC(void) {
    D_800E39E8 = 0;
    D_800E5464 = 0;
    D_800E3A44 = 0;
    func_800A7164();
    func_800A5C00();
    func_800D8378();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A71F0);

void RotMatrix_gte(s16 *, u8 *);
void func_800A735C(u8 *arg0) {
    s16 v[4];
    func_800B0FD4(v);
    RotMatrix_gte(v, arg0);
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
}

void func_800A73FC(void *, void *);
void func_800A739C(u8 *arg0, u8 *arg1) {
    func_800A73FC(arg0, arg1);
    func_800A73D8(arg0, arg1);
}

void func_800A73D8(u8 *arg0, u8 *arg1) {
    *(s32 *)(arg0 + 0x14) = *(s32 *)(arg1 + 0x14);
    *(s32 *)(arg0 + 0x18) = *(s32 *)(arg1 + 0x18);
    *(s32 *)(arg0 + 0x1C) = *(s32 *)(arg1 + 0x1C);
}

void func_800A73FC(void *a, void *b) {
    u16 *d = a;
    u16 *s = b;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = s[5];
    d[6] = s[6];
    d[7] = s[7];
    d[8] = s[8];
}

extern s32 D_800E41DC;
s32 VSync(s32);
void func_800A7468(void) {
    D_800E41DC = VSync(1);
}

extern s32 D_800E3A44;
extern S8007EE88 *D_80086FB4;
void func_800A748C(void) {
    D_800E3A44 = 1 - D_800E3A44;
    D_80086FB4 = &D_8007EE88_s[D_800E3A44];
}

void func_800A74CC(s16 *arg0, s32 *arg1) {
    arg0[0] = arg1[0] >> 16;
    arg0[1] = arg1[1] >> 16;
    arg0[2] = arg1[2] >> 16;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A74F0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A75EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A773C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A77C4);

s32 func_80044DD4(void);
u8 func_8002A040(s32);
s32 func_800A89EC(void) {
    if (func_80044DD4() != 0) {
        return -1;
    }
    if (func_8002A040(0x74636E65) == 0) {
        return 0;
    }
    return -1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A8A30);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A8B00);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A8BA4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A8C3C);

void func_8001B0F8(s32);
s32 func_8003D070(s32, s32);
extern s32 D_800E3A14;
void func_80044EE0(s32);
void func_8003FA64(void);
void func_800A8DF4(s32 arg0) {
    s32 p;
    func_8001B0F8(3);
    func_8004582C(5);
    arg0 += 0x719;
    p = func_8003D070(func_80044924(arg0), 0x801EE000);
    D_800E3A14 = p;
    func_80045F14(arg0, (u8 *)p, 0);
    func_80044EE0(0);
    func_8003FA64();
}

extern s32 D_800E3A14;
void func_800D6900(void);
void func_8003D504(s32);
void func_8003FA64(void);
void func_800A8E68(void) {
    func_800D6900();
    func_8003D504(D_800E3A14);
    func_8003FA64();
}

void func_800A8DF4(s32);
void func_801EE0B0(void);
void func_800A8E68(void);
void func_800A8EA0(void) {
    func_800A8DF4(3);
    func_801EE0B0();
    func_800A8E68();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A8ED0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A9930);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A9AFC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A9CB0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AA1C4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AA3C8);

void func_80044EE0(s32);
void func_800AB060(void);
void func_800AAFE0(void);
void func_800AA45C(void) {
    func_80044EE0(0);
    func_800A5578();
    DrawSync(0);
    func_800AB060();
    func_800AAFE0();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AA49C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AA620);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AA830);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AAA20);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AAFE0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB060);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB15C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB328);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB3B0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB4E8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB584);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB5A8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB694);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ABDFC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ABEF0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AC01C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AC48C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AC58C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AC794);

typedef struct { u8 p[0x6C]; s32 a6C; u8 q[0x7C - 0x70]; s32 a7C; s32 a80; s32 a84; s32 a88; } S800E2508;
extern S800E2508 D_800E2508;
void func_800ACA6C(void) {
    func_8003D504(D_800E2508.a84);
    func_8003D504(D_800E2508.a7C);
    func_8003D504(D_800E2508.a80);
    func_8003D504(D_800E2508.a88);
    func_8003D504(D_800E2508.a6C);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ACACC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ACF60);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AD03C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AD2C0);

void func_800AD3C0(s32 arg0) {
    if (D_800E3A50_h.h != 0) {
        D_800E3A50_h.a = D_800E3A50_h.b = D_800E3A50_h.c = 0xFF0000;
        D_800E3A50_h.h = 0;
        func_800AD2C0(0, arg0, 0, 0, 0, 2);
    }
}

void func_800AD420(s32 arg0) {
    if (D_800E3A50_h.h != 1) {
        D_800E3A50_h.h = 1;
        D_800E3A50_h.a = D_800E3A50_h.b = D_800E3A50_h.c = 0;
        func_800AD2C0(0, arg0, 0xFF, 0xFF, 0xFF, 2);
    }
}

void func_800AD480(s32 arg0) {
    if (D_800E3A50_h.h != 0) {
        D_800E3A50_h.a = D_800E3A50_h.b = D_800E3A50_h.c = 0xFF0000;
        D_800E3A50_h.h = 0;
        func_800AD2C0(0, arg0, 0, 0, 0, 1);
    }
}

void func_800AD4E0(s32 arg0) {
    if (D_800E3A50_h.h != 1) {
        D_800E3A50_h.h = 1;
        D_800E3A50_h.a = D_800E3A50_h.b = D_800E3A50_h.c = 0;
        func_800AD2C0(0, arg0, 0xFF, 0xFF, 0xFF, 1);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AD53C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AD664);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ADB44);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ADC54);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ADD68);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800ADE24);

typedef struct { u8 p[0x10]; s16 h10; u8 q[0x4C - 0x12]; s32 a; s32 b; s32 c; s32 d; } S800E3A50_4C;
extern S800E3A50_4C D_800E3A50_4C asm("D_800E3A50");
extern u8 D_800E3A18;
void func_800AE748(void) {
    D_800E3A50_4C.h10 = 0;
    if (D_800E3A18 != 0) {
        func_8003D504(D_800E3A50_4C.a);
        func_8003D504(D_800E3A50_4C.b);
        func_8003D504(D_800E3A50_4C.c);
        func_8003D504(D_800E3A50_4C.d);
        D_800E3A18 = 0;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AE7B8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AE8FC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AEA18);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AEEE0);

void Square0(s32 *, s32 *);
s32 SquareRoot0(s32);
s32 func_800AF46C(s32 arg0, s32 arg1, s32 arg2) {
    s32 in[4];
    s32 out[4];
    in[0] = arg0;
    in[1] = arg1;
    in[2] = arg2;
    Square0(in, out);
    return SquareRoot0(out[0] + out[1] + out[2]);
}

s32 func_800AF4B4(s32 arg0, s32 arg1) {
    s32 in[4];
    s32 out[4];
    in[0] = arg0;
    in[1] = arg1;
    in[2] = 0;
    Square0(in, out);
    return SquareRoot0(out[0] + out[1]);
}

void Square0(s32 *, s32 *);
s32 SquareRoot0(s32);
s32 func_800AF4F4(s32 arg0) {
    s32 in[4];
    s32 out[4];
    in[0] = arg0;
    Square0(in, out);
    return SquareRoot0(out[0]);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AF528);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AF694);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AFAF8);

extern u32 D_800E411C;
extern s32 D_800724FC;
s32 func_800AFB84(void) {
    u32 x = D_800E411C;
    if (!((x >> 19) & 1) && ((x >> 1) & 1)) {
        return -1;
    }
    if (D_800724FC != -1) {
        return -1;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AFBD0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B02B0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B035C);

s32 func_800AEA18(s32, s32, void *, s32, s32, s32);
s32 func_800B051C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 buf[4];
    func_800AEA18(arg0, arg1, buf, arg3, arg2, 1);
    return buf[1];
}

s32 func_800B054C(s32 arg0, s32 arg1, s32 arg2) {
    s16 buf[4];
    s32 buf2[4];
    func_800AEA18(arg0, arg1, buf, (s32)buf2, arg2, 0);
    return buf[1];
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B057C);

typedef struct { u8 p[0x40]; s32 f40; u8 q[0x278 - 0x44]; } S800E257C;
extern S800E257C *D_800E257C;
s32 func_800B057C(s32);
void func_800B06E0(s32 arg0) {
    D_800E257C[arg0].f40 = func_800B057C(arg0);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B0728);

s32 func_800B0888(s32 a, s32 b, s32 c, s16 *out) {
    s32 d;
    s32 t = (a - b) & 0xFFF;
    if (t < 0x800) {
        d = t;
    } else {
        d = (b - a) & 0xFFF;
    }
    *out = d / c;
    if (d < 0x140) {
        return -1;
    }
    return 1;
}

s32 func_800B08D0(s32 a, s32 b, s32 c) {
    if (((a - b) & 0xFFF) < 0x800) {
        a -= c;
        if (((a - b) & 0xFFF) >= 0x800) {
            a = b;
        }
    } else {
        a += c;
        if (((a - b) & 0xFFF) < 0x801) {
            a = b;
        }
    }
    return a & 0xFFF;
}

s32 func_800B0928(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == arg1) {
        return arg0;
    }
    if (arg0 < arg1) {
        arg0 += arg2;
        if (arg1 < arg0) {
            arg0 = arg1;
        }
    } else {
        arg0 -= arg2;
        if (arg0 < arg1) {
            arg0 = arg1;
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B0968);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B0F1C);

void func_800B0FD4(s16 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
}

void func_800B0FE4(s32 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B0FF4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B16B0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B176C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B1834);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B18F0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B19B8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B1E7C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B2690);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B2864);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B28E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B2B3C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B323C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B3310);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B33CC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B35F8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B36A8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B3864);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B4360);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B49A0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5084);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5440);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B569C);

extern u8 *D_800E14B8;
s16 func_800B589C(s32 arg0) {
    u8 *p = D_800E14B8 + arg0;
    return p[0] + (p[1] << 8);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B58C8);

extern s32 D_80072500[];
void func_800B59EC(s32 arg0) {
    D_80072500[1] |= 1 << arg0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5A0C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5A34);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5AD0);

extern u32 *D_800E3A48;
s32 func_800B5AF4(s32 arg0) {
    if (!(D_800E3A48[arg0 >> 6] & (1 << ((arg0 >> 1) & 0x1F)))) {
        return 0;
    }
    return -1;
}

extern s16 D_800E57A0_a[] asm("D_800E57A0");
s32 func_800B5B34(s32 arg0) {
    if (!(D_800E3A48[arg0 >> 6] & (1 << ((arg0 >> 1) & 0x1F)))) {
        return D_800E57A0_a[arg0 >> 1];
    }
    return (u16)D_800E57A0_a[arg0 >> 1];
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5B98);

s16 func_800B5BB4(s32 arg0) {
    u8 *p = D_800E14B8 + (*(s32 *)(D_1F800004 + 0x228) + arg0);
    return p[0] + (p[1] << 8);
}

u16 func_800B5BEC(s32 arg0) {
    u8 *p = D_800E14B8 + (*(s32 *)(D_1F800004 + 0x228) + arg0);
    return p[0] | (p[1] << 8);
}

s32 func_800B5B34(s32);
s32 func_800B5C1C(s32 arg0) {
    u16 v = func_800B5BEC(arg0);
    if (v & 0x8000) {
        return v & 0x7FFF;
    }
    return func_800B5B34(v);
}

s32 func_800B5C54(s32 arg0, s32 arg1, s32 arg2) {
    if (!(arg1 & arg2)) {
        return func_800B5B34(func_800B5BEC(arg0));
    }
    return func_800B5BB4(arg0);
}

typedef struct { s16 a; s16 b; } P800B5C98;
void func_80029C10(P800B5C98);
void func_800B5C98(void) {
    P800B5C98 p;
    p.a = func_800B5C1C(1);
    p.b = func_800B5C1C(3);
    func_80029C10(p);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5CF8);

typedef struct { s16 a; s16 b; s32 c; } S80072530;
extern S80072530 D_80072530[];
void func_8004A26C(s32, s32);
void func_800B5D90(void) {
    s32 v = func_800B5C1C(1) & 7;
    func_8004A26C(0, 1 << (v + 8));
    D_80072530[v].a = 0xFF;
    D_80072530[v].b = 0;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5E00);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B5F10);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B6020);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B60A4);

typedef struct { u32 b0 : 5; u32 b5 : 1; u32 rest : 26; } F800B6344;
void func_800B6344(void) {
    ((F800B6344 *)(D_1F800004 + 0x270))->b5 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B638C);

void func_800B64AC(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x20) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800B64E8(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x22) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800B6524(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x24) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800B6560(void) {
    *(s32 *)(D_1F800004 + 0xB8) = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

s32 func_800B65BC(u8 *arg0) {
    if (!((*(u32 *)(arg0 + 0x270) >> 1) & 1)) {
        return *(u16 *)(arg0 + 0x10C);
    }
    return *(u16 *)(arg0 + 0x10C) * 2 + (*(u16 *)(arg0 + 0x10C) >> 1);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B65F8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B6C28);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B6FA8);

s32 func_800B74B0(u8 *p, s32 a1) {
    u16 h;
    if ((*(u32 *)(p + 0x270) >> 12) & 1) {
        return a1;
    }
    if (!(a1 & 0x80)) {
        return a1;
    }
    h = *(u16 *)(p + 0xE0);
    if (!(h & 0x80)) {
        return (s16)h;
    }
    return 1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B74FC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B78E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B7A24);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B7B58);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B7EF8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8020);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B82E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B857C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B865C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B878C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8854);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8910);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8A30);

s32 func_8001BF6C(s32, s32, s32);
s32 func_800BDC54(void);
void func_800B8B24(void) {
    if (func_800BDC54() != -1 && func_8001BF6C(func_800B5C1C(1), 0, 0) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        D_800E6480 = 1;
    }
}

extern s32 D_8007E784;
void func_800B8B98(void) {
    if (D_8007E784 == -1) {
        (*(s32 *)(D_1F800004 + 0x228))++;
        return;
    }
    D_800E6480 = 1;
}

typedef struct { u8 p[0x294]; u8 a; u8 b; u8 c; } S800E3A50_294;
extern S800E3A50_294 D_800E3A50_294 asm("D_800E3A50");
void func_800B8BD8(void) {
    D_800E3A50_294.a = func_800B5C1C(1);
    D_800E3A50_294.b = func_800B5C1C(3);
    D_800E3A50_294.c = func_800B5C1C(5);
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8C38);

void func_800B8CF4(void) {
    *(s16 *)(D_1F800004 + 0x100) = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x102) = func_800B5C1C(3);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800B8D44(void) {
    *(s16 *)(D_1F800004 + 0x104) = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x106) = func_800B5C1C(3);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8D94);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8E4C);

extern s16 *D_800E39E4;
void func_800B5B98(u16, s32);
void func_800B8FAC(void) {
    func_800B5B98(func_800B5BEC(1), D_800E39E4[0]);
    func_800B5B98(func_800B5BEC(3), D_800E39E4[1]);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9020);

typedef struct {
    u8 p[0x6CC];
    u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 b3 : 1; u32 b4 : 1; u32 b5 : 1; u32 b6 : 1; u32 b7 : 1;
    u32 b8 : 1; u32 b9 : 1; u32 b10 : 1; u32 b11 : 1; u32 b12 : 1; u32 b13 : 1; u32 rest : 18;
} S800E3A50f;
extern S800E3A50f D_800E3A50_f asm("D_800E3A50");
void func_800B91C4(void) {
    D_800E3A50_f.b5 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800AD664(s32);
void func_800B9218(void) {
    func_800AD664(0);
    *(s32 *)(D_1F800004 + 0x228) += 0x11;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9254);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9384);

typedef struct { u8 p[0x37BC]; u32 f[2]; } S8006EBC8f;
extern S8006EBC8f D_8006EBC8_f asm("D_8006EBC8");
s32 func_800B9408(s32 arg0) {
    if (arg0 < 0x2C) {
        if (D_8006EBC8_f.f[arg0 >> 5] & (1 << (arg0 & 0x1F))) {
            return 0;
        }
    }
    return -1;
}

typedef struct { u8 p[0x2DD8]; u32 a[0x279]; u32 b[2]; } S8006EBC8i;
extern S8006EBC8i D_8006EBC8_i asm("D_8006EBC8");
s32 func_800B9450(s32 arg0) {
    if (arg0 < 0x2C) {
        if ((D_8006EBC8_i.b[arg0 >> 5] | D_8006EBC8_i.a[arg0 >> 5]) & (1 << (arg0 & 0x1F))) {
            return 0;
        }
    }
    return -1;
}

typedef struct { u8 p[0x2DD8]; u32 a[0x27C]; u32 b[2]; } S8006EBC8_37C8;
extern S8006EBC8_37C8 D_8006EBC8_37C8 asm("D_8006EBC8");
s32 func_800B94A0(s32 arg0) {
    if (arg0 < 0x2C) {
        if (D_8006EBC8_37C8.b[arg0 >> 5] & ~D_8006EBC8_37C8.a[arg0 >> 5] & (1 << (arg0 & 0x1F))) {
            D_8006EBC8_37C8.b[arg0 >> 5] &= ~(1 << (arg0 & 0x1F));
            return 0;
        }
        D_8006EBC8_37C8.b[arg0 >> 5] &= ~(1 << (arg0 & 0x1F));
    }
    return -1;
}

typedef struct { u8 p0[0x2DD8]; u32 f2DD8[2]; u8 p1[0x3794 - 0x2DE0]; u32 f3794[2]; u32 f379C[2]; } S8006EBC8c;
extern S8006EBC8c D_8006EBC8_c asm("D_8006EBC8");
void func_800B950C(s32 arg0) {
    if (arg0 < 0x2C) {
        D_8006EBC8_c.f2DD8[arg0 >> 5] |= 1 << (arg0 & 0x1F);
    }
}

void func_800B954C(s32 arg0) {
    if (arg0 < 0x2C) {
        D_8006EBC8_c.f2DD8[arg0 >> 5] &= ~(1 << (arg0 & 0x1F));
    }
}

void func_800B9590(s32 arg0) {
    if (arg0 < 0x2C) {
        D_8006EBC8_c.f379C[arg0 >> 5] |= 1 << (arg0 & 0x1F);
    }
}

void func_800B95D0(s32 arg0) {
    if (arg0 < 0x2C) {
        D_8006EBC8_c.f379C[arg0 >> 5] &= ~(1 << (arg0 & 0x1F));
    }
}

void func_800B9614(s32 arg0) {
    if (arg0 < 0x2C) {
        D_8006EBC8_c.f3794[arg0 >> 5] |= 1 << (arg0 & 0x1F);
    }
}

void func_800B9654(s32 arg0) {
    if (arg0 < 0x2C) {
        D_8006EBC8_c.f3794[arg0 >> 5] &= ~(1 << (arg0 & 0x1F));
    }
}

s32 func_8001C09C(s32);
void func_800B9698(void) {
    if (func_8001C09C(func_800B5C1C(1)) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800B96F4(void) {
    if (func_800B9408(func_800B5C1C(1)) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800B9750(void) {
    if (func_800B9450(func_800B5C1C(1)) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

s32 func_800B94A0(s32);
void func_800B97AC(void) {
    if (func_800B94A0(func_800B5C1C(1)) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800B9808(void) {
    func_800B950C(func_800B5C1C(1));
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800B984C(void) {
    func_800B954C(func_800B5C1C(1));
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9890);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9940);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B99EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9A84);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9B10);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9C44);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9D28);

void func_800B9D28(s32);
void func_800B9E34(void) {
    func_800B9D28(1);
}

void func_800B9E54(void) {
    func_800B9D28(0);
}

extern s32 D_800724F0[];
s32 func_800B9E74(s32 arg0) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_800724F0[i] == arg0) {
            return i;
        }
    }
    return -1;
}

extern s32 D_80072520[];
s32 func_800B9EB0(s32 arg0) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_80072520[i] == arg0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B9EEC);

void func_800B9FA4(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, D_8007E6C0[func_800B5C1C(3)]);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800BA014(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) &= ~0x400;
    } else {
        *(u32 *)(c + 0x38) |= 0x400;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800BA07C(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) |= 0x100;
    } else {
        *(u32 *)(c + 0x38) &= ~0x100;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA0E4);

s32 rand(void);
void func_800BA19C(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, rand());
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BA1F0(void) {
    s32 r = rand();
    s32 v = (r * (func_800B5C1C(3) + 1)) >> 15;
    func_800B5B98(func_800B5BEC(1), v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800BA25C(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x >>= func_800B5C1C(3);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800BA2C8(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x <<= func_800B5C1C(3);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA334);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA3C8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA468);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA4F8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA588);

void func_800BA618(void) {
    s32 v = func_800B5B34(func_800B5BEC(1)) - 1;
    func_800B5B98(func_800B5BEC(1), v);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BA678(void) {
    s32 v = func_800B5B34(func_800B5BEC(1)) + 1;
    func_800B5B98(func_800B5BEC(1), v);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA6D8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA774);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA80C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA89C);

void func_800B5B98(u16, s32);
void func_800BA92C(void) {
    func_800B5B98(func_800B5BEC(1), 0);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BA974(void) {
    func_800B5B98(func_800B5BEC(1), 1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BA9BC);

s32 func_800BAA38(s32 arg0) {
    s32 i;
    if (arg0 == 0xFF) {
        return -1;
    }
    for (i = 0; i < 3; i++) {
        if (D_8007E6C0[i] == 0xFF) {
            return -1;
        }
        if (D_8007E6C0[i] == arg0) {
            return i;
        }
    }
    return -1;
}

extern s32 D_8007E6C8;
extern s32 D_8007E6C4;
s32 func_800BAA90(s32 arg0) {
    if (arg0 == 0xFF) {
        return D_8007E6C8;
    }
    if (arg0 == 0xFE) {
        return D_8007E6C4;
    }
    if (arg0 == 0xFD) {
        return D_8007E6C0[0];
    }
    if (arg0 == 0xFC) {
        return 0xFF;
    }
    if (arg0 < 0x2C) {
        return arg0;
    }
    return 0xFF;
}

extern u8 D_800E546C;
void func_800BAB04(void) {
    u8 *c = D_1F800004;
    s32 f;
    s32 v = D_800E14B8[*(s32 *)(c + 0x228) + 1];
    f = D_800E546C;
    *(u16 *)(c + 0xFA) = ((v << 9) & 0xFFF) | 0x8000;
    if (f == 0) {
        *(u32 *)(c + 0x270) |= 0x4000;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BAB6C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BABD4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BAC9C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BAD18);

void func_800BAF00(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) |= 0x2;
    } else {
        *(u32 *)(c + 0x38) &= ~0x2;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800BAF68(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) |= 0x4;
    } else {
        *(u32 *)(c + 0x38) &= ~0x4;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800BAFD0(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) |= 0x8;
    } else {
        *(u32 *)(c + 0x38) &= ~0x8;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB038);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB0C0);

extern u8 D_800E39E2;
void func_800BB190(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
        D_800E39E2 = 1;
    } else {
        D_800E39E2 = 0;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

extern s16 D_800E3D4E;
void func_800BB1F0(void) {
    D_800E3D4E = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

s32 func_800BB4CC(s32);
s32 func_800BB230(s32 arg0) {
    if (arg0 < 0x400) {
        if (func_800BB4CC(arg0) != -1) {
            return 0;
        }
        return -1;
    }
    if (arg0 < 0x440) {
        if (func_800CFD04(arg0 - 0x401) != 0) {
            return 0;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB294);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB3EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB4CC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB58C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB614);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB690);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB768);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB7F8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB8A0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB928);

s32 func_800BB230(s32);
void func_800BBA0C(void) {
    if (func_800BB230(func_800B5C1C(1)) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BBA68);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BBAF4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BBE10);

void func_800BBE88(void) {
    *(s16 *)(D_1F800004 + 0x110) = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BBEE4);

typedef struct { u32 b0 : 6; u32 b6 : 1; u32 rest : 25; } F800BBFAC;
void func_800BBFAC(void) {
    ((F800BBFAC *)(D_1F800004 + 0x270))->b6 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

extern s32 D_800E3D48;
void func_800BBFF4(void) {
    D_800E3D48 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC034);

void func_800BC0B0(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x24E) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC0EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC190);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC254);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC39C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC458);

extern s32 D_8007E774;
extern u8 *D_8008BE50;
s32 func_800BC4E4(void) {
    if (D_8007E774 == -1) {
        return 0;
    }
    return *(s16 *)(D_8008BE50 + 0x56);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC514);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC7B8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCA6C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCAEC);

void func_800BCB68(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x10C) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BCBA4(void) {
    s32 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x10C) = v << 4;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BD30C(s32);
void func_800BCBE4(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x122) = -1;
    func_800BD30C(9);
}

void func_800C3994(s32);
void func_800BCC2C(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x122) = -1;
    func_800C3994(9);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCC74);

void func_800C3E08(s32);
void func_800BCCF0(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x122) = -1;
    func_800C3E08(3);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCD38);

void func_800BCEF4(s32);
void func_800BCDB4(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x122) = -1;
    func_800BCEF4(3);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCDFC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCE78);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BCEF4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BD30C);

extern u8 D_800E39E0;
s32 func_800BD774(void) {
    if (D_800E39E0 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E3A1A;
s32 func_800BD794(void) {
    if (D_800E3A1A == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E41D8;
s32 func_800BD7B4(void) {
    if (D_800E41D8 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E41D3;
s32 func_800BD7D4(void) {
    if (D_800E41D3 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E41D9;
s32 func_800BD7F4(void) {
    if (D_800E41D9 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E5049;
s32 func_800BD814(void) {
    if (D_800E5049 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E5460;
s32 func_800BD834(void) {
    if (D_800E5460 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E41A4;
extern u8 D_800E41D2;
s32 func_800BD854(void) {
    if (D_800E41A4 == 1) {
        return -1;
    }
    if (D_800E41D2 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E5464;
s32 func_800BD88C(void) {
    if (D_800E5464 != 0) {
        return -1;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BD8AC);

extern u8 D_800E39E8;
s32 func_800BD8D0(void) {
    if (D_800E39E8 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E5458;
s32 func_800BD8F0(void) {
    if (D_800E5458 == 1) {
        return -1;
    }
    return 0;
}

extern u8 D_800E41C8;
s32 func_800BD910(void) {
    if (D_800E41C8 != 0) {
        return -1;
    }
    return 0;
}

extern u8 D_800E25A8;
s32 func_800BD930(void) {
    if (D_800E25A8 != 0) {
        return -1;
    }
    return 0;
}

extern u8 D_800E575A;
s32 func_800BD950(void) {
    if (D_800E575A != 0) {
        return -1;
    }
    return 0;
}

extern u8 D_800E5799;
s32 func_800BD970(void) {
    if (D_800E5799 != 0) {
        return -1;
    }
    return 0;
}

extern u8 D_800E61F0;
s32 func_800BD990(void) {
    if (D_800E61F0 != 0) {
        return -1;
    }
    return 0;
}

extern u8 D_800E3A00;
s32 func_800BD9B0(void) {
    if (D_800E3A00 != 0) {
        return -1;
    }
    return 0;
}

extern u8 D_800E5798;
s32 func_800BD9D0(void) {
    if (D_800E5798 != 0) {
        return -1;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BD9F0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BDAA0);

s32 func_800BDAA0(void);
s32 func_800BD8AC(void);
s32 func_800BDC08(void) {
    if (func_800BDAA0() == -1) {
        return -1;
    }
    if (func_800BD8AC() == -1) {
        return -1;
    }
    return 0;
}

s32 func_800BDC54(void) {
    if (func_800BDC08() == -1) {
        return -1;
    }
    if (func_800BD910() == -1) {
        return -1;
    }
    return 0;
}

typedef struct { s32 a; s32 b; u8 p[0x2C]; s16 h; } S800E5760b;
extern S800E5760b D_800E5760_b asm("D_800E5760");
void func_800BDCA0(void) {
    D_800E5760_b.a = func_800B5C1C(1);
    D_800E5760_b.b = func_800B5C1C(3);
    D_800E5760_b.h = 1;
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BDCFC);

extern s32 D_800E6470;
void func_800BDDB8(void) {
    s32 d = D_800E6470;
    u8 *c = D_1F800004;
    s32 pc = *(s32 *)(c + 0x228);
    D_800E6470 = d + 0x40;
    *(s32 *)(c + 0x228) = pc + 1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BDDE0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BDE84);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BDFE4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE0BC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE1DC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE2BC);

void func_800BE2E0(s32 arg0) {
    if ((u16)(func_800B5BEC(1) & arg0) != 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800BE344(s32 arg0) {
    if (func_800B5BEC(1) == (u16)arg0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

extern u16 D_800E39BC;
void func_800BE344(s32);
void func_800BE3A8(void) {
    func_800BE344(D_800E39BC);
}

extern u16 D_800E417E;
void func_800BE3D0(void) {
    func_800BE344(D_800E417E);
}

void func_800BE2E0(s32);
void func_800BE3F8(void) {
    func_800BE2E0(D_800E39BC);
}

void func_800BE420(void) {
    func_800BE2E0(D_800E417E);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE448);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE534);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE604);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE770);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE880);

extern s16 D_800E3CCA;
void func_800BEABC(void) {
    D_800E3CCA = 0xFF;
    (*(s32 *)(D_1F800004 + 0x228))++;
}

extern s16 D_800E3CCA;
s32 func_800C6BA4(s32);
void func_800BEAE4(void) {
    D_800E3CCA = func_800C6BA4(1);
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800BEB24(void) {
    s32 v = func_800B5C1C(1);
    if (func_800B5B34(0) < v) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800BEB8C(void) {
    s32 v = func_800B5C1C(1);
    if (v >= func_800B5B34(0)) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800BEBF4(void) {
    s32 v = func_800B5C1C(1);
    if (v < func_800B5B34(0)) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800BEC5C(void) {
    s32 v = func_800B5C1C(1);
    if (func_800B5B34(0) >= v) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

void func_800BECC4(void) {
    s32 v = func_800B5C1C(1);
    if (func_800B5B34(0) == v) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

extern s32 D_800E6470;
void func_800BED28(void) {
    D_800E6470 += 0x20;
    func_800B5B98(0, func_800B5C1C(1));
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BED80(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, func_800B5B34(0));
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BEDD8);

void func_800B5B98(u16, s32);
void func_800BEE68(void) {
    u16 v = func_800B5BEC(1) + func_800B5C1C(5);
    func_800B5B98(func_800B5BEC(3), D_800E14B8[v]);
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BEEDC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BEFC0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF050);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF0E4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF178);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF21C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF2C0);

extern s32 D_800E3CB4;
void func_800BF344(void) {
    D_800E3CB4 = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF3A4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF458);

void func_800BF458(u8, u8, s32);
void func_800BF520(void) {
    s32 v = func_800B5C1C(3);
    func_800BF458(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2], v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF588);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF628);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF6A8);

s32 func_800BF748(s32 arg0, s32 *out) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_8007E6C0[i] == arg0) {
            return -1;
        }
        if (D_8007E6C0[i] == 0xFF) {
            *out = i;
            return 0;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF798);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF90C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BFA44);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BFAD4);

void func_80095A08(s32, s16 *);
void func_800BFBC4(s32 arg0, u8 *arg1) {
    s16 v[4];
    func_80095A08(arg0, v);
    if (v[0] < v[2]) {
        *(s16 *)(arg1 + 0x108) = v[2];
    } else {
        *(s16 *)(arg1 + 0x108) = v[0];
    }
    *(s16 *)(arg1 + 0x10A) = v[1];
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BFC20);

u8 *func_8003D8F4(s32, s32, s32);
void func_8009552C(void *, u8 *, u8 *);
u8 *func_800C0048(void *arg0, s32 arg1) {
    u8 *p = func_8003D8F4(0x1000, arg1, 2);
    func_8009552C(arg0, p, p + 0x1000);
    return p;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C008C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C02EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C04D4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C0658);

typedef struct { s32 a; u8 p[6]; u16 h; s32 c; } S800E5598;
extern S800E5598 D_800E5598[];
void func_80094C38(s32);
void func_80095E18(s32, s32, u16);
void func_800C08AC(s32 arg0) {
    func_80094C38(D_800E5598[arg0].a);
    func_80095E18(D_800E5598[arg0].a, 0, D_800E5598[arg0].h);
}

void func_80095F9C(s32, s32, u16);
void func_80094CD8(s32);
void func_800C08F4(s32 arg0) {
    func_80095F9C(D_800E5598[arg0].a, 0, D_800E5598[arg0].h);
    func_80094CD8(D_800E5598[arg0].a);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C093C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C0A78);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C0C98);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C0E84);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C0F08);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1160);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C14A8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1560);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C162C);

void func_800C1768(void) {
    s32 v = func_800B5C1C(1);
    D_800E3A50_5C.f[v >> 5] &= ~(1 << (v & 0x1F));
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C17D0(void) {
    s32 v = func_800B5C1C(1);
    D_800E3A50_5C.f[v >> 5] |= 1 << (v & 0x1F);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C1834(void) {
    if (D_800E5458 == 1) {
        D_800E6480 = 1;
        return;
    }
    (*(s32 *)(D_1F800004 + 0x228))++;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1870);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1A54);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1C28);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1D88);

void func_800C1E20(void) {
    *(s16 *)(D_1F800004 + 0x10E) = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

extern s16 D_800E3C72;
void func_800C1E7C(void) {
    D_800E3C72 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1EBC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1F3C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C21E4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C2400);

extern s32 D_800E4908;
void func_800B5B98(u16, s32);
void func_800C2468(void) {
    func_800B5B98(func_800B5BEC(1), D_800E4908);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C24B4(void) {
    u16 v = func_800B5BEC(1);
    func_800B5B98(v, *(u16 *)(D_1F800004 + 0xFA) & 0xFFF);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C250C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C25AC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C26C4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C2B6C);

void func_800C2FE8(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x126) = D_800E14B8[*(s32 *)(c + 0x228) + 1];
    *(s32 *)(c + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C3030);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C34E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C3994);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C3E08);

void func_800C4224(void) {
    s32 v = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
    *(s32 *)(D_1F800004 + 0x228) += v * 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4264);

void func_800C43BC(void) {
    u8 *p = D_1F800004;
    *(u16 *)(p + 0xF8) |= 0x8000;
    func_800B0FE4((s32 *)(p + 0x4C));
    D_800E6480 = 1;
}

void func_800C43BC(void);
void func_800C43FC(void) {
    func_800C43BC();
    (*(s32 *)(D_1F800004 + 0x228))++;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4438);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C452C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C461C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C471C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C47CC);

void func_800C49E4(void) {
    *(s16 *)(D_1F800004 + 0xFE) = -1;
    (*(s32 *)(D_1F800004 + 0x228))++;
}

void func_800C4A08(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0xFE) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4A44);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4ABC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4B84);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4C50);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4D00);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4D48);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4F4C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C5198);

s32 rand(void);
void func_800C533C(void) {
    *(s16 *)(D_1F800004 + 0x238) = (rand() & 0x3FF) + 0x200;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C5370);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C540C);

typedef struct { u8 p[0x228]; s32 pc; } C800C6550;
extern C800C6550 *D_1F800004_c asm("D_1F800004");
void func_800C540C(void);
void func_800C6550(void) {
    s32 pc = D_1F800004_c->pc;
    func_800C540C();
    D_1F800004_c->pc = pc;
    D_800E6480 = 1;
}

void func_800C659C(void) {
    (*(s32 *)(D_1F800004 + 0x228))++;
}

typedef struct { s16 a; s16 b; u8 r[16]; } T800C65BC;
typedef struct { u8 p[0x11C]; T800C65BC s[13]; u8 pad[8]; s32 pc; s32 idx; } C800C65BC;
extern C800C65BC *D_1F800004_d asm("D_1F800004");
extern s32 D_800E6478;
void func_800C65BC(void) {
    C800C65BC *c = D_1F800004_d;
    D_800E6480 = 1;
    c->s[c->idx].a = 0xF;
    D_800E6478 = 1;
    c->s[c->idx].b = 0xFF;
}

void func_800C6614(void) {
    *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(1);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6644);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C68E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6958);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C69EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6AEC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6BA4);

s32 func_800C6C78(u8 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < 8; i++, arg0 += 0x14) {
        if (arg1 == *(s16 *)(arg0 + 0x11E)) {
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6CA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6E9C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C7218);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C7558);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C76C4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C77F8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C7898);

extern s32 D_800E6474;
void func_800C7D18(s32, s32);
void func_800C7938(void) {
    func_800C7D18(D_800E6474, 0);
}

extern s16 D_800E5628[];
extern u8 D_800E41C8;
extern s32 D_800E545C;
extern s32 D_800E6414;
void func_800C7960(void) {
    s32 i;
    s16 v = -1;
    D_800E41C8 = 0;
    D_800E545C = 0;
    D_800E6414 = -1;
    for (i = 3; i >= 0; i--) {
        D_800E5628[i] = v;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C79A8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C7A74);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C7D18);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C8478);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C850C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C882C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C8E54);

typedef struct { u32 b0 : 9; u32 b9 : 1; u32 rest : 22; } F800C8ECC;
void func_800C8ECC(void) {
    ((F800C8ECC *)(D_1F800004 + 0x270))->b9 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

extern s16 D_800E3D50;
void func_800C8F14(void) {
    D_800E3D50 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C8F54);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C9210);

void func_800C9468(void) {
    D_800E3A50_f.b8 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

extern s16 D_800E3D52;
void func_800C94BC(void) {
    D_800E3D52 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C94FC(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) |= 0x2000;
    } else {
        *(u32 *)(c + 0x38) &= ~0x2000;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C9564);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C9608);

typedef struct { s16 a; s16 b; } S800E6428;
extern S800E6428 D_800E6428[32];
extern s32 D_800E6468;
void func_800C9728(void) {
    s16 m;
    s32 i;
    D_800E6468 = 0;
    m = -1;
    for (i = 15; i >= 0; i--) {
        D_800E6428[i].a = m;
    }
}

void func_800C975C(s32 arg0, s32 arg1) {
    D_800E6428[D_800E6468].a = arg0;
    D_800E6428[D_800E6468].b = arg1;
    D_800E6468 = (D_800E6468 + 1) & 0x1F;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C978C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C982C);

typedef struct { u8 p[0x664]; u8 a[6]; u8 b[6]; u8 c[6]; } S800E3A50_664;
extern S800E3A50_664 D_800E3A50_664 asm("D_800E3A50");
void func_800C99AC(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        D_800E3A50_664.c[func_800B5C1C(2)] = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800C9A14(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        D_800E3A50_664.a[func_800B5C1C(2)] = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800C9A7C(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        D_800E3A50_664.b[func_800B5C1C(2)] = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800A66A0(u8);
void func_800C9AE4(void) {
    func_800A66A0(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1]);
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

extern s32 D_800E6470;
extern u8 D_800E575A;
void func_800C9B40(void) {
    D_800E6470 += 0x40;
    if (D_800E575A == 0) {
        (*(s32 *)(D_1F800004 + 0x228))++;
        *(u32 *)(D_1F800004 + 0x270) &= ~1;
    } else {
        D_800E6480 = 1;
        D_1F800004_c->pc--;
    }
}

void func_800C9BB0(void) {
    D_800E3A50_f.b9 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C9C0C);

void func_800C9CB0(void) {
    u8 *c = D_1F800004;
    if ((*(u32 *)(c + 0x7C) & 0xC000) || ((*(u16 *)(c + 0xFC) + 0x400) & 0xFFF) == (*(u16 *)(c + 0xFA) & 0xFFF)) {
        (*(s32 *)(c + 0x228))++;
    }
    D_800E6480 = 1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C9D0C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C9DAC);

typedef struct { s32 a; s32 b; s32 c; } S800E40C8;
extern S800E40C8 D_800E40C8;
void func_800C9F08(void) {
    D_800E40C8.a = func_800B5C1C(1);
    D_800E40C8.b = func_800B5C1C(3);
    D_800E40C8.c = func_800B5C1C(5);
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

typedef struct { s16 a; s16 b; s16 c; } S800E40D8;
extern S800E40D8 D_800E40D8;
void func_800C9F68(void) {
    D_800E40D8.a = func_800B5C1C(1);
    D_800E40D8.b = func_800B5C1C(3);
    D_800E40D8.c = func_800B5C1C(5);
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

void func_800C9FC8(void) {
    D_800E3A50_f.b10 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

extern s32 D_800E40E0;
void func_800CA01C(void) {
    D_800E40E0 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800CA05C(void) {
}

void func_800CA064(void) {
    D_800E3A50_f.b11 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800CA0B8(void) {
    D_800E3A50_f.b12 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800CA0B8(void);
void func_800CA10C(void) {
    func_800CA0B8();
}

void func_800CA12C(void) {
    D_800E3A50_f.b13 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u8 p[0x6CC]; u32 lo : 19; u32 b : 1; u32 hi : 12; } S800E3A50_19;
extern S800E3A50_19 D_800E3A50_19 asm("D_800E3A50");
void func_800CA180(void) {
    D_800E3A50_19.b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u32 lo : 19; u32 b : 1; u32 hi : 12; } F800CA1D8;
void func_800CA1D8(void) {
    ((F800CA1D8 *)(D_1F800004 + 0x270))->b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u8 p[0x2E]; s16 a; s16 b; } S800E5760;
extern S800E5760 D_800E5760;
void func_800CA224(void) {
    S800E5760 *s = &D_800E5760;
    u8 *c = D_1F800004;
    s32 v = D_800E14B8[*(s32 *)(c + 0x228) + 1];
    s->a = 1;
    s->b = v;
    *(s32 *)(c + 0x228) += 2;
}

extern s16 D_800E5792;
void func_800CA268(void) {
    D_800E5792 = 1;
    (*(s32 *)(D_1F800004 + 0x228))++;
}

typedef struct { u32 lo : 22; u32 b : 1; u32 hi : 9; } F800CA290;
void func_800CA290(void) {
    ((F800CA290 *)(D_1F800004 + 0x270))->b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u32 lo : 23; u32 b : 1; u32 hi : 8; } F800CA2DC;
void func_800CA2DC(void) {
    ((F800CA2DC *)(D_1F800004 + 0x270))->b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CA328);

void func_800CA3EC(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x114) = v;
    *(u32 *)(D_1F800004 + 0x270) |= 0x2000000;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800CA434(void) {
    *(u32 *)(D_1F800004 + 0x270) &= ~0x02000000;
    (*(s32 *)(D_1F800004 + 0x228))++;
}

typedef struct { u32 lo : 21; u32 b : 1; u32 hi : 10; } F800CA460;
void func_800CA460(void) {
    ((F800CA460 *)(D_1F800004 + 0x270))->b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u32 lo : 26; u32 b : 1; u32 hi : 5; } F800CA4AC;
void func_800CA4AC(void) {
    ((F800CA4AC *)(D_1F800004 + 0x270))->b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_8001B50C(void);
void func_800CA4F8(void) {
    func_8001B50C();
    (*(s32 *)(D_1F800004 + 0x228))++;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CA534);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CA60C);

void func_8004A87C(s32, s32, s32);
void func_800CA6B4(void) {
    s32 a = func_800B5C1C(1);
    s32 b = func_800B5C1C(3);
    func_8004A87C(0, a, b);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_8004AAB4(s32, s32);
void func_800CA710(void) {
    s32 a = func_800B5C1C(1);
    s32 b = func_800B5C1C(3);
    func_8004AAB4(a, b);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_8004AA18(s32, s32);
void func_800CA768(void) {
    s32 a = func_800B5C1C(1);
    s32 b = func_800B5C1C(3);
    func_8004AA18(a, b);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_8004A928(s32, s32, s32);
void func_800CA7C0(void) {
    s32 a = func_800B5C1C(1);
    s32 b = func_800B5C1C(3);
    func_8004A928(0, a, b);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CA81C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CA8B4);

extern s32 D_800E5780;
extern s32 D_800E6728;
void func_800CA94C(void) {
    u16 v = func_800B5BEC(1);
    func_800B5B98(v, D_800E5780 - D_800E6728);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CA9A4);

typedef struct { u8 p[0x6A4]; u32 f; } S800E3A50_6A4;
extern S800E3A50_6A4 D_800E3A50_6A4 asm("D_800E3A50");
void func_800CAA58(void) {
    s32 v = func_800B5C1C(1);
    D_800E3A50_6A4.f |= 1 << ((v & 7) + 8);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CAAB4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CABBC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CADD8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CB0B4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CB2A0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CB53C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CB7EC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CB9E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CBC68);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CBE44);

extern s16 D_800E410E;
void func_800CBED0(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        D_800E410E = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CBF20);

typedef struct { u8 p[0x16]; u16 a; u8 q[0xB8 - 0x18]; u16 b; u8 r[0xCC - 0xBA]; } S8006EBC8x;
extern S8006EBC8x D_8006EBC8_x[] asm("D_8006EBC8");
void func_800CBFE8(s32 arg0) {
    s32 v = D_8007E6C0[arg0];
    if (v != 0xFF) {
        D_8006EBC8_x[v].b = D_8006EBC8_x[v].a;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC038);

typedef struct { u8 p[0xB0]; s32 f; u8 r[0xCC - 0xB4]; } S8006EBC8y;
extern S8006EBC8y D_8006EBC8_y[] asm("D_8006EBC8");
void func_800CC1B0(s32 arg0, s32 arg1) {
    s32 v = D_8007E6C0[arg0];
    if (v != 0xFF) {
        D_8006EBC8_y[v].f |= arg1;
    }
}

void func_800CC204(s32 arg0, s32 arg1) {
    s32 v = D_8007E6C0[arg0];
    if (v != 0xFF) {
        D_8006EBC8_y[v].f &= (arg1 ^ 0xFF) | ~0xFF;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC260);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC3F0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC594);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC638);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC6FC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC7B8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC8DC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC974);

extern s32 D_8007257C;
void func_800CCA14(void) {
    if (func_800BDC54() == -1) {
        D_800E6480 = 1;
        D_1F800004_c->pc--;
    } else {
        D_8007257C = 1;
        D_1F800004_c->pc++;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCA80);

void func_800CCAFC(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x258) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCB38);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCC18);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCC9C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCD48);

void func_800CCE18(void) {
    if (!(*(u32 *)(D_1F800004 + 0x38) & 0x400000)) {
        *(s16 *)(D_1F800004 + 0x116) = func_800B5C1C(1);
        *(u32 *)(D_1F800004 + 0x270) |= 0x1000000;
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

extern s32 D_800E6474;
void func_800AB328(s32, s32, s32);
void func_800CCE8C(void) {
    s32 a = func_800B5C1C(1);
    s32 b = func_800B5C1C(3);
    func_800AB328(D_800E6474, a, b);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

typedef struct { u8 p[0x6CC]; u32 lo : 14; u32 b : 1; u32 hi : 17; } S800E3A50_14;
extern S800E3A50_14 D_800E3A50_14 asm("D_800E3A50");
void func_800CCEEC(void) {
    D_800E3A50_14.b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCF40);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CCF78);

s32 func_800CD004(s32 arg0, s32 arg1) {
    if (!(arg0 & 1)) {
        return D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] & 0xF;
    }
    return D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] >> 4;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD074);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD138);

typedef struct { u8 p[0x6CC]; u32 lo : 16; u32 b : 1; u32 hi : 15; } S800E3A50_16;
extern S800E3A50_16 D_800E3A50_16 asm("D_800E3A50");
void func_800CD2A4(void) {
    D_800E3A50_16.b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800CD2FC(void) {
    func_800B5B98(func_800B5BEC(1), D_8007E774);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0x26E2]; u16 f; } S8006EBC8e;
extern S8006EBC8e D_8006EBC8_e asm("D_8006EBC8");
typedef struct { u8 p[0x3D2]; u16 f; } S800E57A0;
extern S800E57A0 D_800E57A0;
void func_800CD348(void) {
    D_8006EBC8_e.f &= ~0x20;
    D_800E57A0.f &= ~0x20;
    (*(s32 *)(D_1F800004 + 0x228))++;
}

extern s16 D_80071C74;
void func_800CD38C(void) {
    func_800B5B98(func_800B5BEC(1), D_80071C74);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 pad[0x30AC]; u16 a; u16 b; } S8006EBC8;
extern S8006EBC8 D_8006EBC8_s asm("D_8006EBC8");
void func_800CD3D8(void) {
    D_8006EBC8_s.b = D_8006EBC8_s.a;
    (*(s32 *)(D_1F800004 + 0x228))++;
}

typedef struct { u8 p[0x6CC]; u32 lo : 17; u32 b : 1; u32 hi : 14; } S800E3A50_17;
extern S800E3A50_17 D_800E3A50_17 asm("D_800E3A50");
void func_800CD404(void) {
    D_800E3A50_17.b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800CD45C(void) {
    DrawSync(0);
    (*(s32 *)(D_1F800004 + 0x228))++;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD498);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD544);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD5F0);

extern s32 D_800E6418;
extern s16 *D_800E39E4;
void func_800CD6F4(void) {
    D_800E6418 = 0;
    D_800E39E4[0] = func_800B5B34(0x330);
    D_800E39E4[1] = func_800B5B34(0x332);
    (*(s32 *)(D_1F800004 + 0x228))++;
}

extern s16 D_800E3A50_s16[] asm("D_800E3A50");
void func_800CD754(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        D_800E3A50_s16[func_800B5C1C(2) & 7] = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD7C4);

void func_800CD898(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x38) &= ~0x100000;
    } else {
        *(u32 *)(c + 0x38) |= 0x100000;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CD908);

extern s16 D_800E411A;
void func_800CD9E0(void) {
    D_800E411A = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CDA20);

s32 func_800CDC78(void) {
    D_800E6480 = 1;
    if (func_800BDC54() == -1 || func_800CF354() != 0) {
        (*(s32 *)(D_1F800004 + 0x228))--;
        return 1;
    }
    return 0;
}

extern s32 D_800E21E8;
extern u8 D_800E41D3;
void func_800CDCDC(void) {
    if (func_800CDC78() == 0) {
        D_800E21E8 = func_800B5C1C(1);
        D_800E41D3 = 1;
        func_800A8A30(0x1);
        *(s32 *)(D_1F800004 + 0x228) += 3;
    }
}

extern s32 D_800E21EC;
extern u8 D_800E41D9;
void func_800CDD44(void) {
    if (func_800CDC78() == 0) {
        D_800E21EC = func_800B5C1C(1);
        D_800E41D9 = 1;
        func_800A8A30(0xBD);
        *(s32 *)(D_1F800004 + 0x228) += 3;
    }
}

extern s32 D_800E21EC;
extern u8 D_800E5049;
void func_800CDDAC(void) {
    if (func_800CDC78() == 0) {
        D_800E21EC = func_800B5C1C(1);
        D_800E5049 = 1;
        func_800A8A30(0xBD);
        *(s32 *)(D_1F800004 + 0x228) += 3;
    }
}

extern s32 D_800E21EC;
extern u8 D_800E5460;
void func_800CDE14(void) {
    if (func_800CDC78() == 0) {
        D_800E21EC = func_800B5C1C(1);
        D_800E5460 = 1;
        func_800A8A30(0xBD);
        *(s32 *)(D_1F800004 + 0x228) += 3;
    }
}

extern u8 D_800E39E0;
void func_800CDE7C(void) {
    if (func_800CDC78() == 0) {
        D_800E39E0 = 1;
        func_800A8A30(3);
        (*(s32 *)(D_1F800004 + 0x228))++;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CDED0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE030);

s32 func_800CDC78(void);
void func_800A8A30(s32);
void func_800CE0D8(void) {
    if (func_800CDC78() == 0) {
        func_800A8A30(3);
        D_800E41A4 = 1;
        D_1F800004_c->pc++;
    }
}

typedef struct { u8 p[0x6CC]; u32 lo : 15; u32 b : 1; u32 hi : 16; } S800E3A50_15;
extern S800E3A50_15 D_800E3A50_15 asm("D_800E3A50");
void func_800CE128(void) {
    D_800E3A50_15.b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

void func_800CE180(void) {
    ((F800C8ECC *)(D_1F800004 + 0x274))->b9 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE1C8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE250);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE2D8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE3DC);

s32 func_800CE48C(s32 arg0, s32 arg1) {
    s32 n = 0;
    u16 x = arg0 & arg1;
    s32 i;
    for (i = 15; i >= 0; i--) {
        if (x & 1) {
            n++;
        }
        x >>= 1;
    }
    return n;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE4BC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE570);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE610);

void func_800CE610(s32);
void func_800CE774(void) {
    func_800CE610(7);
}

void func_800CE794(void) {
    func_800CE610(5);
}

void func_800CE7B4(void) {
    func_800CE610(3);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CE7D4);

extern s16 D_800E3C70;
void func_800CE870(void) {
    D_800E3C70 = func_800B5BEC(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

s32 func_800BC4E4(void);
void func_800CE8B0(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, func_800BC4E4());
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 a; u8 b; } S8006EBC8_1;
extern S8006EBC8_1 D_8006EBC8_1 asm("D_8006EBC8");
void func_800CE904(void) {
    s32 v = func_800B5C1C(1);
    D_8006EBC8_1.b = (D_8006EBC8_1.b & 7) | (1 << (v + 3));
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

extern u16 D_8007238C;
void func_800CE960(void) {
    s32 v = func_800B5C1C(1);
    if ((D_8007238C >> v) & 1) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

typedef struct { u8 p[0x37C4]; u16 f; } S8006EBC8z;
extern S8006EBC8z D_8006EBC8_z asm("D_8006EBC8");
void func_800CE9C8(void) {
    s32 v = func_800B5C1C(1);
    D_8006EBC8_z.f |= 1 << v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CEA1C);

extern u8 D_800E61F0;
void func_800CEA9C(void) {
    if (func_800BDC54() == -1) {
        D_1F800004_c->pc--;
    } else {
        D_800E61F0 = 1;
        D_1F800004_c->pc++;
    }
    D_800E6480 = 1;
}

typedef struct { u8 p[0x6CC]; u32 lo : 18; u32 b : 1; u32 hi : 13; } S800E3A50_18;
extern S800E3A50_18 D_800E3A50_18 asm("D_800E3A50");
void func_800CEB08(void) {
    D_800E3A50_18.b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u32 rest : 31; u32 b31 : 1; } F800CEB60;
void func_800CEB60(void) {
    ((F800CEB60 *)(D_1F800004 + 0x270))->b31 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CEBA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CEC5C);

extern void (*D_800E16B8[])(void);
void func_800CECE4(void) {
    s32 pc = ++*(s32 *)(D_1F800004 + 0x228);
    D_800E16B8[D_800E14B8[pc]]();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CED44);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CEE8C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CEFC4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF088);

typedef struct { u8 p[0xE]; u16 clut; u8 q[0x28 - 0x10]; } S800E6510;
extern S800E6510 D_800E6510[];
u16 GetClut(s32, s32);
void func_800CF120(s32 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_800E6510[i].clut = GetClut(arg0, arg1);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF188);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF26C);

typedef struct { u8 p[0x548]; u32 lo : 22; u32 b : 1; u32 hi : 9; } A800CF2E8;
s32 func_800CF2E8(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] != 0 && ((A800CF2E8 *)D_800E4190[i])->b == 1) {
            return 1;
        }
    }
    return 0;
}

s32 func_800CF354(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] != 0) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF390);

void func_800CF390(s32);
void func_800CF450(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_800E3A04[i] != 0) {
            func_800CF390(i);
        }
    }
}

void func_800CF4AC(u8 *arg0) {
    if (*(s16 *)(arg0 + 0x494) >= *(s16 *)(arg0 + 0x486)) {
        *(s16 *)(arg0 + 0x4B4) = 6;
        *(u32 *)(arg0 + 0x548) |= 0x8000;
    }
}

s32 func_800CF4DC(s32 arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] != 0 && *(s16 *)(D_800E4190[i] + 0x4C4) == arg0) {
            return i;
        }
    }
    return -1;
}

s32 func_800CF53C(s32 arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] != 0 && *(s16 *)(D_800E4190[i] + 0x4C4) == arg0) {
            return 0;
        }
    }
    return -1;
}

s32 func_800CF59C(s32 arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] != 0 && *(s16 *)(D_800E4190[i] + 0x4C4) == arg0) {
            return i;
        }
    }
    return -1;
}

void func_8004A18C(s32, s32, s32, s32);
void func_800CF5FC(s32 arg0) {
    func_8004A18C(arg0, 1, 0x80, 0x7F);
}

s32 func_800CF624(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF664);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF764);

void func_800CF764(s32, s32);
void func_800CF834(s32 arg0) {
    func_800CF764(5, arg0);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CF858);

s32 func_800CFCE8(s32 arg0) {
    if (arg0 == 0xFF) {
        return 0;
    }
    return arg0 + 1;
}

typedef struct { u8 p[0x2710]; u32 f[1]; } S8006EBC8d;
extern S8006EBC8d D_8006EBC8_d asm("D_8006EBC8");
s32 func_800CFD04(s32 arg0) {
    if (!(D_8006EBC8_d.f[arg0 >> 5] & (1 << (arg0 & 0x1F)))) {
        return 0;
    }
    return arg0 + 1;
}

typedef struct { u8 p[0x2710]; u32 f[1]; } S8006EBC8_2710;
extern S8006EBC8_2710 D_8006EBC8_2710 asm("D_8006EBC8");
void func_800CFD44(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        arg0--;
        D_8006EBC8_2710.f[arg0 >> 5] &= ~(1 << (arg0 & 0x1F));
    } else {
        arg0--;
        D_8006EBC8_2710.f[arg0 >> 5] |= 1 << (arg0 & 0x1F);
    }
}

s32 func_800CFDB8(s32 arg0, u8 *arg1) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        if (arg1[i] == arg0) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CFDEC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CFFE0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D1164);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D1208);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D489C);

typedef struct { s16 x, y, z, pad; } SV800D49D0;
void func_800D49D0(SV800D49D0 *p, s16 x, s16 y, s16 w, s16 h) {
    p[0].x = x;
    p[0].y = y;
    p[0].z = 0;
    p[1].x = x + w;
    p[1].y = y;
    p[1].z = 0;
    p[2].x = x;
    p[2].y = y + h;
    p[2].z = 0;
    p[3].x = x + w;
    p[3].y = y + h;
    p[3].z = 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D4A10);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D5BF4);

typedef struct { u16 h0; u16 h2; u16 h4; u16 h6; } S800E41B8b;
extern S800E41B8b *D_800E41B8_b asm("D_800E41B8");
s32 func_800D5CC0(s32 arg0) {
    s32 v = D_800E41B8_b[arg0].h2;
    if (v >= 0x17) {
        v = 0x16;
    }
    return v;
}

s32 func_800D5CF0(u8 *p, s32 n) {
    s32 off = 0;
    s32 i = 0;
    do {
        u8 c = p[off];
        if (c < 0x20) {
            break;
        }
        if (c < 0xF8) {
            off++;
        } else {
            off += 2;
        }
    } while (++i < n);
    return off;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D5D3C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D5DA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D6194);

typedef struct { u8 pad0[4]; u16 h4; u16 h6; } S800D65A8;
extern S800D65A8 *D_800E41B8;
u16 func_800D65A8(s32 arg0) {
    return D_800E41B8[arg0].h4;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D65C4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D664C);

extern s32 D_800E1E50;
void func_80029F58(s32);
void func_800D67B0(void) {
    if (D_800E1E50 != 0) {
        func_80029F58(D_800E1E50);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D67DC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D686C);

void DrawSync(s32);
void func_800D6900(void) {
    DrawSync(0);
    VSync(0);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D6928);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D69B0);

typedef struct { s16 x; s16 y; s16 w; s16 h; } R800D6BD4;
void ClearImage(R800D6BD4 *, s32, s32, s32);
void func_800D6BD4(s32 x, s32 y, s32 w, s32 h) {
    R800D6BD4 r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    ClearImage(&r, 0, 0, 0);
    DrawSync(0);
}

typedef struct { s16 x; s16 y; s16 w; s16 h; } R800D6C18;
void MoveImage(R800D6C18 *, s32, s32);
void func_800D6C18(s32 x, s32 y, s32 w, s32 h, s32 dx, s32 dy) {
    R800D6C18 r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    MoveImage(&r, dx, dy);
    DrawSync(0);
}

typedef struct { s16 x; s16 y; s16 w; s16 h; } R800D6C58;
void StoreImage(R800D6C58 *, void *);
void LoadImage(R800D6C58 *, void *);
void func_800D6C58(s32 x, s32 y, s32 w, s32 h, void *p) {
    R800D6C58 r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    StoreImage(&r, p);
    DrawSync(0);
}

void func_800D6C94(s32 x, s32 y, s32 w, s32 h, void *p) {
    R800D6C58 r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    LoadImage(&r, p);
    DrawSync(0);
}

extern u16 D_800E5784;
void func_8004582C(s32);
void func_800D6CD0(void) {
    if (D_800E5784 == 0) {
        func_8004582C(2);
    } else {
        func_8004582C(3);
    }
}

extern s32 D_800E65C0;
extern u32 D_800E65C4;
extern u32 *D_800E65C8;
u32 func_800D6D04(void) {
    s32 n = D_800E65C0;
    u32 v;
    u32 r;
    if (!(n & 3)) {
        D_800E65C4 = *D_800E65C8++;
    }
    v = D_800E65C4;
    D_800E65C0 = n + 1;
    r = v & 0xFF;
    D_800E65C4 = v >> 8;
    if (r != 0) {
        r >>= 3;
    }
    return r;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D6D68);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D6F08);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D78BC);

typedef struct { s16 a; s16 b; s16 c; s16 d; } S80072530b;
extern S80072530b D_80072530_b[] asm("D_80072530");
s32 func_8004A2D4(void);
void func_800AB5A8(s32, s32, s32, s32);
void func_800D794C(void) {
    s32 i;
    func_8004A26C(0, func_8004A2D4());
    for (i = 0; i < 8; i++) {
        if (D_80072530_b[i].a != 0xFF) {
            func_800AB5A8(D_80072530_b[i].a, 1 << (i + 8), D_80072530_b[i].c, D_80072530_b[i].b);
        }
    }
}

void func_8004A628(s32, s32, s32, s32);
void func_800D79C0(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_80072530_b[i].a != 0xFF) {
            func_8004A628(0, 1 << (i + 8), 0x1E, D_80072530_b[i].b);
        }
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D7A34);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D7C10);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D81DC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D8378);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D8D3C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D8E58);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D8EF0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D8FB4);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D90A8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D949C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D9890);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D9D08);

void func_800DA180(void) {
}

void func_800DA188(void) {
}

void func_800DA190(void) {
}

void func_800DA198(void) {
}

typedef struct { s32 a; u32 b; s32 c; u32 d; u8 p[0xC]; s32 e; } S800E6770;
extern S800E6770 D_800E6770;
s32 CdSync(s32, u8 *);
void func_800DB230(void);
void func_800DA1A0(void) {
    if (D_800E6770.e == 0 && CdSync(1, 0) == 2 && D_800E6770.b < D_800E6770.d) {
        func_800DB230();
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DA208);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DA288);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DA6C4);

void CdSyncCallback(void *);
void CdReadyCallback(void *);
s32 CdFlush(void);
s32 CdControl(u8, u8 *, u8 *);
void func_800DA6E0(void) {
    CdSyncCallback(0);
    CdReadyCallback(0);
    CdFlush();
    CdControl(9, 0, 0);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DA720);

extern s32 D_800E6754;
extern s32 D_800E6794;
void func_800DA874(void) {
    func_8003D504(D_800E6754);
    D_800E6754 = 0;
    if (D_800E6794 != 0) {
        func_8003D504(D_800E6794);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DA8BC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DA9BC);

extern s32 D_800E6660;
extern s32 D_800E6678;
extern s32 D_800E6668;
extern s32 D_800E666C;
extern s32 D_800E6670;
extern s32 D_800E6674;
void func_800DAB50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_800E6660 = 1;
    D_800E6678 = arg0;
    D_800E6668 = arg1;
    D_800E666C = arg2;
    D_800E6670 = arg3;
    D_800E6674 = arg4;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DAB8C);

void func_800DAB8C(void);
void func_800DAC38(void) {
    func_800DAB8C();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DAC58);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DB230);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DB300);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DB70C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DB9A0);

extern s32 D_800E6734;
extern u8 D_800E6768[];
s32 func_800DBB74(void) {
    return D_800E6768[D_800E6734] != 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DBB94);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DBE64);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DBEE0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DBF90);

extern s32 D_800E21F4;
void func_800DC308(void) {
    D_800E21F4 = 1;
}

void func_800DC318(void) {
    D_800E21F4 = 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DC324);

void func_800DC498(s32 arg0, u16 arg1) {
    s32 i;
    D_800E6910.h0 = arg1;
    for (i = 0; i < D_800E6910.h0; i++) {
        D_800E6910.a[i] = arg0 + i;
        D_800E6910.b[i] = 0;
    }
}

void func_800DC4DC(s32 arg0, s32 arg1, s32 arg2) {
    D_800E6910.h0 = arg0;
    D_800E6910.a[arg1] = arg2;
    D_800E6910.b[arg1] = 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DC4FC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DC5B0);

void func_800DC624(void) {
    D_800E6910.h52 = 3;
    D_800E6910.h54 = 0;
}

extern u16 D_800E6962;
u16 func_800DC63C(void) {
    return D_800E6962;
}

u16 func_800DC64C(s32 arg0) {
    return D_800E6910.a[arg0];
}

u16 func_800DC668(s32 arg0) {
    return D_800E6910.b[arg0];
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DC684);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DC738);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DC7EC);

typedef struct { s32 a; s32 b; } S800E6840;
extern S800E6840 D_800E6840_s asm("D_800E6840");
extern s32 D_800E6838;
void func_800DC8C8(void) {
    D_800E6840_s.a = 0;
    D_800E6840_s.b = 0;
    D_800E6838 = 2;
}

typedef struct { s32 a; s32 n; u8 b[0x20]; s32 w[8]; } S800E6840b;
extern S800E6840b D_800E6840_t asm("D_800E6840");
void func_800DC8E8(s32 arg0, s32 arg1) {
    s32 i = D_800E6840_t.n;
    D_800E6840_t.w[i] = arg0;
    D_800E6840_t.b[i] = arg1;
    D_800E6840_t.n++;
}

extern s32 D_800E6840;
s32 func_800DC920(s32 arg0) {
    return arg0 < D_800E6840;
}

s32 func_800DC930(void) {
    return D_800E6840_s.a >= D_800E6840_s.b;
}

typedef struct { s32 a; s32 b; u8 p[0xA0]; u8 c[1]; } S800E6840d;
extern S800E6840d D_800E6840_v asm("D_800E6840");
extern s32 D_800E6838;
s32 func_800DC950(void) {
    if (D_800E6838 != 0) {
        D_800E6838--;
        return 0;
    }
    if (D_800E6840_v.a >= D_800E6840_v.b) {
        return 1;
    }
    D_800E6840_v.c[D_800E6840_v.a] = 0;
    D_800E6840_v.a++;
    return 0;
}

s32 func_800DC920(s32);
s32 func_800DC9B0(s32 arg0, s32 arg1, s32 arg2) {
    return func_800DC920(arg2) != 0;
}

typedef struct { s32 a; s32 b; u8 p[0xA0]; u8 c[1]; } S800E6840c;
extern S800E6840c D_800E6840_u asm("D_800E6840");
s32 func_800DC9D0(void) {
    if (D_800E6840_u.a >= D_800E6840_u.b) {
        return 1;
    }
    D_800E6840_u.c[D_800E6840_u.a] = 0;
    D_800E6840_u.a++;
    return 0;
}

s32 func_800DCA10(s32 arg0, s32 arg1, s32 arg2) {
    return func_800DC920(arg2) != 0;
}

u32 func_800DCA30(s32 arg0) {
    if (arg0 < 0x20) {
        return D_8006EBC8_c.f2DD8[0] & ~D_8006EBC8_c.f379C[0] & (1 << arg0);
    }
    return D_8006EBC8_c.f2DD8[1] & ~D_8006EBC8_c.f379C[1] & (1 << (arg0 - 0x20));
}

s32 func_800DCA94(s32 arg0, s32 arg1) {
    u8 v = D_8006EBC8_h.t[arg0 * 24 + arg1 / 2];
    if (!(arg1 & 1)) {
        return v & 0xF;
    }
    return v >> 4;
}

void func_800DCADC(s32 arg0, s32 arg1, s32 arg2) {
    s32 val;
    if (arg1 & 1) {
        val = arg2 << 4;
        arg2 = 0xF;
    } else {
        val = arg2 & 0xF;
        arg2 = 0xF0;
    }
    D_8006EBC8_h.t[arg0 * 24 + arg1 / 2] = (D_8006EBC8_h.t[arg0 * 24 + arg1 / 2] & arg2) | val;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DCB3C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DCCE8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DCD7C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DCE10);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DCF40);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DD534);

typedef struct { u8 p[0x2B98]; u16 h[0xC0]; u8 b[0xC0]; } S8006EBC8_2B98;
extern S8006EBC8_2B98 D_8006EBC8_2B98 asm("D_8006EBC8");
s32 func_800DD68C(s32 arg0) {
    s32 r = 0;
    s32 i;
    for (i = 0; i < 0xC0; i++) {
        if (D_8006EBC8_2B98.h[i] == arg0) {
            if (D_8006EBC8_2B98.b[i] != 0) {
                D_8006EBC8_2B98.b[i]--;
                r = 1;
                if (D_8006EBC8_2B98.b[i] == 0) {
                    D_8006EBC8_2B98.h[i] = 0;
                }
                break;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DD6F0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DD798);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DD878);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DD934);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DDA88);

typedef struct { u8 p[0x2718]; u16 h[0x180]; u8 b[0x180]; } S8006EBC8_2718;
extern S8006EBC8_2718 D_8006EBC8_2718 asm("D_8006EBC8");
s32 func_800DDD44(s32 arg0) {
    s32 r = 0;
    s32 i;
    for (i = 0; i < 0x180; i++) {
        if (D_8006EBC8_2718.h[i] == arg0) {
            if (D_8006EBC8_2718.b[i] != 0) {
                D_8006EBC8_2718.b[i]--;
                r = 1;
                if (D_8006EBC8_2718.b[i] == 0) {
                    D_8006EBC8_2718.h[i] = 0;
                }
                break;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DDDA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DDE50);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DDF50);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DE330);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DEA18);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DF244);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DF3DC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DF768);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DFA74);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DFDA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800E0148);
