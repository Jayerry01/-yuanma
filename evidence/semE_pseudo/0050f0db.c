void FUN_0050f0db(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005ac620;
  puStack_10 = &LAB_0050a518;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_005cccc4 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_005cccc4)();
  }
  local_8 = 0xffffffff;
  FUN_0050f07a();
  return;
}


