#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8002FE30);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800301CC);

extern s32 D_8006B1EC;
extern s16 D_8007EC20[];
extern s16 D_8007EB08[];
void func_80030680(void) {
    D_8006B1EC = 0;
    D_8007EB08[0] = D_8007EC20[0];
    D_8007EB08[1] = D_8007EC20[1];
}

extern s16 D_8007EB0C[];
extern u16 D_8007EB10;
extern u16 D_8007EB12;
extern s16 D_80062E40[];

void func_800306AC(s32 x, s32 y) {
    D_8007EB0C[0] = x;
    D_8007EB0C[1] = y;
    D_8007EB12 = GetClut(x, y + 8);
    D_8007EB10 = GetTPage(0, 2, x, y);
    D_80062E40[0x98 / 2] = x;
    D_80062E40[0x9A / 2] = y;
    D_80062E40[0xC / 2] = x;
    D_80062E40[0xE / 2] = y + 8;
    func_80033530(D_80062E40);
}

extern s32 D_8007EC1C;
void func_800307CC(u8 arg0);
void func_8003073C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_8007EC1C = 0x80808080;
    D_8007EC20[0] = arg0;
    D_8007EC20[1] = arg1;
    D_8007EC20[2] = arg2;
    D_8007EC20[3] = arg3;
    func_800307CC(0);
}

typedef struct { u16 a, b; } P80030784;
extern P80030784 D_8007EB08_r asm("D_8007EB08");
P80030784 func_80030784(void) {
    return D_8007EB08_r;
}

typedef struct { u16 a, b; } P800307AC;
extern P800307AC D_8007EB08_t asm("D_8007EB08");
void func_800307AC(P800307AC arg0) {
    D_8007EB08_t.a = arg0.a;
    D_8007EB08_t.b = arg0.b;
}

extern u8 D_8006B1E9;
extern u8 D_8006B1EA;
void func_800307CC(u8 arg0) {
    D_8006B1E9 = arg0;
    if (arg0) {
        D_8006B1EA = 6;
    } else {
        D_8006B1EA = 8;
    }
}

extern s32 D_8007EC18;
void func_800307F8(s32 arg0) {
    D_8007EC18 = arg0;
}

extern u8 D_8006B1E9_t asm("D_8006B1E9");
u8 func_80030804(void) {
    return D_8006B1E9_t;
}

typedef struct {
    u32 id : 9;
    u32 len : 6;
    u32 ext : 1;
    u32 pad : 16;
    u32 unk4;
} Unk80030814;

void *func_80030814(u8 *p, s32 id) {
    Unk80030814 h;
    u16 *hp;
    if (p != NULL) {
        hp = (u16 *)&h;
        do {
            *hp = *(u16 *)p;
            if (h.id == id) {
                return p;
            }
            if (h.id == 0) {
                break;
            }
            if (h.ext) {
                p = *(u8 **)(p + ((((Unk80030814 *)p)->len + 3) & ~3));
            } else {
                p += h.len;
            }
        } while (p != NULL);
    }
    return NULL;
}

extern s32 D_8006B208;
extern s32 D_8006B204;
extern s32 D_8006B1FC;
extern s32 D_8006B1F8;
extern s32 D_8006B1F4;
extern s32 D_8006B20C;
extern s32 D_8006B200;
void func_800308A4(void) {
    D_8006B208 = 0;
    D_8006B204 = 0;
    D_8006B1FC = 0;
    D_8006B1F8 = 0;
    D_8006B1F4 = 0;
    D_8006B20C = 0;
    D_8006B200 = 0;
}

extern s32 D_8006B1F4;
void func_800308E0(s32 arg0) {
    D_8006B1F4 = arg0;
}

extern s32 D_8006B200_t asm("D_8006B200");
void func_800308EC(s32 arg0) {
    D_8006B200_t = arg0;
}

extern s32 D_8006B1F8;
void func_800308F8(s32 arg0) {
    D_8006B1F8 = arg0;
}

extern s32 D_8006B1FC;
void func_80030904(s32 arg0) {
    D_8006B1FC = arg0;
}

extern s32 D_8006B20C_t asm("D_8006B20C");
void func_80030910(s32 arg0) {
    D_8006B20C_t = arg0;
}

extern s32 D_8006B204_t asm("D_8006B204");
void func_8003091C(s32 arg0) {
    D_8006B204_t = arg0;
}

extern s32 D_8006B208_t asm("D_8006B208");
void func_80030928(s32 arg0) {
    D_8006B208_t = arg0;
}

s32 func_80030934(s32 arg0) {
    if (D_8006B1F4 != 0) {
        return ((s32 (*)(s32))D_8006B1F4)(arg0);
    }
    return 0;
}

extern s32 (*D_8006B200_f)(void) asm("D_8006B200");
s32 func_80030968(void) {
    if (D_8006B200_f != NULL) {
        return D_8006B200_f();
    }
    return 0;
}

extern s32 (*D_8006B1FC_f)(void) asm("D_8006B1FC");
s32 func_8003099C(void) {
    if (D_8006B1FC_f != NULL) {
        return D_8006B1FC_f();
    }
    return 0;
}

extern s32 (*D_8006B1F8_f)(void) asm("D_8006B1F8");
s32 func_800309D0(void) {
    s32 r;
    if (D_8006B1F8_f == NULL) {
        r = 0;
    } else {
        r = D_8006B1F8_f();
    }
    return r;
}

extern s32 (*D_8006B20C_f)(void) asm("D_8006B20C");
s32 func_80030A04(void) {
    s32 r;
    if (D_8006B20C_f == NULL) {
        r = 0;
    } else {
        r = D_8006B20C_f();
    }
    return r;
}

extern s32 (*D_8006B208_f)(void) asm("D_8006B208");
s32 func_80030A38(void) {
    s32 r;
    if (D_8006B208_f == NULL) {
        r = 0;
    } else {
        r = D_8006B208_f();
    }
    return r;
}

extern s32 (*D_8006B204_f)(void) asm("D_8006B204");
s32 func_80030A6C(void) {
    s32 r;
    if (D_8006B204_f == NULL) {
        r = 0;
    } else {
        r = D_8006B204_f();
    }
    return r;
}

extern s32 D_8006B23C;
extern s16 D_8006B230;
extern s32 D_8007ED90;
extern s32 D_8006B234;
extern u8 D_8006B214[];
extern u8 D_8007ED58[];
extern u8 D_8006B21C[];
extern u8 D_8007ED98[];

