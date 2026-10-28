void __fastcall FUN_004bd380(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a1048;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005aa368;
  param_1[4] = &PTR_LAB_005aa344;
  local_4 = 0;
  FUN_004b3420();
  FUN_0054da60();
  local_4 = 0xffffffff;
  FUN_004abf50();
  ExceptionList = local_c;
  return;
}


