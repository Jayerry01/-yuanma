void FUN_00580510(void)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint local_4;
  
  iVar1 = DAT_0072bac8;
  for (pbVar3 = DAT_0072ba24; pbVar3 < DAT_0072bac4; pbVar3 = pbVar3 + 1) {
    if (*pbVar3 == 0) {
      local_4 = 1;
    }
    else {
      local_4 = (uint)(byte)(&DAT_005b0880)[(uint)*pbVar3 * 4];
    }
    iVar2 = iVar1 * 2;
    if (*(short *)(&DAT_005b0840 + iVar2) != 0) {
      DAT_0072ba30 = pbVar3;
      DAT_0072babc = iVar1;
    }
    if (*(short *)(&DAT_005b0db0 + ((int)*(short *)(&DAT_005b0cb8 + iVar2) + local_4) * 2) != iVar1)
    {
      do {
        iVar1 = (int)*(short *)(&DAT_005b0d00 + iVar2);
        if (0x1e < iVar1) {
          local_4 = (uint)(byte)(&DAT_005b0c80)[local_4 * 4];
        }
        iVar2 = iVar1 * 2;
      } while (*(short *)(&DAT_005b0db0 + ((int)*(short *)(&DAT_005b0cb8 + iVar2) + local_4) * 2) !=
               iVar1);
    }
    iVar1 = (int)*(short *)(&DAT_005b0d48 +
                           ((int)*(short *)(&DAT_005b0cb8 + iVar1 * 2) + local_4) * 2);
  }
  return;
}


