undefined4 * __fastcall FUN_0049ae30(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059f158;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005a974c;
  FUN_004e8500();
  ExceptionList = local_c;
  return param_1;
}


