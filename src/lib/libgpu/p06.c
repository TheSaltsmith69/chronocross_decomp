#include "common.h"

typedef struct { unsigned addr : 24; unsigned len : 8; } TAG_a;
void AddPrim(TAG_a *ot, TAG_a *p) {
    p->addr = ot->addr;
    ot->addr = (u32)p;
}
