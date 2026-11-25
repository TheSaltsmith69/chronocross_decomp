#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", ResetGraph);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetGraphDebug);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetGraphQueue);

extern u8 D_80063DE2;
s32 GetGraphDebug(void) {
    return D_80063DE2;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawSyncCallback);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetDispMask);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawSync);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80012018);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", ClearImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", ClearImage2);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", LoadImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", StoreImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", MoveImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", ClearOTag);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", ClearOTagR);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawPrim);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawOTag);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", PutDrawEnv);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawOTagEnv);

extern u8 D_80063DF0[];
void *memcpy(void *, void *, s32);
void *GetDrawEnv(void *env) {
    memcpy(env, D_80063DF0, 0x5C);
    return env;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", PutDispEnv);

extern u8 D_80063E4C[];
void *GetDispEnv(void *env) {
    memcpy(env, D_80063E4C, 0x14);
    return env;
}

typedef struct { u8 pad[0x38]; u32 (*status)(void); } GpuFuncs;
extern GpuFuncs *D_80063DD8;
u32 GetODE(void) {
    return D_80063DD8->status() >> 31;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetDrawArea);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetDrawOffset);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", SetDrawEnv);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80012FF4);

/* _get_mode */
u32 func_80013264(s32 dfe, s32 dtd, s32 tpage) {
    return (dtd ? 0xe1000200 : 0xe1000000) | (dfe ? 0x400 : 0) | (tpage & 0x9ff);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013284);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_8001331C);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800133B4);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800133D0);

extern volatile u32 *D_80063EE8;
u32 func_80013450(void) {
    return *D_80063EE8;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013468);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013548);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013778);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800139B4);

extern u8 D_8006CEB8[];
void func_80013C34(u32 x) {
    *D_80063EE8 = x;
    D_8006CEB8[x >> 24] = x;
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013C58);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013C6C);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013CAC);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013CF4);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013D24);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013D48);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80013FF8);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80014258);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800143A8);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_800144E4);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80014518);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_8001465C);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", LoadImage2);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", StoreImage2);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", MoveImage2);

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", DrawOTag2);

void DMACallback(s32, void (*)(void));
void func_80013FF8(void);
void _GPU_ResetCallback(void) {
    DMACallback(2, func_80013FF8);
}

INCLUDE_ASM("asm/nonmatchings/lib/libgpu/sys", func_80014B3C);
