#include "common.h"

void func_80019FE4(void);
void func_800221E0(void);
void func_8001A0E0(u8 *, u8 *, s32);
void func_8001BF6C(s32, s32, s32);

INCLUDE_ASM("asm/nonmatchings/game/main", main);

void func_8001A994(void) {
    func_80019FE4();
    func_800221E0();
}

extern u8 D_800623EC[];
extern u8 D_800A3AA8[];
extern u8 D_8006CE20[];
extern u8 D_800A343C[];
void func_8001A9BC(void) {
    func_8001A0E0(D_800623EC, D_800A3AA8, 3);
    func_8001A0E0(D_8006CE20, D_800A343C, 5);
}

extern s32 D_8007252C;
void func_8001AA04(s32 arg0) {
    D_8007252C = arg0 + 1;
}

extern u8 D_8006B43E;
extern s32 D_8007257C;
extern s32 D_800724DC;
extern u8 D_800724D9;
void func_8001AA14(s32 arg0) {
    D_8006B43E = 0;
    D_800724DC = D_8007257C;
    D_8007257C = 1;
    func_8001BF6C(arg0, 0, 0);
    D_800724D9 = 1;
}

extern s32 D_8007E6E8;
extern u8 D_8006417C;
extern s16 D_80070EDA;
extern u16 D_8007E7AA;
void func_8004A518(s32);
void func_8001AA64(void) {
    func_8004A518(1);
    D_8006B43E = 1;
    D_800724D9 = 0;
    D_8007E6E8 = 0x216;
    D_8006417C = 0;
    D_80070EDA = 0;
    D_8007E7AA = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AAB8);

void func_8001AB08(s32 arg0) {
    s32 var;
    if (!(D_8007E7AA & 0x10)) {
        var = 0x17;
        if (arg0 == 0) {
            var = 0x16;
        }
        func_8001AA14(var);
        D_800724D9 = 0;
    }
}

s32 func_8001B8B0(s32);
s32 func_8001AB50(void) {
    if (D_8007E7AA & 0x10) {
        return 1;
    }
    if (func_8001B8B0(0) != 0) {
        return 0;
    }
    D_8007257C = D_800724DC;
    return 1;
}

extern u8 D_800623F8[];
extern u8 D_80062400[];
extern u8 D_800AAA20[];
void func_8001ABA4(void) {
    func_8001A0E0(D_800623F8, D_800AAA20, 2);
    func_8001A0E0(D_80062400, D_800AAA20, 10);
}

extern u8 D_8007E7B8;
extern s16 D_8007E6A0;
extern s16 D_8007E6A8;
extern s32 D_8007E6E8;
extern s32 D_800724E8;
extern s32 D_8007E698;
extern s32 D_8007E6B0;
extern s32 D_8007E6F0[];

void func_8001ABF0(void) {
    if (D_8007E7B8 == 0) {
        func_8004582C(5);
        D_8007E6A0 = -1;
        D_8007E6A8 = D_8007E6E8;
        D_800724E8 = func_8003D8F4(func_80044924(D_8007E6E8 * 3 + 0x85), 1, 2);
        D_8007E698 = func_8003D8F4(func_80044924(D_8007E6E8 * 3 + 0x83), 1, 2);
        D_8007E6B0 = func_8003D8F4(func_80044924(D_8007E6E8 * 3 + 0x84), 1, 2);
        D_8007E6F0[3] = D_8007E6B0;
        D_8007E6F0[6] = 0;
        D_8007E6F0[7] = 0;
        D_8007E6F0[0] = D_8007E6E8 * 3 + 0x83;
        D_8007E6F0[1] = D_8007E698;
        D_8007E6F0[2] = D_8007E6E8 * 3 + 0x84;
        D_8007E6F0[4] = D_8007E6E8 * 3 + 0x85;
        D_8007E6F0[5] = D_800724E8;
        func_80046698(D_8007E6F0, 0);
        D_8007E7B8 = 1;
    }
}

