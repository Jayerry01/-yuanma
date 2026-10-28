void FUN_00425200(int param_1,int param_2,int param_3)

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
  bool bVar22;
  int local_6c;
  int local_68;
  int local_5c;
  uint local_54;
  undefined2 *local_50;
  int local_44;
  int local_3c;
  int local_38;
  int local_30;
  ushort *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
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
    if (param_1 < -0xfff) goto LAB_00425380;
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
    if (0xfff < param_1) goto LAB_00425380;
  }
  param_1 = iVar7;
LAB_00425380:
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
  local_c = *(int *)(iVar18 + 0x10);
  local_6c = DAT_007e28b0 * local_c;
  iVar7 = *(int *)(DAT_007e32ac + 0x34);
  iVar18 = *(int *)(iVar7 + 0x58);
  iVar17 = *(int *)(iVar7 + 0x54);
  uVar10 = *(undefined4 *)(iVar7 + 0x48);
  uVar1 = *(undefined4 *)(iVar7 + 0x4c);
  uVar2 = *(undefined4 *)(iVar7 + 0x50);
  uVar3 = *(uint *)(iVar7 + 0x2c);
  do {
    while( true ) {
      if (-1 < local_c) {
        iVar7 = (int)DAT_007e2314._2_2_;
        iVar15 = DAT_007e2334._2_2_ - iVar7;
        if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar15 + iVar7) {
          iVar15 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar7) + -1;
        }
        if (0 < iVar15) {
          local_50 = (undefined2 *)(local_6c + iVar7 * 2 + DAT_007e2c88);
          param_2 = DAT_007e2318;
          local_2c = (ushort *)
                     (*(int *)(DAT_007e28a4 + 0x34) +
                     (((local_c - DAT_007e2340) * DAT_007e24e0 - DAT_007e2338) + iVar7) * 2);
          local_18 = DAT_007e2308;
          local_8 = DAT_007e2310;
          bVar22 = DAT_007e2314._2_2_ + local_c == (DAT_007e2314._2_2_ + local_c & 0xfffffffeU);
          if (0 < iVar15) {
            local_24 = iVar15 * iVar13;
            local_20 = iVar15 * iVar12;
            local_28 = iVar15 * iVar11;
            local_30 = iVar15 * iVar9;
            local_1c = iVar15 * iVar8;
            iVar7 = 0;
            iVar14 = (DAT_007e230c << 8) / DAT_007e0420;
            local_3c = DAT_007e230c;
            iVar19 = (DAT_007e2310 << 8) / DAT_007e0420;
            local_10 = DAT_007e0420;
            param_3 = iVar15;
            do {
              iVar7 = iVar7 + 0x20;
              if (iVar15 < iVar7) {
                local_68 = param_3;
                local_3c = local_28 + local_3c;
                local_44 = local_8 + local_20;
                local_10 = local_10 + local_24;
                local_14 = (local_3c * 0x100) / local_10;
                local_38 = (local_44 * 0x100) / local_10;
                local_8 = ((local_38 * 0x100 + iVar19 * -0x100) / param_3) * 0x10000 +
                          (local_14 * 0x100 + iVar14 * -0x100) / param_3;
                local_5c = local_1c;
                iVar4 = local_30;
              }
              else {
                local_3c = iVar11 * 0x20 + local_3c;
                local_44 = local_8 + iVar12 * 0x20;
                local_10 = local_10 + iVar13 * 0x20;
                local_14 = (local_3c * 0x100) / local_10;
                local_68 = 0x20;
                local_38 = (local_44 * 0x100) / local_10;
                local_8 = (local_38 * 0x100 + iVar19 * -0x100 >> 5) * 0x10000 +
                          (local_14 * 0x100 + iVar14 * -0x100 >> 5);
                local_5c = iVar8 * 0x20;
                iVar4 = iVar9 * 0x20;
              }
              local_54 = local_18 + iVar4;
              local_5c = param_2 + local_5c;
              uVar20 = iVar19 * 0x1000000 + iVar14 * 0x100;
              puVar21 = local_2c;
              do {
                bVar22 = (bool)(bVar22 ^ 1);
                if (((bVar22) &&
                    (uVar16 = (uint)*(byte *)(iVar18 + ((uVar20 >> ((byte)uVar1 & 0x1f)) <<
                                                       ((byte)uVar2 & 0x1f)) +
                                                       ((uVar20 & 0xffff) >> ((byte)uVar10 & 0x1f)))
                    , uVar16 != uVar3)) &&
                   (uVar5 = (ushort)((uint)param_2 >> 0x10), uVar5 < *puVar21)) {
                  *puVar21 = uVar5;
                  *local_50 = *(undefined2 *)(iVar17 + ((local_18 >> 0x14) + uVar16 * 0x10) * 2);
                }
                puVar21 = puVar21 + 1;
                local_50 = local_50 + 1;
                local_18 = local_18 + iVar9;
                param_2 = param_2 + iVar8;
                uVar20 = uVar20 + local_8;
                local_68 = local_68 + -1;
              } while (local_68 != 0);
              local_1c = local_1c + iVar8 * -0x20;
              local_2c = local_2c + 0x20;
              local_30 = local_30 + iVar9 * -0x20;
              local_20 = local_20 + iVar12 * -0x20;
              local_8 = local_44;
              local_18 = local_54;
              param_3 = param_3 + -0x20;
              param_2 = local_5c;
              local_28 = local_28 + iVar11 * -0x20;
              local_24 = local_24 + iVar13 * -0x20;
              iVar14 = local_14;
              iVar19 = local_38;
            } while (iVar7 < iVar15);
          }
        }
      }
      local_c = local_c + 1;
      local_6c = local_6c + iVar6;
      if ((DAT_007e2328 < local_c) || (*(int *)(DAT_005d5a0c + 0x690) <= local_c)) {
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
