#include "common.h"

void *memcpy(u8 *d, u8 *s, s32 n) {
    void *r;
    if (d == 0) {
        return 0;
    }
    r = d;
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return r;
}
