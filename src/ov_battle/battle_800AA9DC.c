#include "common.h"
#include "ov_battle/battle_800A3E3C.h"

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AA9DC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AAB98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AB030);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AB82C);

s32 func_800ABCEC(u8 *p) {
    *(s32 *)(p + 0x108) += 2;
    return 0;
}

extern u8 D_8009DC00[];
void func_80096178(u8 *, u8 *);
void func_80096190(s32, s32);
s32 func_800ABD04(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    func_80096178(p, D_8009DC00);
    func_80096190((s32)p, *(s16 *)(q + 2));
    return 2;
}

void func_80096180(s32);
void func_800961A4(s32, s32);
s32 func_800ABD4C(s32 a0) {
    func_80096180(a0);
    func_800961A4(a0, 0x1C);
    return 1;
}

void func_800ABD80(void) {
}

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3308);

void func_800AC0F8();
void func_800ABD80_a(char *, s32) asm("func_800ABD80");
void func_800ABD88(u8 *a0, s32 a1) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800AC0F8)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0) {
            func_800ABD80_a("Move", a1);
            func_8009CA60(p);
            p = n;
        }
    }
}

void func_800AD880();
void func_800ABD80_a(char *, s32) asm("func_800ABD80");
void func_800ABE24(u8 *a0, s32 a1) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800AD880)) != 0) {
        if (*(u8 **)(p + 0xC) == a0) {
            func_800ABD80_a("Hop", a1);
        }
    }
}

void func_800AC944();
void func_800ABD80_a(char *, s32) asm("func_800ABD80");
void func_800ABEB0(u8 *a0, s32 a1) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800AC944)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0) {
            func_800ABD80_a("OvalMove", a1);
            func_8009CA60(p);
            p = n;
        }
    }
}

void func_800AE31C();
void func_800ABD80_a(char *, s32) asm("func_800ABD80");
void func_800ABF4C(u8 *a0, s32 a1) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800AE31C)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0) {
            func_800ABD80_a("Rotation", a1);
            func_8009CA60(p);
            p = n;
        }
    }
}

u8 *func_800ABFE8(u8 *a0, s32 *a1, s32 a2) {
    u8 *t = func_8009C9F4(a0, func_800AC0F8);
    *(u8 **)(t + 0xC) = a0;
    *(s32 *)(t + 0x10) = a2;
    *(s32 *)(a0 + 0x94) = (a1[0] - *(s32 *)(a0 + 0x84)) / a2;
    *(s32 *)(a0 + 0x9C) = (a1[2] - *(s32 *)(a0 + 0x8C)) / a2;
    *(s32 *)(a0 + 0x98) = (a1[1] - *(s32 *)(a0 + 0x88)) / a2;
    return t;
}

void func_800AC0F8(u8 *a0) {
    s32 n = *(s32 *)(a0 + 0x10);
    s32 d = D_1F800010;
    u8 *o = *(u8 **)(a0 + 0xC);
    if (d < n) n = d;
    *(s32 *)(o + 0x84) += *(s32 *)(o + 0x94) * n;
    *(s32 *)(o + 0x88) += *(s32 *)(o + 0x98) * n;
    *(s32 *)(o + 0x8C) += *(s32 *)(o + 0x9C) * n;
    if ((*(s32 *)(a0 + 0x10) -= d) <= 0) {
        *(s32 *)(o + 0x84) = *(s16 *)(a0 + 0x14) << 12;
        *(s32 *)(o + 0x88) = *(s16 *)(a0 + 0x16) << 12;
        *(s32 *)(o + 0x8C) = *(s16 *)(a0 + 0x18) << 12;
        *(s32 *)(o + 0x94) = *(s32 *)(o + 0x98) = *(s32 *)(o + 0x9C) = 0;
        func_8009CA60(a0);
    }
}

typedef struct { s16 h[4]; } S1D8;
void func_800AC1D8(u8 *o, s32 a1, s16 *v) {
    s32 n = a1 + *(s16 *)(o + 0x110);
    *(s16 *)(o + 0x144) = a1;
    if (n > 0) {
        u8 *t = func_8009C9F4(o, func_800AC0F8);
        *(u8 **)(t + 0xC) = o;
        *(s32 *)(t + 0x10) = n;
        *(S1D8 *)(t + 0x14) = *(S1D8 *)v;
        if (*(s16 *)(o + 0x110) < 0) {
            n = -*(s16 *)(o + 0x110);
            *(s32 *)(o + 0x84) += *(s32 *)(o + 0x94) * n;
            *(s32 *)(o + 0x88) += *(s32 *)(o + 0x98) * n;
            *(s32 *)(o + 0x8C) += *(s32 *)(o + 0x9C) * n;
        }
    } else {
        *(s32 *)(o + 0x84) = v[0] << 12;
        *(s32 *)(o + 0x88) = v[1] << 12;
        *(s32 *)(o + 0x8C) = v[2] << 12;
        *(s32 *)(o + 0x94) = *(s32 *)(o + 0x98) = *(s32 *)(o + 0x9C) = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AC2F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AC484);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AC60C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AC788);

s32 func_800AC8A4(void) {
    return 5;
}

typedef struct { s32 x, y, z; } VECAC8;
void VectorNormal_(VECAC8 *, VECAC8 *) asm("VectorNormal");
s32 func_800AC8AC(u8 *p) {
    VECAC8 v;
    s16 *d = func_8009AAE0(p, *(s16 *)(*(u8 **)(p + 0x108) + 2));
    v.x = *(s32 *)(p + 0x94) >> 8;
    v.y = *(s32 *)(p + 0x98) >> 8;
    v.z = *(s32 *)(p + 0x9C) >> 8;
    VectorNormal_(&v, &v);
    d[0] = v.x;
    d[2] = v.y;
    d[1] = v.z;
    return 2;
}

s32 func_800AC93C(void) {
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AC944);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800ACADC);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3364);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3394);

void *func_800B54D0(u8 *);
s32 func_800ACDB0(u8 *a0) {
    s16 *d = func_8009AAE0(a0, *(s16 *)(*(u8 **)(a0 + 0x108) + 2));
    u8 *s = func_800B54D0(a0);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetStandPos()", D_800A0F08);
    }
    d[0] = *(s16 *)(s + 4);
    d[1] = *(s16 *)(s + 8);
    d[2] = *(s16 *)(s + 6);
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800ACE44);

s32 func_800ACFB0(u8 *p) {
    s16 *r = func_8009AAE0(p, *(s16 *)(*(u8 **)(p + 0x108) + 2));
    *(s32 *)(p + 0x84) = r[0] << 12;
    *(s32 *)(p + 0x8C) = r[1] << 12;
    *(s32 *)(p + 0x88) = r[2] << 12;
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AD018);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AD150);

