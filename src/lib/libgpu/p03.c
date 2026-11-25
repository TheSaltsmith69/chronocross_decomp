#include "common.h"

extern s32 (*D_80063DDC)(char *, ...);
extern char D_80056570[];
void DumpClut(u16 clut) {
    D_80063DDC(D_80056570, (clut & 0x3F) << 4, clut >> 6);
}
