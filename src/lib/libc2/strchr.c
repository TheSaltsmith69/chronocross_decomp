#include "common.h"

/* strchr */
char *func_800108E4(char *s, char c) {
    if (s == 0) {
        return 0;
    }
    do {
        if (*s == c) {
            return s;
        }
    } while (*s++ != 0);
    return 0;
}
