#include "common.h"

void *bcopy(u8 *s, u8 *d, s32 n) {
    void *r;
    if (s == 0) {
        return 0;
    }
    r = s;
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return r;
}
