#include "common.h"

/* SetSemiTrans */
void func_80011474(u8 *p, s32 abe) {
    if (abe) {
        p[7] |= 2;
    } else {
        p[7] &= ~2;
    }
}
