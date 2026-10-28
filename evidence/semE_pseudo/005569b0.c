int __thiscall FUN_005569b0(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar4 = 0;
  pbVar5 = *(byte **)(param_1 + 0x354);
  pbVar2 = param_2;
  pbVar6 = pbVar5;
  if (0 < *(int *)(param_1 + 0x20)) {
LAB_005569c9:
    do {
      bVar1 = *pbVar2;
      bVar7 = bVar1 < *pbVar5;
      if (bVar1 == *pbVar5) {
        if (bVar1 != 0) {
          bVar1 = pbVar2[1];
          bVar7 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_005569ed;
          pbVar5 = pbVar5 + 2;
          pbVar2 = pbVar2 + 2;
          if (bVar1 != 0) goto LAB_005569c9;
        }
        iVar3 = 0;
      }
      else {
LAB_005569ed:
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      pbVar5 = pbVar6 + 0x2f0;
      pbVar2 = param_2;
      pbVar6 = pbVar5;
    } while (iVar4 < *(int *)(param_1 + 0x20));
  }
  return -1;
}