typedef struct { s16 x, y, w, h; } RECT_8001AD30;
typedef struct { u8 pad0[0x2D]; u8 unk2D; u8 pad2E[0xCC - 0x2E]; } Chr8001AD30;
typedef struct { s32 id; s32 buf; } Req8001AD30;
extern Chr8001AD30 D_8006EBC8_c[] asm("D_8006EBC8");
extern u8 D_8006EBC8[];
extern u8 D_8007E7A8;
extern u8 D_800724D8;
extern u8 D_8006B3F4;
extern s32 D_8007E6E8;
extern s32 D_800724F0[];
extern s32 D_8007E6C0[];
extern s32 D_8007E7A4;
extern s32 D_80072578;
extern s32 D_80072518;
extern s32 D_8007E6D8[];
extern s32 D_8007E778[];
extern Req8001AD30 D_8007E7D8[];
int DrawSync();
int VSync();
int SetDispMask();
int ClearImage();
int func_80046698();
s32 func_8003D8F4();
s32 func_80044924();
void func_8004582C(s32);
void func_8001AD30(void) {
    RECT_8001AD30 r;
    s32 i;
    s32 id;
    s32 size;
    if (D_8007E7A8 != 0) {
        return;
    }
    if (D_800724D8 == 0) {
        DrawSync(0);
        VSync(0);
        SetDispMask(0);
        r.x = 0;
        r.y = 0;
        r.w = 0x280;
        r.h = 0x200;
        ClearImage(&r, 0, 0, 0);
        DrawSync(0);
    }
    if (D_8006B3F4 == 0 && D_800724D8 == 0) {
        D_800724D8 = 1;
        D_8007E6E8 = 8;
        for (i = 0; i < 3; i++) {
            D_8006EBC8[0x2DE4 + i] = D_8007E6C0[i] = D_800724F0[i] = 0xFF;
        }
    }
    for (i = 0; i < 3; i++) {
        D_8007E6C0[i] = D_8006EBC8[0x2DE4 + i];
    }
    func_8004582C(5);
    D_8007E7D8[0].id = 0x715;
    D_8007E7D8[0].buf = D_80072578 = func_8003D8F4(func_80044924(0x715), 1, 2);
    D_8007E7D8[1].id = D_8007E7A4 + 0x725;
    D_8007E7D8[1].buf = D_80072518 = func_8003D8F4(func_80044924(D_8007E7A4 + 0x725), 1, 2);
    for (i = 0; i < 3; i++) {
        if (D_8007E6C0[i] == 0xFF) {
            break;
        }
        D_8007E7D8[2 + i * 2].id = D_8006EBC8_c[D_8007E6C0[i]].unk2D * 2 + 2;
        D_8007E7D8[2 + i * 2].buf = D_8007E6D8[i] = func_8003D8F4(0x8800, 1, 2);
        size = func_80044924(D_8006EBC8_c[D_8007E6C0[i]].unk2D * 2 + 3);
        D_8007E7D8[3 + i * 2].id = D_8006EBC8_c[D_8007E6C0[i]].unk2D * 2 + 3;
        D_8007E7D8[3 + i * 2].buf = D_8007E778[i] = func_8003D8F4(size, 1, 2);
    }
    D_8007E7D8[2 + i * 2].buf = 0;
    D_8007E7D8[2 + i * 2].id = 0;
    func_80046698(D_8007E7D8, 0);
    D_8007E7A8 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B058);

extern u16 D_8007E69E;
void func_8001B0F8(s32 arg0) {
    D_8006B43E = 0;
    D_8007E69E |= 1 << arg0;
}

