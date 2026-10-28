undefined4 * __fastcall FUN_00481900(undefined4 *param_1)

{
  param_1[9] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[6] = 0xffffffff;
  param_1[4] = 0x3c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x13] = 0;
  FUN_00481950(4);
  return param_1;
}



undefined4 __fastcall thunk_FUN_00481ac0(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 == 0) {
    return 1;
  }
  if (param_1[1] == 0) {
    if (*param_1 != 0) {
      if (*param_1 != 1) {
        return 1;
      }
      FUN_00474390(iVar1);
      param_1[2] = 0;
      return 1;
    }
  }
  else {
    if (param_1[1] != 1) {
      return 1;
    }
    if (*param_1 != 0) {
      if (*param_1 != 1) {
        return 1;
      }
      thunk_FUN_004d5fb0(iVar1);
      param_1[2] = 0;
      return 1;
    }
  }
  FUN_00507850(iVar1);
  param_1[2] = 0;
  return 1;
}


