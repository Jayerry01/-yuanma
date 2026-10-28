undefined4 __thiscall FUN_00493710(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059e8db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x23b4) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x59c);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_004beeb0();
    }
    *(undefined4 *)(param_1 + 0x23b4) = uVar2;
  }
  local_4 = 0xffffffff;
  FUN_004bf910(param_1 + 0x20,param_2,param_3);
  ExceptionList = local_c;
  return 1;
}


