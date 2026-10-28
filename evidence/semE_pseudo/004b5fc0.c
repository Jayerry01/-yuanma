uint FUN_004b5fc0(byte *param_1,int param_2,byte *param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  pbVar4 = param_1;
  param_1 = (byte *)(param_2 - (int)param_1);
  param_2 = param_4 - (int)param_3;
  piVar1 = &param_2;
  if ((int)param_1 <= param_2) {
    piVar1 = (int *)&param_1;
  }
  iVar3 = *piVar1;
  bVar5 = false;
  uVar2 = 0;
  bVar6 = true;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar5 = *pbVar4 < *param_3;
    bVar6 = *pbVar4 == *param_3;
    pbVar4 = pbVar4 + 1;
    param_3 = param_3 + 1;
  } while (bVar6);
  if (!bVar6) {
    uVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
  }
  if (uVar2 == 0) {
    if ((int)param_1 < param_2) {
      return 0xffffffff;
    }
    uVar2 = (uint)(param_2 < (int)param_1);
  }
  return uVar2;
}