void func_8001B11C(s32 arg0) {
    D_8007E69E &= ~(1 << arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B13C);

void func_8001B4FC(void) {
}

void func_8001B504(void) {
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Unk80072500;
extern Unk80072500 D_80072500[];
void func_8001B50C(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        D_80072500[i].unk0 = -1;
        D_80072500[i].unk4 = 0;
    }
}

extern u8 D_8006EBC8[];
void func_8001B50C(void);
void func_8001B53C(void) {
    func_8001B50C();
    D_8006EBC8[0x2DE5] = 0xFF;
    D_8006EBC8[0x2DE6] = 0xFF;
    *(s32 *)(D_8006EBC8 + 0x2714) = 0;
    *(s32 *)(D_8006EBC8 + 0x2710) = 0;
    D_8006EBC8[0x2DE4] = 0;
    *(s32 *)(D_8006EBC8 + 0x2DD8) = 1;
    *(s32 *)(D_8006EBC8 + 0x2DDC) = 0;
    *(s32 *)(D_8006EBC8 + 0x3794) = 1;
    *(s32 *)(D_8006EBC8 + 0x3798) = 0;
    *(s32 *)(D_8006EBC8 + 0x37A0) = 0;
    *(s32 *)(D_8006EBC8 + 0x379C) = 0;
    *(s32 *)(D_8006EBC8 + 0x37BC) = 0;
    *(s32 *)(D_8006EBC8 + 0x37C0) = 0;
}

typedef struct {
    u8 pad0[0x2310];
    s16 unk2310[0x1E8];
    u8 pad26E0[0x37C4 - 0x26E0];
    s16 unk37C4;
} Unk8006EBC8_1B5A0;
extern s32 D_800724F0[];
extern s32 D_8007E6C0[];
extern u8 D_8007E69C;
extern s32 D_8007E7B4;

void func_8001B5A0(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        D_800724F0[i] = 0xFF;
        D_8007E6C0[i] = 0xFF;
    }
    func_8001B53C();
    ((Unk8006EBC8_1B5A0 *)D_8006EBC8)->unk37C4 = 0x203;
    D_8007E69C = 0;
    for (i = 0x1E7; i >= 0; i--) {
        ((Unk8006EBC8_1B5A0 *)D_8006EBC8)->unk2310[i] = 0;
    }
    D_8007E7B4 = rand() & 0x1FF;
}

extern u8 D_80072580[];
extern u8 D_8007E7B0;
extern s16 D_8007E6A8;
extern u8 D_8006417C;
extern s32 D_8007E6E8;
extern u8 D_800724D8;
extern u8 D_8007E7A8;
extern u8 D_8007E7B8;
extern s32 D_8007252C;
extern s32 D_8007E6AC;
extern u16 D_8007E7AA;
extern s32 D_8007E6E4;
extern s32 D_8007251C;
extern s32 D_8007E6CC;
extern s32 D_8007E7A4;
extern s32 D_80076690;
extern u8 D_800724D9;
extern u8 D_800724E5;
extern u8 D_8007E7B9;
extern s32 D_800724FC;
extern s32 D_8007E7AC;
extern s32 D_8007257C;
extern s16 D_8007E6A0;
extern s32 D_80072570;
extern s32 D_8007E774;
extern s32 D_8007E6B8;
extern s32 D_80076680;
extern s32 D_8007E784;
extern u8 D_8006B47A;
extern s32 D_80076684;
extern u8 D_8006EBC8[];
void func_8001B5A0(void);
void func_8004582C(s32);
void func_80045F14(s32, void *, s32);
void func_80044EE0(s32);
typedef struct {
    u8 pad0[0x2352];
    s16 unk2352;
    u8 pad2354[0x37C8 - 0x2354];
    s32 unk37C8;
    s32 unk37CC;
} G8001B638;
extern G8001B638 D_8006EBC8_g asm("D_8006EBC8");
void func_8001B638(void) {
    func_8001B5A0();
    func_8004582C(5);
    func_80045F14(0x71E, D_80072580, 0);
    func_80044EE0(0);
    D_8007E7B0 = 1;
    D_8007E6A8 = -1;
    D_8006417C = 0;
    D_8007E6E8 = 0;
    D_800724D8 = 0;
    D_8007E7A8 = 0;
    D_8007E7B8 = 0;
    D_8007252C = 0;
    D_8007E6AC = 0;
    D_8007E7AA = 0;
    D_8007E6E4 = 0;
    D_8007251C = 0;
    D_8007E6CC = 0;
    D_8007E7A4 = 0;
    D_80076690 = 0;
    D_8006EBC8_g.unk37CC = 0;
    D_8006EBC8_g.unk37C8 = 0;
    D_8006EBC8_g.unk2352 = D_8006B47A - 1;
    D_800724D9 = 0;
    D_800724E5 = 0;
    D_8007E7B9 = 0;
    D_800724FC = 0;
    D_8007E7AC = 0;
    D_8007257C = 0;
    D_8007E6A0 = 0;
    D_80072570 = 0xFF;
    D_8007E774 = -1;
    D_8007E6B8 = -1;
    D_80076680 = -1;
    D_8007E784 = -1;
    D_80076684 = 0;
}

void func_8004582C(s32);
s32 func_8003D9E0(void);
s32 func_80044924(s32);
s32 func_8001B788(s32 arg0) {
    s32 temp;
    func_8004582C(10);
    temp = func_8003D9E0();
    return func_80044924(arg0 * 2 + 3) + 0xE100 >= temp;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B7D4);

