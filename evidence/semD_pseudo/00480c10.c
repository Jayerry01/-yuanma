uint __thiscall FUN_00480c10(int *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  byte local_40 [64];
  
  iVar4 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_40 + iVar4)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00593634(local_40);
  iVar4 = *param_1;
  iVar5 = param_1[1] - iVar4 >> 0x1f;
  uVar6 = 0;
  if ((param_1[1] - iVar4) / 0x18 + iVar5 != iVar5) {
    iVar5 = 0;
    do {
      pbVar3 = (byte *)FUN_00480790(*(undefined4 *)(iVar5 + iVar4));
      pbVar7 = local_40;
      do {
        bVar2 = *pbVar3;
        bVar8 = bVar2 < *pbVar7;
        if (bVar2 != *pbVar7) {
LAB_00480c8c:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_00480c91;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar3[1];
        bVar8 = bVar2 < pbVar7[1];
        if (bVar2 != pbVar7[1]) goto LAB_00480c8c;
        pbVar3 = pbVar3 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_00480c91:
      if (iVar4 == 0) {
        return uVar6;
      }
      iVar4 = *param_1;
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x18;
    } while (uVar6 < (uint)((param_1[1] - iVar4) / 0x18));
  }
  return 0xffffffff;
}


