void FUN_0058b4f0(void)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint local_4;
  
  iVar1 = DAT_0072c0f8;
  for (pbVar3 = DAT_0072bed4; pbVar3 < DAT_0072c0f4; pbVar3 = pbVar3 + 1) {
    if (*pbVar3 == 0) {
      local_4 = 1;
    }
    else {
      local_4 = (uint)(byte)(&DAT_005b1578)[(uint)*pbVar3 * 4];
    }
    iVar2 = iVar1 * 2;
    if (*(short *)(&DAT_005b1500 + iVar2) != 0) {
      DAT_0072be2c = pbVar3;
      DAT_0072bfe8 = iVar1;
    }
    if (*(short *)(&DAT_005b1bd8 + ((int)*(short *)(&DAT_005b19e8 + iVar2) + local_4) * 2) != iVar1)
    {
      do {
        iVar1 = (int)*(short *)(&DAT_005b1a70 + iVar2);
        if (0x3a < iVar1) {
          local_4 = (uint)(byte)(&DAT_005b1978)[local_4 * 4];
        }
        iVar2 = iVar1 * 2;
      } while (*(short *)(&DAT_005b1bd8 + ((int)*(short *)(&DAT_005b19e8 + iVar2) + local_4) * 2) !=
               iVar1);
    }
    iVar1 = (int)*(short *)(&DAT_005b1af8 +
                           ((int)*(short *)(&DAT_005b19e8 + iVar1 * 2) + local_4) * 2);
  }
  return;
}


