#include "common.h"

extern s32 D_8006EBC8;
s32 func_801EE000(s32 arg0)
{
  u8 *new_var4;
  int new_var3;
  int new_var;
  s32 var_v0;
  new_var = 0;
  new_var3 = 0x1F;
  var_v0 = new_var;
  new_var4 = &D_8006EBC8;
  new_var4 = ((u8 *) (((arg0 >> 5) * 4) + new_var4)) + 0x3794;
  new_var = (*((s32 *) new_var4)) & (1 << (arg0 & new_var3));
  if (new_var) {
    var_v0 = -1;
    return var_v0;
  }
  if (new_var || var_v0) {
  } else {
    return var_v0;
  }
}

extern s32 D_8006EBC8;
s32 func_801EE03C(s32 arg0)
{
    register s32 reg_a1 asm("a1");
    register s32 reg_v1 asm("v1");
    s32 mask;
    s32 val;

    reg_v1 = (s32)&D_8006EBC8;
    reg_a1 = ((arg0 >> 5) * 4) + reg_v1;
    mask = 1 << (arg0 & 0x1F);
    val = *(s32 *)(reg_a1 + 0x379C);
    if (!(val & mask)) {
        return 0;
    }
    return -1;
}

s32 func_800A5490(s32, s32);
s32 func_800D6C94(s32, s32, s32, s32, s32);
void func_801EE078(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 p;

    func_800D6C94(arg1, arg2, 0x20, 0x40, arg0 + 0x220);
    p = arg0 + 0x14;
    func_800A5490(p, 0x100);
    func_800D6C94(arg3, arg4, 0x100, 1, p);
}

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801EE0F4);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801EE460);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801EE694);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801EEB1C);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801EED54);

extern s32 D_8007E6C0;
s32 func_801EF31C(unsigned int arg0)
{
  int new_var;
  s32 *var_v1;
  s32 var_a1;
  var_a1 = 0;
  new_var = 4;
  var_v1 = &D_8007E6C0;
  loop_1:
  var_a1 += (new_var = 1);
  if ((*var_v1) == arg0) {
    return -new_var;
  }
  if (arg0) {
    var_v1 += new_var;
  } else {
    var_v1 += new_var;
  }
  if (var_a1 >= 3) {
    return 0;
  }
  goto loop_1;
}

extern u8 D_801F510C;
extern s32 D_801F5138;
s32 func_801EF354(s32 arg0) {
    s32 i;

    for (i = 0; i < D_801F5138; i++) {
        if ((&D_801F510C)[i] == arg0) {
            return i;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801EF3A4);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801F0330);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801F0604);

INCLUDE_ASM("asm/ov_party/nonmatchings/party_801EE000", func_801F0CD8);
