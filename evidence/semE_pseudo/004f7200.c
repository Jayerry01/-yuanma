undefined4 * __fastcall FUN_004f7200(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a3928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004f5d60();
  local_4 = 0;
  *param_1 = &PTR_FUN_005ab7a8;
  FUN_004f7270();
  ExceptionList = local_c;
  return param_1;
}


