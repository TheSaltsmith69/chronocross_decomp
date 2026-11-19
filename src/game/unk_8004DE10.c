#include "common.h"
#include "sound.h"

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DE10);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DE64);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DEB8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DF98);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004DFDC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E084);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E0D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E464);

typedef struct {
    u8 pad0[0x28];
    s32 unk28;
    u8 pad2C[8];
    u32 unk34;
    u8 pad38[0x18];
    s32 unk50;
    u8 pad54[0x18];
    s32 unk6C;
    u8 pad70[0xB4];
} C8004E538;
extern C8004E538 D_80089E40_c[] asm("D_80089E40");
void func_80053EBC();
extern s32 D_8008BEB0[];
void func_8004E538(s32 id, s32 flags) {
    u32 bit = 0x1000;
    C8004E538 *ch = D_80089E40_c;
    u32 mask = D_8008BEB0[0] | D_8008BEB0[4];
    u32 i;
    s32 max;
    if (flags & 0x0FFFFFFF) {
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if ((mask & bit) && (ch->unk28 & flags)) {
                if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
            }
        }
    } else if (flags < 0) {
        ch = &D_80089E40_c[id];
        bit <<= id;
        if (mask & bit) {
            func_8004E538(ch->unk50, 0);
        }
        bit <<= 1;
        ch++;
        if (mask & bit) {
            func_8004E538(ch->unk50, 0);
        }
        return;
    } else if (flags & 0x40000000) {
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if (ch->unk28 != 0) {
                mask &= ~bit;
            }
        }
        ch = D_80089E40_c;
        bit = 0x1000;
        max = 0;
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if ((mask & bit) && max < ch->unk6C) {
                max = ch->unk6C;
            }
        }
        ch = D_80089E40_c;
        bit = 0x1000;
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if ((mask & bit) && max == ch->unk6C) {
                if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
            }
        }
    } else {
        for (i = 0; i < 12; i++, ch++, bit <<= 1) {
            if (mask & bit) {
                if (id == -1) {
                    if (ch->unk50 < 0) {
                        if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
                    }
                } else if (ch->unk50 == id) {
                    if (ch->unk34 & 0x100000) {
                ch->unk34 |= 0x200000;
            } else {
                D_8008BEB0[3] |= bit;
                func_80053EBC(ch, bit);
                ch->unk34 = 0;
            }
                }
            }
        }
    }
    D_8008E398[2] |= 0x110;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004E898);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EA34);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EA90);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004EC88);

void func_8004ED00(s32 *arg0, Unk80051F24 *ch) {
    u32 mask;
    s32 bit;
    if (arg0[1] != 0) {
        mask = arg0[1];
        bit = 1;
        do {
            if (mask & bit) {
                ch->unk10C |= 3;
                mask ^= bit;
            }
            ch++;
            bit <<= 1;
        } while (mask != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004ED48);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004ED9C);

extern Unk80051F24 D_8008AD48;
void func_8004ED9C(s32, s32);
void func_8004E0D0(s32, s32);
void func_8004F04C(s32 *arg0) {
    if (D_8008AD48.unk6E != 0 && D_8008AD48.unk6E == arg0[2]) {
        func_8004ED9C(arg0[0], 0);
    } else {
        func_8004E0D0(arg0[0], -1);
        D_8008BE50->unk6E = arg0[2];
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F0C8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F148);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F1F0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F2B8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F484);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F4C4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F510);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F5D8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F688);

void func_8004E538(s32, s32);
void func_8004F7A8(s32 *arg0) {
    func_8004E538(arg0[0], arg0[1]);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004F7D4);

extern Unk80051F24 *D_8008ABF8;
extern u8 *D_8008ABF4;
extern u8 D_80087980[];
void func_8004F888(s32 *arg) {
    s32 n = 1;
    Unk80051F24 *ch;
    s32 v;
    s32 cur;
    if (arg[1] != 0) {
        n = arg[1];
    }
    v = ((arg[2] & 0x7F) << 16) | 0x8000;
    arg = (s32 *)arg[0];
    if (arg == 0 || (s32)arg == D_8008BE50->unk6E) {
        cur = D_8008BE50->unk54;
        cur &= 0xFFFF0000;
        cur |= 0x8000;
        v -= cur;
        v /= n;
        D_8008BE50->unk5C = n;
        D_8008BE50->unk54 = cur;
        D_8008BE50->unk58 = v;
        func_8004ED00(D_8008BE50, D_80087980);
    } else {
        ch = D_8008ABF8;
        if (ch != NULL && arg != 0 && (s32)arg == ch->unk6E) {
            cur = ch->unk54;
            cur &= 0xFFFF0000;
            cur |= 0x8000;
            v -= cur;
            v /= n;
            ch->unk5C = n;
            ch->unk54 = cur;
            ch->unk58 = v;
            func_8004ED00(ch, D_8008ABF4);
        }
    }
}

