bool __thiscall FUN_0046a510(int param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cadb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x484);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004a2f60(param_2,1,PTR_DAT_005c7b64);
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_c;
  return iVar2 != 0;
}


