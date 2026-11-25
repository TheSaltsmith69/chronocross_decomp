#include "common.h"

/* SetShadeTex */
void func_800114A4(u8 *p, s32 tge) {
    if (tge) {
        p[7] |= 1;
    } else {
        p[7] &= ~1;
    }
}
