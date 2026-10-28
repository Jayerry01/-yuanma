void FUN_0047c070(void)

{
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0059d476;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_0047c1c0();
  local_4 = local_4 & 0xffffff00;
  thunk_FUN_00481ac0();
  local_4 = 0xffffffff;
  thunk_FUN_00481ac0();
  ExceptionList = local_c;
  return;
}


