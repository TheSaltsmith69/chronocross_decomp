#include "common.h"

typedef struct Unk8006B490 {
    struct Unk8006B490 *next;
    s32 unk4;
    u32 unk8;
    s32 unkC;
} Unk8006B490;
extern Unk8006B490 *D_8006B490;

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8003FD00);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800404F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040780);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040928);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80040DD0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800413F8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041820);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041AEC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041C0C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041E2C);

void func_80041EAC(s32 *arg0, s32 arg1) {
    arg0[1] = arg1;
}

void func_80041EB4(Unk8006B490 *arg0, Unk8006B490 *arg1) {
    Unk8006B490 *head = D_8006B490;
    u32 flags = arg0->unk8;
    D_8006B490 = arg0;
    arg0->next = head;
    if (((flags >> 8) & 0x3F) == 0) {
        if (arg1 != NULL) {
            arg0->unk8 = (flags & ~0x3F00) | ((arg1->unk8 & 0x3F) << 8);
        } else {
            arg0->unk8 = flags & ~0x3F00;
        }
    }
}

Unk8006B490 *func_80041F0C(u32 arg0, s32 arg1) {
    Unk8006B490 *n;
    for (n = D_8006B490; n != NULL; n = n->next) {
        if ((n->unk8 & 0x3F) == arg0 && (arg1 == 0 || n->unk4 == arg1)) {
            return n;
        }
    }
    return NULL;
}

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
    s32 unkC;
} Unk80041F6C;
void *func_80041F6C(Unk80041F6C *arg0) {
    if (!(arg0->unk8 >> 7)) {
        return &arg0->unkC;
    }
    return (void *)arg0->unkC;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80041F94);

void DrawSync(s32);
void func_80041820(s32);
void func_80041FD4(s32 arg0) {
    DrawSync(0);
    func_80041820(arg0);
}

void func_80040DD0(Unk8006B490 *);
void func_80042004(Unk8006B490 *arg0) {
    Unk8006B490 *n;
    for (n = D_8006B490; n != NULL; n = n->next) {
        if (((n->unk8 >> 8) & 0x3F) == (arg0->unk8 & 0x3F)) {
            func_80040DD0(n);
        }
    }
}

void func_8004206C(s32 *arg0) {
    arg0[2] |= 0x80000000;
}

extern s32 D_8006B494_t asm("D_8006B494");
void func_80042080(s32 arg0) {
    D_8006B494_t = arg0;
}

Unk8006B490 *func_8004208C(Unk8006B490 *arg0, u32 arg1, s32 arg2) {
    if (arg0 != NULL) {
        arg0 = arg0->next;
    } else {
        arg0 = D_8006B490;
    }
    for (; arg0 != NULL; arg0 = arg0->next) {
        if ((arg0->unk8 & 0x3F) == arg1 && (arg2 == 0 || arg0->unk4 == arg2)) {
            return arg0;
        }
    }
    return NULL;
}

typedef struct Obj800420FC {
    struct Obj800420FC *next;
    s32 unk4;
    u32 id : 6;
    u32 f6 : 1;
    u32 f7 : 1;
    u32 parent : 6;
    u32 cnt : 17;
    u32 top : 1;
    s32 unkC;
} Obj800420FC;
extern u8 D_8006B3E0;
s32 func_8003D8F4(s32, s32, s32);
void func_8003F884(void *, s32);

Obj800420FC *func_800420FC(s32 id, s32 a1, s32 a2) {
    Obj800420FC *o = (Obj800420FC *)func_8003D8F4(0x10, D_8006B3E0, 1);
    u32 flags;
    func_8003F884(o, 0x10);
    o->unk4 = 0x30;
    o->cnt = 3;
    o->id = 7;
    o->f6 = 0;
    o->f7 = 0;
    o->unk4 = a1;
    o->unkC = a2;
    o->id = id;
    o->f7 = 1;
    o->next = (Obj800420FC *)D_8006B490;
    D_8006B490 = (Unk8006B490 *)o;
    flags = ((u32 *)o)[2];
    if (o->parent == 0) {
        ((u32 *)o)[2] = flags & ~0x3F00;
    }
    return o;
}

void f_40928_t(s32) asm("func_80040928");
void f_3D504_u(s32) asm("func_8003D504");
void func_800421E8(s32 arg0) {
    f_40928_t(arg0);
    f_3D504_u(arg0);
}

void func_800413F8(Unk8006B490 *);
void func_80042214(Unk8006B490 *arg0) {
    Unk8006B490 *n;
    for (n = D_8006B490; n != NULL; n = n->next) {
        if (((n->unk8 >> 8) & 0x3F) == (arg0->unk8 & 0x3F)) {
            func_800413F8(n);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004227C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800422E8);

typedef struct {
    void *next;
    s32 tag;
    u32 flags;
} Node80042364;
extern Node80042364 D_80086FD0[5];
extern Unk8006B490 *D_8006B4B0;
void func_8003F884(void *, s32);

void func_80042364(void) {
    s32 i;
    Node80042364 *p = D_80086FD0;
    D_8006B490 = NULL;
    D_8006B4B0 = NULL;
    for (i = 0; i != 5; i++, p++) {
        func_8003F884(p, 12);
        p->flags = (p->flags & ~0x3F) | 0xF;
        switch (i) {
        case 0:
            p->tag = 0x656E696C;
            break;
        case 1:
            p->tag = 0x74616C66;
            break;
        case 2:
            p->tag = 0x306E7573;
            break;
        case 3:
            p->tag = 0x7467696C;
            p->flags = (p->flags & ~0x3F) | 0x11;
            break;
        case 4:
            p->tag = 0x6F726373;
            break;
        }
        func_80041EB4((Unk8006B490 *)p, NULL);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004247C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800424AC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_8004257C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042928);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_800429B4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042A10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042AE0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042AE8);

void func_80042B10(void *sp) {
    __asm__ volatile("addu $sp, %0, $zero\n\taddu $fp, $sp, $zero" : : "r"(sp));
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80042B20);

void func_80043B28(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043B30);

INCLUDE_ASM("asm/nonmatchings/game/unk_8003FD00", func_80043F0C);

