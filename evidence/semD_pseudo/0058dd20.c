void FUN_0058dd20(void)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint local_4;
  
  iVar1 = DAT_0072c170;
  for (pbVar3 = DAT_0072c160; pbVar3 < DAT_0072c16c; pbVar3 = pbVar3 + 1) {
    if (*pbVar3 == 0) {
      local_4 = 1;
    }
    else {
      local_4 = (uint)(byte)(&DAT_005b1ff8)[(uint)*pbVar3 * 4];
    }
    iVar2 = iVar1 * 2;
    if (*(short *)(&DAT_005b1fd0 + iVar2) != 0) {
      DAT_0072c15c = pbVar3;
      DAT_0072c164 = iVar1;
    }
    if (*(short *)(&DAT_005b24b8 + ((int)*(short *)(&DAT_005b2420 + iVar2) + local_4) * 2) != iVar1)
    {
      do {
        iVar1 = (int)*(short *)(&DAT_005b244c + iVar2);
        if (0x13 < iVar1) {
          local_4 = (uint)(byte)(&DAT_005b23f8)[local_4 * 4];
        }
        iVar2 = iVar1 * 2;
      } while (*(short *)(&DAT_005b24b8 + ((int)*(short *)(&DAT_005b2420 + iVar2) + local_4) * 2) !=
               iVar1);
    }
    iVar1 = (int)*(short *)(&DAT_005b2478 +
                           ((int)*(short *)(&DAT_005b2420 + iVar1 * 2) + local_4) * 2);
  }
  return;
}


