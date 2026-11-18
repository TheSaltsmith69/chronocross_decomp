#include "common.h"

/* CD command queue: up to 8 libcd commands sent in order by func_8004515C */
typedef struct {
    u8 cmd;      /* CdlSetloc, CdlSeekL, CdlPause ... */
    u8 hasParam;
    u16 flags;   /* 1: restart list on error, 2: treat CdlDataEnd as error,
                    4: restore ready callback, 8: clear ready callback */
    s32 param;   /* copied from the caller's 4-byte parameter */
} CdCmd;

typedef struct CdCmdList {
    u8 unk0;     /* index of the next command to send */
    u8 unk1;     /* nonzero: last list; zero: continue with next */
    u8 count;
    u8 max;
    CdCmd cmds[8];
    struct CdCmdList *next;
} CdCmdList;

typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;

/* one file of a multi-file read: sector position and destination */
typedef struct {
    s32 unk0;
    u8 *unk4;
} Unk80045CCC;

/* ---- declarations ---- */
extern CdCmdList D_80087830;
extern CdCmdList *D_80087978;
extern s32 D_8008787C;
extern s32 D_80087878;
extern s32 D_80087958;
s32 func_80044DD4(void);
s32 func_80044EE0(s32);
void func_80044F6C(CdCmdList *, u8);
s32 func_80044FCC(CdCmdList *, u8, u8 *, u8);
s32 func_800450F8(CdCmdList *);
s32 func_8004515C(CdCmdList *);
s32 func_80044484(s32);
char *func_80044A88(s32);
s32 PCopen(char *, s32, s32);
s32 PClseek(s32, s32, s32);
s32 func_80028614(s32);
s32 func_80044630(s32);
CdlLOC *CdIntToPos(s32, CdlLOC *);
extern s32 D_80087898;
extern s32 D_800878F0;
extern s32 D_80087908;
extern s32 D_80087948;
extern s32 D_8008793C;
void func_800455A0(s32);
s32 CdDataSync(s32);
void func_800455E4(u8, u8 *);
void CdSyncCallback(void *);
void *CdReadyCallback(void *);
extern void *D_8008781C;
extern CdCmdList D_800878A0;
extern s32 D_8006B4B8;
extern s32 D_8006B4BC;
extern s32 D_8006B4CC;
extern s32 D_80087884;
extern s32 D_80087960;
extern s32 D_80087964;
extern s32 D_8008796C;
extern s32 D_80087970;
extern s32 D_800878E8;
void func_800452E4(s32);
s32 func_80046388(Unk80045CCC *);
void func_80045ACC(s32);
void func_80046FB4(u8, u8 *);
void func_80047724(u8, s32);
s32 func_80045E78(s32, s32, s32, s32);
void func_80044B0C(s32);
s32 func_80044924(s32);
s32 CdInit(void);
void CdSetDebug(s32);
s32 VSync(s32);
void func_80028648(void);
extern u16 *D_80087954;
void func_80045CCC(s32, s32, s32, s32);
s32 func_8004600C(s32, s32, s32);
extern s32 D_800878F8;
s32 func_800448C8(s32);
extern s32 D_8008791C;
extern s32 *D_80087828;
extern u8 *D_8008792C;
extern s32 *D_80087880;
extern s32 D_80087940;
extern s32 D_80087938;
extern s32 D_80087900;
extern s32 D_8008789C;
s32 *func_8003D8B4(s32, s32);
extern s32 D_800878F4;
void CdDataCallback(void *);
extern s32 D_8006B4B4;
s32 CdControlF(u8, u8 *);
extern u16 D_80087974;
extern u8 *D_80087950;
extern s32 D_80087810[3];
extern s32 D_80087928;
extern s32 D_80087910;
extern s32 D_800878EC;
extern Unk80045CCC *D_800878FC;
extern s32 D_80087930;
extern s32 D_80087904;
extern CdlLOC D_80087920;
extern u32 D_80087944;


