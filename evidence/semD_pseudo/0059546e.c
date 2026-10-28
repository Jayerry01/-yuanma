FUN_0059546e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  
  if (*(double *)(param_1 + 2) <= (double)CONCAT44(param_5,param_4)) {
    if ((double)CONCAT44(param_5,param_4) <= *(double *)(param_1 + 4)) {
      uVar1 = (**(code **)(*param_1 + 0x14))
                        (param_1[7],param_2,param_3,param_1[6],param_4,param_5,param_6,param_7);
    }
    else {
      *param_7 = 0;
      param_7[1] = 0;
      uVar1 = 1;
    }
  }
  else {
    *param_7 = 0;
    param_7[1] = 0;
    uVar1 = 1;
  }
  return uVar1;
}


