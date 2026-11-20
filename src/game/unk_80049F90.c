#include "common.h"

void func_8004B750(void);
s32 func_80049F90(void) {
    func_8004B750();
    return 0;
}

void f_4B840_t(void) asm("func_8004B840");
s32 func_80049FB0(void) {
    f_4B840_t();
    return 0;
}

extern u8 *D_8008BE1C;
extern u8 *D_8008BE24;
extern u8 *D_8008E388;
extern u8 *D_8008BE28;
s32 func_80049FD0(u8 *arg0) {
    s32 r = func_8004B280();
    if (r == 0) {
        u8 *p;
        p = arg0 + 0x10;
        D_8008BE1C = p;
        p = arg0 + 0x410;
        D_8008BE24 = p;
        p = arg0 + 0x610;
        D_8008E388 = p;
        p = arg0 + 0x810;
        D_8008BE28 = p;
    }
    return r;
}

extern s32 D_8008BEE0;
void func_8005134C(s32);
void func_8004A030(s32 arg0) {
    D_8008BEE0 = arg0;
    func_8005134C(0x10);
}

extern s32 D_8008BEE0_t asm("D_8008BEE0");
void f_5134C_u(s32) asm("func_8005134C");
void func_8004A058(s32 arg0) {
    D_8008BEE0_t = arg0;
    f_5134C_u(0x11);
}

extern s32 D_8008BEE0_a[] asm("D_8008BEE0");
void func_8004A080(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1;
    f_5134C_u(0x14);
}

void f_5134C_t(s32) asm("func_8005134C");
void func_8004A0B0(void) {
    f_5134C_t(0x40);
}

extern s32 D_8008ABF8_t asm("D_8008ABF8");
extern s16 D_8008ADB6_t asm("D_8008ADB6");
s32 func_8004A0D0(void) {
    if (D_8008ABF8_t == 0) {
        D_8008ADB6_t = 0;
    }
    return 0;
}

void func_8004A0F0(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0x7F;
    f_5134C_u(0x19);
}

void func_8004A124(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1;
    D_8008BEE0_a[2] = arg2 & 0x7F;
    f_5134C_u(0x1A);
}

void func_8004A15C(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1;
    f_5134C_u(0x12);
}

void func_8004A18C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8008BEE0_a[0] = arg0 & 0x3FF;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2 & 0xFF;
    D_8008BEE0_a[3] = arg3 & 0x7F;
    f_5134C_u(0x20);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A1DC);

void func_8004A26C(s32 arg0, s32 arg1) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1 & 0xFFFFFF;
    func_8005134C(0x21);
}

void func_8004A2A8(s32 arg0) {
    D_8008BEE0_t = arg0 & 0x3FF;
    f_5134C_u(0x30);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A2D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A33C);

extern s32 D_8008BEB0[];
s32 func_8004A3A8(s32 arg0) {
    u32 v = D_8008BEB0[11] & ~0xF;
    D_8008BEB0[11] = v;
    switch (arg0) {
    case -2:
        D_8008BEB0[11] = v | 1;
        break;
    case -1:
        D_8008BEB0[11] = v | 2;
        break;
    case 1:
        D_8008BEB0[11] = v | 4;
        break;
    case 2:
        D_8008BEB0[11] = v | 8;
        break;
    default:
        arg0 = 0;
        break;
    }
    return arg0;
}

void func_8004A428(s32 arg0) {
    if (arg0 == 1) {
        f_5134C_u(0x81);
    } else {
        f_5134C_u(0x80);
    }
}

void func_8004A45C(s32 arg0) {
    D_8008BEE0_t = arg0;
    f_5134C_u(0x90);
}

void func_8004A484(s32 arg0) {
    D_8008BEE0_t = arg0;
    f_5134C_u(0x92);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A4AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004A518);

void func_8004A584(s32 arg0) {
    D_8008BEE0_t = arg0 & 0x7F;
    f_5134C_u(0xA8);
}

void func_8004A5B0(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0x7F;
    f_5134C_u(0xA9);
}

void func_8004A5E4(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2 & 0x7F;
    f_5134C_u(0xA0);
}

void func_8004A628(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2;
    D_8008BEE0_a[3] = arg3 & 0x7F;
    f_5134C_u(0xA1);
}

void func_8004A670(s32 arg0) {
    D_8008BEE0_t = arg0 & 0xFF;
    f_5134C_u(0xAA);
}

void func_8004A69C(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    f_5134C_u(0xAB);
}

void func_8004A6D0(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2 & 0xFF;
    f_5134C_u(0xA2);
}

void func_8004A714(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2;
    D_8008BEE0_a[3] = arg3 & 0xFF;
    f_5134C_u(0xA3);
}

