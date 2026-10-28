void FUN_0047b270(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d3ab;
  local_c = ExceptionList;
  if (DAT_005f16cc == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x128);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_005f16cc = FUN_0047bc70(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_005f16cc = 0;
  }
  ExceptionList = local_c;
  return;
}


