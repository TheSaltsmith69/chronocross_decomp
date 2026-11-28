#include "common.h"

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008EBEC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008EC94);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008ED38);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008EDF8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008EEC8);

void func_8008EF24(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x1A) = (u16) (*(u16 *)(arg0 + 0x1A) | arg1);
}

void func_8008EF38(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x1A) = (u16) (*(u16 *)(arg0 + 0x1A) & ~arg1);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008EF4C);

void func_8008EF68(u8 *arg0, s32 arg1) {
    *(s16 *)(arg0 + 0x20) = (s16) ((arg1 & 3) << 5);
}

void func_8008EF78(u8 *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0x26) = arg1;
}

void func_8008EF80(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x58) = arg1;
}

void func_80090E6C();

void func_8008EF88(u8 *arg0) {
    *(s32 **)(arg0 + 0x58) = func_80090E6C;
}

void func_8008EF98(u8 *arg0, s32 *arg1) {
    *arg1 = (s32) *(u16 *)(arg0 + 0x16);
}

void func_8008EFA4(u8 *arg0, s32 *arg1) {
    *arg1 = *(u16 *)(arg0 + 6) * 8;
}

void func_8008EFB8(u8 *arg0, s32 *arg1) {
    *arg1 = (s32) *(u16 *)(arg0 + 0x14);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008EFC4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F0AC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F1A8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F21C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F290);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F304);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F378);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F474);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F4AC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F4E4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F51C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F554);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F634);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F674);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F6B4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F6FC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F744);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008F918);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008FA8C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008FC00);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008FD74);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8008FEE8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800900B0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090278);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090440);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090608);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090668);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800906E8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090844);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800908E8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009098C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090A30);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090AD4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090B78);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090C1C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090CC0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090D64);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090DC4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090E44);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80090E6C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009107C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800912F4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80091590);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009185C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80091B40);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80091DF0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800920D4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80092404);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80092754);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80092964);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80092BE4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80092E9C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80093170);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80093470);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80093728);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80093A24);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80093DA0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094118);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094140);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094318);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094558);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094654);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800947E8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009493C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094B90);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094BE4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094C38);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094CD8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094D4C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094E40);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094F34);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80094FAC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095014);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800954BC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009552C);

s32 func_8003D504(s32);
s32 func_8009561C(s32);
s32 func_8009BD60();

void func_80095578(s32 arg0) {
    func_8009BD60();
    func_8009561C(arg0);
    func_8003D504(arg0);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800955AC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009561C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009567C);

s32 func_8003D504(s32);

void func_800957BC(u8 *arg0) {
    s32 temp_a0;

    temp_a0 = *(s32 *)(arg0 + 0x1FC);
    if (temp_a0 != 0) {
        func_8003D504(temp_a0);
        *(s32 *)(arg0 + 0x1FC) = 0;
    }
}

s32 func_800957F8(u8 *arg0) {
    return **(s32 **)(arg0 + 8);
}

s32 func_8009580C(u8 *arg0) {
    return **(s32 **)(arg0 + 4);
}

void func_80095820(u8 **arg0, s32 *arg1) {
    *arg1 = **(s32 **)((u8 *)(*arg0) + 0x10);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009583C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095890);

s32 func_80095890(s32);

void func_80095928(s32 *arg0) {
    func_80095890(*arg0);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009594C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095A08);

void func_80095A50(u8 *arg0, s16 *arg1, s16 *arg2) {
    s32 temp_v1;

    temp_v1 = *(u16 *)(arg0 + 0x74) & 0x1F;
    *arg1 = (temp_v1 & 0xF) << 6;
    *arg2 = (temp_v1 >> 4) << 8;
}

void func_80095A78(u8 *arg0, s16 *arg1, s16 *arg2) {
    u16 temp_v1;

    temp_v1 = *(u16 *)(arg0 + 0x76);
    *arg1 = (temp_v1 & 0x3F) * 0x10;
    *arg2 = (s16) ((u32) (temp_v1 & 0x7FFF) >> 6);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095A9C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095B88);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095BBC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095C28);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095D54);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095E18);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095F1C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095F5C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80095F9C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800960A0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800960E0);

s32 func_80095E18(s32, s32, u32);

void func_80096120(u8 *arg0) {
    u16 temp_a2;

    temp_a2 = *(u16 *)(arg0 + 0x7C);
    func_80095E18(*(s32 *)arg0, temp_a2 & 0xFF, temp_a2 >> 8);
}

s32 func_80095F9C(s32, s32, u32);

void func_8009614C(u8 *arg0) {
    u16 temp_a2;

    temp_a2 = *(u16 *)(arg0 + 0x7C);
    func_80095F9C(*(s32 *)arg0, temp_a2 & 0xFF, temp_a2 >> 8);
}

