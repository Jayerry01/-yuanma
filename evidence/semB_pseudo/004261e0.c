void FUN_004261e0(int param_1,int param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  uint uVar16;
  bool bVar17;
  int local_10;
  int local_c;
  
  iVar14 = param_2;
  if (DAT_005c4628 == 0) {
    FUN_00426680(param_1,param_2,param_3);
  }
  else {
    if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
      param_2 = param_1;
      param_1 = iVar14;
    }
    iVar14 = (int)param_3;
    if (*(int *)((int)param_3 + 0x10) < *(int *)(param_1 + 0x10)) {
      iVar14 = param_1;
      param_1 = (int)param_3;
    }
    iVar13 = iVar14;
    if (*(int *)(iVar14 + 0x10) < *(int *)(param_2 + 0x10)) {
      iVar13 = param_2;
      param_2 = iVar14;
    }
    iVar14 = *(int *)(param_1 + 0x10);
    if (((iVar14 < *(int *)(DAT_005d5a0c + 0x690)) && (-1 < *(int *)(iVar13 + 0x10))) &&
       (iVar5 = *(int *)(iVar13 + 0x10) - iVar14, iVar5 != 0)) {
      iVar5 = ((*(int *)(param_2 + 0x10) - iVar14) * 0x10000) / iVar5;
      iVar14 = (*(int *)(param_1 + 0xc) - *(int *)(param_2 + 0xc)) * 0x10000 +
               (*(int *)(iVar13 + 0xc) - *(int *)(param_1 + 0xc)) * iVar5;
      if (iVar14 != 0) {
        DAT_007e3340 = DAT_007e3340 + 1;
        _DAT_007e0ea0 = iVar13;
        _DAT_007e3390 = iVar13;
        if (iVar14 < 0) {
          DAT_007e0418 = 2;
          DAT_007e2c8c = 1;
          _DAT_007e0ea4 = param_1;
          _DAT_007e3394 = param_2;
          _DAT_007e3398 = param_1;
          iVar6 = FUN_00428a20();
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
          if (-0x1000 < iVar14) {
            iVar14 = -0x1000;
          }
        }
        else {
          DAT_007e2c8c = 2;
          DAT_007e0418 = 1;
          _DAT_007e0ea4 = param_2;
          _DAT_007e0ea8 = param_1;
          _DAT_007e3394 = param_1;
          iVar6 = FUN_00428cf0();
          if (iVar6 < 1) {
            return;
          }
          iVar6 = FUN_00428a20();
          if (iVar6 < 1) {
            DAT_007e2c8c = DAT_007e2c8c + -1;
            iVar6 = FUN_00428a20();
            if (iVar6 < 1) {
              return;
            }
          }
          if (iVar14 < 0x1000) {
            iVar14 = 0x1000;
          }
        }
        iVar7 = FUN_00428d40((*(int *)(param_1 + 0x14) - *(int *)(param_2 + 0x14)) * 0x10000 +
                             (*(int *)(iVar13 + 0x14) - *(int *)(param_1 + 0x14)) * iVar5,iVar14);
        iVar8 = FUN_00428d40((*(int *)(param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                             (*(int *)(iVar13 + 0x28) - *(int *)(param_1 + 0x28)) * iVar5,iVar14);
        uVar9 = FUN_00428d70((*(int *)(param_1 + 0x20) - *(int *)(param_2 + 0x20)) * 0x10000 +
                             (*(int *)(iVar13 + 0x20) - *(int *)(param_1 + 0x20)) * iVar5,iVar14);
        iVar10 = FUN_00428d70((*(int *)(param_1 + 0x24) - *(int *)(param_2 + 0x24)) * 0x10000 +
                              (*(int *)(iVar13 + 0x24) - *(int *)(param_1 + 0x24)) * iVar5,iVar14);
        iVar6 = DAT_007e28b0;
        local_c = *(int *)(param_1 + 0x10);
        iVar14 = *(int *)(DAT_007e32ac + 0x34);
        local_10 = DAT_007e28b0 * local_c;
        iVar13 = *(int *)(iVar14 + 0x54);
        iVar5 = *(int *)(iVar14 + 0x58);
        uVar1 = *(undefined4 *)(iVar14 + 0x4c);
        uVar2 = *(undefined4 *)(iVar14 + 0x48);
        uVar3 = *(undefined4 *)(iVar14 + 0x50);
        while( true ) {
          if (-1 < local_c) {
            iVar14 = (int)DAT_007e2314._2_2_;
            iVar12 = DAT_007e2334._2_2_ - iVar14;
            if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar12 + iVar14) {
              iVar12 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar14) + -1;
            }
            param_1 = DAT_007e2318;
            if (0 < iVar12) {
              param_3 = (undefined2 *)(local_10 + iVar14 * 2 + DAT_007e2c88);
              puVar15 = (ushort *)
                        (*(int *)(DAT_007e28a4 + 0x34) +
                        (((local_c - DAT_007e2340) * DAT_007e24e0 - DAT_007e2338) + iVar14) * 2);
              bVar17 = iVar14 + local_c == (iVar14 + local_c & 0xfffffffeU);
              uVar11 = DAT_007e2310 * 0x10000 + (DAT_007e230c & 0xffff);
              uVar16 = DAT_007e2308;
              do {
                bVar17 = (bool)(bVar17 ^ 1);
                if ((bVar17) && (uVar4 = (ushort)((uint)param_1 >> 0x10), uVar4 < *puVar15)) {
                  *puVar15 = uVar4;
                  *param_3 = *(undefined2 *)
                              (iVar13 + ((uVar16 >> 0x14) +
                                        (uint)*(byte *)(iVar5 + ((uVar11 >> ((byte)uVar1 & 0x1f)) <<
                                                                ((byte)uVar3 & 0x1f)) +
                                                                ((uVar11 & 0xffff) >>
                                                                ((byte)uVar2 & 0x1f))) * 0x10) * 2);
                }
                puVar15 = puVar15 + 1;
                param_3 = param_3 + 1;
                uVar16 = uVar16 + iVar8;
                param_1 = param_1 + iVar7;
                uVar11 = uVar11 + iVar10 * 0x10000 + (uVar9 & 0xffff);
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
          }
          local_c = local_c + 1;
          local_10 = local_10 + iVar6;
          if ((DAT_007e2328 < local_c) || (*(int *)(DAT_005d5a0c + 0x690) <= local_c)) break;
          DAT_007e2c98 = DAT_007e2c98 + -1;
          if (DAT_007e2c98 < 1) {
            DAT_007e2c8c = DAT_007e2c8c + -1;
            if (DAT_007e2c8c < 1) {
              return;
            }
            iVar14 = FUN_00428a20();
            if (iVar14 < 1) {
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
            iVar14 = FUN_00428cf0();
            if (iVar14 < 1) {
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
