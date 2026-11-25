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

s32 func_800A408C(void) {
    extern s32 *D_800E1478;
    return *D_800E1478;
}

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

void func_800A4DB0(void) {
    void func_8003F63C(void);
    extern u16 D_8007E9F0;
    if ((D_8007E9F0 & 0x90F) == 0x90F) {
        func_8003F63C();
    }
}

void func_800A4DE4(void) {
    extern s32 D_800E2238;
    func_8003D504(D_800E2238);
}

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

extern S8007EE88 *D_80086FB4;
void SetDefDrawEnv(void *, s32, s32, s32, s32);
void SetDefDispEnv(void *, s32, s32, s32, s32);
void PutDrawEnv(void *);
void PutDispEnv(void *);
void func_800A5188(void) {
    SetDefDrawEnv(&D_8007EE88_s[0], 0, 0, 0x140, 0xE0);
    SetDefDrawEnv(&D_8007EE88_s[1], 0x140, 0, 0x140, 0xE0);
    SetDefDispEnv((u8 *)&D_8007EE88_s[0] + 0x5C, 0x140, 0, 0x140, 0xE0);
    SetDefDispEnv((u8 *)&D_8007EE88_s[1] + 0x5C, 0, 0, 0x140, 0xE0);
    func_800A5150();
    VSync(0);
    PutDrawEnv(D_80086FB4);
    PutDispEnv((u8 *)D_80086FB4 + 0x5C);
}

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

typedef struct { s32 a; s32 b; s32 c; s32 d; s32 e; s32 f; } S8007E6F0;
extern S8007E6F0 D_8007E6F0;
extern s32 D_8007E698;
extern s32 D_8007E6B0;
void func_80046698(S8007E6F0 *, s32);
void func_800A55B4(s32 n) {
    s32 pad[2];
    s32 f;
    func_8004582C(5);
    f = n * 3;
    D_8007E6F0.a = f + 0x83;
    D_8007E6F0.b = D_8007E698 = (s32)func_8003D8F4(func_80044924(f + 0x83), 1, 2);
    D_8007E6F0.c = f + 0x84;
    D_8007E6F0.d = D_8007E6B0 = (s32)func_8003D8F4(func_80044924(f + 0x84), 1, 2);
    D_8007E6F0.e = 0;
    D_8007E6F0.f = 0;
    func_80046698(&D_8007E6F0, 0);
}

extern s16 D_8007E6A0;
extern s32 D_8007E698;
extern s32 D_8007E6B0;
void func_800A55B4(s32);
s32 func_800A565C(s32 n) {
    func_8004582C(5);
    if (func_80044DD4() != 0) {
        return -1;
    }
    if (n == D_8007E6A8) {
        return 0;
    }
    if (D_8007E6A0 == 0) {
        func_8003D504(D_8007E698);
        func_8003D504(D_8007E6B0);
        return D_8007E6A0 = -1;
    }
    func_800A55B4(n);
    D_8007E6A8 = n;
    return -1;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A570C);

typedef struct { s32 a; u8 r[12]; } S800E5598b;
extern S800E5598b D_800E5598_b[] asm("D_800E5598");
void func_80094CD8(s32);
void func_8003D504(s32);
void func_800A58B4(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_8007E6C0[i] != 0xFF) {
            func_80094CD8(D_800E5598_b[i].a);
        }
        func_8003D504(D_800E5598_b[i].a);
    }
}

typedef struct { u8 p[0xD8]; s32 fD8; u8 q[0x278 - 0xDC]; } A_a59;
extern A_a59 *D_800E257C_a59 asm("D_800E257C");
typedef struct { s32 f0; u8 p[0x2C]; } R_a59;
extern R_a59 D_800E5FA8_a59[] asm("D_800E5FA8");
extern u8 D_800E4914_a59[] asm("D_800E4914");
typedef struct { u8 p[0x304]; R_a59 r[6]; u8 q[0x664 - 0x424]; u8 b[6]; } S_a59;
extern S_a59 D_800E3A50_a59 asm("D_800E3A50");
R_a59 *func_800A593C(s32 a) {
    if (a < 0) {
        a = ~a;
        if (a >= 6) return 0;
        if (D_800E4914_a59[a] == 0xFF) return 0;
        D_800E5FA8_a59[a].f0 = D_800E257C_a59[D_800E4914_a59[a]].fD8;
        return &D_800E5FA8_a59[a];
    }
    if (a >= 6) return 0;
    if (D_800E3A50_a59.b[a] == 0xFF) return 0;
    D_800E3A50_a59.r[a].f0 = D_800E257C_a59[D_800E3A50_a59.b[a]].fD8;
    return &D_800E3A50_a59.r[a];
}

typedef struct { u8 p[0xD8]; s32 fD8; u8 q[0x278 - 0xDC]; } A_a5a;
extern A_a5a *D_800E257C_a5a asm("D_800E257C");
typedef struct { s32 f0; u8 p[0x2C]; } R_a5a;
extern R_a5a D_800E60D0_a5a[] asm("D_800E60D0");
extern u8 D_800E491C_a5a[] asm("D_800E491C");
typedef struct { u8 p[0x424]; R_a5a r[6]; u8 q[0x66A - 0x544]; u8 b[6]; } S_a5a;
extern S_a5a D_800E3A50_a5a asm("D_800E3A50");
R_a5a *func_800A5A28(s32 a) {
    if (a < 0) {
        a = ~a;
        if (a >= 6) return 0;
        if (D_800E491C_a5a[a] == 0xFF) return 0;
        D_800E60D0_a5a[a].f0 = D_800E257C_a5a[D_800E491C_a5a[a]].fD8;
        return &D_800E60D0_a5a[a];
    }
    if (a >= 6) return 0;
    if (D_800E3A50_a5a.b[a] == 0xFF) return 0;
    D_800E3A50_a5a.r[a].f0 = D_800E257C_a5a[D_800E3A50_a5a.b[a]].fD8;
    return &D_800E3A50_a5a.r[a];
}

typedef struct { u8 p[0xD8]; s32 fD8; u8 q[0x278 - 0xDC]; } A_a5b;
extern A_a5b *D_800E257C_a5b asm("D_800E257C");
typedef struct { s32 f0; u8 p[0x2C]; } R_a5b;
extern R_a5b D_800E5470_a5b[] asm("D_800E5470");
extern u8 D_800E41CC_a5b[] asm("D_800E41CC");
typedef struct { u8 p[0x544]; R_a5b r[6]; u8 q[0x670 - 0x664]; u8 b[6]; } S_a5b;
extern S_a5b D_800E3A50_a5b asm("D_800E3A50");
R_a5b *func_800A5B14(s32 a) {
    if (a < 0) {
        a = ~a;
        if (a >= 6) return 0;
        if (D_800E41CC_a5b[a] == 0xFF) return 0;
        D_800E5470_a5b[a].f0 = D_800E257C_a5b[D_800E41CC_a5b[a]].fD8;
        return &D_800E5470_a5b[a];
    }
    if (a >= 6) return 0;
    if (D_800E3A50_a5b.b[a] == 0xFF) return 0;
    D_800E3A50_a5b.r[a].f0 = D_800E257C_a5b[D_800E3A50_a5b.b[a]].fD8;
    return &D_800E3A50_a5b.r[a];
}

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

#define SetSpadStack(addr) __asm__ volatile("move $8, %0\n\tsw $29, 0($8)\n\taddiu $8, $8, -4\n\tmove $29, $8" : : "r"(addr) : "$8", "memory")
#define ResetSpadStack() __asm__ volatile("addiu $29, $29, 4\n\tlw $29, 0($29)\n\tnop" : : : "memory")
extern s16 D_8006B230;
extern u8 D_800E3A12;
extern u8 *D_80086FB4_a74 asm("D_80086FB4");
extern u8 *D_8007EE0C_a74 asm("D_8007EE0C");
extern u8 *D_8007EDFC_a74 asm("D_8007EDFC");
extern s32 D_800E3A44;
extern u8 D_800E253C[];
void func_800A71F0(void);
void func_800307F8(u8 *);
void func_8003CC2C(s32);
void func_80032FAC(u8 *);
void func_800A74F0(void) {
    SetSpadStack(0x1F8003FC);
    func_800267A4(D_8006B230);
    if (D_800E3A12 == 0) {
        func_800A71F0();
    }
    func_800A748C();
    ClearOTagR(D_80086FB4_a74 + 0x70, 0x1000);
    ClearOTagR(D_80086FB4_a74 + 0x4070, 8);
    D_8007EE0C_a74 = D_80086FB4_a74 + 0x70;
    D_8007EDFC_a74 = D_80086FB4_a74 + 0x70;
    func_800307F8(D_80086FB4_a74 + 0x78);
    D_8007EDFC_a74 = D_80086FB4_a74 + 0x4070;
    func_800307F8(D_80086FB4_a74 + 0x4078);
    func_800307F8(D_80086FB4_a74 + 0x4070);
    func_8003CC2C(D_800E3A44);
    func_80032FAC(D_800E253C);
    ResetSpadStack();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800A75EC);

extern s16 D_800E3A0A;
extern s8 D_800E41D4;
extern u8 D_800E3A08;
s32 func_800CF354(void);
s32 func_800AFB84(void);
s32 func_800A773C(void) {
    if (D_800E3A0A != 0) {
        return -1;
    }
    if (D_800E41D4 != 0) {
        return -1;
    }
    if (D_800E61F2 != 0) {
        return -1;
    }
    if (D_800E3A08 != 0) {
        return -1;
    }
    if (func_800CF354() != 0) {
        return -1;
    }
    if (func_800AFB84() == 0) {
        return 0;
    }
    return -1;
}

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

extern s32 D_800E48E8_a8a[] asm("D_800E48E8");
extern s32 D_800E21E4;
extern s32 D_800E1504;
extern s32 D_800E1508;
extern s32 D_800E150C;
void func_800A8A30(s32 a) {
    func_80032DD0();
    func_8004582C(9);
    D_800E1504 = func_8003D070(func_80044924(a), D_800E21E4);
    D_800E48E8_a8a[0] = a;
    D_800E48E8_a8a[1] = D_800E1504;
    D_800E48E8_a8a[2] = 4;
    D_800E1508 = func_8003D8F4(func_80044924(4), 1, 2);
    D_800E48E8_a8a[3] = D_800E1508;
    D_800E48E8_a8a[4] = 5;
    D_800E150C = func_8003D8F4(func_80044924(5), 1, 2);
    D_800E48E8_a8a[5] = D_800E150C;
    D_800E48E8_a8a[6] = 0;
    D_800E48E8_a8a[7] = 0;
    func_80046698(D_800E48E8_a8a, 0);
}

s32 func_8004208C(s32, s32, s32);
s32 func_80041F6C(s32);
void func_8003BEC4(s32, s32);
void func_8003B8C8(s32);
void func_80032D78(s32);
void func_80029F58(s32);
extern u8 D_8007EDEC[];
extern u8 D_8007EDF0[];
extern u8 D_8002C1C8[];
void func_8002C9C0(void *);
void func_800A8B00(void) {
    s32 p = 0;
    while ((p = func_8004208C(p, 10, 0)) != 0) {
        func_8003BEC4(func_80041F6C(p), 1);
        func_8003B8C8(p);
    }
    func_80032D78(0);
    func_80029F58(0);
    D_8007EDEC[0] = 0;
    D_8007EDEC[1] = 0;
    D_8007EDEC[2] = 0;
    D_8007EDF0[0] = 0;
    D_8007EDF0[1] = 0;
    D_8007EDF0[2] = 0;
    func_8002C9C0(D_8002C1C8);
}

extern u32 D_800E411C;
extern u16 D_8007E69E;
extern s32 D_8007E6E8;
extern u8 D_8007E69C;
extern u8 D_8006B43E;
s32 func_800BDC54(void);
void func_800A8BA4(void) {
    s32 f = (D_800E411C >> 14) & 1;
    if (f == 1 && D_8007E69E == 0 && func_800BDC54() == 0 && D_8007E6E8 != 9 && D_8007E6E8 != 8 && D_8007E69C == 0) {
        D_8006B43E = f;
    } else {
        D_8006B43E = 0;
    }
}

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

typedef struct { u8 p[0x21C]; u16 h21C; u16 h21E; u8 q[0x6CC - 0x220]; u32 f6CC; } S800E3A50_21C;
extern S800E3A50_21C D_800E3A50_21C asm("D_800E3A50");
extern u32 D_800E411C;
extern s32 D_800724F0[];
extern s32 D_80072520[];
extern s32 D_8007E768[];
void func_800AA3C8(void) {
    s32 i;
    if ((D_800E411C >> 6) & 1) {
        for (i = 0; i < 3; i++) {
            D_800724F0[i] = D_80072520[i];
            D_8007E6C0[i] = D_8007E768[i];
        }
        D_800E3A50_21C.h21C = D_800E3A50_21C.h21E;
        D_800E3A50_21C.f6CC &= ~0x40;
    }
}

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

extern s32 D_8007E6E8;
void func_8003B13C(s32, s32);
void func_8003CB78(s32, s32);
s32 func_80041F0C(s32, s32);
void func_8002A228(s32);
void func_8003D8A8(s32);
void func_800AAFE0(void) {
    s32 a;
    if (D_8007E6E8 == 8) {
        func_8003B13C(0xC000, 0);
        a = 0x20000;
    } else {
        func_8003B13C(0x4000, 0);
        a = 0x1C000;
    }
    func_8003CB78(a, 0);
    if (func_80041F0C(0x10, 0x706F6F6C) != 0) {
        func_8002A228(0x706F6F6C);
    }
    func_8003D8A8(2);
}

s32 func_80033974(s32 *, s32);
void func_80033530(s32 *);
void func_800AB060(void) {
    s32 *p = (s32 *)D_800724E8;
    s32 n = p[0];
    s32 *q = p;
    s32 i;
    if (n != 0x1201) {
        for (i = 0; i < n; i++) {
            s32 *e;
            q++;
            e = (s32 *)((u8 *)p + *q);
            if (*e != 0x6C7A7373) {
                func_80033530(e);
                DrawSync(0);
            } else {
                s32 r = func_80033974(e, 0);
                func_80033530((s32 *)r);
                DrawSync(0);
                func_8003D504(r);
            }
        }
    }
    DrawSync(0);
    func_8003D504((s32)D_800724E8);
    func_800C978C();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB15C);

typedef struct { s16 h0; s16 id; u8 p[0xC]; s16 h10; s16 h12; s16 h14; s16 h16; s32 f18; s32 f1C; } S800E5638;
extern S800E5638 D_800E5638[];
extern s32 D_800E41B0;
void func_800AB328(s32 id, s32 target, s32 n) {
    s32 i;
    if (n == 0) {
        n = 1;
    }
    for (i = 0; i < D_800E41B0; i++) {
        if (D_800E5638[i].id == id) {
            D_800E5638[i].f1C = -((D_800E5638[i].h10 - target) << 16) / n;
            D_800E5638[i].h16 = 1;
            D_800E5638[i].h14 = n;
            D_800E5638[i].f18 = D_800E5638[i].h10 << 16;
        }
    }
}

typedef struct { s16 f0, f2, f4, f6, f8, fA, fC, fE, f10, f12, f14, f16; s32 f18, f1C; } E_ab3;
extern E_ab3 D_800E5638_ab3[] asm("D_800E5638");
void func_8004A26C();
void func_800AB3B0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 i;
    if (D_800E41B0 < 8) {
        if (a0 != -1) {
            for (i = 0; i < D_800E41B0; i++) {
                if (D_800E5638_ab3[i].f2 == a0) {
                    D_800E5638_ab3[i].f2 = a0;
                    D_800E5638_ab3[i].f0 = a1;
                    D_800E5638_ab3[i].f4 = 0x7FFF;
                    D_800E5638_ab3[i].f8 = a2;
                    D_800E5638_ab3[i].fA = a4;
                    D_800E5638_ab3[i].fC = a3;
                    D_800E5638_ab3[i].f10 = a5;
                    D_800E5638_ab3[i].fE = a6;
                    D_800E5638_ab3[i].f12 = 0;
                    D_800E5638_ab3[i].f16 = 0;
                    func_8004A26C(0, 1 << D_800E5638_ab3[i].f6);
                    return;
                }
            }
        }
        D_800E5638_ab3[D_800E41B0].f6 = D_800E41B0 + 0x10;
        D_800E5638_ab3[D_800E41B0].f2 = a0;
        D_800E5638_ab3[D_800E41B0].f0 = a1;
        D_800E5638_ab3[D_800E41B0].f4 = 0x7FFF;
        D_800E5638_ab3[D_800E41B0].f8 = a2;
        D_800E5638_ab3[D_800E41B0].fA = a4;
        D_800E5638_ab3[D_800E41B0].fC = a3;
        D_800E5638_ab3[D_800E41B0].f10 = a5;
        D_800E5638_ab3[D_800E41B0].fE = a6;
        D_800E5638_ab3[D_800E41B0].f12 = 0;
        D_800E5638_ab3[D_800E41B0].f16 = 0;
        func_8004A26C(0, 1 << D_800E5638_ab3[D_800E41B0].f6);
        D_800E41B0++;
    }
}

