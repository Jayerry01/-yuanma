void FUN_00509633(uint param_1)

{
  int iVar1;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005ac468;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  if (DAT_007f1d70 == 3) {
    ExceptionList = &local_14;
    if (param_1 <= DAT_007f1d68) {
      ExceptionList = &local_14;
      FUN_0050dd18(9);
      local_8 = 0;
      iVar1 = FUN_0050ce77(param_1);
      local_8 = 0xffffffff;
      FUN_0050969a();
      if (iVar1 != 0) {
        ExceptionList = local_14;
        return;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (DAT_007f1d70 == 2) {
      if (param_1 == 0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = param_1 + 0xf & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_005ccbec) {
        ExceptionList = &local_14;
        FUN_0050dd18(9);
        local_8 = 1;
        iVar1 = FUN_0050d91a(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_005096f9();
        if (iVar1 != 0) {
          ExceptionList = local_14;
          return;
        }
      }
      goto LAB_00509712;
    }
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  dwBytes = param_1 + 0xf & 0xfffffff0;
LAB_00509712:
  HeapAlloc(DAT_007f1d6c,0,dwBytes);
  ExceptionList = local_14;
  return;
}


