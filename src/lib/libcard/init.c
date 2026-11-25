#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libcard/init", InitCARD);

s32 func_80022964_q(void) asm("func_80022964");
s32 func_80022974_q(void) asm("func_80022974");
s32 func_80018D84_q(void) asm("func_80018D84");
s32 ChangeClearPAD_q(s32) asm("ChangeClearPAD");
s32 func_800190E4(void) {
    s32 s = func_80022964_q();
    func_80018D84_q();
    ChangeClearPAD_q(0);
    if (s == 1) {
        func_80022974_q();
    }
    return 0;
}

void func_80018D94(void);
void func_80019154(void);
s32 func_8001912C(void) {
    func_80018D94();
    func_80019154();
    return 0;
}
