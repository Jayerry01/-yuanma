void FUN_00426f10(undefined2 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int local_8;
  
  iVar14 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)((int)param_1 + 0x10)) {
    param_2 = (int)param_1;
    param_1 = (undefined2 *)iVar14;
  }
  iVar14 = param_3;
  if (*(int *)(param_3 + 0x10) < *(int *)((int)param_1 + 0x10)) {
    iVar14 = (int)param_1;
    param_1 = (undefined2 *)param_3;
  }
  iVar13 = iVar14;
  if (*(int *)(iVar14 + 0x10) < *(int *)(param_2 + 0x10)) {
    iVar13 = param_2;
    param_2 = iVar14;
  }
  iVar14 = *(int *)((int)param_1 + 0x10);
  if (((iVar14 < *(int *)(DAT_005d5a0c + 0x690)) && (-1 < *(int *)(iVar13 + 0x10))) &&
     (iVar5 = *(int *)(iVar13 + 0x10) - iVar14, iVar5 != 0)) {
    iVar5 = ((*(int *)(param_2 + 0x10) - iVar14) * 0x10000) / iVar5;
    iVar14 = (*(int *)((int)param_1 + 0xc) - *(int *)(param_2 + 0xc)) * 0x10000 +
             (*(int *)(iVar13 + 0xc) - *(int *)((int)param_1 + 0xc)) * iVar5;
    if (iVar14 != 0) {
      DAT_007e3340 = DAT_007e3340 + 1;
      _DAT_007e0ea0 = iVar13;
      _DAT_007e3390 = iVar13;
      if (iVar14 < 0) {
        DAT_007e0418 = 2;
        DAT_007e2c8c = 1;
        _DAT_007e0ea4 = (int)param_1;
        _DAT_007e3394 = param_2;
        _DAT_007e3398 = (int)param_1;
        iVar6 = FUN_00428af0();
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
        _DAT_007e0ea8 = (int)param_1;
        _DAT_007e3394 = (int)param_1;
        iVar6 = FUN_00428cf0();
        if (iVar6 < 1) {
          return;
        }
        iVar6 = FUN_00428af0();
        if (iVar6 < 1) {
          DAT_007e2c8c = DAT_007e2c8c + -1;
          iVar6 = FUN_00428af0();
          if (iVar6 < 1) {
            return;
          }
        }
        if (iVar14 < 0x1000) {
          iVar14 = 0x1000;
        }
      }
      iVar7 = FUN_00428d40((*(int *)((int)param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                           (*(int *)(iVar13 + 0x28) - *(int *)((int)param_1 + 0x28)) * iVar5,iVar14)
      ;
      uVar8 = FUN_00428d70((*(int *)((int)param_1 + 0x20) - *(int *)(param_2 + 0x20)) * 0x10000 +
                           (*(int *)(iVar13 + 0x20) - *(int *)((int)param_1 + 0x20)) * iVar5,iVar14)
      ;
      iVar9 = FUN_00428d70((*(int *)((int)param_1 + 0x24) - *(int *)(param_2 + 0x24)) * 0x10000 +
                           (*(int *)(iVar13 + 0x24) - *(int *)((int)param_1 + 0x24)) * iVar5,iVar14)
      ;
      iVar6 = DAT_007e28b0;
      param_3 = *(int *)((int)param_1 + 0x10);
      iVar14 = *(int *)(DAT_007e32ac + 0x34);
      local_8 = DAT_007e28b0 * param_3;
      iVar13 = *(int *)(iVar14 + 0x54);
      iVar5 = *(int *)(iVar14 + 0x58);
      uVar1 = *(undefined4 *)(iVar14 + 0x4c);
      uVar2 = *(undefined4 *)(iVar14 + 0x48);
      uVar3 = *(uint *)(iVar14 + 0x2c);
      uVar4 = *(undefined4 *)(iVar14 + 0x50);
      while( true ) {
        if (-1 < param_3) {
          iVar14 = (int)DAT_007e2314._2_2_;
          iVar10 = DAT_007e2334._2_2_ - iVar14;
          if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar10 + iVar14) {
            iVar10 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar14) + -1;
          }
          if (0 < iVar10) {
            param_1 = (undefined2 *)(local_8 + iVar14 * 2 + DAT_007e2c88);
            uVar11 = DAT_007e2310 * 0x10000 + (DAT_007e230c & 0xffff);
            uVar15 = DAT_007e2308;
            do {
              uVar12 = (uint)*(byte *)(iVar5 + ((uVar11 >> ((byte)uVar1 & 0x1f)) <<
                                               ((byte)uVar4 & 0x1f)) +
                                               ((uVar11 & 0xffff) >> ((byte)uVar2 & 0x1f)));
              if (uVar12 != uVar3) {
                *param_1 = *(undefined2 *)(iVar13 + ((uVar15 >> 0x14) + uVar12 * 0x10) * 2);
              }
              param_1 = param_1 + 1;
              uVar15 = uVar15 + iVar7;
              uVar11 = uVar11 + iVar9 * 0x10000 + (uVar8 & 0xffff);
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
        }
        param_3 = param_3 + 1;
        local_8 = local_8 + iVar6;
        if ((DAT_007e2328 < param_3) || (*(int *)(DAT_005d5a0c + 0x690) <= param_3)) break;
        DAT_007e2c98 = DAT_007e2c98 + -1;
        if (DAT_007e2c98 < 1) {
          DAT_007e2c8c = DAT_007e2c8c + -1;
          if (DAT_007e2c8c < 1) {
            return;
          }
          iVar14 = FUN_00428af0();
          if (iVar14 < 1) {
            return;
          }
        }
        else {
          DAT_007e2314 = DAT_007e2314 + DAT_007e2bc8;
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
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