extern s32 D_800A0F00[];
u8 **func_8003099C_d(s32) asm("func_8003099C");
void func_8009789C(s32, s32, s32);
typedef struct { s32 x, y, z, pad; } VD288;
s32 func_800AD288(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 **o;
    s16 *r;
    VD288 v;
    if (q[1] == 0) o = func_8003099C_d(q[2]);
    else o = func_800309D0(q[2]);
    if (!o) func_80029DD8(D_800A3364, "kz_GetELPos()", D_800A0F00[q[1]]);
    r = func_8009AAE0(a0, q[4]);
    func_8009789C((s32)*o, q[3], (s32)&v);
    r[0] = v.x;
    r[1] = v.z;
    r[2] = v.y;
    return 5;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AD36C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AD564);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AD6A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AD880);

extern char D_800A343C[];
void func_800AD880();
u8 *func_800AD9D0(u8 *a0, s32 *a1, s32 *a2, s32 a3, s32 a4) {
    s32 h;
    s32 vx, vy, vz, dy, hh;
    u8 *t;
    func_800ABD88(a0, (s32)D_800A343C);
    func_800ABE24(a0, (s32)D_800A343C);
    func_800ABEB0(a0, (s32)D_800A343C);
    vx = (a1[0] - *(s32 *)(a0 + 0x84)) / a3;
    vy = (a1[1] - *(s32 *)(a0 + 0x88)) / a3;
    *(s32 *)(a0 + 0x94) = vx;
    vz = (a1[2] - *(s32 *)(a0 + 0x8C)) / a3;
    h = a3 / 2;
    vy -= a4 * h;
    dy = vy * h;
    hh = h * h;
    *(s32 *)(a0 + 0x98) = vy;
    *(s32 *)(a0 + 0x9C) = vz;
    a2[0] = *(s32 *)(a0 + 0x84) + *(s32 *)(a0 + 0x94) * h;
    a2[2] = *(s32 *)(a0 + 0x8C) + *(s32 *)(a0 + 0x9C) * h;
    a2[1] = *(s32 *)(a0 + 0x88) + (dy + a4 / 2 * hh);
    t = func_8009C9F4(a0, func_800AD880);
    *(u8 **)(t + 0xC) = a0;
    *(s16 *)(t + 0x10) = a3;
    *(s16 *)(t + 0x12) = 0;
    *(s16 *)(t + 0x18) = a1[0] >> 12;
    *(s16 *)(t + 0x1A) = a1[1] >> 12;
    *(s16 *)(t + 0x1C) = a1[2] >> 12;
    *(s32 *)(t + 0x14) = a4;
    return t;
}

extern char D_800A343C[];
void func_800AD880();
void func_800ADBEC_m(u8 *a0, s32 *a1, s32 a2) asm("func_800ADBEC");
void func_800ADBEC_m(u8 *a0, s32 *a1, s32 a2) {
    s32 vx, g, vz;
    u8 *t;
    func_800ABD88(a0, (s32)D_800A343C);
    func_800ABE24(a0, (s32)D_800A343C);
    func_800ABEB0(a0, (s32)D_800A343C);
    vx = (a1[0] - *(s32 *)(a0 + 0x84)) / a2;
    g = -((a1[1] - *(s32 *)(a0 + 0x88)) * 2) / (a2 * a2);
    *(s32 *)(a0 + 0x94) = vx;
    vz = (a1[2] - *(s32 *)(a0 + 0x8C)) / a2;
    *(s32 *)(a0 + 0x98) = -(g * a2);
    *(s32 *)(a0 + 0x9C) = vz;
    t = func_8009C9F4(a0, func_800AD880);
    *(u8 **)(t + 0xC) = a0;
    *(s16 *)(t + 0x10) = a2;
    *(s16 *)(t + 0x12) = 0;
    *(s16 *)(t + 0x18) = a1[0] >> 12;
    *(s16 *)(t + 0x1A) = a1[1] >> 12;
    *(s16 *)(t + 0x1C) = a1[2] >> 12;
    *(s32 *)(t + 0x14) = g;
}

extern char D_800A343C[];
void func_800AD880();
void func_800ADD8C_m(u8 *a0, s32 *a1, s32 a2) asm("func_800ADD8C");
void func_800ADD8C_m(u8 *a0, s32 *a1, s32 a2) {
    s32 vx, g, vz;
    u8 *t;
    func_800ABD88(a0, (s32)D_800A343C);
    func_800ABE24(a0, (s32)D_800A343C);
    func_800ABEB0(a0, (s32)D_800A343C);
    g = a1[1];
    *(s32 *)(a0 + 0x94) = (a1[0] - *(s32 *)(a0 + 0x84)) / a2;
    vz = (a1[2] - *(s32 *)(a0 + 0x8C)) / a2;
    g = ((g - *(s32 *)(a0 + 0x88)) * 2) / (a2 * a2);
    *(s32 *)(a0 + 0x98) = 0;
    *(s32 *)(a0 + 0x9C) = vz;
    t = func_8009C9F4(a0, func_800AD880);
    *(u8 **)(t + 0xC) = a0;
    *(s16 *)(t + 0x10) = a2;
    *(s16 *)(t + 0x12) = 0;
    *(s16 *)(t + 0x18) = a1[0] >> 12;
    *(s16 *)(t + 0x1A) = a1[1] >> 12;
    *(s16 *)(t + 0x1C) = a1[2] >> 12;
    *(s32 *)(t + 0x14) = g;
}

void func_800ADF14(u8 *o, u8 *t) {
    if (*(s16 *)(t + 0x10) > 0) {
        s32 h = *(s16 *)(o + 0x110);
        if (h < 0) {
            s32 n = -h;
            *(s32 *)(o + 0x84) += *(s32 *)(o + 0x94) * n;
            *(s32 *)(o + 0x8C) += *(s32 *)(o + 0x9C) * n;
            *(s16 *)(t + 0x12) += 1;
            *(s32 *)(o + 0x88) -= *(s32 *)(o + 0x98) / 2;
            while (n != 0) {
                *(s32 *)(o + 0x88) += *(s32 *)(o + 0x98);
                *(s32 *)(o + 0x98) += *(s32 *)(t + 0x14);
                n--;
            }
        }
    } else {
        *(s32 *)(o + 0x84) = *(s16 *)(t + 0x18) << 12;
        *(s32 *)(o + 0x88) = *(s16 *)(t + 0x1A) << 12;
        *(s32 *)(o + 0x8C) = *(s16 *)(t + 0x1C) << 12;
        *(s32 *)(o + 0x94) = *(s32 *)(o + 0x98) = *(s32 *)(o + 0x9C) = 0;
        func_8009CA60(t);
    }
}

