undefined4 FUN_00525570(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_00525980();
  if (iVar2 == 0) {
    return 0xa004;
  }
  FUN_00525610(iVar2);
  uVar1 = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(iVar2 + 0x40) = 0;
  FUN_00525620(iVar2);
  return uVar1;
}