typedef struct {
    s32 unk[10];
} CdConfig;
void func_80043F90(CdConfig *arg0) {
    *(CdConfig *)&D_80087950 = *arg0;
    if (D_80087958 == 0 || D_80087958 == -1) {
        while (CdInit() == 0) {}
        CdSetDebug(0);
        CdDataCallback(0);
        CdSyncCallback(0);
        CdReadyCallback(0);
        D_8008793C = 0;
        CdControlF(7, 0);
        func_80044B0C(0xA0);
        func_80044EE0(0);
        VSync(3);
    } else {
        func_80028648();
    }
    D_80087884 = 0x10;
    D_8008793C = 0;
    D_800878F0 = 0;
    D_800878F4 = 0;
    D_80087828 = 0;
    D_8006B4CC = -1;
    D_80087898 = 0;
    if (D_80087958 == 0) {
        D_80087898 = 1;
        func_80045E78(D_80087960, (s32)D_80087950, D_8008796C, 0);
        func_80044EE0(0);
        func_80045E78(D_80087964, (s32)D_80087954, D_80087970, 0);
        func_80044EE0(0);
    }
    if (D_80087958 == -1) {
        D_80087898 = -1;
        D_80087958 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80044190);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80044304);

typedef struct {
    s32 unk0;
    s32 unk4;
} Unk80044484;
s32 func_80044484(s32 arg0) {
    s32 ret;
    s32 *p2;
    Unk80044484 *p1;
    switch (D_80087974) {
    case 0:
        ret = ((D_80087950 + arg0 * 7)[2] << 16) + ((D_80087950 + arg0 * 7)[1] << 8) + (D_80087950 + arg0 * 7)[0];
        break;
    case 1:
        p1 = (Unk80044484 *)D_80087950;
        ret = p1[arg0].unk0;
        break;
    case 2:
        p2 = (s32 *)D_80087950;
        ret = p2[arg0] & 0x7FFFFF;
        break;
    }
    return ret;
}

s32 func_80044630(s32 arg0) {
    s32 ret;
    s32 unused;
    u32 *p2;
    Unk80044484 *p1;
    switch (D_80087974) {
    case 0:
        ret = ((D_80087950 + arg0 * 7)[6] << 24) + ((D_80087950 + arg0 * 7)[5] << 16) +
              ((D_80087950 + arg0 * 7)[4] << 8) + (D_80087950 + arg0 * 7)[3];
        break;
    case 1:
        p1 = (Unk80044484 *)D_80087950;
        ret = p1[arg0].unk4;
        break;
    case 2:
        p2 = (u32 *)D_80087950;
        if (p2[arg0] & 0x800000) {
            ret = 0;
        } else {
            ret = ((p2[arg0 + 1] & 0x7FFFFF) - (p2[arg0] & 0x7FFFFF)) * 0x800 - ((p2[arg0] >> 24) & 0xFF) * 8;
        }
        break;
    }
    return ret;
}

s32 func_800448C8(s32 arg0) {
    return func_80044484(D_8008787C + arg0);
}

s32 func_80044924(s32 arg0) {
    s32 size;
    s32 fd;
    size = 0;
    if (D_80087958 != 0) {
        fd = PCopen(func_80044A88(arg0), 0, 0);
        if (fd != -1) {
            size = PClseek(fd, 0, 2);
            func_80028614(fd);
        }
    }
    if (size == 0) {
        size = func_80044630(D_8008787C + arg0);
    }
    return size;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80044A08);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80044A88);

void func_80044B0C(s32 arg0) {
    s32 i;
    u8 buf[4];
    for (i = 0; i < 4; i++) {
        buf[i] = 0;
    }
    buf[0] = arg0;
    func_80044EE0(0);
    func_80044F6C(&D_80087830, 1);
    func_80044FCC(&D_80087830, 0xE, buf, 0);
    func_80044FCC(&D_80087830, 9, 0, 0);
    func_800450F8(&D_80087830);
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80044BF8);

void func_80044CD0(s32 arg0) {
    CdlLOC loc;
    func_80044F6C(&D_80087830, 1);
    if (arg0 != 0) {
        CdIntToPos(arg0, &loc);
        func_80044FCC(&D_80087830, 2, (u8 *)&loc, 0);
        func_80044FCC(&D_80087830, 0x15, 0, 1);
    } else {
        func_80044FCC(&D_80087830, 9, 0, 0);
    }
    func_800450F8(&D_80087830);
}

s32 func_80044D9C(void) {
    return D_80087898;
}

s32 func_80044DD4(void) {
    s32 ret;
    ret = D_800878F0;
    if (D_80087908 != 0) {
        if (D_80087948 != 0) {
            D_80087948--;
        } else {
            func_800455A0(0);
        }
    } else {
        D_80087948 = 0;
    }
    if (ret == 0) {
        if (D_80087958 == 0) {
            if (CdDataSync(1) != 0) {
                ret = 1;
            }
        }
        if (D_8008793C != 0) {
            ret = 1;
        }
    }
    return ret;
}

