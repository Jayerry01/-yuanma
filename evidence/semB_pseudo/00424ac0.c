void FUN_00424ac0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  ushort *puVar21;
  int local_68;
  undefined2 *local_5c;
  int local_58;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  ushort *local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (DAT_005c4628 == 0) {
    return;
  }
  iVar7 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
    iVar7 = param_1;
    param_1 = param_2;
  }
  iVar18 = param_1;
  if (*(int *)(param_3 + 0x10) < *(int *)(param_1 + 0x10)) {
    iVar18 = param_3;
    param_3 = param_1;
  }
  iVar17 = iVar7;
  if (*(int *)(param_3 + 0x10) < *(int *)(iVar7 + 0x10)) {
    iVar17 = param_3;
    param_3 = iVar7;
  }
  iVar7 = *(int *)(iVar18 + 0x10);
  if (*(int *)(DAT_005d5a0c + 0x690) <= iVar7) {
    return;
  }
  if (*(int *)(param_3 + 0x10) < 0) {
    return;
  }
  iVar6 = *(int *)(param_3 + 0x10) - iVar7;
  if (iVar6 == 0) {
    return;
  }
  iVar6 = ((*(int *)(iVar17 + 0x10) - iVar7) * 0x10000) / iVar6;
  param_1 = (*(int *)(iVar18 + 0xc) - *(int *)(iVar17 + 0xc)) * 0x10000 +
            (*(int *)(param_3 + 0xc) - *(int *)(iVar18 + 0xc)) * iVar6;
  if (param_1 == 0) {
    return;
  }
  DAT_007e3340 = DAT_007e3340 + 1;
  _DAT_007e0ea0 = param_3;
  _DAT_007e3390 = param_3;
  if (param_1 < 0) {
    DAT_007e0418 = 2;
    DAT_007e2c8c = 1;
    _DAT_007e0ea4 = iVar18;
    _DAT_007e3394 = iVar17;
    _DAT_007e3398 = iVar18;
    iVar7 = FUN_00428ba0();
    if (iVar7 < 1) {
      return;
    }
    iVar7 = FUN_00428cf0();
    if (iVar7 < 1) {
      DAT_007e0418 = DAT_007e0418 + -1;
      iVar7 = FUN_00428cf0();
      if (iVar7 < 1) {
        return;
      }
    }
    iVar7 = -0x1000;
    if (param_1 < -0xfff) goto LAB_00424c40;
  }
  else {
    DAT_007e2c8c = 2;
    DAT_007e0418 = 1;
    _DAT_007e0ea4 = iVar17;
    _DAT_007e0ea8 = iVar18;
    _DAT_007e3394 = iVar18;
    iVar7 = FUN_00428cf0();
    if (iVar7 < 1) {
      return;
    }
    iVar7 = FUN_00428ba0();
    if (iVar7 < 1) {
      DAT_007e2c8c = DAT_007e2c8c + -1;
      iVar7 = FUN_00428ba0();
      if (iVar7 < 1) {
        return;
      }
    }
    iVar7 = 0x1000;
    if (0xfff < param_1) goto LAB_00424c40;
  }
  param_1 = iVar7;
