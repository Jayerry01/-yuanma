void FUN_0054a040(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a43de;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0054a090();
  local_4 = 0xffffffff;
  FUN_004e8500();
  ExceptionList = local_c;
  return;
}


