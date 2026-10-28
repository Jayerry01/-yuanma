undefined4 __thiscall FUN_00562dd0(int param_1,float *param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(char *)(param_1 + 0x251) == '\0') {
    return 0;
  }
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = param_2[2];
  local_c = *param_3;
  local_8 = param_3[1];
  local_4 = param_3[2];
  if (local_18 < *(float *)(param_1 + 0x1e0)) {
    local_18 = *(float *)(param_1 + 0x1e0);
  }
  if (local_14 < *(float *)(param_1 + 0x1e4)) {
    local_14 = *(float *)(param_1 + 0x1e4);
  }
  if (local_10 < *(float *)(param_1 + 0x1e8)) {
    local_10 = *(float *)(param_1 + 0x1e8);
  }
  if (*(float *)(param_1 + 0x1ec) < local_c) {
    local_c = *(float *)(param_1 + 0x1ec);
  }
  if (*(float *)(param_1 + 0x1f0) < local_8) {
    local_8 = *(float *)(param_1 + 0x1f0);
  }
  if (*(float *)(param_1 + 0x1ec) < local_4) {
    local_4 = *(float *)(param_1 + 500);
  }
  *(undefined4 *)(param_1 + 0x29c) = 0;
  iVar2 = FUN_00561cd0(&local_18);
  iVar3 = FUN_00561cd0(&local_c);
  iVar7 = *(int *)(iVar3 + 0x3c);
  iVar8 = (uint)(-1 < iVar7 - *(int *)(iVar2 + 0x3c)) * 2 + -1;
  iVar10 = (uint)(-1 < *(int *)(iVar3 + 0x40) - *(int *)(iVar2 + 0x40)) * 2 + -1;
  param_3 = *(float **)(iVar2 + 0x44);
  iVar6 = (uint)(-1 < *(int *)(iVar3 + 0x44) - (int)param_3) * 2 + -1;
  if (param_3 != (float *)(*(int *)(iVar3 + 0x44) + iVar6)) {
    do {
      param_2 = *(float **)(iVar2 + 0x40);
      if (param_2 != (float *)(*(int *)(iVar3 + 0x40) + iVar10)) {
        iVar5 = iVar7 + iVar8;
        do {
          iVar9 = *(int *)(iVar2 + 0x3c);
          if (iVar9 != iVar5) {
            do {
              if (*(int *)(param_1 + 0x49c) + -1 <= *(int *)(param_1 + 0x29c)) goto LAB_00563011;
              uVar4 = FUN_00561c60(iVar9,param_2,param_3);
              iVar9 = iVar9 + iVar8;
              *(undefined4 *)(*(int *)(param_1 + 0x2a0) + *(int *)(param_1 + 0x29c) * 4) = uVar4;
              *(int *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + 1;
              iVar7 = *(int *)(iVar3 + 0x3c);
              iVar5 = iVar7 + iVar8;
            } while (iVar9 != iVar5);
          }
          param_2 = (float *)((int)param_2 + iVar10);
        } while (param_2 != (float *)(*(int *)(iVar3 + 0x40) + iVar10));
      }
      param_3 = (float *)((int)param_3 + iVar6);
    } while (param_3 != (float *)(*(int *)(iVar3 + 0x44) + iVar6));
  }
  if (*(int *)(param_1 + 0x29c) == 0) {
    return 0;
  }
LAB_00563011:
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x29c)) {
    do {
      iVar10 = 0;
      piVar1 = *(int **)(*(int *)(param_1 + 0x2a0) + iVar8 * 4);
      if (0 < *piVar1) {
        do {
          iVar6 = FUN_0056aee0(*(undefined4 *)(piVar1[1] + iVar10 * 4));
          *(undefined4 *)(iVar6 + 0x50) = 0;
          iVar10 = iVar10 + 1;
        } while (iVar10 < *piVar1);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x29c));
  }
  return 1;
}


