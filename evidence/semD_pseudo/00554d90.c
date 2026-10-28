void FUN_00554d90(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x10) + param_3 * 8;
  uVar1 = *(uint *)(param_1 + 0x10) >> 3 & 0x3f;
  *(uint *)(param_1 + 0x10) = uVar2;
  if (uVar2 < param_3 * 8) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar2 = -uVar1 + 0x40;
  if (param_3 < uVar2) {
    uVar2 = 0;
  }
  else {
    FUN_005558a0(uVar1 + 0x18 + param_1,param_2,uVar2);
    FUN_00554eb0(param_1,param_1 + 0x18);
    for (uVar1 = -uVar1 + 0x7f; uVar1 < param_3; uVar1 = uVar1 + 0x40) {
      FUN_00554eb0(param_1,param_2 + -0x3f + uVar1);
      uVar2 = uVar2 + 0x40;
    }
    uVar1 = 0;
  }
  FUN_005558a0(uVar1 + 0x18 + param_1,uVar2 + param_2,param_3 - uVar2);
  return;
}


