#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
} Unk8002BC2C;

typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR_8002B070;

void func_8002B070(SVECTOR_8002B070 *v, s32 n, SVECTOR_8002B070 *center, SVECTOR_8002B070 *max, SVECTOR_8002B070 *min) {
    s32 i;
    max->vx = max->vy = max->vz = -0x7FFF;
    min->vx = min->vy = min->vz = 0x7FFF;
    for (i = 0; i != n; i++) {
        if (max->vx < v[i].vx) {
            max->vx = v[i].vx;
        }
        if (max->vy < v[i].vy) {
            max->vy = v[i].vy;
        }
        if (max->vz < v[i].vz) {
            max->vz = v[i].vz;
        }
        if (min->vx > v[i].vx) {
            min->vx = v[i].vx;
        }
        if (min->vy > v[i].vy) {
            min->vy = v[i].vy;
        }
        if (min->vz > v[i].vz) {
            min->vz = v[i].vz;
        }
    }
    center->vx = (max->vx + min->vx) / 2;
    center->vy = (max->vy + min->vy) / 2;
    center->vz = (max->vz + min->vz) / 2;
}

s32 func_80025044(s32);
s32 func_80025114(s32);

s32 func_8002B1CC(s32 a, s32 mode) {
    s32 v;
    if ((a >> 12) & 1) {
        a = 0x1000 - (a & 0xFFF);
    } else {
        a &= 0xFFF;
    }
    switch (mode) {
    case 1:
        v = func_80025044(a / 4);
        break;
    case 2:
        v = 0x1000 - func_80025114(a / 4);
        break;
    case 3:
        if (a > 0x800) {
            v = 0x1000 - (func_80025044(a / 2) >> 1);
        } else {
            v = func_80025044(a / 2) >> 1;
        }
        break;
    case 4:
        v = 0x800 - func_80025114(a / 2) / 2;
        break;
    case 0:
    default:
        v = a;
        break;
    }
    return v;
}

void *f_29B50_a(s32) asm("func_80029B50");
void f_3F884_a(void *, s32) asm("func_8003F884");
void f_41F94_a(void *) asm("func_80041F94");
s32 f_29D44_a(s32, s32) asm("func_80029D44");
void f_41EB4_a(void *, s32) asm("func_80041EB4");
void f_40DD0_a(void *) asm("func_80040DD0");
extern s32 D_803DE7B4_w asm("D_803DE7B4");
typedef struct {
    s32 unk0;
    s32 unk4;
    u32 lo : 6;
    u32 rest : 26;
} Bf2B2D0;
Bf2B2D0 *func_8002B2D0(void) {
    Bf2B2D0 *p = f_29B50_a(0x20);
    f_3F884_a(p, 0x20);
    f_41F94_a(p);
    p->lo = 0x11;
    p->unk4 = f_29D44_a(0x11, 0);
    f_41EB4_a(p, D_803DE7B4_w);
    f_40DD0_a(p);
    return p;
}

INCLUDE_RODATA("asm/nonmatchings/game/unk_8002B070", D_80062B04);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B34C);

extern s32 D_8006AF3C_t asm("D_8006AF3C");
void func_8002B3D4(s32 arg0) {
    D_8006AF3C_t = arg0;
}

void f_B5864_t(void) asm("func_800B5864");
void func_8002B3E0(void) {
    f_B5864_t();
}

extern u8 D_8006AF2C;
extern s32 D_8006AF34;
extern s32 D_8006AF30;
void func_8002B400(void) {
    D_8006AF2C = 0;
    D_8006AF34 = 0;
    D_8006AF30 = 0;
}

extern s32 D_8006AF34_t asm("D_8006AF34");
void func_8002B41C(void) {
    D_8006AF34_t++;
}

extern s32 D_8006AF34_w asm("D_8006AF34");
extern u8 D_8006AF2C_b asm("D_8006AF2C");
extern char D_80062B04_s[] asm("D_80062B04");
void f_29DD8_a(char *) asm("func_80029DD8");
void func_8002B434(void) {
    s32 v = D_8006AF34_w - 1;
    D_8006AF34_w = v;
    if (v == 0) {
        D_8006AF2C_b = 1;
    } else if (v < 0) {
        f_29DD8_a(D_80062B04_s);
    }
}

extern u8 D_8006B479_b asm("D_8006B479");
void f_2C130_a(void) asm("func_8002C130");
void f_AA94C_a(void) asm("func_800AA94C");
void f_B6188_a(void) asm("func_800B6188");
void func_8002B484(void) {
    if (D_8006B479_b == 0) {
        f_2C130_a();
    } else {
        f_AA94C_a();
        f_B6188_a();
    }
}

