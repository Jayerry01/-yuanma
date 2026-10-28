uint __thiscall FUN_0056e0d0(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  
  pbVar3 = param_2;
  iVar5 = 5;
  bVar8 = true;
  pbVar4 = param_2;
  pbVar7 = &DAT_005c6888;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pbVar4 == *pbVar7;
    pbVar4 = pbVar4 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar8);
  if (!bVar8) {
    iVar5 = 10;
    bVar8 = true;
    pbVar4 = param_2;
    pbVar7 = (byte *)s_Character_005d1884;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pbVar4 == *pbVar7;
      pbVar4 = pbVar4 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      if (*(int *)(param_1 + 0x128) == 0) {
        return -(uint)(*(int *)(*(uint *)(param_1 + 300) + 0x274) != 0) & *(uint *)(param_1 + 300);
      }
    }
    else if (*(int *)(param_1 + 0x128) == 0) {
      iVar5 = FUN_00584c00(param_2);
      if (iVar5 != -1) {
LAB_0056e13e:
        return *(uint *)(param_1 + 300);
      }
      if ((*(int *)(param_1 + 0x128) == 0) && (iVar5 = FUN_00584a40(), iVar5 != 0)) {
        iVar6 = 0;
        iVar5 = FUN_00584a40();
        if (0 < iVar5) {
          do {
            iVar5 = FUN_00584ab0(iVar6,param_2);
            if (iVar5 != -1) goto LAB_0056e13e;
            iVar6 = iVar6 + 1;
            iVar5 = FUN_00584a40();
          } while (iVar6 < iVar5);
        }
      }
    }
    param_2 = (byte *)0x0;
    if (0 < *(int *)(param_1 + 0x40)) {
      do {
        uVar2 = *(uint *)(*(int *)(param_1 + 0x4c) + (int)param_2 * 4);
        pbVar4 = (byte *)(uVar2 + 0x24);
        pbVar7 = pbVar3;
        do {
          bVar1 = *pbVar4;
          bVar8 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_0056e1d9:
            iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_0056e1de;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar8 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_0056e1d9;
          pbVar4 = pbVar4 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_0056e1de:
        if (iVar5 == 0) {
          return uVar2;
        }
        if ((*(int *)(uVar2 + 4) == 8) && (iVar5 = FUN_00587e70(pbVar3), iVar5 != -1)) {
          return uVar2;
        }
        param_2 = (byte *)((int)param_2 + 1);
      } while ((int)param_2 < *(int *)(param_1 + 0x40));
    }
  }
  return 0;
}