u8 *func_800AD9D0(u8 *, s32 *, s32 *, s32, s32);
void func_800ADF14(u8 *, u8 *);
s32 func_800AE02C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    s16 *s = func_8009AAE0(a0, q[1]);
    s16 *d;
    u8 *r;
    s32 in[4];
    s32 out[4];
    d = func_8009AAE0(a0, q[2]);
    in[0] = s[0] << 12;
    in[2] = s[1] << 12;
    in[1] = s[2] << 12;
    r = func_800AD9D0(a0, in, out, q[3], 0x9CCC);
    *(u16 *)(r + 0x10) += *(u16 *)(a0 + 0x110);
    d[0] = out[0] >> 12;
    d[1] = out[2] >> 12;
    d[2] = out[1] >> 12;
    func_800ADF14(a0, r);
    *(s16 *)(a0 + 0x144) = q[3];
    return 4;
}

typedef struct { s32 x, y, z; } V3AE;
s16 *func_8009AAE0(u8 *, s32);
u8 *func_800ADBEC(u8 *, V3AE *, s32);
void func_800ADF14(u8 *, u8 *);
s32 func_800AE11C(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    s16 *r = func_8009AAE0(p, q[1]);
    V3AE v;
    u8 *o;
    v.x = r[0] << 12;
    v.z = r[1] << 12;
    v.y = r[2] << 12;
    o = func_800ADBEC(p, &v, q[2]);
    *(u16 *)(o + 0x10) += *(u16 *)(p + 0x110);
    func_800ADF14(p, o);
    *(s16 *)(p + 0x144) = q[2];
    return 3;
}

typedef struct { s32 x, y, z; } V3AE1;
s16 *func_8009AAE0(u8 *, s32);
u8 *func_800ADD8C(u8 *, V3AE1 *, s32);
void func_800ADF14(u8 *, u8 *);
s32 func_800AE1C0(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    s16 *r = func_8009AAE0(p, q[1]);
    V3AE1 v;
    u8 *o;
    v.x = r[0] << 12;
    v.z = r[1] << 12;
    v.y = r[2] << 12;
    o = func_800ADD8C(p, &v, q[2]);
    *(u16 *)(o + 0x10) += *(u16 *)(p + 0x110);
    func_800ADF14(p, o);
    *(s16 *)(p + 0x144) = q[2];
    return 3;
}

s32 func_800AE264(u8 *p) {
    u16 *d = (u16 *)func_8009AAE0(p, *(s16 *)(*(u8 **)(p + 0x108) + 2));
    d[0] = *(u16 *)(p + 0xA4);
    d[1] = *(u16 *)(p + 0xA8);
    d[2] = *(u16 *)(p + 0xA6);
    return 2;
}

s32 func_800AE2C0(u8 *p) {
    u16 *d = (u16 *)func_8009AAE0(p, *(s16 *)(*(u8 **)(p + 0x108) + 2));
    *(u16 *)(p + 0xA4) = d[0];
    *(u16 *)(p + 0xA8) = d[1];
    *(u16 *)(p + 0xA6) = d[2];
    return 2;
}

void func_800AE31C(u8 *a0) {
    s32 n = *(s32 *)(a0 + 0x10);
    s32 d = D_1F800010;
    u8 *o = *(u8 **)(a0 + 0xC);
    if (d < n) n = d;
    *(s32 *)(a0 + 0x24) += *(s32 *)(a0 + 0x14) * n;
    *(s32 *)(a0 + 0x28) += *(s32 *)(a0 + 0x18) * n;
    *(s32 *)(a0 + 0x2C) += *(s32 *)(a0 + 0x1C) * n;
    *(s16 *)(o + 0xA4) = (*(s32 *)(a0 + 0x24) >> 12) & 0xFFF;
    *(s16 *)(o + 0xA6) = (*(s32 *)(a0 + 0x28) >> 12) & 0xFFF;
    *(s16 *)(o + 0xA8) = (*(s32 *)(a0 + 0x2C) >> 12) & 0xFFF;
    if ((*(s32 *)(a0 + 0x10) -= n) <= 0) func_8009CA60(a0);
}

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A343C);

typedef struct { s16 x, y, z, pad; } SVAE3;
typedef struct { s32 x, y, z, pad; } VAE3;
s32 func_8009A9C0(u8 *, SVAE3 *, SVAE3 *);
s32 func_800AE3FC(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    s32 n = q[2];
    s16 *r;
    SVAE3 in;
    SVAE3 out;
    VAE3 v;
    u8 *t;
    s32 h;
    func_800ABF4C(a0, (s32)"Rot");
    r = func_8009AAE0(a0, q[1]);
    in.x = r[0] & 0xFFF;
    in.z = r[1] & 0xFFF;
    in.y = r[2] & 0xFFF;
    func_8009A9C0(a0 + 0xA4, &in, &out);
    v.x = (out.x << 12) / n;
    v.z = (out.z << 12) / n;
    v.y = (out.y << 12) / n;
    t = func_8009C9F4(a0, func_800AE31C);
    *(u8 **)(t + 0xC) = a0;
    *(s32 *)(t + 0x10) = n + *(s16 *)(a0 + 0x110);
    *(s32 *)(t + 0x14) = v.x;
    *(s32 *)(t + 0x18) = v.y;
    *(s32 *)(t + 0x1C) = v.z;
    *(s32 *)(t + 0x24) = *(s16 *)(a0 + 0xA4) << 12;
    *(s32 *)(t + 0x28) = *(s16 *)(a0 + 0xA6) << 12;
    *(s32 *)(t + 0x2C) = *(s16 *)(a0 + 0xA8) << 12;
    if (*(s16 *)(a0 + 0x110) < 0) {
        h = *(s16 *)(a0 + 0x110);
        *(s32 *)(t + 0x24) += *(s32 *)(t + 0x14) * (h >= 0 ? h : -h);
        h = *(s16 *)(a0 + 0x110);
        *(s32 *)(t + 0x28) += *(s32 *)(t + 0x18) * (h >= 0 ? h : -h);
        h = *(s16 *)(a0 + 0x110);
        *(s32 *)(t + 0x2C) += *(s32 *)(t + 0x1C) * (h >= 0 ? h : -h);
        *(s16 *)(a0 + 0xA4) = (*(s32 *)(t + 0x24) >> 12) & 0xFFF;
        *(s16 *)(a0 + 0xA6) = (*(s32 *)(t + 0x28) >> 12) & 0xFFF;
        *(s16 *)(a0 + 0xA8) = (*(s32 *)(t + 0x2C) >> 12) & 0xFFF;
    }
    return 3;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AE674);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AE7B0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AEA48);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AEB98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AEC64);

