int __thiscall FUN_00578920(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar4 = 0;
  pbVar2 = *(byte **)(param_1 + 8);
  pbVar5 = param_2;
  pbVar6 = pbVar2;
  if (0 < *(int *)(param_1 + 4)) {
LAB_00578936:
    do {
      bVar1 = *pbVar2;
      bVar7 = bVar1 < *pbVar5;
      if (bVar1 == *pbVar5) {
        if (bVar1 != 0) {
          bVar1 = pbVar2[1];
          bVar7 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_0057895a;
          pbVar2 = pbVar2 + 2;
          pbVar5 = pbVar5 + 2;
          if (bVar1 != 0) goto LAB_00578936;
        }
        iVar3 = 0;
      }
      else {
LAB_0057895a:
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      pbVar2 = pbVar6 + 0x24;
      pbVar5 = param_2;
      pbVar6 = pbVar2;
    } while (iVar4 < *(int *)(param_1 + 4));
  }
  return -1;
}