typedef struct { s16 h0; s16 id; s16 h4; s16 h6; u8 p[0xE]; s16 h16; u8 q[8]; } S800E5638b;
extern S800E5638b D_800E5638_b[] asm("D_800E5638");
typedef struct { s16 a; s16 b; s16 c; s16 d; } S80072530f;
extern S80072530f D_80072530_f[] asm("D_80072530");
extern u16 *D_800E3A4C;
extern u8 D_8006417C;
extern u16 D_800E3A10;
void func_800AB4E8(void) {
    s32 i;
    D_800E41B0 = 0;
    for (i = 0; i < 9; i++) {
        D_800E5638_b[i].id = -1;
        D_800E5638_b[i].h6 = 0;
        D_800E5638_b[i].h0 = 0xFF;
        D_800E5638_b[i].h4 = 0x7FFF;
        D_800E5638_b[i].h16 = 0;
    }
    D_800E3A10 = *D_800E3A4C;
    if (D_8006417C == 0) {
        for (i = 0; i < 8; i++) {
            D_80072530_f[i].a = 0xFF;
            D_80072530_f[i].d = 0;
            D_80072530_f[i].c = 0;
            D_80072530_f[i].b = 0;
        }
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB584);

extern u8 D_800E2280;
extern u8 D_8006417C;
extern s32 D_800E490C;
extern s16 D_800E3A10_ab5 asm("D_800E3A10");
void func_8004A26C();
s32 func_800AB584(s32);
void func_8004A1DC(s32, s32, s32, s32);
void func_8004A18C(s32, s32, s32, s32);
void func_800AB5A8(s32 a, s32 b, s32 c, s32 d) {
    if (D_800E2280 != 0) {
        func_8004A26C(0);
        if (D_8006417C == 0 && a != 0xFF) {
            if (!(a & 0x100)) {
                D_800E490C |= b;
                if (a < D_800E3A10_ab5) {
                    func_8004A1DC(func_800AB584(a), b, c, d);
                }
            } else {
                D_800E490C &= b ^ 0xFFFFFF;
                func_8004A18C(a & 0xFF, b, c, d);
            }
        }
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AB694);

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_abd;
typedef struct { s16 vx, vy, vz, pad; } SV_abd;
typedef struct { s16 vx, vy; } DV_abd;
typedef struct { SV_abd v; DV_abd sxy; s32 p; s32 flag; } W_abd;
typedef struct { u8 p[0x3E]; s16 h3E; u8 q[2]; s16 h42; u8 r[2]; s16 h46; u8 s[0x278 - 0x48]; } A_abd;
typedef struct { u8 p[0x34]; MAT_abd m; u8 q[0x74 - 0x54]; A_abd *a; } S_abd;
extern S_abd D_800E2508_abd asm("D_800E2508");
extern s32 D_800A1204;
s32 func_800ABDFC(s32 i, s32 *x, s32 *y, s32 dy) {
    MAT_abd m0;
    MAT_abd m1;
    W_abd w;
    s32 z;
    func_800A735C((u8 *)&m0);
    m0.t[0] = D_800E2508_abd.a[i].h3E;
    m0.t[1] = D_800E2508_abd.a[i].h42 + dy;
    m0.t[2] = D_800E2508_abd.a[i].h46;
    CompMatrix(&D_800E2508_abd.m, &m0, &m1);
    SetRotMatrix(&m1);
    SetTransMatrix(&m1);
    func_800B0FD4((s16 *)&w.v);
    z = RotTransPers(&w.v, &w.sxy, &w.p, &w.flag);
    *y = w.sxy.vy;
    *x = w.sxy.vx;
    return z >> D_800A1204;
}

typedef struct { s16 x, y; } XY_abe;
typedef struct { u32 tag; u32 code[2]; } DO_abe;
extern XY_abe D_800E61F8[];
extern DO_abe D_800E6248[];
extern DO_abe D_800E6290[];
extern s16 D_800E14C0;
extern u8 *D_80086FB4_abe asm("D_80086FB4");
void SetDrawOffset(DO_abe *, XY_abe *);
void func_800ABEF0(void) {
    u8 *ot;
    DO_abe *p, *q;
    D_800E61F8[D_800E3A44].x = D_800E3A44 * D_800E14C0;
    D_800E61F8[D_800E3A44].y = 0;
    SetDrawOffset(&D_800E6248[D_800E3A44], &D_800E61F8[D_800E3A44]);
    SetDrawOffset(&D_800E6290[D_800E3A44], &D_800E61F8[D_800E3A44]);
    p = &D_800E6248[D_800E3A44];
    q = &D_800E6290[D_800E3A44];
    ot = D_80086FB4_abe;
    p->tag = (p->tag & 0xFF000000) | (*(u32 *)(ot + 0x70) & 0xFFFFFF);
    *(u32 *)(ot + 0x70) = (*(u32 *)(ot + 0x70) & 0xFF000000) | ((u32)p & 0xFFFFFF);
    q->tag = (q->tag & 0xFF000000) | (*(u32 *)(ot + 0x4070) & 0xFFFFFF);
    *(u32 *)(ot + 0x4070) = (*(u32 *)(ot + 0x4070) & 0xFF000000) | ((u32)q & 0xFFFFFF);
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AC01C);

typedef struct { u8 a[0x1C]; u8 b[0x1C]; } P_ac4;
typedef struct { u8 p[0x6C]; P_ac4 *prims; u8 q[0x84 - 0x70]; u16 *rng; u8 r[0x9C - 0x88]; u16 n; } S_ac4;
extern S_ac4 D_800E2508_ac4 asm("D_800E2508");
void func_800AC48C(void) {
    s32 i, j;
    for (i = 0; i < D_800E2508_ac4.n; i++) {
        for (j = D_800E2508_ac4.rng[i]; j < D_800E2508_ac4.rng[i + 1] - 1; j++) {
            CatPrim(D_800E2508_ac4.prims[j].a, D_800E2508_ac4.prims[j + 1].a);
            CatPrim(D_800E2508_ac4.prims[j].b, D_800E2508_ac4.prims[j + 1].b);
        }
    }
}

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

typedef struct { u8 t[0x20]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s16 h38; s16 h3A; s32 f3C; u8 q[0x58 - 0x40]; } R_ad2;
typedef struct { u8 p[0x184]; R_ad2 r[4]; } S_ad2;
extern S_ad2 D_800E3A50_ad2 asm("D_800E3A50");
extern u8 D_8006B3F4;
void func_80317904(s32, s32, s32, s32, s32);
void func_800AD2C0(s32 i, s32 n, s32 x, s32 y, s32 z, s32 e) {
    s32 vx, vy, vz;
    if (D_8006B3F4) {
        func_80317904(x, y, z, e, n);
    }
    if (n == 0) {
        n = 1;
    }
    vx = ((x << 16) - D_800E3A50_ad2.r[i].f20) / n;
    vy = ((y << 16) - D_800E3A50_ad2.r[i].f24) / n;
    vz = ((z << 16) - D_800E3A50_ad2.r[i].f28) / n;
    D_800E3A50_ad2.r[i].h38 = e;
    D_800E3A50_ad2.r[i].f3C = n;
    D_800E3A50_ad2.r[i].h3A = 1;
    D_800E3A50_ad2.r[i].f2C = vx;
    D_800E3A50_ad2.r[i].f30 = vy;
    D_800E3A50_ad2.r[i].f34 = vz;
}

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

typedef struct { s16 vx, vy, vz, pad; } SV_ad5;
typedef struct {
    u32 tag; u8 r0, g0, b0, code;
    s16 x0, y0; u8 u0, v0; u16 clut;
    s16 x1, y1; u8 u1, v1; u16 tpage;
    s16 x2, y2; u8 u2, v2; u16 pad1;
    s16 x3, y3; u8 u3, v3; u16 pad2;
} FT4_ad5;
typedef struct { SV_ad5 v[4]; FT4_ad5 prim[2]; } S_ad5;
void func_80011574(FT4_ad5 *);
void func_80011474(FT4_ad5 *, s32);
u16 GetTPage(s32, s32, s32, s32);
u16 GetClut(s32, s32);
void func_800AD53C(S_ad5 *s) {
    FT4_ad5 *p = &s->prim[0];
    FT4_ad5 *q = &s->prim[1];
    func_80011574(p);
    s->v[3].vx = -0x200;
    s->v[3].vy = 0;
    s->v[3].vz = -0x200;
    s->v[2].vx = 0x200;
    s->v[2].vy = 0;
    s->v[2].vz = -0x200;
    s->v[1].vx = -0x200;
    s->v[1].vy = 0;
    s->v[1].vz = 0x200;
    s->v[0].vx = 0x200;
    s->v[0].vy = 0;
    s->v[0].vz = 0x200;
    p->r0 = 0x40;
    p->g0 = 0x40;
    p->b0 = 0x40;
    p->tpage = GetTPage(0, 2, 0x200, 0xE0);
    p->clut = GetClut(0, 0xFB);
    func_80011474(p, 1);
    p->u0 = 0;
    p->v0 = 0xE0;
    p->u1 = 0x1E;
    p->v1 = 0xE0;
    p->u2 = 0;
    p->v2 = 0xFE;
    p->u3 = 0x1E;
    p->v3 = 0xFE;
    *q = *p;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800AD664);

typedef struct { s16 x, y, w, h; } RECT_adb;
typedef struct { u8 a[0x1C]; u8 b[0x1C]; } P_adb;
typedef struct { u8 p[0x68]; s32 n; P_adb *prims; } S_adb;
extern S_adb D_800E2508_adb asm("D_800E2508");
typedef struct { u8 p[0x6CC]; u32 f; } S3_adb;
extern S3_adb D_800E3A50_adb asm("D_800E3A50");
void func_800ADB44(void) {
    RECT_adb r;
    s32 i;
    u8 *buf = func_8003D8F4(0x1800, 0, 2);
    r.x = 0;
    r.y = 0xF0;
    r.w = 0x100;
    r.h = 0xC;
    StoreImage(&r, buf);
    DrawSync(0);
    func_800A544C((u32 *)buf, 0x100);
    LoadImage(&r, buf);
    DrawSync(0);
    D_800E3A50_adb.f |= 0x20;
    for (i = 0; i < D_800E2508_adb.n; i++) {
        func_80011474(&D_800E2508_adb.prims[i].a[0xC], 1);
        func_80011474(&D_800E2508_adb.prims[i].b[0xC], 1);
    }
    func_8003D504((s32)buf);
}

typedef struct { s16 x, y, w, h; } RECT_adc;
typedef struct { u8 a[0x1C]; u8 b[0x1C]; } P_adc;
typedef struct { u8 p[0x68]; s32 n; P_adc *prims; } S_adc;
extern S_adc D_800E2508_adc asm("D_800E2508");
typedef struct { u8 p[0x6CC]; u32 f; } S3_adc;
extern S3_adc D_800E3A50_adc asm("D_800E3A50");
void func_800ADC54(void) {
    RECT_adc r;
    s32 i;
    u8 *buf = func_8003D8F4(0x1800, 0, 2);
    r.x = 0;
    r.y = 0xF0;
    r.w = 0x100;
    r.h = 0xC;
    StoreImage(&r, buf);
    DrawSync(0);
    func_800A5490((u32 *)buf, 0x100);
    LoadImage(&r, buf);
    DrawSync(0);
    D_800E3A50_adc.f &= ~0x20;
    for (i = 0; i < D_800E2508_adc.n; i++) {
        func_80011474(&D_800E2508_adc.prims[i].a[0xC], 0);
        func_80011474(&D_800E2508_adc.prims[i].b[0xC], 0);
    }
    func_8003D504((s32)buf);
}

typedef struct { u8 p[0x14]; s16 h14; u8 q[2]; s32 f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40, f44; } S_add;
extern S_add D_800E3A50_add asm("D_800E3A50");
void func_800ADD68(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 n) {
    s32 t0, t1, t2, t3, t4, t5;
    if (n == 0) n = 1;
    t0 = ((a0 << 16) - D_800E3A50_add.f18) / n;
    t1 = ((a1 << 16) - D_800E3A50_add.f1C) / n;
    t2 = ((a2 << 16) - D_800E3A50_add.f20) / n;
    t3 = ((a3 << 16) - D_800E3A50_add.f24) / n;
    t4 = ((a4 << 16) - D_800E3A50_add.f28) / n;
    t5 = ((a5 << 16) - D_800E3A50_add.f2C) / n;
    D_800E3A50_add.h14 = n;
    D_800E3A50_add.f30 = t0;
    D_800E3A50_add.f34 = t1;
    D_800E3A50_add.f38 = t2;
    D_800E3A50_add.f3C = t3;
    D_800E3A50_add.f40 = t4;
    D_800E3A50_add.f44 = t5;
}

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

extern u8 D_800E5048;
s32 func_80041F6C(s32);
s32 *func_80034024(s32);
void func_800AFAF8(s32 x, s32 y, s32 z, s32 r, s32 id) {
    if (D_800E5048 == 0) {
        s32 *p = func_80034024(func_80041F6C(id));
        if (p != 0) {
            p[0] = x << 16;
            p[1] = y << 16;
            p[2] = z << 16;
            *(s16 *)((u8 *)p + 0x60) = -r;
        }
    }
}

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

typedef struct { u8 p[0x70]; s32 n; s32 a74; s32 a78; } S800E2508_f;
extern S800E2508_f D_800E2508_f asm("D_800E2508");
void func_800AFBD0(s32, s32);
void func_800B06E0_2(s32, s32) asm("func_800B06E0");
void func_800B02B0(void) {
    s32 i;
    D_800E2508_f.a74 = (s32)func_8003D8F4(D_800E2508_f.n * 0x278, 0, 2);
    D_800E2508_f.a78 = (s32)func_8003D8F4(D_800E2508_f.n * 0x90, 0, 2);
    for (i = 0; i < D_800E2508_f.n; i++) {
        func_800AFBD0(i, 0);
        func_800B06E0_2(i, 0);
    }
}

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

typedef struct { u8 p[8]; s16 x; s16 y; s16 w; s16 h; u8 q[8]; s16 x2; s16 y2; s16 w2; s16 h2; } S800E63E8;
extern S800E63E8 D_800E63E8;
extern s16 *D_800E39E4;
void func_800B0F1C(s16 x0, s16 x1, s32 y0, s32 y1) {
    S800E63E8 *r;
    s32 a = x0 + D_800E39E4[0];
    s32 b = x1 + D_800E39E4[0];
    s32 c = (y0 >> 16) + D_800E39E4[1];
    s32 d = (y1 >> 16) + D_800E39E4[1];
    s32 w;
    if (a < b) {
        r = &D_800E63E8;
        w = b - a;
        r->x = a;
        r->w = w;
        r->x2 = a;
    } else {
        r = &D_800E63E8;
        w = a - b;
        r->x = b;
        r->w = w;
        r->x2 = b;
    }
    r->w2 = w;
    if (c < d) {
        r = &D_800E63E8;
        w = d - c;
        r->y = c;
        r->h = w;
        r->y2 = c;
        r->h2 = w;
    } else {
        r = &D_800E63E8;
        w = c - d;
        r->y = d;
        r->h = w;
        r->y2 = d;
        r->h2 = w;
    }
}

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

typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; s32 fD8; s32 fDC; u8 r[0x270 - 0xE0]; u32 f270; u8 s[4]; } A_b16;
typedef struct { u8 p[0x70]; s32 n; A_b16 *a; } S_b16;
extern S_b16 D_800E2508_b16 asm("D_800E2508");
void func_800B16B0(void) {
    s32 i;
    for (i = 0; i < D_800E2508_b16.n; i++) {
        if (!(D_800E2508_b16.a[i].f38 & 0x83C020)) {
            func_80094140(D_800E2508_b16.a[i].fD8);
            if ((D_800E2508_b16.a[i].f270 >> 11) & 1) {
                func_80094140(D_800E2508_b16.a[i].fDC);
            }
        }
    }
}

typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; s32 fD8; s32 fDC; u8 r[0x270 - 0xE0]; u32 f270; u8 s[4]; } A_b17;
typedef struct { u8 p[0x70]; s32 n; A_b17 *a; } S_b17;
extern S_b17 D_800E2508_b17 asm("D_800E2508");
void func_800B176C(void) {
    s32 i;
    for (i = 0; i < D_800E2508_b17.n; i++) {
        s32 f = D_800E2508_b17.a[i].f38;
        if (!(f & 0x3C020)) {
            if (f & 0x800000) {
                func_80094140(D_800E2508_b17.a[i].fD8);
                if ((D_800E2508_b17.a[i].f270 >> 11) & 1) {
                    func_80094140(D_800E2508_b17.a[i].fDC);
                }
            }
        }
    }
}

typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; s32 fD8; s32 fDC; u8 r[0x270 - 0xE0]; u32 f270; u8 s[4]; } A_b18;
typedef struct { u8 p[0x70]; s32 n; A_b18 *a; } S_b18;
extern S_b18 D_800E2508_b18 asm("D_800E2508");
extern A_b18 *D_800A1258_b18 asm("D_800A1258");
void func_800B1834(void) {
    s32 i;
    for (i = 0; i < D_800E2508_b18.n; i++) {
        if (!(D_800E2508_b18.a[i].f38 & 0x81C020)) {
            D_800A1258_b18 = &D_800E2508_b18.a[i];
            func_80094318(D_800E2508_b18.a[i].fD8);
            if ((D_800E2508_b18.a[i].f270 >> 11) & 1) {
                func_80094318(D_800E2508_b18.a[i].fDC);
            }
        }
    }
}

typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; s32 fD8; s32 fDC; u8 r[0x270 - 0xE0]; u32 f270; u8 s[4]; } A_b19;
typedef struct { u8 p[0x70]; s32 n; A_b19 *a; } S_b19;
extern S_b19 D_800E2508_b19 asm("D_800E2508");
extern A_b19 *D_800A1258_b19 asm("D_800A1258");
void func_800B18F0(void) {
    s32 i;
    for (i = 0; i < D_800E2508_b19.n; i++) {
        s32 f = D_800E2508_b19.a[i].f38;
        if (!(f & 0x1C020)) {
            if (f & 0x800000) {
                D_800A1258_b19 = &D_800E2508_b19.a[i];
                func_80094318(D_800E2508_b19.a[i].fD8);
                if ((D_800E2508_b19.a[i].f270 >> 11) & 1) {
                    func_80094318(D_800E2508_b19.a[i].fDC);
                }
            }
        }
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B19B8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B1E7C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B2690);

s32 func_800B2864(s32 arg0, s32 arg1, s32 arg2) {
    switch (arg0) {
    case 0:
    case 1:
        if (arg1 == 0xC) {
            return arg2 + 0x12E;
        }
        if (arg1 == 0x19) {
            return arg2 + 0x1BB;
        }
        if (arg0 == 0) {
            return arg2 + 0x102;
        }
        return arg2 + 0x12A;
    case 2:
        return arg2 + 0x12C;
    case 3:
        return arg2;
    case 4:
        return arg2 + 2;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B28E0);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B2B3C);

typedef struct { u8 p[0x100]; s32 f100; } M_b32;
typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; M_b32 *fD8; s32 fDC; u8 r[0x270 - 0xE0]; u32 f270; u8 s[4]; } A_b32;
typedef struct { u8 p[0x70]; s32 n; A_b32 *a; } S_b32;
extern S_b32 D_800E2508_b32 asm("D_800E2508");
extern A_b32 *D_800A1258_b32 asm("D_800A1258");
void func_800B323C(void) {
    s32 i;
    for (i = 0; i < D_800E2508_b32.n; i++) {
        if (!(D_800E2508_b32.a[i].f38 & 0x1C020) && D_800E2508_b32.a[i].fD8->f100 != 0) {
            D_800A1258_b32 = &D_800E2508_b32.a[i];
            if ((D_800E2508_b32.a[i].f270 >> 11) & 1) {
                func_8009B1A0(D_800E2508_b32.a[i].fDC);
            }
            func_8009B1A0(D_800E2508_b32.a[i].fD8);
        }
    }
}

typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; s32 fD8; s32 fDC; u8 r[0x270 - 0xE0]; u32 f270; u8 s[4]; } A_b33;
typedef struct { u8 p[0x70]; s32 n; A_b33 *a; } S_b33;
extern S_b33 D_800E2508_b33 asm("D_800E2508");
void func_800B3310(void) {
    s32 i;
    for (i = 0; i < D_800E2508_b33.n; i++) {
        if (!(D_800E2508_b33.a[i].f38 & 0x1C020)) {
            func_80096888(D_800E2508_b33.a[i].fD8);
            if ((D_800E2508_b33.a[i].f270 >> 11) & 1) {
                func_80096888(D_800E2508_b33.a[i].fDC);
            }
        }
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B33CC);

extern void *D_800A1274;
extern u8 D_800E253C[];
extern u16 D_800E1550;
void func_800B0FF4(void);
void func_800B33CC(void);
void func_800B1E7C(void);
void func_800B2690(void);
void func_800B323C(void);
void func_800B3310(void);
void func_800B16B0(void);
void func_800B1834(void);
void func_800B19B8(void);
void func_800B176C(void);
void func_800B18F0(void);
void func_80098694(s32, s32);
void func_800B2B3C(s32);
void func_80098720(void);
void func_800B35F8(s32 a) {
    D_800A1274 = D_800E253C;
    func_800B0FF4();
    func_800B33CC();
    func_800B1E7C();
    func_800B2690();
    func_800B323C();
    func_800B3310();
    func_800B16B0();
    func_800B1834();
    func_800B19B8();
    func_800B176C();
    func_800B18F0();
    func_80098694(0x800, 0);
    func_800B2B3C(a);
    func_80098720();
    D_800E1550++;
}

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

extern s32 D_800E6474;
void func_800B5A34(s32 arg0) {
    if (D_800E14B8[0] == 0xFF) {
        s32 b = arg0 << 3;
        s32 v;
        *(s32 *)(D_1F800004 + 0x3C) = func_800B589C(b | 1) << 16;
        *(s32 *)(D_1F800004 + 0x44) = func_800B589C(b | 3) << 16;
        v = func_800B589C(b | 5) & 0xFFF;
        *(s16 *)(D_1F800004 + 0xFA) = *(s16 *)(D_1F800004 + 0xFC) = v;
        ((void (*)(s32, s32))func_800B06E0)(D_800E6474, func_800B589C(b | 7));
    }
}

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

typedef struct { s16 a; s16 b; s32 c; } S80072530c;
extern S80072530c D_80072530_c[] asm("D_80072530");
void func_8004A628(s32, s32, s32, s32);
void func_800B5CF8(void) {
    s32 ch = func_800B5C1C(1);
    s32 a;
    D_80072530_c[ch].b = func_800B5C1C(5);
    a = func_800B5C1C(3);
    func_8004A628(0, 1 << (ch + 8), a, func_800B5C1C(5));
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

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

typedef struct { s16 a, b, c, d; } E_b5e;
extern E_b5e D_80072530_b5e[] asm("D_80072530");
void func_800AB5A8(s32, s32, s32, s32);
void func_800B5E00(void) {
    s32 id;
    s32 v = 0x80;
    s32 p;
    s32 ch;
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
        p = 0x7F;
        id = func_800B5C1C(2);
        ch = func_800B5C1C(4);
        *(s32 *)(D_1F800004 + 0x228) += 6;
    } else {
        id = func_800B5C1C(2);
        v = func_800B5C1C(4);
        p = func_800B5C1C(6);
        ch = func_800B5C1C(8);
        *(s32 *)(D_1F800004 + 0x228) += 10;
    }
    ch &= 7;
    D_80072530_b5e[ch].a = id;
    D_80072530_b5e[ch].b = p;
    D_80072530_b5e[ch].c = v;
    D_80072530_b5e[ch].d = 0;
    func_800AB5A8(id, 1 << (ch + 8), v, p);
}

void func_800AB3B0(s32, s32, s32, s32, s32, s32, s32);
void func_800B5F10(void) {
    s32 a = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x40);
    s32 b = func_800B5C54(5, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x20);
    s32 c = func_800B5C54(7, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x10);
    s32 d = func_800B5C1C(1);
    s32 e = func_800B5C1C(10);
    s32 f = func_800B5C1C(12);
    func_800AB3B0(-1, d, a, b, c, e, f);
    *(s32 *)(D_1F800004 + 0x228) += 0xE;
}

extern s32 D_800E6474;
void func_800AB3B0(s32, s32, s32, s32, s32, s32, s32);
void func_800B6020(void) {
    s32 a = func_800B5C1C(1);
    s32 b = func_800B5C1C(3);
    s32 c = func_800B5C1C(5);
    func_800AB3B0(D_800E6474, a, 0, 0, 0, b, c);
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B60A4);

typedef struct { u32 b0 : 5; u32 b5 : 1; u32 rest : 26; } F800B6344;
void func_800B6344(void) {
    ((F800B6344 *)(D_1F800004 + 0x270))->b5 = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u8 p[0x20]; s16 f20; s16 f22; s16 f24; u8 q[0x278 - 0x26]; } A_b63;
extern A_b63 *D_800E257C_b63 asm("D_800E257C");
typedef struct { u8 p[0x228]; s32 pc; } C_b63;
extern C_b63 *D_1F800004_b63 asm("D_1F800004");
s32 func_800C6BA4(s32);
void func_800B638C(void) {
    s32 n = func_800C6BA4(2);
    if (n != 0xFF) {
        s32 v = func_800B5C1C(3);
        switch (D_800E14B8[D_1F800004_b63->pc + 1]) {
        case 0:
            D_800E257C_b63[n].f20 = v;
            break;
        case 1:
            D_800E257C_b63[n].f22 = v;
            break;
        case 2:
            D_800E257C_b63[n].f24 = v;
            break;
        }
    }
    D_1F800004_b63->pc += 5;
}

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

typedef struct { u8 p[0x228]; s32 pc; } C_b7a;
extern C_b7a *D_1F800004_b7a asm("D_1F800004");
s32 func_80044EE0_b7a(s32) asm("func_80044EE0");
extern u8 *D_800E5FA0;
extern u8 D_800E5798;
extern s32 D_800E6480;
s32 func_800BDC54(void);
void func_8004AC00(u8 *, s32);
void func_8003D504(s32);
u8 *func_8003D8F4(s32, s32, s32);
void func_800B7A24(void) {
    s32 id;
    if (D_800E14B8[D_1F800004_b7a->pc + 1] == 0) {
        if (func_800BDC54() == -1) {
            D_800E6480 = 1;
            return;
        }
        id = func_800B5C1C(2) + 0x8B;
        func_80044EE0_b7a(0);
        func_8004582C(10);
        func_80045F14(id, D_800E5FA0 = func_8003D8F4(func_80044924(id), 0, 2), 0);
        func_8004582C(5);
        D_800E5798 = 1;
        D_1F800004_b7a->pc += 4;
        return;
    }
    if (func_80044EE0_b7a(1) != 0) {
        D_800E6480 = 1;
        return;
    }
    func_80044EE0_b7a(0);
    func_8004AC00(D_800E5FA0, 1);
    func_8003D504((s32)D_800E5FA0);
    D_800E5798 = 0;
    D_1F800004_b7a->pc += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B7B58);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B7EF8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8020);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B82E0);

typedef struct { u8 p[0x284]; s16 a; s16 b; s16 c; s16 d; } S_b85;
extern S_b85 D_800E3A50_b85 asm("D_800E3A50");
void func_800B857C(void) {
    D_800E3A50_b85.a = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x80);
    D_800E3A50_b85.b = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x40);
    D_800E3A50_b85.c = func_800B5C54(5, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x20);
    D_800E3A50_b85.d = func_800B5C54(7, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 9], 0x10);
    *(s32 *)(D_1F800004 + 0x228) += 10;
}

typedef struct { u8 p[0x38]; s32 f38; s32 f3C; s32 f40; s32 f44; u8 q[0x228 - 0x48]; s32 pc; u8 r[0x270 - 0x22C]; u32 f270; } C_b86;
extern C_b86 *D_1F800004_b86 asm("D_1F800004");
extern u8 D_800E546C;
extern s32 D_800E6474;
s32 func_800B057C_2(s32, s32) asm("func_800B057C");
void func_800B865C(void) {
    s32 v;
    C_b86 *c;
    D_1F800004_b86->f3C = func_800B5C54(1, D_800E14B8[D_1F800004_b86->pc + 7], 0x80) << 16;
    D_1F800004_b86->f44 = func_800B5C54(3, D_800E14B8[D_1F800004_b86->pc + 7], 0x40) << 16;
    v = func_800B5C54(5, D_800E14B8[D_1F800004_b86->pc + 7], 0x20);
    c = D_1F800004_b86;
    c->f38 |= 0x40;
    c->f40 = v << 16;
    v = c->f40;
    if (D_800E546C != 0) {
        func_800B06E0_2(D_800E6474, 0);
    } else if ((c->f270 >> 19) & 1) {
        func_800B057C_2(D_800E6474, 0);
    }
    D_1F800004_b86->f40 = v;
    D_1F800004_b86->f270 |= 0x10000;
    D_1F800004_b86->pc += 8;
}

typedef struct { u8 p[0x38]; u32 f38; s32 f3C; u8 q[4]; s32 f44; u8 r[0x228 - 0x48]; s32 pc; u8 s[0x270 - 0x22C]; u32 f270; } C_b87;
extern C_b87 *D_1F800004_b87 asm("D_1F800004");
extern s32 D_800E6474;
void func_800B06E0_2(s32, s32) asm("func_800B06E0");
void func_800B878C(void) {
    D_1F800004_b87->f3C = func_800B5C54(1, D_800E14B8[D_1F800004_b87->pc + 5], 0x80) << 16;
    D_1F800004_b87->f44 = func_800B5C54(3, D_800E14B8[D_1F800004_b87->pc + 5], 0x40) << 16;
    D_1F800004_b87->f38 &= ~0x40;
    func_800B06E0_2(D_800E6474, func_800B5C1C(6));
    D_1F800004_b87->f270 |= 0x10000;
    D_1F800004_b87->pc += 8;
}

s32 func_80025044(s32);
void func_800B8854(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    s32 a = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7], 0x40);
    s32 b = func_800B5C54(5, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7], 0x20);
    func_800B5B98(v, (func_80025044(a) * b) >> 12);
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

typedef struct { u8 p[0x228]; s32 pc; } C_b89;
extern C_b89 *D_1F800004_b89 asm("D_1F800004");
extern u8 D_800E546C;
extern s32 D_80076688;
extern u8 D_800E60C8;
extern s32 D_800E5614;
extern s32 D_8007257C;
extern s32 D_800E6470;
extern s32 D_800E6480;
s32 func_800BDC54(void);
s32 func_8001BF48(s32, s32, s32, s32);
void func_800B8910(void) {
    s32 a;
    if (D_800E546C != 0) {
        D_80076688 = func_800B5C1C(3);
        D_800E60C8 = 1;
        D_800E5614 = func_800B5C1C(1);
        D_1F800004_b89->pc += 5;
        return;
    }
    if (func_800BDC54() == -1) {
        D_800E6480 = 1;
        D_1F800004_b89->pc--;
        return;
    }
    a = func_800B5C1C(1);
    D_8007257C = 1;
    if (func_8001BF48(a, 0, 0, func_800B5C1C(3)) == 0) {
        D_800E6470++;
        D_1F800004_b89->pc += 5;
        return;
    }
    D_800E6480 = 1;
    D_1F800004_b89->pc--;
}

typedef struct { u8 p[0x228]; s32 pc; } C_b8a;
extern C_b8a *D_1F800004_b8a asm("D_1F800004");
extern u8 D_800E546C;
extern s32 D_80076688;
extern u8 D_800E60C8;
extern s32 D_800E5614;
extern s32 D_8007257C;
extern s32 D_800E6470;
extern s32 D_800E6480;
s32 func_8001B788(s32);
s32 func_8001BF6C(s32, s32, s32);
void func_800B8A30(void) {
    s32 a;
    if (D_800E546C != 0) {
        D_80076688 = 0x7F;
        D_800E60C8 = 1;
        D_800E5614 = func_800B5C1C(1);
        D_1F800004_b8a->pc += 3;
        return;
    }
    if (func_800BDC54() != -1) {
        a = func_800B5C1C(1);
        if (a != 0xFF) {
            s32 r = func_8001B788(a);
            if (r == 1) {
                D_8007257C = r;
            }
        }
        if (func_8001BF6C(a, 0, 0) == 0) {
            D_800E6470++;
            D_1F800004_b8a->pc += 3;
            return;
        }
    }
    D_800E6480 = 1;
}

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

s32 func_80025114(s32);
void func_800B8C38(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    s32 a = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7], 0x40);
    s32 b = func_800B5C54(5, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7], 0x20);
    func_800B5B98(v, (func_80025114(a) * b) >> 12);
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

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

