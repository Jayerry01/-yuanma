undefined4 __fastcall FUN_00481b90(int *param_1)

{
  undefined4 uVar1;
  
  param_1[3] = 0;
  if (param_1[1] == 0) {
    if (*param_1 == 1) {
      uVar1 = thunk_FUN_004d5fb0(param_1[2]);
      return uVar1;
    }
  }
  else if ((param_1[1] == 1) && (*param_1 == 1)) {
    uVar1 = thunk_FUN_004d5fb0(param_1[2]);
    return uVar1;
  }
  return 1;
}


