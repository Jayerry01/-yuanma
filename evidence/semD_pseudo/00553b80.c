undefined4 * __fastcall FUN_00553b80(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4dfb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_0054c370(0);
  local_4 = 0;
  FUN_005519d0();
  *param_1 = &PTR_FUN_005ae17c;
  FUN_00554650(0);
  param_1[1] = 0;
  param_1[5] = 0;
  ExceptionList = local_c;
  return param_1;
}


