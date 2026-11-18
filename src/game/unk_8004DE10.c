#include "common.h"
#include "sound.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DE10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DE64);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DEB8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DF98);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DFDC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E084);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E0D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E464);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E538);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E898);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EA34);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EA90);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EC88);

void func_8004ED00(s32 *arg0, Unk80051F24 *ch) {
    u32 mask;
    s32 bit;
    if (arg0[1] != 0) {
        mask = arg0[1];
        bit = 1;
        do {
            if (mask & bit) {
                ch->unk10C |= 3;
                mask ^= bit;
            }
            ch++;
            bit <<= 1;
        } while (mask != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004ED48);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004ED9C);

extern Unk80051F24 D_8008AD48;
void func_8004ED9C(s32, s32);
void func_8004E0D0(s32, s32);
void func_8004F04C(s32 *arg0) {
    if (D_8008AD48.unk6E != 0 && D_8008AD48.unk6E == arg0[2]) {
        func_8004ED9C(arg0[0], 0);
    } else {
        func_8004E0D0(arg0[0], -1);
        D_8008BE50->unk6E = arg0[2];
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F0C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F148);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F1F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F2B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F484);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F4C4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F510);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F5D8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F688);

void func_8004E538(s32, s32);
void func_8004F7A8(s32 *arg0) {
    func_8004E538(arg0[0], arg0[1]);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F7D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F888);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F9C4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FAC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FB78);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FC98);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FCCC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FD34);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FDA4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FE8C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005000C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050088);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050150);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050230);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800503A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050420);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800504E4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800505C4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005074C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800507A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050870);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005088C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800508F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050968);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050984);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800509EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050A60);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050AB0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050B18);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050BF4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050C54);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050CB4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050CF4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050D08);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050DF8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050E94);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050FB0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80051044);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800510C0);

extern s32 D_80089E08[];
extern Unk80051F24 D_80089E40[];
extern s32 D_8008BEB0[];
void func_80050088(void);
void func_80051154(s32 *arg0) {
    u32 i;
    for (i = 0; i < 12; i++) {
        D_80089E08[i] = (s16)D_80089E40[i].unkF0 >> 8;
    }
    arg0[1] = 0;
    func_80050088();
    if (D_8008BEB0[0] != 0) {
        D_8008E398[0] |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800511D0);

void func_800512F4(void) {
}

void func_80051F14(s32 *);
void SpuSetReverb(s32);
void SpuSetReverbModeType(s32);
void func_800512FC(s32 arg0) {
    s32 mode;
    func_80051F14(&mode);
    if (mode != arg0) {
        SpuSetReverb(0);
        SpuSetReverbModeType(arg0 | 0x100);
        SpuSetReverb(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005134C);
