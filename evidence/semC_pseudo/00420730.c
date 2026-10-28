void FUN_00420730(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  
  param_3 = param_3 - param_1;
  param_4 = param_4 - param_2;
  puVar7 = (uint *)*param_7;
  iVar1 = (uint)(0 < param_3) * 2 + -1;
  if (0 < param_4) {
    iVar5 = param_3;
    if (param_3 < 1) {
      iVar5 = -param_3;
    }
    if (iVar5 == 0) {
      if (param_5 == 0) {
        param_4 = param_4 - param_6;
        if (0 < param_4) {
          do {
            if ((int)param_1 < *(int *)(DAT_005d5a0c + 0x68c)) {
              puVar7[1] = param_1;
            }
            else {
              puVar7[1] = *(int *)(DAT_005d5a0c + 0x68c) - 1;
            }
            puVar7 = puVar7 + 2;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
          *param_7 = puVar7;
          return;
        }
      }
      else {
        param_4 = param_4 - param_6;
        if (0 < param_4) {
          do {
            puVar6 = puVar7 + 2;
            param_4 = param_4 + -1;
            *puVar7 = ((int)param_1 < 0) - 1 & param_1;
            puVar7 = puVar6;
          } while (param_4 != 0);
          *param_7 = puVar6;
          return;
        }
      }
    }
    else if (param_4 == iVar5) {
      if (param_6 != 0) {
        param_1 = param_1 + iVar1;
      }
      param_4 = param_4 - param_6;
      if (param_5 == 0) {
        if (0 < param_4) {
          do {
            if ((int)param_1 < *(int *)(DAT_005d5a0c + 0x68c)) {
              puVar7[1] = param_1;
            }
            else {
              puVar7[1] = *(int *)(DAT_005d5a0c + 0x68c) - 1;
            }
            param_1 = param_1 + iVar1;
            puVar7 = puVar7 + 2;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
          *param_7 = puVar7;
          return;
        }
      }
      else if (0 < param_4) {
        do {
          puVar6 = puVar7 + 2;
          uVar4 = ((int)param_1 < 0) - 1 & param_1;
          param_1 = param_1 + iVar1;
          *puVar7 = uVar4;
          param_4 = param_4 + -1;
          puVar7 = puVar6;
        } while (param_4 != 0);
        *param_7 = puVar6;
        return;
      }
    }
    else if (iVar5 < param_4) {
      if (param_3 < 1) {
        iVar3 = 1 - param_4;
      }
      else {
        iVar3 = 0;
      }
      if ((param_6 != 0) && (iVar3 = iVar3 + iVar5, 0 < iVar3)) {
        param_1 = param_1 + iVar1;
        iVar3 = iVar3 - param_4;
      }
      if (param_5 == 0) {
        param_6 = param_4 - param_6;
        if (0 < param_6) {
          do {
            if ((int)param_1 < *(int *)(DAT_005d5a0c + 0x68c)) {
              puVar7[1] = param_1;
            }
            else {
              puVar7[1] = *(int *)(DAT_005d5a0c + 0x68c) - 1;
            }
            iVar3 = iVar3 + iVar5;
            if (0 < iVar3) {
              param_1 = param_1 + iVar1;
              iVar3 = iVar3 - param_4;
            }
            puVar7 = puVar7 + 2;
            param_6 = param_6 + -1;
          } while (param_6 != 0);
          *param_7 = puVar7;
          return;
        }
      }
      else {
        param_6 = param_4 - param_6;
        if (0 < param_6) {
          do {
            iVar3 = iVar3 + iVar5;
            *puVar7 = ((int)param_1 < 0) - 1 & param_1;
            if (0 < iVar3) {
              param_1 = param_1 + iVar1;
              iVar3 = iVar3 - param_4;
            }
            puVar7 = puVar7 + 2;
            param_6 = param_6 + -1;
          } while (param_6 != 0);
          *param_7 = puVar7;
          return;
        }
      }
    }
    else {
      iVar3 = iVar5 % param_4;
      iVar5 = (iVar5 / param_4) * iVar1;
      if (param_3 < 1) {
        iVar2 = 1 - param_4;
      }
      else {
        iVar2 = 0;
      }
      if (param_6 != 0) {
        iVar2 = iVar2 + iVar3;
        param_1 = param_1 + iVar5;
        if (0 < iVar2) {
          param_1 = param_1 + iVar1;
          iVar2 = iVar2 - param_4;
        }
      }
      if (param_5 == 0) {
        param_6 = param_4 - param_6;
        if (0 < param_6) {
          do {
            if ((int)param_1 < *(int *)(DAT_005d5a0c + 0x68c)) {
              puVar7[1] = param_1;
            }
            else {
              puVar7[1] = *(int *)(DAT_005d5a0c + 0x68c) - 1;
            }
            iVar2 = iVar2 + iVar3;
            param_1 = param_1 + iVar5;
            if (0 < iVar2) {
              param_1 = param_1 + iVar1;
              iVar2 = iVar2 - param_4;
            }
            puVar7 = puVar7 + 2;
            param_6 = param_6 + -1;
          } while (param_6 != 0);
        }
      }
      else {
        param_6 = param_4 - param_6;
        if (0 < param_6) {
          do {
            iVar2 = iVar2 + iVar3;
            *puVar7 = ((int)param_1 < 0) - 1 & param_1;
            param_1 = param_1 + iVar5;
            if (0 < iVar2) {
              param_1 = param_1 + iVar1;
              iVar2 = iVar2 - param_4;
            }
            puVar7 = puVar7 + 2;
            param_6 = param_6 + -1;
          } while (param_6 != 0);
          *param_7 = puVar7;
          return;
        }
      }
    }
    *param_7 = puVar7;
  }
  return;
}


