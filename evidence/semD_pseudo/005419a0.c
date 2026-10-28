uint FUN_005419a0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  if (param_3 < param_5) {
    cVar2 = FUN_00541880(param_1,param_2,param_3,param_5);
    if (cVar2 == '\0') {
      return 0xffffffff;
    }
    param_2 = *(int *)(param_1 + 8);
    param_3 = *(int *)(param_1 + 0xc);
  }
  param_3 = param_3 - param_5;
  uVar3 = param_2 >> ((byte)param_3 & 0x1f) & (1 << ((byte)param_5 & 0x1f)) - 1U;
  if (*(int *)(param_4 + param_5 * 4) < (int)uVar3) {
    do {
      if (param_3 < 1) {
        cVar2 = FUN_00541880(param_1,param_2,param_3,1);
        if (cVar2 == '\0') {
          return 0xffffffff;
        }
        param_2 = *(int *)(param_1 + 8);
        param_3 = *(int *)(param_1 + 0xc);
      }
      param_3 = param_3 + -1;
      uVar3 = uVar3 * 2 | param_2 >> ((byte)param_3 & 0x1f) & 1U;
      iVar1 = param_5 * 4;
      param_5 = param_5 + 1;
    } while (*(int *)(param_4 + 4 + iVar1) < (int)uVar3);
  }
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 0xc) = param_3;
  if (0x10 < param_5) {
    *(undefined4 *)(**(int **)(param_1 + 0x10) + 0x14) = 0x76;
    (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0xffffffff);
    return 0;
  }
  return (uint)*(byte *)(*(int *)(param_4 + 0x48 + param_5 * 4) + *(int *)(param_4 + 0x8c) + 0x11 +
                        uVar3);
}