void func_80030AA0(void) {
    s32 t;
    s32 a, b;
    if (D_8006B23C != 0) {
        t = D_8006B23C;
        D_8006B234 = D_8006B230 + (D_8007ED90 - D_8006B230) * t / 256;
        a = func_80032EB4(D_8006B214, D_8007ED58, t);
        b = func_80032EB4(D_8006B21C, D_8007ED98, D_8006B23C);
        a *= D_8006B23C;
        b *= D_8006B23C;
        if (a < 256 && b < 256) {
            func_800318BC();
            D_8006B23C = 0;
        } else {
            func_800318BC();
            D_8006B23C = t;
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/unk_8002FE30", D_80062D98);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8002FE30", D_80062E40);

typedef struct { s16 m[3][3]; s32 t[3]; } M_B98;
typedef struct { s16 vx, vy, vz, pad; } SV_B98;
typedef struct { s16 x, y, z; } S3_B98;
typedef struct { s32 vx, vy, vz, pad; } V_B98;
typedef struct L_B98 { struct L_B98 *next; } L_B98;
typedef struct {
    u32 u0;
    u8 pad4[2];
    s16 u6;
    s16 u8;
    s16 uA;
    u8 uC, uD, uE, uF;
    L_B98 *u10;
    u8 u14[4];
} C_B98;
typedef struct {
    u8 pad0[4];
    C_B98 *u4;
    s32 u8;
    s32 uC;
    s32 u10;
    s16 u14;
    u8 pad16[2];
    s32 u18;
    M_B98 m;
} O_B98;
typedef struct { u8 pad[0x1F4]; s16 u1F4; } R_B98;
extern S3_B98 D_8006B214_s asm("D_8006B214");
extern u16 D_8006B22C;
extern u8 D_8006B238;
extern s8 D_8006B3EF;
extern u8 D_8006B3F4;
extern M_B98 D_8007ED70_m asm("D_8007ED70");
void func_800314D4_x(void *, void *, void *, void *, s32, s32, u8) asm("func_800314D4");
static inline s32 cnt_B98(L_B98 *l) {
    s32 n;
    if ((s32)l > 0) {
        return (s32)l;
    }
    n = 0;
    while (l != NULL) {
        l = l->next;
        n++;
    }
    return n;
}
void func_80030B98(O_B98 *o) {
    C_B98 *c;
    L_B98 *l;
    s32 n;
    s32 m;
    s32 ang;
    u16 a16;
    s32 at;
    R_B98 *r;
    SV_B98 sv;
    V_B98 sc;
    V_B98 sq;
    SV_B98 sv2;
    char buf[8];
    c = o->u4;
    if (o->u8 == 0) {
        l = c->u10;
        if ((s32)l < 0) {
            func_800314D4_x(c->u10, &o->u8, &o->uC, &o->u10, c->u8, cnt_B98(l), 1);
        } else {
            func_800314D4_x(c->u14, &o->u8, &o->uC, &o->u10, c->u8, cnt_B98(l), 0);
        }
    }
    if (c->u0 & 1) {
        r = (R_B98 *)func_800321B8(&o->m, c->uC, c->uD, c->uE, c->uF, 0);
        if (((c->u0 >> 5) & 1) && r != NULL) {
            sc.vx = r->u1F4;
            sc.vy = r->u1F4;
            sc.vz = r->u1F4;
            ScaleMatrix(&o->m, &sc);
        }
    }
    ang = func_8002B1CC(o->u14, c->u6);
    func_8002E948(o->u8, (u16)ang, &sv);
    ApplyMatrixSV(&o->m, &sv, &sv);
    sv.vx += o->m.t[0];
    sv.vy += o->m.t[1];
    sv.vz += o->m.t[2];
    func_80032EB4(&D_8006B214_s, &sv, c->uA);
    if ((c->u0 >> 6) & 1) {
        sc.vx = D_8006B214_s.x;
        sc.vy = 0;
        sc.vz = D_8006B214_s.z;
        Square0(&sc, &sq);
        if (SquareRoot0(sq.vx + sq.vz) > 0x1800) {
            at = func_80027684(D_8006B214_s.z, D_8006B214_s.x);
            D_8006B214_s.x = (func_80025114(at) * 0x1800) / 4096;
            D_8006B214_s.z = (func_80025044(at) * 0x1800) / 4096;
        }
    }
    func_8002E948(o->uC, (u16)ang, &sv);
    ApplyMatrixSV(&o->m, &sv, &sv);
    sv.vx += o->m.t[0];
    sv.vy += o->m.t[1];
    sv.vz += o->m.t[2];
    func_80032EB4(D_8006B21C, &sv, c->uA);
    func_8002E948(o->u10, (u16)ang, &sv);
    D_8006B234 = sv.vx;
    D_8006B22C = sv.vy;
    if (!((c->u0 >> 4) & 1) && c->uC != 0 && D_8006B214_s.y > 0) {
        D_8006B214_s.y = 0;
    }
    func_800318BC();
    if (!((c->u0 >> 4) & 1) && c->uC != 0) {
        sv2.vx = D_8006B214_s.x;
        sv2.vy = D_8006B214_s.y;
        sv2.vz = D_8006B214_s.z;
        sv2.vy = 0;
        ApplyMatrixSV(&D_8007ED70_m, &sv2, &sv2);
        sv2.vx += D_8007ED70_m.t[0];
        sv2.vy += D_8007ED70_m.t[1];
        sv2.vz += D_8007ED70_m.t[2];
        if (sv2.vy < 0x100) {
            D_8007ED70_m.t[1] += 0x100 - sv2.vy;
        }
    }
    if (D_8006B3EF != 0 && D_8006B3F4 != 0) {
        func_8003F884(buf, 8);
        *(s32 *)buf = o->u18;
        func_8002FE30("                       %s\n", buf);
    }
    if (D_8006B238 == 0) {
        if (o->u8 != 0) {
            func_8003D504(o->u8);
            o->u8 = 0;
        }
        if (o->uC != 0) {
            func_8003D504(o->uC);
            o->uC = 0;
        }
        if (o->u10 != 0) {
            func_8003D504(o->u10);
            o->u10 = 0;
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/unk_8002FE30", D_800632FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80031074);

typedef struct E314D4 {
    struct E314D4 *next;
    s16 u4, u6, u8, uA, uC, uE, u10, u12;
} E314D4;
typedef struct { s16 x, y, z, w; } V314D4;
typedef struct {
    s32 n;
    u8 pad4[0x10];
    V314D4 v[1];
} L314D4;
s32 func_8003D8F4(s32, s32, s32);
void func_8002F078();
void func_8002E768();
void func_8003D504(s32);
void func_80029D9C(void);
void func_8002EF9C();
void func_800314D4(E314D4 *list, L314D4 **outA, L314D4 **outB, L314D4 **outC, s32 mode, s32 count, u8 linked) {
    s32 cnt = count;
    V314D4 *buf;
    V314D4 *p;
    L314D4 *a;
    L314D4 *b;
    L314D4 *c;
    E314D4 *e;
    V314D4 *src;
    V314D4 *d1;
    V314D4 *d2;
    s32 n;
    s32 i;
    if (cnt < 5) {
        n = 5;
    } else {
        n = cnt;
    }
    buf = (V314D4 *)func_8003D8F4(n << 4, 0, 1);
    n <<= 7;
    n += 0x1C;
    a = (L314D4 *)func_8003D8F4(n, 1, 1);
    b = (L314D4 *)func_8003D8F4(n, 1, 1);
    c = (L314D4 *)func_8003D8F4(n, 1, 1);
    a->n = 0;
    b->n = 0;
    c->n = 0;
    if (linked) {
        for (p = buf, i = 0, e = list; i != cnt; i++, p++) {
            p->x = e->uC;
            p->y = e->uE;
            p->z = e->u10;
            e = e->next;
        }
    } else {
        for (p = buf, i = 0, e = list; i != cnt; i++, p++) {
            p->x = e->uC;
            p->y = e->uE;
            p->z = e->u10;
            e++;
        }
    }
    func_8002F078(cnt, buf, func_8002EF9C, b);
    b->n++;
    func_8002E768(b);
    if (linked) {
        for (p = buf, i = 0, e = list; i != cnt; i++, p++) {
            p->x = e->u4;
            p->y = e->u6;
            p->z = e->u8;
            e = e->next;
        }
    } else {
        for (p = buf, i = 0, e = list; i != cnt; i++, p++) {
            p->x = e->u4;
            p->y = e->u6;
            p->z = e->u8;
            e++;
        }
    }
    func_8002F078(cnt, buf, func_8002EF9C, a);
    a->n++;
    func_8002E768(a);
    if (linked) {
        for (p = buf, i = 0, e = list; i != cnt; i++, p++) {
            p->x = e->uA;
            p->y = e->u12;
            p->z = 0;
            e = e->next;
        }
    } else {
        for (p = buf, i = 0, e = list; i != cnt; i++, p++) {
            p->x = e->uA;
            p->y = e->u12;
            p->z = 0;
            e++;
        }
    }
    func_8002F078(cnt, buf, func_8002EF9C, c);
    c->n++;
    func_8002E768(c);
    n = a->n - 1;
    if (a->n == b->n && c->n != a->n) {
        func_80029D9C();
    }
    switch (mode) {
    case 1:
        d1 = a->v;
        src = b->v;
        d2 = c->v;
        break;
    case 2:
        d2 = a->v;
        d1 = b->v;
        src = c->v;
        break;
    default:
        src = a->v;
        d1 = b->v;
        d2 = c->v;
        break;
    }
    if (n > 0) {
        i = 0;
        do {
            d1->w = src->w;
            d2->w = src->w;
            src++;
            d1++;
            d2++;
        } while (++i != n);
    }
    func_8003D504((s32)buf);
    *outA = a;
    *outB = b;
    *outC = c;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800318BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80031AC0);

typedef struct { s16 vx, vy, vz, pad; } SV800321B8;
typedef struct { s32 vx, vy, vz, pad; } V800321B8;
typedef struct { s16 m[3][3]; s32 t[3]; } M800321B8;
extern M800321B8 *D_8007ED48;
extern s8 D_8007ED4C;
extern s8 D_8007ED4D;
extern s8 D_8007ED4E;
extern s8 D_8007ED4F;
extern s8 D_8007ED50;
extern s32 D_8007ED54;
extern s16 D_8006B476;
extern M800321B8 D_8006B3C0_m asm("D_8006B3C0");
int func_80031AC0();
int func_80027684();
int func_80025114();
int RotMatrix();
int ScaleMatrix();
extern u8 D_80043A20[];
s32 func_800321B8(M800321B8 *m, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    register u32 sp asm("$29");
    SV800321B8 a;
    SV800321B8 b;
    SV800321B8 rot;
    M800321B8 tmp;
    V800321B8 d;
    V800321B8 sq;
    V800321B8 sc;
    s32 len;
    s32 s;
    if (sp <= 0x1F80017F) {
        D_8007ED48 = m;
        D_8007ED4C = a1;
        D_8007ED4D = a2;
        D_8007ED4E = a3;
        D_8007ED4F = a4;
        D_8007ED50 = a5;
        if (D_8006B476 == 0) {
            __asm__ volatile("addu $8, %0, $0\n\tsw $29, 0($8)\n\taddiu $8, $8, -4\n\taddu $29, $8, $0" : : "r"(D_80043A20) : "$8", "memory");
        }
        D_8006B476++;
        D_8007ED54 = func_800321B8(D_8007ED48, D_8007ED4C, D_8007ED4D, D_8007ED4E, D_8007ED4F, D_8007ED50);
        D_8006B476--;
        if (D_8006B476 == 0) {
            __asm__ volatile("addiu $29, $29, 4\n\tlw $29, 0($29)" : : : "memory");
        }
        if (D_8006B476 < 0) {
            D_8006B476 = 0;
        }
        return D_8007ED54;
    }
    if (a1 == 0) {
        *m = D_8006B3C0_m;
        m->t[2] = 0;
        m->t[1] = 0;
        m->t[0] = 0;
        return;
    }
    func_80031AC0(m, a1, a2);
    if (a3 == 0) {
        return;
    }
    func_80031AC0(&tmp, a3, a4);
    a.vx = m->t[0];
    a.vy = m->t[1];
    a.vz = m->t[2];
    b.vx = tmp.t[0];
    b.vy = tmp.t[1];
    b.vz = tmp.t[2];
    d.vy = b.vy - a.vy;
    d.vx = b.vx - a.vx;
    d.vz = b.vz - a.vz;
    Square0(&d, &sq);
    len = SquareRoot0(sq.vx + sq.vz);
    rot.vx = 0;
    rot.vy = -func_80027684(d.vz, d.vx);
    rot.vz = func_80027684(d.vy, (len << 1) >> 1);
    RotMatrix(&rot, m);
    if (rot.vz & 0x3FF) {
        rot.vz++;
    }
    s = (len << 13) / func_80025114(rot.vz);
    sc.vy = 0x1000;
    a.vx += b.vx;
    a.vy += b.vy;
    a.vz += b.vz;
    a.vx /= 2;
    a.vy /= 2;
    a.vz /= 2;
    sc.vx = s;
    sc.vz = s;
    m->t[0] = a.vx;
    m->t[1] = a.vy;
    m->t[2] = a.vz;
    return ScaleMatrix(m, &sc);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800324F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003276C);

typedef struct {
    u8 pad0[8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk800328F0;
extern Unk800328F0 *D_8006B210;
extern s32 D_8006B23C;
extern u8 D_8006B22E;
extern s32 D_8007ED68;
extern u8 D_8006B238;

void func_800328F0(void) {
    Unk800328F0 *p;
    while ((p = D_8006B210) != NULL) {
        if (p->unk8 != 0) {
            func_8003D504(p->unk8);
            p->unk8 = 0;
        }
        if (p->unkC != 0) {
            func_8003D504(p->unkC);
            p->unkC = 0;
        }
        if (p->unk10 != 0) {
            func_8003D504(p->unk10);
            p->unk10 = 0;
        }
        func_80032B54(p);
        func_80033F20(p);
    }
    D_8006B23C = 0;
    D_8006B22E = 0;
    D_8007ED68 = 0;
    D_8006B238 = 0;
}

s32 func_80041F0C(s32, s32);
void *func_80041F6C(void *);
void func_80031074(void *, s32);
extern s32 D_8006B23C;
void func_800329B8(s32 arg0) {
    s32 v = func_80041F0C(0xC, arg0);
    if (v != 0) {
        func_80031074(func_80041F6C((void *)v), arg0);
        D_8006B23C = 0;
    }
}

typedef struct N32A08 { struct N32A08 *next; u8 pad[0x14]; s32 unk18; } N32A08;
extern N32A08 *D_8006B210_n asm("D_8006B210");
s32 func_80032A08(s32 arg0) {
    N32A08 *n = D_8006B210_n; if (n == NULL) return 0; do { if (arg0 == 0 || n->unk18 == arg0) return 1; n = n->next; } while (n != NULL); return 0;
}

typedef struct { s32 w[8]; } S32A54;
extern S32A54 D_8007ED70_s asm("D_8007ED70");
extern u8 D_8006B22E_b asm("D_8006B22E");
void func_80032A54(S32A54 *arg0) {
    D_8007ED70_s = *arg0;
    D_8006B22E_b = 1;
}

typedef struct N32AAC { struct N32AAC *next; s32 unk4; void *a; void *b; void *c; } N32AAC;
extern N32AAC *D_8006B210_z9 asm("D_8006B210");
void f_3D504_z9(void *) asm("func_8003D504");
void func_80032AAC(N32AAC *arg0) {
    N32AAC *n;
    for (n = arg0->next = D_8006B210_z9; n != NULL; n = n->next) {
        if (n->a != NULL) {
            f_3D504_z9(n->a);
            n->a = NULL;
        }
        if (n->b != NULL) {
            f_3D504_z9(n->b);
            n->b = NULL;
        }
        if (n->c != NULL) {
            f_3D504_z9(n->c);
            n->c = NULL;
        }
    }
    D_8006B210_z9 = arg0;
}

typedef struct Node80032B54 {
    struct Node80032B54 *next;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Node80032B54;
extern u8 D_800632FC[];

void func_80032B54(Node80032B54 *n) {
    Node80032B54 *p = (Node80032B54 *)D_8006B210;
    Node80032B54 *prev = NULL;
    Node80032B54 *next;
    Node80032B54 *q;
    while (p != NULL) {
        if (p == n) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                next = p->next;
                for (q = (Node80032B54 *)D_8006B210; q != NULL; q = q->next) {
                    if (q->unk8 != 0) {
                        func_8003D504(q->unk8);
                        q->unk8 = 0;
                    }
                    if (q->unkC != 0) {
                        func_8003D504(q->unkC);
                        q->unkC = 0;
                    }
                    if (q->unk10 != 0) {
                        func_8003D504(q->unk10);
                        q->unk10 = 0;
                    }
                }
                D_8006B210 = (void *)next;
            }
            break;
        }
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        func_80029DD8(D_800632FC);
    }
}

typedef struct Unk80032C5C {
    struct Unk80032C5C *next;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Unk80032C5C;
typedef struct {
    s32 unk0;
    s32 unk4;
} Arg80032C5C;

void func_80032C5C(void *arg) {
    Arg80032C5C *arg0 = arg;
    Unk80032C5C *p;
restart:
    p = (Unk80032C5C *)D_8006B210;
    while (p != NULL) {
        if (p->unk18 == arg0->unk4 || p->unk4 == (s32)func_80041F6C(arg0)) {
            if (p->unk8 != 0) {
                func_8003D504(p->unk8);
                p->unk8 = 0;
            }
            if (p->unkC != 0) {
                func_8003D504(p->unkC);
                p->unkC = 0;
            }
            if (p->unk10 != 0) {
                func_8003D504(p->unk10);
                p->unk10 = 0;
            }
            func_80032B54(p);
            func_80033F20(p);
            goto restart;
        }
        p = p->next;
    }
}

void f_31074_a(void *, s32) asm("func_80031074");
extern s32 D_8006B23C_w asm("D_8006B23C");
void func_80032D40(s32 *arg0) {
    f_31074_a(func_80041F6C(arg0), arg0[1]);
    D_8006B23C_w = 0;
}

s32 func_8004208C(s32, s32, s32);
void func_80032C5C(void *);
void func_80032D78(s32 arg0) {
    s32 p = 0;
    while ((p = func_8004208C(p, 0xC, arg0)) != 0) {
        func_80032C5C(p);
    }
}

typedef struct N32DD0 { struct N32DD0 *next; s32 unk4; void *a; void *b; void *c; } N32DD0;
extern N32DD0 *D_8006B210_m asm("D_8006B210");
void f_3D504_g(void *) asm("func_8003D504");
void func_80032DD0(void) {
    N32DD0 *n;
    for (n = D_8006B210_m; n != NULL; n = n->next) {
        if (n->a != NULL) {
            f_3D504_g(n->a);
            n->a = NULL;
        }
        if (n->b != NULL) {
            f_3D504_g(n->b);
            n->b = NULL;
        }
        if (n->c != NULL) {
            f_3D504_g(n->c);
            n->c = NULL;
        }
    }
}

extern u16 D_8007ED58_h[] asm("D_8007ED58");
extern u16 D_8007ED98_h[] asm("D_8007ED98");
extern s32 D_8007ED90_w asm("D_8007ED90");
extern s32 D_8006B23C_x asm("D_8006B23C");
void func_80032E60(u16 *arg0, u16 *arg1, s32 arg2, s32 arg3) {
    D_8007ED58_h[0] = arg0[0];
    D_8007ED58_h[1] = arg0[1];
    D_8007ED58_h[2] = arg0[2];
    D_8007ED90_w = arg2;
    D_8007ED98_h[0] = arg1[0];
    D_8007ED98_h[1] = arg1[1];
    D_8007ED98_h[2] = arg1[2];
    D_8006B23C_x = arg3;
}

typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR_80032EB4;
typedef struct {
    s32 vx, vy, vz, pad;
} VECTOR_80032EB4;

s32 func_80032EB4(SVECTOR_80032EB4 *a, SVECTOR_80032EB4 *b, s32 t) {
    VECTOR_80032EB4 d;
    VECTOR_80032EB4 sq;
    d.vx = (b->vx - a->vx) * t / 256;
    d.vy = (b->vy - a->vy) * t / 256;
    d.vz = (b->vz - a->vz) * t / 256;
    a->vx += d.vx;
    a->vy += d.vy;
    a->vz += d.vz;
    Square0(&d, &sq);
    return SquareRoot0(sq.vx + sq.vy + sq.vz);
}

typedef struct {
    s32 v[8];
} Unk80032FAC;
extern Unk80032FAC D_8007ED70;
extern Unk80032FAC *D_8007ED6C;
extern s32 D_8006B234;
extern s16 D_8006B230;
extern s16 D_8007EDE8;
extern s16 D_8007EDE2;

void func_80032FAC(Unk80032FAC *arg0) {
    u8 unused[0x60];
    if (D_8006B22E != 0) {
        *arg0 = D_8007ED70;
    }
    D_8006B22E = 0;
    D_8007ED6C = arg0;
    if (D_8006B234 != 0) {
        D_8006B230 = D_8006B234;
        func_8003C988(D_8007EDE8, D_8007EDE2, D_8006B230);
        func_800267A4(D_8006B230);
        D_8006B234 = 0;
    }
}

extern s32 D_8006B234;
void func_80033074(s32 arg0) {
    D_8006B234 = arg0;
}

typedef struct {
    u8 pad0[4];
    s16 unk4;
} Unk80033080_4;
typedef struct {
    u8 pad0[4];
    Unk80033080_4 *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
} Unk80033080;
extern s16 D_1F800010;

void func_80033080(Unk80033080 *o) {
    s32 spd;
    s32 pad[2];
    s16 d = o->unk4->unk4;
    if (d != 0) {
        spd = 0x40000 / d;
        spd >>= 6;
    } else {
        spd = 0;
    }
    o->unk14 += spd * D_1F800010;
    if (o->unk14 >= 0x1000) {
        if ((Unk80033080 *)D_8006B210 == o) {
            o->unk14 = 0xFFF;
            func_80030B98(o);
        }
        if (o->unk8 != 0) {
            func_8003D504(o->unk8);
            o->unk8 = 0;
        }
        if (o->unkC != 0) {
            func_8003D504(o->unkC);
            o->unkC = 0;
        }
        if (o->unk10 != 0) {
            func_8003D504(o->unk10);
            o->unk10 = 0;
        }
        func_80032B54(o);
        func_80033F20(o);
    }
    if ((Unk80033080 *)D_8006B210 == o && D_1F800010 != 0) {
        func_80030B98(o);
    }
}

void func_800331AC(N32DD0 *arg0) {
    N32DD0 *n;
    for (n = D_8006B210_m; n != NULL; n = n->next) {
        if (n->a != NULL) {
            f_3D504_g(n->a);
            n->a = NULL;
        }
        if (n->b != NULL) {
            f_3D504_g(n->b);
            n->b = NULL;
        }
        if (n->c != NULL) {
            f_3D504_g(n->c);
            n->c = NULL;
        }
    }
    D_8006B210_m = arg0;
}

void func_8003324C(N32DD0 *arg0) {
    N32DD0 *n;
    N32DD0 *last = NULL;
    N32DD0 *m = D_8006B210_m;
    while (m != NULL) {
        last = m;
        m = last->next;
    }
    if (last != NULL) {
        last->next = arg0;
    } else {
        for (n = D_8006B210_m; n != NULL; n = n->next) {
            if (n->a != NULL) {
                f_3D504_g(n->a);
                n->a = NULL;
            }
            if (n->b != NULL) {
                f_3D504_g(n->b);
                n->b = NULL;
            }
            if (n->c != NULL) {
                f_3D504_g(n->c);
                n->c = NULL;
            }
        }
        D_8006B210_m = arg0;
    }
    arg0->next = NULL;
}

void func_80033324(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003332C);

typedef struct {
    s16 x, y, w, h;
} RECT_8003;
void LoadImage(void *, void *);
void func_80033530(s32 *tim) {
    RECT_8003 unused;
    s32 *p = tim + 2;
    if (tim[1] & 8) {
        p = (s32 *)((u8 *)p + tim[2]);
        LoadImage(tim + 3, tim + 5);
    }
    tim = p;
    LoadImage(tim + 1, tim + 3);
}

void func_80033588(s32 *tim, s32 cx, s32 cy, s32 px, s32 py) {
    RECT_8003 r;
    s32 *p = tim + 2;
    if (tim[1] & 8) {
        p = (s32 *)((u8 *)p + tim[2]);
        r = *(RECT_8003 *)(tim + 3);
        if (cx | cy) {
            r.x = cx;
            r.y = cy;
        }
        LoadImage(&r, tim + 5);
    }
    cx = (s32)p;
    r = *(RECT_8003 *)((s32 *)cx + 1);
    if (px | py) {
        r.x = px;
        r.y = py;
    }
    LoadImage(&r, (s32 *)cx + 3);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033654);

typedef struct { s32 a; u8 b; u8 pad[3]; s32 c; s32 d; } S80033940;
void f_33654_t(S80033940 *) asm("func_80033654");
void func_80033940(s32 arg0) {
    S80033940 s;
    S80033940 *p = &s;
    p->a = arg0;
    p->c = 0;
    p->b = 0x80;
    p->d = 0;
    f_33654_t(p);
}

typedef struct {
    s32 *unk0;
    u8 unk4;
    s32 unk8;
    s32 unkC;
} Unk80033974;
s32 func_800339DC(s32 *);
s32 func_8003D8F4(s32, s32, s32);
void func_80033654(Unk80033974 *, s32);
s32 func_80033974(s32 *arg0, s32 arg1) {
    Unk80033974 s;
    Unk80033974 *p;
    s32 ret;
    ret = func_8003D8F4(func_800339DC(arg0), arg1, 1);
    p = &s;
    s.unk0 = arg0;
    p->unk8 = 0;
    p->unk4 = 0x80;
    p->unkC = 0;
    func_80033654(p, ret);
    return ret;
}

s32 func_800339DC(s32 *arg0) {
    return arg0[1];
}

s32 func_800339E8(void) {
    return 0;
}

typedef struct { u8 *p; u8 mask; u8 pad[3]; s32 cur; s32 count; } Bits339F0;
extern char D_80063428_s[] asm("D_80063428");
void f_29DD8_b(char *) asm("func_80029DD8");
s32 func_800339F0(Bits339F0 *arg0) {
    s32 r;
    if (arg0->mask == 0x80) {
        if ((arg0->cur = *arg0->p++) == -1) {
            f_29DD8_b(D_80063428_s);
        }
        arg0->count++;
    }
    r = arg0->cur & arg0->mask;
    arg0->mask >>= 1;
    if (arg0->mask == 0) {
        arg0->mask = 0x80;
    }
    return r != 0;
}

u32 func_80033A80(Bits339F0 *arg0, s32 arg1) {
    u32 bit = 1 << (arg1 - 1);
    u32 r = 0;
    while (bit != 0) {
        if (arg0->mask == 0x80) {
            if ((arg0->cur = *arg0->p++) == -1) {
                f_29DD8_b(D_80063428_s);
            }
            arg0->count++;
        }
        if (arg0->cur & arg0->mask) {
            r |= bit;
        }
        bit >>= 1;
        arg0->mask >>= 1;
        if (arg0->mask == 0) {
            arg0->mask = 0x80;
        }
    }
    return r;
}

void func_80033B58(s32 arg0, s32 *arg1) {
    arg1[0] = arg0;
    arg1[2] = 0;
    ((u8 *)arg1)[4] = 0x80;
    arg1[3] = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033B70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033D80);

typedef struct Blk80033F20 {
    u32 next : 16;
    u32 prev : 15;
    u32 used : 1;
} Blk80033F20;
extern Blk80033F20 *D_8006B240_b asm("D_8006B240");
extern s32 D_8006B24C;
extern Blk80033F20 *D_1F800008_b asm("D_1F800008");
void func_80033F20(Blk80033F20 *q) {
    Blk80033F20 *b = q - 3;
    Blk80033F20 *p;
    D_8006B240_b = b;
    b->used = 0;
    D_8006B24C--;
    if (b->prev != 0) {
        u32 base = (u32)D_1F800008_b;
        p = (Blk80033F20 *)(b->prev * 4 + base);
        if (!p->used) {
            p->next = b->next;
            q = (Blk80033F20 *)(b->next * 4 + base);
            q->prev = ((u32)p - base) >> 2;
            b = p;
        }
    }
    {
        u32 base = (u32)D_1F800008_b;
        q = (Blk80033F20 *)(b->next * 4 + base);
        if (!q->used) {
            b->next = q->next;
            q = (Blk80033F20 *)(q->next * 4 + base);
            q->prev = ((u32)b - base) >> 2;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80034024);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8002FE30", D_80063428);

INCLUDE_RODATA("asm/nonmatchings/game/unk_8002FE30", D_80063444);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800342B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800369FC);

typedef union { s32 w; struct { u16 lo; s16 hi; } h; } FX36F4C;
typedef struct { s16 vx, vy, vz, pad; } SV36F4C;
typedef struct {
    u8 pad0[0x20];
    s32 u20;
    u8 pad24[4];
    u8 u28, u29, u2A, u2B;
    s32 u2C;
} P36F4C;
typedef struct {
    s32 u0, u4, u8, uC, u10, u14, u18;
    u8 pad1C[0x56 - 0x1C];
    s16 u56, u58, u5A;
    u8 pad5C[6];
    s16 u62, u64, u66;
    u8 pad68[0x7C - 0x68];
    s16 u7C;
    u8 pad7E[0x94 - 0x7E];
    u32 u94;
    u8 pad98[0xA8 - 0x98];
    s32 uA8, uAC, uB0, uB4;
    u16 uB8, uBA, uBC;
    s16 uBE, uC0, uC2;
    u16 uC4, uC6, uC8;
    s16 uCA, uCC, uCE;
    P36F4C *uD0;
    u8 padD4[4];
    M800321B8 uD8;
    u8 padF8[0];
    s16 uF8, uFA;
} O36F4C;
extern s16 D_1F800010;
extern u8 D_1F800000;
s32 func_8002B1CC(s32, s32);
void func_8002E948();
int ApplyMatrixSV();
void func_80036F4C(O36F4C *o) {
    O36F4C *e = o;
    s32 v[4];
    SV36F4C sv;
    M800321B8 m;
    s32 pad[2];
    M800321B8 *mp;
    P36F4C *p;
    s32 i;
    s32 n;
    s32 sh;
    if ((o->u94 >> 19) & 1) {
        v[0] = o->u56 << 16;
        v[1] = o->u58 << 16;
        v[2] = o->u5A << 16;
        v[0] |= o->uB8;
        v[1] |= o->uBA;
        v[2] |= o->uBC;
        for (i = 0; i != D_1F800010; i++) {
            v[0] += e->uBE << 5;
            v[1] += e->uC0 << 5;
            v[2] += e->uC2 << 5;
        }
        o->u56 = v[0] >> 16;
        o->u58 = v[1] >> 16;
        o->u5A = v[2] >> 16;
        e->uB8 = v[0];
        e->uBA = v[1];
        e->uBC = v[2];
    }
    if ((e->u94 >> 20) & 1) {
        v[0] = (o->u62 << 16) | e->uC4;
        v[1] = (o->u64 << 16) | e->uC6;
        v[2] = (o->u66 << 16) | e->uC8;
        for (i = 0; i != D_1F800010; i++) {
            v[0] += e->uCA << 5;
            v[1] += e->uCC << 5;
            v[2] += e->uCE << 5;
        }
        o->u62 = v[0] >> 16;
        o->u64 = v[1] >> 16;
        o->u66 = v[2] >> 16;
        e->uC4 = v[0];
        e->uC6 = v[1];
        e->uC8 = v[2];
    }
    if (e->u94 & 1) {
        e->uA8 += e->uB0 * D_1F800010;
        e->uAC += e->uB4 * D_1F800010;
    }
    p = e->uD0;
    if (p != NULL && o->uFA != o->u7C) {
        func_8002E948(p->u2C, (u16)func_8002B1CC(((o->uFA - o->u7C) << 12) / o->uFA, o->uF8), &sv);
        if (p->u20 & 1) {
            func_800321B8(&m, p->u28, p->u29, p->u2A, p->u2B, 0);
            mp = &m;
        } else {
            mp = &o->uD8;
        }
        ApplyMatrixSV(mp, &sv, &sv);
        sv.vx += mp->t[0];
        sv.vy += mp->t[1];
        sv.vz += mp->t[2];
        v[0] = sv.vx << 16;
        v[1] = sv.vy << 16;
        v[2] = sv.vz << 16;
        if (D_1F800010 != 0) {
            sh = D_1F800000;
            o->u10 = ((v[0] - o->u0) >> sh) / D_1F800010;
            o->u14 = ((v[1] - o->u4) >> sh) / D_1F800010;
            o->u18 = ((v[2] - o->u8) >> sh) / D_1F800010;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037320);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037B40);

typedef struct {
    s16 vx, vy, vz, pad;
} SV_80037CA8;
typedef struct {
    u8 pad0[8];
    u16 unk8;
} Unk80037CA8_90;
typedef struct {
    u8 pad0[0x50];
    SV_80037CA8 unk50;
    u8 pad58[4];
    SV_80037CA8 unk5C;
    u8 pad64[4];
    SV_80037CA8 unk68;
    u8 pad70[0x18];
    u32 unk88;
    u8 pad8C[4];
    Unk80037CA8_90 *unk90;
} Unk80037CA8;
extern s16 D_1F800010;
extern u8 D_8006B3F4;
extern void *D_803DEFCC;
void func_8033398C(void *, void *);
void func_8003A4C0(void *, void *);

void func_80037CA8(Unk80037CA8 *o) {
    SV_80037CA8 a;
    SV_80037CA8 c;
    SV_80037CA8 b;
    s32 pad[4];
    Unk80037CA8_90 *p = o->unk90;
    u32 f;
    p->unk8 += D_1F800010;
    f = o->unk88;
    if ((f >> 8) & 1) {
        a.vx = o->unk5C.vx;
        a.vy = o->unk5C.vy;
        a.vz = o->unk5C.vz;
    }
    if ((f >> 10) & 1) {
        b.vx = o->unk50.vx;
        b.vy = o->unk50.vy;
        b.vz = o->unk50.vz;
    }
    if ((f >> 11) & 1) {
        c.vx = o->unk68.vx;
        c.vy = o->unk68.vy;
        c.vz = o->unk68.vz;
    }
    if (D_8006B3F4 != 0 && p == D_803DEFCC) {
        func_8033398C(p, o);
    } else {
        func_8003A4C0(p, o);
    }
    if ((f >> 8) & 1) {
        o->unk5C.vx = a.vx;
        o->unk5C.vy = a.vy;
        o->unk5C.vz = a.vz;
    }
    if ((f >> 10) & 1) {
        o->unk50.vx = b.vx;
        o->unk50.vy = b.vy;
        o->unk50.vz = b.vz;
    }
    if ((f >> 11) & 1) {
        o->unk68.vx = c.vx;
        o->unk68.vy = c.vy;
        o->unk68.vz = c.vz;
    }
}

typedef struct { s16 m[3][3]; s32 t[3]; } M_E68;
typedef struct { s32 vx, vy, vz, pad; } V_E68;
typedef struct { s16 vx, vy, vz, pad; } SV_E68;
typedef struct { u8 pad[0x14]; u8 *u14; } C_E68;
typedef struct {
    u8 pad0[2];
    s16 u2;
    u8 pad4[2];
    s16 u6;
    u8 pad8[2];
    s16 uA;
    C_E68 *uC;
    u8 pad10[0xC];
    u32 *u1C;
    u8 pad20[0x10];
    M_E68 m;
    u8 pad50[0x2A];
    s16 u7A;
    u8 pad7C[0xC];
    u32 u88;
} O_E68;
extern M_E68 *D_8007ED6C_e asm("D_8007ED6C");
extern s32 D_8006B2C4;
void ApplyMatrixLV(void *, void *, void *);
void MulMatrix0(void *, void *, void *);
void SetMulMatrix(void *, void *);
s32 RotTransPers(void *, void *, void *, void *);
void func_80097854(void *, s32, void *, void *);
#define gte_SetRotMatrix_e(r0) __asm__ volatile ("addu $12, %0, $0; lw $13, 0($12); lw $14, 4($12); ctc2 $13, $0; ctc2 $14, $1; lw $13, 8($12); lw $14, 12($12); lw $15, 16($12); ctc2 $13, $2; ctc2 $14, $3; ctc2 $15, $4" : : "r"(r0) : "$12", "$13", "$14", "$15")
#define gte_SetTransMatrix_e(r0) __asm__ volatile ("addu $12, %0, $0; lw $13, 20($12); lw $14, 24($12); ctc2 $13, $5; lw $15, 28($12); ctc2 $14, $6; ctc2 $15, $7" : : "r"(r0) : "$12", "$13", "$14", "$15")
#define gte_ldv0_e(r0) __asm__ volatile ("addu $12, %0, $0; lwc2 $0, 0($12); lwc2 $1, 4($12)" : : "r"(r0) : "$12")
#define gte_rtv0_e() __asm__ volatile ("nop; nop; mvmva 1, 0, 0, 3, 0")
#define gte_stlvnl_e(r0) __asm__ volatile ("addu $12, %0, $0; swc2 $25, 0($12); swc2 $26, 4($12); swc2 $27, 8($12)" : : "r"(r0) : "$12", "memory")
#define gte_ldv3_e(r0, r1, r2) __asm__ volatile ("addu $12, %0, $0" : : "r"(r0) : "$12"); __asm__ volatile ("addu $13, %0, $0" : : "r"(r1) : "$13"); __asm__ volatile ("addu $14, %0, $0" : : "r"(r2) : "$14"); __asm__ volatile ("lwc2 $0, 0($12); lwc2 $1, 4($12); lwc2 $2, 0($13); lwc2 $3, 4($13); lwc2 $4, 0($14); lwc2 $5, 4($14)")
#define gte_rtpt_e() __asm__ volatile ("nop; nop; rtpt")
#define gte_stsxy3_e(r0, r1, r2) __asm__ volatile ("addu $12, %0, $0" : : "r"(r0) : "$12"); __asm__ volatile ("addu $13, %0, $0" : : "r"(r1) : "$13"); __asm__ volatile ("addu $14, %0, $0" : : "r"(r2) : "$14"); __asm__ volatile ("swc2 $12, 0($12); swc2 $13, 0($13); swc2 $14, 0($14)" : : : "memory")
#define gte_stflg_e(r0) __asm__ volatile ("addu $12, %0, $0; cfc2 $13, $31; nop; sw $13, 0($12)" : : "r"(r0) : "$12", "$13", "memory")
#define gte_stszotz_e(r0) __asm__ volatile ("addu $12, %0, $0; mfc2 $13, $19; nop; sra $13, $13, 2; sw $13, 0($12)" : : "r"(r0) : "$12", "$13", "memory")
s32 func_80037E68(O_E68 *arg0) {
    O_E68 *o = arg0;
    V_E68 v;
    SV_E68 sv;
    M_E68 tm;
    union { M_E68 m; s32 s[8]; } u;
    M_E68 m2;
    s32 a;
    M_E68 *b;
    u32 flag;
    s32 otz;
    s32 ip;
    C_E68 *c;
    M_E68 *mp;
    u8 *s0;
    u8 *s3;
    u8 *p;
    u16 *q;
    s32 i;
    s32 r;
    s32 n;
    s32 x;

    if (!((o->u88 >> 25) & 1)) {
        x = o->u2;
        sv.vx = x;
        x = o->u6;
        sv.vy = x;
        x = o->uA;
        sv.vz = x;
        gte_SetRotMatrix_e(D_8007ED6C_e);
        gte_ldv0_e(&sv);
        gte_rtv0_e();
        gte_stlvnl_e(&v);
    } else {
        v.vx = o->u2;
        v.vy = o->u6;
        v.vz = o->uA;
    }
    if ((o->u88 >> 15) & 1) {
        c = o->uC;
        s0 = func_80030814(c->u14, 0x30);
        if (s0 != NULL) {
            mp = (M_E68 *)(*(u16 *)(s0 + 4) | (*(u16 *)(s0 + 6) << 16));
            v.vx = o->u2;
            v.vy = o->u6;
            v.vz = o->uA;
            ApplyMatrixLV(mp, &v, &v);
            v.vx += mp->t[0];
            v.vy += mp->t[1];
            v.vz += mp->t[2];
            ApplyMatrixLV(D_8007ED6C_e, &v, &v);
        } else {
            s0 = func_80030814(c->u14, 0x39);
            if (s0 != NULL) {
                s3 = (u8 *)func_800321B8((M800321B8 *)&u.m, s0[2], s0[3], s0[4], s0[5], 0);
                mp = &u.m;
                v.vx = o->u2;
                v.vy = o->u6;
                v.vz = o->uA;
                ApplyMatrixLV(mp, &v, &v);
                v.vx += mp->t[0];
                v.vy += mp->t[1];
                v.vz += mp->t[2];
                ApplyMatrixLV(D_8007ED6C_e, &v, &v);
                if (*(u8 *)&o->u88 >> 7) {
                    if (s3 != NULL) {
                        if (s0[3] >= 2) {
                            func_80097854(s3, s0[3] - 2, &a, &b);
                            MulMatrix0(b, &o->m, &o->m);
                        } else {
                            RotMatrix(s3 + 0xA4, &m2);
                            MulMatrix0(&m2, &o->m, &o->m);
                        }
                    }
                }
            }
        }
    }
    if ((o->u88 >> 26) & 1) {
        if (!((o->u88 >> 24) & 1)) {
            SetMulMatrix(D_8007ED6C_e, &o->m);
            tm.t[0] = D_8007ED6C_e->t[0] + v.vx;
            tm.t[1] = D_8007ED6C_e->t[1] + v.vy;
            tm.t[2] = D_8007ED6C_e->t[2] + v.vz;
            gte_SetTransMatrix_e(&tm);
        } else {
            SetMulMatrix(D_8007ED6C_e, &o->m);
            tm.t[0] = v.vx;
            tm.t[1] = v.vy;
            tm.t[2] = v.vz + (D_8006B230 << D_1F800000);
            gte_SetTransMatrix_e(&tm);
        }
    } else {
        if (!((o->u88 >> 24) & 1)) {
            tm.t[0] = D_8007ED6C_e->t[0] + v.vx;
            tm.t[1] = D_8007ED6C_e->t[1] + v.vy;
            tm.t[2] = D_8007ED6C_e->t[2] + v.vz;
            gte_SetTransMatrix_e(&tm);
            gte_SetRotMatrix_e(&o->m);
        } else {
            tm.t[0] = v.vx;
            tm.t[1] = v.vy;
            tm.t[2] = v.vz + (D_8006B230 << D_1F800000);
            gte_SetTransMatrix_e(&tm);
            gte_SetRotMatrix_e(&o->m);
        }
    }
    r = 0;
    if ((o->u88 >> 28) & 1) {
        if ((o->u1C[2] & 0x3F) == 0xE) {
            p = func_80041F6C(o->u1C);
            r = 1;
            gte_ldv3_e(p + 0x28, p + 0x30, p + 0x38);
            gte_rtpt_e();
            gte_stsxy3_e(&u.s[2], &u.s[3], &u.s[4]);
            gte_ldv3_e(p + 0x40, p + 0x48, p + 0x50);
            gte_rtpt_e();
            gte_stsxy3_e(&u.s[5], &u.s[6], &u.s[7]);
            gte_stflg_e(&flag);
            gte_stszotz_e(&otz);
            if (!(flag & 0x40000000)) {
                i = 0;
                n = 6;
                q = (u16 *)&u.s[2];
                do {
                    if ((u32)(q[0] - 1) < 0x15F) goto zero;
                    if ((u16)(q[1] + 0x1F) < 0xFF) goto zero;
                    i++;
                    q += 2;
                } while (i != n);
                goto done;
            zero:
                r = 0;
            done:;
            }
        } else {
            otz = RotTransPers(&D_8006B2C4, &u.s[0], &ip, &flag);
            r = flag >> 31;
        }
        if ((o->u88 >> 12) & 1) {
            if ((D_8006B230 * 2) < otz) {
                o->u7A = 1;
            } else {
                o->u7A = 2;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038554);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038AD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038D28);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80038ED4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80039038);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003944C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800395D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800399FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80039C70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003A118);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003A1F8);

typedef struct { s16 amp, freq, phase, pad; } W_A4C0;
typedef struct { u16 hdr; W_A4C0 w[3]; } R_A4C0;
typedef struct { u32 op : 9; u32 len : 6; u32 jmp : 1; u32 pad : 16; } H_A4C0;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } M_A4C0;
typedef struct { s32 vx, vy, vz, pad; } V_A4C0;
typedef struct {
    V_A4C0 pos;
    u8 pad10[0x20];
    M_A4C0 m;
    s16 scale[3];
    s16 a56[3];
    s16 rot[3];
    s16 a62[3];
    s16 a68[3];
    s16 a6E[3];
    u8 pad74[0x14];
    s32 flags;
} O_A4C0;
typedef struct { u8 pad0[8]; u16 t; u8 pad[0xA]; u8 *rec; } C_A4C0;
extern M_A4C0 D_8006B3C0_a asm("D_8006B3C0");
s32 rsin_a(s32) asm("func_80025044");
void RotMatrix_a(s16 *, M_A4C0 *) asm("RotMatrix_gte");
void RotMatrixZYX_a(s16 *, M_A4C0 *) asm("RotMatrixZYX_gte");
void ScaleMatrix_a(M_A4C0 *, V_A4C0 *) asm("ScaleMatrix");

static inline s32 wave_A4C0(C_A4C0 *c, W_A4C0 *w) {
    s32 v;
    if (w->freq != 0) {
        v = rsin_a((c->t & 0xFFF) * w->freq + w->phase) * w->amp * 16;
    } else {
        v = 0;
    }
    return v;
}

void f_A4C0(C_A4C0 *c, O_A4C0 *o) asm("func_8003A4C0");
void f_A4C0(C_A4C0 *c, O_A4C0 *o) {
    R_A4C0 *r;
    V_A4C0 x;
    V_A4C0 d;
    V_A4C0 s;
    u16 hb[2];

    for (r = (R_A4C0 *)c->rec; r != NULL;) {
        *(u16 *)hb = r->hdr;
        if (((H_A4C0 *)hb)->op == 0) {
            break;
        }
        switch (((H_A4C0 *)hb)->op) {
        case 8:
            o->pos.vx = r->w[0].amp << 16;
            o->pos.vy = r->w[0].freq << 16;
            o->pos.vz = r->w[0].phase << 16;
            break;
        case 0x12:
            o->scale[0] = r->w[0].amp;
            o->scale[1] = r->w[0].freq;
            o->scale[2] = r->w[0].phase;
            break;
        case 0x19:
            o->rot[0] = r->w[0].amp;
            o->rot[1] = r->w[0].freq;
            o->rot[2] = r->w[0].phase;
            break;
        case 0x20:
            o->a68[0] = r->w[0].amp;
            o->a68[1] = r->w[0].freq;
            o->a68[2] = r->w[0].phase;
            break;
        case 9:
            d.vx = wave_A4C0(c, &r->w[0]);
            d.vy = wave_A4C0(c, &r->w[1]);
            d.vz = wave_A4C0(c, &r->w[2]);
            o->pos.vx += d.vx;
            o->pos.vy += d.vy;
            o->pos.vz += d.vz;
            break;
        case 0x14:
            o->scale[0] += wave_A4C0(c, &r->w[0]) >> 16;
            o->scale[1] += wave_A4C0(c, &r->w[1]) >> 16;
            o->scale[2] += wave_A4C0(c, &r->w[2]) >> 16;
            break;
        case 0x16:
            o->a56[0] += wave_A4C0(c, &r->w[0]) >> 16;
            o->a56[1] += wave_A4C0(c, &r->w[1]) >> 16;
            o->a56[2] += wave_A4C0(c, &r->w[2]) >> 16;
            break;
        case 0x1B:
            o->a62[0] = r->w[0].amp;
            o->a62[1] = r->w[0].freq;
            o->a62[2] = r->w[0].phase;
            break;
        case 0x1C:
            o->rot[0] += wave_A4C0(c, &r->w[0]) >> 16;
            o->rot[1] += wave_A4C0(c, &r->w[1]) >> 16;
            o->rot[2] += wave_A4C0(c, &r->w[2]) >> 16;
            break;
        case 0x1F:
            o->a62[0] += wave_A4C0(c, &r->w[0]) >> 16;
            o->a62[1] += wave_A4C0(c, &r->w[1]) >> 16;
            o->a62[2] += wave_A4C0(c, &r->w[2]) >> 16;
            break;
        case 0x21:
            o->a68[0] += wave_A4C0(c, &r->w[0]) >> 16;
            o->a68[1] += wave_A4C0(c, &r->w[1]) >> 16;
            o->a68[2] += wave_A4C0(c, &r->w[2]) >> 16;
            break;
        case 0x23:
            o->a6E[0] += wave_A4C0(c, &r->w[0]) >> 16;
            o->a6E[1] += wave_A4C0(c, &r->w[1]) >> 16;
            o->a6E[2] += wave_A4C0(c, &r->w[2]) >> 16;
            break;
        case 0x22:
            o->a6E[0] = r->w[0].amp;
            o->a6E[1] = r->w[0].freq;
            o->a6E[2] = r->w[0].phase;
            break;
        }
        if (((H_A4C0 *)hb)->jmp) {
            r = *(R_A4C0 **)((u8 *)r + ((((H_A4C0 *)r)->len + 3) & 0x7C));
        } else {
            r = (R_A4C0 *)((u8 *)r + ((H_A4C0 *)hb)->len);
        }
    }
    if (*(s32 *)&o->rot[0] != 0 || o->rot[2] != 0) {
        if (*(u16 *)((u8 *)o + 0x8A) & 1) {
            RotMatrixZYX_a(o->rot, &o->m);
        } else {
            RotMatrix_a(o->rot, &o->m);
        }
    } else {
        o->m = D_8006B3C0_a;
    }
    if (*(s32 *)&o->scale[0] != 0 || o->scale[2] != 0) {
        s.vx = o->scale[0];
        s.vy = o->scale[1];
        s.vz = o->scale[2];
        ScaleMatrix_a(&o->m, &s);
    }
    if (o->a62[0] != 0 || *(s32 *)&o->a62[1] != 0) {
        o->flags |= 0x200000;
    }
    if (*(s32 *)&o->scale[0] != 0x10001000 || *(s32 *)&o->scale[2] != 0x1000 || *(s32 *)&o->a56[1] != 0) {
        o->flags |= 0x400000;
    }
}

typedef struct {
    u8 pad0[0x10];
    u32 unk10;
} OAFE4;
typedef struct {
    u8 pad0[0xC];
    void *unkC;
    u8 pad10[0x6C];
    s16 unk7C;
} EAFE4;
typedef struct {
    Blk80033F20 hdr;
    void (*fn)();
    s32 pad8;
    EAFE4 e;
} BAFE4;
void func_8003B258();
void func_8003C22C();
void func_80043B30();
void func_8003AFE4(s32 arg0) {
    s32 n = 0;
    OAFE4 *o;
    BAFE4 *p;
    while ((n = func_8004208C(n, 10, arg0)) != 0) {
        o = func_80041F6C((void *)n);
        if (!(o->unk10 & 1)) {
            func_8003B258(o);
        }
        o->unk10 |= 1;
        if (D_1F800008_b != NULL) {
        restart:
            p = (BAFE4 *)(D_1F800008_b + 1);
            if (p->hdr.next != 0) {
                do {
                    if (p->hdr.used && p->fn == func_80043B30) {
                        EAFE4 *e = &p->e;
                        if (e->unkC == o) {
                            if (e->unk7C == 0) {
                                func_8003C22C(e);
                                goto restart;
                            }
                            e->unk7C = 1;
                        }
                    }
                    p = (BAFE4 *)(p->hdr.next * 4 + (u32)D_1F800008_b);
                } while (p->hdr.next != 0);
            }
        }
    }
}

void func_8003B12C(s32 *arg0, s32 arg1) {
    arg0[-1] = arg1;
}

void func_8003B134(s32 *arg0, s32 arg1) {
    arg0[-2] = arg1;
}

typedef struct H8003B13C {
    u32 lo : 16;
    u32 mid : 15;
    u32 top : 1;
} H8003B13C;
typedef struct B8003B13C {
    s32 unk0;
    H8003B13C h;
} B8003B13C;
extern char D_80063444[];
extern B8003B13C *D_1F800008_ asm("D_1F800008");
extern H8003B13C *D_8006B244_ asm("D_8006B244");
extern s32 D_8006B240;
extern s32 D_8006B24C;
extern u8 D_8006B30C;
void func_8003DB78(char *);
s32 func_8003D8F4(s32, s32, s32);

void func_8003B13C(s32 size, s32 arg1) {
    B8003B13C *p;
    H8003B13C *end;
    func_8003DB78(D_80063444);
    p = (B8003B13C *)func_8003D8F4(size, arg1, 1);
    D_1F800008_ = p;
    D_8006B244_ = end = (H8003B13C *)((u8 *)p + size - 0xC);
    D_8006B240 = 0;
    D_8006B24C = 0;
    D_8006B30C = 0;
    p->h.mid = 0;
    p->h.lo = ((u32)end - (u32)p) >> 2;
    p->h.top = 0;
    end->mid = 1;
    end->lo = 0;
    end->top = 1;
}

void func_8003B210(void **arg0) {
    ((void (*)(void))arg0[-1])();
}

typedef struct Unk8003B238 {
    struct Unk8003B238 *next;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u32 unk10;
} Unk8003B238;
extern Unk8003B238 *D_8006B248;
void func_8003B238(Unk8003B238 *arg0) {
    arg0->next = D_8006B248;
    D_8006B248 = arg0;
    arg0->unk8 = 0;
    arg0->unkC = arg0->unkA;
}

void func_8003B258(Unk8003B238 *arg0) {
    Unk8003B238 *prev = NULL;
    Unk8003B238 *n;
    for (n = D_8006B248; n != NULL; n = n->next) {
        if (n == arg0) {
            if (prev != NULL) {
                prev->next = n->next;
            } else {
                D_8006B248 = n->next;
            }
            return;
        }
        prev = n;
    }
}

s32 f_34024_a(void) asm("func_80034024");
s32 func_8003B2B0(void) {
    s32 r = f_34024_a();
    if (r == 0) {
        func_80029D9C();
    }
    return r;
}

void f_3D504_a(void *) asm("func_8003D504");
extern s32 D_8006B240_w asm("D_8006B240");
extern s32 D_8006B244_w asm("D_8006B244");
extern u8 D_8006B30C_b asm("D_8006B30C");
void func_8003B2E8(void) {
    f_3D504_a(D_1F800008_b);
    D_1F800008_b = 0;
    D_8006B240_w = 0;
    D_8006B244_w = 0;
    D_8006B30C_b = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B330);

extern s32 D_8006B258;
extern s32 D_8006B24C;
extern u8 D_8007EDEC[];
extern u8 D_8007EDF0[];
extern u8 D_8006B454;
extern u8 D_8006B30C;
void func_8003BC80(u8);
void func_8003B420(void) {
    D_8006B248 = 0;
    D_8006B258 = 0;
    D_8006B24C = 0;
    D_8007EDEC[0] = 0;
    D_8007EDEC[1] = 0;
    D_8007EDEC[2] = 0;
    D_8007EDF0[0] = 0;
    D_8007EDF0[1] = 0;
    D_8007EDF0[2] = 0;
    D_8006B454 = 0;
    D_8006B30C = 0;
    func_8003BC80(0);
}

s16 *f_30814_a(s32, s32) asm("func_80030814");
void func_8003B490(void *arg0, u16 *arg1) {
    u16 *p = f_30814_a(((s32 *)func_80041F6C(arg0))[5], 8);
    if (p != NULL) {
        p[1] = arg1[0];
        p[2] = arg1[1];
        p[3] = arg1[2];
    }
}

void func_8003B4F0(void *arg0, u16 *arg1) {
    u16 *p = f_30814_a(((s32 *)func_80041F6C(arg0))[5], 8);
    if (p != NULL) {
        arg1[0] = p[1];
        arg1[1] = p[2];
        arg1[2] = p[3];
    }
}

void func_8003B550(void *arg0, u32 arg1) {
    s16 *p = f_30814_a(((s32 *)func_80041F6C(arg0))[5], 0x30);
    if (p != NULL) {
        p[2] = arg1;
        p[3] = arg1 >> 16;
    }
}

void func_8003B594(void *arg0) {
    Unk8003B238 *n = func_80041F6C(arg0);
    if (n->unk10 & 1) {
        func_8003B238(n);
        if ((n->unk10 >> 10) & 1) {
            n->unk8 = 0;
            n->unkC = 1;
        }
    }
    n->unkC = 1;
    n->unk8 = 0;
    n->unk10 &= ~1;
}

void f_3B258_a(void *) asm("func_8003B258");
void func_8003B610(void *arg0) {
    u32 *p = func_80041F6C(arg0);
    if (!(p[4] & 1)) {
        f_3B258_a(p);
    }
    p[4] |= 1;
}

typedef struct { u8 pad[8]; s16 h8; s16 hA; s16 hC; s16 hE; u32 b0 : 1; u32 b1 : 9; u32 b10 : 1; u32 rest : 21; } S3B660;
void *f_4208C_z7(void *, s32, s32) asm("func_8004208C");
S3B660 *f_41F6C_z7(void *) asm("func_80041F6C");
void f_3B238_z7(void *) asm("func_8003B238");
void func_8003B660(s32 arg0) {
    void *p = NULL;
    while ((p = f_4208C_z7(p, 10, arg0)) != NULL) {
        S3B660 *q = f_41F6C_z7(p);
        if (q->b0) {
            f_3B238_z7(q);
            if (q->b10) {
                q->h8 = 0;
                q->hC = 1;
            }
        }
        q->h8 = 0;
        q->hC = 1;
        q->b0 = 0;
    }
}

typedef struct { u8 pad[0x10]; u32 w10; } S3B720b;
void *f_4208C_d(void *, s32, s32) asm("func_8004208C");
S3B720b *f_41F6C_d(void *) asm("func_80041F6C");
void f_3B258_d(void *) asm("func_8003B258");
void func_8003B720(s32 arg0) {
    void *p = NULL;
    while ((p = f_4208C_d(p, 10, arg0)) != NULL) {
        S3B720b *q = f_41F6C_d(p);
        if (!(q->w10 & 1)) {
            f_3B258_d(q);
        }
        q->w10 = (q->w10 & ~1) | 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B7BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B8C8);

extern s16 D_1F800010_z7 asm("D_1F800010");
extern u8 D_1F800000_z7 asm("D_1F800000");
s32 func_8003B9A8(u8 *arg0) {
    s32 h = *(s16 *)(arg0 + 0x7C);
    s32 pos;
    s32 vel;
    s32 n;
    s32 acc;
    if (h != 0 && h - D_1F800010_z7 <= 0) {
        return 1;
    }
    pos = *(s32 *)(arg0 + 4);
    vel = *(s32 *)(arg0 + 0x14);
    acc = *(s32 *)(arg0 + 0x24);
    for (n = D_1F800010_z7; n != 0; n--) {
        pos += vel << D_1F800000_z7;
        vel += acc;
        if (*(s16 *)(arg0 + 0x84) != 0) {
            vel = ((vel >> 6) * *(s16 *)(arg0 + 0x84)) >> 6;
        }
    }
    if (((*(u32 *)(arg0 + 0x88) >> 4) & 1) && ((*(u16 *)(arg0 + 0x82) << D_1F800000_z7) << 16) < pos) {
        return 1;
    }
    return 0;
}

s32 func_8003BA64(u8 *arg0) {
    u16 *p = *(u16 **)(arg0 + 0x14);
    s32 n = 0x18;
    if (p != NULL) {
        do {
            u32 h = *p;
            n += (h >> 9) & 0x3F;
            if (h & 0x8000) {
                p = *(u16 **)((u8 *)p + ((((*(u32 *)p >> 9) & 0x3F) + 3) & ~3));
            } else {
                p = (u16 *)((u8 *)p + ((h >> 9) & 0x3F));
            }
            if (!(*p & 0x1FF)) {
                n += (*p >> 9) & 0x3F;
                break;
            }
        } while (p != NULL);
    }
    return n;
}

s32 *f_3D8F4_a(s32, s32, s32) asm("func_8003D8F4");
void f_3F884_b(void *, s32) asm("func_8003F884");
extern s32 D_8006B240_y asm("D_8006B240");
extern s32 D_8006B244_y asm("D_8006B244");
extern s32 D_8006B248_y asm("D_8006B248");
extern s32 D_8006B258_y asm("D_8006B258");
extern s32 D_1F800008_y asm("D_1F800008");
s32 *func_8003BAF0(s32 arg0) {
    s32 *p = f_3D8F4_a(12, arg0, 1);
    s32 a, b, c, n;
    f_3F884_b(p, 12);
    a = D_1F800008_y;
    b = D_8006B244_y;
    c = D_8006B248_y;
    n = D_8006B258_y;
    D_8006B240_y = 0;
    D_1F800008_y = 0;
    D_8006B244_y = 0;
    D_8006B248_y = 0;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    D_8006B258_y = n + 1;
    return p;
}

extern s32 D_1F800008_w asm("D_1F800008");
extern s32 D_8006B244_x asm("D_8006B244");
extern s32 D_8006B248_x asm("D_8006B248");
extern s32 D_8006B258_x asm("D_8006B258");
void f_3D504_b(void *) asm("func_8003D504");
void func_8003BB78(s32 *arg0) {
    D_1F800008_w = arg0[0];
    D_8006B244_x = arg0[1];
    D_8006B248_x = arg0[2];
    D_8006B258_x--;
    f_3D504_b(arg0);
}

typedef struct {
    u8 pad0[8];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u32 unk10;
    void *unk14;
    u8 unk18[1];
} Unk8003BBC8;

void func_8003BBC8(Unk8003BBC8 *p) {
    u32 f;
    if (p->unk14 == NULL) {
        p->unk14 = p->unk18;
        p->unk10 |= 1;
        f = (p->unk10 >> 2) & 1;
        if (f) {
            if (!(p->unk10 & 1)) {
                func_8003B258((Unk8003B238 *)p);
            }
        } else if (p->unk10 & 1) {
            func_8003B238((Unk8003B238 *)p);
            if ((p->unk10 >> 10) & 1) {
                p->unk8 = 0;
                p->unkC = 1;
            }
        }
        p->unk10 = (p->unk10 & ~1) | f;
    }
}

extern u8 D_8006B30C;
extern u8 D_800B61EC[];

void func_8003BC80(u8 arg0) {
    s32 i;
    s32 *p;
    D_8006B30C = arg0;
    if (arg0 != 0) {
        i = 0;
        while ((p = (s32 *)func_80030934(i++)) != NULL) {
            func_80096178(*p, D_800B61EC);
        }
    } else {
        i = 0;
        while ((p = (s32 *)func_80030934(i++)) != NULL) {
            if (*(u8 **)(*p + 0x1F8) == D_800B61EC) {
                func_80096180(*p);
            }
        }
    }
}

void func_8003BD2C(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BD34);

extern u8 *D_1F800008_c asm("D_1F800008");
void *func_8003BE00(u8 *arg0, void *arg1) {
    u8 *e;
    if (D_1F800008_c == NULL) {
        return NULL;
    }
    if (arg0 == NULL) {
        e = D_1F800008_c + 4;
    } else {
        e = (u8 *)((*(u16 *)(arg0 - 0xC) << 2) + (s32)D_1F800008_c);
    }
    while (*(u16 *)e != 0) {
        if (*(s32 *)e < 0 && *(void **)(e + 4) == arg1) {
            return e + 0xC;
        }
        e = (u8 *)((*(u16 *)e << 2) + (s32)D_1F800008_c);
    }
    return NULL;
}

s16 func_8003BEA0(void *arg0) {
    return ((s16 *)func_80041F6C(arg0))[3];
}

typedef struct { u8 pad[8]; s16 h8; s16 hA; s16 hC; s16 hE; u32 b0 : 1; u32 b1 : 9; u32 b10 : 1; u32 rest : 21; } S3BEC4;
void f_3B238_e(void *) asm("func_8003B238");
void func_8003BEC4(S3BEC4 *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (!arg0->b0) {
            f_3B258_d(arg0);
        }
    } else if (arg0->b0) {
        f_3B238_e(arg0);
        if (arg0->b10) {
            arg0->h8 = 0;
            arg0->hC = 1;
        }
    }
    arg0->b0 = arg1;
}

typedef struct { u8 pad[0x10]; u32 w10; } S3BF6C;
extern u8 *D_1F800008_z5 asm("D_1F800008");
void f_3B258_z5(void *) asm("func_8003B258");
void f_3C22C_z5(void *) asm("func_8003C22C");
void func_80043B30(void);
void func_8003BF6C(S3BF6C *arg0) {
    u8 *e;
    if (!(arg0->w10 & 1)) {
        f_3B258_z5(arg0);
    }
    arg0->w10 |= 1;
    if (D_1F800008_z5 == NULL) {
        return;
    }
again:
    e = D_1F800008_z5 + 4;
    if (*(u16 *)e == 0) {
        return;
    }
    do {
        if (*(s32 *)e < 0 && *(void **)(e + 4) == func_80043B30) {
            u8 *q = e + 0xC;
            if (*(void **)(q + 0xC) == arg0) {
                f_3C22C_z5(q);
                goto again;
            }
        }
        e = (u8 *)((*(u16 *)e << 2) + (s32)D_1F800008_z5);
    } while (*(u16 *)e != 0);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C048);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C138);

typedef struct {
    u8 pad0[8];
    u32 unk8;
} Unk8003C22C_1C;
typedef struct {
    u8 pad0[0x1C];
    Unk8003C22C_1C *unk1C;
    u8 pad20[0x5A];
    s16 unk7A;
    u8 pad7C[0xC];
    s32 unk88;
} Unk8003C22C;
extern u8 D_8006B479;
extern Unk8003C22C *D_800D9AE8;
extern Unk8003C22C *D_800D9AB8;

void func_8003C22C(Unk8003C22C *o) {
    if (o->unk88 < 0) {
        if (o->unk1C != NULL) {
            if (((u32)o->unk88 >> 30) & 1) {
                func_80095578(func_80041F6C(o->unk1C));
                func_800421E8(o->unk1C);
            } else if ((o->unk1C->unk8 & 0x3F) == 0x11) {
                func_80021C0C(o->unk7A);
            }
        }
        if (D_8006B479 == 1) {
            if (D_800D9AE8 == o) {
                D_800D9AE8 = NULL;
            }
            if (D_800D9AB8 == o) {
                D_800D9AB8 = NULL;
            }
        }
    }
    func_80033F20(o);
}

void f_SetBackColor_a(s32, s32, s32) asm("SetBackColor");
extern u8 D_8006B308_a[] asm("D_8006B308");
void func_8003C304(s32 arg0, s32 arg1, s32 arg2) {
    f_SetBackColor_a(arg0, arg1, arg2);
    D_8006B308_a[0] = arg0;
    D_8006B308_a[1] = arg1;
    D_8006B308_a[2] = arg2;
}

extern u8 *D_1F800014_z5 asm("D_1F800014");
extern s32 D_8006B420_z5[] asm("D_8006B420");
void f_11554_z5(void *) asm("func_80011554");
void f_11474_z5(void *, s32) asm("func_80011474");
void AddPrim_z5(void *, void *) asm("AddPrim");
void f_3CCF8_z5(void *, s32) asm("func_8003CCF8");
void func_8003C354(u8 *arg0, s32 arg1, void *arg2) {
    u8 *p = D_1F800014_z5;
    D_1F800014_z5 = p + 0x18;
    f_11554_z5(p);
    if (arg1 != 0) {
        f_11474_z5(p, 1);
        arg1--;
    }
    p[4] = arg0[0];
    p[5] = arg0[1];
    p[6] = arg0[2];
    *(s16 *)(p + 0x8) = 0;
    *(s16 *)(p + 0xA) = 0;
    *(s16 *)(p + 0xC) = 0x160;
    *(s16 *)(p + 0xE) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s16 *)(p + 0x12) = 0x110;
    *(s16 *)(p + 0x14) = 0x160;
    *(s16 *)(p + 0x16) = 0x110;
    AddPrim_z5(arg2, p);
    f_3CCF8_z5(arg2, D_8006B420_z5[arg1]);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C42C);

s32 f_3B9A8_a() asm("func_8003B9A8");
s32 f_4A26C_a() asm("func_8004A26C");
s32 f_33B70_a() asm("func_80033B70");
s32 f_4A5E4_a() asm("func_8004A5E4");
s32 f_4A6D0_a() asm("func_8004A6D0");
void func_8003C4B8(u8 *arg0) {
    s32 a;
    s32 b;
    u8 *p = arg0;
    if (f_3B9A8_a(arg0) & 0xFF) {
        f_4A26C_a(*(s16 *)(arg0 + 0x7A));
    }
    f_33B70_a(p, &a, &b);
    f_4A5E4_a(0, *(s16 *)(p + 0x7A), b);
    f_4A6D0_a(0, *(s16 *)(p + 0x7A), a);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C52C);

typedef struct B8003C630 {
    s32 w;
    void *fn;
    s32 pad8;
} B8003C630;
extern u8 *SPAD_BASE asm("D_1F800008");
void *f_33D80_g(s32, s32) asm("func_80033D80");
void f_3C22C_g(void *) asm("func_8003C22C");
void f_43B30_g(void) asm("func_80043B30");
void L8003F63C_g(void) asm(".L8003F63C");
void *func_8003C630(s32 size, s32 owner) {
    void *r;
    B8003C630 *b;
    u8 *p;
outer:
    for (;;) {
        r = f_33D80_g(size, owner);
        if (r != NULL) {
            return r;
        }
        b = (B8003C630 *)(SPAD_BASE + 4);
        while (*(u16 *)b != 0) {
            if (b->w < 0) {
                p = (u8 *)(b + 1);
                if (b->fn == (void *)f_43B30_g && *(s16 *)(p + 0x7C) != 0) {
                    f_3C22C_g(p);
                    goto outer;
                }
            }
            b = (B8003C630 *)((*(u16 *)b << 2) + (u32)SPAD_BASE);
        }
        L8003F63C_g();
    }
}

typedef struct { u8 pad[0xA]; s16 hA; s16 hC; s16 hE; u32 b0 : 3; u32 b3 : 6; u32 rest : 23; } S3C714;
void f_34024_z7(void *) asm("func_80034024");
s32 rand_z7(void) asm("rand");
void func_8003C714(S3C714 *arg0) {
    if (--arg0->hC == -1) {
        s32 i;
        for (i = 0; i <= arg0->hE; i++) {
            f_34024_z7(arg0);
        }
        arg0->hC = arg0->hA;
        if (arg0->b3 != 0) {
            arg0->hC += (rand_z7() % arg0->b3) * 2;
        }
    }
}

void func_80043B30();
void func_8003C7D0(s32 *arg0) {
    func_8003B134(arg0, (s32)func_80043B30);
}

typedef struct {
    s32 vx, vy, vz, pad;
} VECTOR_8003C7F4;
typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR_8003C7F4;
typedef struct {
    s16 m[3][3];
    s32 t[3];
} MATRIX_8003C7F4;
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x14];
    MATRIX_8003C7F4 unk30;
    u8 pad50[0x38];
    u32 unk88;
} Unk8003C7F4;

void func_8003C7F4(Unk8003C7F4 *o) {
    VECTOR_8003C7F4 v;
    VECTOR_8003C7F4 sq;
    SVECTOR_8003C7F4 rot;
    MATRIX_8003C7F4 m;
    s32 len;
    v.vx = o->unk10 >> 8;
    v.vy = o->unk14 >> 8;
    v.vz = o->unk18 >> 8;
    Square0(&v, &sq);
    len = SquareRoot0(sq.vx + sq.vz);
    rot.vx = 0;
    rot.vy = -func_80027684(v.vz, v.vx);
    if ((o->unk88 >> 13) & 2) {
        rot.vz = 0;
    } else {
        rot.vz = func_80027684(v.vy, len);
    }
    RotMatrix(&rot, &m);
    MulMatrix0(&m, &o->unk30, &o->unk30);
}

s32 func_80025044(s32);
s32 func_8003C8CC(s16 *arg0, u16 *arg1) {
    s32 ret = 0;
    if (arg0[1] != 0) {
        ret = func_80025044((arg1[4] & 0xFFF) * arg0[1] + arg0[2]) * arg0[0] * 16;
    }
    return ret;
}

typedef struct { s32 t; s32 arg; void (*fn)(s32); } T3C930;
extern s16 D_1F800010_h asm("D_1F800010");
void f_33F20_d(void *) asm("func_80033F20");
void func_8003C930(T3C930 *arg0) {
    arg0->t -= D_1F800010_h;
    if (arg0->t < 0) {
        arg0->fn(arg0->arg);
        f_33F20_d(arg0);
    }
}

void SetFogNearFar(s32, s32, s32);
extern s16 D_8007EDE8;
extern s16 D_8007EDE2;
void func_8003C988(s32 arg0, s32 arg1, s32 arg2) {
    SetFogNearFar(arg0, arg1, arg2);
    D_8007EDE8 = arg0;
    D_8007EDE2 = arg1;
}

void f_SetFarColor_a(s32, s32, s32) asm("SetFarColor");
extern u8 D_8007EDE4_a[] asm("D_8007EDE4");
void func_8003C9C8(s32 arg0, s32 arg1, s32 arg2) {
    f_SetFarColor_a(arg0, arg1, arg2);
    D_8007EDE4_a[0] = arg0;
    D_8007EDE4_a[1] = arg1;
    D_8007EDE4_a[2] = arg2;
}

