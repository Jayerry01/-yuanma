void FUN_004298e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_007ddf40;
  for (iVar1 = 0x800; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(DAT_005d5a0c + 0x6cc) = 0;
  *(undefined4 *)(DAT_005d5a0c + 0x6d0) = 0;
  DAT_005d5b00 = 1;
  return;
}


