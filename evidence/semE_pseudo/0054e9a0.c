void __fastcall FUN_0054e9a0(undefined4 param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a48f3;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_00553c20(param_1);
  ExceptionList = local_c;
  return;
}


