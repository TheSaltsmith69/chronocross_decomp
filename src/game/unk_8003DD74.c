#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003DD74);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003E074);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003E444);

typedef struct {
    u8 pad0[0x2A];
    u16 unk2A;
    u8 pad2C[0x7E - 0x2C];
    u16 unk7E;
} Unk8003EC44_0;
typedef struct {
    Unk8003EC44_0 *unk0;
    u8 pad4[0x10];
    u32 unk14;
} Unk8003EC44;
extern s16 D_1F800010;
extern s32 D_8006B480;
s32 func_80030934(s32);

void func_8003EC44(void) {
    s32 i;
    Unk8003EC44 *p;
    Unk8003EC44_0 *o;
    i = 0;
    func_8009C718();
    while ((p = (Unk8003EC44 *)func_80030934(i++)) != NULL) {
        if (!(p->unk0->unk7E & 1) && ((p->unk14 >> 1) & 1)) {
            func_80096888(p->unk0);
        }
    }
    i = 0;
    while ((p = (Unk8003EC44 *)func_80030934(i++)) != NULL) {
        if (!(p->unk0->unk7E & 1) && ((p->unk14 >> 1) & 1)) {
            func_80094140(p->unk0);
        }
    }
    i = 0;
    while ((p = (Unk8003EC44 *)func_80030934(i++)) != NULL) {
        if (!(p->unk0->unk7E & 1) && ((p->unk14 >> 1) & 1)) {
            func_80094318(p->unk0);
        }
    }
    o = (Unk8003EC44_0 *)D_8006B480;
    if (o != NULL) {
        func_8009B1A0(o);
        func_80096354(D_8006B480, (s16)((u16)D_1F800010 * ((Unk8003EC44_0 *)D_8006B480)->unk2A));
        if (!(o->unk7E & 1)) {
            func_80096888(D_8006B480);
            func_80094140(D_8006B480);
            func_80094318(D_8006B480);
            func_800B42B8(D_8006B480);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003EE10);

typedef struct {
    s16 x, y, w, h;
} RECT_8003F2A8;
typedef struct {
    RECT_8003F2A8 disp;
    RECT_8003F2A8 screen;
    u8 isinter, isrgb24, pad0, pad1;
} DISPENV_8003F2A8;
extern s16 D_1F800010;
extern s32 D_80086FA8;
extern u16 D_80086FAC[];
extern u16 D_80086FB8_[] asm("D_80086FB8");
extern u16 D_80086FBC_[] asm("D_80086FBC");

void func_8003F2A8(void) {
    DISPENV_8003F2A8 env;
    s32 t, t2;
    if (D_1F800010 != 0) {
        if (D_80086FA8 != 0) {
            D_80086FA8--;
            D_80086FBC_[1] += D_80086FB8_[1];
            D_80086FBC_[0] += D_80086FB8_[0];
            if (D_80086FA8 == 0) {
                D_80086FBC_[1] = D_80086FAC[1];
                D_80086FBC_[0] = D_80086FAC[0];
            }
        }
        if ((D_80086FBC_[1] >> 8) != 0 || (D_80086FBC_[0] >> 8) != 0) {
            GetDispEnv(&env);
            env.screen.x = ((rand() & 0xFFFF) * ((s16)D_80086FBC_[0] >> 8)) / 0x10000 + (s16)D_80086FBC_[0] / 512;
            t = ((rand() & 0xFFFF) * ((s16)D_80086FBC_[1] >> 8)) / 0x10000;
            env.screen.y = t + (s16)((s16)D_80086FBC_[1] / 512 + 10);
            PutDispEnv(&env);
        }
    }
}

typedef struct Task8003F414 {
    void (*fn)(struct Task8003F414 *);
    struct Task8003F414 *next;
} Task8003F414;
extern u8 D_8006B394;
extern s32 D_8006B488;
extern u8 D_8006B3F4;
extern u8 D_8007EAA8[];
extern u8 D_8006B458;
extern u8 D_8007E9FD;
extern u16 D_8007EE08;
extern u16 D_8007EAAA;
extern s32 *D_8006B48C;

void func_8003F414(void) {
    Task8003F414 *t;
    if (D_8006B394 == 0) {
        D_8006B488++;
        func_8003F2A8();
        for (t = (Task8003F414 *)D_8006B48C; t != NULL; t = t->next) {
            t->fn(t);
        }
        if (D_8006B3F4 != 0 && D_8007EAA8[0x24] == 0 && (D_8007EAA8[0x25] >> 4) == 1) {
            func_80029B8C(&D_8007EAA8[0x24]);
        }
    }
    if (D_8006B458 != 0) {
        if (PadGetState(0) < 2) {
            D_8007E9FD = 0;
            D_8007EE08 = 0;
        } else {
            D_8007EE08 |= ~((D_8007EAAA >> 8) | ((D_8007EAAA & 0xFF) << 8));
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F528);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", .L8003F63C);

extern u8 D_8007E9FD;
extern s32 D_8006B480;
extern u8 D_8006B455;
extern u8 D_8006B47E;
extern u8 D_8006B47B;
extern u8 D_8006B47C;
extern s16 D_8006B476;
extern u8 D_8006B3F4;

void func_8003F7D4(void) {
    D_8007E9FD = 0;
    D_8006B480 = 0;
    D_8006B455 = 0;
    D_8006B47E = 0;
    D_8006B47B = 0;
    D_8006B47C = 0;
    D_8006B476 = 0;
    func_8003F934();
    func_8003B420();
    func_80042364();
    if (D_8006B3F4 != 0) {
        func_80336CD8();
        func_803356C8();
    }
    func_800328F0();
    func_80029F04();
    func_8002B400();
    func_8002BE30();
    func_800308A4();
}

void func_8003F884(u8 *arg0, u32 arg1) {
    while (arg1 > 4) {
        *(s32 *)arg0 = 0;
        arg1 -= 4;
        arg0 += 4;
    }
    while (arg1 != 0) {
        *arg0 = 0;
        arg1--;
        arg0++;
    }
}

extern s32 *D_8006B48C;
void func_8003F8C4(s32 *arg0) {
    s32 *prev = NULL;
    s32 *n;
    for (n = D_8006B48C; n != NULL; n = (s32 *)n[1]) {
        if (n == arg0) {
            if (prev != NULL) {
                prev[1] = n[1];
            } else {
                D_8006B48C = (s32 *)n[1];
            }
        }
        prev = n;
    }
}

extern s32 *D_8006B48C;
void func_8003F920(s32 *arg0) {
    arg0[1] = (s32)D_8006B48C;
    D_8006B48C = arg0;
}

void func_8003F934(void) {
    D_8006B48C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F940);

extern s16 D_80086FBC[];
extern s16 D_80086FB8[];
extern s32 D_80086FA8;
void func_8003F9AC(void) {
    D_80086FBC[1] = 0;
    D_80086FBC[0] = 0;
    D_80086FB8[1] = 0;
    D_80086FB8[0] = 0;
    D_80086FA8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003F9D8);

void func_80022964(void);
void func_80022974(void);
void func_80042B20(void);
void func_8003FA64(void) {
    s32 *p = (s32 *)func_80042B20;
    s32 i;
    func_80022964();
    for (i = 0; i != 0x400; i++) {
        *p++ = 0;
    }
    func_80042B20();
    func_80022974();
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003FAB4);

typedef struct Obj8003FB60 {
    u8 pad[0x1F4];
    s16 unk1F4;
    s16 unk1F6;
} Obj8003FB60;
void func_80095A08(Obj8003FB60 *, s16 *);
s32 SquareRoot0(s32);
void func_8003FB60(Obj8003FB60 *o) {
    s16 v[12];
    s32 t;
    func_80095A08(o, v);
    t = (v[1] << 12) / 1067;
    t -= 0x1000;
    t /= 2;
    t += 0x1000;
    if (t > 0x10000) {
        t = 0x8000;
    }
    if (t < 0x300) {
        t = 0x300;
    }
    o->unk1F4 = t;
    t = (SquareRoot0(v[0] * v[0] + v[2] * v[2]) << 12) / 572;
    t -= 0x1000;
    t /= 2;
    t += 0x1000;
    if (t > 0x10000) {
        t = 0x8000;
    }
    if (t < 0x300) {
        t = 0x300;
    }
    o->unk1F6 = t;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003DD74", func_8003FC70);
