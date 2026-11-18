#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_800191D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_800192E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019510);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019550);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019690);

typedef struct {
    s32 count;
    s32 offsets[1];
} Unk8005783C;
extern Unk8005783C D_8005783C;
u8 *func_80019794(s32 arg0, s32 arg1) {
    u8 *p = (u8 *)&D_8005783C + D_8005783C.offsets[arg0];
    return p + ((u16 *)p)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_800197C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019A00);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019CD4);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019DA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019ED8);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019FE4);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A06C);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A0E0);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A14C);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A350);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A448);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A654);
