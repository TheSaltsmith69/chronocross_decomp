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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030784);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800307AC);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030804);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800308EC);

extern s32 D_8006B1F8;
void func_800308F8(s32 arg0) {
    D_8006B1F8 = arg0;
}

extern s32 D_8006B1FC;
void func_80030904(s32 arg0) {
    D_8006B1FC = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030910);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003091C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030928);

s32 func_80030934(s32 arg0) {
    if (D_8006B1F4 != 0) {
        return ((s32 (*)(s32))D_8006B1F4)(arg0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030968);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003099C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800309D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030A04);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030A38);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030A6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030AA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80030B98);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80031074);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800314D4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800318BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80031AC0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800321B8);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032A08);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032A54);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032AAC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032B54);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032D40);

s32 func_8004208C(s32, s32, s32);
void func_80032C5C(void *);
void func_80032D78(s32 arg0) {
    s32 p = 0;
    while ((p = func_8004208C(p, 0xC, arg0)) != 0) {
        func_80032C5C(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032DD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032E60);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80032EB4);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033080);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800331AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003324C);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033588);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033654);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033940);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800339E8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800339F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033A80);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033B58);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033B70);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033D80);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80033F20);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80034024);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800342B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_800369FC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80036F4C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037320);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037B40);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037CA8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_80037E68);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003A4C0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003AFE4);

void func_8003B12C(s32 *arg0, s32 arg1) {
    arg0[-1] = arg1;
}

void func_8003B134(s32 *arg0, s32 arg1) {
    arg0[-2] = arg1;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B13C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B210);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B2B0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B2E8);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B490);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B4F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B550);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B610);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B660);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B720);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B7BC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B8C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003B9A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BA64);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BAF0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BB78);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BE00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BEA0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BEC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003BF6C);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C304);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C354);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C42C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C4B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C52C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C630);

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C714);

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

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C930);

void SetFogNearFar(s32, s32, s32);
extern s16 D_8007EDE8;
extern s16 D_8007EDE2;
void func_8003C988(s32 arg0, s32 arg1, s32 arg2) {
    SetFogNearFar(arg0, arg1, arg2);
    D_8007EDE8 = arg0;
    D_8007EDE2 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8002FE30", func_8003C9C8);
