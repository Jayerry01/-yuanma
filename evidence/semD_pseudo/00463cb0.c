undefined4 __thiscall FUN_00463cb0(int param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c8fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x484);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004a2f60(param_2,1,PTR_DAT_005c7b64);
  }
  *(undefined4 *)(param_1 + 8) = uVar2;
  ExceptionList = local_c;
  return 1;
}


