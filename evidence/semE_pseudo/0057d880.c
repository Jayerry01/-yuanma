void FUN_0057d880(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a662b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0057d910();
  local_4 = 0xffffffff;
  FUN_0047c070();
  ExceptionList = local_c;
  return;
}


