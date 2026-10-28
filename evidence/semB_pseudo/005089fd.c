void FUN_005089fd(LPVOID param_1)

{
  int iVar1;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005ac408;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  if (param_1 == (LPVOID)0x0) {
    return;
  }
  if (DAT_007f1d70 == 3) {
    ExceptionList = &local_14;
    FUN_0050dd18(9);
    local_8 = 0;
    local_20 = FUN_0050cb23(param_1);
    if (local_20 != 0) {
      FUN_0050cb4e(local_20,param_1);
    }
    local_8 = 0xffffffff;
    FUN_00508a67();
    iVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_007f1d70 != 2) goto LAB_00508ac9;
    ExceptionList = &local_14;
    FUN_0050dd18(9);
    local_8 = 1;
    local_28 = FUN_0050d87e(param_1,&local_2c,&local_24);
    if (local_28 != 0) {
      FUN_0050d8d5(local_2c,local_24,local_28);
    }
    local_8 = 0xffffffff;
    FUN_00508abf();
    iVar1 = local_28;
  }
  if (iVar1 != 0) {
    ExceptionList = local_14;
    return;
  }
LAB_00508ac9:
  HeapFree(DAT_007f1d6c,0,param_1);
  ExceptionList = local_14;
  return;
}


