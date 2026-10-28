undefined4 * __fastcall FUN_0054a170(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4480;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004736a0();
  local_4 = 0;
  FUN_004736a0();
  local_4._0_1_ = 1;
  FUN_00554690();
  local_4._0_1_ = 2;
  FUN_00553b80();
  local_4._0_1_ = 3;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  iVar1 = FUN_00402bf0(8);
  param_1[0x2c] = iVar1;
  param_1[0x2d] = iVar1;
  param_1[0x2e] = iVar1 + 8;
  local_4._0_1_ = 4;
  FUN_00402a70();
  local_4._0_1_ = 5;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  FUN_004608a0(8);
  local_4._0_1_ = 6;
  FUN_00402a70();
  local_4._0_1_ = 7;
  FUN_004736a0();
  local_4._0_1_ = 8;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  FUN_0054c370(0);
  local_4._0_1_ = 9;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  FUN_0054c370(0);
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  local_4 = CONCAT31(local_4._1_3_,0xb);
  *param_1 = &PTR_FUN_005ae084;
  param_1[5] = 0;
  param_1[6] = 0xffffffff;
  *(undefined1 *)(param_1 + 7) = 1;
  param_1[8] = 0;
  FUN_0054b560();
  ExceptionList = local_c;
  return param_1;
}