void *func_8009CB34(void *, void *);
void func_8009CA60(void *);
void func_800AEB98();
void func_800AED98(u8 *a0) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800AEB98)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0) {
            func_8009CA60(p);
            p = n;
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AEE04);

void func_800AED98(u8 *);
void func_800AEC64(u8 *, s32, s32, s32);
s32 func_800AF024(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    func_800AED98(p);
    func_800AEC64(p, *(s16 *)(q + 2), *(s16 *)(p + 0x1AE), 1);
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AF070);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AF1D8);

void func_800AF1D8_l(u8 *, u8 *, s32) asm("func_800AF1D8");
void func_80029D9C(void);
s32 func_800AF3A8(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    s32 a = q[1];
    s32 b = q[2];
    char *s = "Look";
    u8 **o;
    func_800ABD88(p, (s32)s);
    func_800ABE24(p, (s32)s);
    func_800ABEB0(p, (s32)s);
    func_800ABF4C(p, (s32)s);
    o = func_800309D0(a);
    if (!o) func_80029D9C();
    func_800AF1D8_l(p, *o + 0x84, b);
    return 3;
}

typedef struct { s32 x, y, z; } V3AF;
s16 *func_8009AAE0(u8 *, s32);
void func_800AF1D8(u8 *, V3AF *, s32);
s32 func_800AF458(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    char *s = "LookPos";
    s16 *r;
    V3AF v;
    func_800ABEB0(p, (s32)s);
    func_800ABF4C(p, (s32)s);
    r = func_8009AAE0(p, q[1]);
    v.x = r[0] << 12;
    v.y = r[2] << 12;
    v.z = r[1] << 12;
    func_800AF1D8(p, &v, q[2]);
    return 3;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AF4F4);

s32 func_800AF688(void) {
    return 3;
}

void func_8009789C(s32, s32, s32);
void func_800AF690(u8 *p) {
    func_8009789C(**(s32 **)(p + 0x10), *(s32 *)(p + 0x14), *(s32 *)(p + 0xC) + 0x1C4);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AF6C4);

void func_800AF690();
void func_80097F80(u8 *, s32);
s32 func_800AF83C(u8 *a0) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800AF690)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0) {
            func_8009CA60(p);
            p = n;
        }
    }
    func_80097F80(a0, 0);
    return 1;
}

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A34D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AF8B8);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3508);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800AF954);

s32 func_800AFA2C(void) {
    return 1;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFA34(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetCommon()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x12);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFAC8(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetHitType()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x10);
    return 3;
}

typedef struct { unsigned b0 : 1; } BF14;
void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFB5C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetDeath()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = ((BF14 *)(s + 0x14))->b0;
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFBF4(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetStatusL()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x14);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFC88(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetStatusH()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x16);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFD1C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetBtStatus0()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x20);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFDB0(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetBtStatus1()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x22);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFE44(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetBtStatus2()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x24);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFED8(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetBtStatus3()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x26);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800AFF6C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetAttrib()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u8 *)(s + 0x1B);
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800B0000(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetMonBit()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x18) >> 15;
    return 3;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800B0098(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetOption()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x28);
    return 3;
}

void *func_800B54D0(u8 *);
s32 func_800B012C(u8 *a0) {
    u8 *s0 = func_800B54D0(a0);
    if (s0 == 0) {
        func_80029DD8(D_800A3364, "kz_Erase()", D_800A0F08);
    }
    *(u32 *)(s0 + 0x14) &= ~2;
    return 2;
}

s16 *func_8009AAE0(u8 *, s32);
s32 func_800B0184(u8 *p) {
    s16 *r = func_8009AAE0(p, *(s16 *)(*(u8 **)(p + 0x108) + 2));
    *r = *(u16 *)(p + 0x146);
    return 2;
}

s32 func_800B01C8(u8 *p) {
    *(u16 *)(p + 0x146) = *(u16 *)(*(u8 **)(p + 0x108) + 2);
    return 2;
}

void func_80029DD8_4(char *, char *, s32, u8 *) asm("func_80029DD8");
s16 *func_8009AAE0(u8 *, s32);
s32 func_800B01E4(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B54D0(a0);
    if (!s) {
        func_80029DD8_4("%s\n  %s\x82\xC5\x8E\xA9\x95\xAA\x82\xCC\x8F\xEE\x95\xF1\x82\xAA\x8C\xA9\x82\xC2\x82\xA9\x82\xE8\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\x81\x42\n%x\n",
                        "kz_GetModelNum()", D_800A0F08, a0);
    }
    *func_8009AAE0(a0, q[1]) = *(u16 *)(s + 0x18) & 0x7FFF;
    return 2;
}

void *func_800B54D0(u8 *);
s32 func_800B0268(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    u8 *s1 = func_800B54D0(a0);
    if (s1 == 0) {
        func_80029DD8(D_800A3364, "kz_GetPnum()", D_800A0F08);
    }
    *func_8009AAE0(a0, *(s16 *)(q + 2)) = (*(u32 *)(s1 + 0x14) >> 4) & 7;
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B02EC);

void *func_800B54D0(u8 *);
s32 func_800B03B0(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    u8 *s1 = func_800B54D0(a0);
    if (s1 == 0) {
        func_80029DD8(D_800A3364, "kz_CheckEquipGrandorion()", D_800A0F08);
    }
    *func_8009AAE0(a0, *(s16 *)(q + 2)) = (*(u32 *)(s1 + 0x14) >> 13) & 1;
    return 2;
}

void *func_800B54D0(u8 *);
s32 func_800B0434(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    u8 *s1 = func_800B54D0(a0);
    if (s1 == 0) {
        func_80029DD8(D_800A3364, "kz_CheckEquipBraveShield()", D_800A0F08);
    }
    *func_8009AAE0(a0, *(s16 *)(q + 2)) = (*(u32 *)(s1 + 0x14) >> 14) & 1;
    return 2;
}

void *func_800B54D0(u8 *);
s32 func_800B04B8(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    u8 *s1 = func_800B54D0(a0);
    if (s1 == 0) {
        func_80029DD8(D_800A3364, "kz_CheckEquipBraveGoods()", D_800A0F08);
    }
    *func_8009AAE0(a0, *(s16 *)(q + 2)) = (*(u32 *)(s1 + 0x14) >> 15) & 1;
    return 2;
}

