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

extern u32 D_8006EB58;

u32 func_80019CD4(s32 arg0) {
    u32 t = (u16)func_80019690(1, 999);
    u32 m = arg0 * 1000;
    t *= m;
    t /= D_8006EB58;
    t *= 2;
    if (t % 1000000 > 499999) {
        t += 1000000;
    }
    return t / 1000000;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019DA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_80019ED8);

typedef struct {
    u8 pad0[0x2DE7];
    u8 unk2DE7;
    u8 pad2DE8[0x30AC - 0x2DE8];
    s16 unk30AC;
    s16 unk30AE;
    s32 unk30B0;
} Unk8006EBC8;
extern Unk8006EBC8 D_8006EBC8;
extern s32 D_8006EB4C;
extern s32 D_8006EB50;
extern s32 D_8006EB54;

void func_80019FE4(void) {
    func_80019ED8(0x79);
    func_80019A00(1);
    D_8006EBC8.unk30B0 = 2;
    D_8006EBC8.unk30AE = 20;
    D_8006EBC8.unk30AC = 20;
    D_8006EBC8.unk2DE7 = 0xFF;
    func_80019DA0();
    func_800197C0(0);
    func_8003D504(D_8006EB4C);
    func_8003D504(D_8006EB50);
    func_8003D504(D_8006EB54);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A06C);

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
} Unk80072418;
extern Unk80072418 D_80072418[];
void func_80029D9C(void);
void func_8001A0E0(s32 arg0, s32 arg1, u32 arg2) {
    Unk80072418 *p;
    if (arg2 >= 16) {
        func_80029D9C();
    }
    p = &D_80072418[arg2];
    p->unk0 = arg0;
    p->unk4 = arg1;
    p->unk8 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A14C);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A350);

INCLUDE_ASM("asm/nonmatchings/game/unk_800191D4", func_8001A448);

typedef struct {
    s16 x, y, w, h;
} RECT_8001;
void func_8003F7D4(void);
void func_800306AC(s32, s32);
void func_8003073C(s32, s32, s32, s32, s32, s32);
void VSyncCallback(void (*)());
void func_8003F414();
extern u8 D_8006B394;
void func_8001A654(void) {
    RECT_8001 unused;
    func_8003F7D4();
    func_800306AC(0x3C0, 0x1F7);
    func_8003073C(0x10, 0x10, 0x140, 0xF0, 0, 0x200);
    VSyncCallback(func_8003F414);
    D_8006B394 = 0;
}
