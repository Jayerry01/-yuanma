undefined4 * FUN_0049f3d0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 - (int)param_1 >> 2;
  if (iVar2 < 1) {
    return param_3;
  }
  do {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return param_3;
}