s32 func_80044DD4(void);
u8 *func_800479AC(void);
void func_8004ACA0(u8 *, s32, s32);
u16 func_80047E18(u8 *);
s32 func_8001B848(void) {
    s32 busy;
    u8 *p;
    while (1) {
        busy = func_80044DD4();
        p = func_800479AC();
        if (p == NULL) {
            break;
        }
        func_8004ACA0(p, 0x800, 1);
        func_80047E18(p);
    }
    if (busy != 0) {
        return -1;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/main", D_800623EC);

INCLUDE_RODATA("asm/nonmatchings/game/main", D_800623F8);

INCLUDE_RODATA("asm/nonmatchings/game/main", D_80062400);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B8B0);

extern s32 D_80076688;
s32 func_8001BF94(s32, s32, s32);
void func_8001BF48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_80076688 = arg3;
    func_8001BF94(arg0, arg1, arg2);
}

void func_8001BF6C(s32 arg0, s32 arg1, s32 arg2) {
    D_80076688 = 0x7F;
    func_8001BF94(arg0, arg1, arg2);
}

extern s32 D_8007E774;
extern s32 D_80076684;
extern s32 D_8007E6B8;
extern s32 D_8007E784;
extern s32 D_80076680;
extern s32 D_80076688;
extern s32 D_8007E6BC;
extern s32 D_80076690;
extern u8 D_800724D9;

s32 func_8001BF94(s32 arg0, s32 arg1, s32 arg2) {
    s32 id;
    if (arg0 == 0xFF) {
        if (D_8007E774 != -1) {
            func_8004A058(D_80076684);
        }
        D_8007E6B8 = -1;
        D_8007E784 = -1;
        D_8007E774 = -1;
        D_80076680 = -1;
        return 0;
    }
    id = arg0;
    if (D_8007E784 != -1) {
        return -1;
    }
    if (D_80076680 == arg0) {
        func_8004A848(0, D_80076688);
        return 0;
    }
    D_80076680 = arg0;
    if (D_8007E774 != -1) {
        D_8007E6BC = 1;
    } else {
        D_8007E6BC = 0;
    }
    D_8007E774 = id;
    D_8007E6B8 = arg0;
    D_8007E784 = 0;
    D_80076690 = 0x10;
    D_800724D9 = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C09C);

extern u8 D_80062444[];
extern u8 D_80062468[];
void func_80019550();
void func_80019510();
void func_8001C0E4(void) {
    func_8001A0E0(D_80062444, (u8 *)func_80019550, 9);
    func_8001A0E0(D_80062468, (u8 *)func_80019510, 8);
}

void InitCARD(s32);
void func_800190E4(void);
void func_80018D34(void);
void ChangeClearPAD(s32);
void func_8001C12C(void) {
    InitCARD(0);
    func_800190E4();
    func_80018D34();
    ChangeClearPAD(0);
}

void func_8001C164(void) {
    ChangeClearPAD(0);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C184);

void func_8001C244(u8 *arg0, u8 *arg1, u8 *arg2) {
    arg0[0] = (arg1[0] * arg2[0]) >> 7;
    arg0[1] = (arg1[1] * arg2[1]) >> 7;
    arg0[2] = (arg1[2] * arg2[2]) >> 7;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C29C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C31C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C388);

INCLUDE_RODATA("asm/nonmatchings/game/main", D_80062444);

INCLUDE_RODATA("asm/nonmatchings/game/main", D_80062468);

