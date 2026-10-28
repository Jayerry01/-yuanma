undefined4 FUN_00536420(int *param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_00530d00(0x506);
    return 0;
  }
  _DAT_007dc7e8 = (double)param_3 / (double)*param_1;
  _DAT_007dc7d8 = (double)param_4 / (double)param_1[1];
  _DAT_007dc7f0 = (double)param_5 / (double)param_1[2];
  uVar1 = FUN_005364d0(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}