void func_80096178(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x1F8) = arg1;
}

void func_8009CC0C();

void func_80096180(u8 *arg0) {
    *(s32 **)(arg0 + 0x1F8) = func_8009CC0C;
}

void func_80096190(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x7E) = (u16) (*(u16 *)(arg0 + 0x7E) | arg1);
}

void func_800961A4(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x7E) = (u16) (*(u16 *)(arg0 + 0x7E) & ~arg1);
}

void func_800961B8(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x2C) = arg1;
}

void func_800961C0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}

void func_800961C8(u8 *arg0, s32 arg1) {
    *(u16 *)(arg0 + 0x74) = (u16) ((*(u16 *)(arg0 + 0x74) & 0xFF9F) | ((arg1 & 3) << 5));
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800961E4);

void func_80096238(u8 *arg0, u32 arg1, s32 arg2) {
    *(s16 *)(arg0 + 0x76) = (s16) ((arg2 << 6) | ((arg1 >> 4) & 0x3F));
}

void func_80096250(u8 *arg0, u32 arg1, s32 arg2) {
    *(s16 *)(arg0 + 0x7A) = (s16) ((arg2 << 6) | ((arg1 >> 4) & 0x3F));
}

void func_80096268(u8 *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0x7C) = arg1;
}

void func_80096270(u8 *arg0, u8 *arg1) {
    *(s32 *)(arg0 + 0x84) = (s32) *(s32 *)arg1;
    *(s32 *)(arg0 + 0x88) = (s32) *(s32 *)(arg1 + 4);
    *(s32 *)(arg0 + 0x8C) = (s32) *(s32 *)(arg1 + 8);
}

void func_80096294(u8 *arg0, u8 *arg1) {
    *(s32 *)(arg0 + 0xA4) = (s32) *(s32 *)arg1;
    *(s32 *)(arg0 + 0xA8) = (s32) *(s32 *)(arg1 + 4);
}

void func_800962AC(u8 *arg0, u8 *arg1) {
    *(s32 *)(arg0 + 0xAC) = (s32) *(s32 *)arg1;
    *(s32 *)(arg0 + 0xB0) = (s32) *(s32 *)(arg1 + 4);
}

void func_800962C4(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_a0;

    temp_a0 = arg0 + (arg1 * 4);
    *(u8 *)(temp_a0 + 0x37) = (u8) (*(u8 *)(temp_a0 + 0x37) | arg2);
}

void func_800962E0(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_a0;

    temp_a0 = arg0 + (arg1 * 4);
    *(u8 *)(temp_a0 + 0x37) = (u8) (*(u8 *)(temp_a0 + 0x37) & ~arg2);
}

void func_800962FC(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x80) = (s32) ((arg2 << 0x10) | arg1);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009630C);

void func_80096354(u8 *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0x20) = arg1;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009635C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800964A8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800967CC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80096888);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80096E38);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80096FA4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800970FC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097438);

s32 func_80094F34(s32, s16);

void func_800977C4(u8 *arg0, s32 arg1) {
    func_80094F34(arg1, *(s16 *)(arg0 + 0x12));
    *(s32 *)(arg0 + 0xC) = arg1;
}

void func_80097800(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) = 0;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097808);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097854);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009789C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097918);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097B98);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097C9C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097D28);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80097F80);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800980AC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009813C);

void func_8009868C(void) {
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80098694);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80098720);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80098768);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80098864);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800989A4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80098BC0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80098BFC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099004);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099060);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099100);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099118);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800992F8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800994B4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009950C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099880);

void func_80099914(void) {
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009991C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099988);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099A84);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_80099FCC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009A63C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009A8BC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009A9C0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AAA4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AAE0);

s32 func_8009AB14(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x100) + 4);
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AB28);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009ABAC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AC54);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AD74);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AE10);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009AF54);

s32 func_80094B90(s32);

void func_8009B098(u8 *arg0, s32 arg1) {
    func_80094B90(arg1);
    *(s32 *)(arg0 + 0x104) = arg1;
}

void func_8009B0D0(u8 *arg0) {
    *(s32 *)(arg0 + 0x104) = 0;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B0D8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B1A0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B228);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B268);

s32 func_8002B434();

s32 func_8009B2C4(u8 *arg0) {
    *(s32 *)(arg0 + 0x108) = 0;
    *(s16 *)(arg0 + 0x110) = 0;
    func_8002B434();
    return 0;
}

extern s32 D_800A32E0;

s32 func_8009B2E8(u8 *arg0) {
    D_800A32E0 = 0;
    *(s32 *)(arg0 + 0x108) = 0;
    *(s16 *)(arg0 + 0x110) = 0;
    return 0;
}

