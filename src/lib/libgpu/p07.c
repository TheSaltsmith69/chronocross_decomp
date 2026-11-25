#include "common.h"

typedef struct { unsigned addr : 24; unsigned len : 8; } TAG_b;
void AddPrims(TAG_b *ot, TAG_b *p0, TAG_b *p1) {
    p1->addr = ot->addr;
    ot->addr = (u32)p0;
}
