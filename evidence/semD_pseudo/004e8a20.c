undefined4 * __fastcall FUN_004e8a20(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a30cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005ab150;
  pvVar1 = operator_new(4);
  param_1[2] = pvVar1;
  pvVar1 = operator_new(0x48);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005498c0();
  }
  local_4 = 0xffffffff;
  param_1[10] = uVar2;
  FUN_004e8b10();
  ExceptionList = local_c;
  return param_1;
}


