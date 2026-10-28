int __fastcall FUN_00481b30(int *param_1)

{
  int iVar1;
  
  param_1[3] = 0;
  if (param_1[1] == 0) {
    if (*param_1 == 0) {
      param_1[3] = param_1[2];
    }
    else if (*param_1 == 1) {
      iVar1 = thunk_FUN_0047ade0(param_1[2]);
      param_1[3] = iVar1;
      return iVar1;
    }
  }
  else if (param_1[1] == 1) {
    if (*param_1 == 0) {
      param_1[3] = param_1[2];
      return param_1[2];
    }
    if (*param_1 == 1) {
      iVar1 = thunk_FUN_004d5fb0(param_1[2]);
      param_1[3] = iVar1;
      return iVar1;
    }
  }
  return param_1[3];
}


