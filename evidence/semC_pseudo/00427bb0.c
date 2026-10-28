void FUN_00427bb0(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  
  iVar9 = param_2;
  if (DAT_005c4628 == 0) {
    FUN_00427f50(param_1,param_2,param_3);
  }
  else {
    if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
      param_2 = param_1;
      param_1 = iVar9;
    }
    iVar9 = param_3;
    if (*(int *)(param_3 + 0x10) < *(int *)(param_1 + 0x10)) {
      iVar9 = param_1;
      param_1 = param_3;
    }
    iVar7 = iVar9;
    if (*(int *)(iVar9 + 0x10) < *(int *)(param_2 + 0x10)) {
      iVar7 = param_2;
      param_2 = iVar9;
    }
    iVar9 = *(int *)(param_1 + 0x10);
    if (((iVar9 < *(int *)(DAT_005d5a0c + 0x690)) && (-1 < *(int *)(iVar7 + 0x10))) &&
       (iVar2 = *(int *)(iVar7 + 0x10) - iVar9, iVar2 != 0)) {
      iVar2 = ((*(int *)(param_2 + 0x10) - iVar9) * 0x10000) / iVar2;
      iVar9 = (*(int *)(param_1 + 0xc) - *(int *)(param_2 + 0xc)) * 0x10000 +
              (*(int *)(iVar7 + 0xc) - *(int *)(param_1 + 0xc)) * iVar2;
      if (iVar9 != 0) {
        DAT_007e3340 = DAT_007e3340 + 1;
        _DAT_007e0ea0 = iVar7;
        _DAT_007e3390 = iVar7;
        if (iVar9 < 0) {
          DAT_007e0418 = 2;
          DAT_007e2c8c = 1;
          _DAT_007e0ea4 = param_1;
          _DAT_007e3394 = param_2;
          _DAT_007e3398 = param_1;
          iVar3 = FUN_00428920();
          if (iVar3 < 1) {
            return;
          }
          iVar3 = FUN_00428cf0();
          if (iVar3 < 1) {
            DAT_007e0418 = DAT_007e0418 + -1;
            iVar3 = FUN_00428cf0();
            if (iVar3 < 1) {
              return;
            }
          }
          if (-0x1000 < iVar9) {
            iVar9 = -0x1000;
          }
        }
        else {
          DAT_007e2c8c = 2;
          DAT_007e0418 = 1;
          _DAT_007e0ea4 = param_2;
          _DAT_007e0ea8 = param_1;
          _DAT_007e3394 = param_1;
          iVar3 = FUN_00428cf0();
          if (iVar3 < 1) {
            return;
          }
          iVar3 = FUN_00428920();
          if (iVar3 < 1) {
            DAT_007e2c8c = DAT_007e2c8c + -1;
            iVar3 = FUN_00428920();
            if (iVar3 < 1) {
              return;
            }
          }
          if (iVar9 < 0x1000) {
            iVar9 = 0x1000;
          }
        }
        iVar3 = FUN_00428d40((*(int *)(param_1 + 0x14) - *(int *)(param_2 + 0x14)) * 0x10000 +
                             (*(int *)(iVar7 + 0x14) - *(int *)(param_1 + 0x14)) * iVar2,iVar9);
        iVar2 = FUN_00428d40((*(int *)(param_1 + 0x28) - *(int *)(param_2 + 0x28)) * 0x10000 +
                             (*(int *)(iVar7 + 0x28) - *(int *)(param_1 + 0x28)) * iVar2,iVar9);
        iVar7 = DAT_007e28b0;
        param_1 = *(int *)(param_1 + 0x10);
        param_3 = DAT_007e28b0 * param_1;
        iVar9 = *(int *)(*(int *)(DAT_007e32ac + 0x3c) + 0xc);
        while( true ) {
          if (-1 < param_1) {
            iVar4 = (int)DAT_007e2314._2_2_;
            iVar5 = DAT_007e2334._2_2_ - iVar4;
            if (*(int *)(DAT_005d5a0c + 0x68c) <= iVar5 + iVar4) {
              iVar5 = (*(int *)(DAT_005d5a0c + 0x68c) - iVar4) + -1;
            }
            if (0 < iVar5) {
              puVar6 = (undefined2 *)(param_3 + iVar4 * 2 + DAT_007e2c88);
              puVar10 = (ushort *)
                        (*(int *)(DAT_007e28a4 + 0x34) +
                        (((param_1 - DAT_007e2340) * DAT_007e24e0 - DAT_007e2338) + iVar4) * 2);
              iVar4 = DAT_007e2318;
              uVar8 = DAT_007e2308;
              do {
                uVar1 = (ushort)((uint)iVar4 >> 0x10);
                if (uVar1 < *puVar10) {
                  *puVar10 = uVar1;
                  *puVar6 = *(undefined2 *)((uVar8 >> 0xf & 0xfffe) + iVar9);
                }
                puVar6 = puVar6 + 1;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + iVar3;
                uVar8 = uVar8 + iVar2;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
          }
          param_1 = param_1 + 1;
          param_3 = param_3 + iVar7;
          if ((DAT_007e2328 < param_1) || (*(int *)(DAT_005d5a0c + 0x690) <= param_1)) break;
          DAT_007e2c98 = DAT_007e2c98 + -1;
          if (DAT_007e2c98 < 1) {
            DAT_007e2c8c = DAT_007e2c8c + -1;
            if (DAT_007e2c8c < 1) {
              return;
            }
            iVar4 = FUN_00428920();
            if (iVar4 < 1) {
              return;
            }
          }
          else {
            DAT_007e2318 = DAT_007e2318 + DAT_007e2bd4;
            DAT_007e2314 = DAT_007e2314 + DAT_007e2bc8;
            DAT_007e2308 = DAT_007e2308 + DAT_007e2b80;
          }
          DAT_007e24d4 = DAT_007e24d4 + -1;
          if (DAT_007e24d4 < 1) {
            DAT_007e0418 = DAT_007e0418 + -1;
            if (DAT_007e0418 < 1) {
              return;
            }
            iVar4 = FUN_00428cf0();
            if (iVar4 < 1) {
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
