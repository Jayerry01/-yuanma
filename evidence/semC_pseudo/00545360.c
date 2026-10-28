void FUN_00545360(int param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x1a8) + 0x18);
  local_18 = param_2[1];
  param_1 = param_2[2];
  local_4 = param_2[3];
  local_14 = param_2[5];
  iVar8 = param_2[4];
  local_10 = *param_2;
  iVar3 = local_10;
  if (local_10 < local_18) {
    do {
      if (param_1 <= local_4) {
        psVar4 = (short *)(*(int *)(iVar2 + iVar3 * 4) + (param_1 * 0x20 + iVar8) * 2);
        iVar6 = iVar8;
        iVar7 = param_1;
        psVar5 = psVar4;
        do {
          for (; iVar6 <= local_14; iVar6 = iVar6 + 1) {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
            if (sVar1 != 0) {
              *param_2 = iVar3;
              local_10 = iVar3;
              goto LAB_00545411;
            }
          }
          iVar7 = iVar7 + 1;
          psVar4 = psVar5 + 0x20;
          iVar6 = iVar8;
          psVar5 = psVar4;
        } while (iVar7 <= local_4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= local_18);
LAB_00545411:
    iVar3 = local_18;
    if (local_10 < local_18) {
      do {
        if (param_1 <= local_4) {
          psVar4 = (short *)(*(int *)(iVar2 + iVar3 * 4) + (param_1 * 0x20 + iVar8) * 2);
          iVar6 = iVar8;
          iVar7 = param_1;
          psVar5 = psVar4;
          do {
            for (; iVar6 <= local_14; iVar6 = iVar6 + 1) {
              sVar1 = *psVar4;
              psVar4 = psVar4 + 1;
              if (sVar1 != 0) {
                param_2[1] = iVar3;
                local_18 = iVar3;
                goto LAB_0054548a;
              }
            }
            iVar7 = iVar7 + 1;
            psVar4 = psVar5 + 0x20;
            iVar6 = iVar8;
            psVar5 = psVar4;
          } while (iVar7 <= local_4);
        }
        iVar3 = iVar3 + -1;
      } while (local_10 <= iVar3);
    }
  }
LAB_0054548a:
  if (param_1 < local_4) {
    iVar3 = (param_1 * 0x20 + iVar8) * 2;
    iVar6 = local_10;
    local_c = param_1;
    do {
      for (; iVar6 <= local_18; iVar6 = iVar6 + 1) {
        psVar4 = (short *)(*(int *)(iVar2 + iVar6 * 4) + iVar3);
        for (iVar7 = iVar8; iVar7 <= local_14; iVar7 = iVar7 + 1) {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
          if (sVar1 != 0) {
            param_1 = local_c;
            param_2[2] = local_c;
            goto LAB_00545504;
          }
        }
      }
      iVar3 = iVar3 + 0x40;
      local_c = local_c + 1;
      iVar6 = local_10;
    } while (local_c <= local_4);
LAB_00545504:
    if (param_1 < local_4) {
      iVar3 = (local_4 * 0x20 + iVar8) * 2;
      iVar6 = local_10;
      local_c = local_4;
      do {
        for (; iVar6 <= local_18; iVar6 = iVar6 + 1) {
          psVar4 = (short *)(*(int *)(iVar2 + iVar6 * 4) + iVar3);
          for (iVar7 = iVar8; iVar7 <= local_14; iVar7 = iVar7 + 1) {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
            if (sVar1 != 0) {
              local_4 = local_c;
              param_2[3] = local_c;
              goto LAB_0054557a;
            }
          }
        }
        iVar3 = iVar3 + -0x40;
        local_c = local_c + -1;
        iVar6 = local_10;
      } while (param_1 <= local_c);
    }
  }
LAB_0054557a:
  local_c = iVar8;
  if (iVar8 < local_14) {
    do {
      if (local_10 <= local_18) {
        iVar3 = local_10;
        do {
          psVar4 = (short *)(*(int *)(iVar2 + iVar3 * 4) + (param_1 * 0x20 + local_c) * 2);
          for (iVar6 = param_1; iVar6 <= local_4; iVar6 = iVar6 + 1) {
            if (*psVar4 != 0) {
              param_2[4] = local_c;
              iVar8 = local_c;
              goto LAB_005455e7;
            }
            psVar4 = psVar4 + 0x20;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= local_18);
      }
      local_c = local_c + 1;
    } while (local_c <= local_14);
LAB_005455e7:
    local_c = local_14;
    if (iVar8 < local_14) {
      do {
        if (local_10 <= local_18) {
          iVar3 = local_10;
          do {
            psVar4 = (short *)(*(int *)(iVar2 + iVar3 * 4) + (param_1 * 0x20 + local_c) * 2);
            for (iVar6 = param_1; iVar6 <= local_4; iVar6 = iVar6 + 1) {
              if (*psVar4 != 0) {
                local_14 = local_c;
                param_2[5] = local_c;
                goto LAB_00545654;
              }
              psVar4 = psVar4 + 0x20;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 <= local_18);
        }
        local_c = local_c + -1;
      } while (iVar8 <= local_c);
    }
  }
LAB_00545654:
  iVar3 = (local_14 - iVar8) * 8;
  iVar7 = (local_4 - param_1) * 0xc;
  iVar6 = (local_18 - local_10) * 0x10;
  param_2[6] = iVar3 * iVar3 + iVar7 * iVar7 + iVar6 * iVar6;
  iVar3 = 0;
  local_c = local_10;
  if (local_10 <= local_18) {
    do {
      if (param_1 <= local_4) {
        local_10 = (local_4 - param_1) + 1;
        psVar4 = (short *)(*(int *)(iVar2 + local_c * 4) + (param_1 * 0x20 + iVar8) * 2);
        do {
          if (iVar8 <= local_14) {
            iVar6 = (local_14 - iVar8) + 1;
            psVar5 = psVar4;
            do {
              if (*psVar5 != 0) {
                iVar3 = iVar3 + 1;
              }
              psVar5 = psVar5 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          psVar4 = psVar4 + 0x20;
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
      local_c = local_c + 1;
    } while (local_c <= local_18);
    param_2[7] = iVar3;
    return;
  }
  param_2[7] = 0;
  return;
}


