#include "common.h"
#include "ov_battle/battle_800A3E3C.h"
#include "ov_battle/battle_800AA9DC.h"

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B3E58);

typedef struct { s16 h[4]; } SB20;
extern SB20 D_800D9B20_s asm("D_800D9B20");
extern SB20 D_800D9B28_s asm("D_800D9B28");
void func_800B3E58();
u8 *func_8009C9F4(u8 *, void *);
s32 func_800B3F7C(u8 *a0) {
    s16 *q = *(s16 **)(a0 + 0x108);
    u8 *t = func_8009C9F4(a0, func_800B3E58);
    *(u8 **)(t + 0xC) = a0;
    *(SB20 *)(t + 0x10) = D_800D9B20_s;
    *(SB20 *)(t + 0x18) = D_800D9B28_s;
    *(s16 *)(t + 0x20) = D_800D9B30.x;
    *(s16 *)(t + 0x22) = D_800D9B30.y;
    *(s16 *)(t + 0x24) = q[1];
    *(s16 *)(t + 0x26) = q[2];
    *(s16 *)(t + 0x28) = q[3];
    *(s16 *)(t + 0x2A) = 0;
    *(s16 *)(t + 0x2C) = 1;
    return 4;
}

extern s32 D_800D86F4;
void func_8003DB78(char *);
s32 func_8003D8F4(s32, s32, s32);
void func_800B4058(s32 a0) {
    func_8003DB78("AFIMG BUF");
    D_800D86F4 = func_8003D8F4(0x3E80, a0, 4);
}

void func_800B4280(u8 *);
typedef struct SL { struct SL *next; u8 pad[8]; } SL;
typedef struct { u8 pad[0x148]; SL l[8]; } SLB;
void func_800B409C(void) {
    s32 i;
    u8 **o;
    if (D_800D86F4) {
        i = 0;
        while ((o = func_8003099C_(i++))) {
            SLB *b = (SLB *)*o;
            s32 k;
            if (!b) continue;
            for (k = 0; k < 8; k++) {
                SL *n = b->l[k].next;
                while (n != &b->l[k]) {
                    SL *nx = n->next;
                    func_800B4280((u8 *)n);
                    n = nx;
                }
            }
        }
        func_8003D504(D_800D86F4);
        D_800D86F4 = 0;
    }
}

typedef struct L9B38 { struct L9B38 *a; struct L9B38 *b; s32 c; } L9B38;
extern L9B38 D_800D9B38;
void func_800B417C(void) {
    s32 buf[12];
    s32 i = 0;
    u8 *p = (u8 *)D_800D86F4;
    D_800D9B38.a = &D_800D9B38;
    D_800D9B38.b = &D_800D9B38;
    D_800D9B38.c = 0;
    for (; i < 400; i++) {
        func_8009C920((s32)D_800D9B38.b, p);
        *(s32 *)(p + 8) = 0;
        p += 0x28;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B41EC);

extern s32 D_800D9B3C;
void func_8009C944(u8 *);
void func_8009C920(s32, u8 *);
void func_800B4280(u8 *p) {
    func_8009C944(p);
    func_8009C920(D_800D9B3C, p);
    *(s32 *)(p + 8) = 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B42B8);

void func_800B4A04();
u8 *func_800B4354(SLB *a0, s32 a1, s16 a2, s16 a3) {
    s32 i;
    for (i = a1 * 4; i < a1 * 4 + 4; i++) {
        if (a0->l[i].next == &a0->l[i]) break;
    }
    if (i >= a1 * 4 + 4) return 0;
    {
        u8 *t = func_8009C9F4((u8 *)a0, func_800B4A04);
        s32 o = a1 * 2;
        *(SLB **)(t + 0xC) = a0;
        *(s16 *)(t + 0x10) = a2;
        *(s16 *)(t + 0x12) = a3;
        *(s32 *)(t + 0x18) = 0;
        *(s32 *)(t + 0x14) = i;
        *(s16 *)((u8 *)a0 + o + 0x1A8) = i;
        return t;
    }
}

void func_800B4434(u8 *p, s32 i) {
    p += i * 2;
    *(s16 *)(p + 0x1A8) = -1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B4448);

s32 func_800B4614(s32 a0, s32 a1) {
    u8 *p = (u8 *)a0;
    s32 o2 = a1 * 2;
    s32 i = *(s16 *)(p + o2 + 0x1A8);
    if (i != -1) {
        s16 h;
        s32 n;
        func_800B4434(p, a1);
        h = *(s16 *)(p + 0x110);
        if (h < 0) {
            n = -h;
            if (n) {
                s32 o = i * 12;
                u8 *e = p + o;
                u8 *head = p + (o + 0x148);
                do {
                    if (*(u8 **)(e + 0x14C) != head) {
                        func_800B4280(*(u8 **)(e + 0x14C));
                    }
                } while (--n);
            }
        }
    }
    return 1;
}

void func_800B4448(s32, s32);
s32 func_800B46C0(s32 a0) {
    func_800B4448(a0, 0);
    return 3;
}

s32 func_800B46E0(s32 a0) {
    func_800B4448(a0, 1);
    return 3;
}

s32 func_800B4614(s32, s32);
s32 func_800B4700(s32 a0) {
    func_800B4614(a0, 0);
    return 1;
}

s32 func_800B4614(s32, s32);
s32 func_800B4720(s32 a0) {
    func_800B4614(a0, 1);
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B4740);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B4A04);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B4B34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B4D98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B4E88);

s32 func_800B53FC(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    *(s32 *)(p + 0x1B0) = *(u16 *)(q + 2) | (*(s16 *)(q + 4) << 16);
    *(s32 *)(p + 0x1B4) = *(u16 *)(q + 6) | (*(s16 *)(q + 8) << 16);
    return 5;
}

s32 func_800B5434(u8 *p) {
    *(u16 *)(p + 0x1AC) = *(u16 *)(*(u8 **)(p + 0x108) + 2);
    return 2;
}

s32 func_800B5450(u8 *p) {
    u8 *q = *(u8 **)(p + 0x108);
    *(s32 *)(p + 0x1B8) = *(u16 *)(q + 2) | (*(s16 *)(q + 4) << 16);
    return 3;
}

void **func_80030934(s32);
s32 func_800B5474(void) {
    s32 i = 0;
    u8 **r;
    while ((r = (u8 **)func_80030934(i)) != 0) {
        if (*r && *(s32 *)(*r + 0x108)) {
            return 1;
        }
        i++;
    }
    return 0;
}

void **func_8003099C(s32);
void *func_800B54D0(u8 *a0) {
    s32 i = 0;
    u8 **r;
    while ((r = (u8 **)func_80030934(i)) != 0) {
        i++;
        if (*r == a0) {
            return r;
        }
    }
    r = (u8 **)func_8003099C(-1);
    if (r && *r == a0) {
        return r;
    }
    return 0;
}

void **func_8003099C(s32);
void *func_800B5550(u8 *a0) {
    s32 i = 0;
    u8 **r;
    while ((r = (u8 **)func_8003099C(i)) != 0) {
        i++;
        if (*r == a0) {
            return r;
        }
    }
    r = (u8 **)func_8003099C(-1);
    if (r && *r == a0) {
        return r;
    }
    return 0;
}

void *func_800309D0(s32);
s32 *func_800B55D0(s32 a0) {
    s32 i = 0;
    s32 *r;
    while ((r = func_800309D0(i)) != 0) {
        if (*r == a0) {
            return r;
        }
        i++;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B5624);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B56BC);

extern s32 D_800D9C78;
extern s32 D_800D9C7C;
void func_800B56FC(void) {
    D_800D9C78 = 0;
    D_800D9C7C = 0;
}

void func_800B5710(void) {
    D_800D9C78 = (D_800D9C78 + 1) & 3;
}

typedef struct { s32 w[12]; } S572C;
extern u8 *D_800D9BE0[];
void func_800B572C(void) {
    s32 i = 0;
    u8 *p;
    while ((p = func_800309D0(i))) {
        ((S572C *)D_800D86FC)[D_800D9C7C * 9 + i] = *(S572C *)p;
        D_800D9BE0[D_800D9C7C * 9 + i] = p;
        i++;
    }
    D_800D9C70 = 0;
    D_800D9B48[D_800D9C7C] = i;
    D_800D9C7C = (D_800D9C7C + 1) & 3;
}

extern s32 D_800D86FC;
void func_8003D504(s32);
void func_800B582C(void) {
    if (D_800D86FC) {
        func_8003D504(D_800D86FC);
        D_800D86FC = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B5864);

void func_8009B0D8(void *, s32, s32);
void func_8009B1A0(void *);
extern s32 D_800A32E0;
void func_800B59D0(void) {
    s32 i = 0;
    void **r;
    while ((r = func_8003099C(i)) != 0) {
        func_8009B0D8(*r, 2, i++);
        D_800A32E0 = 1;
    }
    i = 0;
    while ((r = func_80030934(i)) != 0) {
        if (*r) {
            func_8009B1A0(*r);
        }
        i++;
    }
}

void **func_8003099C(s32);
void func_8009B0D8(void *, s32, s32);
extern s32 D_800A32F4;
extern s32 D_800A32DC;
extern s32 D_800A32E0;
void func_800B5A64(void) {
    s32 i = 0;
    void **r;
    while ((r = func_8003099C(i)) != 0) {
        func_8009B0D8(*r, 3, i++);
        D_800A32E0 = 2;
    }
    D_800A32F4 = 0;
    D_800A32DC = 0;
}

s32 func_800B5AD4(s32 x) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (x & 1) {
            return i;
        }
        x >>= 1;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B5AFC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B5C9C);

void func_8009B1A0(void *);
void func_800B600C(void) {
    s32 i = 0;
    void **r;
    while ((r = func_8003099C(i)) != 0) {
        i++;
        func_8009B0D8(*r, 5, 0);
    }
    i = 0;
    while ((r = func_80030934(i)) != 0) {
        if (*r) {
            func_8009B1A0(*r);
        }
        i++;
    }
}

void func_80097800(u8 *);
extern u8 D_800DDAA8;
extern s32 D_800D86F8;
extern u8 D_8006B238;
extern s32 D_800D9C74;
extern s32 D_8006B1F8;
void func_800B6088(void) {
    s32 i = 0;
    u8 **o;
    while ((o = func_8003099C_(i++))) {
        u8 *s = *o;
        if (D_800A32D4) {
            if (!D_800DDAA8 && (*(s32 *)(D_800A32D4 + 8) & 0x3F)) {
                func_80041C0C((s32)D_800A32D4);
                func_80097800(s);
            }
            func_8003D504((s32)D_800A32D4);
            D_800A32D4 = 0;
        }
    }
    D_8006B238 = 0;
    if (D_800D86F8) {
        func_80041C0C(D_800D86F8);
        func_8003D504(D_800D86F8);
        D_800D86F8 = 0;
    }
    func_800B409C();
    func_800B582C();
    if (D_800D9C74) {
        D_8006B1F8 = D_800D9C74;
        D_800D9C74 = 0;
    }
}

extern s32 D_800D9C70;
void func_800B6188(void) {
    D_800D9C70 = 0;
}

u8 *func_800B6194(s32 a0) {
    s32 *t = D_800D9B48;
    s32 k = D_800D9C78;
    if (a0 < t[k]) {
        return (u8 *)D_800D86FC + (k * 9 + a0) * 0x30;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B61EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B63B4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B66C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B6940);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B6BE4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B6EDC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B7210);

extern u8 D_800DB032;
void func_800BF660(s32);
void func_800B72D8(s32 a0, u8 a1) {
    S800DB078 *t;
    S800DB078 *e;
    if (a1) D_800DB032 = 4;
    t = D_800DB078;
    e = &t[a0];
    e->wB0 &= 0x9FFFFFFF;
    e->w1B0 &= 0x9FFFFFFF;
    D_800DDD38[a0].w20 &= 0x9FFFFFFF;
    func_8009B0D8(e->p190, 1, 0);
    func_800BF660(1);
    e->b1CF = 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B738C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B7898);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B8070);

extern u8 D_800DB035;
u8 func_800C82AC(u8);
void func_800B8070(void);
void func_800B81EC(void) {
    u8 r = 1;
    if (D_800DB035) {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (func_800C82AC(i) && !(D_800DB078[i].w1B0 & 0x20304000) && D_800DB078[i].h19E >= 10) {
                r = 0;
                break;
            }
        }
        if (r) func_800B8070();
    }
}

void func_800B738C(void);
void func_800B7898(void);
void func_800B81EC(void);
void func_800B829C(void) {
    func_800B738C();
    func_800B7898();
    func_800B81EC();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B82CC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B8614);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B89BC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B8AC4);

extern s16 D_800D9C82;
void func_800B8BD8(u8 *a0, u8 a1) {
    s16 v = *a0;
    switch (a1) {
    case 1:
        v += D_800D9C82 / 16;
        break;
    case 2:
        v += D_800D9C82 / 8;
        break;
    case 3:
        v += D_800D9C82 / 4;
        break;
    }
    if (v > 255) v = 255;
    *a0 = v;
}