void func_8004A75C(s32 arg0) {
    D_8008BEE0_t = arg0 & 0xFF;
    f_5134C_u(0xAC);
}

void func_8004A788(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    f_5134C_u(0xAD);
}

void func_8004A7BC(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2 & 0xFF;
    f_5134C_u(0xA4);
}

void func_8004A800(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFFFFFF;
    D_8008BEE0_a[2] = arg2;
    D_8008BEE0_a[3] = arg3 & 0xFF;
    f_5134C_u(0xA5);
}

void func_8004A848(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0x7F;
    f_5134C_u(0xC0);
}

void func_8004A87C(s32 arg0, s32 arg1, s32 arg2) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1;
    (&D_8008BEE0)[2] = arg2 & 0x7F;
    func_8005134C(0xC1);
}

void func_8004A8B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1;
    (&D_8008BEE0)[2] = arg2 & 0x7F;
    (&D_8008BEE0)[3] = arg3 & 0x7F;
    func_8005134C(0xC2);
}

void func_8004A8F4(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0x7F;
    f_5134C_u(0xC4);
}

void func_8004A928(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1;
    D_8008BEE0_a[2] = arg2 & 0x7F;
    f_5134C_u(0xC5);
}

void func_8004A960(s32 arg0) {
    D_8008BEE0_t = arg0;
    f_5134C_u(0x70);
}

void func_8004A988(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1;
    f_5134C_u(0x71);
}

void func_8004A9B8(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1;
    D_8008BEE0_a[2] = arg2;
    f_5134C_u(0x72);
}

void func_8004A9EC(s32 arg0) {
    D_8008BEE0_t = arg0 & 0xFF;
    f_5134C_u(0xD0);
}

void func_8004AA18(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    f_5134C_u(0xD1);
}

void func_8004AA4C(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    D_8008BEE0_a[2] = arg2 & 0xFF;
    f_5134C_u(0xD2);
}

void func_8004AA88(s32 arg0) {
    D_8008BEE0_t = arg0 & 0xFF;
    f_5134C_u(0xD4);
}

void func_8004AAB4(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    f_5134C_u(0xD5);
}

void func_8004AAE8(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    D_8008BEE0_a[2] = arg2 & 0xFF;
    f_5134C_u(0xD6);
}

void func_8004AB24(s32 arg0) {
    D_8008BEE0_t = arg0 & 0xFF;
    f_5134C_u(0xD8);
}

void func_8004AB50(s32 arg0, s32 arg1) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    f_5134C_u(0xD9);
}

void func_8004AB84(s32 arg0, s32 arg1, s32 arg2) {
    D_8008BEE0_a[0] = arg0;
    D_8008BEE0_a[1] = arg1 & 0xFF;
    D_8008BEE0_a[2] = arg2 & 0xFF;
    f_5134C_u(0xDA);
}

void func_8004ABC0(void) {
    f_5134C_t(0xF0);
}

void func_8004ABE0(void) {
    f_5134C_t(0xF1);
}

s32 func_8004B3A0(s32, s32);
void func_8004A2A8(s32);
s32 func_8004AC00(s32 arg0, s32 arg1) {
    s32 r;
    do {
        r = func_8004B3A0(arg0, arg1);
    } while (r == 1);
    if (r == -1) {
        func_8004A2A8(0x18);
    }
    return r;
}

extern s32 D_8008BE20;
s32 func_8004AC70(void) {
    return D_8008BE20;
}

extern s32 D_8008E398;
extern s32 D_8008E46C;
s32 func_8004AC80(void) {
    D_8008E46C = 0;
    D_8008E398 |= 1;
    return 0;
}

