void __fastcall FUN_00567960(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a5908;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005ae20c;
  local_4 = 0;
  FUN_005679f0();
  local_4 = 0xffffffff;
  FUN_0047b570();
  ExceptionList = local_c;
  return;
}


