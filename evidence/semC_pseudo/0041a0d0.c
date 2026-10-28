char FUN_0041a0d0(int param_1)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = 0;
  local_1c = 0;
  do {
    if (iVar5 == 3) {
      local_c = DAT_007e2880;
      local_8 = DAT_007e2884;
      local_4 = DAT_007e2888;
      local_18 = DAT_007e2820;
      local_14 = DAT_007e2824;
      local_10 = DAT_007e2828;
    }
    else {
      local_c = (&DAT_007e2820)[iVar5 * 8];
      local_8 = (&DAT_007e2824)[iVar5 * 8];
      local_4 = (&DAT_007e2828)[iVar5 * 8];
      local_18 = (&DAT_007e2840)[iVar5 * 8];
      local_14 = (&DAT_007e2844)[iVar5 * 8];
      local_10 = (&DAT_007e2848)[iVar5 * 8];
    }
    iVar4 = 2;
    iVar7 = 2;
    iVar6 = param_1 + 0x98;
    do {
      iVar1 = FUN_0041a040(&local_c,&local_18,iVar6,*(undefined4 *)(iVar6 + -4));
      if (iVar1 == 0) {
        iVar4 = 0;
        break;
      }
      if (iVar1 == 1) {
        iVar4 = 1;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x10;
    } while (iVar7 < 6);
    local_1c = local_1c + iVar4;
    iVar5 = iVar5 + 1;
    if (3 < iVar5) {
      if (local_1c != 0) {
        return (local_1c == 8) + '\x01';
      }
      iVar5 = 2;
      pfVar3 = (float *)(param_1 + 0x9c);
      while( true ) {
        iVar6 = 0;
        pfVar2 = (float *)&DAT_007e2824;
        do {
          if (pfVar3[-2] <= *pfVar2 * *pfVar3 + pfVar2[-1] * pfVar3[-1] + pfVar2[1] * pfVar3[1]) {
            iVar6 = iVar6 + 1;
          }
          pfVar2 = pfVar2 + 8;
        } while ((int)pfVar2 < 0x7e28a4);
        if (iVar6 == 0) break;
        iVar5 = iVar5 + 1;
        pfVar3 = pfVar3 + 4;
        if (5 < iVar5) {
          return '\x01';
        }
      }
      return '\0';
    }
  } while( true );
}


