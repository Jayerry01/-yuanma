undefined4 * __fastcall FUN_004f58f0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a3910;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004a9010();
  local_4 = 0;
  FUN_005498c0();
  local_4 = 1;
  *param_1 = &PTR_FUN_005ab670;
  FUN_004f5890();
  ExceptionList = local_c;
  return param_1;
}


