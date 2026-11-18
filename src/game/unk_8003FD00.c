#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8003FD00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800404F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040780);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040928);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040DD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800413F8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041820);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041AEC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041C0C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041E2C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041EAC);

typedef struct Unk8006B490 {
    struct Unk8006B490 *next;
    s32 unk4;
    u32 unk8;
} Unk8006B490;
extern Unk8006B490 *D_8006B490;
void func_80041EB4(Unk8006B490 *arg0, Unk8006B490 *arg1) {
    Unk8006B490 *head = D_8006B490;
    u32 flags = arg0->unk8;
    D_8006B490 = arg0;
    arg0->next = head;
    if (((flags >> 8) & 0x3F) == 0) {
        if (arg1 != NULL) {
            arg0->unk8 = (flags & ~0x3F00) | ((arg1->unk8 & 0x3F) << 8);
        } else {
            arg0->unk8 = flags & ~0x3F00;
        }
    }
}

Unk8006B490 *func_80041F0C(u32 arg0, s32 arg1) {
    Unk8006B490 *n;
    for (n = D_8006B490; n != NULL; n = n->next) {
        if ((n->unk8 & 0x3F) == arg0 && (arg1 == 0 || n->unk4 == arg1)) {
            return n;
        }
    }
    return NULL;
}

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
    s32 unkC;
} Unk80041F6C;
void *func_80041F6C(Unk80041F6C *arg0) {
    if (!(arg0->unk8 >> 7)) {
        return &arg0->unkC;
    }
    return (void *)arg0->unkC;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041F94);

void DrawSync(s32);
void func_80041820(s32);
void func_80041FD4(s32 arg0) {
    DrawSync(0);
    func_80041820(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042004);

void func_8004206C(s32 *arg0) {
    arg0[2] |= 0x80000000;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042080);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004208C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800420FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800421E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042214);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004227C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800422E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042364);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004247C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800424AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004257C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042928);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800429B4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042A10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042AE0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042AE8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042B10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042B20);

void func_80043B28(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043B30);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043F0C);

