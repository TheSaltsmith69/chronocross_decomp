#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libcd/event", CdInit);

s32 CD_init(void);
s32 CD_initvol(void);
s32 func_80049C80(void) {
    if (CD_init() != 0) {
        return 0;
    }
    return CD_initvol() == 0;
}

void DeliverEvent(u32, s32);
void func_80049CBC(void) {
    DeliverEvent(0xF0000003, 0x20);
}

void DeliverEvent(u32, s32);
void func_80049CE4(void) {
    DeliverEvent(0xF0000003, 0x40);
}

void DeliverEvent(u32, s32);
void func_80049D0C(void) {
    DeliverEvent(0xF0000003, 0x40);
}
