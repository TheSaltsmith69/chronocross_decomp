#include "common.h"

void *bzero(char *s, s32 n) {
    void *r;
    if (s == 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    r = s;
    while (n > 0) {
        *s++ = 0;
        n--;
    }
    return r;
}
