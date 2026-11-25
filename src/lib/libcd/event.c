#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libcd/event", CdInit);

INCLUDE_ASM("asm/nonmatchings/lib/libcd/event", func_80049C80);

void DeliverEvent(u32, s32);
void func_80049CBC(void) {
    DeliverEvent(0xF0000003, 0x20);
}

void DeliverEvent(u32, s32);
void func_80049CE4(void) {
    DeliverEvent(0xF0000003, 0x40);
}

INCLUDE_ASM("asm/nonmatchings/lib/libcd/event", func_80049D0C);
