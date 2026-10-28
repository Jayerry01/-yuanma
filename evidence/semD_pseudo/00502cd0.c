void __thiscall FUN_00502cd0(int param_1,undefined2 param_2,undefined1 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a3ff8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00502d70();
  local_14 = CONCAT22(CONCAT11(local_14._3_1_,param_3),param_2);
  local_10 = param_4;
  local_4 = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar1 == *(undefined4 **)(param_1 + 0x20)) {
    FUN_004c4b00(puVar1,&local_14);
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = local_14;
      puVar1[1] = param_4;
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 8;
  }
  local_4 = 0xffffffff;
  FUN_004e8500();
  ExceptionList = local_c;
  return;
}


