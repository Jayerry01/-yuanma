void __thiscall FUN_004a01b0(int param_1,float *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = 0;
  fVar2 = (float10)FUN_0050a69a(*(undefined4 *)(param_1 + 8));
  param_4 = param_4 + -1;
  *param_2 = (float)fVar2;
  if (0 < param_4) {
    do {
      FUN_004a00b0(2);
      param_2 = param_2 + 1;
      fVar2 = (float10)FUN_0050a69a(*(undefined4 *)(param_1 + 8));
      *param_2 = (float)fVar2;
      iVar1 = iVar1 + 1;
      if (0xc < iVar1) {
        FUN_0049ff70();
        iVar1 = 0;
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  FUN_004a00b0(param_3);
  return;
}


