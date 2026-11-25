#include "common.h"

/* SpuSetTransferCallback */
s32 DMACallback(s32, void *);
void func_80029474(void *f) {
    DMACallback(4, f);
}
