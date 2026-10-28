undefined4 __thiscall FUN_00582880(int param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 local_8;
  
  iVar5 = *(int *)(param_1 + 0x1ec);
  uVar6 = 0xffffffff;
  piVar8 = (int *)(iVar5 + 0xf4);
  local_8 = 1;
  pcVar11 = param_2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  pcVar11 = (char *)*piVar8;
  uVar7 = *(int *)(iVar5 + 0xf8) - (int)pcVar11;
  uVar3 = (int)(param_2 + (~uVar6 - 1)) - (int)param_2;
  if (uVar7 < uVar3) {
    pcVar10 = param_2;
    for (uVar3 = uVar7 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    FUN_00403490(param_2 + (*(int *)(iVar5 + 0xf8) - *piVar8),param_2 + (~uVar6 - 1));
  }
  else {
    pcVar10 = param_2;
    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    iVar2 = *(int *)(iVar5 + 0xf8);
    iVar9 = *piVar8 + uVar3;
    if (iVar9 != iVar2) {
      FUN_005092c0(iVar9,iVar2,1);
      *(int *)(iVar5 + 0xf8) = *(int *)(iVar5 + 0xf8) + (iVar9 - iVar2);
    }
  }
  iVar5 = *(int *)(param_1 + 0x1ec);
  uVar6 = 0xffffffff;
  piVar8 = (int *)(iVar5 + 0x100);
  pcVar11 = param_3;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  pcVar11 = (char *)*piVar8;
  uVar7 = *(int *)(iVar5 + 0x104) - (int)pcVar11;
  uVar3 = (int)(param_3 + (~uVar6 - 1)) - (int)param_3;
  if (uVar7 < uVar3) {
    pcVar10 = param_3;
    for (uVar3 = uVar7 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    FUN_00403490(param_3 + (*(int *)(iVar5 + 0x104) - *piVar8),param_3 + (~uVar6 - 1));
  }
  else {
    pcVar10 = param_3;
    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    iVar2 = *(int *)(iVar5 + 0x104);
    iVar9 = *piVar8 + uVar3;
    if (iVar9 != iVar2) {
      FUN_005092c0(iVar9,iVar2,1);
      *(int *)(iVar5 + 0x104) = *(int *)(iVar5 + 0x104) + (iVar9 - iVar2);
    }
  }
  if (*(int *)(param_1 + 0x1e4) != 0) {
    FUN_00583220(param_1);
  }
  if (*(int *)(param_1 + 0x1e8) != 0) {
    FUN_00583260(param_1);
  }
  uVar4 = FUN_0056e0d0(param_2);
  *(undefined4 *)(param_1 + 0x1e4) = uVar4;
  uVar4 = FUN_0056e0d0(param_3);
  *(undefined4 *)(param_1 + 0x1e8) = uVar4;
  if (*(int *)(param_1 + 0x1e4) == 0) {
LAB_00582a1f:
    *(undefined4 *)(param_1 + 0x1e4) = 0;
    local_8 = 0;
  }
  else {
    iVar5 = FUN_00583280(*(int *)(param_1 + 0x1e4));
    if (iVar5 == 0) goto LAB_00582a1f;
    FUN_00583200(param_1);
  }
  if (*(int *)(param_1 + 0x1e8) != 0) {
    iVar5 = FUN_005832b0(*(int *)(param_1 + 0x1e8));
    if (iVar5 != 0) {
      FUN_00583240(param_1);
      goto LAB_00582a57;
    }
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  local_8 = 0;
LAB_00582a57:
  uVar4 = FUN_0056e230(param_2,param_1,0);
  *(undefined4 *)(param_1 + 0x1dc) = uVar4;
  uVar4 = FUN_0056e230(param_3,param_1,0);
  *(undefined4 *)(param_1 + 0x1e0) = uVar4;
  return local_8;
}


