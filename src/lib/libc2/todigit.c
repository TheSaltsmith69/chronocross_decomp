#include "common.h"

extern u8 D_80063CA1[];
char tolower(char c);
s32 func_80010D04(char c) {
    u8 t = D_80063CA1[(u8)c];
    if (t & 4) {
        return c - '0';
    }
    if (!(t & 3)) {
        return 9999999;
    }
    return tolower(c) - 'a' + 10;
}