void *func_800B5624(s32, s32);
extern s32 D_800A0F00[];
s16 *func_8009AAE0(u8 *, s32);
s32 func_800B053C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *s = func_800B5624((s32)a0, q[1]);
    if (s == 0) {
        func_80029DD8(D_800A3364, "kz_GetBeta()", D_800A0F00[q[1]]);
    }
    *func_8009AAE0(a0, q[2]) = *(u16 *)(s + 0x2A);
    return 3;
}

void func_800962C4(u8 *, s32, s32);
void func_800962E0(u8 *, s32, s32);
void func_800B05D0(u8 *a0, s32 a1) {
    s32 n = a1;
    u8 *p = a0;
    u8 *o = *(u8 **)(p + 0xC);
    if (*(s16 *)(p + 0x10) == 0) {
        *(s16 *)(p + 0x10) = 1;
        *(s16 *)(p + 0x12) += *(s16 *)(p + 0x1A);
        func_800962C4(o, *(s16 *)(p + 0x14), 1);
        func_800962E0(o, *(s16 *)(p + 0x16), 1);
    } else {
        *(s16 *)(p + 0x10) = 0;
        *(s16 *)(p + 0x12) += *(s16 *)(p + 0x18);
        func_800962C4(o, *(s16 *)(p + 0x16), 1);
        func_800962E0(o, *(s16 *)(p + 0x14), 1);
    }
    if (*(s16 *)(p + 0x12) < 0) {
        if (n > 0) func_800B05D0(a0, n - 1);
        else if (*(s16 *)(p + 0x10) == 0) *(s16 *)(p + 0x12) = *(s16 *)(p + 0x1A);
        else *(s16 *)(p + 0x12) = *(s16 *)(p + 0x18);
    }
}

extern u16 D_1F800010_u asm("D_1F800010");
void func_800B05D0(u8 *, s32);
void func_800B06D4(u8 *p) {
    s16 v = *(u16 *)(p + 0x12) - D_1F800010_u;
    *(s16 *)(p + 0x12) = v;
    if (v < 0) {
        func_800B05D0(p, 8);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B0718);

void func_800B06D4();
s32 func_800B0828(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800B06D4)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0 && *(s16 *)(p + 0x14) == q[1] && *(s16 *)(p + 0x16) == q[2]) {
            func_8009CA60(p);
            p = n;
        }
    }
    return 3;
}

typedef struct { u8 pad[0xDA]; struct { s16 h; u8 pad[34]; } e[2]; } SB08C8;
s32 func_800B08C8(SB08C8 *p) {
    s32 i = *(s16 *)(*(u8 **)((u8 *)p + 0x108) + 2);
    if (i < 2) {
        if (i >= 0) {
            p->e[i].h = 0;
            goto end;
        }
    }
    p->e[1].h = 0;
    p->e[0].h = 0;
end:
    return 2;
}

s32 func_800B0910(SB08C8 *p) {
    s32 i = *(s16 *)(*(u8 **)((u8 *)p + 0x108) + 2);
    if (i < 2) {
        if (i >= 0) {
            p->e[i].h = 1;
            goto end;
        }
    }
    p->e[1].h = 1;
    p->e[0].h = 1;
end:
    return 2;
}

void func_800961B8(s32, s32);
s32 func_800B0964(s32 a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    func_800961B8(a0, *(u16 *)(q + 2) | (*(s16 *)(q + 4) << 16));
    return 3;
}

void func_800961C8(u8 *, s32);
s32 func_800B0998(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    if (*(s16 *)(q + 2)) {
        func_80096190((s32)p, 2);
        func_800961C8(p, *(s16 *)(q + 2) - 1);
    } else {
        func_800961A4((s32)p, 2);
    }
    return 2;
}

s32 func_800B0A08(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    u16 a = *(u16 *)(q + 4);
    *(u16 *)(p + 0x74) = (*(u16 *)(p + 0x74) & 0xFFE0) |
        (((s16)(a & 0x100) >> 4) | ((*(u16 *)(q + 2) & 0x3FF) >> 6) | ((a & 0x200) << 2));
    return 3;
}

s32 func_800B0A50(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    *(u16 *)(p + 0x76) = (*(u16 *)(q + 4) << 6) | ((*(u16 *)(q + 2) >> 4) & 0x3F);
    return 3;
}

void func_80096190(s32, s32);
s32 func_800B0A7C(s32 a0) {
    func_80096190(a0, 0x200);
    return 1;
}

void func_800961A4(s32, s32);
s32 func_800B0A9C(s32 a0) {
    func_800961A4(a0, 0x200);
    return 1;
}

void *func_800B5624(s32, s32);
s32 func_800B0ABC(s32 a0) {
    void *s0 = func_800B5624(a0, 1);
    if (s0 == 0) {
        func_80029DD8(D_800A3364, "kz_CallDamage()", D_800A0F04);
    }
    func_800A9A98(s0);
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B0B10);

void *func_800B54D0(u8 *);
s32 func_800B0B68(u8 *a0) {
    u8 *s0 = func_800B54D0(a0);
    if (s0 == 0) {
        func_80029DD8(D_800A3364, "kz_ChgEye()", D_800A0F08);
    }
    if ((*(u32 *)(s0 + 0x14) >> 12) & 1) {
        func_800989A4((s32)a0, *(s16 *)(*(u8 **)(a0 + 0x108) + 2));
    }
    return 2;
}

void *func_800B54D0(u8 *);
s32 func_800B0BE8(u8 *a0) {
    u8 *s0 = func_800B54D0(a0);
    if (s0 == 0) {
        func_80029DD8(D_800A3364, "kz_BlinkOn()", D_800A0F08);
    }
    if ((*(u32 *)(s0 + 0x14) >> 12) & 1) {
        func_80096190((s32)a0, 0x400);
    }
    return 1;
}

void func_800989A4(s32, s32);
s32 func_800B0C5C(s32 a0) {
    func_800961A4(a0, 0x400);
    func_800989A4(a0, 0);
    return 1;
}

extern s32 D_800A32F4;
s32 func_8004227C(s32, s32, s32);
void func_80032D40(s32);
s32 func_800B0C94(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    s32 key = q[1] | (q[2] << 16);
    if ((D_800A32F4 & 0xFFFFFF) != (key & 0xFFFFFF)) {
        s32 h = 0;
        u8 *t = *(u8 **)(*(u8 **)a0 + 0x18);
        if (t) {
            h = func_8004227C(0xC, key, *(s32 *)(t + 8) & 0x3F);
        }
        if (h) {
            func_80032D40(h);
        } else {
            func_800329B8(key);
        }
        D_800A32F4 = key;
    }
    return 3;
}

