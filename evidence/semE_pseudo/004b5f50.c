bool FUN_004b5f50(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  pbVar4 = (byte *)*param_1;
  pbVar5 = (byte *)*param_2;
  param_1 = (undefined4 *)(param_1[1] - (int)pbVar4);
  param_2 = (undefined4 *)(param_2[1] - (int)pbVar5);
  piVar1 = (int *)&param_2;
  if ((int)param_1 <= (int)param_2) {
    piVar1 = (int *)&param_1;
  }
  iVar2 = *piVar1;
  bVar6 = false;
  uVar3 = 0;
  bVar7 = true;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  if (!bVar7) {
    uVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
  }
  if (uVar3 == 0) {
    if ((int)param_1 < (int)param_2) {
      return true;
    }
    uVar3 = (uint)((int)param_2 < (int)param_1);
  }
  return (int)uVar3 < 0;
}