extern Unk80051F24 *D_8008ABF8;
extern u8 *D_8008ABF4;
extern u8 D_80087980[];

void func_8004F9C4(s32 *arg) {
    s32 n = 1;
    Unk80051F24 *ch;
    u8 *tbl;
    s32 v;
    if (arg[1] != 0) {
        n = arg[1];
    }
    if (arg[0] == 0 || arg[0] == D_8008BE50->unk6E) {
        ch = D_8008BE50;
        tbl = D_80087980;
    } else if (D_8008ABF8 != NULL && arg[0] != 0 && arg[0] == D_8008ABF8->unk6E) {
        ch = D_8008ABF8;
        tbl = D_8008ABF4;
    } else {
        return;
    }
    v = ((arg[2] & 0x7F) << 16) | 0x8000;
    ch->unk54 = v;
    ch->unk58 = ((((arg[3] & 0x7F) << 16) | 0x8000) - v) / n;
    ch->unk5C = n;
    func_8004ED00(ch, tbl);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FAC4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FB78);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FC98);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FCCC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FD34);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FDA4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8004FE8C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005000C);

extern s32 D_8008BEB0[];
extern Unk80051F24 D_80089E40[];

void func_80050088(s32 *arg0) {
    u32 mask = 0x1000;
    s32 active = D_8008BEB0[0];
    u32 i;
    Unk80051F24 *ch = D_80089E40;
    s16 n;
    for (i = 0; i < 12; i++, ch++, mask <<= 1) {
        if ((active & mask) && !(ch->unk28 & 0x2000000)) {
            n = 1;
            if (arg0[0] != 0) {
                n = arg0[0];
            }
            ch->unkF2 = (s16)(((((u16 *)arg0)[2] & 0x7F) << 8) - ch->unkF0) / n;
            ch->unkA0 = n;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050150);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050230);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800503A8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050420);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800504E4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800505C4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005074C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800507A4);

extern s16 D_8008ADCA_t asm("D_8008ADCA");
extern s32 D_8008E394_t asm("D_8008E394");
void func_80050870(s8 *arg0) {
    s32 v = *arg0;
    D_8008ADCA_t = 0;
    D_8008E394_t = v << 16;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_8005088C);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800508F4);

extern s16 D_8008ADC8_t asm("D_8008ADC8");
extern s32 D_8008E390_t asm("D_8008E390");
void func_80050968(s8 *arg0) {
    s32 v = *arg0;
    D_8008ADC8_t = 0;
    D_8008E390_t = v << 16;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050984);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800509EC);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050A60);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050AB0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050B18);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050BF4);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050C54);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050CB4);

extern u8 *D_8008BE50_u asm("D_8008BE50");
void func_80050CF4(u16 *arg0) {
    *(u16 *)(D_8008BE50_u + 0x70) = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050D08);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050DF8);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050E94);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80050FB0);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_80051044);

INCLUDE_ASM("asm/nonmatchings/game/unk_8004DE10", func_800510C0);

extern s32 D_80089E08[];
extern Unk80051F24 D_80089E40[];
extern s32 D_8008BEB0[];
void func_80050088(s32 *);
void func_80051154(s32 *arg0) {
    u32 i;
    for (i = 0; i < 12; i++) {
        D_80089E08[i] = (s16)D_80089E40[i].unkF0 >> 8;
    }
    arg0[1] = 0;
    func_80050088(arg0);
    if (D_8008BEB0[0] != 0) {
        D_8008E398[0] |= 0x10000;
    }
}

extern s32 D_80089E08[];
extern Unk80051F24 D_80089E40[];
extern s32 D_8008BEB0[];