s32 func_80044EE0(s32 arg0) {
    switch (arg0) {
    case 0: {
        while (func_80044DD4() > 0) {}
        break;
    }
    default:
        break;
    }
    return func_80044DD4();
}

void func_80044F6C(CdCmdList *arg0, u8 arg1) {
    arg0->unk0 = 0;
    arg0->unk1 = arg1;
    arg0->count = 0;
    arg0->max = 8;
}

s32 func_80044FCC(CdCmdList *list, u8 cmd, u8 *param, u8 arg3) {
    CdCmd *e;
    if (list->count < list->max) {
        e = &list->cmds[list->count];
        e->cmd = cmd;
        e->flags = arg3;
        if (param != 0) {
            e->hasParam = 1;
            e->param = *(s32 *)param;
        } else {
            e->hasParam = 0;
        }
        list->count++;
        return 0;
    } else {
        return -1;
    }
}

s32 func_800450F8(CdCmdList *arg0) {
    CdSyncCallback(func_800455E4);
    D_80087978 = arg0;
    return func_8004515C(arg0);
}

s32 func_8004515C(CdCmdList *list) {
    if (list->unk0 < list->count) {
        D_8008793C = 1;
        D_8006B4B4++;
        list->unk0++;
        if (list->cmds[list->unk0 - 1].hasParam != 0) {
            CdControlF(list->cmds[list->unk0 - 1].cmd, (u8 *)&list->cmds[list->unk0 - 1].param);
        } else {
            CdControlF(list->cmds[list->unk0 - 1].cmd, 0);
        }
        return 0;
    } else {
        return -1;
    }
}

void func_800452E4(s32 arg0) {
    D_80087908 = 1;
    if (D_80087978->cmds[D_80087978->unk0 - 1].flags & 1) {
        D_80087978->unk0 = 0;
    } else if (D_80087978->unk0 != 0) {
        D_80087978->unk0--;
    }
    if (arg0 != 0) {
        D_800878A0.next = D_80087978;
        D_80087978 = &D_800878A0;
        func_80044F6C(D_80087978, 0);
        switch (arg0) {
        case 1:
            func_80044FCC(D_80087978, 1, 0, 2);
            func_80044FCC(D_80087978, 0x13, 0, 1);
            break;
        case 2:
            D_8008781C = CdReadyCallback(0);
            func_80044FCC(D_80087978, 1, 0, 2);
            func_80044FCC(D_80087978, 0x13, 0, 1);
            func_80044FCC(D_80087978, 9, 0, 5);
            break;
        case 3:
            D_8008781C = CdReadyCallback(0);
            func_80044FCC(D_80087978, 1, 0, 2);
            func_80044FCC(D_80087978, 0x13, 0, 1);
            func_80044FCC(D_80087978, 9, 0, 1);
            func_80044FCC(D_80087978, 8, 0, 1);
            func_80044FCC(D_80087978, 9, 0, 5);
            break;
        }
    }
}

void func_800455A0(s32 arg0) {
    D_80087908 = 0;
    func_8004515C(D_80087978);
}

void func_800455E4(u8 arg0, u8 *arg1) {
    s32 err;
    err = 0;
    if (arg0 != 2) {
        err = 1;
    }
    if ((*arg1 & 0x10) && (D_80087978->cmds[D_80087978->unk0 - 1].flags & 2)) {
        err = 1;
    }
    if (err) {
        D_8006B4B8++;
        if (D_80087978->cmds[D_80087978->unk0 - 1].flags & 8) {
            D_8008781C = CdReadyCallback(0);
        }
        func_800452E4(D_80087978->unk1);
    } else {
        D_8006B4BC++;
        if (D_80087978->cmds[D_80087978->unk0 - 1].flags & 4) {
            CdReadyCallback(D_8008781C);
        }
        if (func_8004515C(D_80087978) != 0) {
            if (D_80087978->unk1 != 0) {
                CdSyncCallback(0);
                D_8008793C = 0;
            } else {
                D_80087978 = D_80087978->next;
                func_8004515C(D_80087978);
            }
        }
    }
}

