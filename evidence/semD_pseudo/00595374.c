FUN_00595374(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(double *)(param_1 + 2) <= (double)CONCAT44(param_5,param_4)) {
    if ((double)CONCAT44(param_5,param_4) <= *(double *)(param_1 + 4)) {
      uVar2 = (**(code **)(*param_1 + 0x10))
                        (param_1[7],param_2,param_3,param_1[6],param_4,param_5,param_6,param_7);
    }
    else {
      iVar1 = param_1[6];
      *param_7 = param_3[iVar1 * 2 + -2];
      param_7[1] = param_3[iVar1 * 2 + -1];
      uVar2 = 1;
    }
  }
  else {
    *param_7 = *param_3;
    param_7[1] = param_3[1];
    uVar2 = 1;
  }
  return uVar2;
}


