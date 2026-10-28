void FUN_0052aae0(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00525980();
  FUN_00525610(iVar1);
  if (param_2 == (float *)0x0) {
    FUN_005255b0(0xa003);
    FUN_00525620(iVar1);
    return;
  }
  *param_2 = 0.0;
  if (param_1 == 0xc000) {
    *param_2 = *(float *)(iVar1 + 0x58);
    FUN_00525620(iVar1);
    return;
  }
  if (param_1 == 0xc001) {
    *param_2 = *(float *)(iVar1 + 0x5c);
    FUN_00525620(iVar1);
    return;
  }
  if (param_1 != 0xd000) {
    FUN_005255b0(0xa002);
    FUN_00525620(iVar1);
    return;
  }
  *param_2 = (float)*(int *)(iVar1 + 0x54);
  FUN_00525620(iVar1);
  return;
}


