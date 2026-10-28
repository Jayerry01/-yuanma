void FUN_00405560(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  param_1[0x45] = param_2;
  uVar1 = __ftol();
  param_1[0x46] = uVar1;
  if (((param_1[1] == 6) && (uVar1 = param_1[0x27], uVar1 != 0)) &&
     ((*(byte *)(uVar1 + 4) & 1) != 0)) {
    FUN_00419db0(uVar1,param_2);
  }
  if ((param_1[1] == 8) && (uVar1 = param_1[0x27], uVar1 != 0)) {
    uVar2 = FUN_00419bd0(*(undefined4 *)(uVar1 + 0x14),*(undefined4 *)(uVar1 + 0x18),
                         *(undefined4 *)(uVar1 + 0x1c),param_1[0x45]);
    *(undefined4 *)(param_1[0x27] + 0x20) = uVar2;
  }
  if (param_3 != 0) {
    if (0xfe < (int)param_1[0x46]) {
      FUN_0040afd0();
      FUN_004054e0(*param_1 | 0x2000000,0x13,1);
      return;
    }
    FUN_0040aee0(param_1,0);
    FUN_004054e0(*param_1 | 0x2000000,0x13,0);
    return;
  }
  if (0xfe < (int)param_1[0x46]) {
    FUN_004054e0();
    return;
  }
  FUN_004054e0();
  return;
}


