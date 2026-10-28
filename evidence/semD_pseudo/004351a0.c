undefined4 FUN_004351a0(undefined4 param_1)

{
  int local_68;
  byte abStack_60 [84];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059a3d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00507979(param_1,0x20,0x1a4,1);
  local_4 = 0xffffffff;
  if ((abStack_60[*(int *)(local_68 + 4)] & 6) == 0) {
    FUN_00507a30();
    FUN_005078d5();
    ExceptionList = pvStack_c;
    return 1;
  }
  FUN_00507a30();
  FUN_005078d5();
  ExceptionList = pvStack_c;
  return 0;
}