typedef struct Up8008E468 {
    s32 *dst;
    s32 addr;
    u32 len;
    u32 tlen;
} Up8008E468;
typedef struct Hdr8008BE70 {
    s32 pad[4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Hdr8008BE70;
extern Up8008E468 D_8008E468_f asm("D_8008E468");
extern Hdr8008BE70 D_8008BE70_f asm("D_8008BE70");
extern struct { s32 a[4]; } D_8008ADD0_f[] asm("D_8008ADD0");
extern s32 D_8008E398_f asm("D_8008E398");
s32 func_8004B280(void);
void func_80051F44(void *, void *, u32);
void func_8004B230(void *, void *, s32, s32);

s32 func_8004ACA0(s32 *src, u32 size, s32 flag) {
    u32 n;
    u32 m;
    if (D_8008E398_f & 1) {
        if (D_8008E468_f.addr == 0) {
            if (func_8004B280() == 0) {
                func_80051F44(src, &D_8008BE70_f, 0x40);
                src += 0x10;
                size -= 0x40;
                D_8008E468_f.addr = D_8008BE70_f.unk10;
                /* the original really writes this word back */
                D_8008BE70_f.unk18 = D_8008BE70_f.unk18;
                D_8008E468_f.len = D_8008BE70_f.unk14;
                D_8008E468_f.dst = (s32 *)&D_8008ADD0_f[D_8008BE70_f.unk18];
                D_8008E468_f.tlen = D_8008BE70_f.unk1C << 4;
            } else {
                func_8004A2A8(0x18);
                size = 0;
                D_8008E468_f.len = 0;
                D_8008E468_f.tlen = 0;
            }
        }
        if (D_8008E468_f.tlen != 0) {
            if (size == 0) {
                goto end;
            }
            n = D_8008E468_f.tlen;
            if (n >= size) {
                n = size;
            }
            func_80051F44(src, D_8008E468_f.dst, n);
            src += n / 4;
            size -= n;
            D_8008E468_f.dst += n / 4;
            D_8008E468_f.tlen -= n;
            if (D_8008E468_f.tlen == 0) {
                func_8004B230(&D_8008ADD0_f[D_8008BE70_f.unk18], &D_8008ADD0_f[D_8008BE70_f.unk18],
                              D_8008BE70_f.unk10, D_8008BE70_f.unk1C);
            }
        }
        if (size == 0) {
            goto end;
        }
        if (D_8008E468_f.len == 0) {
            goto clear;
        }
        m = D_8008E468_f.len;
        if (m >= size) {
            m = size;
        }
        size = m;
        SpuSetTransferStartAddr(D_8008E468_f.addr);
        func_8004B2E8((u8 *)src, size);
        D_8008E468_f.addr += size;
        D_8008E468_f.len -= size;
        if (flag != 0) {
            func_8004B374();
        }
    end:
        if (D_8008E468_f.len != 0) {
            goto ret;
        }
    clear:
        D_8008E398_f &= ~1;
    }
ret:
    return D_8008E468_f.len;
}

void f_4AC00_t(s32, s32) asm("func_8004AC00");
void func_8004AEC0(s32 arg0, s32 arg1, s32 arg2) {
    f_4AC00_t(arg0, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80049F90", func_8004AEE0);

void func_8004AF74(void) {
    func_8005134C(0xE2);
}

void func_8004AF94(s32 arg0) {
    D_8008BEE0 = (arg0 & 0x7F) << 8;
    func_8005134C(0xE4);
}

void func_8004AFC4(s32 arg0, s32 arg1) {
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = (arg1 & 0x7F) << 8;
    func_8005134C(0xE5);
}

void f_SpuSetTransferMode_a(s32) asm("SpuSetTransferMode");
void f_SpuSetTransferStartAddr_a(s32) asm("SpuSetTransferStartAddr");
extern u8 D_8006B4FC_u[] asm("D_8006B4FC");
void f_4B2E8_a(void *, s32) asm("func_8004B2E8");
void f_4B374_a(void) asm("func_8004B374");
s32 func_8004AFFC(s32 arg0) {
    f_SpuSetTransferMode_a(0);
    f_SpuSetTransferStartAddr_a(0x1010);
    f_4B2E8_a(D_8006B4FC_u, 0x40);
    f_4B374_a();
    return arg0;
}

extern u8 D_8006B4FC[];
void func_8005134C(s32);
void SpuSetTransferMode(s32);
u32 SpuSetTransferStartAddr(u32);
void func_8004B2E8(u8 *, s32);
void func_8004B374(void);
s32 func_8004B048(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return -1;
    }
    (&D_8008BEE0)[0] = arg0;
    (&D_8008BEE0)[1] = arg1;
    func_8005134C(0xE8);
    SpuSetTransferMode(0);
    SpuSetTransferStartAddr(0xF0C0);
    func_8004B2E8(D_8006B4FC, 0x40);
    func_8004B374();
    return 0;
}

typedef struct {
    u8 pad0[8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad14[0xC];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    u32 unk3C;
} Unk8008E3A8;
extern Unk8008E3A8 D_8008E3A8;
extern s32 D_8008E3DC;

s32 func_8004B0B4(void) {
    D_8008E3A8.unk24++;
    D_8008E3A8.unk38++;
    if (D_8008E3A8.unk3C - 1 < D_8008E3A8.unk38) {
        D_8008E3A8.unk38 = 0;
    }
    if ((D_8008E3A8.unk8 & 0x1000000) && D_8008E3A8.unk38 >= 2) {
        func_80055F20();
    }
    return D_8008E3DC;
}

s32 func_8004B138(s32 arg0) {
    D_8008BEE0 = arg0;
    func_8005134C(0xAE);
    return arg0;
}

s32 func_8004B16C(s32 arg0) {
    D_8008BEE0 = arg0;
    func_8005134C(0xAF);
    return arg0;
}
