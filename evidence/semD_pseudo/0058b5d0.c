uint FUN_0058b5d0(int param_1)

{
  int iVar1;
  uint local_4;
  
  iVar1 = param_1 * 2;
  if (*(short *)(&DAT_005b1500 + iVar1) != 0) {
    DAT_0072bfe8 = param_1;
    DAT_0072be2c = DAT_0072c0f4;
  }
  local_4 = 1;
  if (*(short *)(&DAT_005b1bda + *(short *)(&DAT_005b19e8 + iVar1) * 2) != param_1) {
    do {
      param_1 = (int)*(short *)(&DAT_005b1a70 + iVar1);
      if (0x3a < param_1) {
        local_4 = (uint)(byte)(&DAT_005b1978)[local_4 * 4];
      }
      iVar1 = param_1 * 2;
    } while (*(short *)(&DAT_005b1bd8 + ((int)*(short *)(&DAT_005b19e8 + iVar1) + local_4) * 2) !=
             param_1);
  }
  return -(uint)((int)*(short *)(&DAT_005b1af8 +
                                ((int)*(short *)(&DAT_005b19e8 + param_1 * 2) + local_4) * 2) !=
                0x3a) &
         (int)*(short *)(&DAT_005b1af8 +
                        ((int)*(short *)(&DAT_005b19e8 + param_1 * 2) + local_4) * 2);
}


