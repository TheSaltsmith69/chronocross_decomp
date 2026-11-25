#include "common.h"

char *strcpy(char *dst, char *src) {
    char *r;
    if (dst == 0) {
        return 0;
    }
    if (src == 0) {
        return 0;
    }
    r = dst;
    while ((*dst++ = *src++) != 0) {
    }
    return r;
}
