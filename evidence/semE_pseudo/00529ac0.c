void FUN_00529ac0(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    FUN_005255b0(0xa003);
    return;
  }
  iVar1 = FUN_00525980();
  FUN_00525610(iVar1);
  if (param_1 != 0x100a) {
    FUN_005255b0(0xa004);
    FUN_00525620(iVar1);
    return;
  }
  *param_2 = *(undefined4 *)(iVar1 + 0x30);
  FUN_00525620(iVar1);
  return;
}


