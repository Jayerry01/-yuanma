void FUN_0042a440(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x4c);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x54);
      if (iVar2 == param_1) {
        *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
      }
      else {
        for (iVar1 = *(int *)(iVar2 + 0x50); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {
          if (iVar1 == param_1) {
            *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(param_1 + 0x50);
            break;
          }
          iVar2 = iVar1;
        }
      }
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x54);
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x50);
      *(undefined4 *)(iVar1 + 0x4c) = 0;
      *(int *)(iVar1 + 0x50) = 0;
      iVar1 = iVar2;
    }
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return;
}


