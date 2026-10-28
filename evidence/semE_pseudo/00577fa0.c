void __fastcall FUN_00577fa0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a6188;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_005ae288;
  local_4 = 0;
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(3);
    param_1[9] = 0;
  }
  local_4 = 0xffffffff;
  FUN_00577c40();
  ExceptionList = pvStack_c;
  return;
}


