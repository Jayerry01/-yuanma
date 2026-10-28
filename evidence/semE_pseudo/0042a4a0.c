void FUN_0042a4a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x4c), iVar1 != 0)) {
    iVar3 = *(int *)(iVar1 + 0x54);
    if (iVar3 == param_1) {
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x4c) = 0;
      return;
    }
    iVar1 = *(int *)(iVar3 + 0x50);
    if (*(int *)(iVar3 + 0x50) != 0) {
      while (iVar2 = iVar1, iVar2 != param_1) {
        iVar1 = *(int *)(iVar2 + 0x50);
        iVar3 = iVar2;
        if (*(int *)(iVar2 + 0x50) == 0) {
          *(undefined4 *)(param_1 + 0x50) = 0;
          *(undefined4 *)(param_1 + 0x4c) = 0;
          return;
        }
      }
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_1 + 0x50);
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  return;
}


