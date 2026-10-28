int FUN_00428cf0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(&DAT_007e3390 + DAT_007e0418 * 4);
  iVar2 = *(int *)(*(int *)(&DAT_007e338c + DAT_007e0418 * 4) + 0x10) - *(int *)(iVar1 + 0x10);
  if (iVar2 < 1) {
    return 0;
  }
  DAT_007e2c84 = ((*(int *)(*(int *)(&DAT_007e338c + DAT_007e0418 * 4) + 0xc) -
                  *(int *)(iVar1 + 0xc)) * 0x10000) / iVar2;
  DAT_007e2334 = *(int *)(iVar1 + 0xc) << 0x10;
  DAT_007e24d4 = iVar2;
  return iVar2;
}


