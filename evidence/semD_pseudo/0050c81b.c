SIZE_T FUN_0050c81b(LPCVOID param_1)

{
  byte *pbVar1;
  SIZE_T SVar2;
  undefined1 local_30 [4];
  byte *local_2c;
  undefined1 local_28 [4];
  SIZE_T local_24;
  byte *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005ac500;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  if (DAT_007f1d70 == 3) {
    ExceptionList = &local_14;
    FUN_0050dd18(9);
    local_8 = 0;
    local_20 = (byte *)FUN_0050cb23(param_1);
    if (local_20 != (byte *)0x0) {
      local_24 = *(int *)((int)param_1 + -4) - 9;
    }
    SVar2 = local_24;
    local_8 = 0xffffffff;
    FUN_0050c885();
    pbVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_007f1d70 != 2) goto LAB_0050c8d9;
    ExceptionList = &local_14;
    FUN_0050dd18(9);
    local_8 = 1;
    local_2c = (byte *)FUN_0050d87e(param_1,local_30,local_28);
    if (local_2c != (byte *)0x0) {
      local_24 = (uint)*local_2c << 4;
    }
    SVar2 = local_24;
    local_8 = 0xffffffff;
    FUN_0050c900();
    pbVar1 = local_2c;
  }
  if (pbVar1 != (byte *)0x0) {
    ExceptionList = local_14;
    return SVar2;
  }
LAB_0050c8d9:
  SVar2 = HeapSize(DAT_007f1d6c,0,param_1);
  ExceptionList = local_14;
  return SVar2;
}


