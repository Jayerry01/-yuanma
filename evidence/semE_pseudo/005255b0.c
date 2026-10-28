void FUN_005255b0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00525980();
  if (iVar1 != 0) {
    FUN_00525610(iVar1);
    *(undefined4 *)(iVar1 + 0x40) = param_1;
    FUN_00525620(iVar1);
  }
  return;
}


