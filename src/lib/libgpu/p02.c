#include "common.h"

extern s32 (*D_80063DDC_g)(char *, ...) asm("D_80063DDC");
extern char D_80056550[];
void DumpTPage(u16 tp) {
    D_80063DDC_g(D_80056550, (tp >> 7) & 3, (tp >> 5) & 3, (tp << 6) & 0x7C0,
                 ((tp << 4) & 0x100) | ((tp >> 2) & 0x200));
}
