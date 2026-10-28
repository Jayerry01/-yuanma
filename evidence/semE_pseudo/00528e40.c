undefined1 FUN_00528e40(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  iVar1 = FUN_00525980();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00525610(iVar1);
  iVar2 = *(int *)(iVar1 + 0x38);
  uVar3 = 0;
  if (*(uint *)(iVar1 + 0x3c) != 0) {
    while (iVar2 != param_1) {
      iVar2 = *(int *)(iVar2 + 0xe64);
      uVar3 = uVar3 + 1;
      if (*(uint *)(iVar1 + 0x3c) <= uVar3) {
        FUN_00525620(iVar1);
        return 0;
      }
    }
    uVar4 = 1;
  }
  FUN_00525620(iVar1);
  return uVar4;
}


