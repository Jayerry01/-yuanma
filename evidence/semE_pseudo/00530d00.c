void FUN_00530d00(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_005cfe50 = DAT_005cfe50 + 1;
  if (0x1f < DAT_005cfe50) {
    puVar2 = &DAT_007dcb04;
    puVar3 = &DAT_007dcb00;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_005cfe50 = 0x1f;
    DAT_007dcb7c = param_1;
    return;
  }
  (&DAT_007dcb00)[DAT_005cfe50] = param_1;
  return;
}


