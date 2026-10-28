undefined1 * FUN_00591700(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar3 = 0;
  pbVar5 = &DAT_005d3380;
  pbVar4 = param_1;
  pbVar6 = pbVar5;
LAB_00591713:
  do {
    bVar1 = *pbVar5;
    bVar7 = bVar1 < *pbVar4;
    if (bVar1 == *pbVar4) {
      if (bVar1 != 0) {
        bVar1 = pbVar5[1];
        bVar7 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_00591737;
        pbVar5 = pbVar5 + 2;
        pbVar4 = pbVar4 + 2;
        if (bVar1 != 0) goto LAB_00591713;
      }
      iVar2 = 0;
    }
    else {
LAB_00591737:
      iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
    }
    if (iVar2 == 0) {
      return &DAT_005d3380 + iVar3 * 0x18;
    }
    pbVar5 = pbVar6 + 0x18;
    iVar3 = iVar3 + 1;
    pbVar4 = param_1;
    pbVar6 = pbVar5;
    if (0x5d364f < (int)pbVar5) {
      return (undefined1 *)0x0;
    }
  } while( true );
}



undefined4 * __thiscall