void __fastcall FUN_0054a300(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a4528;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_005ae084;
  local_4 = 9;
  FUN_0054a740();
  iVar1 = param_1[0x54];
  iVar2 = param_1[0x53];
  local_4._0_1_ = 10;
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
    FUN_004b2e30();
  }
  local_4._0_1_ = 8;
  if ((int)(param_1[0x55] - param_1[0x53]) / 0x18 != 0) {
    FUN_00402e90();
  }
  local_4._0_1_ = 0xb;
  FUN_004e6050(param_1 + 0x4b);
  FUN_0054c870();
  local_4._0_1_ = 7;
  FUN_0049ca90();
  local_4._0_1_ = 0xc;
  FUN_004e6050(param_1 + 0x41);
  FUN_0054c870();
  local_4._0_1_ = 6;
  FUN_0049ca90();
  local_4._0_1_ = 4;
  if ((param_1[0x2f] != 0) && (param_1[0x31] != param_1[0x2f])) {
    FUN_00402e90();
  }
  local_4._0_1_ = 3;
  if ((param_1[0x2c] != 0) && (param_1[0x2e] != param_1[0x2c])) {
    FUN_00402e90();
  }
  local_4._0_1_ = 2;
  FUN_00553c20();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_005546b0();
  ExceptionList = pvStack_c;
  return;
}


