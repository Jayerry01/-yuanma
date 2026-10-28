void FUN_00544c70(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_428;
  int local_420;
  int aiStack_400 [256];
  
  local_428 = 0;
  iVar7 = param_3 + 0x1c;
  iVar1 = *(int *)(param_1 + 0x70);
  local_420 = 0x7fffffff;
  iVar6 = 0x7fffffff;
  if (0 < iVar1) {
    piVar2 = *(int **)(param_1 + 0x74);
    iVar10 = *piVar2;
    iVar3 = piVar2[1];
    iVar4 = piVar2[2];
    do {
      uVar5 = (uint)*(byte *)(iVar10 + local_428);
      if ((int)uVar5 < param_2) {
        iVar11 = (uVar5 - param_2) * 2;
        iVar11 = iVar11 * iVar11;
        iVar8 = param_2 + 0x18;
LAB_00544d1b:
        iVar6 = iVar8;
      }
      else {
        iVar6 = param_2 + 0x18;
        iVar8 = param_2;
        if (iVar6 < (int)uVar5) {
          iVar11 = (uVar5 - iVar6) * 2;
          iVar11 = iVar11 * iVar11;
          goto LAB_00544d1b;
        }
        iVar11 = 0;
        if (param_2 * 2 + 0x18 >> 1 < (int)uVar5) goto LAB_00544d1b;
      }
      iVar6 = (uVar5 - iVar6) * 2;
      uVar5 = (uint)*(byte *)(iVar3 + local_428);
      if ((int)uVar5 < param_3) {
        iVar8 = (uVar5 - param_3) * 3;
        iVar11 = iVar11 + iVar8 * iVar8;
        iVar8 = uVar5 - iVar7;
      }
      else {
        if (iVar7 < (int)uVar5) {
          iVar8 = (uVar5 - iVar7) * 3;
          iVar11 = iVar11 + iVar8 * iVar8;
        }
        else if ((int)uVar5 <= param_3 + iVar7 >> 1) {
          iVar8 = uVar5 - iVar7;
          goto LAB_00544d75;
        }
        iVar8 = uVar5 - param_3;
      }
LAB_00544d75:
      uVar5 = (uint)*(byte *)(iVar4 + local_428);
      if ((int)uVar5 < param_4) {
        iVar11 = iVar11 + (uVar5 - param_4) * (uVar5 - param_4);
        iVar9 = uVar5 - (param_4 + 0x18);
      }
      else {
        iVar9 = param_4 + 0x18;
        if (iVar9 < (int)uVar5) {
          iVar11 = iVar11 + (uVar5 - iVar9) * (uVar5 - iVar9);
          iVar9 = uVar5 - param_4;
        }
        else if (param_4 * 2 + 0x18 >> 1 < (int)uVar5) {
          iVar9 = uVar5 - param_4;
        }
        else {
          iVar9 = uVar5 - iVar9;
        }
      }
      iVar6 = iVar6 * iVar6 + iVar8 * 3 * iVar8 * 3 + iVar9 * iVar9;
      aiStack_400[local_428] = iVar11;
      if (iVar6 < local_420) {
        local_420 = iVar6;
      }
      local_428 = local_428 + 1;
      iVar6 = local_420;
    } while (local_428 < iVar1);
  }
  iVar7 = 0;
  iVar10 = 0;
  if (0 < iVar1) {
    do {
      if (aiStack_400[iVar10] <= iVar6) {
        *(char *)(iVar7 + param_5) = (char)iVar10;
        iVar7 = iVar7 + 1;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar1);
  }
  return;
}