s32 func_8009B300(u8 *arg0) {
    *(s32 *)(arg0 + 0x108) = 0;
    *(s16 *)(arg0 + 0x110) = 0;
    return 0;
}

s32 func_8009B310(s32 arg0) {
    u8 *temp_a0;
    u8 *temp_v1;

    temp_a0 = arg0 + 0x100;
    temp_v1 = *(u8 **)(temp_a0 + 8);
    *(u8 **)(temp_a0 + 8) = (u8 *) (temp_v1 + (*(s16 *)(temp_v1 + 2) * 2));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B338);

s32 func_8009B37C(s32 arg0) {
    u16 temp_v0;
    u8 *temp_a0;

    temp_a0 = arg0 + 0x100;
    temp_v0 = *(u16 *)(temp_a0 + 0x12) - 1;
    *(u16 *)(temp_a0 + 0x12) = temp_v0;
    *(s32 *)(temp_a0 + 8) = (s32) *(s32 *)((u8 *)((temp_a0 + ((s32) (temp_v0 << 0x10) >> 0xE))) + 0x14);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B3B0);

extern u8 *D_800A1280;

s32 func_8009B4A4(s32 arg0) {
    u8 *temp_a0;
    u8 *temp_v1;

    temp_a0 = arg0 + 0x100;
    temp_v1 = *(u8 **)(temp_a0 + 8);
    D_800A1280 = temp_v1;
    *(u8 **)(temp_a0 + 8) = (u8 *) (temp_v1 + (*(s16 *)(temp_v1 + 2) * 2));
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B4D0);

s32 func_8009B5D0(s32 arg0) {
    u8 *temp_a0;
    u8 *temp_v1;

    temp_a0 = arg0 + 0x100;
    temp_v1 = *(u8 **)(temp_a0 + 8);
    *(u8 **)(temp_a0 + 8) = (u8 *) (temp_v1 + (*(s16 *)(temp_v1 + 2) * 2));
    return 2;
}

s32 func_8009B5F8(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B600);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B658);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B6D0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B738);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B768);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B7B4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B84C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B86C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B89C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B934);

extern u8 D_8006B47C;

s32 func_8009B964(u8 *arg0) {
    D_8006B47C = *(u8 *)(*(u8 **)(arg0 + 0x108) + 2);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B980);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009B9B0);

s32 func_8009BA18(u8 *arg0) {
    *(u16 *)(arg0 + 0x2A) = (u16) *(u16 *)(*(u8 **)(arg0 + 0x108) + 2);
    return 2;
}

s32 func_8009BA34(u8 *arg0) {
    *(s16 *)(arg0 + 0x22) = 1;
    return 1;
}

s32 func_8009BA44(u8 *arg0) {
    *(s16 *)(arg0 + 0x22) = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BA50);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BA70);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BA90);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BABC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BAE8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BB44);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BCD8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BD60);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009BDCC);

s32 func_8009C014(void) {
    return 8;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C01C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C05C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C09C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C100);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C164);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C1F4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C25C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C2EC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C350);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C3B4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C3FC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C444);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C48C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C50C);

s32 func_8009C5C0(void) {
    return 4;
}

s32 func_8009C5C8(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C5D0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C60C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C718);

void func_8009C920(u8 **arg0, u8 *arg1) {
    u8 *temp_v1;

    temp_v1 = *arg0;
    *(u8 **)arg1 = temp_v1;
    *arg0 = arg1;
    *(u8 **)(arg1 + 4) = (u8 *) *(u8 **)(temp_v1 + 4);
    *(u8 **)(temp_v1 + 4) = arg1;
}

void func_8009C944(u8 *arg0) {
    u8 *temp_v0;
    u8 **temp_v1;

    temp_v1 = *(u8 ***)(arg0 + 4);
    temp_v0 = *(u8 **)arg0;
    *temp_v1 = temp_v0;
    *(u8 ***)(temp_v0 + 4) = temp_v1;
    *(u8 ***)(arg0 + 4) = NULL;
    *(u8 **)arg0 = NULL;
    *(s32 *)(arg0 + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C968);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009C9F4);

extern s32 D_800A32BC;

void func_8009CA60(u8 *task) {
    func_8009C944(task);
    func_8009C920((u8 **)D_800A32BC, task);
    *(s32 *)(task + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009CA98);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009CAF4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009CB34);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009CB8C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009CC0C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009CDDC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009D0EC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009D35C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009D5F0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009D8DC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009DC00);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009DCE4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009DF94);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009E204);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009E498);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009E784);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009EAA8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009EB8C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009EDF8);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009F0D0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009F3D0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009F72C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009FAC0);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009FCE4);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_8009FF34);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800A01AC);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800A0434);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800A076C);

INCLUDE_ASM("asm/nonmatchings/blob_8008EBEC", func_800A0AD8);
