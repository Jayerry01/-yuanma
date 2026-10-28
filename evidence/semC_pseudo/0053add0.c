undefined1 FUN_0053add0(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bStack_22;
  byte bStack_21;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  
  uStack_20 = 0;
  uStack_1e = 0;
  uStack_1d = 0;
  bStack_22 = 0;
  bStack_21 = 0;
  uVar4 = (int)*(uint *)(param_1 + 0x16) >> 0x1f;
  cVar1 = FUN_0052c880(*(undefined4 *)(param_1 + 0x12),(*(uint *)(param_1 + 0x16) ^ uVar4) - uVar4,1
                       ,1,0,0x1401);
  if (cVar1 == '\0') {
    return 0;
  }
  DAT_0072329c[10] = 0x601;
  if (*(int *)(param_1 + 0x16) == 0) {
    uStack_20 = 0x507;
    uStack_1e = 0;
    uStack_1d = 0;
    bStack_22 = 0x53;
    bStack_21 = 0;
    FUN_00530d00();
    return 0;
  }
  DAT_0072329c[8] = 0x1900;
  DAT_0072329c[0xd] = 0x405;
  DAT_0072329c[0xc] = 0x40;
  uVar4 = DAT_0072329c[0xc];
  uStack_20 = (undefined2)uVar4;
  uStack_1e = (undefined1)(uVar4 >> 0x10);
  uStack_1d = (undefined1)(uVar4 >> 0x18);
  bStack_22 = 0x53;
  bStack_21 = 0;
  uVar4 = FUN_00530d80();
  DAT_0072329c[0xb] = uVar4;
  if (DAT_0072329c[0xb] == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x16) < 0) {
    DAT_0072329c[10] = 0x602;
  }
  else {
    DAT_0072329c[10] = 0x601;
  }
  uStack_20 = 0;
  uStack_1e = 0;
  uStack_1d = 0;
  bStack_22 = 0;
  bStack_21 = 0;
  (*DAT_007dc854)();
  iVar3 = (*DAT_007dc850)(DAT_0072329c[0xb],DAT_0072329c[0xc],1);
  if (iVar3 != 1) {
    return 0;
  }
  (*DAT_007dc854)(*(undefined4 *)(param_1 + 10),0);
  pbVar7 = (byte *)DAT_0072329c[5];
  pbVar6 = pbVar7 + DAT_0072329c[6];
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (pbVar6 <= pbVar7) {
            return 1;
          }
          iVar3 = (*DAT_007dc850)(&bStack_22,2,1);
          if (iVar3 != 1) {
            return 0;
          }
          if (bStack_22 == 0) break;
          bVar5 = 0;
          if (bStack_22 != 0) {
            do {
              if (pbVar6 <= pbVar7) {
                return 1;
              }
              bVar2 = bStack_21 >> 4;
              if ((bVar5 & 1) != 0) {
                bVar2 = bStack_21 & 0xf;
              }
              *pbVar7 = bVar2;
              pbVar7 = pbVar7 + 1;
              bVar5 = bVar5 + 1;
            } while (bVar5 < bStack_22);
          }
        }
        if (bStack_21 != 0) break;
        uVar4 = (uint)((int)pbVar6 - (int)pbVar7) % *DAT_0072329c;
        if (uVar4 != 0) {
          pbVar7 = pbVar7 + (*DAT_0072329c - uVar4);
        }
      }
      if (bStack_21 == 1) {
        return 1;
      }
      if (bStack_21 != 2) break;
      iVar3 = (*DAT_007dc850)(&bStack_22,2,1);
      if (iVar3 != 1) {
        return 0;
      }
      pbVar7 = pbVar7 + (CONCAT21(uStack_20,bStack_21) & 0xff) * *DAT_0072329c +
                        (CONCAT11(bStack_21,bStack_22) & 0xff);
    }
    bVar5 = 0;
    if (bStack_21 != 0) {
      do {
        if (pbVar6 <= pbVar7) break;
        if ((bVar5 & 1) == 0) {
          iVar3 = (*DAT_007dc850)(&bStack_22,1,1);
          if (iVar3 != 1) {
            return 0;
          }
          bVar2 = bStack_22 >> 4;
        }
        else {
          bVar2 = bStack_22 & 0xf;
        }
        *pbVar7 = bVar2;
        pbVar7 = pbVar7 + 1;
        bVar5 = bVar5 + 1;
      } while (bVar5 < bStack_21);
    }
    if ((((bStack_21 & 3) == 1) || ((bStack_21 & 3) == 2)) &&
       (iVar3 = (*DAT_007dc850)(&bStack_22,1,1), iVar3 != 1)) {
      return 0;
    }
  } while( true );
}


