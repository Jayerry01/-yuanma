void __thiscall FUN_004b4e80(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int **ppiVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  int *local_8;
  int local_4;
  
  piVar3 = param_3;
  iVar2 = *param_1;
  iVar1 = *(int *)(*param_1 + 4);
  local_8 = param_1;
  while (iVar1 != 0) {
    iVar4 = FUN_004b5fc0(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),*piVar3,
                         piVar3[1]);
    if (iVar4 < 0) {
      iVar1 = *(int *)(iVar1 + 0xc);
    }
    else {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar1 + 8);
    }
  }
  iVar1 = *local_8;
  local_4 = iVar2;
  if (iVar2 != iVar1) {
    local_8 = (int *)(piVar3[1] - *piVar3);
    iVar4 = *(int *)(iVar2 + 0x14) - (int)*(byte **)(iVar2 + 0x10);
    ppiVar5 = &param_3;
    if ((int)local_8 <= iVar4) {
      ppiVar5 = &local_8;
    }
    piVar6 = *ppiVar5;
    bVar10 = false;
    uVar7 = 0;
    bVar11 = true;
    pbVar8 = (byte *)*piVar3;
    pbVar9 = *(byte **)(iVar2 + 0x10);
    do {
      if (piVar6 == (int *)0x0) break;
      piVar6 = (int *)((int)piVar6 + -1);
      bVar10 = *pbVar8 < *pbVar9;
      bVar11 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar11);
    if (!bVar11) {
      uVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
    }
    if (uVar7 == 0) {
      if ((int)local_8 < iVar4) goto LAB_004b4f2a;
      uVar7 = (uint)(iVar4 < (int)local_8);
    }
    if (-1 < (int)uVar7) {
      *param_2 = iVar2;
      return;
    }
  }
LAB_004b4f2a:
  *param_2 = iVar1;
  return;
}