void func_80032D78(s32);
s32 func_800B0D40(void) {
    func_80032D78(0);
    return 1;
}

extern s32 D_800A32DC;
extern u8 *D_800A32D4;
extern u8 *D_8006AF4C;
s32 func_8004227C(s32, s32, s32);
void func_8002A200(u8 *, s32);
void func_8002A228(s32);
s32 func_800B0D60(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    s32 h = 0;
    s32 key = q[1] | (q[2] << 16);
    if ((D_800A32DC & 0xFFFFFF) != (key & 0xFFFFFF)) {
        u8 *t = D_800A32D4;
        if (t || (t = D_8006AF4C)) {
            h = func_8004227C(0x10, key, *(s32 *)(t + 8) & 0x3F);
        }
        if (h) {
            func_8002A200(func_80041F6C_(h), *(s32 *)(h + 4));
        } else {
            func_8002A228(key);
        }
        D_800A32DC = key;
    }
    return 3;
}

extern u8 *D_800A32D4;
extern u8 *D_8006AF4C;
s32 func_8004227C(s32, s32, s32);
void func_8002A200(u8 *, s32);
void func_8002A228(s32);
s32 func_800B0E2C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    s32 h = 0;
    s32 key = q[1] | (q[2] << 16);
    u8 *t = D_800A32D4;
    if (t || (t = D_8006AF4C)) {
        h = func_8004227C(0x10, key, *(s32 *)(t + 8) & 0x3F);
    }
    if (h) {
        func_8002A200(func_80041F6C_(h), *(s32 *)(h + 4));
    } else {
        func_8002A228(key);
    }
    return 3;
}

extern s32 D_800A32DC;
s32 func_800B0ED0(void) {
    D_800A32DC = 0;
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B0EE0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B10D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B12F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B1460);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B1790);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B1940);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B1D0C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B1EA4);

void func_800B1D0C();
void func_800B21C8(u8 *a0) {
    u8 *p = 0;
    while ((p = func_8009CB34(p, func_800B1D0C)) != 0) {
        u8 *n = *(u8 **)(p + 4);
        if (*(u8 **)(p + 0xC) == a0) {
            *(s32 *)(a0 + 0x2C) = *(s32 *)(p + 0x24);
            func_800961A4((s32)a0, 2);
            func_800961C8(a0, 0);
            func_80096180((s32)a0);
            func_8009CA60(p);
            p = n;
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B2268);

typedef struct { s32 a, b, c, pad[4]; } S8007E8A8;
extern S8007E8A8 D_8007E8A8[];
s32 func_800B2320(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    D_8007E8A8[q[1]].a = q[2];
    D_8007E8A8[q[1]].b = q[3];
    D_8007E8A8[q[1]].c = q[4];
    return 5;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B2390);

typedef struct { s16 x, y; } V2548;
typedef struct { s32 a, b, c, d; V2548 v; s32 w14, w18; } T2548;
extern T2548 D_8007E8A8_t5[] asm("D_8007E8A8");
extern u8 D_800A32D0[];
void func_800B2390();
s32 func_800B2548(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u16 k = q[1];
    u8 *t;
    s32 i;
    u8 **p;
    *(s32 *)&D_8007E8A8_t5[k].v = (u16)q[2] | (q[3] << 16);
    D_8007E8A8_t5[k].w18 = q[4];
    D_8007E8A8_t5[k].w14 = q[5];
    t = func_8009C9F4(a0, func_800B2390);
    *(u8 **)(t + 0xC) = a0;
    *(u16 *)(t + 0x10) = k;
    *(u16 *)(t + 0x12) = q[7];
    *(s32 *)(t + 0x14) = (q[6] - D_8007E8A8_t5[k].w14) / *(s16 *)(t + 0x12);
    i = 0;
    while ((p = func_8003099C_d(i))) {
        func_80096190((s32)*p, 0x100);
        i++;
    }
    i = 0;
    while ((p = func_800309D0(i))) {
        func_80096190((s32)*p, 0x100);
        i++;
    }
    D_800A32D0[k]++;
    return 8;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B26A4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B26F0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B2748);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B282C);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3784);

extern char D_800A3784[];
void func_80029DD8_2(char *, char *) asm("func_80029DD8");
s32 func_800B2A3C(u8 *p) {
    s32 i = *(s16 *)(*(u8 **)(p + 0x108) + 2);
    if (i >= *(s16 *)(p + 0x12)) {
        func_80029DD8_2(D_800A3784, "kz_DisElemMotion()");
    }
    *(u32 *)(*(u8 **)(*(u8 **)(p + 0xB4) + i * 0x6C + 0x64) + 0x10) |= 1;
    return 2;
}

s32 func_800B2AD0(u8 *p) {
    s32 i = *(s16 *)(*(u8 **)(p + 0x108) + 2);
    if (i >= *(s16 *)(p + 0x12)) {
        func_80029DD8_2(D_800A3784, "kz_EnaElemMotion()");
    }
    *(u32 *)(*(u8 **)(*(u8 **)(p + 0xB4) + i * 0x6C + 0x64) + 0x10) &= ~1;
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B2B64);

void func_800B2B64();
s32 func_800B2C2C(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    s32 n = *(s16 *)(q + 8);
    u16 x = *(u16 *)(q + 2);
    u16 y = *(u16 *)(q + 4);
    u16 z = *(u16 *)(q + 6);
    if (n > 0) {
        u8 *t = func_8009C9F4(a0, func_800B2B64);
        s32 h;
        *(u8 **)(t + 0xC) = a0;
        *(s32 *)(t + 0x10) = n;
        *(s16 *)(t + 0x14) = ((s16)x - *(s16 *)(a0 + 0xAC)) / n;
        *(s16 *)(t + 0x16) = ((s16)y - *(s16 *)(a0 + 0xAE)) / n;
        *(s16 *)(t + 0x18) = ((s16)z - *(s16 *)(a0 + 0xB0)) / n;
        *(u16 *)(t + 0x1C) = x;
        *(u16 *)(t + 0x1E) = y;
        *(u16 *)(t + 0x20) = z;
        h = *(s16 *)(a0 + 0x110);
        if (h < 0) {
            n += h;
            if (n > 0) {
                n = -h;
                *(s16 *)(a0 + 0xAC) += *(s16 *)(t + 0x14) * n;
                *(s16 *)(a0 + 0xAE) += *(s16 *)(t + 0x16) * n;
                *(s16 *)(a0 + 0xB0) += *(s16 *)(t + 0x18) * n;
                *(s32 *)(t + 0x10) -= n;
            } else {
                *(u16 *)(a0 + 0xAC) = x;
                *(u16 *)(a0 + 0xAE) = y;
                *(u16 *)(a0 + 0xB0) = z;
                func_8009CA60(t);
            }
        }
    } else {
        *(u16 *)(a0 + 0xAC) = x;
        *(u16 *)(a0 + 0xAE) = y;
        *(u16 *)(a0 + 0xB0) = z;
    }
    return 5;
}

