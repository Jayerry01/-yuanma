undefined4 FUN_00421b60(void)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005a8478;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc0;
  local_20 = 0;
  iVar1 = cpuid_basic_info(0);
  local_2c = *(undefined4 *)(iVar1 + 4);
  local_28 = *(undefined4 *)(iVar1 + 8);
  local_24 = *(undefined4 *)(iVar1 + 0xc);
  local_8 = 0xffffffff;
  ExceptionList = &local_14;
  iVar1 = _strncmp((char *)&local_2c,s_GenuineIntel_005c6784,0xc);
  if (iVar1 == 0) {
    iVar1 = cpuid_Version_info(1);
    if ((*(uint *)(iVar1 + 8) & 0x2000000) != 0) {
      local_20 = 1;
    }
    if (local_20 != 0) {
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}


