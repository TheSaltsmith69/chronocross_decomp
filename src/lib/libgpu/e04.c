#include "common.h"

typedef struct { s16 x, y, w, h; } RECT_d;
typedef struct { RECT_d disp; RECT_d screen; u8 isinter, isrgb24, pad0, pad1; } DISPENV_d;
DISPENV_d *SetDefDispEnv(DISPENV_d *env, s32 x, s32 y, s32 w, s32 h) {
    env->disp.x = x;
    env->disp.y = y;
    env->disp.w = w;
    env->screen.x = 0;
    env->screen.y = 0;
    env->screen.w = 0;
    env->screen.h = 0;
    env->isrgb24 = 0;
    env->isinter = 0;
    env->pad1 = 0;
    env->pad0 = 0;
    env->disp.h = h;
    return env;
}
