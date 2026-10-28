undefined4 * __thiscall FUN_00593200(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a7288;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  iVar1 = FUN_00402bf0(8);
  param_1[3] = iVar1;
  param_1[4] = iVar1;
  param_1[5] = iVar1 + 8;
  local_4 = 2;
  FUN_00402a70();
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = param_2;
  *param_1 = &PTR_FUN_005b36ec;
  param_1[1] = 0x27;
  param_1[9] = 0;
  param_1[2] = 1;
  ExceptionList = local_c;
  return param_1;
}