typedef struct { s16 h[4]; } S2E1C;
typedef struct { u8 pad[0x5C]; s16 h5C, h5E, h60; u8 pad2[0x6C - 0x62]; } S2E1Cb;
void func_800B2E1C(u8 *a0) {
    s32 n = *(s32 *)(a0 + 0x10);
    s32 d = D_1F800010;
    u8 *o = *(u8 **)(a0 + 0xC);
    s32 k = *(s16 *)(a0 + 0x1A);
    if (d < n) n = d;
    (*(S2E1Cb **)(o + 0xB4))[k].h5C += *(s16 *)(a0 + 0x14) * n;
    (*(S2E1Cb **)(o + 0xB4))[k].h5E += *(s16 *)(a0 + 0x16) * n;
    (*(S2E1Cb **)(o + 0xB4))[k].h60 += *(s16 *)(a0 + 0x18) * n;
    if ((*(s32 *)(a0 + 0x10) -= d) <= 0) {
        *(S2E1C *)&(*(S2E1Cb **)(o + 0xB4))[k].h5C = *(S2E1C *)(a0 + 0x1C);
        func_8009CA60(a0);
    }
}

void func_800B2E1C();
s32 func_800B2F28(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    s32 n = *(s16 *)(q + 0xA);
    s32 k = *(s16 *)(q + 2);
    u16 x = *(u16 *)(q + 4);
    u16 y = *(u16 *)(q + 6);
    u16 z = *(u16 *)(q + 8);
    if (n > 0) {
        u8 *t = func_8009C9F4(a0, func_800B2E1C);
        s32 h;
        *(u8 **)(t + 0xC) = a0;
        *(s32 *)(t + 0x10) = n;
        *(s16 *)(t + 0x14) = ((s16)x - *(s16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5C)) / n;
        *(s16 *)(t + 0x16) = ((s16)y - *(s16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5E)) / n;
        *(s16 *)(t + 0x18) = ((s16)z - *(s16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x60)) / n;
        *(s16 *)(t + 0x1A) = k;
        *(u16 *)(t + 0x1C) = x;
        *(u16 *)(t + 0x1E) = y;
        *(u16 *)(t + 0x20) = z;
        h = *(s16 *)(a0 + 0x110);
        if (h < 0) {
            n += h;
            if (n > 0) {
                n = -h;
                *(s16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5C) += *(s16 *)(t + 0x14) * n;
                *(s16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5E) += *(s16 *)(t + 0x16) * n;
                *(s16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x60) += *(s16 *)(t + 0x18) * n;
                *(s32 *)(t + 0x10) -= n;
            } else {
                *(u16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5C) = x;
                *(u16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5E) = y;
                *(u16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x60) = z;
                func_8009CA60(t);
            }
        }
    } else {
        *(u16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5C) = x;
        *(u16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x5E) = y;
        *(u16 *)(k * 0x6C + *(u8 **)(a0 + 0xB4) + 0x60) = z;
    }
    return 6;
}

s32 func_800B31D0(u8 *p) {
    u8 *r = *(u8 **)(p + 0xB4) + *(s16 *)(*(u8 **)(p + 0x108) + 2) * 0x6C;
    *(s16 *)(r + 0x5C) = *(s16 *)(r + 0x5E) = *(s16 *)(r + 0x60) = 0x1000;
    return 2;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B3214);

s32 func_800B33C0(void) {
    return 3;
}

void func_8004A1DC(u8 *, s32, s32, s32);
s32 func_800B33C8(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    s32 h = 0;
    s32 key = q[1] | (q[2] << 16);
    while ((h = func_8004208C(h, 0x16, 0)) != 0) {
        if (*(s32 *)(h + 4) == key) {
            func_8004A1DC(func_80041F6C_(h), 0, 0x80, *(u16 *)&q[3] & 0x7F);
        }
    }
    return 4;
}

u8 **func_8003099C_(s32) asm("func_8003099C");
void func_80029DD8_1(char *) asm("func_80029DD8");
s32 func_800B3460(u8 *p) {
    u8 **r = func_8003099C_(*(s16 *)(*(u8 **)(p + 0x108) + 2));
    if (r == 0) {
        func_80029DD8_1("\x83\x4C\x83\x83\x83\x58\x83\x5E\x81\x5B\x8E\x77\x92\xE8\x82\xB3\x82\xEA\x82\xC4\x82\xDC\x82\xB9\x82\xF1\x81\x42\n");
    }
    *(u8 **)(*r + 0x10C) = p;
    return 2;
}

void func_80029DD8_1(char *) asm("func_80029DD8");
s32 func_800B34C4(u8 *p) {
    u8 **r = func_800309D0(*(s16 *)(*(u8 **)(p + 0x108) + 2));
    if (r == 0) {
        func_80029DD8_1("\x83\x5E\x81\x5B\x83\x51\x83\x62\x83\x67\x8E\x77\x92\xE8\x82\xB3\x82\xEA\x82\xC4\x82\xDC\x82\xB9\x82\xF1\x81\x42\n");
    }
    *(u8 **)(*r + 0x10C) = p;
    return 2;
}

void *func_800309D0(s32);
s32 func_800B3528(s32 a0) {
    s32 i = 0;
    u8 **r;
    while (1) {
        r = func_800309D0(i);
        i++;
        if (r == 0) {
            break;
        }
        *(s32 *)(*r + 0x10C) = a0;
    }
    return 1;
}

s32 func_800B3574(u8 *p) {
    if (*(s32 *)(p + 0x10C) == 0) {
        return 0;
    }
    *(s32 *)(p + 0x10C) = 0;
    return 1;
}

u8 **func_8003099C_(s32) asm("func_8003099C");
void func_80029DD8_1(char *) asm("func_80029DD8");
extern char D_800A3820[];
s32 func_800B3594(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    u8 **r = func_8003099C_(q[1]);
    s32 d, s;
    if (r == 0) {
        func_80029DD8_1(D_800A3820);
    }
    d = q[3] * 2;
    s = q[2] * 2;
    *(u16 *)(p + d + 0x124) = *(u16 *)(*r + s + 0x124);
    return 4;
}

