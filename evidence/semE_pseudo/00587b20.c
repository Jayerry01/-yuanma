void __fastcall FUN_00587b20(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a6a98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005b1148;
  local_4 = 0;
  FUN_00587b70();
  local_4 = 0xffffffff;
  FUN_005813c0();
  ExceptionList = local_c;
  return;
}


