undefined4 FUN_0050b378(LPVOID param_1)

{
  BOOL BVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005ac4d8;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  BVar1 = TlsSetValue(DAT_005cccc0,param_1);
  if (BVar1 == 0) {
    __amsg_exit(0x10);
  }
  if (PTR_FUN_005ca684 != (undefined *)0x0) {
    (*(code *)PTR_FUN_005ca684)();
  }
  local_8 = 0;
  (**(code **)((int)param_1 + 0x48))(*(undefined4 *)((int)param_1 + 0x4c));
  FUN_0050b40b();
  ExceptionList = local_14;
  return 0;
}


