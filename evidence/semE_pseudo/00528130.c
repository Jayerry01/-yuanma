undefined1 FUN_00528130(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  uVar1 = FUN_00525980();
  FUN_00525610(uVar1);
  uVar3 = 0;
  iVar2 = DAT_00667a54;
  if (DAT_00667a58 != 0) {
    while (iVar2 != param_1) {
      uVar3 = uVar3 + 1;
      iVar2 = *(int *)(iVar2 + 0x24);
      if (DAT_00667a58 <= uVar3) {
        FUN_00525620(uVar1);
        return 0;
      }
    }
    uVar4 = 1;
  }
  FUN_00525620(uVar1);
  return uVar4;
}


