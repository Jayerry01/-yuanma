undefined4 * __fastcall FUN_004bce70(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a0fe8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005aa1fc;
  local_4 = 0;
  FUN_005498c0();
  *param_1 = &PTR_FUN_005aa2ac;
  param_1[0x14] = 0;
  param_1[1] = 0;
  ExceptionList = local_c;
  return param_1;
}


