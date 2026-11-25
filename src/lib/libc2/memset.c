#include "common.h"

void *memset(char *s, s32 c, s32 n) {
    void *r;
    if (s == 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    r = s;
    while (n > 0) {
        *s++ = c;
        n--;
    }
    return r;
}