s32 func_8004582C(s32 arg0) {
    if (1) {
        D_8008787C = D_80087954[arg0];
        D_80087878 = arg0;
    } else {
        D_8008787C = 0;
        return -1;
    }
    return D_8008787C;
}

s32 func_800458BC(void) {
    return D_80087878;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_800458F4);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_800459D0);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80045ACC);

void func_80045CCC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    for (i = 0; i < 3; i++) {
        D_80087810[i] = 0;
    }
    D_80087908 = 0;
    D_80087948 = 0;
    D_80087928 = 0;
    D_80087910 = 0;
    D_800878EC = 0;
    D_800878FC = (Unk80045CCC *)arg3;
    if (arg3 != 0) {
        D_80087930 = D_800878FC[D_800878EC].unk0;
        D_8008792C = D_800878FC[D_800878EC].unk4;
        D_80087904 = func_800448C8(D_80087930);
        D_800878F4 = func_80044924(D_80087930);
    } else {
        D_8008792C = (u8 *)arg2;
        D_80087904 = arg0;
        D_800878F4 = arg1;
    }
    CdIntToPos(D_80087904, &D_80087920);
    D_80087944 = 0;
}

s32 func_80045E78(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_80087958 != 0) {
        return;
    }
    func_80044EE0(0);
    func_80045CCC(arg0, arg2, arg1, 0);
    return func_8004600C(0, arg1, arg3);
}

s32 func_80045F14(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 < 0 || func_80044924(arg0) <= 0 || arg1 == 0) {
        return -3;
    }
    func_80044EE0(0);
    D_800878F8 = D_8008787C;
    func_80045CCC(func_800448C8(arg0), func_80044924(arg0), arg1, 0);
    return func_8004600C(arg0, arg1, arg2);
}

extern s16 D_80087924;
void func_800459D0(s32, s32, s32, s32);
s32 *func_80047760(s32 *);
s32 func_80047844(void);
void func_800475C8(u8, s32);
void func_80046BC4(u8, u8 *);
void func_800468AC(u8, u8 *);
s32 func_8004600C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    D_800878E8 = arg2;
    D_80087930 = arg0;
    D_800878F0 = 1;
    if (arg2 & 0x100) {
        func_80047760((s32 *)arg1);
        func_80047844();
        if (D_80087958 != 0) {
            for (i = 0; i < 4; i++) {
                D_8006B4CC = PCopen(func_80044A88(arg0), 0, 0);
                if (D_8006B4CC != -1) {
                    break;
                }
                func_800459D0(i, 0xFF, 0, 0);
            }
            return 0;
        }
        CdDataCallback(func_800475C8);
        CdReadyCallback(func_80046BC4);
        func_80044F6C(&D_80087830, 2);
        func_80044FCC(&D_80087830, 2, (u8 *)&D_80087920, 0);
        func_80044FCC(&D_80087830, 6, 0, 1);
        func_800450F8(&D_80087830);
        return 0;
    }
    if (arg2 & 0x200) {
        D_800878E8 = (arg2 & 0xFDFF) | 0xA0;
        D_80087924 = 0;
        func_80047760((s32 *)arg1);
        func_80047844();
        if (D_80087958 != 0) {
            for (i = 0; i < 4; i++) {
                D_8006B4CC = PCopen(func_80044A88(arg0), 0, 0);
                if (D_8006B4CC != -1) {
                    break;
                }
                func_800459D0(i, 0xFF, 0, 0);
            }
            return 0;
        }
        return 0;
    }
    if (D_80087958 != 0) {
        func_80045ACC(arg0);
        return 0;
    }
    CdDataCallback(0);
    CdReadyCallback(func_800468AC);
    func_80044F6C(&D_80087830, 2);
    func_80044FCC(&D_80087830, 2, (u8 *)&D_80087920, 0);
    func_80044FCC(&D_80087830, 6, 0, 1);
    func_800450F8(&D_80087830);
    return 0;
}

s32 func_80046388(Unk80045CCC *arg0) {
    s32 i;
    s32 j;
    s32 min;
    s32 n;
    u32 minval;
    u8 *tmp;
    if (arg0 == 0) {
        return 0;
    }
    n = 0;
    while (arg0[n].unk4 != 0) {
        n++;
    }
    if (n == 0) {
        return 0;
    }
    i = 0;
    while (i < n - 1) {
        minval = arg0[i].unk0;
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arg0[j].unk0 < minval) {
                min = j;
                minval = arg0[j].unk0;
            }
        }
        minval = arg0[i].unk0;
        tmp = arg0[i].unk4;
        arg0[i].unk0 = arg0[min].unk0;
        arg0[i].unk4 = arg0[min].unk4;
        arg0[min].unk0 = minval;
        arg0[min].unk4 = tmp;
        i++;
    }
    return n;
}

