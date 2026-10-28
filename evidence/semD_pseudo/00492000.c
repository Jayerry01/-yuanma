undefined4 * __fastcall FUN_00492000(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059e7be;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  iVar1 = FUN_00402bf0(8);
  param_1[1] = iVar1;
  param_1[2] = iVar1;
  param_1[3] = iVar1 + 8;
  local_4 = 1;
  FUN_00402a70();
  local_4 = 2;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  iVar1 = FUN_00402bf0(8);
  param_1[4] = iVar1;
  param_1[5] = iVar1;
  param_1[6] = iVar1 + 8;
  local_4._0_1_ = 4;
  FUN_00402a70();
  local_4._0_1_ = 5;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  iVar1 = FUN_00402bf0(8);
  param_1[7] = iVar1;
  param_1[8] = iVar1;
  param_1[9] = iVar1 + 8;
  local_4 = CONCAT31(local_4._1_3_,6);
  FUN_00402a70();
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *param_1 = &PTR_FUN_005a94e4;
  param_1[0xb] = 0;
  param_1[10] = 0;
  ExceptionList = local_c;
  return param_1;
}


