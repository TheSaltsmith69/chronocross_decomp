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

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padSendAtLoadInfo);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padRecvAtLoadInfo);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padGetActSize);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80014EAC);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80014F80);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80015028);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padSetActAlign);

void func_80015488(u8 *p) {
    p[0x37] = 0x4D;
    p[0x36] = 6;
    *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x20);
}

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_800154A4);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", _padSetMainMode);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80015604);

INCLUDE_ASM("asm/nonmatchings/lib/libpad/padcmd", func_80015658);

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
