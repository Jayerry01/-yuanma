undefined4 __thiscall FUN_0057e060(int *param_1,undefined4 param_2,int param_3)

{
  FUN_0050a118(param_1,4,1,param_2);
  if (*param_1 != 0) {
    param_1[1] = param_3;
    FUN_0050a118(param_3,*param_1 << 2,1,param_2);
  }
  return 1;
}


