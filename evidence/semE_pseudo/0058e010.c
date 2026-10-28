undefined4 FUN_0058e010(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar3 = 0;
  pcVar5 = s_group_005d3118;
  pbVar4 = param_1;
  pbVar6 = (byte *)pcVar5;
LAB_0058e023:
  do {
    bVar1 = *pcVar5;
    bVar7 = bVar1 < *pbVar4;
    if (bVar1 == *pbVar4) {
      if (bVar1 != 0) {
        bVar1 = pcVar5[1];
        bVar7 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_0058e047;
        pcVar5 = pcVar5 + 2;
        pbVar4 = pbVar4 + 2;
        if (bVar1 != 0) goto LAB_0058e023;
      }
      iVar2 = 0;
    }
    else {
LAB_0058e047:
      iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
    }
    if (iVar2 == 0) {
      return (&DAT_005d3138)[iVar3 * 9];
    }
    pcVar5 = (char *)(pbVar6 + 0x24);
    iVar3 = iVar3 + 1;
    pbVar4 = param_1;
    pbVar6 = (byte *)pcVar5;
    if (0x5d313b < (int)pcVar5) {
      return 0;
    }
  } while( true );
}