extern s16 D_80071C76;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; u8 pad1[2]; u8 b1C; u8 b1D; u8 pad2[0x88]; u8 bA6; u8 bA7; u8 pad3[0x438 - 0xA8]; } T8C98;
extern T8C98 D_800DB078_t[] asm("D_800DB078");
void func_800B8C98(u8 a0) {
    T8C98 *p = &D_800DB078_t[a0];
    s32 v = p->bA6 & 0x7F;
    if (v < D_80071C76) {
        D_800D9C82 = D_80071C76 - v;
        if (D_800D9C82 < 0) D_800D9C82 = 0;
        func_800B8BD8(&D_800DB078_t[a0].b18, p->bA7 & 3);
        func_800B8BD8(&D_800DB078_t[a0].b19, (p->bA7 & 0xC) >> 2);
        func_800B8BD8(&D_800DB078_t[a0].b1C, (p->bA7 & 0x30) >> 4);
        func_800B8BD8(&D_800DB078_t[a0].b1D, p->bA7 >> 6);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B8D74);

extern char D_80355D44_l[] asm("D_80355D44");
extern s32 D_800D9C90;
s32 func_80044DD4(void);
s32 func_80044924(s32);
void func_80045F14(s32, s32, s32);
s32 func_800B918C(void) {
    s32 r;
    if (func_80044DD4()) return 0;
    func_8003DB78(D_80355D44_l);
    D_800DB078[D_800DA980.b4].w180 = func_8003D8F4(0x12000, 0, 3);
    if (D_800DA980.b2) {
        r = func_8003D8F4(func_80044924(0x77), 1, 3);
        D_800D9C90 = r;
        func_80045F14(0x77, r, 0);
    }
    return 1;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B9248);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B95A0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B98A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B9DA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800B9FB4);

extern u8 D_800DA987;
void func_800B8D74(void);
void func_8002B41C(void);
void func_800BA100(void) {
    if (D_800DA980.b2C) {
        D_800DA980.b2 = 2;
    } else {
        D_800DA980.b2 = 1;
    }
    D_800DA987 = 0;
    func_800B8D74();
    func_8002B41C();
}

void func_800BA14C(void) {
    D_800DA980.b5 = 1;
    D_800DA980.b6 = 1;
}

typedef struct { u8 pad0[2]; u8 b2, b3; u8 pad1[3]; u8 b7; u8 pad2[0x10]; u8 b18[3]; u8 b1B; } SBA164;
extern SBA164 D_800DA980_b asm("D_800DA980");
extern u8 D_800DA612[];
extern s32 D_800DBA68;
typedef struct { u8 pad[0x2D]; u8 b2D; u8 pad2[0x438 - 0x2E]; } TBA164;
extern TBA164 D_800DB078_ba[] asm("D_800DB078");
void func_800BA164(u8 a0) {
    s32 j = 2;
    if ((u8)(a0 - 1) < 3) {
        if (D_800DA612[2] != 0xFF) {
            SBA164 *d = &D_800DA980_b;
            d->b1B = 1;
            d->b2 = 0;
            d->b3 = a0;
            d->b7 = 0;
            for (; a0 != 0; a0--) {
                u8 v = D_800DB078_ba[j].b2D;
                if (v < 0x40) d->b18[j] = D_800DA612[j];
                else d->b18[j] = v;
                j--;
            }
            func_800B8D74();
            func_8002B41C();
        } else {
            func_8002B41C();
            func_8003D504(D_800DBA68);
        }
    }
}

extern u8 D_800DA614;
extern u8 D_80355D44[];
extern s32 D_800DBA68;
void func_8002B434(void);
void func_800BA24C(void) {
    if (D_800DA614 != 0xFF) {
        S800DA980 *s = &D_800DA980;
        s32 v = s->b1A;
        s->b5 = 1;
        s->b6 = 0;
        s->b4 = 2;
        D_800DA980.h0 = v;
    } else {
        func_8003DB78(D_80355D44);
        D_800DBA68 = func_8003D8F4(0x12000, 0, 3);
        func_8002B434();
    }
}

void bzero_b(void *, s32) asm("bzero");
void func_800308E0(void *);
void func_80030904(void *);
void func_800308F8(void *);
void func_800308EC(void *);
void func_80030910(void *);
void func_80030928(void *);
void func_800BC368(u8);
s32 func_800429B4(s32, s32);
extern s32 D_800D9CA8[];
S800DDD38 *func_800BA3B0(s32);
S800DDD38 *func_800BA418(s32);
S800DDD38 *func_800BA480(s32);
u8 *func_800BA4E8(void);
u8 *func_800BA4F4(void);
void func_800BA2C8(void) {
    s32 i;
    for (i = 0; i < 9; i++) bzero_b(&D_800DDD38[i], 0x30);
    func_800308E0(func_800BA3B0);
    func_80030904(func_800BA418);
    func_800308F8(func_800BA480);
    func_800308EC(func_800BA4E8);
    func_80030910(func_800BA4F4);
    func_80030928(func_800BA418);
    func_800BC368(0x14);
    for (i = 0; i < 4; i++) D_800D9CA8[i] = func_800429B4(D_800DA620, i + 1);
}

S800DDD38 *func_800A9E1C_p(void) asm("func_800A9E1C");
extern u8 D_800DA718[];
S800DDD38 *func_800BA3B0(s32 a0) {
    S800DDD38 *r;
    if (a0 < 0) {
        r = func_800A9E1C_p();
    } else if (D_800DA718[a0] == 0xFF) {
        r = 0;
    } else {
        r = &D_800DDD38[D_800DA718[a0]];
    }
    return r;
}

S800DDD38 *func_800A9E48_p(void) asm("func_800A9E48");
extern u8 D_800DDB60_a[] asm("D_800DDB60");
S800DDD38 *func_800BA418(s32 a0) {
    S800DDD38 *r;
    if (a0 < 0) {
        r = func_800A9E48_p();
    } else if (D_800DDB60_a[a0] == 0xFF) {
        r = 0;
    } else {
        r = &D_800DDD38[D_800DDB60_a[a0]];
    }
    return r;
}

S800DDD38 *func_800A9E24_p(void) asm("func_800A9E24");
S800DDD38 *func_800BA480(s32 a0) {
    S800DDD38 *r;
    if (a0 < 0) {
        r = func_800A9E24_p();
    } else if (((S800DAF20 *)((u8 *)&D_800DAF20 + a0))->bEF == 0xFF) {
        r = 0;
    } else {
        r = &D_800DDD38[((S800DAF20 *)((u8 *)&D_800DAF20 + a0))->bEF];
    }
    return r;
}

extern u8 D_800DA61C[];
u8 *func_800BA4E8(void) {
    return D_800DA61C;
}

extern u8 D_800DB00C;
extern s16 D_800DDF48;
extern s16 D_800DA6EE;
extern u8 D_800DA61C[];
u8 *func_800BA4F4(void) {
    if (D_800DB00C < 3) {
        if (D_800DDF48 < 2) {
            return 0;
        }
        return D_800DA61C;
    }
    if (D_800DA6EE > 0) {
        return D_800DA61C;
    }
    return 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BA54C);

s16 func_80027684(s32, s32);
void func_800BA6EC(u8 a0, s32 *a1) {
    S800DB1E4 *s = &D_800DB1E4[a0];
    u8 *o = s->p24;
    *(s16 *)(s->p24 + 0xA6) = func_80027684(*(s32 *)(o + 0x84) - a1[0], *(s32 *)(o + 0x8C) - a1[2]);
    s->b2F = (*(s16 *)(s->p24 + 0xA6) & 0xFFF) / 64;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BA780);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BA89C);

S800DDD38 *func_800BAC18(u8 i) {
    if (i == 0xFF) {
        return 0;
    }
    return &D_800DDD38[i];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BAC48);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BB01C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BB320);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BB720);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BB948);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BBF74);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BC130);

void func_80011554(u8 *);
void func_80011474(u8 *, s32);
void AddPrim_c(void *, void *) asm("AddPrim");
void SetDrawTPage(u8 *, s32, s32, s32);
void func_800BC274(s32 x, s32 y, s32 w, s32 h) {
    u8 *p = D_1F800014;
    D_1F800014 = p + 0x18;
    func_80011554(p);
    *(s16 *)(p + 0x8) = x;
    *(s16 *)(p + 0xA) = y;
    *(s16 *)(p + 0xC) = x + w;
    *(s16 *)(p + 0xE) = y;
    *(s16 *)(p + 0x10) = x;
    *(s16 *)(p + 0x12) = y + h;
    *(s16 *)(p + 0x14) = x + w;
    *(s16 *)(p + 0x16) = y + h;
    p[4] = 0x50;
    p[5] = 0x50;
    p[6] = 0x50;
    func_80011474(p, 1);
    AddPrim_c(D_80086FB4 + 0x4070, p);
    {
        u8 *t = D_1F800014;
        D_1F800014 = t + 8;
        SetDrawTPage(t, 0, 0, 0x40);
        AddPrim_c(D_80086FB4 + 0x4070, t);
    }
}

extern s32 D_800DAB08[];
extern s32 D_800DA620;
void func_80041F6C(s32);
void func_800BC368(u8 i) {
    s32 v = D_800DAB08[i >> 2];
    D_800DA620 = v;
    func_80041F6C(v);
}

void func_800BC3A0(s16 a0, s16 a1, s32 a2, s32 a3, s32 a4) {
    func_80042928(a0, a1, D_800DA620, a2, D_80086FB4 + 0x4070, a3, a4);
}

void func_800BC3F8(s16 a0, s16 a1, s32 a2, s32 a3, s32 a4) {
    func_80042928(a0, a1, D_800DA620, a2, D_80086FB4 + 0x4074, a3, a4);
}

extern s32 D_800DA620;
void func_80042928(s16, s16, s32, s32, void *, s32, s32);
void func_800BC450(s16 a0, s16 a1, s32 a2, s32 a3, s32 a4) {
    s32 buf[8];
    func_80042928(a0, a1, D_800DA620, a2, buf, a3, a4);
}

void func_800BC4A0(s16 a0, s16 a1, s32 a2) {
    func_80042928(a0, a1, D_800DA620, a2, D_80086FB4 + 0x4070, 0, 0x80808080);
}

extern u8 *D_80086FB4;
void func_800BC4F8(s16 a0, s16 a1, s32 a2, s32 a3) {
    func_80042928(a0, a1, D_800DA620, a2, D_80086FB4 + 0x4070, 0, a3);
}

extern u16 D_800D8D3C[];
u16 func_800BC54C(u8 i) {
    return D_800D8D3C[i];
}

extern u16 D_800D8D3C[];
u16 func_800BC56C(u8 i) {
    return ~D_800D8D3C[i];
}

u16 func_800BC594(u16 m, u8 i) {
    return D_800D8D3C[i] & m;
}

extern u32 D_800D8D5C[];
u32 func_800BC5B4(u8 i) {
    return D_800D8D5C[i];
}

extern u32 D_800D8D5C[];
u32 func_800BC5D4(u8 i) {
    return ~D_800D8D5C[i];
}

u32 func_800BC5F4(u32 m, u8 i) {
    return m & D_800D8D5C[i];
}

extern u8 D_800DA608[];
void func_800BC614(u32 a0) {
    u32 d = 100000000;
    s32 i;
    for (i = 0; i < 9; i++) {
        D_800DA608[i] = a0 / d;
        a0 = a0 % d;
        d /= 10;
    }
    for (i = 1; i < 9; i++) {
        if (D_800DA608[i] != 0) {
            if (D_800DA608[i - 1] == 0) D_800DA608[i - 1] = 0xFF;
            return;
        }
        D_800DA608[i - 1] = 0xFF;
    }
}

void func_8004A18C(u16, s32, s32, s32);
extern u8 D_800D8698;
extern u16 D_8006EBBE;
void func_800BC6C4(s32 a0) {
    S800DAF20 *d = &D_800DAF20;
    u8 ok = 1;
    if (d->b130 == 0) {
        return;
    }
    if (d->b100 == 0) {
        return;
    }
    if (D_800D8698) {
        ok = D_8006EBBE != 0x1D8;
    }
    if (ok) {
        func_8004A18C(a0, 0x800000, 0x80, 0x7F);
    }
}

u32 func_800BC744(u32 *p) {
    u32 n = p[0];
    u32 i;
    for (i = 0; i < n; i++) {
        p[i + 1] = (u32)p + p[i + 1];
    }
    return n;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BC77C);

typedef struct { s32 x; s32 off[1]; } S5783C;
extern S5783C D_8005783C;
extern u8 D_800DDB38[];
u8 *func_800BC8DC(s32 a0, s32 a1) {
    u8 *b;
    if (a0 == 4) {
        u32 k = a1 - 0xC7;
        if (k < 3) {
            return D_800DDB38 + k * 12;
        }
    }
    b = (u8 *)&D_8005783C + D_8005783C.off[a0];
    return b + ((u16 *)b)[a1];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BC940);

