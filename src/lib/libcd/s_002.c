#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libcd/s_002", CdIntToPos);

#define BTOI(b) (((b) >> 4) * 10 + ((b) & 0xF))
s32 CdPosToInt(u8 *p) {
    return (BTOI(p[0]) * 60 + BTOI(p[1])) * 75 + BTOI(p[2]) - 150;
}
