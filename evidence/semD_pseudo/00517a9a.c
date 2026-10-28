FUN_00517a9a(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            float param_5,float param_6)

{
  int iVar1;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  param_5 = param_5 + param_6;
  iVar1 = FUN_00515706(param_5,0);
  if (iVar1 == 0) {
    thunk_FUN_005178cc(local_24,param_2,param_3,param_5);
    thunk_FUN_005178cc(local_14,param_2,param_4,param_5);
    thunk_FUN_005178cc(param_1,local_24,local_14,param_6 / param_5);
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return param_1;
}


