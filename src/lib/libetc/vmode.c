#include "common.h"

/* SetVideoMode */
extern s32 D_8006AD78;
s32 func_800285C4(s32 mode) {
    s32 old = D_8006AD78;
    D_8006AD78 = mode;
    return old;
}
