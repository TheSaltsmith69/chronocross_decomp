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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B1CC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B2D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B34C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B3D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B3E0);

extern u8 D_8006AF2C;
extern s32 D_8006AF34;
extern s32 D_8006AF30;
void func_8002B400(void) {
    D_8006AF2C = 0;
    D_8006AF34 = 0;
    D_8006AF30 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B41C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B434);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002B484);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BB70);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BC6C);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BE9C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BF30);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002BFC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C130);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C1B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C1BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C1C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C334);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C460);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C60C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002C9C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CA14);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CA80);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CAF4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CB18);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CB3C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CB60);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CB84);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CBA8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CBCC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CBF0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CC14);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CCC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CD14);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CD70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002CEB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E238);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E284);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E2EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E430);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E574);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E5B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E660);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E768);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002E948);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002EB28);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002ED00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002EE4C);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002F05C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002F078);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002B070", func_8002F53C);