typedef struct {
    u16 type;
    u16 id;
    s32 data;
} E4A0;
typedef struct {
    s32 n;
    E4A0 e[1];
} L4A0;
typedef struct {
    L4A0 *u0;
    s32 u4;
    s32 u8;
    u8 padC[4];
    s32 u10;
    u16 u14;
    u16 u16;
    u8 pad18[4];
    u8 u1C;
    u8 u1D;
    u8 u1E;
    u8 pad1F[7];
    s16 u26;
} O4A0;
extern u32 D_80064190;
extern s32 D_80064194;
extern s32 D_8007E858;
extern s32 D_8007E85C;
extern s32 D_8007E860;
extern s32 D_8007E864;
extern s32 D_8007E868;
extern s32 D_8007E874;
extern s32 D_8007E878;
extern s32 D_800A120C;
extern s32 D_8007E834;
extern s32 D_8007E828;
extern s32 D_8007E830;
extern s32 D_8007E880;
extern s32 D_8007E884;
void func_80090D64(O4A0 *, s32);
void func_80090608(O4A0 *, s32);
void func_8001C388(u16, u16, s16, u32);
void func_8001C918(u16, s32, s32, u8, u8, s32, s32, s32, s16);
void func_8001CF00(u16, s32, s32, u8, u8, s32, s32, s32, s16);
void func_8001D558(u16, s32, s32, s32, u16, u8, s32, s32, s32, s16);
void func_8001DCC4(u16, s32, s32, s32, u16, u8, s32, s32, s32, s16);
void func_8001E55C(u16, s32, s32, s32, s32, s16);
void func_8001EA4C(u16, s32, s32, s32, s32, s16);
void func_8001EFA8(u16, s32, s32, s32, s32, s16);
void func_8001F274(u16, s32, s32, s32, s32, s32, s16);
void func_8001F958(u16, s32, s32, s32, s32, s32, s16);
void func_8001C4A0(u32 flags, O4A0 *a, O4A0 *b, s16 t, s32 p4, u16 p5, s16 p6, s32 p7, s32 p8) {
    s32 *pa;
    s32 *pb;
    u16 c;
    s32 col;
    u32 t5;
    u32 tmp;
    s32 n;
    pa = (s32 *)a->u0;
    D_80064190 = flags;
    pb = pa;
    if (flags & 2) {
        pb = (s32 *)b->u0;
    }
    t5 = p5 & 0x7F;
    c = t5;
    p6 &= 0x7F;
    if (t > 0x1000) {
        t = 0x1000;
    }
    D_8007E858 = 0x1000 - t;
    D_8007E85C = t;
    D_8007E860 = t5;
    D_8007E864 = p6;
    D_8007E868 = a->u26;
    tmp = a->u1C | (a->u1D << 8) | (a->u1E << 16);
    D_8007E874 = a->u4;
    D_8007E878 = b->u4;
    D_800A120C = 6;
    D_8007E834 = tmp;
    col = tmp;
    if (flags & 0xC) {
        if (a->u10 == 0) {
            func_80090D64(a, 0);
        }
        if (a->u8 == 0) {
            func_80090608(a, 0);
        }
    }
    if ((D_80064190 & 2) && b != NULL && (D_80064190 & 0xC)) {
        if (b->u10 == 0) {
            func_80090D64(b, 0);
        }
        if (b->u8 == 0) {
            func_80090608(b, 0);
        }
        D_8007E828 = b->u10;
        D_8007E830 = b->u8;
    }
    D_8007E880 = a->u10;
    D_8007E884 = a->u8;
    D_8007E828 = b->u10;
    D_8007E830 = b->u8;
    if (D_80064190 & 2) {
        func_8001C388(a->u14, a->u16, t, D_80064190);
    }
    D_80064194 = 0;
    n = *pa++;
    pb++;
    for (; n != 0; pa += 2, n--, pb += 2) {
        switch (((E4A0 *)pa)->type) {
        case 0x24:
            func_8001C918(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, p4, c, p6, p7, p8, col, t);
            break;
        case 0x2C:
            func_8001CF00(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, p4, c, p6, p7, p8, col, t);
            break;
        case 0x20:
            func_8001E55C(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, p4, p8, col, t);
            break;
        case 0x28:
            func_8001EA4C(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, p4, p8, col, t);
            break;
        case 0x30:
            func_8001F274(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, pb[1], p4, p8, col, t);
            break;
        case 0x38:
            if (D_80064190 & 0x400) {
                func_8001EFA8(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, p4, p8, col, t);
            } else {
                func_8001F958(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, pb[1], p4, p8, col, t);
            }
            break;
        case 0x34:
            func_8001D558(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, pb[1], p4, c, p6, p7, p8, col, t);
            break;
        case 0x3C:
            func_8001DCC4(((E4A0 *)pa)->id, ((E4A0 *)pa)->data, pb[1], p4, c, p6, p7, p8, col, t);
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C918);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001CF00);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001D558);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001DCC4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001E55C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001EA4C);

INCLUDE_RODATA("asm/nonmatchings/game/main", D_800624F0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001EFA8);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001F274);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001F958);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800201C4);

extern s32 D_80064198;
void func_80020478(void) {
    D_80064198 = 1;
}

void func_80020488(void) {
    D_80064198 = 0;
}

