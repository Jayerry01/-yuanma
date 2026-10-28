undefined4 FUN_00479e30(byte *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int extraout_EDX;
  byte *pbVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  
  pbVar7 = &DAT_005e0d50;
  do {
    iVar4 = -1;
    pbVar3 = pbVar7;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (bVar1 != 0);
    pbVar3 = pbVar7;
    pbVar8 = param_1;
    if (iVar4 != -2) {
      do {
        bVar1 = *pbVar3;
        bVar10 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_00479e73:
          iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_00479e78;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar10 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_00479e73;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00479e78:
      if (iVar4 == 0) {
        FUN_00478bb0();
        *param_2 = extraout_EDX + 1;
        return 0;
      }
    }
    pbVar7 = pbVar7 + 0x30;
  } while ((int)pbVar7 < 0x5ecd50);
  iVar4 = 0;
  pcVar6 = &DAT_005e0d50;
  do {
    iVar5 = -1;
    pcVar9 = pcVar6;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    iVar4 = iVar4 + 1;
    if (iVar5 == -2) {
      *param_2 = iVar4;
      return 1;
    }
    pcVar6 = pcVar6 + 0x30;
    if (0x5ecd4f < (int)pcVar6) {
      return 0xffffffff;
    }
  } while( true );
}


