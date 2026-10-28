undefined4 FUN_005259a0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = FUN_005255e0(param_1);
  if (cVar2 != '\0') {
    FUN_00525610(param_1);
    uVar1 = *(undefined4 *)(param_1 + 0x60);
    FUN_00525620(param_1);
    return uVar1;
  }
  FUN_00525630(0xa002);
  return 0;
}


