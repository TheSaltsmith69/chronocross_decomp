#include "common.h"

void func_8004B230(s32 *s, s32 *d, s32 add, s32 n) {
    do {
        d[0] = s[0] + add;
        d[1] = s[1] + add;
        d[2] = s[2];
        d[3] = s[3];
        s += 4;
        d += 4;
    } while (--n != 0);
}

s32 func_8004B280(s32 *p) {
    return *p + 0xB0BEB4BF;
}

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B294);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B2B8);

extern volatile s32 D_8008BE20_v asm("D_8008BE20");
void func_8004BD24(void *);
void func_8004B294(void);
s32 func_8004BCC4(void *, s32);
void func_8004B2E8(void *addr, s32 size) {
    D_8008BE20_v = 1;
    func_8004BD24(func_8004B294);
    func_8004BCC4(addr, size);
}

void func_8004B2B8(void);
s32 SpuRead(void *, s32);
void func_8004B338(void *addr, s32 size) {
    func_8004B2B8();
    SpuRead(addr, size);
}

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B374);

s32 func_8004B280(s32 *p);
s32 func_8004B3F0(s32 *p, s32 a, s32 b, s32 c);
s32 func_8004B3A0(s32 *p, s32 a) {
    if (func_8004B280(p) != 0) {
        return -1;
    }
    func_8004B3F0(p, a, p[6], p[4]);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B3F0);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B4B4);

INCLUDE_ASM("asm/nonmatchings/lib/unk_8004B230", func_8004B750);

extern s32 D_8008BE20;
extern u8 D_8006B4FC[];
extern s32 D_8006B4E0;
void func_8004B2E8(void *addr, s32 size);
void func_8004B374(void);
s32 func_8004B9E8(u32);
void UnDeliverEvent(u32, s32);
s32 DisableEvent(s32);
s32 CloseEvent(s32);
void func_8004BD70(u32);
void func_8003FC70(void);
void func_8004B840(void) {
    if (D_8008BE20 == 1) {
        func_8004B2E8(D_8006B4FC, 0x40);
        func_8004B374();
    }
    while (func_8004B9E8(0xF2000002) == 0) {
    }
    UnDeliverEvent(0xF2000002, 2);
    while (DisableEvent(D_8006B4E0) == 0) {
    }
    while (CloseEvent(D_8006B4E0) == 0) {
    }
    func_8004BD70(0xFFFFFF);
    func_8003FC70();
}
