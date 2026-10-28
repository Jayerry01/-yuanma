void __thiscall FUN_00550490(int param_1,char *param_2)

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
  
  if (param_2 != (char *)0x0) {
    piVar1 = (int *)(param_1 + 0x684);
    uVar5 = 0xffffffff;
    pcVar9 = param_2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    pcVar9 = (char *)*piVar1;
    uVar6 = *(int *)(param_1 + 0x688) - (int)pcVar9;
    uVar4 = (int)(param_2 + (~uVar5 - 1)) - (int)param_2;
    if (uVar6 < uVar4) {
      pcVar8 = param_2;
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
      FUN_00403490(param_2 + (*(int *)(param_1 + 0x688) - *piVar1),param_2 + (~uVar5 - 1));
    }
    else {
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *param_2;
        param_2 = param_2 + 1;
        pcVar9 = pcVar9 + 1;
      }
      iVar3 = *(int *)(param_1 + 0x688);
      iVar7 = *piVar1 + uVar4;
      if (iVar7 != iVar3) {
        FUN_005092c0(iVar7,iVar3,1);
        *(int *)(param_1 + 0x688) = *(int *)(param_1 + 0x688) + (iVar7 - iVar3);
        return;
      }
    }
  }
  return;
}


