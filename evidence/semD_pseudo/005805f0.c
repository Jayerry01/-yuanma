uint FUN_005805f0(int param_1)

{
  int iVar1;
  uint local_4;
  
  iVar1 = param_1 * 2;
  if (*(short *)(&DAT_005b0840 + iVar1) != 0) {
    DAT_0072babc = param_1;
    DAT_0072ba30 = DAT_0072bac4;
  }
  local_4 = 1;
  if (*(short *)(&DAT_005b0db2 + *(short *)(&DAT_005b0cb8 + iVar1) * 2) != param_1) {
    do {
      param_1 = (int)*(short *)(&DAT_005b0d00 + iVar1);
      if (0x1e < param_1) {
        local_4 = (uint)(byte)(&DAT_005b0c80)[local_4 * 4];
      }
      iVar1 = param_1 * 2;
    } while (*(short *)(&DAT_005b0db0 + ((int)*(short *)(&DAT_005b0cb8 + iVar1) + local_4) * 2) !=
             param_1);
  }
  return -(uint)((int)*(short *)(&DAT_005b0d48 +
                                ((int)*(short *)(&DAT_005b0cb8 + param_1 * 2) + local_4) * 2) !=
                0x1e) &
         (int)*(short *)(&DAT_005b0d48 +
                        ((int)*(short *)(&DAT_005b0cb8 + param_1 * 2) + local_4) * 2);
}


