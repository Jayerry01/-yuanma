bool FUN_0042b280(byte *param_1,byte *param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  byte local_100 [128];
  byte local_80 [128];
  
  if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    return false;
  }
  if (param_3 == 0) {
    while( true ) {
      bVar2 = *param_1;
      bVar9 = bVar2 < *param_2;
      if (bVar2 != *param_2) break;
      if (bVar2 == 0) {
        return true;
      }
      bVar2 = param_1[1];
      bVar9 = bVar2 < param_2[1];
      if (bVar2 != param_2[1]) break;
      param_1 = param_1 + 2;
      param_2 = param_2 + 2;
      if (bVar2 == 0) {
        return true;
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    pbVar8 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar2 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar2 != 0);
    iVar5 = ~uVar4 - 1;
    iVar7 = 0;
    if (0 < iVar5) {
      iVar1 = -(int)param_1;
      iVar6 = iVar5;
      do {
        bVar2 = *param_1;
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        param_1[(int)(local_80 + iVar1)] = bVar2;
        param_1 = param_1 + 1;
        iVar6 = iVar6 + -1;
        iVar7 = iVar5;
      } while (iVar6 != 0);
    }
    uVar4 = 0xffffffff;
    local_80[iVar7] = 0;
    pbVar8 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar2 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar2 != 0);
    iVar5 = ~uVar4 - 1;
    iVar7 = 0;
    if (0 < iVar5) {
      iVar1 = -(int)param_2;
      iVar6 = iVar5;
      do {
        bVar2 = *param_2;
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        param_2[(int)(local_100 + iVar1)] = bVar2;
        param_2 = param_2 + 1;
        iVar6 = iVar6 + -1;
        iVar7 = iVar5;
      } while (iVar6 != 0);
    }
    local_100[iVar7] = 0;
    pbVar8 = local_100;
    pbVar3 = local_80;
    while( true ) {
      bVar2 = *pbVar3;
      bVar9 = bVar2 < *pbVar8;
      if (bVar2 != *pbVar8) break;
      if (bVar2 == 0) {
        return true;
      }
      bVar2 = pbVar3[1];
      bVar9 = bVar2 < pbVar8[1];
      if (bVar2 != pbVar8[1]) break;
      pbVar3 = pbVar3 + 2;
      pbVar8 = pbVar8 + 2;
      if (bVar2 == 0) {
        return true;
      }
    }
  }
  return 1 - bVar9 == (uint)(bVar9 != 0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
