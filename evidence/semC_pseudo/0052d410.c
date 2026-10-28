undefined4 FUN_0052d410(uint param_1,uint param_2,int param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int local_20;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar2 = param_3;
  uVar7 = param_1;
  local_18 = DAT_0072329c[5];
  local_20 = 0;
  local_14 = 0;
  cVar3 = FUN_0052b240(0x600);
  if (((cVar3 != '\0') && (uVar4 = FUN_0052bc40(0x603), uVar4 != DAT_0072329c[10])) &&
     (local_18 = FUN_0052cf80(DAT_0072329c), local_18 == 0)) {
    return 0;
  }
  uVar4 = (uint)*(byte *)((int)DAT_0072329c + 0xd) * (uint)(byte)DAT_0072329c[3];
  if ((int)param_1 < 0) {
    param_1 = 0;
    uVar8 = (int)uVar7 >> 0x1f;
    local_20 = (uVar7 ^ uVar8) - uVar8;
  }
  if ((int)param_2 < 0) {
    local_14 = (param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f);
    param_2 = 0;
  }
  if (*DAT_0072329c < param_1 + param_3) {
    param_3 = *DAT_0072329c - param_1;
  }
  if (DAT_0072329c[1] < param_2 + param_4) {
    param_4 = DAT_0072329c[1] - param_2;
  }
  iVar6 = param_4 - local_14;
  local_c = 0;
  puVar11 = DAT_0072329c;
  if (0 < iVar6) {
    param_4 = uVar4 * iVar2 * local_14;
    do {
      if (0 < param_3 - local_20) {
        iVar10 = uVar4 * local_20;
        iVar9 = uVar4 * param_1;
        local_10 = param_3 - local_20;
        do {
          uVar7 = 0;
          if (uVar4 != 0) {
            do {
              puVar1 = (undefined1 *)(param_4 + iVar10 + param_5 + uVar7);
              iVar5 = puVar11[4] * (param_2 + local_c) + iVar9 + uVar7;
              uVar7 = uVar7 + 1;
              *(undefined1 *)(iVar5 + local_18) = *puVar1;
              puVar11 = DAT_0072329c;
            } while (uVar7 < uVar4);
          }
          iVar9 = iVar9 + uVar4;
          iVar10 = iVar10 + uVar4;
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
      local_c = local_c + 1;
      param_4 = param_4 + uVar4 * iVar2;
    } while (local_c < iVar6);
  }
  if (local_18 != puVar11[5]) {
    FUN_00530db0(puVar11[5]);
    DAT_0072329c[5] = local_18;
  }
  return 1;
}



undefined4