void func_800B8D94(void) {
    u8 *c = D_1F800004;
    switch (D_800E14B8[*(s32 *)(c + 0x228) + 1]) {
    case 0:
        *(s32 *)(c + 0x38) |= 0x200;
        break;
    case 1:
        *(s32 *)(c + 0x38) &= ~0x200;
        break;
    case 2:
        *(s32 *)(c + 0x38) |= 0x1200;
        break;
    case 3:
        *(s32 *)(c + 0x38) &= ~0x1200;
        break;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800B8E4C);

extern s16 *D_800E39E4;
void func_800B5B98(s32, s32);
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

void func_800B9384(void) {
    s32 v = func_800B5C1C(1);
    s32 i = 0;
    u8 *c = D_1F800004;
    s32 *t = D_8007E6C0;
    for (; i < 3; i++, t++) {
        if (v == *t) {
            *(s32 *)(c + 0x228) += 5;
            return;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
}

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

void func_800B9890(void) {
    s32 v = func_800B5C1C(3);
    s32 i;
    for (i = 0; i < 3; i++) {
        if (v == D_8007E6C0[i]) {
            func_800B5B98(func_800B5BEC(1), i);
            *(s32 *)(D_1F800004 + 0x228) += 5;
            return;
        }
    }
    func_800B5B98(func_800B5BEC(1), -1);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_80032D78(s32);
void func_80029F58(s32);
void func_800B9940(void) {
    s32 pc = *(s32 *)(D_1F800004 + 0x228);
    s32 key;
    s32 r;
    key = D_800E14B8[pc + 1];
    key |= D_800E14B8[pc + 2] << 8;
    key |= D_800E14B8[pc + 3] << 16;
    key |= D_800E14B8[pc + 4] << 24;
    if (key == 0x30303030) {
        func_80032D78(0);
        func_80029F58(0);
    } else {
        r = func_80041F0C(0x10, key);
        if (r != 0) {
            func_80029F58(r);
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800B99EC(void) {
    s32 pc = *(s32 *)(D_1F800004 + 0x228);
    s32 key;
    key = D_800E14B8[pc + 1];
    key |= D_800E14B8[pc + 2] << 8;
    key |= D_800E14B8[pc + 3] << 16;
    key |= D_800E14B8[pc + 4] << 24;
    if (func_80041F0C(0x10, key) != 0) {
        func_8002A228(key);
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_8003B594(s32);
void func_800B9A84(void) {
    s32 pc = *(s32 *)(D_1F800004 + 0x228);
    s32 key;
    s32 v;
    key = D_800E14B8[pc + 1];
    key |= D_800E14B8[pc + 2] << 8;
    key |= D_800E14B8[pc + 3] << 16;
    key |= D_800E14B8[pc + 4] << 24;
    v = func_80041F0C(10, key);
    if (v != 0) {
        func_8003B594(v);
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

typedef struct { u8 p[0xD8]; s32 fD8; u8 q[0x278 - 0xDC]; } A_b9b;
extern A_b9b *D_800E257C_b9b asm("D_800E257C");
typedef struct { u8 p[0x14]; s32 x; s32 y; s32 z; } M_b9b;
typedef struct { u8 p[0x228]; s32 pc; } C_b9b;
extern C_b9b *D_1F800004_b9b asm("D_1F800004");
s32 func_800C6BA4(s32);
s32 func_80041F0C(s32, s32);
void func_80097854(s32, s32, s16 **, M_b9b **);
void func_8003B550(s32, s32);
void func_8003B594(s32);
void func_800B9B10(void) {
    s16 *v;
    M_b9b *m;
    s32 n = func_800C6BA4(5);
    if (n != 0xFF) {
        s32 pc = D_1F800004_b9b->pc;
        s32 key;
        s32 r;
        key = D_800E14B8[pc + 1];
        key |= D_800E14B8[pc + 2] << 8;
        key |= D_800E14B8[pc + 3] << 16;
        key |= D_800E14B8[pc + 4] << 24;
        r = func_80041F0C(10, key);
        if (r != 0) {
            func_80097854(D_800E257C_b9b[n].fD8, func_800B5C1C(6), &v, &m);
            m->x += v[0];
            m->y += v[1];
            m->z += v[2];
            func_8003B550(r, (s32)m);
            func_8003B594(r);
        }
    }
    D_1F800004_b9b->pc += 8;
}

typedef struct { u8 p[0xB4]; s32 fB4; } M_b9c;
typedef struct { u8 p[0xD8]; M_b9c *fD8; u8 q[0x278 - 0xDC]; } A_b9c;
extern A_b9c *D_800E257C_b9c asm("D_800E257C");
void func_8003B550(s32, s32);
void func_8003B594(s32);
void func_800B9C44(void) {
    s32 i = func_800C6BA4(5);
    s32 v;
    s32 key;
    if (i != 0xFF) {
        s32 pc = *(s32 *)(D_1F800004 + 0x228);
        key = D_800E14B8[pc + 1];
        key |= D_800E14B8[pc + 2] << 8;
        key |= D_800E14B8[pc + 3] << 16;
        key |= D_800E14B8[pc + 4] << 24;
        v = func_80041F0C(10, key);
        if (v != 0) {
            func_8003B550(v, D_800E257C_b9c[i].fD8->fB4 + 0x24);
            func_8003B594(v);
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

s32 func_8004208C(s32, s32, s32);
void func_8003B8C8(s32);
s32 func_80041F6C(s32);
void func_8003BEC4(s32, s32);
void func_8003B610(s32);
void func_800B9D28(s32 flag) {
    s32 pc = *(s32 *)(D_1F800004 + 0x228);
    s32 key;
    s32 v;
    key = D_800E14B8[pc + 1];
    key |= D_800E14B8[pc + 2] << 8;
    key |= D_800E14B8[pc + 3] << 16;
    key |= D_800E14B8[pc + 4] << 24;
    v = 0;
    if (key == 0x30303030) {
        while ((v = func_8004208C(v, 10, 0)) != 0) {
            func_8003B8C8(v);
            func_8003BEC4(func_80041F6C(v), 1);
        }
    } else {
        v = func_80041F0C(10, key);
        if (v != 0) {
            if (flag == 0) {
                func_8003B610(v);
            } else {
                func_8003B8C8(v);
            }
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

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

extern s32 D_800E6474;
extern s32 D_800724F0[];
extern s32 D_8007E6C0[];
void func_800B9EEC(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_800724F0[i] == D_800E6474) {
            if (D_8007E6C0[i] == func_800B5C1C(1)) {
                *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
            } else {
                *(s32 *)(D_1F800004 + 0x228) += 5;
            }
            return;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

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

s32 func_80027684(s32, s32);
void func_800BA0E4(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    s32 a = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7], 0x40);
    s32 b = func_800B5C54(5, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7], 0x20);
    func_800B5B98(v, (s16)func_80027684(a, b));
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

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

void func_800BA334(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x *= func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA3C8(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    s32 d = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    if (d == 0) {
        d = 1;
    }
    x /= d;
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA468(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x ^= func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA4F8(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x |= func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA588(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x &= func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

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

void func_800BA6D8(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x &= ~(1 << func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40));
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA774(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x |= 1 << func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA80C(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x -= func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800BA89C(void) {
    s32 x = func_800B5B34(func_800B5BEC(1));
    x += func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    func_800B5B98(func_800B5BEC(1), x);
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

void func_800B5B98(s32, s32);
void func_800BA92C(void) {
    func_800B5B98(func_800B5BEC(1), 0);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BA974(void) {
    func_800B5B98(func_800B5BEC(1), 1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800BA9BC(void) {
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40));
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

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

typedef struct { u8 p[0xFA]; u16 hFA; u8 q[0x228 - 0xFC]; s32 pc; u8 s[0x270 - 0x22C]; u32 f270; } C_bab;
extern C_bab *D_1F800004_bab asm("D_1F800004");
extern u8 D_800E546C;
void func_800BABD4(void) {
    s32 a = func_800B5C1C(2);
    C_bab *c;
    if (a >= 0x800) {
        a -= 2;
    }
    c = D_1F800004_bab;
    if (D_800E14B8[c->pc + 1] == 0) {
        c->hFA = ((c->hFA + a) & 0xFFF) | 0x8000;
    } else {
        c->hFA = ((c->hFA - a) & 0xFFF) | 0x8000;
    }
    if (D_800E546C == 0) {
        D_1F800004_bab->f270 |= 0x4000;
    }
    D_1F800004_bab->pc += 4;
}

void func_800BAC9C(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x270) |= 0x20000000;
        *(u32 *)(c + 0x38) &= ~0x20;
    } else {
        *(u32 *)(c + 0x38) |= 0x20;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

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

void func_800BB038(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
        func_800AD3C0(func_800B5C1C(2));
    } else {
        func_800AD420(func_800B5C1C(2));
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

typedef struct { s16 x, y, w, h; } R_bb0;
typedef struct { s16 x, y; } V_bb0;
extern u8 D_8006B3F4;
extern s32 D_800E39F0_bb0[] asm("D_800E39F0");
void func_800BB0C0(void) {
    P800B5C98 v;
    R_bb0 r;
    if (D_8006B3F4 != 0) {
        D_800E39F0_bb0[0] = func_800B5C1C(1);
        D_800E39F0_bb0[1] = func_800B5C1C(3);
        D_800E39F0_bb0[2] = func_800B5C1C(5);
        D_800E39F0_bb0[3] = func_800B5C1C(7);
        r.x = D_800E39F0_bb0[0];
        r.y = D_800E39F0_bb0[1];
        r.w = D_800E39F0_bb0[2];
        r.h = D_800E39F0_bb0[3];
        func_80029C3C(&r);
        v.a = D_800E39F0_bb0[0];
        v.b = D_800E39F0_bb0[1];
        func_80029C10(v);
    }
    *(s32 *)(D_1F800004 + 0x228) += 9;
}

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

typedef struct { u8 p[0x2718]; s16 h[0x180]; u8 b[1]; } S8006EBC8_BB58C;
extern S8006EBC8_BB58C D_8006EBC8_bb asm("D_8006EBC8");
s32 func_800BB294(s32);
void func_800BB58C(s32 id, s32 n) {
    if (id != -1) {
        s32 i = func_800BB294(id);
        if (i != -1) {
            D_8006EBC8_bb.h[i] = id;
            if ((u8)(D_8006EBC8_bb.b[i] += n) >= 100) {
                D_8006EBC8_bb.b[i] = 99;
            }
        }
    }
}

void func_800BB58C(s32, s32);
void func_800BB3EC(s32, s32, s32);
void func_800CFD44(s32, s32);
void func_800BB614(s32 arg0) {
    if (arg0 < 0x200) {
        func_800BB58C(arg0, 1);
    } else if (arg0 < 0x400) {
        if (arg0 >= 0x261 && arg0 < 0x26C) {
            func_800BB3EC(arg0 - 0x200, 5, 0);
        } else {
            func_800BB3EC(arg0 - 0x200, 1, 0);
        }
    } else if (arg0 < 0x440) {
        func_800CFD44(arg0 - 0x400, 1);
    }
}

typedef struct { u8 p[0x2718]; u16 a[0x180]; u8 b[0x180]; u16 c[0xC0]; u8 d[0xC0]; } S_bb6;
extern S_bb6 D_8006EBC8_bb6 asm("D_8006EBC8");
s32 func_800BB4CC(s32);
void func_800CFD44(s32, s32);
void func_800BB690(s32 a) {
    s32 i;
    if (a < 0x200) {
        i = func_800BB4CC(a);
        if (i != -1) {
            if (D_8006EBC8_bb6.b[i] == 1) {
                D_8006EBC8_bb6.a[i] = 0;
                D_8006EBC8_bb6.b[i] = 0;
            } else {
                D_8006EBC8_bb6.b[i]--;
            }
        }
    } else if (a < 0x400) {
        i = func_800BB4CC(a);
        if (i != -1) {
            i -= 0x200;
            if (D_8006EBC8_bb6.d[i] == 1) {
                D_8006EBC8_bb6.c[i] = 0;
                D_8006EBC8_bb6.d[i] = 0;
            } else {
                D_8006EBC8_bb6.d[i]--;
            }
        }
    } else if (a < 0x440) {
        func_800CFD44(a - 0x400, 0);
    }
}

extern s32 D_800719A8;
void func_800BB768(void) {
    u8 *c = D_1F800004;
    s32 pc = *(s32 *)(c + 0x228);
    s32 key;
    key = D_800E14B8[pc + 1];
    key += D_800E14B8[pc + 2] << 8;
    key += D_800E14B8[pc + 3] << 16;
    key += D_800E14B8[pc + 4] << 24;
    if (D_800719A8 >= key) {
        *(s32 *)(c + 0x228) = pc + 7;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(5);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BB7F8);

void func_800BB690(s32);
void func_800BB8A0(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
        func_800BB614(func_800B5C1C(2));
    } else {
        func_800BB690(func_800B5C1C(2));
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

extern u8 D_8006EBC8_bb9[] asm("D_8006EBC8");
s32 func_800BB4CC(s32);
s32 func_800CFD04(s32);
void func_800BB928(void) {
    s32 r = 0;
    s32 a = func_800B5C1C(3);
    s32 i;
    if (a < 0x200) {
        i = func_800BB4CC(a);
        if (i != -1) {
            r = D_8006EBC8_bb9[i + 0x2A18];
        }
    } else if (a < 0x400) {
        i = func_800BB4CC(a);
        if (i != -1) {
            r = D_8006EBC8_bb9[i + 0x2B18];
        }
    } else if (a < 0x440) {
        if (func_800CFD04(a - 0x401)) {
            r = 1;
        }
    }
    func_800B5B98(func_800B5BEC(1), r);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

s32 func_800BB230(s32);
void func_800BBA0C(void) {
    if (func_800BB230(func_800B5C1C(1)) == 0) {
        *(s32 *)(D_1F800004 + 0x228) += 5;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(3);
    }
}

typedef struct { u8 p[0x38]; u32 f38; u8 q[0x278 - 0x3C]; } S800E257Ce;
void func_800BBA68(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF && !(((S800E257Ce *)D_800E257C)[v].f38 & 0x8000)) {
        *(s32 *)(D_1F800004 + 0x228) += 4;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(2);
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BBAF4);

void func_800BBE10(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(s32 *)(c + 0xB4) = 0;
        *(s32 *)(c + 0x228) += 2;
    } else {
        *(s32 *)(c + 0xB4) += 0x4000;
        *(s16 *)(c + 0x110) += *(s32 *)(c + 0xB4) >> 16;
        if (*(s16 *)(c + 0x110) > 0) {
            *(s16 *)(c + 0x110) = 0;
            *(s32 *)(c + 0x228) += 2;
        }
    }
}

void func_800BBE88(void) {
    *(s16 *)(D_1F800004 + 0x110) = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

typedef struct { s16 a; s16 b; } P_bbe;
extern P_bbe *D_800E55C8_bbe asm("D_800E55C8");
extern s16 D_800E25A6;
void func_800BBEE4(void) {
    s32 a = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x80);
    s32 b = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x40);
    s32 i = func_800B5C1C(6);
    if (i < D_800E25A6) {
        D_800E55C8_bbe[i].a = a;
        D_800E55C8_bbe[i].b = b;
    }
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

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

typedef struct { u8 p[0x10C]; s16 h10C; u8 q[0x24E - 0x10E]; s16 h24E; u8 r[0x278 - 0x250]; } S800E257Cb;
void func_800BC034(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        ((S800E257Cb *)D_800E257C)[v].h24E = func_800B5C1C(2);
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800BC0B0(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x24E) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0x38]; u32 f38; u8 q[0x274 - 0x3C]; u32 f274; } S800E257Cj;
void func_800BC0EC(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF && !(((S800E257Cj *)D_800E257C)[v].f38 & 0x4000) && !((((S800E257Cj *)D_800E257C)[v].f274 >> 8) & 1)) {
        D_800E6480 = 1;
    } else {
        *(s32 *)(D_1F800004 + 0x228) += 2;
    }
}

typedef struct { u8 p[0x124]; s16 h124; } M_bc1;
typedef struct { u8 p[0x38]; s32 f38; u8 q[0xD8 - 0x3C]; M_bc1 *fD8; u8 r[0xF4 - 0xDC]; s16 hF4; s16 hF6; u8 s[0x228 - 0xF8]; s32 pc; u8 t[0x274 - 0x22C]; u32 f274; } C_bc1;
extern C_bc1 *D_1F800004_bc1 asm("D_1F800004");
extern s16 D_800E41D6;
extern s32 D_800E6470;
extern s32 D_800E6480;
void func_800BC190(void) {
    s32 v;
    C_bc1 *c;
    if (D_800E41D6 != 0) {
        D_800E6480 = 1;
        return;
    }
    v = func_800B5C1C(1);
    if (v == 0xFF) {
        D_1F800004_bc1->hF6 = -1;
    } else {
        D_1F800004_bc1->hF4 = v;
    }
    c = D_1F800004_bc1;
    if (!(c->f38 & 0x4000)) {
        s32 n = D_800E6470;
        c->fD8->h124 = 0;
        D_800E6470 = n + 1;
        c->f274 &= ~0x100;
    }
    D_1F800004_bc1->pc += 3;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BC254);

typedef struct { u8 p[0x23C]; u8 b23C; u8 b23D; u8 b23E; u8 q[0x278 - 0x23F]; } A_bc3;
typedef struct { u8 p[0x74]; A_bc3 *a; } S_bc3;
extern S_bc3 D_800E2508_bc3 asm("D_800E2508");
void func_800BC39C(void) {
    s32 i = func_800C6BA4(1);
    if (i != 0xFF) {
        D_800E2508_bc3.a[i].b23C = func_800B5C1C(2);
        D_800E2508_bc3.a[i].b23D = func_800B5C1C(4);
        D_800E2508_bc3.a[i].b23E = func_800B5C1C(6);
    }
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

extern s32 D_800E6470;
extern u8 D_8006EBC1;
void func_800BC458(void) {
    D_800E6470 += 0x40;
    if (D_8006EBC1 < 2) {
        u8 *c = D_1F800004;
        *(u32 *)(c + 0x38) |= 0x30;
        *(s32 *)(c + 0x228) += 4;
        func_800B59EC(*(s16 *)(c + 0x250));
    } else {
        *(s32 *)(D_1F800004 + 0x228) += 1;
    }
}

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

void func_800BCA6C(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        ((S800E257Cb *)D_800E257C)[v].h10C = func_800B5C1C(2) << 4;
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800BCAEC(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        ((S800E257Cb *)D_800E257C)[v].h10C = func_800B5C1C(2);
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

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

void func_800BCC74(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] != 1) {
        s32 v = func_800B5C1C(7);
        u8 *c = D_1F800004;
        s32 o = *(s32 *)(c + 0x22C) * 20;
        *(s16 *)(c + o + 0x122) = v;
    }
    func_800C3994(0xB);
}

void func_800C3E08(s32);
void func_800BCCF0(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x122) = -1;
    func_800C3E08(3);
}

void func_800BCD38(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] != 1) {
        s32 v = func_800B5C1C(3);
        u8 *c = D_1F800004;
        s32 o = *(s32 *)(c + 0x22C) * 20;
        *(s16 *)(c + o + 0x122) = v;
    }
    func_800C3E08(5);
}

void func_800BCEF4(s32);
void func_800BCDB4(void) {
    u8 *c = D_1F800004;
    u8 *p = c + *(s32 *)(c + 0x22C) * 20;
    *(s16 *)(p + 0x122) = -1;
    func_800BCEF4(3);
}

void func_800BCDFC(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] != 1) {
        s32 v = func_800B5C1C(3);
        u8 *c = D_1F800004;
        s32 o = *(s32 *)(c + 0x22C) * 20;
        *(s16 *)(c + o + 0x122) = v;
    }
    func_800BCEF4(5);
}

void func_800BCE78(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] != 1) {
        s32 v = func_800B5C1C(9);
        u8 *c = D_1F800004;
        s32 o = *(s32 *)(c + 0x22C) * 20;
        *(s16 *)(c + o + 0x122) = v;
    }
    func_800BD30C(0xB);
}

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

s32 func_800BD8AC(void);
void func_800BD9F0(void) {
    s16 f = func_800BD8D0() == -1;
    if (func_800BD8AC() == -1) {
        f |= 2;
    }
    if (func_800BD88C() == -1) {
        f |= 4;
    }
    if (func_800BD950() == -1) {
        f |= 8;
    }
    if (func_800BD910() == -1) {
        f |= 0x10;
    }
    if (func_800BD930() == -1) {
        f |= 0x20;
    }
    func_800B5B98(0x4E, f);
}

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

typedef struct { u8 p[0x6CC]; u32 f6CC; } S_bdc;
extern S_bdc D_800E3A50_bdc asm("D_800E3A50");
extern s32 D_8007E6E8;
extern u8 D_800E39E8;
extern u8 D_800E3A19;
extern s32 D_800E6480;
s32 func_800BDC54(void);
void func_800BDCFC(void) {
    u8 *c;
    s32 v;
    *(u32 *)(D_1F800004 + 0x270) |= 1;
    D_800E3A50_bdc.f6CC |= 2;
    if (func_800BDC54() == -1) {
        D_800E6480 = 1;
        return;
    }
    func_800B5B98(8, D_8007E6E8);
    D_800E39E8 = 1;
    D_8007E6E8 = func_800B5C1C(1);
    v = func_800B5C1C(3);
    c = D_1F800004;
    {
        s32 pc = *(s32 *)(c + 0x228);
        D_800E3A19 = v;
        *(s32 *)(c + 0x228) = pc + 5;
    }
}

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

typedef struct { s16 x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5; } T_be0;
typedef struct { u8 p[0x3E]; s16 f3E; u8 q[6]; s16 f46; u8 r[0x278 - 0x48]; } A_be0;
extern A_be0 *D_800E257C_be0 asm("D_800E257C");
typedef struct { u8 p[0x228]; s32 pc; } C_be0;
extern C_be0 *D_1F800004_be0 asm("D_1F800004");
extern T_be0 *D_800E14BC_t asm("D_800E14BC");
extern s16 D_800E3C6C;
extern s32 D_800E14CC;
extern s32 D_800E6470;
s32 func_800BDDE0(s32, s32, s32, s32, s32);
void func_800BE0BC(void) {
    s32 k = D_800E14B8[D_1F800004_be0->pc + 1];
    if (func_800BDDE0((D_800E14BC_t[k].x1 << 16) + D_800E14BC_t[k].x0,
                      (D_800E14BC_t[k].y2 << 16) + D_800E14BC_t[k].y1,
                      (D_800E14BC_t[k].x4 << 16) + D_800E14BC_t[k].x3,
                      (D_800E14BC_t[k].y5 << 16) + D_800E14BC_t[k].y4,
                      (D_800E257C_be0[D_800E3C6C].f46 << 16) + D_800E257C_be0[D_800E3C6C].f3E) == 0) {
        D_800E14CC = k;
        D_1F800004_be0->pc += 4;
        return;
    }
    D_1F800004_be0->pc = func_800B5BEC(2);
    D_800E6470++;
}

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

typedef struct { u8 p[0x3E]; s16 h3E; u8 q[2]; s16 h42; u8 r[2]; s16 h46; u8 s[0x278 - 0x48]; } A_be4;
extern A_be4 *D_800E257C_be4 asm("D_800E257C");
void func_800BE448(void) {
    s32 i = func_800C6BA4(3);
    s32 j = func_800C6BA4(4);
    s32 x0 = D_800E257C_be4[i].h3E;
    s32 z0 = D_800E257C_be4[i].h46;
    s32 y0 = D_800E257C_be4[i].h42;
    s32 x1 = D_800E257C_be4[j].h3E;
    s32 z1 = D_800E257C_be4[j].h46;
    s32 y1 = D_800E257C_be4[j].h42;
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, func_800AF46C(x1 - x0, y1 - y0, z1 - z0));
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

typedef struct { u8 p[0x3E]; s16 h3E; u8 q[6]; s16 h46; u8 s[0x278 - 0x48]; } A_be5;
extern A_be5 *D_800E257C_be5 asm("D_800E257C");
s32 func_800AF4B4(s32, s32);
void func_800BE534(void) {
    s32 a = func_800C6BA4(3);
    s32 b = func_800C6BA4(4);
    s32 ax = D_800E257C_be5[a].h3E;
    s32 az = D_800E257C_be5[a].h46;
    s32 bx = D_800E257C_be5[b].h3E;
    s32 bz = D_800E257C_be5[b].h46;
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, func_800AF4B4(bx - ax, bz - az));
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BE604);

s32 func_800AF4B4(s32, s32);
void func_800BE770(void) {
    s32 a = func_800B5C54(3, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 0xB], 0x40);
    s32 b = func_800B5C54(5, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 0xB], 0x20);
    s32 c = func_800B5C54(7, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 0xB], 0x10);
    s32 d = func_800B5C54(9, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 0xB], 0x8);
    s32 v = func_800B5BEC(1) & 0xFFFF;
    func_800B5B98(v, func_800AF4B4(c - a, d - b));
    *(s32 *)(D_1F800004 + 0x228) += 0xC;
}

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

void func_800BEDD8(void) {
    s32 a = func_800B5B34(func_800B5BEC(1));
    s32 b = func_800B5B34(func_800B5BEC(3));
    func_800B5B98(func_800B5BEC(3), a);
    func_800B5B98(func_800B5BEC(1), b);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800B5B98(s32, s32);
void func_800BEE68(void) {
    u16 v = func_800B5BEC(1) + func_800B5C1C(5);
    func_800B5B98(func_800B5BEC(3), D_800E14B8[v]);
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

void func_800BEEDC(void) {
    u16 off = func_800B5BEC(1) + func_800B5C1C(5);
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 7] == 0) {
        func_800B5B98(func_800B5BEC(3), D_800E14B8[off] | (D_800E14B8[off + 1] << 8));
    } else {
        func_800B5B98(func_800B5BEC(3), (s16)(D_800E14B8[off] + (D_800E14B8[off + 1] << 8)));
    }
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

void func_800BEFC0(void) {
    u32 v = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    u32 idx = v >> 4;
    s32 bit = 1 << (v & 0xF);
    func_800B5B98(idx, func_800B5B34(idx) | bit);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800BF050(void) {
    u32 v = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    u32 idx = v >> 4;
    s32 bit = 1 << (v & 0xF);
    func_800B5B98(idx, func_800B5B34(idx) & ~bit);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800BF0E4(void) {
    u32 v = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    s32 bit = 1 << (v & 0xF);
    if (func_800B5B34(v >> 4) & bit) {
        *(s32 *)(D_1F800004 + 0x228) += 6;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(4);
    }
}

void func_800BF178(void) {
    s32 a = func_800B5C1C(9);
    s32 b = func_800B5C1C(3) & 0xFF;
    s32 c = func_800B5C1C(5) & 0xFF;
    s32 d = func_800B5C1C(7) & 0xFF;
    func_800AD2C0(1, a, b, c, d, func_800B5C1C(1));
    *(s32 *)(D_1F800004 + 0x228) += 0xB;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF21C);

typedef struct { u8 p[0x27C]; s16 a[1]; } S800E3A50_27C;
extern S800E3A50_27C D_800E3A50_27C asm("D_800E3A50");
void func_800BF2C0(void) {
    s32 v = func_800B5C54(2, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 4], 0x80);
    u8 *c = D_1F800004;
    D_800E3A50_27C.a[D_800E14B8[*(s32 *)(c + 0x228) + 1]] = v;
    *(s32 *)(c + 0x228) += 5;
}

extern s32 D_800E3CB4;
void func_800BF344(void) {
    D_800E3CB4 = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

extern u8 (*D_800E256C)[4];
s32 func_800BF3A4(s32 a, s32 b) {
    switch (b) {
    case 0:
        return D_800E256C[a][0];
    case 1:
        return D_800E256C[a][1];
    case 2:
        return D_800E256C[a][2];
    case 3:
        return D_800E256C[a][3];
    }
    return 0;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800BF458);

void func_800BF458(u8, u8, s32);
void func_800BF520(void) {
    s32 v = func_800B5C1C(3);
    func_800BF458(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2], v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

s32 func_800BF3A4(s32, s32);
void func_800BF458(u8, u8, s32);
void func_800BF588(void) {
    s32 v = func_800BF3A4(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2]);
    v |= func_800B5C1C(3);
    func_800BF458(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2], v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

s32 func_800BF3A4(s32, s32);
void func_800BF628(void) {
    s32 v = func_800BF3A4(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2]);
    func_800B5B98(func_800B5BEC(3), v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800BF6A8(void) {
    s32 v = func_800BF3A4(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2]);
    v &= func_800B5C1C(3);
    func_800BF458(D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1], D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 2], v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

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

typedef struct { u8 p[0x2D]; u8 b2D; u8 q[0xCC - 0x2E]; } S8006EBC8_cc;
extern S8006EBC8_cc D_8006EBC8_cc[] asm("D_8006EBC8");
void func_800BFA44(void) {
    s32 i = func_800BAA90(func_800B5C1C(1));
    s32 v = 0;
    if (i != 0xFF) {
        v = D_8006EBC8_cc[i].b2D;
    }
    func_800B5B98(func_800B5BEC(3), v);
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

extern u8 D_800E5464;
extern s32 D_800E6480;
extern s32 D_8007E6C0[];
void func_800BF798(s32, s32);
void func_800BFAD4(void) {
    s32 a;
    s32 slot;
    if (func_800BDC54() != -1 && D_800E5464 == 0) {
        func_80044EE0(0);
        a = func_800B5C1C(1);
        if (a < 0x2C) {
            func_800B950C(a);
            if (func_800BF748(a, &slot) == 0) {
                D_800E5464 = 1;
                D_8007E6C0[slot] = a;
                func_800BF798(a, slot);
                *(s32 *)(D_1F800004 + 0x228) += 3;
                return;
            }
        }
        *(s32 *)(D_1F800004 + 0x228) += 4;
    } else {
        D_800E6480 = 1;
    }
}

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

typedef struct { u8 p[0x38]; u32 f38; u8 q[0x278 - 0x3C]; } S800E257Cd;
void func_800AFBD0(s32, s32);
void func_800C0E84(s32 arg0) {
    if (D_800724F0[arg0] != 0xFF) {
        func_800AFBD0(D_800724F0[arg0], 1);
        ((S800E257Cd *)D_800E257C)[D_800724F0[arg0]].f38 |= 0x10;
        D_800724F0[arg0] = 0xFF;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C0F08);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1160);

typedef struct { u8 p[0xC]; u8 c; u8 q; } R14_c14;
typedef struct { u8 p[0x80]; s32 f80; u8 q[0x278 - 0x84]; } A278_c14;
typedef struct { u8 p[0x5C]; R14_c14 *r; u8 q[0x74 - 0x60]; A278_c14 *a; } S2508_c14;
extern S2508_c14 D_800E2508_c14 asm("D_800E2508");
void func_800C14A8(void) {
    s32 i = func_800C6BA4(1);
    if (i != 0xFF && func_800B5C1C(2) == D_800E2508_c14.r[D_800E2508_c14.a[i].f80].c) {
        *(s32 *)(D_1F800004 + 0x228) += 6;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(4);
    }
}

typedef struct { u8 p[0x3E]; s16 h3E; u8 q[2]; s16 h42; u8 r[2]; s16 h46; u8 s[0x278 - 0x48]; } A_c15;
extern A_c15 *D_800E257C_c15 asm("D_800E257C");
typedef struct { u8 p[0x3E]; s16 h3E; u8 q[2]; s16 h42; u8 r[2]; s16 h46; u8 s[0x228 - 0x48]; s32 pc; } C_c15;
extern C_c15 *D_1F800004_c15 asm("D_1F800004");
s32 func_800AF46C(s32, s32, s32);
void func_800C1560(void) {
    s32 i = func_800C6BA4(1);
    if (i != 0xFF) {
        A_c15 *a = &D_800E257C_c15[i];
        C_c15 *c = D_1F800004_c15;
        s32 d = func_800AF46C(c->h3E - a->h3E, c->h42 - a->h42, c->h46 - a->h46);
        if (d < func_800B5C1C(2)) {
            D_1F800004_c15->pc += 6;
            return;
        }
    }
    D_1F800004_c15->pc = func_800B5BEC(4);
}

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

typedef struct { u8 p[0x10E]; s16 h10E; u8 q[0x278 - 0x110]; } S800E257Cf;
void func_800C1D88(void) {
    s32 v = func_800C6BA4(4);
    if (v != 0xFF) {
        ((S800E257Cf *)D_800E257C)[v].h10E = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

void func_800C1E20(void) {
    *(s16 *)(D_1F800004 + 0x10E) = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 3], 0x80);
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

extern s16 D_800E3C72;
void func_800C1E7C(void) {
    D_800E3C72 = func_800B5C1C(1);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C1EBC(void) {
    *(s16 *)(D_1F800004 + 0xD0) = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0xD2) = func_800B5C1C(3);
    *(s16 *)(D_1F800004 + 0xD4) = func_800B5C1C(5);
    *(s16 *)(D_1F800004 + 0xD6) = func_800B5C1C(7);
    *(s32 *)(D_1F800004 + 0xCC) = func_800B5C1C(9);
    *(s32 *)(D_1F800004 + 0x228) += 0xB;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C1F3C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C21E4);

extern u8 D_8006B3F9;
void func_8002FE30(const char *, ...);
void func_800C2400(void) {
    s32 v = func_800B5B34(func_800B5BEC(1));
    if (D_8006B3F9 == 0) {
        func_8002FE30("DEBUG=%xh %d \n", v, v);
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

extern s32 D_800E4908;
void func_800B5B98(s32, s32);
void func_800C2468(void) {
    func_800B5B98(func_800B5BEC(1), D_800E4908);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C24B4(void) {
    u16 v = func_800B5BEC(1);
    func_800B5B98(v, *(u16 *)(D_1F800004 + 0xFA) & 0xFFF);
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0xFA]; u16 hFA; u16 hFC; u8 q[0x278 - 0xFE]; } S800E257Cg;
void func_800C250C(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        func_800B5B98(func_800B5BEC(2), ((S800E257Cg *)D_800E257C)[v].hFA & 0xFFF);
    } else {
        func_800B5B98(func_800B5BEC(2), 0);
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

typedef struct { u8 p[0x3E]; s16 h3E; u8 q[2]; s16 h42; u8 r[2]; s16 h46; u8 s[0x278 - 0x48]; } A_c25;
typedef struct { u8 p[0x74]; A_c25 *a; } S_c25;
extern S_c25 D_800E2508_c25 asm("D_800E2508");
void func_800C25AC(void) {
    s32 i = func_800C6BA4(1);
    if (i != 0xFF) {
        func_800B5B98(func_800B5BEC(2), D_800E2508_c25.a[i].h3E);
        func_800B5B98(func_800B5BEC(4), D_800E2508_c25.a[i].h46);
        func_800B5B98(func_800B5BEC(6), D_800E2508_c25.a[i].h42);
    } else {
        func_800B5B98(func_800B5BEC(2), 0);
        func_800B5B98(func_800B5BEC(4), 0);
        func_800B5B98(func_800B5BEC(6), 0);
    }
    *(s32 *)(D_1F800004 + 0x228) += 8;
}

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

typedef struct { u8 p[0x38]; u32 f38; u8 q[0x270 - 0x3C]; u32 f270; u8 r[4]; } A_c44;
typedef struct { u8 p[0x74]; A_c44 *a; } S_c44;
extern S_c44 D_800E2508_c44 asm("D_800E2508");
extern A_c44 *D_800E257C_c44 asm("D_800E257C");
void func_800C4438(void) {
    s32 i = func_800C6BA4(2);
    if (i != 0xFF) {
        if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
            D_800E2508_c44.a[i].f38 &= ~0x20;
            D_800E2508_c44.a[i].f270 |= 0x20000000;
        } else {
            D_800E257C_c44[i].f38 |= 0x20;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0x270]; u32 f270; u8 q[4]; } A_c45;
extern A_c45 *D_800E257C_c45 asm("D_800E257C");
typedef struct { u8 p[0x38]; u32 f38; u8 q[0x228 - 0x3C]; s32 pc; u8 r[0x266 - 0x22C]; s16 h266; s16 h268; u8 s[0x270 - 0x26A]; u32 f270; } C_c45;
extern C_c45 *D_1F800004_c45 asm("D_1F800004");
void func_800C452C(void) {
    s32 i;
    if (D_800E14B8[D_1F800004_c45->pc + 1] == 0) {
        D_1F800004_c45->h266 = 0;
        D_1F800004_c45->f38 &= ~0x800000;
    } else {
        i = func_800C6BA4(1);
        if (i != 0xFF) {
            D_800E257C_c45[i].f270 |= 0x200;
            D_1F800004_c45->h266 = i;
            D_1F800004_c45->f270 |= 0x200;
            D_1F800004_c45->h268 = func_800B5C1C(2);
            D_1F800004_c45->f38 |= 0x800000;
        }
    }
    D_1F800004_c45->pc += 4;
}

typedef struct { u8 p[0x3C]; s32 f3C; u8 q[4]; s32 f44; u8 r[0xFA - 0x48]; u16 hFA; u8 s[0x270 - 0xFC]; u32 f270; u8 t[4]; } A_c46;
typedef struct { u8 p[0x74]; A_c46 *a; } S_c46;
extern S_c46 D_800E2508_c46 asm("D_800E2508");
extern u8 D_800E546C;
void func_800C461C(void) {
    s32 i = func_800C6BA4(1);
    s32 j = func_800C6BA4(2);
    if (i != 0xFF) {
        D_800E2508_c46.a[i].hFA = (-func_80027684((D_800E2508_c46.a[j].f44 - D_800E2508_c46.a[i].f44) >> 16, (D_800E2508_c46.a[j].f3C - D_800E2508_c46.a[i].f3C) >> 16) & 0xFFF) | 0x8000;
        if (D_800E546C == 0) {
            D_800E2508_c46.a[i].f270 |= 0x4000;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0xFA]; u16 hFA; u8 q[0x270 - 0xFC]; u32 f270; u8 r[4]; } A800C471C;
typedef struct { u8 p[0x74]; A800C471C *a; } S800E2508_h;
extern S800E2508_h D_800E2508_h asm("D_800E2508");
void func_800C471C(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        D_800E2508_h.a[v].hFA = (func_800B5C1C(2) & 0xFFF) | 0x8000;
        if (D_800E546C == 0) {
            D_800E2508_h.a[v].f270 |= 0x4000;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

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

s32 func_800CF4DC(s32);
void func_800CF390(s32);
void DrawSync(s32);
void func_800C4A44(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        s32 s = func_800CF4DC(v);
        if (s != -1) {
            DrawSync(0);
            func_800CF390(s);
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u8 p[0x3C]; s32 f3C; u8 q[4]; s32 f44; u8 r[0x278 - 0x48]; } A_c4a;
extern A_c4a *D_800E257C_c4a asm("D_800E257C");
typedef struct { u8 p[0x3C]; s32 f3C; u8 q[4]; s32 f44; u8 r[0xFA - 0x48]; u16 hFA; u8 s[0x228 - 0xFC]; s32 pc; u8 t[0x270 - 0x22C]; u32 f270; } C_c4a;
extern C_c4a *D_1F800004_c4a asm("D_1F800004");
extern u8 D_800E546C;
s32 func_80027684(s32, s32);
void func_800C4ABC(void) {
    s32 i = func_800C6BA4(1);
    if (i != 0xFF) {
        D_1F800004_c4a->hFA = (-func_80027684((D_800E257C_c4a[i].f44 - D_1F800004_c4a->f44) >> 16, (D_800E257C_c4a[i].f3C - D_1F800004_c4a->f3C) >> 16) & 0xFFF) | 0x8000;
        if (D_800E546C == 0) {
            D_1F800004_c4a->f270 |= 0x4000;
        }
    }
    D_1F800004_c4a->pc += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4B84);

typedef struct { u8 p[0x270]; u32 f270; u8 r[4]; } A800C4C50;
typedef struct { u8 p[0x70]; s32 n; A800C4C50 *a; } S800E2508_i;
extern S800E2508_i D_800E2508_i asm("D_800E2508");
void func_800C4C50(void) {
    u8 *c = D_1F800004;
    s32 i;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x270) &= ~1;
    } else {
        for (i = 0; i < D_800E2508_i.n; i++) {
            D_800E2508_i.a[i].f270 &= ~1;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4D00);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4D48);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C4F4C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C5198);

s32 rand(void);
void func_800C533C(void) {
    *(s16 *)(D_1F800004 + 0x238) = (rand() & 0x3FF) + 0x200;
}

typedef struct { u8 p[0x14]; u8 b14; u8 q[3]; u8 b18; u8 b19; } S8007E9E8;
extern S8007E9E8 D_8007E9E8;
void func_800C5370(void) {
    s32 r = 0;
    if (D_8007E9E8.b14 == 1) {
        if ((u32)(D_8007E9E8.b19 - 0x4C) >= 0x69 || D_8007E9E8.b18 < 0x4C || D_8007E9E8.b18 >= 0xB5) {
            r = 1;
        }
    }
    if (r) {
        *(s32 *)(D_1F800004 + 0x228) += 3;
    } else {
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(1);
    }
}

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

typedef struct { u8 p[0x218]; s32 r[4]; } C800C68E0;
void func_800C68E0(void) {
    C800C68E0 *c = (C800C68E0 *)D_1F800004;
    if (((u8 *)c)[0x26F] != 4) {
        c->r[((u8 *)c)[0x26F]] = *(s32 *)((u8 *)c + 0x228) + 3;
        *(s32 *)(D_1F800004 + 0x228) = func_800B5BEC(1);
        D_1F800004[0x26F]++;
    } else {
        D_800E6480 = 1;
    }
}

void func_800C6958(void) {
    C800C65BC *c = D_1F800004_d;
    u8 n = ((u8 *)c)[0x26F];
    if (n == 0) {
        D_800E6478 = 1;
        c->s[c->idx].a = 0xF;
        D_800E6480 = 1;
        c->s[c->idx].b = 0xFF;
    } else {
        C800C68E0 *d;
        ((u8 *)c)[0x26F] = n - 1;
        d = (C800C68E0 *)D_1F800004_d;
        *(s32 *)((u8 *)d + 0x228) = d->r[((u8 *)d)[0x26F]];
    }
}

typedef struct { s32 f0; s16 h4; s16 h6; s16 h8; s16 hA; s16 hC; s16 hE; s16 h10; s16 h12; } SL_c69;
typedef struct { u8 p[0x118]; SL_c69 s[8]; u8 q[0x22C - 0x1B8]; s32 idx; } C_c69;
extern C_c69 *D_1F800004_c69 asm("D_1F800004");
extern s32 D_800E6474;
extern s32 D_800E6480;
s32 func_800B5AD0(s32, s32);
void func_800C69EC(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_1F800004_c69->s[i].h4 == 7) {
            s32 v = func_800B5AD0(D_800E6474, 1);
            C_c69 *c = D_1F800004_c69;
            c->s[i].f0 = v;
            c->s[i].h4 = 0xF;
            c->s[i].hA = -1;
            c->s[i].f0 = 0xFFFF;
            c->s[i].h8 = 0;
            c->s[i].h10 = 0;
            c->s[i].hC = 0;
            c->s[i].hE = 0;
            c->s[i].h6 = 0xFF;
        }
    }
    D_1F800004_c69->s[D_1F800004_c69->idx].h4 = 0xF;
    D_800E6480 = 1;
    D_1F800004_c69->s[D_1F800004_c69->idx].h6 = 0xFF;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C6AEC);

extern s32 D_800724F0[];
extern s32 D_800724F4;
extern s32 D_800724F8;
extern s32 D_800E6474;
s32 func_800BAA38(s32);
s32 func_800C6BA4(s32 n) {
    s32 v = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + n];
    if (v == 0xFF) {
        v = D_800724F0[0];
    } else if (v == 0xFE) {
        v = D_800724F4;
    } else if (v == 0xFD) {
        v = D_800724F8;
    } else {
        if (v == 0xFB) {
            v = D_800E6474;
        }
        if (v >= 0x80) {
            v = func_800BAA38(v - 0x80);
            if (v == -1) {
                v = 0xFF;
            } else {
                v = D_800724F0[v];
            }
        }
    }
    return v;
}

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

typedef struct {
    u8 p[0x546]; u8 f546; u8 f547;
    u32 b0 : 1; u32 bf : 9; u32 b10 : 3; u32 b13 : 1; u32 b14 : 2; u32 b16 : 1; u32 b17 : 15;
} O_c76;
extern O_c76 *D_800E4190_c76[] asm("D_800E4190");
typedef struct { u8 p[0x228]; s32 pc; } C_c76;
extern C_c76 *D_1F800004_c76 asm("D_1F800004");
extern s32 D_800E6474;
extern s32 D_800E640C;
extern s32 D_800E6410;
extern s32 D_800E6480;
s32 func_800CF53C(s32);
s32 func_800CF4DC(s32);
void func_800C76C4(void) {
    if (func_800CF53C(D_800E6474) == 0) {
        s32 i = func_800CF4DC(D_800E6474);
        D_800E4190_c76[i]->b13 = 0;
        D_800E4190_c76[i]->bf = D_800E4190_c76[i]->f546 = D_800E14B8[D_1F800004_c76->pc + 1] >> 4;
        D_800E4190_c76[i]->f547 = D_800E14B8[D_1F800004_c76->pc + 1] & 0xF;
        D_800E4190_c76[i]->b16 = 1;
        D_800E640C = D_800E14B8[D_1F800004_c76->pc + 1] >> 4;
        D_800E6410 = D_800E14B8[D_1F800004_c76->pc + 1] & 0xF;
    }
    D_1F800004_c76->pc += 2;
    D_800E6480 = 1;
}

s32 func_800C7D18_i(s32, s32) asm("func_800C7D18");
void func_800C77F8(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        *(s32 *)(D_1F800004 + 0x228) += 1;
        if (func_800C7D18_i(v, 1) == -1) {
            *(s32 *)(D_1F800004 + 0x228) -= 1;
        }
        D_800E6480 = 1;
    } else {
        *(s32 *)(D_1F800004 + 0x228) += 8;
    }
}

void func_800C7898(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        *(s32 *)(D_1F800004 + 0x228) += 1;
        if (func_800C7D18_i(v, 1) == -1) {
            *(s32 *)(D_1F800004 + 0x228) -= 1;
        }
        D_800E6480 = 1;
    } else {
        *(s32 *)(D_1F800004 + 0x228) += 6;
    }
}

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

typedef struct { u8 p[0x6CC]; u32 b0 : 1; u32 b1 : 1; u32 rest : 30; } S800E3A50_b1;
extern S800E3A50_b1 D_800E3A50_b1 asm("D_800E3A50");
typedef struct { u8 p[0x38]; u32 f38; u8 q[0x270 - 0x3C]; u32 b0 : 1; u32 rest : 31; u8 r[0x278 - 0x274]; } A800C8478;
typedef struct { u8 p[0x70]; s32 n; A800C8478 *a; } S800E2508_c;
extern S800E2508_c D_800E2508_c asm("D_800E2508");
void func_800C8478(void) {
    s32 i;
    D_800E3A50_b1.b1 = 0;
    for (i = 0; i < D_800E2508_c.n; i++) {
        if (!(D_800E2508_c.a[i].f38 & 0x10)) {
            D_800E3A50_b1.b1 |= D_800E2508_c.a[i].b0;
        }
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C850C);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800C882C);

void func_800C8E54(void) {
    u8 *c = D_1F800004;
    if (D_800E14B8[*(s32 *)(c + 0x228) + 1] == 0) {
        *(u32 *)(c + 0x270) |= 0x20000100;
    } else {
        D_800E3A50_f.b7 = 1;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

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

typedef struct { u8 p[0x228]; s32 pc; u8 q[0x240 - 0x22C]; u16 h240; u8 r[0x24E - 0x242]; u16 h24E; u8 s[0x270 - 0x250]; u32 lo : 13; u32 b13 : 1; u32 b14 : 1; u32 b15 : 1; u32 hi : 16; } C800C9564;
extern C800C9564 *D_1F800004_e asm("D_1F800004");
void func_800C9564(void) {
    C800C9564 *c = D_1F800004_e;
    c->b13 = D_800E14B8[c->pc + 1];
    if (!c->b13) {
        if (c->b15 == 1) {
            c->h24E = c->h240;
        }
        D_1F800004_e->b15 = 0;
        D_1F800004_e->b14 = 0;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct {
    u8 p[0x240]; u16 f240; u8 q[0x24E - 0x242]; u16 f24E; u8 r[0x270 - 0x250];
    u32 b0 : 13; u32 b13 : 1; u32 b14 : 1; u32 b15 : 1; u32 b16 : 16; s32 f274;
} A_c96;
typedef struct { u8 p[0x74]; A_c96 *a; } G_c96;
extern G_c96 D_800E2508_c96 asm("D_800E2508");
typedef struct { u8 p[0x228]; s32 pc; } C_c96;
extern C_c96 *D_1F800004_c96 asm("D_1F800004");
s32 func_800C6BA4(s32);
void func_800C9608(void) {
    s32 n = func_800C6BA4(2);
    if (n != 0xFF) {
        G_c96 *g = &D_800E2508_c96;
        g->a[n].b13 = D_800E14B8[D_1F800004_c96->pc + 1] & 1;
        if (!g->a[n].b13) {
            if (g->a[n].b15 == 1) {
                g->a[n].f24E = g->a[n].f240;
            }
            g->a[n].b15 = 0;
            g->a[n].b14 = 0;
        }
    }
    D_1F800004_c96->pc += 3;
}

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

typedef struct { s16 a; s16 b; } S800E6428b;
extern S800E6428b D_800E6428_b[] asm("D_800E6428");
typedef struct { u8 p[0xD8]; s32 fD8; u8 q[0x278 - 0xDC]; } A800C978C;
typedef struct { u8 p[0x74]; A800C978C *a; } S800E2508_d;
extern S800E2508_d D_800E2508_d asm("D_800E2508");
void func_80095C28(s32, s32, s32, s32);
void func_800C978C(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_800E6428_b[i].a != -1) {
            func_80095C28(D_800E2508_d.a[D_800E6428_b[i].a].fD8, 0, 0x100, D_800E6428_b[i].b + 0xF5);
            D_800E6428_b[i].a = -1;
        }
    }
}

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

typedef struct { u8 p[0x6C]; s32 f6C; s32 f70; s32 f74; u8 q[0x278 - 0x78]; } A800C9C0C;
typedef struct { u8 p[0x70]; s32 n; A800C9C0C *a; } S800E2508_e;
extern S800E2508_e D_800E2508_e asm("D_800E2508");
void func_800C9C0C(void) {
    s32 v = func_800B5C1C(1);
    s32 i;
    for (i = 0; i < D_800E2508_e.n; i++) {
        D_800E2508_e.a[i].f6C = v;
        D_800E2508_e.a[i].f70 = v;
        D_800E2508_e.a[i].f74 = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

void func_800C9CB0(void) {
    u8 *c = D_1F800004;
    if ((*(u32 *)(c + 0x7C) & 0xC000) || ((*(u16 *)(c + 0xFC) + 0x400) & 0xFFF) == (*(u16 *)(c + 0xFA) & 0xFFF)) {
        (*(s32 *)(c + 0x228))++;
    }
    D_800E6480 = 1;
}

typedef struct { u8 p[0x7C]; u32 f7C; u8 q[0xFA - 0x80]; u16 hFA; u16 hFC; u8 r[0x278 - 0xFE]; } S800E257Ch;
void func_800C9D0C(void) {
    s32 v = func_800C6BA4(1);
    if (v == 0xFF || (((S800E257Ch *)D_800E257C)[v].f7C & 0xC000) ||
        ((((S800E257Ch *)D_800E257C)[v].hFC + 0x400) & 0xFFF) == (((S800E257Ch *)D_800E257C)[v].hFA & 0xFFF)) {
        *(s32 *)(D_1F800004 + 0x228) += 2;
    }
    D_800E6480 = 1;
}

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

extern s16 D_800E4110;
extern s16 D_800E4112;
extern s16 D_800E4118;
void func_800CA328(void) {
    switch (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1]) {
    case 0x10:
        D_800E4118 = func_800B5C1C(2);
        break;
    case 0x11:
        D_800E4110 = func_800B5C1C(2);
        break;
    case 0x12:
        D_800E4112 = func_800B5C1C(2);
        break;
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

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

extern s32 D_800E6480;
extern u8 D_800E5799;
extern s32 D_8007E7A4;
extern s32 D_80072518;
s32 func_800BDC54(void);
typedef struct { u8 p[0x228]; s32 pc; } C_ca5;
extern C_ca5 *D_1F800004_ca5 asm("D_1F800004");
void func_800CA534(void) {
    if (func_800BDC54() == -1) {
        C_ca5 *c = D_1F800004_ca5;
        s32 pc = c->pc;
        D_800E6480 = 1;
        c->pc = pc - 1;
        return;
    }
    func_80044EE0(0);
    D_800E5799 = 1;
    func_800B5B98(0x44, D_8007E7A4 = func_800B5C1C(1));
    func_8004582C(5);
    func_80045F14(D_8007E7A4 + 0x725, D_80072518 = func_8003D8F4(func_80044924(D_8007E7A4 + 0x725), 1, 2), 0);
    D_1F800004_ca5->pc += 3;
}

s32 func_80044EE0_i(s32) asm("func_80044EE0");
extern s32 D_80072518;
extern u8 D_800E5799;
void func_800CF088(void);
void func_800CA60C(void) {
    if (func_80044EE0_i(1) != 0) {
        D_800E6480 = 1;
        D_1F800004_c->pc--;
    } else {
        func_80044EE0(0);
        func_800A54D4(D_80072518, 0x380, 0, 0x100, 0xFD);
        func_8003D504(D_80072518);
        func_800CF088();
        D_800E5799 = 0;
        D_1F800004_c->pc++;
    }
}

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

typedef struct { s16 a; s16 b; s16 c; s16 d; } S80072530e;
extern S80072530e D_80072530_e[] asm("D_80072530");
void func_8004A714(s32, s32, s32, s32);
void func_800CA81C(void) {
    s32 ch = func_800B5C1C(1);
    s32 a;
    D_80072530_e[ch].c = func_800B5C1C(5);
    a = func_800B5C1C(3);
    func_8004A714(0, 1 << (ch + 8), a, func_800B5C1C(5));
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

void func_8004A800(s32, s32, s32, s32);
void func_800CA8B4(void) {
    s32 ch = func_800B5C1C(1);
    s32 a;
    D_80072530_e[ch].d = func_800B5C1C(5);
    a = func_800B5C1C(3);
    func_8004A800(0, 1 << (ch + 8), a, func_800B5C1C(5));
    *(s32 *)(D_1F800004 + 0x228) += 7;
}

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

typedef struct { u8 p[0xB8]; s16 hB8; u8 q[0xCC - 0xBA]; } S8006EBC8_cf;
extern S8006EBC8_cf D_8006EBC8_cf[] asm("D_8006EBC8");
void func_800CC594(void) {
    s32 i = func_800BAA90(func_800B5C1C(3));
    if (i != 0xFF) {
        func_800B5B98(func_800B5BEC(1), D_8006EBC8_cf[i].hB8);
    } else {
        func_800B5B98(func_800B5BEC(1), 0);
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

typedef struct { u8 p[0x16]; s16 h16; u8 q[0xB8 - 0x18]; s16 hB8; u8 r[0xCC - 0xBA]; } P_cc5;
extern P_cc5 D_8006EBC8_cc5[] asm("D_8006EBC8");
void func_800CC638(void) {
    s32 m = func_800BAA90(func_800B5C1C(3));
    if (m != 0xFF) {
        s32 v = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x80);
        if (v <= 0) {
            v = 1;
        }
        if (D_8006EBC8_cc5[m].h16 < v) {
            v = D_8006EBC8_cc5[m].h16;
        }
        D_8006EBC8_cc5[m].hB8 = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

typedef struct { u8 p[0x16]; s16 h16; u8 q[0xB8 - 0x18]; s16 hB8; u8 r[0xCC - 0xBA]; } P_cc6;
extern P_cc6 D_8006EBC8_cc6[] asm("D_8006EBC8");
void func_800CC6FC(void) {
    s32 m = func_800BAA90(func_800B5C1C(3));
    if (m != 0xFF) {
        s32 v = func_800B5C54(1, D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 5], 0x80) + D_8006EBC8_cc6[m].hB8;
        if (D_8006EBC8_cc6[m].h16 < v) {
            v = D_8006EBC8_cc6[m].h16;
        }
        D_8006EBC8_cc6[m].hB8 = v;
    }
    *(s32 *)(D_1F800004 + 0x228) += 6;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CC7B8);

typedef struct { u8 p[0xA8]; s32 fA8; s32 fAC; s32 fB0; u8 q[0xCC - 0xB4]; } S8006EBC8_cd;
extern S8006EBC8_cd D_8006EBC8_cd[] asm("D_8006EBC8");
void func_800CC8DC(void) {
    s32 i = func_800BAA90(func_800B5C1C(3));
    if (i != 0xFF) {
        func_800B5B98(func_800B5BEC(1), (D_8006EBC8_cd[i].fA8 | D_8006EBC8_cd[i].fB0) & 0xFF);
    }
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

typedef struct { u8 p[0x274]; u32 lo : 10; u32 b : 1; u32 hi : 21; } S800E257Ci;
void func_800CC974(void) {
    s32 v = func_800C6BA4(2);
    if (v != 0xFF) {
        ((S800E257Ci *)D_800E257C)[v].b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

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

typedef struct { u8 p[0x258]; s16 h258; u8 r[0x278 - 0x25A]; } S800E257Cc;
void func_800CCA80(void) {
    s32 v = func_800C6BA4(1);
    if (v != 0xFF) {
        ((S800E257Cc *)D_800E257C)[v].h258 = func_800B5C1C(2);
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800CCAFC(void) {
    s16 v = func_800B5C1C(1);
    *(s16 *)(D_1F800004 + 0x258) = v;
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0x2344]; u16 a; u8 q[0x2352 - 0x2346]; u16 b; } S_ccb;
extern S_ccb D_8006EBC8_ccb asm("D_8006EBC8");
extern s16 D_800E57A0_ccb[] asm("D_800E57A0");
extern u8 D_8006B47A;
extern s32 D_8007E6E8;
void func_80019FE4(void);
void func_800221E0(void);
void func_8001B5A0(void);
void func_800CCB38(void) {
    u16 s = D_800E57A0_ccb[0x1A];
    s32 i;
    s32 v;
    func_80019FE4();
    func_800221E0();
    D_8007E6E8 = 8;
    func_800B5B98(6, 8);
    func_8001B5A0();
    for (i = 0x1E7; i >= 0; i--) {
        D_800E57A0_ccb[i] = 0;
    }
    for (i = 0; i < 0x200; i++) {
        D_800E57A0_ccb[i + 0x200] = 0;
    }
    D_800E57A0_ccb[0x1A] = s;
    D_8006EBC8_ccb.a = s;
    v = D_8006B47A - 1;
    D_800E57A0_ccb[0x21] = v;
    D_8006EBC8_ccb.b = v;
    *(s32 *)(D_1F800004 + 0x228) += 1;
}

typedef struct { u8 p[0x238E]; u16 h238E; u8 q[0x2714 - 0x2390]; u32 f2714; u8 r[0x37C4 - 0x2718]; s16 h37C4; } S8006EBC8_q;
extern S8006EBC8_q D_8006EBC8_q asm("D_8006EBC8");
void func_8001A06C(void);
void func_8001B53C(void);
void func_800CCC18(void) {
    if (D_8006EBC8_q.h238E == 0) {
        func_8001A06C();
        func_8001B53C();
        D_8006EBC8_q.h37C4 = 0x203;
    } else {
        func_8001B53C();
        D_8006EBC8_q.f2714 |= 0x30000000;
    }
    *(s32 *)(D_1F800004 + 0x228) += 1;
}

typedef struct { u8 p[0x270]; u32 lo : 24; u32 b : 1; u32 hi : 7; u8 q[0x278 - 0x274]; } A800CCC9C;
typedef struct { u8 p[0x74]; A800CCC9C *a; } S800E2508_g;
extern S800E2508_g D_800E2508_g asm("D_800E2508");
void func_800CCC9C(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_800724F0[i] != 0xFF) {
            D_800E2508_g.a[D_800724F0[i]].b = D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1];
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

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

void func_800CCF78(s32 arg0, s32 arg1, s32 arg2) {
    if (!(arg0 & 1)) {
        D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] = arg2 | (D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] & 0xF0);
    } else {
        D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] = (D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] & 0xF) | (arg2 << 4);
    }
}

s32 func_800CD004(s32 arg0, s32 arg1) {
    if (!(arg0 & 1)) {
        return D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] & 0xF;
    }
    return D_8006EBC8_h.t[(arg0 >> 1) + arg1 * 22] >> 4;
}

typedef struct { u8 p[0x40]; u16 h40[0x30]; u8 q[0xCC - 0xA0]; } P_cd0;
extern P_cd0 D_8006EBC8_cd0[] asm("D_8006EBC8");
s32 func_800CD004(s32, s32);
void func_800CD074(s32 m) {
    s32 i;
    for (i = 0; i < 0x30; i++) {
        if ((D_8006EBC8_cd0[m].h40[i] & 0x1FF) < 0x80) {
            u8 x = func_800CD004(i, m);
            func_800BB3EC(D_8006EBC8_cd0[m].h40[i] & 0x1FF, x, 1);
            D_8006EBC8_cd0[m].h40[i] &= 0xC000;
            func_800CCF78(i, m, 0);
        }
    }
}

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

typedef struct { u8 p[0x28]; s16 h28; s16 h2A; s16 h2C; u8 q[0x228 - 0x2E]; s32 pc; } C800CD498;
extern C800CD498 *D_1F800004_f asm("D_1F800004");
void func_800CD498(void) {
    D_1F800004_f->h28 = func_800B5C54(1, D_800E14B8[D_1F800004_f->pc + 7], 0x80);
    D_1F800004_f->h2A = func_800B5C54(5, D_800E14B8[D_1F800004_f->pc + 7], 0x20);
    D_1F800004_f->h2C = func_800B5C54(3, D_800E14B8[D_1F800004_f->pc + 7], 0x40);
    D_1F800004_f->pc += 8;
}

typedef struct { u8 p[0x30]; s16 h30; s16 h32; s16 h34; u8 q[0x228 - 0x36]; s32 pc; } C800CD544;
extern C800CD544 *D_1F800004_g asm("D_1F800004");
void func_800CD544(void) {
    D_1F800004_g->h30 = func_800B5C54(1, D_800E14B8[D_1F800004_g->pc + 7], 0x80);
    D_1F800004_g->h32 = func_800B5C54(5, D_800E14B8[D_1F800004_g->pc + 7], 0x20);
    D_1F800004_g->h34 = func_800B5C54(3, D_800E14B8[D_1F800004_g->pc + 7], 0x40);
    D_1F800004_g->pc += 8;
}

typedef struct { u8 p[0xD8]; s32 fD8; u8 q[0x278 - 0xDC]; } A_cd5;
extern A_cd5 *D_800E257C_cd5 asm("D_800E257C");
void func_8009789C(s32, s32, s32 *);
void func_800CD5F0(void) {
    s32 out[3];
    s32 i = func_800C6BA4(1);
    if (i != 0xFF) {
        func_8009789C(D_800E257C_cd5[i].fD8, func_800B5C1C(2), out);
        func_800B5B98(func_800B5BEC(4), out[0]);
        func_800B5B98(func_800B5BEC(6), out[2]);
        func_800B5B98(func_800B5BEC(8), out[1]);
    } else {
        func_800B5B98(func_800B5BEC(4), 0);
        func_800B5B98(func_800B5BEC(6), 0);
        func_800B5B98(func_800B5BEC(8), 0);
    }
    *(s32 *)(D_1F800004 + 0x228) += 10;
}

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

extern s32 D_8007E6C0[];
void func_800CD908(void) {
    s32 a = func_800B5C1C(1);
    s32 i;
    s32 t;
    for (i = 0; i < 3; i++) {
        if (D_8007E6C0[i] == a) {
            break;
        }
    }
    if ((u32)(i - 1) < 2) {
        func_800C08F4(i);
        func_800C08F4(0);
        func_800C0A78(i, 0);
        func_800C08AC(0);
        func_800C08AC(i);
        t = D_8007E6C0[0];
        D_8007E6C0[0] = D_8007E6C0[i];
        D_8007E6C0[i] = t;
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

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

typedef struct { s32 w[0x37D0 / 4]; } B8006EBC8;
extern B8006EBC8 D_8006EBC8_blk asm("D_8006EBC8");
extern u8 D_800E39E1;
extern B8006EBC8 *D_800E4184;
B8006EBC8 *func_8003CD38(s32, s32);
void func_800A8A30(s32);
void func_800CE030(void) {
    if (func_800CDC78() == 0) {
        B8006EBC8 *p;
        u8 *c;
        s32 t;
        D_800E39E1 = 1;
        p = func_8003CD38(0x37D0, 0);
        D_800E4184 = p;
        *p = D_8006EBC8_blk;
        func_800A8A30(3);
        c = D_1F800004;
        t = *(s32 *)(c + 0x228);
        D_800E41D2 = 1;
        *(s32 *)(c + 0x228) = t + 1;
    }
}

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

void func_800CE1C8(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
        func_800B9614(func_800B5C1C(2));
    } else {
        func_800B9654(func_800B5C1C(2));
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

void func_800CE250(void) {
    if (D_800E14B8[*(s32 *)(D_1F800004 + 0x228) + 1] == 0) {
        func_800B9590(func_800B5C1C(2));
    } else {
        func_800B95D0(func_800B5C1C(2));
    }
    *(s32 *)(D_1F800004 + 0x228) += 4;
}

typedef struct { u8 p[0x228]; s32 pc; } C_ce2;
extern C_ce2 *D_1F800004_ce2 asm("D_1F800004");
extern u8 D_800E61F0, D_800E3A00, D_800E41D3, D_800E41D9, D_800E5049, D_800E39E0, D_800E3A1A, D_800E5460, D_800E41A4, D_800E41D2;
extern s32 D_800E6480;
void func_800CE2D8(void) {
    if (D_800E61F0 == 0 && D_800E3A00 == 0 && D_800E41D3 == 0 && D_800E41D9 == 0 && D_800E5049 == 0 &&
        D_800E39E0 == 0 && D_800E3A1A == 0 && D_800E5460 == 0 && D_800E41A4 == 0 && D_800E41D2 == 0) {
        D_1F800004_ce2->pc += 1;
    } else {
        D_800E6480 = 1;
        D_1F800004_ce2->pc -= 1;
    }
}

typedef struct { u8 p[0x21C]; s16 h21C; } S800E3A50_21Cb;
extern S800E3A50_21Cb D_800E3A50_21Cb asm("D_800E3A50");
void func_800B569C(s32, s32);
void func_800CE3DC(void) {
    s32 i;
    if (D_800724F0[0] != 0xFF) {
        for (i = 0; i < 0x80; i++) {
            func_800B569C(D_800E3A50_21Cb.h21C, 0);
        }
    }
    if (D_800724F0[1] != 0xFF) {
        for (i = 0; i < 0x80; i++) {
            func_800B569C(D_800724F0[1], 1);
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 1;
}

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

typedef struct { u8 p[0x24]; u16 h24[3]; u8 q[0xCC - 0x2A]; } S8006EBC8_ce4;
extern S8006EBC8_ce4 D_8006EBC8_ce4[] asm("D_8006EBC8");
void func_800CD074(s32);
void func_800CE4BC(void) {
    s32 m = func_800B5C1C(1);
    s32 i;
    func_800CD074(m);
    for (i = 0; i < 3; i++) {
        if (D_8006EBC8_ce4[m].h24[i] != 0) {
            func_800BB614(D_8006EBC8_ce4[m].h24[i]);
            D_8006EBC8_ce4[m].h24[i] = 0;
        }
    }
    *(s32 *)(D_1F800004 + 0x228) += 3;
}

typedef struct { u8 p[0x20]; u16 h20; u8 q[0xCC - 0x22]; } S8006EBC8_ce;
extern S8006EBC8_ce D_8006EBC8_ce[] asm("D_8006EBC8");
void func_800CE570(void) {
    s32 v = func_800B5C1C(3);
    func_800BB58C(D_8006EBC8_ce[func_800B5C1C(1)].h20, 1);
    D_8006EBC8_ce[func_800B5C1C(1)].h20 = v;
    *(s32 *)(D_1F800004 + 0x228) += 5;
}

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

extern u8 D_800E491A;
void func_800CE7D4(void) {
    u8 *c = D_1F800004;
    s32 pc = *(s32 *)(c + 0x228);
    D_800E6480 = 1;
    if (D_800E14B8[pc + 1] == 0) {
        D_800E491A = 1;
        func_800B5B98(0x42, func_800B5C1C(2));
        *(s32 *)(D_1F800004 + 0x228) += 4;
    } else {
        *(s32 *)(c + 0x228) = D_800E491A ? pc - 1 : pc + 2;
    }
}

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

extern u8 D_800724E5;
void func_800CEA1C(void) {
    if (func_800BDC54() == -1) {
        D_1F800004_c->pc--;
    } else {
        u8 *c;
        s32 t;
        D_800724E5 = func_800B5C1C(1);
        c = D_1F800004;
        t = *(s32 *)(c + 0x228);
        D_800E3A00 = 1;
        *(s32 *)(c + 0x228) = t + 3;
    }
    D_800E6480 = 1;
}

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

typedef struct { u8 p[0x228]; s32 pc; u8 q[0x270 - 0x22C]; u32 f270; u8 b274; } C800CEBA8;
extern C800CEBA8 *D_1F800004_h asm("D_1F800004");
void func_800CEBA8(void) {
    u8 *c = D_1F800004;
    switch (D_800E14B8[*(s32 *)(c + 0x228) + 1]) {
    case 0:
        *(u32 *)(c + 0x270) &= ~0x40000000;
        break;
    case 1:
        *(u32 *)(c + 0x270) |= 0x40000000;
        break;
    default:
        D_1F800004_h->f270 |= 0x40000000;
        D_1F800004_h->b274 = D_800E14B8[D_1F800004_h->pc + 1];
        break;
    }
    *(s32 *)(D_1F800004 + 0x228) += 2;
}

typedef struct { u8 p[0x2F98]; u8 b[6]; } S8006EBC8_2F98;
extern S8006EBC8_2F98 D_8006EBC8_2F98 asm("D_8006EBC8");
extern u8 D_800E16B0[];
void func_800CEC5C(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_8006EBC8_2F98.b[i] != D_800E16B0[i]) {
            D_1F800004_c->pc++;
            return;
        }
    }
    D_8006EBC8_2F98.b[4] = 100;
    D_8006EBC8_2F98.b[5] = 0;
    *(s32 *)(D_1F800004 + 0x228) += 1;
}

extern void (*D_800E16B8[])(void);
void func_800CECE4(void) {
    s32 pc = ++*(s32 *)(D_1F800004 + 0x228);
    D_800E16B8[D_800E14B8[pc]]();
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CED44);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800CEE8C);

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; s16 x2, y2; u8 u2, v2; u16 pad1; s16 x3, y3; u8 u3, v3; u16 pad2; } PFT4_cef;
extern PFT4_cef D_800E6510_cef[] asm("D_800E6510");
void func_800CEFC4(s32 x, s32 y, u32 *ot, s32 n, s32 col, s32 row) {
    PFT4_cef *p = &D_800E6510_cef[n + row];
    p->x0 = x;
    p->y0 = y;
    p->x1 = x + 16;
    p->y1 = y;
    p->x2 = x;
    p->y2 = y + 16;
    p->x3 = x + 16;
    p->y3 = y + 16;
    p->u0 = col * 16 + row * 32;
    p->v0 = 0x50;
    p->u1 = col * 16 + 16 + row * 32;
    p->v1 = 0x50;
    p->u2 = col * 16 + row * 32;
    p->v2 = 0x60;
    p->u3 = col * 16 + 16 + row * 32;
    p->v3 = 0x60;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
}

u8 *func_8003D8F4(s32, s32, s32);
void func_800D6C58(s32 x, s32 y, s32 w, s32 h, void *p);
void func_800D6C94(s32 x, s32 y, s32 w, s32 h, void *p);
void func_800CF088(void) {
    u16 *buf = (u16 *)func_8003D8F4(0x200, 0, 2);
    s32 i;
    func_800D6C58(0x100, 0xFD, 0x100, 1, buf);
    for (i = 0; i < 0x100; i++) {
        if (buf[i] != 0) {
            buf[i] = 0xFFFF;
        }
    }
    func_800D6C94(0x100, 0xFE, 0x100, 1, buf);
    func_8003D504((s32)buf);
}

typedef struct { u8 p[0xE]; u16 clut; u8 q[0x28 - 0x10]; } S800E6510;
extern S800E6510 D_800E6510[];
u16 GetClut(s32, s32);
void func_800CF120(s32 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_800E6510[i].clut = GetClut(arg0, arg1);
    }
}

typedef struct { u32 tag; u8 r0, g0, b0, code; s16 x0, y0; u8 u0, v0; u16 clut; s16 x1, y1; u8 u1, v1; u16 tpage; u8 rest[0x28 - 0x18]; } P_cf1;
extern P_cf1 D_800E6510_cf1[] asm("D_800E6510");
extern u8 D_800E3A04[];
extern u8 D_800E4188_cf1[] asm("D_800E4188");
extern u8 D_800E39B0_cf1[] asm("D_800E39B0");
extern u8 D_800E4178_cf1[] asm("D_800E4178");
extern s32 D_800E64EC_cf1 asm("D_800E64EC");
void func_800CF088(void);
void func_800CF188(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        D_800E3A04[i] = 0;
        D_800E4188_cf1[i] = 0;
        D_800E39B0_cf1[i] = 0;
        D_800E4178_cf1[i] = 0;
    }
    func_800CF088();
    for (i = 0; i < 4; i++) {
        func_80011574(&D_800E6510_cf1[i]);
        D_800E6510_cf1[i].r0 = 0x80;
        D_800E6510_cf1[i].g0 = 0x80;
        D_800E6510_cf1[i].b0 = 0x80;
        D_800E6510_cf1[i].clut = GetClut(0x100, 0xFD);
        D_800E6510_cf1[i].tpage = GetTPage(1, 0, 0x380, 0x50);
    }
    D_800E64EC_cf1 = 0;
}

typedef struct { u8 p[0x548]; u32 lo : 23; u32 b : 1; u32 hi : 8; } A800CF26C;
s32 func_800CF26C(void) {
    s32 r = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_800E3A04[i] != 0) {
            r = 1;
            if (((A800CF26C *)D_800E4190[i])->b == 1) {
                return r;
            }
        }
    }
    if (r == 1) {
        return 0;
    }
    return -1;
}

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

typedef struct { u8 p[0x28]; s32 f28; s32 f2C; u8 q[0x498 - 0x30]; s32 f498; } O_cf3;
extern O_cf3 *D_800E4190_cf3[] asm("D_800E4190");
extern u8 D_800E3A04_cf3[] asm("D_800E3A04");
extern u8 D_800E4188_cf3[] asm("D_800E4188");
extern u8 D_800E39B0_cf3[] asm("D_800E39B0");
extern u8 D_800E4178_cf3[] asm("D_800E4178");
void func_800CF390(s32 i) {
    func_8003D504(D_800E4190_cf3[i]->f498);
    func_8003D504(D_800E4190_cf3[i]->f28);
    func_8003D504(D_800E4190_cf3[i]->f2C);
    func_8003D504((s32)D_800E4190_cf3[i]);
    D_800E3A04_cf3[i] = 0;
    D_800E4188_cf3[i] = 0;
    D_800E39B0_cf3[i] = 0;
    D_800E4178_cf3[i] = 0;
}

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

void func_800CF664(s32 v, u8 *out) {
    s32 a, b, c, d;
    out[0] = 0;
    if (v < 0) {
        v = -v;
    }
    a = v / 10000;
    v -= a * 10000;
    b = v / 1000;
    v -= b * 1000;
    c = v / 100;
    v -= c * 100;
    d = v / 10;
    v -= d * 10;
    out[6] = 0;
    out[1] = a;
    out[2] = b;
    out[3] = c;
    out[4] = d;
    out[5] = v;
}

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

void func_800D1164(u8 *p, s32 x, s32 y, s32 w, s32 h) {
    s32 dx = *(s16 *)(p + 0x20) - *(s16 *)(p + 8);
    s32 dy = *(s16 *)(p + 0x22) - *(s16 *)(p + 0xA);
    if (dx < 0) {
        x--;
        if (x < 0) {
            x = 0;
            w--;
        }
    }
    if (dy < 0) {
        y--;
        if (y < 0) {
            y = 0;
            h--;
        }
    }
    if (x + w >= 0x100) {
        w--;
    }
    if (x + h >= 0x100) {
        h--;
    }
    p[0xC] = x;
    p[0xD] = y;
    p[0x14] = x + w;
    p[0x15] = y;
    p[0x1C] = x;
    p[0x1D] = y + h;
    p[0x24] = x + w;
    p[0x25] = y + h;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D1208);

typedef struct { s16 x, y, w, h; } R_d48;
void func_800D489C(R_d48 *a, R_d48 *b) {
    if (a->x >= b->x + b->w) {
        a->x = b->x;
        a->y = b->y;
        a->w = 0;
        a->h = 0;
        return;
    }
    if (a->y >= b->y + b->h) {
        a->x = b->x;
        a->y = b->y;
        a->w = 0;
        a->h = 0;
        return;
    }
    if (a->x < b->x) {
        a->w -= b->x - a->x;
        a->x = b->x;
    }
    if (a->y < b->y) {
        a->h -= b->y - a->y;
        a->y = b->y;
    }
    if (a->x + a->w > b->x + b->w) {
        a->w = b->x + b->w - a->x;
    }
    if (a->y + a->h > b->y + b->h) {
        a->h = b->y + b->h - a->y;
    }
}

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

typedef struct { u8 p[0x4C2]; s16 h4C2; } O_d5b;
extern O_d5b *D_800E4190_d5b[] asm("D_800E4190");
extern u8 D_800E3A04_d5b[] asm("D_800E3A04");
void func_800D5BF4(void) {
    s16 buf[4];
    s32 n = 0;
    s32 k, j;
    for (k = 0; k < 4; k++) {
        for (j = 0; j < 4; j++) {
            if (D_800E3A04_d5b[j] != 0 && D_800E4190_d5b[j]->h4C2 == k) {
                buf[n++] = j;
            }
        }
    }
    for (k = 0; k < n; k++) {
        D_800E4190_d5b[buf[k]]->h4C2 = k;
    }
}

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

s32 func_800D5D3C(s32 a) {
    if ((u32)(a - 0x4C) < 0x1A) {
        a -= 0x1A;
    } else {
        switch (a) {
        case 0x90:
            a = 0x85;
            break;
        case 0x9D:
            a = 0x8C;
            break;
        case 0xA1:
            a = 0x8A;
            break;
        case 0x95:
            a = 0x88;
            break;
        case 0x99:
            a = 0xA6;
            break;
        }
    }
    return a;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D5DA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D6194);

typedef struct { u8 pad0[4]; u16 h4; u16 h6; } S800D65A8;
extern S800D65A8 *D_800E41B8;
u16 func_800D65A8(s32 arg0) {
    return D_800E41B8[arg0].h4;
}

void func_800D65C4(u8 *dst, u16 *src, s32 sh) {
    s32 hi = 0x10 << sh;
    s32 lo = 1 << sh;
    s32 i, j;
    for (i = 0; i < 12; i++) {
        u32 bits = *src;
        for (j = 0; j < 11; j++) {
            if (bits & 0x8000) {
                if (j & 1) {
                    dst[i * 8 + (j >> 1)] |= hi;
                } else {
                    dst[i * 8 + (j >> 1)] |= lo;
                }
            }
            bits <<= 1;
        }
        src++;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800D664C);

extern s32 D_800E1E50;
void func_80029F58(s32);
void func_800D67B0(void) {
    if (D_800E1E50 != 0) {
        func_80029F58(D_800E1E50);
    }
}

extern s32 D_800E1E50;
extern u8 D_8006B47A;
extern s32 D_800E576C;
extern s16 D_1F800010;
void func_8002A200(s32, s32);
void func_800D67DC(void) {
    s32 tag = 0x61326F6D;
    s32 p;
    D_800E1E50 = 0;
    if (D_8006B47A == 1) {
        tag = 0x61316F6D;
    }
    p = func_80041F0C(0x10, tag + (D_800E576C << 24));
    D_800E1E50 = p;
    if (p != 0) {
        D_1F800010 = 4;
        func_8002A200(func_80041F6C(p), *(s32 *)(p + 4));
    }
}

s32 func_8003BE00(s32, void (*)(s32));
void func_8002A300(s32);
void func_800D686C(void) {
    s32 p = 0;
    if (D_800E1E50 != 0) {
        D_1F800010 = 4;
        while ((p = func_8003BE00(p, func_8002A300)) != 0) {
            if (*(s32 *)(p + 4) == func_80041F6C(D_800E1E50)) {
                func_8002A300(p);
            }
        }
    }
}

void DrawSync(s32);
void func_800D6900(void) {
    DrawSync(0);
    VSync(0);
}

typedef struct { s32 a[8]; } B800D6928;
typedef struct { u8 p[0x20]; s32 f20; u8 q[0x10]; B800D6928 b; } S800E2508_b;
extern S800E2508_b D_800E2508_b asm("D_800E2508");
extern s32 D_800E6804;
extern B800D6928 D_800E6708;
void func_80033074(s32);
void func_800D6928(void) {
    S800E2508_b *s = &D_800E2508_b;
    s32 v = D_800E6804;
    s->b = D_800E6708;
    s->f20 = v;
    func_800267A4(v);
    func_80033074(s->f20);
}

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

s32 func_8004A33C(s32);
s32 func_8004A2D4(void);
void func_8004A628(s32, s32, s32, s32);
void func_800D78BC(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_8004A33C(1 << (i + 8)) == 0) {
            D_80072530[i].a = 0xFF;
            D_80072530[i].b = 0;
        }
    }
    func_8004A628(0, func_8004A2D4(), 0x20, 0);
}

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

u8 *func_8003D8F4(s32, s32, s32);
void func_800D6C58(s32 x, s32 y, s32 w, s32 h, void *p);
void func_800D6C94(s32 x, s32 y, s32 w, s32 h, void *p);
void func_8003D504(s32);
void func_800D8D3C(s32 x, s32 y, s32 h) {
    u32 *p = (u32 *)func_8003D8F4(h << 7, 1, 2);
    u32 *q;
    s32 i;
    func_800D6C58(x, y, 0x40, h, p);
    q = p;
    for (i = 0; i < h << 5; i += 8) {
        q[0] |= 0x80008000;
        q[1] |= 0x80008000;
        q[2] |= 0x80008000;
        q[3] |= 0x80008000;
        q[4] |= 0x80008000;
        q[5] |= 0x80008000;
        q[6] |= 0x80008000;
        q[7] |= 0x80008000;
        q += 8;
    }
    func_800D6C94(x, y, 0x40, h, p);
    func_8003D504((s32)p);
}

typedef struct { u8 p[4]; u8 a; u8 b; u8 c; u8 r[33]; } E800E4A6Cb;
extern E800E4A6Cb D_800E4A6C_e[] asm("D_800E4A6C");
void func_800D8E58(u8 v, s32 k) {
    s32 i;
    for (i = 0; i < 5; i++) {
        ((E800E4A6Cb *)((u8 *)D_800E4A6C_e + k * 900 + i * 80))[D_800E3A44].a = v;
        ((E800E4A6Cb *)((u8 *)D_800E4A6C_e + k * 900 + i * 80))[D_800E3A44].b = v;
        ((E800E4A6Cb *)((u8 *)D_800E4A6C_e + k * 900 + i * 80))[D_800E3A44].c = v;
    }
}

typedef struct { s16 clip[4]; s16 ofs[2]; u8 rest[0x4090 - 0xC]; } DE_d8e;
extern DE_d8e D_8007EE88_d8e[2] asm("D_8007EE88");
extern u32 D_800E411C;
extern s32 D_800E3A44;
void func_800D8EF0(void) {
    DrawSync(0);
    VSync(0);
    if (!((D_800E411C >> 5) & 1)) {
        ClearImage(D_80086FB4, 0, 0, 0);
    }
    D_8007EE88_d8e[D_800E3A44 & 1].ofs[0] = (D_800E3A44 & 1) * 320;
    D_8007EE88_d8e[D_800E3A44 & 1].ofs[1] = 0;
    PutDrawEnv(D_80086FB4);
    PutDispEnv((u8 *)D_80086FB4 + 0x5C);
    DrawOTag((u8 *)D_80086FB4 + 0x408C);
}

typedef struct { u8 p[0x37C]; s32 f37C; s32 f380; } S_d8f;
extern S_d8f D_800E4940_d8f asm("D_800E4940");
extern u8 *D_80086FB4_d8f asm("D_80086FB4");
void func_800D90A8(s32, s32, s32, s32, s32, s32, s32);
void func_800A74F0(void);
void func_800D9890(u8 *, s32);
void func_800D8D3C(s32, s32, s32);
void func_800D8FB4(s32 a, s32 b, s32 c) {
    s32 i;
    s32 x;
    func_800D90A8(a, b, 0x280, 0, 0x280, 0, 0);
    c = 0x800000 / c;
    D_800E4940_d8f.f380 = 0x800000;
    D_800E4940_d8f.f37C = c;
    for (i = 0; i < 2; i++) {
        func_800A74F0();
        func_800D9890(D_80086FB4_d8f + 0x4070, 0);
        func_800D8EF0();
    }
    x = 0x280;
    for (i = 0; i < 5; i++) {
        func_800D8D3C(x, 0, 0xE0);
        x += 0x40;
    }
    for (i = 0; i < 2; i++) {
        func_800A74F0();
        func_800D9890(D_80086FB4_d8f + 0x4070, 0);
        func_800D8EF0();
    }
}

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

typedef struct { u8 b0; u8 b1; s16 h2; s16 h4; s16 h6; s32 f8; } E_da8;
extern s32 D_800E6750, D_800E67FC, D_800E6734, D_800E66F4, D_800E6764, D_800E66F0, D_800E66C0, D_800E66F8, D_800E6680, D_800E6754;
extern s32 D_800E6794_da8 asm("D_800E6794");
extern u8 D_800E6768[];
extern E_da8 D_800E6798[];
typedef struct { u8 p[0x20]; s32 f20; } S_da8;
extern volatile S_da8 D_8008E3A8_da8 asm("D_8008E3A8");
void func_8004B048(s32, s32);
void func_800DA8BC(void) {
    s32 i;
    s32 p;
    D_800E6794_da8 = 0;
    D_800E6750 = 0;
    D_800E67FC = 0;
    D_800E6734 = 0;
    D_800E66F4 = 0;
    D_800E6764 = 0;
    D_800E66F0 = 0;
    D_800E66C0 = 0;
    D_800E66F8 = 0;
    D_800E6680 = 0;
    D_800E6794_da8 = (s32)func_8003D8F4(0x8000, 0, 2);
    func_8004B048(D_800E6794_da8, 0x8000);
    D_8008E3A8_da8.f20 = 0;
    p = (s32)func_8003CD38(0x20000, 0);
    D_800E6754 = p;
    for (i = 0; i < 8; i++) {
        D_800E6768[i] = 0;
        D_800E6798[i].f8 = p;
        p += 0x4000;
        D_800E6798[i].b0 = 0;
        D_800E6798[i].b1 = 0xFF;
        D_800E6798[i].h2 = 0;
        D_800E6798[i].h4 = 0;
        D_800E6798[i].h6 = 0;
    }
}

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

extern u8 D_800E1E60[];
extern u8 D_800E66BC;
extern s32 D_8006B4CC;
void func_8003F8C4(u8 *);
void func_800A3D34(s32);
void func_80028614(s32);
void func_800DBE64(void) {
    VSync(0);
    func_8003F8C4(D_800E1E60);
    VSync(0);
    func_800A3D34(0);
    func_800A3AA4(0);
    VSync(0);
    if (D_800E66BC == 0) {
        func_800DA6E0();
    } else {
        func_80028614(D_8006B4CC);
    }
}

typedef struct { s32 a; s32 b; s32 c; s32 d; s32 e; } S800E65F8;
extern S800E65F8 D_800E65F8;
extern s32 D_800E6640;
extern s32 D_800E6760;
extern s32 D_800E6704;
void func_8004AF74(void);
void func_800DBEE0(void) {
    func_800DBE64();
    DrawSync(0);
    VSync(0);
    func_8004AF74();
    func_8003D504(D_800E65F8.a);
    func_8003D504(D_800E65F8.b);
    func_8003D504(D_800E65F8.d);
    func_8003D504(D_800E65F8.e);
    func_8003D504(D_800E6640);
    func_800DA874();
    if (D_800E6760 == 2) {
        func_8003D504(D_800E6704);
    }
    D_800E65F8.b = 0;
    D_800E65F8.a = 0;
}

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

void func_800DC4FC(void) {
    u16 a = D_800E6910.a[0];
    u16 b = D_800E6910.b[0];
    s32 i;
    for (i = 0; i < D_800E6910.h0 - 1; i++) {
        D_800E6910.a[i] = D_800E6910.a[i + 1];
        D_800E6910.b[i] = D_800E6910.b[i + 1];
    }
    D_800E6910.a[D_800E6910.h0 - 1] = a;
    D_800E6910.b[D_800E6910.h0 - 1] = b;
    D_800E6910.h52 = 2;
    D_800E6910.h54 = D_800E6910.h0 - 1;
}

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

s32 func_800DC684(void) {
    s32 m = D_800E6910.h52;
    switch (m) {
    case 0:
        return 0;
    case 1:
    case 2:
        D_800E6910.h52 = 0;
        break;
    case 3:
        if (D_800E6910.h54 < D_800E6910.h0) {
            D_800E6910.h52 = m;
        } else {
            D_800E6910.h52 = 0;
        }
        break;
    }
    func_800DC64C(D_800E6910.h54);
    D_800E6910.h54++;
    return D_800E6910.h52;
}

s32 func_800DC738(void) {
    s32 m = D_800E6910.h52;
    switch (m) {
    case 0:
        return 0;
    case 1:
    case 2:
        D_800E6910.h52 = 0;
        break;
    case 3:
        if (D_800E6910.h54 < D_800E6910.h0) {
            D_800E6910.h52 = m;
        } else {
            D_800E6910.h52 = 0;
        }
        break;
    }
    func_800DC64C(D_800E6910.h54);
    D_800E6910.h54++;
    return D_800E6910.h52;
}

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

void func_800DCCE8(u16 *k, u8 *v, s32 n) {
    s32 i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i; j < n; j++) {
            u16 a = k[i];
            u16 b = k[j];
            if (b < a || a == 0) {
                u8 t;
                k[i] = b;
                k[j] = a;
                t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
}

void func_800DCD7C(u16 *k, u8 *v, s32 n) {
    s32 i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i; j < n; j++) {
            u16 a = k[i];
            u16 b = k[j];
            if (a < b || a == 0) {
                u8 t;
                k[i] = b;
                k[j] = a;
                t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
}

typedef struct { u8 p[0x2B98]; u16 a[0xC0]; u8 b[0xC0]; } S_dce;
extern S_dce D_8006EBC8_dce asm("D_8006EBC8");
void func_800DCD7C(u16 *, u8 *, s32);
void func_800DCCE8(u16 *, u8 *, s32);
s32 func_800DCE10(u16 *out16, u8 *out8, u16 *buf16, u8 *buf8, s32 lo, s32 hi, s32 mode) {
    s32 i, j, n;
    for (n = i = 0; i < 0xC0; i++) {
        s32 v = D_8006EBC8_dce.a[i];
        if (v >= lo && v <= hi) {
            buf16[n] = v;
            buf8[n] = D_8006EBC8_dce.b[i];
            n++;
            D_8006EBC8_dce.a[i] = 0;
            D_8006EBC8_dce.b[i] = 0;
        }
    }
    if (mode) {
        func_800DCD7C(buf16, buf8, n);
    } else {
        func_800DCCE8(buf16, buf8, n);
    }
    for (j = i = 0; i < n; i++) {
        out16[j] = buf16[i];
        out8[j++] = buf8[i];
    }
    return j;
}

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

typedef struct { u8 p[0x2B98]; u16 h[0xC0]; u8 b[0xC0]; } S8006EBC8_2B98b;
extern S8006EBC8_2B98b D_8006EBC8_2B98b asm("D_8006EBC8");
s32 func_800DD6F0(s32 id) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 0xC0; i++) {
        if (D_8006EBC8_2B98b.h[i] == id) {
            if (D_8006EBC8_2B98b.b[i] < 99) {
                D_8006EBC8_2B98b.b[i]++;
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        for (i = 0; i < 0xC0; i++) {
            if (D_8006EBC8_2B98b.h[i] == 0) {
                D_8006EBC8_2B98b.h[i] = id;
                D_8006EBC8_2B98b.b[i] = 1;
                found = 1;
                break;
            }
        }
    }
    return found;
}

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

typedef struct { u8 p[0x2718]; u16 h[0x180]; u8 b[0x180]; } S8006EBC8_2718b;
extern S8006EBC8_2718b D_8006EBC8_2718b asm("D_8006EBC8");
s32 func_800DDDA8(s32 id) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 0x180; i++) {
        if (D_8006EBC8_2718b.h[i] == id) {
            if (D_8006EBC8_2718b.b[i] < 99) {
                D_8006EBC8_2718b.b[i]++;
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        for (i = 0; i < 0x180; i++) {
            if (D_8006EBC8_2718b.h[i] == 0) {
                D_8006EBC8_2718b.h[i] = id;
                D_8006EBC8_2718b.b[i] = 1;
                found = 1;
                break;
            }
        }
    }
    return found;
}

typedef struct { s16 lo; s16 hi; } H_dde;
extern s32 D_800E6810[];
extern s32 D_8007EE0C;
extern s16 D_1F800010;
void func_8004257C(s16, s16, s32, s32, s32, s32, s32);
void func_800DDE50(s32 x, s32 y, s32 k, s32 mode, s32 e) {
    s32 h = ((H_dde *)&D_800E6810[k])->hi;
    switch (mode) {
    case 0:
        func_8004257C(x, y - h, e, 5, D_8007EE0C + 0x10, 0, 0x808080);
        break;
    case 1:
        func_8004257C(x, y + h, e, 7, D_8007EE0C + 0x10, 0, 0x808080);
        break;
    }
    if (D_800E6810[k] > 0x40000) {
        D_800E6810[k] = 0;
    } else {
        D_800E6810[k] += D_1F800010 * 0x3000;
    }
}

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DDF50);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DE330);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DEA18);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DF244);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DF3DC);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DF768);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DFA74);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800DFDA8);

INCLUDE_ASM("asm/ov_field/nonmatchings/field_800A39B4", func_800E0148);
