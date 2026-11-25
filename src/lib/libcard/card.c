#include "common.h"

void _new_card(void);
s32 _card_write(s32, s32, void *);
void _card_clear(s32 chan) {
    _new_card();
    _card_write(chan, 0x3F, 0);
}
