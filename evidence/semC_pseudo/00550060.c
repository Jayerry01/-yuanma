undefined4 * __fastcall FUN_00550060(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4a7c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0054d0e0();
  local_4 = 0;
  param_1[0x18b] = 0;
  param_1[0x18c] = 0;
  param_1[0x18d] = 0;
  FUN_004608a0(8);
  local_4._0_1_ = 1;
  FUN_00402a70();
  local_4._0_1_ = 2;
  param_1[0x18e] = 0;
  param_1[399] = 0;
  param_1[400] = 0;
  FUN_004608a0(8);
  local_4._0_1_ = 3;
  FUN_00402a70();
  local_4._0_1_ = 4;
  param_1[0x191] = 0;
  param_1[0x192] = 0;
  param_1[0x193] = 0;
  FUN_004608a0(8);
  local_4._0_1_ = 5;
  FUN_00402a70();
  local_4._0_1_ = 6;
  param_1[0x194] = 0;
  param_1[0x195] = 0;
  param_1[0x196] = 0;
  FUN_004608a0(8);
  local_4._0_1_ = 7;
  FUN_00402a70();
  local_4._0_1_ = 8;
  param_1[0x197] = 0;
  param_1[0x198] = 0;
  param_1[0x199] = 0;
  FUN_004608a0(8);
  local_4._0_1_ = 9;
  FUN_00402a70();
  param_1[0x19b] = 0;
  param_1[0x19c] = 0;
  param_1[0x19d] = 0;
  local_4._0_1_ = 0xb;
  param_1[0x1a1] = 0;
  param_1[0x1a2] = 0;
  param_1[0x1a3] = 0;
  iVar1 = FUN_00402bf0(8);
  param_1[0x1a1] = iVar1;
  param_1[0x1a2] = iVar1;
  param_1[0x1a3] = iVar1 + 8;
  local_4 = CONCAT31(local_4._1_3_,0xd);
  FUN_00402a70();
  *param_1 = &PTR_FUN_005ae110;
  param_1[0x184] = 0;
  param_1[0x185] = 0;
  *(undefined1 *)(param_1 + 0x19f) = 0;
  param_1[0x1a0] = 0;
  param_1[0x19a] = 0;
  ExceptionList = local_c;
  return param_1;
}


