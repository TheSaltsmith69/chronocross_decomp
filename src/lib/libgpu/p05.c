#include "common.h"

s32 IsEndPrim(void *p) {
    return (*(u32 *)p & 0xffffff) == 0xffffff;
}
