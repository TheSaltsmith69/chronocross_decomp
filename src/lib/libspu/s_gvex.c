#include "common.h"

extern volatile u16 *D_8006AE10;
void SpuGetVoiceEnvelope(s32 voice, u16 *env) {
    *env = D_8006AE10[voice * 8 + 6];
}
