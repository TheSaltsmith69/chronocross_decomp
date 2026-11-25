#include "common.h"

/* SpuSetIRQCallback */
s32 InterruptCallback(s32, void *);
void func_8004BC34(void *f) {
    InterruptCallback(9, f);
}
