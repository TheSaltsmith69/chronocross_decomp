#include "common.h"

void *NextPrim(void *p) {
    return (void *)((*(u32 *)p & 0xffffff) | 0x80000000);
}
