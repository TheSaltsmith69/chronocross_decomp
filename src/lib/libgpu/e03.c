#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_de;
typedef struct {
    RECT_de clip;
    s16 ofs[2];
    RECT_de tw;
    u16 tpage;
    u8 dtd, dfe, isbg, r0, g0, b0;
} DRAWENV_d;
s32 func_800285D8(void);
DRAWENV_d *SetDefDrawEnv(DRAWENV_d *env, s32 x, s32 y, s32 w, s32 h) {
    s32 mode = func_800285D8();
    env->clip.x = x;
    env->clip.y = y;
    env->clip.w = w;
    env->tw.x = 0;
    env->tw.y = 0;
    env->tw.w = 0;
    env->tw.h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip.h = h;
    if (mode) {
        env->dfe = h < 0x121;
    } else {
        env->dfe = h < 0x101;
    }
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tpage = 10;
    env->isbg = 0;
    return env;
}