LAB_00424c40:
  iVar8 = FUN_00428d40((*(int *)(iVar18 + 0x14) - *(int *)(iVar17 + 0x14)) * 0x10000 +
                       (*(int *)(param_3 + 0x14) - *(int *)(iVar18 + 0x14)) * iVar6,param_1);
  iVar9 = FUN_00428d40((*(int *)(iVar18 + 0x28) - *(int *)(iVar17 + 0x28)) * 0x10000 +
                       (*(int *)(param_3 + 0x28) - *(int *)(iVar18 + 0x28)) * iVar6,param_1);
  uVar10 = __ftol(param_1);
  iVar11 = FUN_00428da0(uVar10);
  uVar10 = __ftol(param_1);
  iVar12 = FUN_00428da0(uVar10);
  uVar10 = __ftol(param_1);
  iVar13 = FUN_00428da0(uVar10);
  iVar6 = DAT_007e28b0;
  local_2c = *(int *)(iVar18 + 0x10);
  local_68 = DAT_007e28b0 * local_2c;
  iVar7 = *(int *)(DAT_007e32ac + 0x34);
  iVar18 = *(int *)(iVar7 + 0x58);
  iVar17 = *(int *)(iVar7 + 0x54);
  uVar10 = *(undefined4 *)(iVar7 + 0x48);
  uVar1 = *(undefined4 *)(iVar7 + 0x4c);
  uVar2 = *(undefined4 *)(iVar7 + 0x50);
  uVar3 = *(uint *)(iVar7 + 0x2c);
  do {
    while( true ) {
      if (-1 < local_2c) {
        iVar7 = (int)DAT_007e2314._2_2_;
        iVar15 = DAT_007e2334._2_2_ - iVar7;
        if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar15 + iVar7) {
          iVar15 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar7) + -1;
        }
        if (0 < iVar15) {
          local_5c = (undefined2 *)(local_68 + iVar7 * 2 + DAT_007e2c88);
          param_2 = DAT_007e2318;
          local_24 = (ushort *)
                     (*(int *)(DAT_007e28a4 + 0x34) +
                     (((local_2c - DAT_007e2340) * DAT_007e24e0 - DAT_007e2338) + iVar7) * 2);
          local_c = DAT_007e2308;
          local_8 = DAT_007e2310;
          if (0 < iVar15) {
            local_1c = iVar15 * iVar13;
            local_28 = iVar15 * iVar12;
            local_30 = iVar15 * iVar11;
            local_18 = iVar15 * iVar9;
            local_34 = iVar15 * iVar8;
            iVar7 = 0;
            iVar14 = (DAT_007e230c << 8) / DAT_007e0420;
            local_3c = DAT_007e230c;
            iVar19 = (DAT_007e2310 << 8) / DAT_007e0420;
            local_10 = DAT_007e0420;
            param_3 = iVar15;
            do {
              iVar7 = iVar7 + 0x20;
              if (iVar15 < iVar7) {
                local_4c = param_3;
                local_3c = local_30 + local_3c;
                local_40 = local_8 + local_28;
                local_10 = local_10 + local_1c;
                local_14 = (local_3c * 0x100) / local_10;
                local_48 = (local_40 * 0x100) / local_10;
                local_8 = ((local_48 * 0x100 + iVar19 * -0x100) / param_3) * 0x10000 +
                          (local_14 * 0x100 + iVar14 * -0x100) / param_3;
                local_58 = local_34;
                iVar4 = local_18;
              }
              else {
                local_4c = 0x20;
                local_3c = local_3c + iVar11 * 0x20;
                local_40 = iVar12 * 0x20 + local_8;
                local_10 = local_10 + iVar13 * 0x20;
                local_14 = (local_3c * 0x100) / local_10;
                local_48 = (local_40 * 0x100) / local_10;
                local_8 = (local_48 * 0x100 + iVar19 * -0x100 >> 5) * 0x10000 +
                          (local_14 * 0x100 + iVar14 * -0x100 >> 5);
                local_58 = iVar8 * 0x20;
                iVar4 = iVar9 * 0x20;
              }
              local_38 = local_c + iVar4;
              local_58 = param_2 + local_58;
              uVar20 = iVar19 * 0x1000000 + iVar14 * 0x100;
              puVar21 = local_24;
              do {
                uVar16 = (uint)*(byte *)(iVar18 + ((uVar20 >> ((byte)uVar1 & 0x1f)) <<
                                                  ((byte)uVar2 & 0x1f)) +
                                                  ((uVar20 & 0xffff) >> ((byte)uVar10 & 0x1f)));
                if ((uVar16 != uVar3) && (uVar5 = (ushort)((uint)param_2 >> 0x10), uVar5 < *puVar21)
                   ) {
                  *puVar21 = uVar5;
                  *local_5c = *(undefined2 *)(iVar17 + ((local_c >> 0x14) + uVar16 * 0x10) * 2);
                }
                puVar21 = puVar21 + 1;
                local_5c = local_5c + 1;
                local_c = local_c + iVar9;
                param_2 = param_2 + iVar8;
                uVar20 = uVar20 + local_8;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
              local_34 = local_34 + iVar8 * -0x20;
              local_24 = local_24 + 0x20;
              local_18 = local_18 + iVar9 * -0x20;
              local_28 = local_28 + iVar12 * -0x20;
              local_8 = local_40;
              local_c = local_38;
              param_3 = param_3 + -0x20;
              param_2 = local_58;
              local_30 = local_30 + iVar11 * -0x20;
              local_1c = local_1c + iVar13 * -0x20;
              iVar14 = local_14;
              iVar19 = local_48;
            } while (iVar7 < iVar15);
          }
        }
      }
      local_2c = local_2c + 1;
      local_68 = local_68 + iVar6;
      if ((DAT_007e2328 < local_2c) || (*(int *)(DAT_005d5a0c + 0x690) <= local_2c)) {
        return;
      }
      DAT_007e2c98 = DAT_007e2c98 + -1;
      if (DAT_007e2c98 < 1) {
        DAT_007e2c8c = DAT_007e2c8c + -1;
        if (DAT_007e2c8c < 1) {
          return;
        }
        iVar7 = FUN_00428ba0();
        if (iVar7 < 1) {
          return;
        }
      }
      else {
        DAT_007e2314 = DAT_007e2314 + DAT_007e2bc8;
        DAT_007e2308 = DAT_007e2308 + DAT_007e2b80;
        DAT_007e2318 = DAT_007e2318 + DAT_007e2bd4;
        DAT_007e230c = DAT_007e230c + DAT_007e2bd0;
        DAT_007e2310 = DAT_007e2310 + DAT_007e2bcc;
        DAT_007e0420 = DAT_007e0420 + DAT_007e2704;
      }
      DAT_007e24d4 = DAT_007e24d4 + -1;
      if (DAT_007e24d4 < 1) break;
      DAT_007e2334 = DAT_007e2334 + DAT_007e2c84;
    }
    DAT_007e0418 = DAT_007e0418 + -1;
    if (DAT_007e0418 < 1) {
      return;
    }
    iVar7 = FUN_00428cf0();
  } while (0 < iVar7);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
