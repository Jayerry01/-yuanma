void FUN_00423c30(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  ushort *puVar19;
  int local_68;
  undefined2 *local_5c;
  int local_58;
  uint local_50;
  int local_4c;
  int local_40;
  int local_3c;
  int local_38;
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
  iVar6 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
    iVar6 = param_1;
    param_1 = param_2;
  }
  iVar16 = param_1;
  if (*(int *)(param_3 + 0x10) < *(int *)(param_1 + 0x10)) {
    iVar16 = param_3;
    param_3 = param_1;
  }
  iVar15 = iVar6;
  if (*(int *)(param_3 + 0x10) < *(int *)(iVar6 + 0x10)) {
    iVar15 = param_3;
    param_3 = iVar6;
  }
  iVar6 = *(int *)(iVar16 + 0x10);
  if (*(int *)(DAT_005d5a0c + 0x690) <= iVar6) {
    return;
  }
  if (*(int *)(param_3 + 0x10) < 0) {
    return;
  }
  iVar5 = *(int *)(param_3 + 0x10) - iVar6;
  if (iVar5 == 0) {
    return;
  }
  iVar5 = ((*(int *)(iVar15 + 0x10) - iVar6) * 0x10000) / iVar5;
  param_1 = (*(int *)(iVar16 + 0xc) - *(int *)(iVar15 + 0xc)) * 0x10000 +
            (*(int *)(param_3 + 0xc) - *(int *)(iVar16 + 0xc)) * iVar5;
  if (param_1 == 0) {
    return;
  }
  DAT_007e3340 = DAT_007e3340 + 1;
  _DAT_007e0ea0 = param_3;
  _DAT_007e3390 = param_3;
  if (param_1 < 0) {
    DAT_007e0418 = 2;
    DAT_007e2c8c = 1;
    _DAT_007e0ea4 = iVar16;
    _DAT_007e3394 = iVar15;
    _DAT_007e3398 = iVar16;
    iVar6 = FUN_00428ba0();
    if (iVar6 < 1) {
      return;
    }
    iVar6 = FUN_00428cf0();
    if (iVar6 < 1) {
      DAT_007e0418 = DAT_007e0418 + -1;
      iVar6 = FUN_00428cf0();
      if (iVar6 < 1) {
        return;
      }
    }
    iVar6 = -0x1000;
    if (param_1 < -0xfff) goto LAB_00423db0;
  }
  else {
    DAT_007e2c8c = 2;
    DAT_007e0418 = 1;
    _DAT_007e0ea4 = iVar15;
    _DAT_007e0ea8 = iVar16;
    _DAT_007e3394 = iVar16;
    iVar6 = FUN_00428cf0();
    if (iVar6 < 1) {
      return;
    }
    iVar6 = FUN_00428ba0();
    if (iVar6 < 1) {
      DAT_007e2c8c = DAT_007e2c8c + -1;
      iVar6 = FUN_00428ba0();
      if (iVar6 < 1) {
        return;
      }
    }
    iVar6 = 0x1000;
    if (0xfff < param_1) goto LAB_00423db0;
  }
  param_1 = iVar6;
