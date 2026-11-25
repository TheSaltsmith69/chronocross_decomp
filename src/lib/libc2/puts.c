#include "common.h"

extern char D_80056540[];
void func_800104B4_p(char) asm("func_800104B4");
void func_800105B0(void);
void puts(u8 *s) {
    char c;
    if (s == 0) {
        s = (u8 *)D_80056540;
    }
    while ((c = *s++) != 0) {
        func_800104B4_p(c);
    }
    func_800105B0();
}