s32 func_80046698(Unk80045CCC *arg0, s32 arg1) {
    s32 n;
    s32 i;
    s32 pos;
    n = func_80046388(arg0);
    if (n == 0) {
        return -3;
    }
    func_80044EE0(0);
    D_800878F8 = D_8008787C;
    func_80045CCC(0, 0, 0, (s32)arg0);
    D_800878E8 = arg1;
    D_800878F0 = n;
    D_8008791C = n;
    if (D_80087958 != 0) {
        for (i = 0; i < n; i++) {
            pos = D_800878FC[i].unk0;
            D_8008792C = D_800878FC[i].unk4;
            D_800878F4 = func_80044924(pos);
            func_80045ACC(pos);
        }
        return 0;
    }
    CdDataCallback(func_80047724);
    CdReadyCallback(func_80046FB4);
    func_80044F6C(&D_80087830, 2);
    func_80044FCC(&D_80087830, 2, (u8 *)&D_80087920, 0);
    func_80044FCC(&D_80087830, 6, 0, 1);
    func_800450F8(&D_80087830);
    return 0;
}

extern s32 D_8006B4C0;
extern s32 D_8006B4C4;
extern s32 D_8006B4C8;
extern u8 D_80087010[];
void CdGetSector(void *, s32);
s32 CdPosToInt(CdlLOC *);
void func_80044CD0(s32);
void func_800468AC(u8 arg0, u8 *arg1) {
    D_8006B4C0++;
    if (arg0 == 1) {
        if (D_80087928 != 0) {
            goto done;
        }
        if (D_800878F4 >= 0x800) {
            CdGetSector(D_80087810, 3);
            CdGetSector(D_8008792C, 0x200);
        } else if (D_800878F4 > 0) {
            CdGetSector(D_80087810, 3);
            CdGetSector(D_8008792C, (D_800878F4 + 3) / 4);
            CdGetSector(D_80087010, 0x200 - (D_800878F4 + 3) / 4);
        }
        if (CdPosToInt((CdlLOC *)D_80087810) != D_80087904) {
            D_8006B4C8++;
            goto retry;
        }
        D_8006B4C4++;
        D_8008792C += 0x800;
        D_800878F4 -= 0x800;
        D_80087904++;
        if (D_800878F4 <= 0) {
        done:
            CdReadyCallback(0);
            D_800878F4 = 0;
            func_80044CD0(0);
            D_800878F0 = 0;
            return;
        }
    } else {
    retry:
        D_80087944++;
        D_80087978->unk0 = 1;
        CdIntToPos(D_80087904, &D_80087920);
        D_80087978->cmds[0].param = *(s32 *)&D_80087920;
        CdSyncCallback(func_800455E4);
        if (D_80087944 < 4) {
            func_800452E4(D_80087978->unk1);
        } else {
            D_80087948 = 0x1E;
            D_80087944 = 0;
            func_800452E4(3);
        }
    }
}

void func_80046BC4(u8 arg0, u8 *arg1) {
    s32 i;
    u16 *ent;
    s32 idx;
    D_8006B4C0++;
    if (arg0 == 1) {
        if (D_80087928 != 0) {
            CdReadyCallback(0);
            CdDataCallback(0);
            D_800878F4 = 0;
            func_80044CD0(0);
            D_800878F0 = 0;
            return;
        }
        if (D_800878F4 > 0) {
            for (i = 0; i < (u32)D_80087940; i++) {
                ent = (u16 *)(D_80087880 + D_800878EC * 2);
                idx = D_800878EC;
                D_800878EC++;
                if (D_800878EC >= (u32)D_80087940) {
                    D_800878EC = 0;
                }
                if (ent[0] == 0) {
                    break;
                }
            }
            if (ent[0] == 0) {
                CdGetSector(D_80087810, 3);
                if (CdPosToInt((CdlLOC *)D_80087810) != D_80087904) {
                    D_8006B4C8++;
                    CdGetSector(D_80087010, 0x200);
                    goto retry;
                }
                D_800878F4 -= 0x800;
                ent[1] = D_80087938;
                ent[0] = 1;
                D_80087938++;
                CdGetSector(D_8008792C + idx * 0x800, 0x200);
                D_8006B4C4++;
                D_80087904++;
            } else {
                goto retry;
            }
        }
        if (D_800878F4 <= 0) {
            CdReadyCallback(0);
            D_800878F4 = 0;
            func_80044CD0(0);
            return;
        }
    } else {
        D_80087944++;
    retry:
        D_80087978->unk0 = 1;
        CdIntToPos(D_80087904, &D_80087920);
        D_80087978->cmds[0].param = *(s32 *)&D_80087920;
        CdSyncCallback(func_800455E4);
        if (D_80087944 < 4) {
            func_800452E4(D_80087978->unk1);
        } else {
            D_80087948 = 0x1E;
            D_80087944 = 0;
            func_800452E4(3);
        }
    }
}

