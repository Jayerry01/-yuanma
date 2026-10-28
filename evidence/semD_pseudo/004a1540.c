void __fastcall FUN_004a1540(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  *(undefined4 *)(param_1 + 0x30) = 1;
  piVar1 = (int *)(param_1 + 0x24);
  uVar5 = 0xffffffff;
  pcVar9 = s_Command__005c96b0;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  pcVar9 = (char *)*piVar1;
  uVar6 = *(int *)(param_1 + 0x28) - (int)pcVar9;
  uVar4 = ~uVar5 - 1;
  if (uVar6 < uVar4) {
    pcVar8 = s_Command__005c96b0;
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_00403490(s_Command__005c96b0 + (*(int *)(param_1 + 0x28) - *piVar1),~uVar5 + 0x5c96af);
  }
  else {
    pcVar8 = s_Command__005c96b0;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar3 = *(int *)(param_1 + 0x28);
    iVar7 = *piVar1 + uVar4;
    if (iVar7 != iVar3) {
      FUN_005092c0(iVar7,iVar3,1);
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (iVar7 - iVar3);
      return;
    }
  }
  return;
}


