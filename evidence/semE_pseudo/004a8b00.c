void FUN_004a8b00(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 >> 2;
  if (0 < iVar1) {
    param_1 = param_1 - (int)param_3;
    do {
      *param_3 = *(undefined4 *)(param_1 + (int)param_3);
      param_3 = param_3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


