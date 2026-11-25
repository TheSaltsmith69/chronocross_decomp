#include "common.h"

extern void *D_80063F80;
extern void *D_80063F84;
extern void *D_80063F88;
void func_800176B8(void);
s32 func_80017B0C();
void func_800177C8(void);
void _padInitDirSeq(void) {
    D_80063F80 = func_800176B8;
    D_80063F84 = func_80017B0C;
    D_80063F88 = func_800177C8;
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_800176B8);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padseqd", func_800177C8);

extern void (*D_80063F6C_s)(u8 *) asm("D_80063F6C");
void func_80017A2C(u8 *p) {
    (*(s32 *)(p + 0x4C))++;
    if (p[0x46] != 0) {
        if (p[0x46] == 1) {
            if (p[0x4A] < 0xB) {
                p[0x4A]++;
                return;
            }
            p[0x49] = 2;
            p[0x46] = 0xFF;
            return;
        }
        if (p[0x4A] < 0xB) {
            p[0x4A]++;
            return;
        }
        if (p[0x49] != 0) {
            D_80063F6C_s(p);
        }
    }
    if (**(u8 **)(p + 0x3C) != 0xF3) {
        (*(u8 **)(p + 0x30))[0] = 0xFF;
        (*(u8 **)(p + 0x30))[1] = 0;
        p[0xE8] = 0;
        p[0x35] = 0;
    }
}

s32 func_80017B0C(u8 *p) {
    if (*(u16 *)(p + 0xE6) == 0 || p[0x46] != 0xFF) {
        return 1;
    }
    return 0;
}
