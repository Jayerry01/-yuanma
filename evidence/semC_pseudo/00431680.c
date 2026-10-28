void FUN_00431680(float *param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float local_60;
  int local_5c;
  float *local_58;
  float *local_54;
  int local_50;
  int local_4c;
  float local_44 [17];
  
  iVar2 = (int)param_4;
  iVar8 = 0;
  *param_3 = 1.0;
  pfVar4 = param_1;
  if (0 < (int)param_4) {
    do {
      local_60 = 0.0;
      pfVar6 = pfVar4;
      iVar7 = (int)param_4;
      do {
        fVar1 = *pfVar6;
        if (fVar1 <= 0.0) {
          fVar1 = -fVar1;
        }
        if (local_60 < fVar1) {
          local_60 = fVar1;
        }
        pfVar6 = pfVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar8 = iVar8 + 1;
      local_44[iVar8] = 1.0 / local_60;
      pfVar4 = pfVar4 + (int)param_4;
    } while (iVar8 < (int)param_4);
  }
  local_5c = 0;
  if (0 < (int)param_4) {
    local_50 = (int)param_4;
    param_4 = param_1;
    local_54 = param_1;
    local_58 = param_1;
    do {
      iVar8 = 0;
      pfVar4 = param_1;
      pfVar6 = param_4;
      if (0 < local_5c) {
        do {
          fVar1 = *pfVar6;
          pfVar3 = pfVar4;
          pfVar5 = param_4;
          iVar7 = iVar8;
          if (0 < iVar8) {
            do {
              iVar7 = iVar7 + -1;
              fVar1 = fVar1 - *pfVar5 * *pfVar3;
              pfVar3 = pfVar3 + 1;
              pfVar5 = pfVar5 + iVar2;
            } while (iVar7 != 0);
          }
          iVar8 = iVar8 + 1;
          *pfVar6 = fVar1;
          pfVar4 = pfVar4 + iVar2;
          pfVar6 = pfVar6 + iVar2;
        } while (iVar8 < local_5c);
      }
      local_60 = 0.0;
      pfVar4 = local_58;
      pfVar6 = local_54;
      for (iVar8 = local_5c; iVar8 < iVar2; iVar8 = iVar8 + 1) {
        fVar1 = *pfVar6;
        pfVar3 = pfVar4;
        pfVar5 = param_4;
        iVar7 = local_5c;
        if (0 < local_5c) {
          do {
            iVar7 = iVar7 + -1;
            fVar1 = fVar1 - *pfVar3 * *pfVar5;
            pfVar3 = pfVar3 + 1;
            pfVar5 = pfVar5 + iVar2;
          } while (iVar7 != 0);
        }
        *pfVar6 = fVar1;
        if (fVar1 <= 0.0) {
          fVar1 = -fVar1;
        }
        if (local_60 <= fVar1 * local_44[iVar8 + 1]) {
          local_60 = fVar1 * local_44[iVar8 + 1];
          local_4c = iVar8;
        }
        pfVar4 = pfVar4 + iVar2;
        pfVar6 = pfVar6 + iVar2;
      }
      if (local_5c != local_4c) {
        pfVar4 = param_1 + local_4c * iVar2;
        pfVar6 = local_58;
        iVar8 = iVar2;
        do {
          fVar1 = *pfVar4;
          *pfVar4 = *pfVar6;
          pfVar4 = pfVar4 + 1;
          *pfVar6 = fVar1;
          iVar8 = iVar8 + -1;
          pfVar6 = pfVar6 + 1;
        } while (iVar8 != 0);
        *param_3 = -*param_3;
        local_44[local_4c + 1] = *(float *)((int)local_44 + (4 - (int)param_1) + (int)param_4);
      }
      *(int *)((param_2 - (int)param_1) + (int)param_4) = local_4c;
      if (*local_54 == 0.0) {
        *local_54 = 1e-07;
      }
      if (local_5c != iVar2 + -1) {
        fVar1 = *local_54;
        if (local_5c + 1 < iVar2) {
          pfVar4 = param_1 + local_50 + local_5c;
          iVar8 = iVar2 - (local_5c + 1);
          do {
            *pfVar4 = (1.0 / fVar1) * *pfVar4;
            pfVar4 = pfVar4 + iVar2;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
      local_58 = local_58 + iVar2;
      local_5c = local_5c + 1;
      param_4 = param_4 + 1;
      local_54 = local_54 + iVar2 + 1;
      local_50 = local_50 + iVar2;
    } while (local_5c < iVar2);
  }
  return;
}


