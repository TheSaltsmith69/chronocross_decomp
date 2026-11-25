#include "common.h"

void CatPrim(void *p0, void *p1) {
    *(u32 *)p0 = (*(u32 *)p0 & 0xff000000) | ((u32)p1 & 0xffffff);
}
