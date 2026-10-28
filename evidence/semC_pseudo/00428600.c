void FUN_00428600(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  iVar8 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
    param_2 = param_1;
    param_1 = iVar8;
  }
  iVar8 = param_3;
  if (*(int *)(param_3 + 0x10) < *(int *)(param_1 + 0x10)) {
    iVar8 = param_1;
    param_1 = param_3;
  }
  iVar6 = iVar8;
  if (*(int *)(iVar8 + 0x10) < *(int *)(param_2 + 0x10)) {
    iVar6 = param_2;
    param_2 = iVar8;
  }
  iVar8 = *(int *)(param_1 + 0x10);
  if (((iVar8 < *(int *)(DAT_005d5a0c + 0x690)) && (-1 < *(int *)(iVar6 + 0x10))) &&
     (iVar1 = *(int *)(iVar6 + 0x10) - iVar8, iVar1 != 0)) {
    iVar1 = ((*(int *)(param_2 + 0x10) - iVar8) * 0x10000) / iVar1;
    iVar8 = (*(int *)(param_1 + 0xc) - *(int *)(param_2 + 0xc)) * 0x10000 +
            (*(int *)(iVar6 + 0xc) - *(int *)(param_1 + 0xc)) * iVar1;
    if (iVar8 != 0) {
      DAT_007e3340 = DAT_007e3340 + 1;
      _DAT_007e0ea0 = iVar6;
      _DAT_007e3390 = iVar6;
      if (iVar8 < 0) {
        DAT_007e0418 = 2;
        DAT_007e2c8c = 1;
        _DAT_007e0ea4 = param_1;
        _DAT_007e3394 = param_2;
        _DAT_007e3398 = param_1;
        iVar2 = FUN_004289b0();
        if (iVar2 < 1) {
          return;
        }
        iVar2 = FUN_00428cf0();
        if (iVar2 < 1) {
          DAT_007e0418 = DAT_007e0418 + -1;
          iVar2 = FUN_00428cf0();
          if (iVar2 < 1) {
            return;
          }
        }
        if (-0x1000 < iVar8) {
          iVar8 = -0x1000;
        }
      }
      else {
        DAT_007e2c8c = 2;
        DAT_007e0418 = 1;
        _DAT_007e0ea4 = param_2;
        _DAT_007e0ea8 = param_1;
        _DAT_007e3394 = param_1;
        iVar2 = FUN_00428cf0();
        if (iVar2 < 1) {
          return;
        }
        iVar2 = FUN_004289b0();
        if (iVar2 < 1) {
          DAT_007e2c8c = DAT_007e2c8c + -1;
          iVar2 = FUN_004289b0();
          if (iVar2 < 1) {
            return;
          }
        }
        if (iVar8 < 0x1000) {
          iVar8 = 0x1000;
        }
      }
      iVar2 = FUN_00428d40((*(int *)(param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                           (*(int *)(iVar6 + 0x28) - *(int *)(param_1 + 0x28)) * iVar1,iVar8);
      iVar1 = DAT_007e28b0;
      iVar8 = *(int *)(*(int *)(DAT_007e32ac + 0x3c) + 0xc);
      iVar6 = *(int *)(param_1 + 0x10);
      param_2 = DAT_007e28b0 * iVar6;
      while( true ) {
        if (-1 < iVar6) {
          iVar3 = (int)DAT_007e2314._2_2_;
          iVar4 = DAT_007e2334._2_2_ - iVar3;
          if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar4 + iVar3) {
            iVar4 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar3) + -1;
          }
          if (1 < iVar4) {
            puVar5 = (undefined2 *)(param_2 + iVar3 * 2 + DAT_007e2c88);
            bVar9 = iVar3 + iVar6 == (iVar3 + iVar6 & 0xfffffffeU);
            uVar7 = DAT_007e2308;
            do {
              bVar9 = (bool)(bVar9 ^ 1);
              if (bVar9) {
                *puVar5 = *(undefined2 *)((uVar7 >> 0xf & 0xfffe) + iVar8);
              }
              puVar5 = puVar5 + 1;
              uVar7 = uVar7 + iVar2;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        param_2 = param_2 + iVar1;
        iVar6 = iVar6 + 1;
        if ((DAT_007e2328 < iVar6) || (*(int *)(DAT_005d5a0c + 0x690) <= iVar6)) break;
        DAT_007e2c98 = DAT_007e2c98 + -1;
        if (DAT_007e2c98 < 1) {
          DAT_007e2c8c = DAT_007e2c8c + -1;
          if (DAT_007e2c8c < 1) {
            return;
          }
          iVar3 = FUN_004289b0();
          if (iVar3 < 1) {
            return;
          }
        }
        else {
          DAT_007e2314 = DAT_007e2314 + DAT_007e2bc8;
          DAT_007e2308 = DAT_007e2308 + DAT_007e2b80;
        }
        DAT_007e24d4 = DAT_007e24d4 + -1;
        if (DAT_007e24d4 < 1) {
          DAT_007e0418 = DAT_007e0418 + -1;
          if (DAT_007e0418 < 1) {
            return;
          }
          iVar3 = FUN_00428cf0();
          if (iVar3 < 1) {
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


