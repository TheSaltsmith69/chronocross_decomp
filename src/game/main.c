#include "common.h"

void func_80019FE4(void);
void func_800221E0(void);
void func_8001A0E0(u8 *, u8 *, s32);
void func_8001BF6C(s32, s32, s32);

INCLUDE_ASM("asm/nonmatchings/game/main", main);

void func_8001A994(void) {
    func_80019FE4();
    func_800221E0();
}

extern u8 D_800623EC[];
extern u8 D_800A3AA8[];
extern u8 D_8006CE20[];
extern u8 D_800A343C[];
void func_8001A9BC(void) {
    func_8001A0E0(D_800623EC, D_800A3AA8, 3);
    func_8001A0E0(D_8006CE20, D_800A343C, 5);
}

extern s32 D_8007252C;
void func_8001AA04(s32 arg0) {
    D_8007252C = arg0 + 1;
}

extern u8 D_8006B43E;
extern s32 D_8007257C;
extern s32 D_800724DC;
extern u8 D_800724D9;
void func_8001AA14(s32 arg0) {
    D_8006B43E = 0;
    D_800724DC = D_8007257C;
    D_8007257C = 1;
    func_8001BF6C(arg0, 0, 0);
    D_800724D9 = 1;
}

extern s32 D_8007E6E8;
extern u8 D_8006417C;
extern s16 D_80070EDA;
extern u16 D_8007E7AA;
void func_8004A518(s32);
void func_8001AA64(void) {
    func_8004A518(1);
    D_8006B43E = 1;
    D_800724D9 = 0;
    D_8007E6E8 = 0x216;
    D_8006417C = 0;
    D_80070EDA = 0;
    D_8007E7AA = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AAB8);

void func_8001AB08(s32 arg0) {
    s32 var;
    if (!(D_8007E7AA & 0x10)) {
        var = 0x17;
        if (arg0 == 0) {
            var = 0x16;
        }
        func_8001AA14(var);
        D_800724D9 = 0;
    }
}

s32 func_8001B8B0(s32);
s32 func_8001AB50(void) {
    if (D_8007E7AA & 0x10) {
        return 1;
    }
    if (func_8001B8B0(0) != 0) {
        return 0;
    }
    D_8007257C = D_800724DC;
    return 1;
}

extern u8 D_800623F8[];
extern u8 D_80062400[];
extern u8 D_800AAA20[];
void func_8001ABA4(void) {
    func_8001A0E0(D_800623F8, D_800AAA20, 2);
    func_8001A0E0(D_80062400, D_800AAA20, 10);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001ABF0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001AD30);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B058);

extern u16 D_8007E69E;
void func_8001B0F8(s32 arg0) {
    D_8006B43E = 0;
    D_8007E69E |= 1 << arg0;
}

void func_8001B11C(s32 arg0) {
    D_8007E69E &= ~(1 << arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B13C);

void func_8001B4FC(void) {
}

void func_8001B504(void) {
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Unk80072500;
extern Unk80072500 D_80072500[];
void func_8001B50C(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        D_80072500[i].unk0 = -1;
        D_80072500[i].unk4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B53C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B5A0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B638);

void func_8004582C(s32);
s32 func_8003D9E0(void);
s32 func_80044924(s32);
s32 func_8001B788(s32 arg0) {
    s32 temp;
    func_8004582C(10);
    temp = func_8003D9E0();
    return func_80044924(arg0 * 2 + 3) + 0xE100 >= temp;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B7D4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B848);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001B8B0);

extern s32 D_80076688;
void func_8001BF94(s32, s32, s32);
void func_8001BF48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_80076688 = arg3;
    func_8001BF94(arg0, arg1, arg2);
}

void func_8001BF6C(s32 arg0, s32 arg1, s32 arg2) {
    D_80076688 = 0x7F;
    func_8001BF94(arg0, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001BF94);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C09C);

extern u8 D_80062444[];
extern u8 D_80062468[];
void func_80019550();
void func_80019510();
void func_8001C0E4(void) {
    func_8001A0E0(D_80062444, (u8 *)func_80019550, 9);
    func_8001A0E0(D_80062468, (u8 *)func_80019510, 8);
}

void InitCARD(s32);
void func_800190E4(void);
void func_80018D34(void);
void ChangeClearPAD(s32);
void func_8001C12C(void) {
    InitCARD(0);
    func_800190E4();
    func_80018D34();
    ChangeClearPAD(0);
}

void func_8001C164(void) {
    ChangeClearPAD(0);
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C184);

void func_8001C244(u8 *arg0, u8 *arg1, u8 *arg2) {
    arg0[0] = (arg1[0] * arg2[0]) >> 7;
    arg0[1] = (arg1[1] * arg2[1]) >> 7;
    arg0[2] = (arg1[2] * arg2[2]) >> 7;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C29C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C31C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C388);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C4A0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001C918);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001CF00);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001D558);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001DCC4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001E55C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001EA4C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001EFA8);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001F274);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8001F958);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800201C4);

extern s32 D_80064198;
void func_80020478(void) {
    D_80064198 = 1;
}

void func_80020488(void) {
    D_80064198 = 0;
}

extern s32 D_8007E89C;
extern s32 D_8007E894;
extern s32 D_8006419C;
void func_80020494(s32 arg0, s32 arg1) {
    D_8007E89C = arg0;
    D_8007E894 = arg1;
    D_8006419C = 1;
}

void func_800204B4(void) {
    D_8006419C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_800204C0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800205B0);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8002096C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020D30);

extern u8 D_8006B479;
void func_80021518(void);
void func_80020EDC(void);
void func_80020E94(void) {
    if (D_8006B479 == 0 || D_8006B479 == 2) {
        func_80021518();
    } else {
        func_80020EDC();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80020EDC);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021518);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021B54);

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    s32 unk18;
} Unk8007E8A8;
extern Unk8007E8A8 D_8007E8A8[];
void func_80021C0C(s32 arg0) {
    if (arg0 < 3) {
        D_8007E8A8[arg0].unk14 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021C38);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80021E9C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022128);

extern s32 D_80071C78;
extern s32 D_8007E7A4;
extern s32 D_800641A4;
extern s32 D_800641A8;
extern s32 D_800641AC;
extern s32 D_800641B0;
extern s32 D_800641C4;
extern s32 D_8006B488;
void func_800221E0(void) {
    D_80071C78 = 2;
    D_8007E7A4 = 0;
    D_800641A4 = 0x76543201;
    D_800641A8 = 0x76543201;
    D_800641AC = 0x3210;
    D_800641B0 = 0x3210;
    D_800641C4 = 1;
    D_8006B488 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022238);

INCLUDE_ASM("asm/nonmatchings/game/main", func_8002232C);

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022474);

void func_80022508(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/main", func_80022510);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800225A4);

INCLUDE_ASM("asm/nonmatchings/game/main", func_800225BC);
