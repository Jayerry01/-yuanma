uint FUN_00410ce0(void)

{
  uint *puVar1;
  
  if (DAT_005d5a0c == 0) {
    return 0;
  }
  if (*(int *)(DAT_005d5a0c + 0x6c8) == 0) {
    return 0;
  }
  puVar1 = *(uint **)(*(int *)(DAT_005d5a0c + 0x6c8) + 0x14);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  return *puVar1 | 0x2000000;
}


