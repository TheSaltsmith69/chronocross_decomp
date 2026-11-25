#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc2/atoi", atoi);

/* atol */
s32 atoi(char *);
s32 func_80010220(char *s) {
    return atoi(s);
}
