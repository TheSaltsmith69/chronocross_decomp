#include "common.h"

/*
 * PsyQ libpress (MDEC decoding): the first object in the field overlay.
 * Sony built it with gcc 2.7.2, so the Makefile compiles this file with
 * 2.7.2 instead of the game's 2.8.1.
 */

/* Pointers to the MDEC and DMA registers (filled in by the data section). */
extern volatile u32 *D_800E1444; /* DMA0 (MDEC in) MADR */
extern volatile u32 *D_800E1448; /* DMA0 BCR */
extern volatile u32 *D_800E144C; /* DMA0 CHCR */
extern volatile u32 *D_800E1450; /* DMA1 (MDEC out) MADR */
extern volatile u32 *D_800E1454; /* DMA1 BCR */
extern volatile u32 *D_800E1458; /* DMA1 CHCR */
extern volatile u32 *D_800E1474; /* MDEC0 command/data */
extern volatile u32 *D_800E1478; /* MDEC1 control/status */
extern volatile u32 *D_800E147C; /* DPCR */

INCLUDE_ASM("asm/ov_field/nonmatchings/libpress", func_800A39B4);

void ResetCallback(void);
void func_800A3D58(s32);

/* PsyQ libpress DecDCTReset */
void func_800A3AA4(s32 mode) {
    if (mode == 0) {
        ResetCallback();
    }
    func_800A3D58(mode);
}

extern u32 D_800E1338[], D_800E1378[], D_800E13BC[];
/* PsyQ libpress DecDCTGetEnv */
u32 *func_800A3AD8(u32 *env) {
    u32 *dest, *src;
    s32 i;
    dest = env;
    src = D_800E1338;
    for (i = 15; i != -1; i--)
        *dest++ = *src++;
    dest = env + 16;
    src = D_800E1378;
    for (i = 15; i != -1; i--)
        *dest++ = *src++;
    dest = env + 32;
    src = D_800E13BC;
    for (i = 31; i != -1; i--)
        *dest++ = *src++;
    return env;
}

extern u32 D_800E1338[], D_800E1378[];
extern u32 D_800E1334[], D_800E13B8[];
void func_800A3E48(u32 *, u32);
/* PsyQ libpress DecDCTPutEnv */
u32 *func_800A3B64(u32 *env) {
    u32 *dest, *src;
    s32 i;
    dest = D_800E1338;
    src = env;
    for (i = 15; i != -1; i--)
        *dest++ = *src++;
    dest = D_800E1378;
    src = env + 16;
    for (i = 15; i != -1; i--)
        *dest++ = *src++;
    func_800A3E48(D_800E1334, 0x20);
    func_800A3E48(D_800E13B8, 0x20);
    return env;
}

void func_800A3E48(u32 *, u32);
/* PsyQ libpress DecDCTin */
void func_800A3BFC(u32 *buf, s32 mode) {
    if (mode & 1) {
        *buf &= ~0x08000000;
    } else {
        *buf |= 0x08000000;
    }
    if (mode & 2) {
        *buf |= 0x02000000;
    } else {
        *buf &= ~0x02000000;
    }
    func_800A3E48(buf, *(u16 *)buf);
}

void func_800A3ED8(u32 *, u32);

/* PsyQ libpress DecDCTout */
void func_800A3C78(u32 *buf, u32 size) {
    func_800A3ED8(buf, size);
}

s32 func_800A3F64(void);
u32 func_800A408C(void);
/* PsyQ libpress DecDCTinSync */
s32 func_800A3C98(s32 mode) {
    if (mode != 0) {
        return (func_800A408C() >> 29) & 1;
    }
    return func_800A3F64();
}

s32 func_800A3FF8(void);
u32 func_800A408C(void);
/* PsyQ libpress DecDCToutSync */
s32 func_800A3CD4(s32 mode) {
    if (mode != 0) {
        return (func_800A408C() >> 24) & 1;
    }
    return func_800A3FF8();
}

void DMACallback(s32, s32);

/* PsyQ libpress DecDCTinCallback */
void func_800A3D10(s32 func) {
    DMACallback(0, func);
}

/* PsyQ libpress DecDCToutCallback */
void func_800A3D34(s32 func) {
    DMACallback(1, func);
}

extern u32 D_800E1334[], D_800E13B8[];
void func_800A3E48(u32 *, u32);
void func_80043B28(const char *, ...);
/* PsyQ libpress MDEC_reset */
void func_800A3D58(s32 mode) {
    switch (mode) {
    case 0:
        *D_800E1478 = 0x80000000;
        *D_800E144C = 0;
        *D_800E1458 = 0;
        *D_800E1478 = 0x60000000;
        func_800A3E48(D_800E1334, 0x20);
        func_800A3E48(D_800E13B8, 0x20);
        break;
    case 1:
        *D_800E1478 = 0x80000000;
        *D_800E144C = 0;
        *D_800E1458 = 0;
        *D_800E1458;
        *D_800E1478 = 0x60000000;
        break;
    default:
        func_80043B28("MDEC_rest:bad option(%d)\n", mode);
        break;
    }
}

s32 func_800A3F64(void);
/* Start a DMA transfer into the MDEC */
void func_800A3E48(u32 *buf, u32 size) {
    func_800A3F64();
    *D_800E147C |= 0x88;
    *D_800E1444 = (u32)(buf + 1);
    *D_800E1448 = ((size >> 5) << 16) | 0x20;
    *D_800E1474 = *buf;
    *D_800E144C = 0x01000201;
}

s32 func_800A3FF8(void);
/* Start a DMA transfer out of the MDEC */
void func_800A3ED8(u32 *buf, u32 size) {
    func_800A3FF8();
    *D_800E147C |= 0x88;
    *D_800E1458 = 0;
    *D_800E1450 = (u32)buf;
    *D_800E1454 = ((size >> 5) << 16) | 0x20;
    *D_800E1458 = 0x01000200;
}

s32 func_800A40A4(const char *);
/* PsyQ libpress MDEC_in_sync */
s32 func_800A3F64(void) {
    volatile s32 cnt = 0x100000;
    while (*D_800E1478 & 0x20000000) {
        if (--cnt == -1) {
            func_800A40A4("MDEC_in_sync");
            return -1;
        }
    }
    return 0;
}

s32 func_800A40A4(const char *);
/* PsyQ libpress MDEC_out_sync */
s32 func_800A3FF8(void) {
    volatile s32 cnt = 0x100000;
    while (*D_800E1458 & 0x01000000) {
        if (--cnt == -1) {
            func_800A40A4("MDEC_out_sync");
            return -1;
        }
    }
    return 0;
}

u32 func_800A408C(void) {
    return *D_800E1478;
}

INCLUDE_ASM("asm/ov_field/nonmatchings/libpress", func_800A40A4);

/* The last two are hand-written assembly (DecDCTvlcSize, DecDCTvlc). */
INCLUDE_ASM("asm/ov_field/nonmatchings/libpress", func_800A4124);

INCLUDE_ASM("asm/ov_field/nonmatchings/libpress", func_800A4154);
