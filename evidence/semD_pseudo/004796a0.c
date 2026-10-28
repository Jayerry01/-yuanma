undefined4 FUN_004796a0(byte *param_1,int *param_2)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  
  pbVar6 = &DAT_005e0d50;
  pcVar7 = &DAT_005ecd50;
  do {
    iVar4 = -1;
    pcVar9 = pcVar7;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pbVar3 = pbVar6;
    pbVar8 = param_1;
    if (iVar4 != -2) {
      do {
        bVar2 = *pbVar3;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004796ef:
          iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004796f4;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar3[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004796ef;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_004796f4:
      if (iVar4 == 0) {
        iVar4 = FUN_00478c10();
        *param_2 = iVar4 + 0x7d1;
        return 0;
      }
    }
    pcVar7 = pcVar7 + 0x28;
    pbVar6 = pbVar6 + 0x30;
  } while ((int)pcVar7 < 0x5ef550);
  iVar4 = 0;
  pcVar7 = &DAT_005ecd50;
  do {
    iVar5 = -1;
    pcVar9 = pcVar7;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar5 == -2) {
      *param_2 = iVar4 + 0x7d1;
      return 1;
    }
    pcVar7 = pcVar7 + 0x28;
    iVar4 = iVar4 + 1;
    if (0x5ef54f < (int)pcVar7) {
      return 0xffffffff;
    }
  } while( true );
}


