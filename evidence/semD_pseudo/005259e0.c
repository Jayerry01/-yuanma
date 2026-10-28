undefined4 FUN_005259e0(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_005255e0(param_1);
  if ((cVar1 == '\0') && (param_1 != 0)) {
    FUN_00525630(0xa002);
    return 0;
  }
  iVar2 = FUN_00525980();
  if (iVar2 != 0) {
    FUN_00525610(iVar2);
    *(undefined1 *)(iVar2 + 0x44) = 0;
    FUN_00525620(iVar2);
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x60) != 0)) {
    FUN_00525610(param_1);
    *(undefined1 *)(param_1 + 0x44) = 1;
    FUN_00525620(param_1);
  }
  return 1;
}


