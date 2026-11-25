#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libcard/init", InitCARD);

INCLUDE_ASM("asm/nonmatchings/lib/libcard/init", func_800190E4);

void func_80018D94(void);
void func_80019154(void);
s32 func_8001912C(void) {
    func_80018D94();
    func_80019154();
    return 0;
}
