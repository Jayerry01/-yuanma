undefined4 * __thiscall FUN_00577e80(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a6173;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00577ad0(param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_005ae288;
  param_1[1] = 10;
  param_1[10] = param_3;
  piVar1 = operator_new(param_3 * 0x18 + 4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (piVar1 == (int *)0x0) {
    param_1[9] = 0;
  }
  else {
    *piVar1 = param_3;
    FUN_0050ac61(piVar1 + 1,0x18,param_3,FUN_00565a40,FUN_004fa4f0);
    param_1[9] = piVar1 + 1;
  }
  ExceptionList = local_c;
  return param_1;
}


