undefined4 * __fastcall FUN_0054d0e0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4786;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00553290();
  param_1[0x17d] = 0;
  param_1[0x17e] = 0;
  param_1[0x17f] = 0;
  local_4 = 1;
  *param_1 = &PTR_FUN_005ae0a8;
  param_1[0x180] = 0;
  param_1[0x182] = 0;
  FUN_00553790(240000);
  ExceptionList = local_c;
  return param_1;
}