void func_800BCC7C(void) {
}

u16 func_800BC594(u16, u8);
extern u16 D_800DDF40;
void func_800BCC84(void) {
    s32 i;
    for (i = 0; i < 9; i++) {
        if (func_800BC594(D_800DDF40, i)) {
            *(u16 *)(D_800DB078[i].p190 + 0x7E) &= 0xFFFD;
            if (D_800DB078[i].hB8 != 0 && !(D_800DB078[i].w1B0 & 0x80) && D_800DB078[i].h1C8 == 0) {
                *(u16 *)(D_800DB078[i].p190 + 0x7E) &= 0xFFFC;
            }
        }
    }
}

void func_800C85DC(void);
void func_800BCC84(void);
void func_800BCD44(void) {
    func_800C85DC();
    func_800BCC84();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BCD6C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BD2BC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BD414);

extern u8 D_800DB028;
void func_800BC368(u8);
void func_800BC3A0(s16, s16, s32, s32, s32);
void func_800BD548(void) {
    s32 n = D_800DB028 + 1;
    func_800BC368(0);
    func_800BC3A0(0x12C, 0x16, n, 2, 0x60606060);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BD598);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BD780);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BD980);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BDACC);

void func_800BDACC(s32, s32, s32, s32, u8, s32, s32, s32, s32);
void func_800BDD54(s32 a0, s32 a1, s32 a2, s32 a3, u8 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    func_800BDACC(a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

extern s32 D_800D9D98;
extern s32 D_800D9DA8;
extern s32 D_800D9DB8;
void func_800BDACC(s32, s32, s32, s32, u8, s32, s32, s32, s32);
void func_800BDD98(s32 a0, s32 a1, s32 a2, s32 a3, u8 a4, s32 a5) {
    func_800BDACC(a0, a1, a2, a3, a4, a5, D_800D9D98, D_800D9DA8, D_800D9DB8);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BDDE8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BE098);

extern s16 D_800D8F90[];
extern s16 D_800D8F98[];
void func_800BE51C(u32 a0, s32 a1) {
    if (a0) {
        u32 mask = 0x33377339;
        s32 i, k, row;
        func_800BC368(0x78);
        i = 0;
        row = 7;
        for (k = i; i < 32; i++) {
            if (func_800BC5F4(mask, i)) {
                if (func_800BC5F4(a0, i)) {
                    func_800BC4A0(D_800D8F90[(u8)a1 * 2 + k / 9], D_800D8F98[k], row);
                    k++;
                }
                row++;
            }
        }
    }
}

void func_800BE51C(u32, s32);
extern u8 D_800DB021;
void func_800BE630(void) {
    func_800BE51C(D_800DB078[D_800DB021].w1B0 & 0x22166139, 0);
}

void func_800BE51C(u32, s32);
extern u8 D_800DB01A;
void func_800BE688(void) {
    func_800BE51C(D_800DB078[D_800DB01A].w1B0 & 0x22166139, 1);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BE6E0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BEBEC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BED70);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BEEEC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BF078);

extern u8 D_800DABE0;
extern u8 D_800D8AB0[];
void func_800BF078(s32, s32);
void func_800BC368(u8);
void func_800BC4A0_l(s32, s32, s32) asm("func_800BC4A0");
void func_800BF4A8(void) {
    if (D_800DABE0) {
        u8 *d = (u8 *)&D_800DAF20;
        u8 k;
        *(s16 *)(d + 0x5C) = 8;
        *(s16 *)(d + 0x5E) = 0x16;
        if (d[0x81]) func_800BF078(0, 1);
        if (d[0xE9]) {
            func_800BC368(0xB4);
            func_800BC4A0_l(8, 0x16, 1);
        } else {
            k = d[0x81];
            if (k == 0x3F) k = 0x21;
            if (k) {
                func_800BC368(D_800D8AB0[k] * 4 + 0x14);
                func_800BC4A0_l(8, 0x16, 3);
            }
        }
    }
}

typedef struct { s16 x, y, w, h; } RECTF578;
extern u8 D_800D9048;
void MoveImage_(RECTF578 *, s32, s32) asm("MoveImage");
void DrawSync_(s32) asm("DrawSync");
void func_800BF578(u8 a0) {
    RECTF578 r;
    if (D_800D9048) {
        r.x = 0x2C0;
        r.y = a0 * 12 + 0x100;
        r.w = 0xC;
        r.h = 0xC;
        MoveImage_(&r, 0x200, 0xE0);
        D_800D9048 = 0;
    }
    DrawSync_(0);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BF5EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BF660);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BF714);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BFA80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800BFBA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C011C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C04D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C07D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C0A18);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C0B7C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C0D94);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C0EE4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1058);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1228);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C14F8);

void func_800C1058(void);
void func_800C1228(void);
void func_800C3B80(void);
void func_800C1944(void) {
    s32 pad[2];
    D_800DAF20.h110 += 2;
    func_800C1058();
    func_800C1228();
    func_800C3B80();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1988);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C19E8);

typedef struct { s16 x, y, w, h; } RECT1B34;
extern u8 D_800D9248;
void MoveImage2_(RECT1B34 *, s32, s32) asm("MoveImage2");
void func_800C1B34(u8 a0) {
    RECT1B34 r;
    if (D_800D9248) {
        r.x = 0x2C0;
        r.y = a0 * 12 + 0x100;
        r.w = 0xC;
        r.h = 0xC;
        MoveImage2_(&r, 0x200, 0xE0);
        D_800D9248 = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1BA0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1D08);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1E80);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C1FC4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C2044);

void func_800C303C(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_800C2114(void) {
    if (D_800DA648[D_800DDF4C & 0xF].b6) {
        u8 *d;
        func_800C303C(3, 0x20, 0x90, 0x100, 10, 0, 0, 0, 0x10);
        d = (u8 *)&D_800DAF20;
        *(s16 *)(d + 0x13E) = 0x78;
        *(s16 *)(d + 0x140) = 1;
        D_800DA648[D_800DDF4C & 0xF].b5 = 3;
        D_800DA648[D_800DDF4C & 0xF].b6 = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C21D8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C23D4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C25D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C2BE0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C303C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C3188);

u16 GetTPage_(s32, s32, s32, s32) asm("GetTPage");
u16 GetClut_(s32, s32) asm("GetClut");
u8 *func_800C3250(void) {
    u8 *p = D_1F800014;
    D_1F800014 = p + 0x28;
    p[3] = 9;
    p[7] = 0x2C;
    p[4] = 0x80;
    p[5] = 0x80;
    p[6] = 0x80;
    *(u16 *)(p + 0x16) = GetTPage_(0, 0, 0x380, 0x100);
    *(u16 *)(p + 0xE) = GetClut_(0x1F0, 0xF0);
    *(u16 *)(p + 0x16) |= 0x40;
    p[7] |= 2;
    return p;
}

typedef struct { s16 x, y, w, h; } RECT_;
void SetTexWindow(void *, RECT_ *);
void AddPrim(void *, void *);
void func_800C32E0(s16 a0, s16 a1, s16 a2, s16 a3) {
    RECT_ r;
    u8 *prim;
    r.x = a0;
    r.y = a1;
    r.w = a2;
    r.h = a3;
    prim = D_1F800014;
    D_1F800014 = prim + 0xC;
    SetTexWindow(prim, &r);
    AddPrim(D_80086FB4 + 0x4070, prim);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C333C);

extern u8 D_800DABD8[];
void func_800C333C(u16, u16, u16, u16);
void func_800C3A48(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_800DAF20.b118 == 0 && D_800DAF20.b103 != 2 && D_800DABD8[i] == 2) {
            func_800C333C(D_800DAC50[i].a, D_800DAC50[i].b, D_800DAC50[i].c, D_800DAC50[i].d);
        }
    }
}

extern u8 D_800DABD8[];
void func_800C25D0(void);
void func_800C333C(u16, u16, u16, u16);
void func_800C3AFC(void) {
    s32 i;
    func_800C25D0();
    for (i = 3; i < 5; i++) {
        if (D_800DABD8[i] == 2) {
            func_800C333C(D_800DAC50[i].a, D_800DAC50[i].b, D_800DAC50[i].c, D_800DAC50[i].d);
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C3B80);

extern u8 *D_80086FB4;
extern u8 D_8007EE88[];
extern s32 D_800DDC20;
extern u8 D_8006EB78[];
extern u8 *D_8007EE0C;
extern u8 *D_8007EDFC;
void ClearOTagR_l(u8 *, s32) asm("ClearOTagR");
void func_8003CC2C(s32);
void func_80032FAC(u8 *);
void func_800307F8(u8 *);
void func_8003E444(void);
void func_800BC77C(void);
void func_800C3D98(void) {
    u8 *v = D_80086FB4;
    u8 *b = D_8007EE88;
    if (v == b) b += 0x4090;
    D_80086FB4 = b;
    ClearOTagR_l(b + 0x70, 0x1000);
    ClearOTagR_l(D_80086FB4 + 0x4070, 8);
    func_8003CC2C(D_800DDC20 = (D_800DDC20 == 0));
    func_80032FAC(D_8006EB78);
    D_8007EDFC = D_8007EE0C = D_80086FB4 + 0x70;
    func_800307F8(D_80086FB4 + 0x78);
    D_8007EDFC = D_80086FB4 + 0x4070;
    func_800307F8(D_80086FB4 + 0x4078);
    func_8003E444();
    func_800BC77C();
}

s32 VSync_i(s32) asm("VSync");
typedef struct { s16 h[4]; } S3E60;
extern u8 D_800D92E0;
extern u8 D_800D92E1;
extern S3E60 D_800DABC8;
extern S3E60 D_800DDD28;
extern s16 D_8007EDF8;
extern s16 D_8007EDFA;
void PutDispEnv(u8 *);
void PutDrawEnv(u8 *);
void DrawOTag(u8 *);
void func_800C3E60(void) {
    s32 a = VSync_i(1);
    s32 b;
    DrawSync_(0);
    D_800D92E0 = 1;
    D_800D92E1 = 0;
    D_800DABC8 = *(S3E60 *)(D_80086FB4 + 0x5C);
    b = VSync_i(1);
    D_8007EDF8 = a;
    D_8007EDFA = b;
    ((void (*)(s32))func_800AA188)(0);
    PutDispEnv(D_80086FB4 + 0x5C);
    PutDrawEnv(D_80086FB4);
    D_800DDD28 = *(S3E60 *)D_80086FB4;
    DrawOTag(D_80086FB4 + 0x406C);
    DrawOTag(D_80086FB4 + 0x408C);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C3F5C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C421C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C4500);

void func_800C476C(void) {
    S800DDD38 *t = D_800DDD38;
    s32 a = D_800DDC28.b6F;
    s32 b = D_800DDC28.b6E;
    t[a].w14 &= ~4;
    t[b].w14 &= ~4;
}

void func_800C47C8(void) {
    S800DDD38 *t = D_800DDD38;
    s32 a = D_800DDC28.b6F;
    s32 b = D_800DDC28.b6E;
    t[a].h10 = 2;
    t[b].h10 = 2;
}

void func_800C4810(void) {
    D_800DDD38[D_800DDC97].h10 = 2;
}

extern u8 D_800DDCA9;
void func_800C47C8(void);
void func_800C483C(void) {
    if (!D_800DDCA9) {
        func_800C47C8();
    }
}

void func_800C4868(void) {
    if (!D_800DDCA9) {
        func_800C4810();
    }
}

void func_800C4894(void) {
    S800DDD38 *t = D_800DDD38;
    S800DDD38 *e;
    t[D_800DDC28.b6F].h10 = 1;
    e = &t[D_800DDC28.b6E];
    if (e->h10 == 0xFF) {
        e->h10 = 1;
        func_800C476C();
    }
}

void func_800C4908(void) {
    S800DDD38 *t = D_800DDD38;
    s32 a = D_800DDC28.b6F;
    s32 b = D_800DDC28.b6E;
    t[a].h10 = 3;
    t[b].h10 = 3;
    func_800C476C();
}

void func_800C4968(void) {
    S800DDD38 *t = D_800DDD38;
    s32 a = D_800DDC28.b6F;
    s32 b = D_800DDC28.b6E;
    t[a].h10 = 0;
    t[b].h10 = 0;
}

typedef struct { u8 pad[4]; u16 h4; u8 pad2[2]; } SDBD0;
extern SDBD0 D_800DDBD0[];
void func_800C49AC(void) {
    SDBD0 *t = D_800DDBD0;
    S800DDC28 *c = &D_800DDC28;
    if (t[c->b6E].h4 & 4) c->h66 = c->h66 * 125 / 100;
    if (t[c->b6F].h4 & 8) c->h66 = c->h66 * 75 / 100;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C4A68);

u16 func_80019690(s32, s32);
u8 func_800C4D08(void) {
    D_800DDC28.b81 = 0;
    if (func_80019690(1, 0x63) <= *(s16 *)((u8 *)D_800DDC28.p + 0xA)) {
        D_800DDC28.b81 = 1;
    }
    return D_800DDC28.b81;
}

void func_800C4D68(void) {
    S800DDC28 *d = &D_800DDC28;
    if (d->w58 & d->w4C) {
        d->b70 = 1;
    }
    if (d->w5C & d->w54) {
        d->b71 = 1;
    }
}

void func_800C4DB0(void) {
    u32 m = D_800DDC28.w54 & 0xE007FFFF;
    if (*(u32 *)(D_800DDC28.p + 0x1C) & m) {
        D_800DDC28.b71 = 1;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C4DE8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C50AC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C52F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C542C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C5658);

void func_800C5658(void);
void func_800C50AC(s32);
void func_800C5964(void) {
    func_800C5658();
    func_800C50AC(1);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C598C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C5ACC);

void func_800C49AC(void);
void func_800C5CC4(void) {
    S800DDC28 *c = &D_800DDC28;
    c->h66 = c->h74;
    func_800C49AC();
    D_800DDD38[c->b6F].h2A = c->h66;
    if (c->h66) {
        if (c->w54 & 0x2000000) {
            func_800C4968();
        } else {
            func_800C4908();
        }
    } else {
        func_800C4894();
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C5D64);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C5F0C);

typedef struct { u8 pad[0x62]; s16 h62; u8 pad2[0x10]; s16 h74; } SC61A4;
extern SC61A4 D_800DDC28_c asm("D_800DDC28");
void func_800C61A4_d(s16 a0) asm("func_800C61A4");
void func_800C61A4_d(s16 a0) {
    s32 i, sum;
    sum = i = 0;
    for (; i <= D_800DDC28_c.h62; i++) {
        sum += a0 * 100 - func_80019690(0, (u16)a0);
    }
    D_800DDC28_c.h74 = sum / 400;
    if (D_800DDC28_c.h74 < 0) D_800DDC28_c.h74 = 1;
}

void func_800C61A4(s32);
void func_800C6284(void) {
    func_800C61A4(*(s16 *)(D_800DDC28.p + 0xA));
}

void func_800C62B0(void) {
    func_800C61A4(*(s16 *)(D_800DDC28.p + 0xC));
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C62DC);

void func_800C62DC(s32);
void func_800C6494(void) {
    func_800C62DC(*(s16 *)(D_800DDC28.p + 0x8));
}

void func_800C64C0(void) {
    D_800DDC28.h74 = *(u16 *)(D_800DDC28.p + 0xA);
}

extern u16 D_8007104E;
void func_800C62DC(s32);
void func_800C64DC(s16 a0) {
    func_800C62DC((s16)(*(u16 *)(D_800DDC28.p + 8) + D_8007104E * a0));
}

void func_800C6528(s16 a0) {
    S800DB078 *t = D_800DB078;
    S800DDC28 *c = &D_800DDC28;
    if ((s16)(t[c->b6F].h19E += a0 * 10) >= 0x47) {
        t[c->b6F].h19E = 0x46;
    }
}

u16 func_80019690(s32, s32);
void func_800C65B8(s16 a0) {
    s32 i;
    for (i = 0; i < 80; i++) {
        if (func_80019690(0, 99) < a0) {
            u16 v = D_800DB078[D_800DDC28.b6F].h1D4[i];
            if (v & 1) D_800DB078[D_800DDC28.b6F].h1D4[i] = v & 0xFFFE;
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C6670);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C67F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C692C);

void func_800C6B9C(void) {
}

s32 func_800C692C();
u8 func_800C6BA4(void) {
    return func_800C692C(*(s32 *)(D_800DDC28.p + 0x18), *(u32 *)(D_800DDC28.p + 0x1C) & 0xE007FFFF);
}

void func_800C6670(u8, u8);
void func_800C6BDC(u32 a0, u8 a1) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (func_800BC5F4(a0, i)) {
            func_800C6670(i, a1);
        }
    }
}

void func_800C67F8_b(u8, u8, u8) asm("func_800C67F8");
void func_800C6C4C(s32 a0, u32 a1, s32 a2) {
    u32 m[2];
    s32 i, j;
    m[0] = a0;
    m[1] = a1;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 0x20; i++) {
            if (func_800BC5F4(m[j], i)) {
                func_800C67F8_b(i, j, a2);
            }
        }
    }
}

