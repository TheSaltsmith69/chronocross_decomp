#include "common.h"

u8 *memmove(u8 *d, u8 *s, s32 n) {
    if (d >= s) {
        while (n-- > 0) {
            d[n] = s[n];
        }
    } else {
        while (n-- > 0) {
            *d++ = *s++;
        }
    }
    return d;
}
