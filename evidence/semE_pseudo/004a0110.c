void __thiscall FUN_004a0110(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = FUN_0050915b(*(undefined4 *)(param_1 + 8));
  *param_2 = uVar1;
  param_4 = param_4 + -1;
  if (0 < param_4) {
    do {
      FUN_004a00b0(2);
      param_2 = param_2 + 1;
      uVar1 = FUN_0050915b(*(undefined4 *)(param_1 + 8));
      iVar2 = iVar2 + 1;
      *param_2 = uVar1;
      if (0xc < iVar2) {
        FUN_0049ff70();
        iVar2 = 0;
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  FUN_004a00b0(param_3);
  return;
}


