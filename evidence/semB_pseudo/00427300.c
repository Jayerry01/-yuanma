void FUN_00427300(int param_1,int param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  ushort *puVar17;
  uint uVar18;
  bool bVar19;
  int local_10;
  int local_c;
  
  iVar16 = param_2;
  if (DAT_005c4628 == 0) {
    FUN_004277b0(param_1,param_2,param_3);
  }
  else {
    if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
      param_2 = param_1;
      param_1 = iVar16;
    }
    iVar16 = (int)param_3;
    if (*(int *)((int)param_3 + 0x10) < *(int *)(param_1 + 0x10)) {
      iVar16 = param_1;
      param_1 = (int)param_3;
    }
    iVar15 = iVar16;
    if (*(int *)(iVar16 + 0x10) < *(int *)(param_2 + 0x10)) {
      iVar15 = param_2;
      param_2 = iVar16;
    }
    iVar16 = *(int *)(param_1 + 0x10);
    if (((iVar16 < *(int *)(DAT_005d5a0c + 0x690)) && (-1 < *(int *)(iVar15 + 0x10))) &&
       (iVar6 = *(int *)(iVar15 + 0x10) - iVar16, iVar6 != 0)) {
      iVar6 = ((*(int *)(param_2 + 0x10) - iVar16) * 0x10000) / iVar6;
      iVar16 = (*(int *)(param_1 + 0xc) - *(int *)(param_2 + 0xc)) * 0x10000 +
               (*(int *)(iVar15 + 0xc) - *(int *)(param_1 + 0xc)) * iVar6;
      if (iVar16 != 0) {
        DAT_007e3340 = DAT_007e3340 + 1;
        _DAT_007e0ea0 = iVar15;
        _DAT_007e3390 = iVar15;
        if (iVar16 < 0) {
          DAT_007e0418 = 2;
          DAT_007e2c8c = 1;
          _DAT_007e0ea4 = param_1;
          _DAT_007e3394 = param_2;
          _DAT_007e3398 = param_1;
          iVar7 = FUN_00428a20();
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
          if (-0x1000 < iVar16) {
            iVar16 = -0x1000;
          }
        }
        else {
          DAT_007e2c8c = 2;
          DAT_007e0418 = 1;
          _DAT_007e0ea4 = param_2;
          _DAT_007e0ea8 = param_1;
          _DAT_007e3394 = param_1;
          iVar7 = FUN_00428cf0();
          if (iVar7 < 1) {
            return;
          }
          iVar7 = FUN_00428a20();
          if (iVar7 < 1) {
            DAT_007e2c8c = DAT_007e2c8c + -1;
            iVar7 = FUN_00428a20();
            if (iVar7 < 1) {
              return;
            }
          }
          if (iVar16 < 0x1000) {
            iVar16 = 0x1000;
          }
        }
        iVar8 = FUN_00428d40((*(int *)(param_1 + 0x14) - *(int *)(param_2 + 0x14)) * 0x10000 +
                             (*(int *)(iVar15 + 0x14) - *(int *)(param_1 + 0x14)) * iVar6,iVar16);
        iVar9 = FUN_00428d40((*(int *)(param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                             (*(int *)(iVar15 + 0x28) - *(int *)(param_1 + 0x28)) * iVar6,iVar16);
        uVar10 = FUN_00428d70((*(int *)(param_1 + 0x20) - *(int *)(param_2 + 0x20)) * 0x10000 +
                              (*(int *)(iVar15 + 0x20) - *(int *)(param_1 + 0x20)) * iVar6,iVar16);
        iVar11 = FUN_00428d70((*(int *)(param_1 + 0x24) - *(int *)(param_2 + 0x24)) * 0x10000 +
                              (*(int *)(iVar15 + 0x24) - *(int *)(param_1 + 0x24)) * iVar6,iVar16);
        iVar7 = DAT_007e28b0;
        local_c = *(int *)(param_1 + 0x10);
        iVar16 = *(int *)(DAT_007e32ac + 0x34);
        local_10 = DAT_007e28b0 * local_c;
        iVar15 = *(int *)(iVar16 + 0x54);
        iVar6 = *(int *)(iVar16 + 0x58);
        uVar1 = *(undefined4 *)(iVar16 + 0x4c);
        uVar2 = *(undefined4 *)(iVar16 + 0x48);
        uVar3 = *(uint *)(iVar16 + 0x2c);
        uVar4 = *(undefined4 *)(iVar16 + 0x50);
        while( true ) {
          if (-1 < local_c) {
            iVar16 = (int)DAT_007e2314._2_2_;
            iVar13 = DAT_007e2334._2_2_ - iVar16;
            if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar13 + iVar16) {
              iVar13 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar16) + -1;
            }
            param_1 = DAT_007e2318;
            if (0 < iVar13) {
              param_3 = (undefined2 *)(local_10 + iVar16 * 2 + DAT_007e2c88);
              puVar17 = (ushort *)
                        (*(int *)(DAT_007e28a4 + 0x34) +
                        (((local_c - DAT_007e2340) * DAT_007e24e0 - DAT_007e2338) + iVar16) * 2);
              bVar19 = iVar16 + local_c == (iVar16 + local_c & 0xfffffffeU);
              uVar12 = DAT_007e2310 * 0x10000 + (DAT_007e230c & 0xffff);
              uVar18 = DAT_007e2308;
              do {
                bVar19 = (bool)(bVar19 ^ 1);
                if (((bVar19) &&
                    (uVar14 = (uint)*(byte *)(iVar6 + ((uVar12 >> ((byte)uVar1 & 0x1f)) <<
                                                      ((byte)uVar4 & 0x1f)) +
                                                      ((uVar12 & 0xffff) >> ((byte)uVar2 & 0x1f))),
                    uVar14 != uVar3)) && (uVar5 = (ushort)((uint)param_1 >> 0x10), uVar5 < *puVar17)
                   ) {
                  *puVar17 = uVar5;
                  *param_3 = *(undefined2 *)(iVar15 + ((uVar18 >> 0x14) + uVar14 * 0x10) * 2);
                }
                puVar17 = puVar17 + 1;
                param_3 = param_3 + 1;
                uVar18 = uVar18 + iVar9;
                param_1 = param_1 + iVar8;
                uVar12 = uVar12 + iVar11 * 0x10000 + (uVar10 & 0xffff);
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
            }
          }
          local_c = local_c + 1;
          local_10 = local_10 + iVar7;
          if ((DAT_007e2328 < local_c) || (*(int *)(DAT_005d5a0c + 0x690) <= local_c)) break;
          DAT_007e2c98 = DAT_007e2c98 + -1;
          if (DAT_007e2c98 < 1) {
            DAT_007e2c8c = DAT_007e2c8c + -1;
            if (DAT_007e2c8c < 1) {
              return;
            }
            iVar16 = FUN_00428a20();
            if (iVar16 < 1) {
              return;
            }
          }
          else {
            DAT_007e2314 = DAT_007e2314 + DAT_007e2bc8;
            DAT_007e2318 = DAT_007e2318 + DAT_007e2bd4;
            DAT_007e230c = DAT_007e230c + DAT_007e2bd0;
            DAT_007e2308 = DAT_007e2308 + DAT_007e2b80;
            DAT_007e2310 = DAT_007e2310 + DAT_007e2bcc;
          }
          DAT_007e24d4 = DAT_007e24d4 + -1;
          if (DAT_007e24d4 < 1) {
            DAT_007e0418 = DAT_007e0418 + -1;
            if (DAT_007e0418 < 1) {
              return;
            }
            iVar16 = FUN_00428cf0();
            if (iVar16 < 1) {
              return;
            }
          }
          else {
            DAT_007e2334 = DAT_007e2334 + DAT_007e2c84;
          }
        }
      }
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
