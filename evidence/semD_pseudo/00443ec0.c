void __fastcall FUN_00443ec0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059b428;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005a8928;
  local_4 = 0;
  if (param_1[3] != 0) {
    FUN_00429cb0(param_1[3]);
  }
  if (param_1[4] != 0) {
    FUN_00429cb0(param_1[4]);
  }
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
    param_1[2] = 0;
  }
  *param_1 = &PTR_LAB_005a8810;
  ExceptionList = local_c;
  return;
}


