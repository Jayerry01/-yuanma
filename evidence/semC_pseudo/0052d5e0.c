FUN_0052d5e0(uint param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,int param_7)

{
  undefined1 *puVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int local_34;
  int local_30;
  int local_2c;
  uint local_24;
  int local_1c;
  int local_18;
  int local_10;
  
  iVar2 = param_5;
  iVar7 = param_4;
  uVar5 = param_2;
  local_24 = DAT_0072329c[5];
  local_30 = 0;
  local_34 = 0;
  local_2c = 0;
  cVar3 = FUN_0052b240(0x600);
  if (((cVar3 != '\0') && (uVar4 = FUN_0052bc40(0x603), uVar4 != DAT_0072329c[10])) &&
     (local_24 = FUN_0052cf80(DAT_0072329c), local_24 == 0)) {
    return 0;
  }
  uVar4 = (uint)*(byte *)((int)DAT_0072329c + 0xd) * (uint)(byte)DAT_0072329c[3];
  if ((int)param_1 < 0) {
    local_30 = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
    param_1 = 0;
  }
  if ((int)param_2 < 0) {
    param_2 = 0;
    uVar8 = (int)uVar5 >> 0x1f;
    local_34 = (uVar5 ^ uVar8) - uVar8;
  }
  if ((int)param_3 < 0) {
    uVar8 = (int)param_3 >> 0x1f;
    uVar5 = param_3 ^ uVar8;
    param_3 = 0;
    local_2c = uVar5 - uVar8;
  }
  if (*DAT_0072329c < param_1 + param_4) {
    param_4 = *DAT_0072329c - param_1;
  }
  iVar7 = uVar4 * iVar7;
  if (DAT_0072329c[1] < param_2 + param_5) {
    param_5 = DAT_0072329c[1] - param_2;
  }
  if (DAT_0072329c[2] < param_3 + param_6) {
    param_6 = DAT_0072329c[2] - param_3;
  }
  iVar9 = param_6 - local_2c;
  local_10 = 0;
  puVar11 = DAT_0072329c;
  if (0 < iVar9) {
    local_2c = iVar7 * iVar2 * local_2c;
    do {
      local_18 = 0;
      if (0 < param_5 - local_34) {
        iVar6 = iVar7 * local_34;
        do {
          if (0 < param_4 - local_30) {
            iVar12 = uVar4 * local_30;
            param_6 = uVar4 * param_1;
            local_1c = param_4 - local_30;
            do {
              uVar5 = 0;
              if (uVar4 != 0) {
                do {
                  puVar1 = (undefined1 *)(local_2c + iVar6 + iVar12 + param_7 + uVar5);
                  iVar10 = puVar11[4] * (local_18 + param_2) +
                           param_6 + puVar11[7] * (local_10 + param_3) + uVar5;
                  uVar5 = uVar5 + 1;
                  *(undefined1 *)(iVar10 + local_24) = *puVar1;
                  puVar11 = DAT_0072329c;
                } while (uVar5 < uVar4);
              }
              iVar12 = iVar12 + uVar4;
              param_6 = param_6 + uVar4;
              local_1c = local_1c + -1;
            } while (local_1c != 0);
          }
          local_18 = local_18 + 1;
          iVar6 = iVar6 + iVar7;
        } while (local_18 < param_5 - local_34);
      }
      local_10 = local_10 + 1;
      local_2c = local_2c + iVar7 * iVar2;
    } while (local_10 < iVar9);
  }
  if (local_24 != puVar11[5]) {
    FUN_00530db0(puVar11[5]);
    DAT_0072329c[5] = local_24;
  }
  return 1;
}


