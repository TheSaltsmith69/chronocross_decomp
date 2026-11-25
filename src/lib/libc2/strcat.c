#include "common.h"

s32 strlen(char *);
char *strcat(char *d, char *s) {
    char *r;
    if (d != 0) {
        if (s == 0) {
            return 0;
        }
        if (d + strlen(d) != s + strlen(s)) {
            r = d;
            while (*d++) {
            }
            d--;
            while ((*d++ = *s++) != 0) {
            }
            return r;
        }
    }
    return 0;
}