void func_800C6C4C(s32, u32, s32);
void func_800C6CE4(void) {
    func_800C6C4C(*(s32 *)(D_800DDC28.p + 0x18), *(u32 *)(D_800DDC28.p + 0x1C) & 0xE007FFFF, 0);
}

s32 func_800C692C();
u8 func_800C6D20(void) {
    return func_800C692C();
}

void func_800C67F8(s32, s32, s32);
void func_800C6D40(s32 a0) {
    if (!(a0 & 0x4000)) {
        func_800C67F8(0xE, 0, 0);
    }
    if (!(a0 & 0x100000)) {
        func_800C67F8(0x14, 0, 0);
    }
}

void func_800C6D94(void) {
}

void func_800C6D9C(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C6DA4);

extern u8 D_800DA611;
extern u8 D_800DDEEE;
extern u8 D_8007E9E8[];
void func_800C71CC(void) {
    if (D_800DA611 && D_8006B440) {
        func_800BC368(0xB0);
        if (D_800DDEEE) {
            u16 f = *(u16 *)D_8007E9E8;
            if (f & 2) {
                func_800BC3A0(0xE8, 0x90, 1, 3, 0x80808080);
            } else if (f & 1) {
                func_800BC3A0(0xE8, 0x90, 2, 3, 0x80808080);
            }
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C7274);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C7300);

void func_800CC358(void);
void func_800C3AFC(void);
void func_800C3A48(void);
void func_800C80B8(void) {
    func_800CC358();
    func_800C3AFC();
    func_800C3A48();
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C80E8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C80F4);

extern u8 D_800DAE54;
extern s32 D_800DAAE8;
void func_800BF660(s32);
void VSync(s32);
void func_800C8144(void) {
    if (D_800DAE54) {
        func_800BF660(1);
        VSync(0);
        D_800DAE54 = 0;
        func_8003D504(D_800DAAE8);
    }
}

void func_800C8190(void) {
    D_800DAF20.bE8 = 0;
    D_800DAF20.bE7 = 0;
    D_800DAF20.b6B = 0;
    D_800DAF20.bE6 = 5;
}

extern s32 D_80071C78;
typedef struct { u8 pad0[0x101]; u8 b101; u8 pad1[4]; s16 h106; u8 pad2[0x3E]; s16 h146[3]; } SC81B0;
extern SC81B0 D_800DAF20_c8 asm("D_800DAF20");
void func_800C81B0(void) {
    if ((D_80071C78 & 3) && (D_80071C78 & 2)) {
        s32 i;
        for (i = 2; i >= 0; i--) {
            if (D_800DAF20_c8.h146[i] >= 80) {
                s32 k;
                if (D_800DB078[D_800DAF20_c8.b101].w1B0 & 0x2000) k = (i * 500) / 40;
                else k = i * 10;
                if (D_800DB078[D_800DAF20_c8.b101].h19E >= k + 10) {
                    D_800DAF20_c8.h106 = i;
                    return;
                }
            }
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C82AC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C8338);

void func_800BCD44(void);
void func_800329B8(s32);
extern u8 D_800DDB60;
void func_800C8580(void) {
    S800DAF20 *d = &D_800DAF20;
    d->b112 = 5;
    d->bEC = d->b101;
    func_800BCD44();
    if (d->b109 == 0) {
        D_800DDB60 = d->b101;
        func_800329B8(0x306D6C65);
    }
}

void func_80032D78(s32);
void func_80029F58(s32);
void func_800C85DC(void) {
    func_80032D78(0);
    func_80029F58(0);
}

void func_800AA94C(void);
void func_800B6188(void);
void func_800C8338(void);
void func_800C8604(void) {
    func_800AA94C();
    func_800B6188();
    func_800C8338();
    *(u16 *)(D_800DDB30 + 0xE0) = 0;
}

void func_800458F4(void);
extern u8 D_800DB039;
extern u8 D_8006EB5C;
void func_800329B8(s32);
void func_800C8644(s32 a0, s32 a1) {
    func_800C85DC();
    D_800DB032 = 5;
    if ((u8)a0) func_800329B8((func_80019690(D_8006EB5C * 2, D_8006EB5C * 2 | 1) << 24) + 0x30727061);
    func_800B5A64();
    D_800DDAA8 = 0;
    if (func_80044DD4()) D_800DDAA8 = 1;
    func_800458F4();
    while (func_80044DD4()) func_800BF660(1);
    while (D_800A32E0) func_800BF660(1);
    while (func_800B5474()) func_800BF660(1);
    func_800B6088();
    D_800DB039 = 0;
}

void func_800B5864(void);
void func_800B59D0(void);
void func_800BA54C(u8, u8);
extern u8 D_8006EB5C;
void func_800C8748(void) {
    S800DAF20 *d = &D_800DAF20;
    d->b112 = 5;
    func_800329B8((func_80019690(D_8006EB5C * 2, (D_8006EB5C * 2) | 1) << 24) + 0x30727061);
    func_800B5864();
    func_800B59D0();
    d->b119 = 1;
    func_800BA54C(d->bFA, d->b101);
}

void func_800C87C0(void) {
    D_800DAF20.bEE = 0xFF;
    D_800DAF20.bED = 0xFF;
    D_800DAF20.bEC = 0xFF;
    D_800DAF20.bF7 = 0xFF;
    D_800DAF20.bF6 = 0xFF;
    D_800DAF20.bF5 = 0xFF;
    D_800DAF20.bF4 = 0xFF;
    D_800DAF20.bF3 = 0xFF;
    D_800DAF20.bF2 = 0xFF;
    D_800DAF20.bF1 = 0xFF;
    D_800DAF20.bF0 = 0xFF;
    D_800DAF20.bEF = 0xFF;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C8800);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C8A5C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C8BB8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C8D64);

u8 func_800C8BB8(u8);
u8 func_800C8D64(u8);
void func_800C8F04(u8 a0, u8 a1, u8 a2) {
    if (a1) {
        if (a0) {
            if (func_800C8BB8(a2)) {
                func_800C8D64(a2);
            }
        } else {
            if (func_800C8D64(a2)) {
                func_800C8BB8(a2);
            }
        }
    } else {
        if (a0) {
            func_800C8BB8(a2);
        } else {
            func_800C8D64(a2);
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C8F98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C91FC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C92F0);

void func_800C92F0(void);
s32 func_800C8F98(s32, s32);
void func_800C8F04_l(s32, s32, s32) asm("func_800C8F04");
void func_800C8580(void);
void func_800C99D8(void) {
    u8 *d;
    func_800C92F0();
    d = (u8 *)&D_800DAF20;
    d[0x5A] = 1;
    d[0xEB] = 1;
    *(s16 *)(d + 0xE4) = func_800C8F98(D_800DB078[d[0x101]].h16E, 1);
    d[0x66] = 0xFF;
    *(s16 *)(d + 0x68) = 0xFF;
    *(s16 *)(d + 0x5C) = 0x153;
    d[0x67] = 0;
    d[0x80] = 0;
    d[0x58] = 0;
    *(s16 *)(d + 0x106) = 5;
    func_800C8F04_l(1, 1, 0);
    d[0x137] = 1;
    d[0x136] = 1;
    d[0x135] = 1;
    func_800C8580();
}

s32 func_800CBE90(u8, u8);
typedef struct { u8 pad0[0x5B]; u8 b5B; u8 pad1[0xA5]; u8 b101, b102, b103; u8 pad2[4]; u8 b108, b109; u8 pad3[9]; u8 b113; u8 pad4[7]; u8 b11B; u8 pad5[0x13]; u8 b12F; u8 pad6[4]; u8 b134; } S9A94;
extern S9A94 D_800DAF20_c asm("D_800DAF20");
typedef struct { u8 pad[0x11]; u8 b11; u8 b12; u8 b13; } S9A94b;
extern S9A94b D_800DA728_c[] asm("D_800DA728");
u8 func_800C9A94_d(u8 a0, u8 a1) asm("func_800C9A94");
u8 func_800C9A94_d(u8 a0, u8 a1) {
    s32 k = func_800CBE90(a0, a1);
    func_8009B0D8(D_800DB078[k].p190, 1, 0);
    D_800DAF20_c.b103 = 0;
    D_800DAF20_c.b108 = 0;
    D_800DA728_c[D_800DAF20_c.b101].b13 = 0;
    D_800DA728_c[D_800DAF20_c.b101].b11 = 0;
    D_800DABD8[D_800DAF20_c.b101] = 0;
    D_800DAF20_c.b5B = 0;
    D_800DAF20_c.b102 = 0;
    D_800DAF20_c.b109 = 0;
    D_800DAF20_c.b113 = 0;
    D_800DAF20_c.b134 = 0;
    D_800DAF20_c.b12F = 0;
    func_800C85DC();
    D_800DAF20_c.b11B = 0;
    return k;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C9B7C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C9CE0);

extern u8 D_8006EB5C;
extern u8 D_800DDFA7;
void func_800BB320(s32, s32, u8, s32);
void func_800C9E40(void) {
    D_800DDFA7 = D_8006EB5C;
    D_8006EB5C = 0;
    func_800BB320(0x80, 1, D_800DB078[D_800DB021].b434, 1);
    D_8006EB5C = D_800DDFA7;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800C9EBC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CA270);

void func_800CA60C(void) {
    s32 i, n;
    for (n = i = 0; i < D_800DAF20.b12F; i++) {
        n += D_800DAF20.b128[i] + 1;
    }
    if (n >= 8) {
        D_800DAF20.b12F = 0;
        D_800DAF20.b134 = 0;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CA670);

extern u8 D_800DABD8[];
void func_800C8644(s32, s32);
void func_800CAB14(void) {
    if (D_800A32E0 == 0) {
        u8 *t = D_800DABD8;
        S800DAF20 *d = &D_800DAF20;
        t[d->b101] = 0;
        if (d->h116 < 0 && d->b115) {
            func_800C8644(0, 1);
            d->b112 = 0;
            d->b103++;
        }
    }
}

extern s32 D_800A32E0;
s32 func_800C9A94(s32, s32);
void func_800BC6C4(s32);
void func_800CAB90(void) {
    if (!D_800A32E0) {
        D_800DAF20.b10A = func_800C9A94(D_800DAF20.b101, 0) + 1;
        func_800BC6C4(0x16);
    }
}

extern u8 D_800DB021;
extern u16 D_800DA790[][80];
u8 func_800CABDC(u8 a0) {
    s32 i;
    u8 r = 0;
    if (D_800DB078[D_800DB021].h16E >= a0) {
        for (i = 0; i < 10; i++) {
            if (D_800DA790[D_800DB021][a0 * 10 + i] != 0 && !(D_800DB078[D_800DB021].h1D4[a0 * 10 + i] & 0x40)) {
                r = 1;
                break;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CAC98);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CB3F0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CB780);

extern u8 D_800DAA50;
extern u8 D_800DABE0;
void func_800C8190(void);
void func_800CB9A4(void) {
    S800DAF20 *d = &D_800DAF20;
    if (d->h116 < 0 && d->b115) {
        D_800DAA50 = 1;
        D_800DABE0 = 0;
        if (!d->b6B) {
            d->b6B = 1;
        }
        if (d->b6B == d->bE6) {
            func_800C8190();
            d->b103++;
        }
    }
}

extern u8 D_800D9480;
void func_800C99D8(void);
u8 func_800C82AC(u8);
s32 func_800C9A94(s32, s32);
void func_800BC6C4(s32);
void func_800CBA30(void) {
    s32 i;
    S800DAF20 *t;
    func_800C99D8();
    for (i = 0; i < 9; i++) {
        if (func_800C82AC(i)) {
            *(s16 *)(D_800DB078[i].p190 + 0xA6) = D_800DB078[i].b1BF << 6;
        }
    }
    t = &D_800DAF20;
    t->b112 = 5;
    if (D_800D9480) {
        t->b10A = func_800C9A94(t->b101, 0) + 1;
        func_800BC6C4(0x16);
        D_800D9480 = 0;
    } else {
        D_800D9480 = 1;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CBAE0);

s32 func_800C9A94(s32, s32);
void func_800BC6C4(s32);
void func_800CBCF4(void) {
    D_800DAF20.b10A = func_800C9A94(D_800DAF20.b101, 0) + 1;
    func_800BC6C4(0x16);
}

void func_8003F940(s32, s32, s32, s32);
extern u8 D_800DDD31;
extern u8 D_800DB034;
extern u8 D_800DDD32;
extern SA648 *D_800DABD4;
typedef struct { u8 pad[0x95]; u8 b95; u8 b96; } SBD34;
extern SBD34 D_800DA9B8_bd asm("D_800DA9B8");
void func_800CBD34(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (func_800C82AC(i)) func_8009B0D8(D_800DB078[i].p190, 7, 0);
    }
    func_8003F940(0x637365, 0x800000, 0x80, 0x7F);
    D_800DDD31 = 1;
    D_800DB034 = 1;
    if (D_800DA9B8_bd.b96) {
        D_800DABD4 = &D_800DA648[D_800DDD32 & 0xF];
        D_800DABD4->b4 = 5;
        D_800DABD4->b5 = 1;
        D_800DA9B8_bd.b95 = 0x50;
        D_800DA9B8_bd.b96 = 0;
        D_800DDD32++;
    }
}

extern u8 D_800DA612[];
s32 func_800CBE20(u8 a0) {
    s32 r = 0;
    if (D_800DA612[a0] != 0xFF) {
        S800DB078 *t = D_800DB078;
        S800DB078 *e = &t[a0];
        if (!(e->w1B0 & 0x20304080)) {
            r = e->h19E >= 10;
        }
    }
    return r;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CBE90);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CBF84);

u8 func_800CBF84(u8, u16, u16, u16, u16, u8, s32);
u8 func_800CC060(u8 a0, u16 a1, u16 a2, u16 a3, u16 a4, u8 a5) {
    return func_800CBF84(a0, a1, a2, a3, a4, a5, 4);
}

u8 func_800CC0A8(u8 a0, u16 a1, u16 a2, u16 a3, u16 a4, u8 a5) {
    return func_800CBF84(a0, a1, a2, a3, a4, a5, 0x10);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CC0F0);

extern s32 D_800DADF8;
void func_800CC164(s16 a0, s16 a1, s32 a2) {
    func_80042928(a0, a1, D_800DADF8, a2, D_80086FB4 + 0x4070, 3, 0x80808080);
}

u8 func_800CC1C0(u8 *s) {
    s32 n = 0;
    while (1) {
        u8 c = *s;
        if (c < 0x20) {
            break;
        }
        if (c >= 0xF8) {
            s++;
        }
        s++;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CC1F8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CC358);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CC6B8);

extern s32 D_800DDFB0;
extern s32 D_800DDFB4;
extern s32 D_800DDFB8;
void func_8003D504(s32);
void func_800CC9AC(void) {
    func_8003D504(D_800DDFB0);
    func_8003D504(D_800DDFB4);
    func_8003D504(D_800DDFB8);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CC9F4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CD058);

void func_800CD160(void) {
}

s16 func_800CD168(s16 a0, u8 a1) {
    S800DB078 *t = D_800DB078;
    S800DB078 *e = &t[a1];
    s16 v = e->h16E + a0;
    if (v >= e->h1BC) {
        v = e->h1BC;
    }
    if (v < -1) {
        v = -1;
    }
    return v;
}

u8 func_800C6BA4(void);
void func_800C4968(void);
void func_800C6BDC_l(s32, s32) asm("func_800C6BDC");
void func_800C4DB0(void);
void func_800C4DE8(s32);
void func_800C5F0C(void);
void func_800C5964(void);
void func_800C6D9C(void);
void func_800CD1E0(void) {
    u8 r = 1;
    u8 v = func_800C6BA4();
    u8 *p = D_800DDC28.p;
    if (*(s16 *)(p + 0xE) & 0x8000) r = (v == 0);
    if ((*(u16 *)(p + 0xE) & 0x4000) && (D_800DDC28.w54 & 0x2000000)) {
        func_800C4968();
        r = 0;
        func_800C6BDC_l(0x80, 0);
    }
    if (r) {
        func_800C4DB0();
        func_800C4DE8(1);
        func_800C5F0C();
        func_800C5964();
        func_800C6D9C();
    }
}

void func_800C6CE4(void);
void func_800C4868(void);
void func_800CD29C(void) {
    S800DDD38 *t = D_800DDD38;
    S800DDC28 *c = &D_800DDC28;
    t[c->b6F].h10 = 0;
    if (!(*(u16 *)((u8 *)D_800DDC28.p + 0xE) & 1)) {
        c->b81 = func_800C6BA4();
    } else {
        func_800C6CE4();
    }
    func_800C4868();
}

u8 func_800C6D20_b(u32, s32) asm("func_800C6D20");
void func_800CD31C(void) {
    S800DDC28 *c;
    u8 v = func_800C6BA4();
    c = &D_800DDC28;
    c->b81 = v;
    if (!v) {
        c->b81 = func_800C6D20_b(func_80019690(0, 1) ? 0x40000 : 0x20000, 0);
    }
    D_800DDD38[D_800DDC97].h10 = 0;
    func_800C483C();
}

void func_800C6284(void);
void func_800C598C(void);
void func_800C6CE4(void);
void func_800C6528(s16);
void func_800C65B8(s16);
void func_800CD3A4(void) {
    if (*(s16 *)((u8 *)D_800DDC28.p + 0xE) == 0) {
        func_800C6284();
        func_800C598C();
        func_800C6CE4();
        func_800C6528(*(s16 *)((u8 *)D_800DDC28.p + 8));
    }
    func_800C65B8(*(s16 *)((u8 *)D_800DDC28.p + 0xC));
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CD418);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CD75C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CD7E4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CD8B4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CD9FC);

s32 func_800C4D08_i(void) asm("func_800C4D08");
s16 func_800CD168(s16, u8);
void func_800CDA94(void) {
    if (func_800C4D08_i()) {
        S800DB1E4 *s = &D_800DB1E4[D_800DDC28.b6F];
        s->h2 = func_800CD168(*(s16 *)((u8 *)D_800DDC28.p + 8), D_800DB021);
    }
    func_800C483C();
}

s32 func_800C4D08_i(void) asm("func_800C4D08");
u8 func_800C6D20_b(u32, s32) asm("func_800C6D20");
void func_800CDB04(void) {
    if (func_800C4D08_i()) {
        S800DDC28 *c = &D_800DDC28;
        u8 k;
        do {
            k = func_80019690(0, 0x1F);
        } while (!func_800BC5F4(0x8E8EA939, k));
        c->b81 = func_800C6D20_b(func_800BC5B4(k), 0);
    }
    func_800C483C();
}

s32 func_800C4D08_i(void) asm("func_800C4D08");
void func_800C483C(void);
void func_800CDB80(void) {
    if (func_800C4D08_i()) {
        S800DB1E4 *s = &D_800DB1E4[D_800DDC97];
        if (s->h32 >= 0) {
            s->h32 = 0;
        }
    }
    func_800C483C();
}

extern s16 D_800DB004;
extern u8 D_800DDCA9;
void func_800C47C8(void);
void func_800CDBEC(void) {
    s32 i, j;
    if (D_800DB004 >= 2) {
        for (i = 0; i < D_800DB004; i++) {
            for (j = 0; j < 10; j++) {
                D_800DB078[D_800DDC28.b6F].h1D4[i * 10 + j] &= 0xFFFE;
            }
        }
    } else {
        D_800DDCA9 = 0;
        func_800C47C8();
    }
}

extern u8 *D_800DDC34;
void func_800C6D20_a(u32, s32) asm("func_800C6D20");
s32 func_800C4D08_i(void) asm("func_800C4D08");
void func_800C483C(void);
void func_800CDCA0(void) {
    if (func_800C4D08_i()) {
        u32 s = *(u32 *)(D_800DDC34 + 0xB0) & 0xAA9EED39;
        func_800C6D20_a(s, 0);
        func_800C6C4C(s, 0, 1);
    }
    func_800C483C();
}

void func_800CD1E0(void);
void func_800CD3A4(void);
void func_800CDD00(void) {
    s32 c = D_800DDC97 >= 3;
    if (c) {
        func_800CD1E0();
    } else {
        func_800CD3A4();
    }
    D_800DDD38[D_800DDC96].h10 = 3;
}

s32 func_800C6BA4_i(void) asm("func_800C6BA4");
void func_800CDD6C(void) {
    if (!func_800C6BA4_i()) {
        func_800C4DB0();
        func_800C4DE8(1);
        func_800C5F0C();
        func_800C5964();
    } else {
        func_800C4968();
    }
}

extern u8 D_800DDC94;
void func_800C4A68(void);
void func_800C4D68(void);
void func_800C5D64(void);
void func_800C542C(void);
void func_800C6B9C(void);
void func_800C6D40(s32);
void func_800CDDC4(void) {
    func_800C4A68();
    if (!D_800DDC94) {
        func_800C4D68();
        func_800C4DE8(0);
        func_800C5D64();
        func_800C542C();
        func_800C6B9C();
        func_800C6D40(0);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CDE28);

void func_800CE01C(u16 *a0, u8 *a1, u8 a2, s16 a3) {
    s32 i;
    u8 f = 1;
    for (i = 0; i < a3; i++) {
        if (a0[i] == a2) {
            f = 0;
            if (++a1[i] >= 100) a1[i] = 99;
            break;
        }
    }
    if (f) {
        for (i = 0; i < a3; i++) {
            if (a0[i] == 0) {
                a0[i] = a2;
                a1[i] = 1;
                return;
            }
        }
    }
}

typedef struct { u8 pad0[0x84]; u8 b84[7]; u8 pad1[0xB]; u8 b96; u8 b97; } SA9B8;
extern SA9B8 D_800DA9B8;
extern u8 D_80071760[];
extern u16 D_800DAC18[];
extern u8 D_8006EBC1;
void func_800CE0E4(void) {
    s32 i;
    if (D_800DA9B8.b96 && !D_8006EBC1 && D_800DA9B8.b97) {
        i = 0;
        do {
            if (D_800DAC18[i] & 0x8000) func_800CE01C((u16 *)D_80071760, D_80071760 + 0x180, *(u8 *)&D_800DAC18[i], 0xC0);
            else func_800CE01C((u16 *)(D_80071760 - 0x480), D_80071760 - 0x480 + 0x300, *(u8 *)&D_800DAC18[i], 0x180);
            i++;
        } while (i < D_800DA9B8.b97);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CE1C0);

void func_800CE5EC(void) {
}

extern u8 D_800DDCA9;
void func_800C4DB0(void);
void func_800C4DE8(s32);
void func_800C6494(void);
void func_800C5964(void);
u8 func_800C6BA4(void);
void func_800C6D40(s32);
void func_800CE5F4(void) {
    func_800C4DB0();
    func_800C4DE8(1);
    func_800C6494();
    func_800C5964();
    D_800DDCA9 = func_800C6BA4();
    func_800C6D40(0);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CE644);

void func_800CE6FC(void) {
}

void func_800C4DE8(s32);
void func_800C5F0C(void);
void func_800C5ACC(void);
void func_800CE704(void) {
    func_800C4DB0();
    func_800C4DE8(1);
    func_800C5F0C();
    func_800C5ACC();
}

extern u8 D_800D8AB0[];
extern s32 D_800D957C[];
void func_800CE73C(void) {
    if (func_80019690(0, 0x63) < *(s16 *)((u8 *)D_800DDC28.p + 0xA)) {
        func_800C6BDC(D_800D957C[D_800D8AB0[(*(u8 **)((u8 *)&D_800DDC28 + 0x10))[1] >> 2] - 1], 0);
    } else {
        D_800DDC28.b81 = 0;
    }
}

extern u8 D_800DAAF8[];
void func_800C4DB0(void);
void func_800C4DE8(s32);
void func_800C5F0C(void);
void func_800C5964(void);
void func_800CE7C8(void) {
    s32 i;
    func_800C4DB0();
    func_800C4DE8(1);
    func_800C5F0C();
    func_800C5964();
    D_800DAF20.bE7 = 1;
    D_800DAF20.bE6 = 13;
    D_800DAF20.bE8 = 2;
    for (i = 0; i < 4; i++) {
        D_800DAAF8[i + 8] = ((u8 *)D_800DDC28.p)[0xE];
        D_800DAAF8[i + 4] = ((u8 *)D_800DDC28.p)[0xC];
        D_800DAAF8[i] = ((u8 *)D_800DDC28.p)[0xA];
    }
}

void func_800CE878(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CE880);

void func_800CEA5C(void) {
    S800DDC28 *c;
    func_800CD1E0();
    c = &D_800DDC28;
    if (!(c->w54 & 0x10000)) {
        S800DDD38 *t = D_800DDD38;
        S800DB078 *u = D_800DB078;
        s32 a = c->b6E;
        s32 b = c->b6F;
        t[b].h2A = t[a].h2A = u[b].hB8 / 2;
    }
}

void func_800CEB04(void) {
    D_800DDD38[D_800DDC96].h12 = *(u16 *)(D_800DDB30 + 0xDE);
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CEB38);

void func_800C64C0(void);
void func_800C5CC4(void);
void func_800CECB4(void) {
    func_800C64C0();
    func_800C5CC4();
}

void func_800C4968(void);
void func_800CECDC(void) {
    func_800C4968();
    D_800DAF20.bEC = 0;
    D_800DAF20.bED = 4;
}

typedef struct { u8 pad[5]; u8 b5; u8 pad2[0x26]; } S2C;
extern u16 D_800D95AC[];
extern S2C *D_800DDEF0;
void func_800CED10(u8 a0) {
    s32 i;
    for (i = 0; i < 0x12; i++) {
        D_800DDEF0[D_800D95AC[i]].b5 = (D_800DDEF0[D_800D95AC[i]].b5 & 3) | (a0 & 0xFC);
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CED70);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CEE10);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CEF34);

typedef struct { u8 pad[0x176]; s16 h176; } S76698;
extern S76698 D_80076698;
typedef struct { u8 pad[0x16]; u8 b16; u8 pad2[0x19]; } SDD38b;
extern SDD38b D_800DDD38_b[] asm("D_800DDD38");
u16 func_80019690(s32, s32);
void func_800C64DC_l(s32) asm("func_800C64DC");
void func_800C6D40(s32);
void func_800C4DB0(void);
void func_800C4DE8(s32);
void func_800C5964(void);
void func_800CF4C0(void) {
    s32 r = 1;
    S76698 *g = &D_80076698;
    if (func_80019690(0, 15) < g->h176) {
        r = 2;
        g->h176 = 0;
    }
    D_800DDD38_b[D_800DDC28.b6E].b16 = D_800DDD38_b[D_800DDC28.b6F].b16 = r - 1;
    func_800C4DB0();
    func_800C4DE8(1);
    func_800C64DC_l(r);
    func_800C5964();
    func_800C6D40(0);
}

extern u8 D_800D95D6;
s32 func_800BC54C_i(u8) asm("func_800BC54C");
void func_800CF57C(void) {
    u8 ok = 1;
    s32 m;
    s32 i;
    u8 *p;
    do {
        m = func_800BC54C_i(func_80019690(0, 5));
        for (i = 0; i < 3; i++) {
            if (!((D_800DB078[i].b1 >> 2) & (s16)m)) {
                ok = 0;
                break;
            }
        }
    } while (ok);
    i = 11;
    p = D_800DAAF8 + i;
    D_800DAF20.bE7 = 1;
    D_800DAF20.bE6 = 0xD;
    for (; i >= 0; i--) *p-- = m;
    D_800D95D6 = 1;
    D_800DDD38[D_800DDC96].h2A = m * 4;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CF67C);

extern u16 D_8006EBBE;
void func_800CF8C0(void) {
    s32 i;
    D_800DB078[D_800DDC28.b6F].h19E = 70;
    if (D_8006EBBE == 0x1D8 && D_800DDC28.b6F < 3) {
        for (i = 0; i < 80; i++) {
            if (D_800DB078[D_800DDC28.b6F].hCC[i]) {
                D_800DB078[D_800DDC28.b6F].h1D4[i] &= 0xFFFE;
            }
        }
    }
}

void func_800D06A8(s32);
void func_800C47C8(void);
void func_800CF97C(void) {
    D_800DDC28.b6C = 1;
    D_800DAF20.b11B = 0;
    D_800DAF20.h14C = 0;
    func_800D06A8(1);
    D_800DDC28.b81 = 0;
    func_800C47C8();
}

void func_800CDE28(void);
void func_800CF9C8(void) {
    if ((D_800DDD38[D_800DDC28.b6E].w14 >> 15) & 1) {
        func_800CDE28();
    } else {
        D_800DDC28.b81 = 0;
        func_800C47C8();
    }
}

void bzero_(void *, s32) asm("bzero");
void func_800CFA34(void) {
    s32 i;
    u16 v = 0xFFFF;
    for (i = 8; i >= 0; i--) {
        D_800DDD38[i].h2A = v;
    }
    bzero_(&D_800DDC28, 0xA4);
    D_800DDC28.b85 = 0xFF;
    D_800DDC28.b84 = 0xFF;
    D_800DDC28.b83 = 0xFF;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800CFA98);

u16 func_800BC594(u16, u8);
extern u16 D_800DDF40;
void func_800D0508(void) {
    s32 i;
    for (i = 0; i < 9; i++) {
        if (func_800BC594(D_800DDF40, i)) {
            D_800DB078[i].w1B0 = D_800DB078[i].wA8 | D_800DB078[i].wB0;
            D_800DB078[i].w1B4 = D_800DB078[i].wAC | D_800DB078[i].wB4;
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D058C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D06A8);

extern u16 D_800DA790_2[][80] asm("D_800DA790");
s16 func_800D09A0(u16 a0, u8 a1) {
    s32 i;
    s32 r;
    for (i = 0; i < 0x50; i++) {
        if (a0 == D_800DA790_2[a1][i]) {
            r = i / 10 + 1;
            break;
        }
    }
    return -r;
}

typedef struct { u8 pad[0x131]; u8 b131[3]; } T0A14;
extern T0A14 D_800DAF20_ta asm("D_800DAF20");
void func_800D0A14(u8 a0) {
    S800DB078 *base = D_800DB078;
    S800DB078 *e = &base[a0];
    if ((u16)e->h1CA == 0) D_800DDD38[a0].w14 |= 1;
    e->wB0 |= 0x80;
    if (a0 < 3) {
        D_800DDD38[a0].w14 &= ~0x200;
        e->wB0 &= 0x400480;
        e->wB4 &= 0x1FE00000;
        D_800DAF20_ta.b131[a0] = 0;
        if (D_800DDC97 == a0) D_800DDB30[0x830] = 1;
        D_800DDB30[a0 + 0x685] = 0xFF;
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D0B1C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D0BD8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D14EC);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D1728);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D1AB0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D1C18);

extern u8 D_800D8AB0[];
extern u8 D_800DA612[];
void func_800D1D20(u8 a0) {
    u16 k = D_800D8AB0[a0] - 1;
    u8 f = 0;
    if (a0) {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (D_800DA612[i] == 0x2B) {
                f = 1;
                break;
            }
        }
        if (f && k < 6) {
            u8 *p = D_800DDB30 + (k + 2) * 2;
            if (++*(u16 *)(p + 0x84) > 0xFFFE) *(u16 *)(p + 0x84) = 0xFFFF;
        }
    }
}

extern u8 D_800DAE55;
extern u8 D_800DB03E;
extern u8 D_800DDC97;
extern u8 D_800D8AB0[];
void func_800D1DD0(void) {
    u8 r = 1;
    if (D_800DDC28.b6E < 3 && D_800DDC28.b6F >= 3 && D_800DAE55 != 0) {
        if (D_800DB03E == 1) {
            r = D_800D8AB0[((u8 *)D_800DDC28.p)[5] >> 2] != D_800DAE55;
        }
    } else {
        r = 0;
    }
    if (r) D_800DDD38[D_800DDC97].h2A = 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D1E88);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D27FC);

u16 func_800D294C(u8 *p) {
    s32 i;
    s32 j;
    u32 m;
    i = 0;
    m = 0xFF;
    for (; i < 0x20; i++) {
        if ((p + i)[0x40] < m) {
            j = i;
        }
    }
    p[0x80] = j;
    p[0x81] = (p + j)[0x60];
    return *(u16 *)(p + (j << 1));
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D29A8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D2B78);

u16 func_800D2CEC(u8 *p) {
    s32 i;
    for (i = 1; i < 0x20; i++) {
        if ((p + i)[0x40] == 0xFF) {
            break;
        }
    }
    return i;
}

extern u8 D_800D9624[];
u8 func_800D2D20(s32 a0, u8 *a1) {
    return D_800D9624[*a1];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D2D3C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D2DC0);

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D2B78(s32, s32, s32);
u8 func_800D2E04(s32 a0, u8 *a1) {
    u8 *e;
    s32 k;
    a0 <<= 2;
    e = *(u8 **)(D_800DDB30 + a0);
    func_800D29A8(a1, 2, a1[5], 0);
    if (func_800D2B78(*(s16 *)(D_800DDB30 + 0x6A4), *(s16 *)(D_800DDB30 + 0x6A6), a1[5])) {
        return D_800D9624[a1[0]];
    }
    k = e[0x80] << 1;
    *(u16 *)(e + k) = a1[6] + (a1[7] << 8);
    return 0;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D2EB8);

void func_800D2F44(void) {
}

void func_800D2F4C(void) {
}

void func_800D2F54(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D2F5C);

void func_800D29A8(u8 *, s32, s32, s32);
u16 func_800BC594(u16, u8);
extern u16 D_800DDF40;
extern s32 D_800DDFD8;
s32 func_800D2FB8(s32 a0, u8 *a1) {
    s32 k;
    func_800D29A8(a1, 1, 0, 1);
    k = D_800DDB30[0x6A4] + 0x20;
    if (func_800BC594(D_800DDF40, k)) {
        (*(u8 **)(D_800DDB30 + (a0 << 2)))[0x83] = k;
        return 3;
    }
    (*(u8 **)(D_800DDB30 + (a0 << 2)))[0x83] = 9;
    (D_800DDB30 + D_800DDFD8)[0x684] = 0xFF;
    return 0x7FFF;
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D3078(s32 a0, u8 *a1) {
    u8 *b;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    *(u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = *(u16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

u8 func_800D30E8(s32 a0, u8 *a1) {
    u8 *b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = 1;
    return D_800D9624[a1[0]];
}

u8 func_800D312C(s32 a0, u8 *a1) {
    u8 *b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = 0;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D316C(s32 a0, u8 *a1) {
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    p = (u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84);
    *p += *(u16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D31E8(s32 a0, u8 *a1) {
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    p = (u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84);
    *p -= *(u16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D3264(s32 a0, u8 *a1) {
    u16 v;
    func_800D29A8(a1, 2, a1[5], 0);
    v = func_800BC54C(D_800DDB30[0x6A6]);
    *(u16 *)(D_800DDB30 + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) |= v;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u16 func_800BC56C(u8);
u8 func_800D32F8(s32 a0, u8 *a1) {
    u16 v;
    func_800D29A8(a1, 2, a1[5], 0);
    v = func_800BC56C(D_800DDB30[0x6A6]);
    *(u16 *)(D_800DDB30 + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) &= v;
    return D_800D9624[a1[0]];
}

u8 func_800D338C(s32 a0, u8 *a1) {
    u8 *b = D_800DDB30;
    *(u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) += 1;
    return D_800D9624[a1[0]];
}

u8 func_800D33D8(s32 a0, u8 *a1) {
    u8 *b = D_800DDB30;
    *(u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) -= 1;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D3424(s32 a0, u8 *a1) {
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    p = (u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84);
    *p &= *(u16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D34A0(s32 a0, u8 *a1) {
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    p = (u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84);
    *p |= *(u16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D351C(s32 a0, u8 *a1) {
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    p = (u16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84);
    *p ^= *(u16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D3598(s32 a0, u8 *a1) {
    s32 k = ((a1[2] << 8) | a1[1]) >> 1;
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, 0, 1);
    b = D_800DDB30;
    p = (u16 *)(b + k * 2 + 0x84);
    *p <<= *(s16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D3620(s32 a0, u8 *a1) {
    s32 k = ((a1[2] << 8) | a1[1]) >> 1;
    u8 *b;
    u16 *p;
    func_800D29A8(a1, 2, 0, 1);
    b = D_800DDB30;
    p = (u16 *)(b + k * 2 + 0x84);
    *p >>= *(s16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

u16 func_80019690(s32, s32);
u8 func_800D36A8(s32 a0, u8 *a1) {
    s16 v = func_80019690(0, 0x7FFF);
    u8 *b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = v;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
s32 rand_(void) asm("rand");
u8 func_800D370C(s32 a0, u8 *a1) {
    u16 r;
    u8 *b;
    func_800D29A8(a1, 2, 0, 1);
    r = rand_();
    b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = r % (*(s16 *)(b + 0x6A6) + 1);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D3798(s32 a0, u8 *a1) {
    u8 *b;
    s32 x, y;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    x = *(s16 *)(b + 0x6A4);
    y = *(s16 *)(b + 0x6A6);
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = x * y;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D381C(s32 a0, u8 *a1) {
    u8 *b;
    func_800D29A8(a1, 2, a1[5], 0);
    b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = *(s16 *)(b + 0x6A4) / *(s16 *)(b + 0x6A6);
    return D_800D9624[a1[0]];
}

void func_800D38A0(void) {
}

void func_800D38A8(void) {
}

void func_800D38B0(void) {
}

void func_800D38B8(void) {
}

void func_800D38C0(void) {
}

void func_800D38C8(void) {
}

void func_800D38D0(void) {
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D38D8(s32 a0, u8 *a1) {
    u8 r = 0;
    u8 *e;
    a0 <<= 2;
    e = *(u8 **)(D_800DDB30 + a0);
    if (e[0x188] == 0) {
        u8 **pp;
        func_800D29A8(a1, 1, 0, 1);
        pp = (u8 **)(D_800DDB30 + a0);
        *(s16 *)(*pp + 0x186) = *(s16 *)(D_800DDB30 + 0x6A4) * 2;
        (*pp)[0x188] = 1;
    } else if (*(s16 *)(e + 0x186) == 0) {
        e[0x188] = 0;
        r = D_800D9624[a1[0]];
    }
    return r;
}

void func_800D399C(void) {
}

void func_800D39A4(void) {
}

void func_800D39AC(void) {
}

void func_800D39B4(void) {
}

extern s32 D_800DDFDC;
extern u8 D_800D9624[];
u8 func_800D39BC(s32 a0, u8 *a1) {
    D_800DDFDC = 0x20;
    return D_800D9624[*a1];
}

extern s32 D_800DDFDC;
extern s32 D_800A32E0;
extern u16 D_800DDF40;
u16 func_800BC594(u16, u8);
void func_800C8644(s32, s32);
void func_800D39E4(void) {
    S800DAF20 *d;
    D_800DDFDC = 0x20;
    d = &D_800DAF20;
    d->b118 = 2;
    d->b123 = 1;
    d->h116 = -2;
    if (d->b119 && !D_800A32E0) {
        func_800C8644(0, 1);
        d->b103 = 1;
        *(s16 *)((u8 *)d + 0x106) = 0;
        d->h116 = -2;
        d->b12F = d->b134;
        if (func_800BC594(D_800DDF40, d->bFA)) {
            ((u8 *)d)[0x11D] = 1;
            d->b11B = d->b101 + 1;
            ((u8 *)d)[0x11C] = d->bFA;
        }
    }
}

void func_800D39E4(void);
extern u8 D_800D95F8;
u8 func_800D3AA8(s32 a0, u8 *a1) {
    S800DAF20 *d = &D_800DAF20;
    if (d->b115 == 0 || d->b103 >= 5) {
        d->h116 = -2;
        return 0;
    }
    func_800D39E4();
    D_800D95F8 = 1;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D3B28);

void func_800BCC84(void);
void func_800D39E4(void);
u8 func_800D3C50(s32 a0, u8 *a1) {
    S800DAF20 *d = &D_800DAF20;
    if (d->b115 == 0 || d->b103 >= 5) {
        d->h116 = -2;
        return 0;
    }
    func_800BCC84();
    d->b143 = 1;
    d->b101 = 0xFF;
    func_800D39E4();
    return D_800D9624[a1[0]];
}

u8 func_800D3CE0(s32 a0, u8 *a1) {
    D_800DAF20.b143 = 0;
    D_800DAF20.b118 = 0;
    D_800DAF20.b11A = 0xFF;
    D_800DAF20.b123 = 0;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D3D18);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D40C4);

u8 func_800D4138(u8 a0) {
    u8 *b = D_800DDB30;
    if (*(s16 *)(b + 0x6A6) == 0xE9) {
        return (*(u8 **)(b + (a0 << 2)))[0x83];
    }
    return b[0x6A6] + 0x20;
}

void func_800D29A8(u8 *, s32, s32, s32);
u16 func_800D40C4(u8, s32);
u8 func_800D4188(s32 a0, u8 *a1) {
    u16 v;
    func_800D29A8(a1, 3, a1[7], 0);
    v = func_800D40C4(func_800D4138(a0), *(u16 *)(D_800DDB30 + 0x6A8));
    *(u16 *)(D_800DDB30 + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = v;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D421C);

void func_800D29A8(u8 *, s32, s32, s32);
void func_800D421C(u8, s32, s32);
u8 func_800D4288(s32 a0, u8 *a1) {
    u8 k;
    func_800D29A8(a1, 3, a1[7], 0);
    k = func_800D4138(a0);
    func_800D421C(k, *(u16 *)(D_800DDB30 + 0x6A8), *(u16 *)(D_800DDB30 + 0x6A4));
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4300);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D44D4);

extern u16 D_800DDBC4;
u16 func_800D4570(u8 a0) {
    u16 r = 0;
    s32 i, s, n;
    if (a0 == 0) {
        s = 0;
        n = 3;
    } else {
        s = 3;
        n = 9;
    }
    for (i = s; i < n; i++) {
        if (func_800BC594(D_800DDBC4, i) && (D_800DB078[i].w1B0 & 0x80)) {
            r = func_800BC54C(i);
            break;
        }
    }
    return r;
}

extern u8 D_800DA612[];
u8 func_800C82AC(u8);
u16 func_800D4658(s32 a0) {
    u16 r = 1;
    s32 i;
    for (i = 0; i < 3; i++) {
        if (func_800C82AC(i) && D_800DB078[i].h1CC == 0 && D_800DA612[i] == a0) {
            r = func_800BC54C(i);
        }
    }
    return r;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4710);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4804);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D48DC);

void func_800D29A8(u8 *, s32, s32, s32);
u16 func_800D48DC(u8, u8);
u8 func_800D4A38(s32 a0, u8 *a1) {
    u16 v;
    func_800D29A8(a1, 2, a1[5], 0);
    a0 <<= 2;
    v = func_800D48DC(D_800DDB30[0x6A6], (*(u8 **)(D_800DDB30 + a0))[0x83]);
    *(u16 *)(D_800DDB30 + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = v;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4AD8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4B8C);

void func_800D4C9C(void) {
}

s32 func_800D4CA4(void) {
    s32 r = 1;
    s32 i;
    for (i = 3; i < 9; i++) {
        if (func_800BC594(D_800DDF40, i)) {
            if (D_800DB078[i].h16C == 0) {
                r = 0;
                break;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4D34);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D4FB8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D5014);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D5194);

void func_800D29A8(u8 *, s32, s32, s32);
void func_8009635C(u8 *, s32, s32);
u8 func_800D5348(s32 a0, u8 *a1) {
    func_800D29A8(a1, 1, 0, 1);
    a0 <<= 2;
    func_8009635C(D_800DB078[(*(u8 **)(D_800DDB30 + a0))[0x83]].p190, *(s16 *)(D_800DDB30 + 0x6A4), 0);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D53E4(s32 a0, u8 *a1) {
    u8 *b;
    u8 *e;
    s32 k;
    func_800D29A8(a1, 1, 0, 2);
    b = D_800DDB30;
    k = *(s16 *)(b + 0x6A4) << 2;
    e = *(u8 **)(b + k);
    if (e[0x83] != 0xFF) {
        func_8009635C(D_800DB078[e[0x83]].p190, *(s16 *)(b + 0x6A6), 0);
    }
    return D_800D9624[a1[0]];
}

void func_800D548C(void) {
}

void func_800D5494(void) {
}

void func_800D549C(void) {
}

typedef struct { u8 b0; u8 pad[3]; } T54A4;
extern T54A4 D_800DA970_t5[] asm("D_800DA970");
typedef struct { u8 pad[0x81]; u8 b81; } T54A4b;
extern T54A4b D_800DA9B8_t5 asm("D_800DA9B8");
u16 func_800D54A4(u8 a0) {
    u8 n = 0;
    s32 i, j;
    u8 cnt[3];
    if (a0 < 0x40) {
        for (i = 0; i < 3; i++) {
            if (D_800DA970_t5[i].b0 == a0) n++;
        }
        return n;
    }
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (D_800DA970_t5[i].b0 == D_800DA970_t5[j].b0) cnt[i]++;
        }
    }
    for (i = 0; i < 3; i++) {
        if (cnt[i] >= n) {
            n = cnt[i];
            D_800DA9B8_t5.b81 = cnt[i];
        }
    }
    return n;
}

void func_800D29A8(u8 *, s32, s32, s32);
u16 func_800D54A4(u8);
u8 func_800D55A8(s32 a0, u8 *a1) {
    u16 v;
    func_800D29A8(a1, 2, 0, 1);
    v = func_800D54A4(func_800BC54C(D_800DDB30[0x6A6]));
    *(u16 *)(D_800DDB30 + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = v;
    return D_800D9624[a1[0]];
}

void func_800D5638(void) {
}

void func_800D5640(void) {
}

void func_800D5648(void) {
}

void func_800D5650(void) {
}

void func_800D5658(void) {
}

void func_800D5660(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D5668);

s32 func_800D5668(s32, s32, s32);
u16 func_800D57EC(s32 a0, s32 a1) {
    return func_800D5668(a0, a1, 0);
}

u16 func_800D580C(s32 a0, s32 a1) {
    return func_800D5668(a0, a1, 1);
}

void func_800D582C(void) {
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D5834(s32 a0, u8 *a1) {
    u8 *b;
    func_800D29A8(a1, 1, 0, 1);
    b = D_800DDB30;
    a0 <<= 2;
    *(u16 *)(D_800DB078[(*(u8 **)(b + a0))[0x83]].p190 + 0x146) = *(u16 *)(b + 0x6A4);
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D58D0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D5954);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D5B74);

void func_800D5C98(void) {
}

void func_8002A228(s32);
u8 func_800D5CA0(s32 a0, u8 *a1) {
    func_8002A228(a1[1] + (a1[2] << 8) + (a1[3] << 16) + (a1[4] << 24));
    return D_800D9624[a1[0]];
}

void func_80029F58(s32);
u8 func_800D5D00(s32 a0, u8 *a1) {
    func_80029F58(0);
    return D_800D9624[a1[0]];
}

void func_800329B8(s32);
u8 func_800D5D3C(s32 a0, u8 *a1) {
    func_800329B8(a1[1] + (a1[2] << 8) + (a1[3] << 16) + (a1[4] << 24));
    return D_800D9624[a1[0]];
}

void func_80032D78(s32);
u8 func_800D5D9C(s32 a0, u8 *a1) {
    func_80032D78(0);
    return D_800D9624[a1[0]];
}

u8 func_8002A040(s32);
u8 func_800D5DD8(s32 a0, u8 *a1) {
    if (func_8002A040(a1[1] + (a1[2] << 8) + (a1[3] << 16) + (a1[4] << 24))) {
        return 0;
    }
    return D_800D9624[a1[0]];
}

u8 func_80032A08(s32);
u8 func_800D5E44(s32 a0, u8 *a1) {
    if (func_80032A08(a1[1] + (a1[2] << 8) + (a1[3] << 16) + (a1[4] << 24))) {
        return 0;
    }
    return D_800D9624[a1[0]];
}

void func_800D5EB0(void) {
}

extern u8 D_800DB064;
u8 func_800D5EB8(s32 a0, u8 *a1) {
    D_800DB064 = a1[1];
    return D_800D9624[a1[0]];
}

extern u8 D_800DAC48;
u8 func_800D5EE0(s32 a0, u8 *a1) {
    D_800DAC48 = a1[1];
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D5F08);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D60C0);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D6478);

void func_800D29A8(u8 *, s32, s32, s32);
s32 func_800D60C0(s32, u8 *, u8, s32, s32);
s32 func_800D64B8(s32 a0, u8 *a1) {
    func_800D29A8(a1, 1, 0, 1);
    return func_800D60C0(a0, a1, func_800D4138(a0), 1, 3);
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D651C(s32 a0, u8 *a1) {
    u8 k;
    func_800D29A8(a1, 2, 0, 1);
    k = func_800D4138(a0);
    *(u16 *)(D_800DDB30 + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = D_800DB078[k].h1C8;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D65C4);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D6680);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D6738);

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D6854(s32 a0, u8 *a1) {
    u8 *b;
    u8 *e;
    s32 k;
    func_800D29A8(a1, 2, 0, 2);
    b = D_800DDB30;
    k = *(s16 *)(b + 0x6A4) << 2;
    e = *(u8 **)(b + k);
    if (e[0x83] != 0xFF) {
        func_8009B0D8(D_800DB078[e[0x83]].p190, *(s16 *)(b + 0x6A6), 0);
    }
    return D_800D9624[a1[0]];
}

extern u16 D_800DA616;
u8 func_800D68FC(s32 a0, u8 *a1) {
    u8 i;
    s16 f = 0;
    func_800D29A8(a1, 2, 0, 2);
    i = func_800D4138(a0);
    if (a1[1]) {
        D_800DA616 &= func_800BC56C(i);
        f = 1;
    } else {
        D_800DA616 |= func_800BC54C(i);
    }
    D_800DB078[i].h1CC = f;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D69D4(s32 a0, u8 *a1) {
    s32 z;
    func_800D29A8(a1, 2, 0, 2);
    z = a1[1] == 0;
    D_800DB078[func_800D4138(a0)].h1CA = z;
    return D_800D9624[a1[0]];
}

void func_800D6A68(void) {
}

void func_800D6A70(void) {
}

void func_800D6A78(void) {
}

extern u8 D_800DDB60_a[] asm("D_800DDB60");
u8 func_800D6A80(s32 a0, u8 *a1) {
    s32 v = 0xFF;
    s32 i = 6;
    u8 *p = D_800DDB60_a + i;
    do {
        *p-- = v;
    } while (--i >= 0);
    D_800DDB60_a[0] = (*(u8 **)(D_800DDB30 + (a0 << 2)))[0x83];
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D6AE4(s32 a0, u8 *a1) {
    s32 i;
    func_800D29A8(a1, 1, 0, 1);
    for (i = 0; i < 3; i++) {
        D_800DB078[i].b434 = D_800DB078[i].b435 = D_800DDB30[0x6A4];
    }
    return D_800D9624[a1[0]];
}

extern u8 D_8006EBBC;
u8 func_800D6B60(s32 a0, u8 *a1) {
    D_8006EBBC = 1;
    return D_800D9624[a1[0]];
}

u8 func_800D6B88(s32 a0, u8 *a1) {
    D_800DDB30[0x831] = a1[1];
    return D_800D9624[a1[0]];
}

extern u8 D_800DDD31;
u8 func_800D6BB8(s32 a0, u8 *a1) {
    D_800DDD31 = a1[1];
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
extern u8 D_8006EBC1;
u8 func_800D6BE0(s32 a0, u8 *a1) {
    func_800D29A8(a1, 1, 0, 1);
    D_8006EBC1 = ((s8 *)D_800DDB30)[0x6A4] - 0x80;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D6C40(s32 a0, u8 *a1) {
    u8 k;
    u8 *b;
    func_800D29A8(a1, 1, 0, 1);
    b = D_800DDB30;
    if (*(s16 *)(b + 0x6A4) == 0xE9) {
        k = (*(u8 **)(b + (a0 << 2)))[0x83];
    } else {
        k = b[0x6A4] + 0x20;
    }
    D_800DDD38[k].w14 |= 0x80000000;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D6D00(s32 a0, u8 *a1) {
    S800DB1E4 *s;
    s32 v;
    func_800D29A8(a1, 2, 0, 1);
    s = &D_800DB1E4[func_800D4138(a0)];
    s->b2F = s->b53 = D_800DDB30[0x6A4];
    v = *(s16 *)(D_800DDB30 + 0x6A4);
    *(s16 *)(s->p24 + 0xA6) = v * 64;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D6DAC);

u8 func_800D6E88(s32 a0, u8 *a1) {
    u8 *b;
    s16 r;
    s32 m = ((*(u16 *)(D_800DDB30 + 0xDA) << 16) + *(u16 *)(D_800DDB30 + 0xD8)) / 60;
    func_800D29A8(a1, 3, 0, 1);
    b = D_800DDB30;
    r = m >= *(s16 *)(b + 0x6A8) * 3600 + *(s16 *)(b + 0x6A6);
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = r;
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
extern u16 D_8006EBB4;
u8 func_800D6F68(s32 a0, u8 *a1) {
    func_800D29A8(a1, 1, 0, 1);
    D_8006EBB4 |= *(u16 *)(D_800DDB30 + 0x6A4);
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D6FCC);

void func_800D29A8(u8 *, s32, s32, s32);
u8 func_800D7090(s32 a0, u8 *a1) {
    u8 **pp;
    func_800D29A8(a1, 1, 0, 1);
    pp = (u8 **)D_800DDB30 + a0;
    (*pp)[0x1A7] = D_800DDB30[0x6A4];
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D7104);

void func_800D29A8(u8 *, s32, s32, s32);
void func_800D7104(s32, u8 *, s32);
u8 func_800D724C(s32 a0, u8 *a1) {
    func_800D29A8(a1, 2, 0, 1);
    func_800D7104(a0, a1, 1);
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
void func_800D7104(s32, u8 *, s32);
extern u8 D_800DB035;
u8 func_800D72B0(s32 a0, u8 *a1) {
    if (D_800DB035) {
        func_800D29A8(a1, 1, 0, 1);
        func_800D7104(a0, a1, 0);
    }
    return D_800D9624[a1[0]];
}

void func_800D29A8(u8 *, s32, s32, s32);
extern u8 D_800DAE55;
u8 func_800D7320(s32 a0, u8 *a1) {
    func_800D29A8(a1, 1, 0, 1);
    D_800DAE55 = D_800DDB30[0x6A4];
    return D_800D9624[a1[0]];
}

void func_800D39E4(void);
extern u8 D_800DDD30;
u8 func_800D737C(s32 a0, u8 *a1) {
    S800DAF20 *d;
    if (D_800DDD30 == 1) {
        return 0;
    }
    d = &D_800DAF20;
    if (d->b115 == 0 || d->b103 >= 5) {
        d->h116 = -2;
        return 0;
    }
    func_800D39E4();
    D_800DDD30 = 1;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D741C);

typedef struct { u8 pad0[0x84]; u8 b84[7]; } SA9B8x;
extern SA9B8x D_800DA9B8_x asm("D_800DA9B8");
extern u8 D_800D9614[];
extern u8 D_800DB050;
u8 func_800D7678(s32 a0, u8 *a1) {
    s16 r = 1;
    s32 i;
    u8 *b;
    func_800D29A8(a1, 2, 0, 1);
    for (i = 0; i < 7; i++) {
        if (D_800DA9B8_x.b84[i] != D_800D9614[i]) {
            r = 0;
            break;
        }
    }
    b = D_800DDB30;
    *(s16 *)(b + (((a1[2] << 8) | a1[1]) & 0xFFFE) + 0x84) = r;
    if (r) D_800DB050 = 0;
    return D_800D9624[a1[0]];
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D7748);

void func_800D78F0(void) {
}

void func_800D78F8(void) {
}

void func_800D7900(void) {
}

void func_800D7908(void) {
}

void func_800D7910(void) {
}

void func_800D7918(void) {
}

void func_800D7920(void) {
}

void func_800D7928(void) {
}

void func_800D7930(void) {
}

void func_800D7938(void) {
}

void func_800D7940(void) {
}

void func_800D7948(void) {
}

void func_800D7950(void) {
}

void func_800D7958(void) {
}

void func_800D7960(void) {
}

void func_800D7968(void) {
}

void func_800D7970(void) {
}

void func_800D7978(void) {
}

void func_800D7980(void) {
}

void func_800D7988(void) {
}

void func_800D7990(void) {
}

void func_800D7998(void) {
}

void func_800D79A0(void) {
}

void func_800D79A8(void) {
}

void func_800D79B0(void) {
}

void func_800D79B8(void) {
}

void func_800D79C0(void) {
}

void func_800D79C8(void) {
}

void func_800D79D0(void) {
}

void func_800D79D8(void) {
}

void func_800D79E0(void) {
}

void func_800D79E8(void) {
}

void func_800D79F0(void) {
}

void func_800D79F8(void) {
}

void func_800D7A00(void) {
}

void func_800D7A08(void) {
}

void func_800D7A10(void) {
}

void func_800D7A18(void) {
}

void func_800D7A20(void) {
}

void func_800D7A28(void) {
}

void func_800D7A30(void) {
}

void func_800D7A38(void) {
}

void func_800D7A40(void) {
}

void func_800D7A48(void) {
}

void func_800D7A50(void) {
}

void func_800D7A58(void) {
}

void func_800D7A60(void) {
}

void func_800D7A68(void) {
}

void func_800D7A70(void) {
}

void func_800D7A78(void) {
}

void func_800D7A80(void) {
}

void func_800D7A88(void) {
}

void func_800D7A90(void) {
}

void func_800D7A98(void) {
}

void func_800D7AA0(void) {
}

void func_800D7AA8(void) {
}

void func_800D7AB0(void) {
}

void func_800D7AB8(void) {
}

void func_800D7AC0(void) {
}

void func_800D7AC8(void) {
}

void func_800D7AD0(void) {
}

void func_800D7AD8(void) {
}

void func_800D7AE0(void) {
}

void func_800D7AE8(void) {
}

void func_800D7AF0(void) {
}

void func_800D7AF8(void) {
}

void func_800D7B00(void) {
}

void func_800D7B08(void) {
}

void func_800D7B10(void) {
}

void func_800D7B18(void) {
}

void func_800D7B20(void) {
}

void func_800D7B28(void) {
}

void func_800D7B30(void) {
}

void func_800D7B38(void) {
}

void func_800D7B40(void) {
}

void func_800D7B48(void) {
}

void func_800D7B50(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D7B58);

void func_800D7C38(void) {
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D7C40);

extern u8 *D_800DDB5C;
void func_800D7C38_l(u8) asm("func_800D7C38");
void func_800D7C40_l(u8) asm("func_800D7C40");
void func_800D7D7C(void) {
    u32 i;
    for (i = 0; i < *(u32 *)(D_800DDB5C + 0x80); i++) {
        u8 *e = *(u8 **)(D_800DDB30 + (i << 2));
        if (e[0x18B] == 1) {
            switch (e[0x1A4]) {
            case 0:
                func_800D7C38_l(i);
                break;
            case 1:
            case 2:
                func_800D7C40_l(i);
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D7E38);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D80B8);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D823C);

INCLUDE_ASM("asm/ov_battle/nonmatchings/battle_800B3E58", func_800D8484);
