undefined4 * __fastcall FUN_00553290(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4d81;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004736a0();
  local_4 = 0;
  FUN_004736a0();
  local_4._0_1_ = 1;
  FUN_00554690();
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00555a50();
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[0x17b] = 0;
  *param_1 = &PTR_FUN_005ae158;
  param_1[1] = 0xffffffff;
  *(undefined1 *)(param_1 + 3) = 1;
  ExceptionList = local_c;
  return param_1;
}


