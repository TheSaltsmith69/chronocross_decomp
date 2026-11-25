#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B230);

s32 func_8004B280(s32 *p) {
    return *p + 0xB0BEB4BF;
}

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B294);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B2B8);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B2E8);

void func_8004B2B8(void);
s32 SpuRead(void *, s32);
void func_8004B338(void *addr, s32 size) {
    func_8004B2B8();
    SpuRead(addr, size);
}

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B374);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B3A0);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B3F0);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B4B4);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B750);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B840);