void func_800511D0(s32 *arg0) {
    u32 mask;
    s32 active;
    u32 i;
    Unk80051F24 *ch;
    s32 *p;
    s16 n;
    D_8008E398[0] &= ~0x10000;
    if (D_8008BEB0[4] != 0) {
        D_8008E398[0] &= ~0x10000;
        func_80050FB0(arg0);
        mask = 0x1000;
        ch = D_80089E40;
        n = 1;
        active = D_8008BEB0[0];
        if (arg0[0] != 0) {
            n = arg0[0];
        }
        for (i = 0; i < 12; i++, ch++, mask <<= 1) {
            if ((active & mask) && !(ch->unk28 & 0x2000000)) {
                ch->unkF2 = (s16)((D_80089E08[i] << 8) + 0x80) / n;
                ch->unkF0 = 0;
                ch->unkA0 = n;
            }
        }
    }
}

void func_800512F4(void) {
}

void func_80051F14(s32 *);
void SpuSetReverb(s32);
void SpuSetReverbModeType(s32);
void func_800512FC(s32 arg0) {
    s32 mode;
    func_80051F14(&mode);
    if (mode != arg0) {
        SpuSetReverb(0);
        SpuSetReverbModeType(arg0 | 0x100);
        SpuSetReverb(1);
    }
}

typedef struct { s32 unk0, unk4, unk8, unkC, unk10, unk14; } A8005134C;
typedef struct { u8 pad0[4]; u16 unk4; u8 pad6[2]; u16 unk8; } P8005134C;
extern s32 D_8006B4E0;
extern A8005134C D_8008BDD0;
extern s32 D_8008BEE0[];
extern s32 D_8008E404;
extern void (*D_8006C16C[])(A8005134C *);
int DisableEvent();
int EnableEvent();
s32 func_8004B280();
s32 func_8005134C(u32 cmd) {
    s32 ret = 0;
    P8005134C *p;
    s32 v;
    A8005134C *a;
    s32 *q;
    DisableEvent(D_8006B4E0);
    cmd &= 0xFF;
    a = &D_8008BDD0;
    switch (cmd) {
    case 0x01:
        D_8008E404 ^= 0x100;
        break;
    case 0x10:
    case 0x12:
    case 0x14:
    case 0x19:
    case 0x1A:
        q = D_8008BEE0;
        if (func_8004B280(q[0]) == 0) {
            ret = q[0];
            if (D_8008BE50->unk6E != ((P8005134C *)ret)->unk4 || (D_8008ABF8 != NULL && D_8008ABF8->unk6E != D_8008BE50->unk6E)) {
                if (cmd != 0x19) {
                    func_800512FC(((P8005134C *)ret)->unk8);
                }
                a->unk0 = ret;
                a->unk8 = ((P8005134C *)ret)->unk4;
                switch (cmd) {
                case 0x14:
                    a->unkC = q[1] != 0 ? q[1] | 1 : -1;
                    break;
                case 0x12:
                    a->unkC = q[1];
                    break;
                case 0x19:
                    a->unk10 = q[1];
                    break;
                case 0x1A:
                    a->unk10 = q[1];
                    a->unk14 = q[2];
                    break;
                }
                ret = ((P8005134C *)ret)->unk4;
            } else {
                cmd = 0;
                ret = 0;
            }
        } else {
            cmd = 0;
            ret = -1;
        }
        break;
    case 0xD8:
        a->unk0 = D_8008BEE0[0];
        D_8006C16C[0xD0](a);
        cmd = 0xD4;
        break;
    case 0xD9:
        a->unk0 = D_8008BEE0[0];
        a->unk4 = D_8008BEE0[1];
        D_8006C16C[0xD1](a);
        cmd = 0xD5;
        break;
    case 0xDA:
        a->unk0 = D_8008BEE0[0];
        a->unk4 = D_8008BEE0[1];
        a->unk8 = D_8008BEE0[2];
        D_8006C16C[0xD2](a);
        cmd = 0xD6;
        break;
    case 0x99:
        D_8006C16C[0x9B](a);
        D_8006C16C[0x9D](a);
        cmd = 0x9F;
        break;
    case 0x98:
        D_8006C16C[0x9A](a);
        D_8006C16C[0x9C](a);
        cmd = 0x9E;
        break;
    default:
        a->unk0 = D_8008BEE0[0];
        a->unk4 = D_8008BEE0[1];
        a->unk8 = D_8008BEE0[2];
        a->unkC = D_8008BEE0[3];
        a->unk10 = D_8008BEE0[4];
        a->unk14 = D_8008BEE0[5];
        break;
    }
    D_8006C16C[cmd](a);
    EnableEvent(D_8006B4E0);
    return ret;
}
