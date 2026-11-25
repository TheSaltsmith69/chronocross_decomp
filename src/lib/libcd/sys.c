#include "common.h"

extern u8 D_8006428C;
s32 CdStatus(void) {
    return D_8006428C;
}

extern u8 D_8006429C;
s32 CdMode(void) {
    return D_8006429C;
}

extern u8 D_8006429D;
s32 CdLastCom(void) {
    return D_8006429D;
}

extern u8 D_80064298[];
u8 *CdLastPos(void) {
    return D_80064298;
}

INCLUDE_ASM("asm/nonmatchings/lib/libcd/sys", CdReset);

void CD_flush(void);
void CdFlush(void) {
    CD_flush();
}

extern s32 D_80064288;
s32 CdSetDebug(s32 level) {
    s32 old = D_80064288;
    D_80064288 = level;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/lib/libcd/sys", CdComstr);

INCLUDE_ASM("asm/nonmatchings/lib/libcd/sys", CdIntstr);

s32 CD_sync(s32, u8 *);
s32 CdSync(s32 mode, u8 *result) {
    return CD_sync(mode, result);
}

s32 CD_ready(s32, u8 *);
s32 CdReady(s32 mode, u8 *result) {
    return CD_ready(mode, result);
}

extern s32 D_80064280;
s32 CdSyncCallback(s32 func) {
    s32 old = D_80064280;
    D_80064280 = func;
    return old;
}

extern s32 D_80064284;
s32 CdReadyCallback(s32 func) {
    s32 old = D_80064284;
    D_80064284 = func;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/lib/libcd/sys", CdControl);

INCLUDE_ASM("asm/nonmatchings/lib/libcd/sys", CdControlF);

INCLUDE_ASM("asm/nonmatchings/lib/libcd/sys", CdControlB);

void CD_vol(void *);
s32 CdMix(void *vol) {
    CD_vol(vol);
    return 1;
}

s32 CD_getsector(void *, s32);
s32 CdGetSector(void *madr, s32 size) {
    return CD_getsector(madr, size) == 0;
}

s32 CD_getsector2(void *, s32);
s32 CdGetSector2(void *madr, s32 size) {
    return CD_getsector2(madr, size) == 0;
}

void DMACallback(s32, void (*)(void));
void CdDataCallback(void (*func)(void)) {
    DMACallback(3, func);
}

s32 CD_datasync(s32);
s32 CdDataSync(s32 mode) {
    return CD_datasync(mode);
}
