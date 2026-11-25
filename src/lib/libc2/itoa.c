#include "common.h"

extern char D_8006CE30[];
extern char D_80056530[];
s32 func_80029B48(char *, char *, ...);
char *itoa(s32 n) {
    func_80029B48(D_8006CE30, D_80056530, n);
    return D_8006CE30;
}
