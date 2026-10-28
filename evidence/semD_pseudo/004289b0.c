int FUN_004289b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(&DAT_007e0ea0 + DAT_007e2c8c * 4);
  iVar2 = *(int *)(&DAT_007e0e9c + DAT_007e2c8c * 4);
  iVar3 = *(int *)(iVar2 + 0x10) - *(int *)(iVar1 + 0x10);
  if (iVar3 < 1) {
    return 0;
  }
  DAT_007e2bc8 = ((*(int *)(iVar2 + 0xc) - *(int *)(iVar1 + 0xc)) * 0x10000) / iVar3;
  DAT_007e2314 = *(int *)(iVar1 + 0xc) << 0x10;
  DAT_007e2c98 = iVar3;
  DAT_007e2b80 = ((*(int *)(iVar2 + 0x28) - *(int *)(iVar1 + 0x28)) * 0x10000) / iVar3;
  DAT_007e2308 = *(int *)(iVar1 + 0x28) << 0x10;
  return iVar3;
}


