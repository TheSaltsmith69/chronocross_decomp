#include "common.h"

void _padSetAct(u8 *p, u8 *act, s32 len) {
    *(u8 **)(p + 0x28) = act;
    p[0x34] = len;
}

void _padSetCmd(u8 *p, s32 cmd, u8 *buf, s32 len) {
    p[0x37] = cmd;
    *(u8 **)(p + 0x2C) = buf;
    p[0x36] = len;
}

void func_800156D8_s(u8 *) asm("func_800156D8");
void func_800156EC_s(u8 *, s32) asm("func_800156EC");
void func_8001572C_s(u8 *, s32) asm("func_8001572C");
void _padSendAtLoadInfo(u8 *p) {
    switch (p[0x46]) {
    case 2:
        func_800156D8_s(p);
        break;
    case 3:
        func_800156EC_s(p, p[0xE4]);
        break;
    case 4:
        func_8001572C_s(p, p[0x47]);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padRecvAtLoadInfo);

s32 _padGetActSize(u8 *p) {
    s32 a = ((p[0xE3] + 1) >> 1) << 2;
    s32 b = ((p[0xE9] * 5 + 3) & 0xFFC) + 4;
    return a + b + *(u16 *)(p + 0xEC);
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80014EAC);

void func_800156EC_f(u8 *, s32) asm("func_800156EC");
void func_8001570C_f(u8 *, s32) asm("func_8001570C");
void func_8001572C_f(u8 *, s32) asm("func_8001572C");
void func_8001574C_f(u8 *) asm("func_8001574C");
void func_80014F80(u8 *p) {
    switch (p[0x46]) {
    case 2:
        func_800156EC_f(p, p[0x47]);
        break;
    case 3:
        func_8001570C_f(p, p[0x47]);
        break;
    case 4:
        if (p[0x48] == 0) {
            func_8001572C_f(p, p[0x47]);
        } else {
            func_8001574C_f(p);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80015028);

extern s32 (*D_80063F84_p)(u8 *) asm("D_80063F84");
void func_800154A4_p(void) asm("func_800154A4");
void func_80015488_p(void) asm("func_80015488");
s32 _padSetActAlign(u8 *p, void *data) {
    if (D_80063F84_p(p) != 0) {
        return 0;
    }
    p[0x46] = 1;
    *(void **)(p + 0x14) = func_80015488_p;
    *(void **)(p + 0x20) = data;
    *(void **)(p + 0x18) = func_800154A4_p;
    return 1;
}

void func_80015488(u8 *p) {
    p[0x37] = 0x4D;
    p[0x36] = 6;
    *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x20);
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_800154A4);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padSetMainMode);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80015604);

extern void (*D_80063F6C_p)(void) asm("D_80063F6C");
s32 func_80015658(u8 *p) {
    if (p[0x53] != 0) {
        if (p[0x46] == 2) {
            return 1;
        }
        p[0x46] = 0xFE;
    } else {
        D_80063F6C_p();
    }
    return 0;
}

void _padCmdParaMode(u8 *p, s32 mode) {
    p[0x37] = 0x43;
    *(u8 **)(p + 0x2C) = p + 0x24;
    p[0x24] = mode;
    p[0x36] = 1;
}

void func_800156D8(u8 *p) {
    p[0x37] = 0x45;
    *(s32 *)(p + 0x2C) = 0;
    p[0x36] = 0;
}

void func_800156EC(u8 *p, s32 mode) {
    p[0x37] = 0x4C;
    *(u8 **)(p + 0x2C) = p + 0x24;
    p[0x24] = mode;
    p[0x36] = 1;
}

void func_8001570C(u8 *p, s32 mode) {
    p[0x37] = 0x46;
    *(u8 **)(p + 0x2C) = p + 0x24;
    p[0x24] = mode;
    p[0x36] = 1;
}

void func_8001572C(u8 *p, s32 mode) {
    p[0x37] = 0x47;
    *(u8 **)(p + 0x2C) = p + 0x24;
    p[0x24] = mode;
    p[0x36] = 1;
}

void func_8001574C(u8 *p) {
    p[0x37] = 0x4B;
    *(s32 *)(p + 0x2C) = 0;
    p[0x36] = 0;
}