extern s32 D_8007E89C;
extern s32 D_8007E894;
extern s32 D_8006419C;
void func_80020494(s32 arg0, s32 arg1) {
    D_8007E89C = arg0;
    D_8007E894 = arg1;
    D_8006419C = 1;
}

void func_800204B4(void) {
    D_8006419C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_800204C0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800205B0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8002096C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020D30);

extern u8 D_8006B479;
void func_80021518(void);
void func_80020EDC(void);
void func_80020E94(void) {
    if (D_8006B479 == 0 || D_8006B479 == 2) {
        func_80021518();
    } else {
        func_80020EDC();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020EDC);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021518);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021B54);

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    s32 unk18;
} Unk8007E8A8;
extern Unk8007E8A8 D_8007E8A8[];
void func_80021C0C(s32 arg0) {
    if (arg0 < 3) {
        D_8007E8A8[arg0].unk14 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021C38);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021E9C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022128);

extern s32 D_80071C78;
extern s32 D_8007E7A4;
extern s32 D_800641A4;
extern s32 D_800641A8;
extern s32 D_800641AC;
extern s32 D_800641B0;
extern s32 D_800641C4;
extern s32 D_8006B488;
void func_800221E0(void) {
    D_80071C78 = 2;
    D_8007E7A4 = 0;
    D_800641A4 = 0x76543201;
    D_800641A8 = 0x76543201;
    D_800641AC = 0x3210;
    D_800641B0 = 0x3210;
    D_800641C4 = 1;
    D_8006B488 = 0;
}

extern s32 D_800641A4;
extern s32 D_800641A8;
extern s32 D_800641AC;
extern s32 D_800641B0;

u32 func_80022238(s32 port, s32 idx) {
    u32 map;
    if (D_800641C4 == 0) {
        switch (port) {
            case 0:
                map = D_800641A4;
                break;
            case 1:
                map = D_800641AC;
                break;
            case 2:
                map = D_800641A8;
                break;
            case 3:
                map = D_800641B0;
                break;
        }
    } else {
        switch (port) {
            case 0:
            case 2:
                map = 0x76543201;
                break;
            case 1:
            case 3:
                map = 0x3210;
                break;
        }
    }
    return (map >> (idx * 4)) & 0xF;
}

extern s32 D_800641C8[];

void func_8002232C(u16 *pad) {
    s32 port;
    u16 out;
    s32 i;
    if (D_8006B479 == 0 || D_8006B479 == 2) {
        port = 0;
    } else {
        port = 2;
    }
    out = *pad & 0xF000;
    if (*pad & 0x800) {
        out = (*pad & 0xF000) | 0x800;
    }
    if (*pad & 0x100) {
        out |= 0x100;
    }
    if (func_80022238(port | 1, 2) == 2) {
        if (*pad & 0x200) {
            out |= 0x200;
        }
        if (*pad & 0x400) {
            out |= 0x400;
        }
    } else {
        if (*pad & 0x200) {
            out |= 0x400;
        }
        if (*pad & 0x400) {
            out |= 0x200;
        }
    }
    for (i = 0; i < 8; i++) {
        if (*pad & D_800641C8[func_80022238(port, i)]) {
            out |= (u16)D_800641C8[i];
        }
    }
    *pad = out;
}

extern s32 D_800641C0;

u16 func_80022474(u16 arg0) {
    u16 pad;
    pad = arg0;
    if (D_800641C0 == 0) {
        func_8002232C(&pad);
    }
    if (D_8006B479 == 2 && D_800641C0 == 0) {
        if (pad & 0x200) {
            pad = (pad | 0x20) & ~0x200;
        }
        if (pad & 0x400) {
            pad = (pad | 0x40) & ~0x400;
        }
    }
    return pad;
}

void func_80022508(void) {
}

void func_80022510(u8 *arg0) {
    s32 port;
    u8 t;
    if (D_8006B479 == 0 || D_8006B479 == 2) {
        port = 1;
    } else {
        port = 3;
    }
    if (D_800641C4 == 0 && D_800641C0 == 0 && func_80022238(port, 0) == 1) {
        t = arg0[0x18];
        arg0[0x18] = arg0[0x16];
        arg0[0x16] = t;
        t = arg0[0x19];
        arg0[0x19] = arg0[0x17];
        arg0[0x17] = t;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_800225A4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800225BC);
