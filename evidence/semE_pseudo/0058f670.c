void __fastcall FUN_0058f670(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a6eb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005b2548;
  local_4 = 0;
  FUN_0058f6c0();
  local_4 = 0xffffffff;
  FUN_0058ec20();
  ExceptionList = local_c;
  return;
}


