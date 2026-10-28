void __fastcall FUN_005071c0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a4288;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005ac2a0;
  local_4 = 0;
  FUN_00507450();
  CoUninitialize();
  *param_1 = &PTR_LAB_005ac2e8;
  ExceptionList = local_c;
  return;
}