void func_80029DD8_1(char *) asm("func_80029DD8");
extern char D_800A3840[];
s32 func_800B3614(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    u8 **r = func_800309D0(q[1]);
    s32 d, s;
    if (r == 0) {
        func_80029DD8_1(D_800A3840);
    }
    d = q[3] * 2;
    s = q[2] * 2;
    *(u16 *)(p + d + 0x124) = *(u16 *)(*r + s + 0x124);
    return 4;
}

u8 **func_8003099C_(s32) asm("func_8003099C");
void func_80029DD8_1(char *) asm("func_80029DD8");
extern char D_800A3820[];
s32 func_800B3694(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    u8 **r = func_8003099C_(q[1]);
    s32 d, s;
    if (r == 0) {
        func_80029DD8_1(D_800A3820);
    }
    d = q[2] * 2;
    s = q[3] * 2;
    *(u16 *)(*r + d + 0x124) = *(u16 *)(p + s + 0x124);
    return 4;
}

void func_80029DD8_1(char *) asm("func_80029DD8");
extern char D_800A3840[];
s32 func_800B3714(u8 *p) {
    s16 *q = *(s16 **)(p + 0x108);
    u8 **r = func_800309D0(q[1]);
    s32 d, s;
    if (r == 0) {
        func_80029DD8_1(D_800A3840);
    }
    d = q[2] * 2;
    s = q[3] * 2;
    *(u16 *)(*r + d + 0x124) = *(u16 *)(p + s + 0x124);
    return 4;
}

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3820);

INCLUDE_RODATA("asm/ov_battle/nonmatchings/battle_800AA9DC", D_800A3840);

extern s32 D_800D9C70;
void func_800B5710(void);
u8 *func_800B5550_l(u8 *) asm("func_800B5550");
void func_8009B0D8(void *, s32, s32);
extern s32 D_800A0F00[];
s32 func_800B3794(u8 *a0) {
    u8 *s;
    u8 **o;
    if (!D_800D9C70) {
        D_800D9C70 = 1;
        func_800B5710();
    }
    s = func_800B5550_l(a0);
    if (!s) func_80029DD8(D_800A3364, "kz_CallDamTarget()", D_800A0F00[0]);
    o = func_800309D0(*(s16 *)(*(u8 **)(a0 + 0x108) + 2));
    if (!o) func_80029DD8(D_800A3364, "kz_CallDamTarget()", D_800A0F04);
    if (a0 != *o) func_8009B0D8(*o, *(s16 *)(s + 0xC), 7);
    return 2;
}

extern s32 D_800D9C70;
void func_800B5710(void);
u8 *func_800B5550_l(u8 *) asm("func_800B5550");
s32 func_800B3860(u8 *a0) {
    u8 *s;
    s32 i;
    u8 **o;
    if (!D_800D9C70) {
        D_800D9C70 = 1;
        func_800B5710();
    }
    s = func_800B5550_l(a0);
    if (!s) {
        func_80029DD8(D_800A3364, "kz_CallDamTargetAll()", D_800A0F00[0]);
    }
    for (i = 0; (o = func_800309D0(i)) != 0; i++) {
        if (a0 != *o) func_8009B0D8(*o, *(s16 *)(s + 0xC), 7);
    }
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B3914);

void func_800B3914();
s32 func_800B39B4(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *t = func_8009C9F4(a0, func_800B3914);
    s16 d;
    *(u8 **)(t + 0xC) = a0;
    *(s16 *)(t + 0x10) = q[1];
    *(s16 *)(t + 0x12) = q[2];
    d = q[3];
    *(s16 *)(t + 0x14) = d;
    *(s16 *)(t + 0x16) = *(s16 *)(t + 0x12) / d;
    return 4;
}

typedef struct { s32 x, y, z, pad; } V3A54;
void func_800B3A54(u8 *a0) {
    V3A54 b;
    V3A54 a;
    func_8009789C(*(s32 *)(a0 + 0x10), *(s16 *)(a0 + 0x16), (s32)&a);
    *(s16 *)(a0 + 0x20) = a.x - (*(s32 *)(*(u8 **)(a0 + 0x10) + 0x84) >> 12);
    *(s16 *)(a0 + 0x22) = a.y - (*(s32 *)(*(u8 **)(a0 + 0x10) + 0x88) >> 12);
    *(s16 *)(a0 + 0x24) = a.z - (*(s32 *)(*(u8 **)(a0 + 0x10) + 0x8C) >> 12);
    func_8009789C(*(s32 *)(a0 + 0xC), *(s16 *)(a0 + 0x14), (s32)&b);
    *(s32 *)(*(u8 **)(a0 + 0x10) + 0x84) = (b.x - *(s16 *)(a0 + 0x20)) << 12;
    *(s32 *)(*(u8 **)(a0 + 0x10) + 0x88) = (b.y - *(s16 *)(a0 + 0x22)) << 12;
    *(s32 *)(*(u8 **)(a0 + 0x10) + 0x8C) = (b.z - *(s16 *)(a0 + 0x24)) << 12;
    if (*(s16 *)(a0 + 0x18) != 0) {
        *(s16 *)(a0 + 0x18) -= D_1F800010_u;
        if (*(s16 *)(a0 + 0x18) <= 0) func_8009CA60(a0);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800AA9DC", func_800B3B64);

extern u16 D_800D9B20[];
s32 func_800B3D0C(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    D_800D9B20[0] = *(u16 *)(q + 2);
    D_800D9B20[1] = *(u16 *)(q + 4);
    D_800D9B20[2] = *(u16 *)(q + 6);
    D_800D9B20[3] = *(u16 *)(q + 8);
    return 5;
}

extern u16 D_800D9B28[];
s32 func_800B3D4C(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    D_800D9B28[0] = *(u16 *)(q + 2);
    D_800D9B28[1] = *(u16 *)(q + 4);
    D_800D9B28[2] = *(u16 *)(q + 6);
    D_800D9B28[3] = *(u16 *)(q + 8);
    return 5;
}

extern s32 D_800A0F00[];
typedef struct { s16 x, y; } SB30;
extern SB30 D_800D9B30;
void func_80095A50(u8 *, s16 *, s16 *);
s32 func_800B3D8C(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x108);
    u8 **o;
    s16 r[2];
    if (*(s16 *)(q + 2) == 0) o = (u8 **)func_8003099C_(*(s16 *)(q + 4));
    else o = func_800309D0(*(s16 *)(q + 4));
    if (!o) func_80029DD8(D_800A3364, "kz_TimRectTo()", D_800A0F00[*(s16 *)(q + 2)]);
    func_80095A50(*o, &r[0], &r[1]);
    D_800D9B30.x = q[6] + r[0];
    D_800D9B30.y = q[7] + r[1];
    return 4;
}
