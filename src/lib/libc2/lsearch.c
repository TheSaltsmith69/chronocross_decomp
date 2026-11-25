#include "common.h"

char *lsearch(char *key, char *base, s32 *nelp, s32 width, s32 (*compar)(char *, char *)) {
    while (compar(key, base) != 0) {
        base += width;
    }
    return base;
}
