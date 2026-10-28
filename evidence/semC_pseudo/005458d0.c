void FUN_005458d0(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  ushort *puVar12;
  int iVar13;
  int iVar14;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar14 = 0;
  local_34 = 0;
  piVar1 = param_2 + 3;
  piVar2 = param_2 + 1;
  iVar9 = param_2[2];
  iVar4 = param_2[4];
  piVar3 = param_2 + 5;
  iVar6 = *param_2;
  local_30 = 0;
  local_2c = 0;
  if (iVar6 <= *piVar2) {
    param_2 = (int *)(iVar6 * 8 + 4);
    do {
      if (iVar9 <= *piVar1) {
        iVar10 = iVar9 * 4 + 2;
        puVar11 = (ushort *)
                  (*(int *)(*(int *)(*(int *)(param_1 + 0x1a8) + 0x18) + iVar6 * 4) +
                  (iVar9 * 0x20 + iVar4) * 2);
        iVar7 = (*piVar1 - iVar9) + 1;
        do {
          if (iVar4 <= *piVar3) {
            iVar8 = iVar4 * 8 + 4;
            iVar13 = (*piVar3 - iVar4) + 1;
            puVar12 = puVar11;
            do {
              uVar5 = (uint)*puVar12;
              puVar12 = puVar12 + 1;
              if (uVar5 != 0) {
                local_34 = local_34 + (int)param_2 * uVar5;
                local_30 = local_30 + iVar10 * uVar5;
                iVar14 = iVar14 + uVar5;
                local_2c = local_2c + iVar8 * uVar5;
              }
              iVar8 = iVar8 + 8;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
          }
          iVar10 = iVar10 + 4;
          puVar11 = puVar11 + 0x20;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar6 = iVar6 + 1;
      param_2 = (int *)((int)param_2 + 8);
    } while (iVar6 <= *piVar2);
  }
  iVar9 = iVar14 >> 1;
  *(char *)(param_3 + **(int **)(param_1 + 0x74)) = (char)((iVar9 + local_34) / iVar14);
  *(char *)(param_3 + *(int *)(*(int *)(param_1 + 0x74) + 4)) = (char)((local_30 + iVar9) / iVar14);
  *(char *)(param_3 + *(int *)(*(int *)(param_1 + 0x74) + 8)) = (char)((local_2c + iVar9) / iVar14);
  return;
}


