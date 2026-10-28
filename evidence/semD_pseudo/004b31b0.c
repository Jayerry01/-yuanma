undefined4 * __fastcall FUN_004b31b0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a05e4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00550060();
  local_4 = 0;
  FUN_004a9010();
  param_1[0x1a8] = 0;
  param_1[0x1a9] = 0;
  param_1[0x1aa] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  *param_1 = &PTR_FUN_005a9dc0;
  param_1[0x1a4] = &PTR_LAB_005a9d88;
  FUN_004b3470();
  ExceptionList = local_c;
  return param_1;
}


