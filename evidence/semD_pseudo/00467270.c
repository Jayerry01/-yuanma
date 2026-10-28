int __thiscall FUN_00467270(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  bool bVar6;
  byte local_34 [52];
  
  piVar4 = (int *)**(int **)(param_1 + 8);
  if (piVar4 != *(int **)(param_1 + 8)) {
    do {
      pbVar2 = local_34;
      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
        pbVar2[0] = 0;
        pbVar2[1] = 0;
        pbVar2[2] = 0;
        pbVar2[3] = 0;
        pbVar2 = pbVar2 + 4;
      }
      pbVar2[0] = 0;
      pbVar2[1] = 0;
      FUN_004663c0(local_34,param_3);
      pbVar2 = local_34;
      pbVar5 = param_2;
      do {
        bVar1 = *pbVar2;
        bVar6 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_004672d1:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_004672d6;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar6 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_004672d1;
        pbVar2 = pbVar2 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_004672d6:
      if (iVar3 == 0) {
        return piVar4[2];
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(param_1 + 8));
  }
  return 0;
}