LAB_00423db0:
  iVar7 = FUN_00428d40((*(int *)(iVar16 + 0x14) - *(int *)(iVar15 + 0x14)) * 0x10000 +
                       (*(int *)(param_3 + 0x14) - *(int *)(iVar16 + 0x14)) * iVar5,param_1);
  iVar8 = FUN_00428d40((*(int *)(iVar16 + 0x28) - *(int *)(iVar15 + 0x28)) * 0x10000 +
                       (*(int *)(param_3 + 0x28) - *(int *)(iVar16 + 0x28)) * iVar5,param_1);
  uVar9 = __ftol(param_1);
  iVar10 = FUN_00428da0(uVar9);
  uVar9 = __ftol(param_1);
  iVar11 = FUN_00428da0(uVar9);
  uVar9 = __ftol(param_1);
  iVar12 = FUN_00428da0(uVar9);
  iVar5 = DAT_007e28b0;
  local_2c = *(int *)(iVar16 + 0x10);
  local_68 = DAT_007e28b0 * local_2c;
  iVar6 = *(int *)(DAT_007e32ac + 0x34);
  iVar16 = *(int *)(iVar6 + 0x58);
  iVar15 = *(int *)(iVar6 + 0x54);
  uVar9 = *(undefined4 *)(iVar6 + 0x48);
  uVar1 = *(undefined4 *)(iVar6 + 0x4c);
  uVar2 = *(undefined4 *)(iVar6 + 0x50);
  do {
    while( true ) {
      if (-1 < local_2c) {
        iVar6 = (int)DAT_007e2314._2_2_;
        iVar14 = DAT_007e2334._2_2_ - iVar6;
        if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar14 + iVar6) {
          iVar14 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar6) + -1;
        }
        if (0 < iVar14) {
          local_5c = (undefined2 *)(local_68 + iVar6 * 2 + DAT_007e2c88);
          param_2 = DAT_007e2318;
          local_24 = (ushort *)
                     (*(int *)(DAT_007e28a4 + 0x34) +
                     (((local_2c - DAT_007e2340) * DAT_007e24e0 - DAT_007e2338) + iVar6) * 2);
          local_c = DAT_007e2308;
          local_8 = DAT_007e2310;
          if (0 < iVar14) {
            local_1c = iVar14 * iVar12;
            local_28 = iVar14 * iVar11;
            local_30 = iVar14 * iVar10;
            local_18 = iVar14 * iVar8;
            local_34 = iVar14 * iVar7;
            iVar6 = 0;
            iVar13 = (DAT_007e230c << 8) / DAT_007e0420;
            local_3c = DAT_007e230c;
            iVar17 = (DAT_007e2310 << 8) / DAT_007e0420;
            local_10 = DAT_007e0420;
            param_3 = iVar14;
            do {
              iVar6 = iVar6 + 0x20;
              if (iVar14 < iVar6) {
                local_4c = param_3;
                local_3c = local_30 + local_3c;
                local_40 = local_8 + local_28;
                local_10 = local_10 + local_1c;
                local_14 = (local_3c * 0x100) / local_10;
                local_38 = (local_40 * 0x100) / local_10;
                local_8 = ((local_38 * 0x100 + iVar17 * -0x100) / param_3) * 0x10000 +
                          (local_14 * 0x100 + iVar13 * -0x100) / param_3;
                local_58 = local_34;
                iVar3 = local_18;
              }
              else {
                local_4c = 0x20;
                local_3c = local_3c + iVar10 * 0x20;
                local_40 = iVar11 * 0x20 + local_8;
                local_10 = local_10 + iVar12 * 0x20;
                local_14 = (local_3c * 0x100) / local_10;
                local_38 = (local_40 * 0x100) / local_10;
                local_8 = (local_38 * 0x100 + iVar17 * -0x100 >> 5) * 0x10000 +
                          (local_14 * 0x100 + iVar13 * -0x100 >> 5);
                local_58 = iVar7 * 0x20;
                iVar3 = iVar8 * 0x20;
              }
              local_50 = local_c + iVar3;
              local_58 = param_2 + local_58;
              uVar18 = iVar17 * 0x1000000 + iVar13 * 0x100;
              puVar19 = local_24;
              do {
                uVar4 = (ushort)((uint)param_2 >> 0x10);
                if (uVar4 < *puVar19) {
                  *puVar19 = uVar4;
                  *local_5c = *(undefined2 *)
                               (iVar15 + ((local_c >> 0x14) +
                                         (uint)*(byte *)(iVar16 + ((uVar18 >> ((byte)uVar1 & 0x1f))
                                                                  << ((byte)uVar2 & 0x1f)) +
                                                                  ((uVar18 & 0xffff) >>
                                                                  ((byte)uVar9 & 0x1f))) * 0x10) * 2
                               );
                }
                puVar19 = puVar19 + 1;
                local_5c = local_5c + 1;
                local_c = local_c + iVar8;
                param_2 = param_2 + iVar7;
                uVar18 = uVar18 + local_8;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
              local_34 = local_34 + iVar7 * -0x20;
              local_24 = local_24 + 0x20;
              local_18 = local_18 + iVar8 * -0x20;
              local_28 = local_28 + iVar11 * -0x20;
              local_8 = local_40;
              local_c = local_50;
              param_3 = param_3 + -0x20;
              param_2 = local_58;
              local_30 = local_30 + iVar10 * -0x20;
              local_1c = local_1c + iVar12 * -0x20;
              iVar13 = local_14;
              iVar17 = local_38;
            } while (iVar6 < iVar14);
          }
        }
      }
      local_2c = local_2c + 1;
      local_68 = local_68 + iVar5;
      if ((DAT_007e2328 < local_2c) || (*(int *)(DAT_005d5a0c + 0x690) <= local_2c)) {
        return;
      }
      DAT_007e2c98 = DAT_007e2c98 + -1;
      if (DAT_007e2c98 < 1) {
        DAT_007e2c8c = DAT_007e2c8c + -1;
        if (DAT_007e2c8c < 1) {
          return;
        }
        iVar6 = FUN_00428ba0();
        if (iVar6 < 1) {
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
    iVar6 = FUN_00428cf0();
  } while (0 < iVar6);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
