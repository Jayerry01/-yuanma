void FUN_00461480(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c87b;
  local_c = ExceptionList;
  if (DAT_005e032c == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x2c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_005e032c = FUN_004614f0(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_005e032c = 0;
  }
  ExceptionList = local_c;
  return;
}


