#include "common.h"
#include "sound.h"


INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80051F24);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80051F44);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80051FC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005203C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80052518);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800527BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80052850);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80052E64);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053078);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800532A0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053430);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800536A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053DDC);

void func_80053E50(Unk80051F24 *arg0, Unk8008ADD0 *arg1, s32 arg2) {
    arg0->unk110 = arg2;
    arg0->unk114 = arg1->unk4;
    arg0->unk11A = arg1->unkC;
    arg0->unk11C = arg1->unkE;
    arg0->unk10C |= 0x1FF80;
}

extern Unk8008ADD0 D_8008ADD0[];
void func_80053E84(Unk80051F24 *arg0, s32 arg1) {
    Unk8008ADD0 *e;
    arg0->unk7E = arg1;
    e = &D_8008ADD0[arg1];
    func_80053E50(arg0, e, e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053EBC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80053F28);

void func_80053FFC(Unk80051F24 *arg0) {
    Unk80051F24 *ch = D_8008BE50;
    ch->unk24 = arg0->unk0[0] << 16;
    ch->unk24 |= arg0->unk0[1] << 24;
    arg0->unk0 += 2;
    ch->unk6C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054048);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800540E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054130);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800541D8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054204);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005425C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054294);

void func_800542A0(Unk80051F24 *arg0) {
    u8 v = *arg0->unk0++;
    arg0->unk10C |= 3;
    arg0->unk96 = v << 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800542C8);

void func_8005434C(Unk80051F24 *arg0) {
    s32 v = *((s8 *)arg0->unk0)++;
    arg0->unk9C = 0;
    arg0->unk10C |= 3;
    arg0->unk9E = 0;
    arg0->unk5C = v << 23;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005437C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054408);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054498);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800544AC);

void func_800544C0(Unk80051F24 *arg0) {
    s32 v = *arg0->unk0++;
    arg0->unkA4 = 0;
    arg0->unk10C |= 3;
    arg0->unkA2 = ((v + 0x40) & 0xFF) << 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800544F4);

void func_80054580(Unk80051F24 *arg0) {
    arg0->unkA8 = *arg0->unk0++;
}

void func_8005459C(Unk80051F24 *arg0) {
    arg0->unkA8 = (arg0->unkA8 + 1) & 0xF;
}

void func_800545B4(Unk80051F24 *arg0) {
    arg0->unkA8 = (arg0->unkA8 - 1) & 0xF;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800545CC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054640);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800546AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054740);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054788);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800547AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800547D8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054820);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054858);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054860);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800548C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054924);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054A24);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054A84);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054AF0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054B50);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054B74);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054C2C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054C50);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054CC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054D20);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054D44);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054DB8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054DD8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054E44);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054EA4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054EC8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054F28);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80054F90);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055004);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005506C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800550CC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005512C);

void func_80055138(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055140);

void func_8005515C(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055164);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055200);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055244);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055278);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800552A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800552EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005532C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055370);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800553E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005542C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005544C);

void func_8005545C(Unk80051F24 *arg0) {
    arg0->unkE4 = (arg0->unkE4 + 1) & 3;
    arg0->unk4[arg0->unkE4] = arg0->unk0;
    arg0->unk86[arg0->unkE4] = 0;
    arg0->unk8E[arg0->unkE4] = arg0->unk84;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800554AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055540);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800555AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055628);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005567C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800556A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800556EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055724);

extern Unk80051F24 *D_8008BE50;
void func_8005573C(Unk80051F24 *arg0) {
    Unk80051F24 *ch = D_8008BE50;
    ch->unk78 = *arg0->unk0++;
    ch->unk74 = *arg0->unk0++;
    ch->unk7A = 0;
    ch->unk76 = 0;
}

void func_80055774(Unk80051F24 *arg0) {
    Unk80051F24 *ch = D_8008BE50;
    ch->unk7C = *arg0->unk0++;
    ch->unk7C |= *arg0->unk0++ << 8;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800557B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800557EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055830);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055860);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800558A4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800558D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005593C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055950);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055964);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055978);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_8005598C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A04);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A18);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A2C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A4C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A88);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055A90);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055AB0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055AD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055B70);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055C00);

void func_80055AD0(void);
void func_80055DBC(void) {
    func_80055AD0();
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055DDC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055E4C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055ECC);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80055F20);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800560D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80056198);

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_80056208);

void func_80056208(s32, s32, s32, void *);
void func_80056394();
void func_80056364(void) {
    func_80056208(0xF100, 0xF900, 0x1000, func_80056394);
}

void func_80056394(void) {
    func_80056208(0x10100, 0x10900, 0x1000, func_80056364);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80051F24", func_800563CC);
