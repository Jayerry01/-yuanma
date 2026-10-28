void FUN_0042a500(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (FUN_0042a4a0(param_1), param_2 != 0)) {
    *(int *)(param_1 + 0x4c) = param_2;
    iVar1 = *(int *)(param_2 + 0x54);
    if (iVar1 == 0) {
      *(int *)(param_2 + 0x54) = param_1;
      *(undefined4 *)(param_1 + 0x50) = 0;
      return;
    }
    for (iVar2 = *(int *)(iVar1 + 0x50); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x50)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x50) = param_1;
  }
  return;
}