void func_80046FB4(u8 arg0, u8 *arg1) {
    s32 pos;
    u32 start;
    D_8006B4C0++;
    if (arg0 == 1) {
        if (D_80087928 != 0) {
            CdReadyCallback(0);
            CdDataCallback(0);
            D_800878F4 = 0;
            func_80044CD0(0);
            D_8008791C = 0;
            D_800878F0 = 0;
            return;
        }
        if (D_80087910 == 0) {
            if (D_800878F4 >= 0x800) {
                CdGetSector(D_80087810, 3);
                CdGetSector(D_8008792C, 0x200);
            } else if (D_800878F4 > 0) {
                CdGetSector(D_80087810, 3);
                CdGetSector(D_8008792C, (D_800878F4 + 3) / 4);
                CdGetSector(D_80087010, 0x200 - (D_800878F4 + 3) / 4);
            }
            if (CdPosToInt((CdlLOC *)D_80087810) != D_80087904) {
                D_8006B4C8++;
                goto retry;
            }
        }
        D_8006B4C4++;
        D_8008792C += 0x800;
        D_800878F4 -= 0x800;
        D_80087904++;
        if (D_800878F4 <= 0) {
            D_800878EC++;
            pos = D_800878FC[D_800878EC].unk0;
            D_8008792C = D_800878FC[D_800878EC].unk4;
            if (pos >= 0 && D_8008792C != 0) {
                start = func_80044484(D_800878F8 + pos);
                D_800878F4 = func_80044630(D_800878F8 + pos);
                if (start > D_80087904 && D_80087904 + D_80087884 >= start) {
                    D_80087910 = 1;
                    D_800878F4 = (D_80087904 - start) * 0x800;
                    D_800878EC--;
                } else if (start == D_80087904) {
                    D_80087910 = 0;
                    D_8008791C--;
                } else {
                    D_80087910 = 0;
                    D_80087904 = start;
                    CdIntToPos(D_80087904, &D_80087920);
                    D_8008781C = CdReadyCallback(0);
                    CdSyncCallback(func_800455E4);
                    func_80044F6C(&D_80087830, 2);
                    func_80044FCC(&D_80087830, 9, 0, 5);
                    func_80044FCC(&D_80087830, 2, (u8 *)&D_80087920, 0);
                    func_80044FCC(&D_80087830, 6, 0, 1);
                    func_800450F8(&D_80087830);
                    D_8008791C--;
                }
            } else {
                D_800878F4 = 0;
                CdReadyCallback(0);
                func_80044CD0(0);
                D_8008791C = 0;
                D_800878F0 = 0;
            }
        }
    } else {
    retry:
        D_80087944++;
        D_80087978->unk0 = 1;
        CdIntToPos(D_80087904, &D_80087920);
        D_80087978->cmds[0].param = *(s32 *)&D_80087920;
        CdSyncCallback(func_800455E4);
        if (D_80087944 < 4) {
            func_800452E4(D_80087978->unk1);
        } else {
            D_80087948 = 0x1E;
            D_80087944 = 0;
            func_800452E4(3);
        }
    }
}

void func_800475C8(u8 arg0, s32 arg1) {
    s16 i;
    u16 *p;
    s32 unused;
    p = (u16 *)D_80087880;
    for (i = 0; i < (u32)D_80087940; i++) {
        if (p[0] == 1 && p[1] == D_80087900) {
            break;
        }
        p += 4;
    }
    if (i == D_80087940) {
        return;
    }
    D_80087900++;
    p[0] = 3;
    if (D_800878F4 <= 0 && D_800878F0 < 2) {
        CdDataCallback(0);
        D_800878F0 = 0;
    }
}

