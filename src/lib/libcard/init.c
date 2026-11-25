#include "common.h"

void ChangeClearPAD_i(s32) asm("ChangeClearPAD");
s32 VSync_i(s32) asm("VSync");
s32 func_80022964_i(void) asm("func_80022964");
s32 func_80022974_i(void) asm("func_80022974");
s32 ReadInitPadFlag_i(void) asm("ReadInitPadFlag");
void InitCARD2_i(s32) asm("InitCARD2");
void _copy_memcard_patch_i(void) asm("_copy_memcard_patch");
void func_80018F10_i(void) asm("func_80018F10");
void func_80018FA4_i(void) asm("func_80018FA4");
void func_80018E34_i(void) asm("func_80018E34");
void InitCARD(s32 val) {
    s32 s;
    ChangeClearPAD_i(0);
    VSync_i(0);
    s = func_80022964_i();
    if (ReadInitPadFlag_i() == 0) {
        val = 0;
    }
    InitCARD2_i(val);
    _copy_memcard_patch_i();
    func_80018F10_i();
    func_80018FA4_i();
    func_80018E34_i();
    if (s == 1) {
        func_80022974_i();
    }
}

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
