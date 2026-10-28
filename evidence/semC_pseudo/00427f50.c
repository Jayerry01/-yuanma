void FUN_00427f50(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
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
      iVar1 = FUN_00428d40((*(int *)(param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                           (*(int *)(iVar6 + 0x28) - *(int *)(param_1 + 0x28)) * iVar1,iVar8);
      iVar6 = DAT_007e28b0;
      param_1 = *(int *)(param_1 + 0x10);
      iVar2 = DAT_007e28b0 * param_1;
      iVar8 = *(int *)(*(int *)(DAT_007e32ac + 0x3c) + 0xc);
      while( true ) {
        if (-1 < param_1) {
          iVar3 = (int)DAT_007e2314._2_2_;
          iVar5 = DAT_007e2334._2_2_ - iVar3;
          if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar5 + iVar3) {
            iVar5 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar3) + -1;
          }
          if (0 < iVar5) {
            puVar4 = (undefined2 *)(iVar2 + iVar3 * 2 + DAT_007e2c88);
            uVar7 = DAT_007e2308;
            do {
              *puVar4 = *(undefined2 *)((uVar7 >> 0xf & 0xfffe) + iVar8);
              puVar4 = puVar4 + 1;
              uVar7 = uVar7 + iVar1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
        }
        param_1 = param_1 + 1;
        iVar2 = iVar2 + iVar6;
        if ((DAT_007e2328 < param_1) || (*(int *)(DAT_005d5a0c + 0x690) <= param_1)) break;
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
