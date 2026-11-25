#include "common.h"

extern void *D_8006AE4C;
void func_8004BC34(void *);
void *SpuSetIRQCallback(void *f) {
    void *old = D_8006AE4C;
    if (f != old) {
        D_8006AE4C = f;
        func_8004BC34(f);
    }
    return old;
}