extern u8 D_8006AF2C;
extern s32 D_8006AF34;
extern u8 D_8006AF38;
extern void (*D_8006AF3C)(void);

void func_8002B4C8(void) {
    s32 i;
    s32 *p;
    s32 q;
    if (D_8006AF2C != 0 && D_8006AF34 == 0) {
        i = 0;
        if (*(s16 *)func_80030968() == 1) {
            while ((p = (s32 *)func_80030934(i)) != NULL) {
                q = p[0];
                if ((p[5] & 1) && *(s32 *)(q + 0x108) != 0) {
                    return;
                }
                i++;
            }
        } else {
            while ((p = (s32 *)func_80030934(i)) != NULL) {
                if (*(s32 *)(p[0] + 0x108) != 0) {
                    return;
                }
                i++;
            }
        }
        if (D_8006AF38 == 0 && D_8006AF3C != NULL) {
            D_8006AF3C();
            D_8006AF2C = 0;
        }
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unk803D2A68;
extern u8 D_8006B3F4;
extern u8 D_8007EAA8[];
extern u8 D_8007E9E8[];
extern u32 D_8006B3E8;
extern u8 D_8006AF44[];
extern s16 D_8007EE08[];
extern Unk803D2A68 D_803D2A68[];
extern s16 D_803D2A58[];
extern s32 D_803D2A5C;

void func_8002B5C0(void) {
    s32 i;
    if (D_8006B3F4 != 0) {
        func_803153EC(D_8007EAA8, D_8007EAA8 + 0x24);
    } else {
        PadInitDirect(D_8007EAA8, D_8007EAA8 + 0x24);
    }
    D_8006B3E8 = 0;
    D_8007EAA8[0] = 0xFF;
    D_8007EAA8[0x24] = 0xFF;
    D_8007E9E8[0x15] = 0;
    D_8007E9E8[0x35] = 0;
    PadSetAct(0, D_8007E9E8 + 0x1A, 2);
    PadStartCom();
    PadSetActAlign(0, D_8006AF44);
    D_8007EE08[0] = 0;
    D_8007EE08[1] = 0;
    if (D_8006B3F4 != 0) {
        for (i = 0; i < 16; i++) {
            D_803D2A68[i].unk0 = -1;
            D_803D2A68[i].unk4 = 0;
            D_803D2A68[i].unk8 = 0;
        }
        D_803D2A58[1] = 0;
        D_803D2A58[0] = 0;
        D_803D2A5C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B6C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B8C0);

extern u8 D_8006B43D;
extern s16 D_1F800010;
void func_8002BB1C(Unk8002BC2C *arg0, s32 arg1, s32 arg2) {
    s32 a = arg0->unk1C;
    s32 b = arg0->unk1D;
    if (D_8006B43D != 0 && D_1F800010 != 0) {
        a += arg1;
        if (a != 0) {
            a = 1;
        }
        b += arg2;
        arg0->unk1C = a;
        if ((u32)b > 0xFF) {
            b = 0xFF;
        }
        arg0->unk1D = b;
    }
}

extern u8 D_8006B43D_t asm("D_8006B43D");
void func_8002BB70(u8 arg0) {
    D_8006B43D_t = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BB7C);

void func_8002BC2C(Unk8002BC2C *arg0) {
    arg0->unk1C = 0;
    arg0->unk1D = 0;
    arg0->unk1A = 0;
    arg0->unk1B = 0;
    arg0->unk19 = 0;
    arg0->unk18 = 0;
    arg0->unk17 = 0;
    arg0->unk16 = 0;
    arg0->unk14 = 0;
    arg0->unk10 = 0;
    arg0->unkC = 0;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk2 = 0;
    arg0->unk6 = 0;
}

extern u8 D_8007EAF8_t asm("D_8007EAF8");
extern u8 D_8006AF50_t asm("D_8006AF50");
void func_8002BC6C(void) {
    if (D_8007EAF8_t == 0) {
        D_8006AF50_t = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BC90);

extern s16 D_8006B474;
extern s16 D_8007EE80;
extern u8 D_8006AF50;
extern s32 D_8006AF4C;
extern u8 D_8007EAF8;
extern s32 D_8006AF54;
void func_8002BE30(void) {
    D_8006B474 = 0;
    D_8007EE80 = 0;
    D_8006AF50 = 0;
    D_8006AF4C = 0;
    D_8007EAF8 = 0;
    D_8006AF54 = 0;
}

void func_8002BE64(void) {
    if (D_8007EAF8) {
        ((void (*)(s32, s32))0x801C5E04)(1, 0);
    }
}

void *f_4208C_c(void *, s32, s32) asm("func_8004208C");
void f_3B8C8_c(void *) asm("func_8003B8C8");
void f_3BEC4_c(void *, s32) asm("func_8003BEC4");
void *f_41F6C_cc(void *) asm("func_80041F6C");
s16 *f_30814_c(s32, s32) asm("func_80030814");
void func_8002BE9C(void) {
    void *p = NULL;
    while ((p = f_4208C_c(p, 10, 0)) != NULL) {
        s32 *q = f_41F6C_cc(p);
        if (f_30814_c(q[5], 5)[6] == 0x15) {
            f_3B8C8_c(p);
            f_3BEC4_c(q, 1);
        }
    }
}

void func_8002BF30(void) {
    void *p = NULL;
    while ((p = f_4208C_c(p, 10, 0)) != NULL) {
        s32 *q = f_41F6C_cc(p);
        if (f_30814_c(q[5], 5)[6] == 0x15) {
            f_3B8C8_c(p);
            f_3BEC4_c(q, 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BFC4);

extern void *D_8006AF4C_p asm("D_8006AF4C");
extern u8 D_8006B238_b asm("D_8006B238");
extern s16 D_800D8688_h asm("D_800D8688");
extern u8 D_8007EAF8_b asm("D_8007EAF8");
void f_2E238_a(s32, s32) asm("func_8002E238");
void f_41C0C_a(void *) asm("func_80041C0C");
void f_3D504_h(void *) asm("func_8003D504");
void f_2BF30_a(void) asm("func_8002BF30");
void func_8002C130(void) {
    if (D_8006AF4C_p != NULL) {
        f_2E238_a(2, 0);
        f_41C0C_a(D_8006AF4C_p);
        f_3D504_h(D_8006AF4C_p);
        D_8006AF4C_p = NULL;
        f_3D504_h((void *)0x801C5E00);
        D_8006B238_b = 0;
        D_800D8688_h = 100;
    }
    D_8007EAF8_b = 0;
    f_2BF30_a();
}

extern s32 D_8006AF60_t asm("D_8006AF60");
void func_8002C1B0(s32 arg0) {
    D_8006AF60_t = arg0;
}

void func_8002C1BC(void) {
    D_8006AF60_t = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C1C8);

typedef struct { u8 r, g, b, a; } C2C334;
typedef struct { s16 cur; s16 total; C2C334 from; C2C334 to; } F2C334;
extern s16 D_1F800010_y1 asm("D_1F800010");
void f_33F20_y1(void *) asm("func_80033F20");
void f_3C304_y1(s32, s32, s32) asm("func_8003C304");
void func_8002C334(F2C334 *arg0) {
    C2C334 c;
    if (D_1F800010_y1 != 0) {
        if (arg0->total != 0) {
            c.r = arg0->from.r + (arg0->to.r - arg0->from.r) * arg0->cur / arg0->total;
            c.g = arg0->from.g + (arg0->to.g - arg0->from.g) * arg0->cur / arg0->total;
            c.b = arg0->from.b + (arg0->to.b - arg0->from.b) * arg0->cur / arg0->total;
        }
        arg0->cur += D_1F800010_y1;
        if (arg0->total < arg0->cur) {
            c = arg0->to;
            f_33F20_y1(arg0);
        }
        f_3C304_y1(c.r, c.g, c.b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C460);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C60C);

void *f_3BE00_a(void *, s32) asm("func_8003BE00");
void f_33F20_b(void *) asm("func_80033F20");
void func_8002C9C0(s32 arg0) {
    void *p = NULL;
    while ((p = f_3BE00_a(p, arg0)) != NULL) {
        f_33F20_b(p);
    }
}

void *f_4208C_a(void *, s32, s32) asm("func_8004208C");
void f_3B8C8_a(void *) asm("func_8003B8C8");
void f_3BEC4_a(void *, s32) asm("func_8003BEC4");
void *f_41F6C_ca(void *) asm("func_80041F6C");
void func_8002CA14(s32 arg0) {
    void *p = NULL;
    while ((p = f_4208C_a(p, 10, arg0)) != NULL) {
        f_3B8C8_a(p);
        f_3BEC4_a(f_41F6C_ca(p), 1);
    }
}

void *f_4208C_b(void *, s32, s32) asm("func_8004208C");
void f_3BEC4_b(void *, s32) asm("func_8003BEC4");
void *f_41F6C_cb(void *) asm("func_80041F6C");
void func_8002CA80(s32 arg0) {
    void *p = NULL;
    while ((p = f_4208C_b(p, 10, arg0)) != NULL) {
        s16 *q = f_41F6C_cb(p);
        if (q[3] == 0) {
            f_3BEC4_b(q, 0);
        }
    }
}

void f_2CA14_t(s32) asm("func_8002CA14");
void f_2CA80_t(s32) asm("func_8002CA80");
void func_8002CAF4(void) {
    f_2CA14_t(0x7261656E);
}

void func_8002CB18(void) {
    f_2CA14_t(0x726166);
}

void func_8002CB3C(void) {
    f_2CA14_t(0x676E6972);
}

void func_8002CB60(void) {
    f_2CA14_t(0x666F6F72);
}

void func_8002CB84(void) {
    f_2CA80_t(0x676E6972);
}

void func_8002CBA8(void) {
    f_2CA80_t(0x7261656E);
}

void func_8002CBCC(void) {
    f_2CA80_t(0x726166);
}

void func_8002CBF0(void) {
    f_2CA80_t(0x666F6F72);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CC14);

extern void *D_8006AF58_p asm("D_8006AF58");
void f_3D504_c(void *) asm("func_8003D504");
void f_33F20_c(void *) asm("func_80033F20");
void f_2B434_c(void) asm("func_8002B434");
void func_8002CCC0(void *arg0) {
    if (D_8006AF58_p != NULL) {
        f_3D504_c(D_8006AF58_p);
    }
    D_8006AF58_p = NULL;
    f_33F20_c(arg0);
    f_2B434_c();
}

s32 f_44DD4_a(void *) asm("func_80044DD4");
extern void *D_8006AF58_r asm("D_8006AF58");
void f_3332C_a(void *, s32, s32, s32, s32, s32, s32) asm("func_8003332C");
void f_3B134_a(void *, void *) asm("func_8003B134");
void func_8002CCC0(void *);
void func_8002CD14(void *arg0) {
    if (f_44DD4_a(arg0) == 0) {
        f_3332C_a(D_8006AF58_r, 0, 0, 0, 0, 0, 0);
        f_3B134_a(arg0, func_8002CCC0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CD70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CEB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E238);

u8 *f_3C630_a(s32, void *) asm("func_8003C630");
void func_8002C1C8(void);
void func_8002E284(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p = f_3C630_a(0x10, func_8002C1C8);
    *(u16 *)(p + 4) = 0;
    p[0xC] = arg0;
    p[0xD] = arg1;
    p[0xE] = arg2;
    *(u16 *)(p + 6) = arg4;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E2EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E430);

u8 f_2A040_a(s32) asm("func_8002A040");
void f_2B434_a(void) asm("func_8002B434");
void f_33F20_a(s32) asm("func_80033F20");
void func_8002E574(s32 arg0) {
    if (f_2A040_a(0) == 0) {
        f_2B434_a();
        f_33F20_a(arg0);
    }
}

s32 *f_3099C_e(s32) asm("func_8003099C");
s32 *f_309D0_e(s32) asm("func_800309D0");
s32 f_41F0C_e(s32, s32) asm("func_80041F0C");
void f_2A228_e(s32) asm("func_8002A228");
void f_2B41C_e(void) asm("func_8002B41C");
void *f_3C630_e(s32, void *) asm("func_8003C630");
void f_2E574_e(void *) asm("func_8002E574");
void func_8002E5B8(void) {
    s32 *a = f_3099C_e(0);
    s32 *b = f_309D0_e(0);
    s32 name;
    if (*a == *b && f_41F0C_e(0x10, 0x6E776F) != 0) {
        name = 0x6E776F;
    } else if (f_41F0C_e(0x10, 0x6E69616D) != 0) {
        name = 0x6E69616D;
    } else {
        return;
    }
    f_2A228_e(name);
    f_2B41C_e();
    f_2E574_e(f_3C630_e(8, f_2E574_e));
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E660);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E768);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E948);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002EB28);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002ED00);

void *f_41F6C_e(void *) asm("func_80041F6C");
void f_3D504_e(void *) asm("func_8003D504");
void func_8002EE4C(void *arg0) {
    u32 *p = f_41F6C_e(arg0);
    if ((p[8] >> 5) & 1) {
        if (p[11] != 0) {
            f_3D504_e((void *)p[11]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002EEA0);

typedef struct {
    s32 vx, vy, vz, pad;
} VEC_8002EF9C;
typedef struct {
    s16 vx, vy, vz, pad;
} SVEC_8002EF9C;

void func_8002EF9C(VEC_8002EF9C *a, VEC_8002EF9C *b, s32 *cnt) {
    SVEC_8002EF9C *dst = (SVEC_8002EF9C *)((u8 *)cnt + (*cnt * 8 + 0x14));
    s32 i;
    if (*cnt == 0) {
        dst->vx = a->vx;
        dst->vy = a->vy;
        dst->vz = a->vz;
        dst++;
        dst->vx = b->vx;
        dst->vy = b->vy;
        dst->vz = b->vz;
        (*cnt)++;
    } else {
        for (i = 0; i != 2; i++) {
            (*cnt)++;
            dst++;
            dst->vx = a->vx;
            dst->vy = a->vy;
            dst->vz = a->vz;
            a = b;
        }
    }
}

void func_8002F05C(u8 *arg0) {
    *(u8 **)(arg0 + 0x2C) = arg0 + *(s32 *)(arg0 + 0x30) * 8 + 0x34;
}

typedef struct { s16 vx, vy, vz, pad; } SV_F078;
typedef struct { s32 x, y, z, pad; } V_F078;
extern s32 D_8007EB00;
void func_8002F53C(s32, s32, SV_F078 *, V_F078 *);
void func_8002F078(s32 n, SV_F078 *p, void (*cb)(V_F078 *, V_F078 *, s32), s32 arg) {
    V_F078 a;
    V_F078 b;
    s32 pad[2];
    s32 i;
    s32 k;
    D_8007EB00 = 0;
    if (n < 5) {
        if (n < 3) {
            if (n < 2) {
                return;
            }
            a.x = p[0].vx;
            a.y = p[0].vy;
            a.z = p[0].vz;
            b.x = p[1].vx;
            b.y = p[1].vy;
            b.z = p[1].vz;
            cb(&a, &b, arg);
            return;
        }
        switch (n) {
        case 3:
            p[3].vx = p[2].vx;
            p[3].vy = p[2].vy;
            p[3].vz = p[2].vz;
            p[4].vx = p[2].vx;
            p[4].vy = p[2].vy;
            p[4].vz = p[2].vz;
            break;
        case 4:
            p[4].vx = p[3].vx;
            p[4].vy = p[3].vy;
            p[4].vz = p[3].vz;
            break;
        }
        n = 5;
    }
    k = 0;
    func_8002F53C(0, 0, &p[k], &a);
    for (i = 1; i != 8; i++) {
        if (i & 1) {
            func_8002F53C(0, i, &p[k], &b);
            cb(&a, &b, arg);
        } else {
            func_8002F53C(0, i, &p[k], &a);
            cb(&b, &a, arg);
        }
    }
    if (n >= 6) {
        k = 1;
        func_8002F53C(1, 0, &p[k], &a);
        cb(&b, &a, arg);
        for (i = 1; i != 8; i++) {
            if (i & 1) {
                func_8002F53C(1, i, &p[k], &b);
                cb(&a, &b, arg);
            } else {
                func_8002F53C(1, i, &p[k], &a);
                cb(&b, &a, arg);
            }
        }
    }
    for (k = 2; k < n - 5; k++) {
        func_8002F53C(2, 0, &p[k], &a);
        cb(&b, &a, arg);
        for (i = 1; i != 8; i++) {
            if (i & 1) {
                func_8002F53C(2, i, &p[k], &b);
                cb(&a, &b, arg);
            } else {
                func_8002F53C(2, i, &p[k], &a);
                cb(&b, &a, arg);
            }
        }
    }
    if (n >= 7) {
        k = n - 5;
        func_8002F53C(3, 0, &p[k], &a);
        cb(&b, &a, arg);
        for (i = 1; i != 8; i++) {
            if (i & 1) {
                func_8002F53C(3, i, &p[k], &b);
                cb(&a, &b, arg);
            } else {
                func_8002F53C(3, i, &p[k], &a);
                cb(&b, &a, arg);
            }
        }
    }
    k = n - 4;
    func_8002F53C(4, 0, &p[k], &a);
    cb(&b, &a, arg);
    for (i = 1; i != 8; i++) {
        if (i & 1) {
            func_8002F53C(4, i, &p[k], &b);
            cb(&a, &b, arg);
        } else {
            func_8002F53C(4, i, &p[k], &a);
            cb(&b, &a, arg);
        }
    }
    if (n >= 5) {
        a.x = p[n - 1].vx;
        a.y = p[n - 1].vy;
        a.z = p[n - 1].vz;
        cb(&b, &a, arg);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002F53C);
