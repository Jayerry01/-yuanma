uint FUN_0058de00(int param_1)

{
  int iVar1;
  uint local_4;
  
  iVar1 = param_1 * 2;
  if (*(short *)(&DAT_005b1fd0 + iVar1) != 0) {
    DAT_0072c164 = param_1;
    DAT_0072c15c = DAT_0072c16c;
  }
  local_4 = 1;
  if (*(short *)(&DAT_005b24ba + *(short *)(&DAT_005b2420 + iVar1) * 2) != param_1) {
    do {
      param_1 = (int)*(short *)(&DAT_005b244c + iVar1);
      if (0x13 < param_1) {
        local_4 = (uint)(byte)(&DAT_005b23f8)[local_4 * 4];
      }
      iVar1 = param_1 * 2;
    } while (*(short *)(&DAT_005b24b8 + ((int)*(short *)(&DAT_005b2420 + iVar1) + local_4) * 2) !=
             param_1);
  }
  return -(uint)((int)*(short *)(&DAT_005b2478 +
                                ((int)*(short *)(&DAT_005b2420 + param_1 * 2) + local_4) * 2) !=
                0x13) &
         (int)*(short *)(&DAT_005b2478 +
                        ((int)*(short *)(&DAT_005b2420 + param_1 * 2) + local_4) * 2);
}


