undefined4 * __fastcall FUN_004a0740(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059f6d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004a0280();
  local_4 = 0;
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
  FUN_004a2510(0);
  local_4 = CONCAT31(local_4._1_3_,1);
  *param_1 = &PTR_FUN_005a9810;
  FUN_004a07e0();
  ExceptionList = local_c;
  return param_1;
}


