void FUN_00425e00(undefined2 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int local_8;
  
  iVar12 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)((int)param_1 + 0x10)) {
    param_2 = (int)param_1;
    param_1 = (undefined2 *)iVar12;
  }
  iVar12 = param_3;
  if (*(int *)(param_3 + 0x10) < *(int *)((int)param_1 + 0x10)) {
    iVar12 = (int)param_1;
    param_1 = (undefined2 *)param_3;
  }
  iVar11 = iVar12;
  if (*(int *)(iVar12 + 0x10) < *(int *)(param_2 + 0x10)) {
    iVar11 = param_2;
    param_2 = iVar12;
  }
  iVar12 = *(int *)((int)param_1 + 0x10);
  if (((iVar12 < *(int *)(DAT_005d5a0c + 0x690)) && (-1 < *(int *)(iVar11 + 0x10))) &&
     (iVar4 = *(int *)(iVar11 + 0x10) - iVar12, iVar4 != 0)) {
    iVar4 = ((*(int *)(param_2 + 0x10) - iVar12) * 0x10000) / iVar4;
    iVar12 = (*(int *)((int)param_1 + 0xc) - *(int *)(param_2 + 0xc)) * 0x10000 +
             (*(int *)(iVar11 + 0xc) - *(int *)((int)param_1 + 0xc)) * iVar4;
    if (iVar12 != 0) {
      DAT_007e3340 = DAT_007e3340 + 1;
      _DAT_007e0ea0 = iVar11;
      _DAT_007e3390 = iVar11;
      if (iVar12 < 0) {
        DAT_007e0418 = 2;
        DAT_007e2c8c = 1;
        _DAT_007e0ea4 = (int)param_1;
        _DAT_007e3394 = param_2;
        _DAT_007e3398 = (int)param_1;
        iVar5 = FUN_00428af0();
        if (iVar5 < 1) {
          return;
        }
        iVar5 = FUN_00428cf0();
        if (iVar5 < 1) {
          DAT_007e0418 = DAT_007e0418 + -1;
          iVar5 = FUN_00428cf0();
          if (iVar5 < 1) {
            return;
          }
        }
        if (-0x1000 < iVar12) {
          iVar12 = -0x1000;
        }
      }
      else {
        DAT_007e2c8c = 2;
        DAT_007e0418 = 1;
        _DAT_007e0ea4 = param_2;
        _DAT_007e0ea8 = (int)param_1;
        _DAT_007e3394 = (int)param_1;
        iVar5 = FUN_00428cf0();
        if (iVar5 < 1) {
          return;
        }
        iVar5 = FUN_00428af0();
        if (iVar5 < 1) {
          DAT_007e2c8c = DAT_007e2c8c + -1;
          iVar5 = FUN_00428af0();
          if (iVar5 < 1) {
            return;
          }
        }
        if (iVar12 < 0x1000) {
          iVar12 = 0x1000;
        }
      }
      iVar6 = FUN_00428d40((*(int *)((int)param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                           (*(int *)(iVar11 + 0x28) - *(int *)((int)param_1 + 0x28)) * iVar4,iVar12)
      ;
      uVar7 = FUN_00428d70((*(int *)((int)param_1 + 0x20) - *(int *)(param_2 + 0x20)) * 0x10000 +
                           (*(int *)(iVar11 + 0x20) - *(int *)((int)param_1 + 0x20)) * iVar4,iVar12)
      ;
      iVar8 = FUN_00428d70((*(int *)((int)param_1 + 0x24) - *(int *)(param_2 + 0x24)) * 0x10000 +
                           (*(int *)(iVar11 + 0x24) - *(int *)((int)param_1 + 0x24)) * iVar4,iVar12)
      ;
      iVar5 = DAT_007e28b0;
      param_3 = *(int *)((int)param_1 + 0x10);
      iVar12 = *(int *)(DAT_007e32ac + 0x34);
      local_8 = DAT_007e28b0 * param_3;
      iVar11 = *(int *)(iVar12 + 0x54);
      iVar4 = *(int *)(iVar12 + 0x58);
      uVar1 = *(undefined4 *)(iVar12 + 0x4c);
      uVar2 = *(undefined4 *)(iVar12 + 0x48);
      uVar3 = *(undefined4 *)(iVar12 + 0x50);
      while( true ) {
        if (-1 < param_3) {
          iVar12 = (int)DAT_007e2314._2_2_;
          iVar9 = DAT_007e2334._2_2_ - iVar12;
          if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar9 + iVar12) {
            iVar9 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar12) + -1;
          }
          if (0 < iVar9) {
            param_1 = (undefined2 *)(local_8 + iVar12 * 2 + DAT_007e2c88);
            uVar10 = DAT_007e2310 * 0x10000 + (DAT_007e230c & 0xffff);
            uVar13 = DAT_007e2308;
            do {
              *param_1 = *(undefined2 *)
                          (iVar11 + ((uVar13 >> 0x14) +
                                    (uint)*(byte *)(iVar4 + ((uVar10 >> ((byte)uVar1 & 0x1f)) <<
                                                            ((byte)uVar3 & 0x1f)) +
                                                            ((uVar10 & 0xffff) >>
                                                            ((byte)uVar2 & 0x1f))) * 0x10) * 2);
              param_1 = param_1 + 1;
              uVar13 = uVar13 + iVar6;
              uVar10 = uVar10 + iVar8 * 0x10000 + (uVar7 & 0xffff);
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        param_3 = param_3 + 1;
        local_8 = local_8 + iVar5;
        if ((DAT_007e2328 < param_3) || (*(int *)(DAT_005d5a0c + 0x690) <= param_3)) break;
        DAT_007e2c98 = DAT_007e2c98 + -1;
        if (DAT_007e2c98 < 1) {
          DAT_007e2c8c = DAT_007e2c8c + -1;
          if (DAT_007e2c8c < 1) {
            return;
          }
          iVar12 = FUN_00428af0();
          if (iVar12 < 1) {
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
          iVar12 = FUN_00428cf0();
          if (iVar12 < 1) {
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