void func_80047724(u8 arg0, s32 arg1) {
    D_800878F0 = D_8008791C;
}

s32 *func_80047760(s32 *arg0) {
    s32 n;
    s32 *p;
    D_80087828 = arg0;
    p = D_80087828;
    n = *p;
    if (n == 0) {
        return 0;
    }
    D_8008792C = (u8 *)p + n * 8 + 0x24;
    D_80087880 = p + 1;
    D_80087940 = n;
    D_80087938 = 0;
    D_80087900 = 0;
    D_8008789C = 0;
    return p;
}

s32 func_80047844(void) {
    s32 i;
    s32 n;
    s32 *p;
    u16 *ent;
    if (D_80087828 == 0) {
        return -1;
    }
    p = D_80087828;
    n = *p;
    ent = (u16 *)(p + 1);
    for (i = 0; i < n; i++) {
        ent[i * 4] = 0;
        ent[i * 4 + 1] = 0;
        ent[i * 4 + 2] = 0;
        ent[i * 4 + 3] = 0;
    }
    ent[2] = n;
    return n;
}

s32 PCread(s32, u8 *, s32);
u8 *func_800479AC(void) {
    s32 i;
    s32 ret;
    s32 n;
    s32 *p;
    u8 *data;
    u16 *ent;
    s32 idx;
    if (D_80087828 == 0) {
        return 0;
    }
    p = D_80087828;
    n = *p;
    data = (u8 *)p + n * 8 + 0x24;
    ent = (u16 *)(p + 1);
    if (D_80087958 != 0) {
        if (D_8006B4CC != -1 && D_800878F0 > 0) {
            for (i = 0; i < (u32)D_80087940; i++) {
                ent = (u16 *)(D_80087880 + D_800878EC * 2);
                idx = D_800878EC;
                D_800878EC++;
                if (D_800878EC >= (u32)D_80087940) {
                    D_800878EC = 0;
                }
                if (ent[0] == 0) {
                    break;
                }
            }
            if (ent[0] != 0) {
                return 0;
            }
            ent[0] = 3;
            data += idx * 0x800;
            for (i = 0; i < 4; i++) {
                ret = PCread(D_8006B4CC, data, 0x800);
                if (ret != 0) {
                    break;
                }
                func_800459D0(i, 0, 0xFF, 0);
            }
            D_800878F4 -= 0x800;
            if (D_800878F4 <= 0) {
                D_800878F4 = 0;
                for (i = 0; i < 4; i++) {
                    ret = func_80028614(D_8006B4CC);
                    if (ret == 0) {
                        break;
                    }
                    func_800459D0(i, 0, 0, 0xFF);
                }
                D_8006B4CC = -1;
                D_800878F0 = 0;
            }
            return data;
        } else {
            return 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            if (ent[0] == 3 && ent[1] == D_8008789C) {
                break;
            }
            ent += 4;
        }
        if (i == n) {
            return 0;
        }
    }
    D_8008789C++;
    return data + i * 0x800;
}

u16 func_80047E18(u8 *arg0) {
    u32 idx;
    s32 n;
    s32 *p;
    u8 *data;
    u16 *ent;
    u16 ret;
    if (D_80087828 == 0) {
        return 0;
    }
    if (arg0 == 0) {
        return 0;
    }
    p = D_80087828;
    n = *p;
    data = (u8 *)p + n * 8 + 0x24;
    ent = (u16 *)(p + 1);
    idx = (u32)(arg0 - data) >> 11;
    ret = ent[idx * 4];
    ent[idx * 4] = 0;
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80047F44);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_8004803C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80048140);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_800489A8);

s32 *func_80048B44(s32 arg0, s32 arg1) {
    s32 *temp;
    if (arg0 <= 0) {
        return 0;
    }
    temp = func_8003D8B4(arg0 * 0x808 + 0x24, arg1);
    if (temp == 0) {
        return 0;
    }
    *temp = arg0;
    return temp;
}

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80048C00);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80048E6C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_8004928C);

INCLUDE_ASM("asm/nonmatchings/game/unk_80043F90", func_80049960);
