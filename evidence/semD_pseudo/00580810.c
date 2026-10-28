undefined4 FUN_00580810(char *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  bool bVar8;
  
  iVar5 = (int)&DAT_0072ba38 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar5] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_00593634(&DAT_0072ba38);
  iVar5 = 0;
  pcVar7 = s_animation_005d2980;
  do {
    pbVar3 = &DAT_0072ba38;
    pbVar6 = (byte *)pcVar7;
    do {
      bVar2 = *pbVar3;
      bVar8 = bVar2 < *pbVar6;
      if (bVar2 != *pbVar6) {
LAB_0058086c:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_00580871;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar8 = bVar2 < pbVar6[1];
      if (bVar2 != pbVar6[1]) goto LAB_0058086c;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00580871:
    if (iVar4 == 0) {
      return (&DAT_005d29a0)[iVar5 * 9];
    }
    pcVar7 = pcVar7 + 0x24;
    iVar5 = iVar5 + 1;
    if (0x5d2e47 < (int)pcVar7) {
      return 0;
    }
  } while( true );
}


