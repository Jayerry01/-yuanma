undefined4 * FUN_00577350(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int local_8;
  
  local_8 = (param_2 - param_1) / 0x68;
  if (local_8 < 1) {
    return param_3;
  }
  piVar7 = param_3 + 4;
  piVar9 = (int *)(param_2 + 0x10);
  do {
    puVar1 = (undefined4 *)(param_2 + -0x68);
    param_2 = param_2 + -0x68;
    param_3 = param_3 + -0x1a;
    piVar10 = piVar9 + -0x1a;
    piVar8 = piVar7 + -0x1a;
    *param_3 = *puVar1;
    piVar7[-0x1d] = piVar9[-0x1d];
    piVar7[-0x1c] = piVar9[-0x1c];
    piVar7[-0x1b] = piVar9[-0x1b];
    if (piVar10 != piVar8) {
      iVar2 = piVar9[-0x19];
      iVar6 = *piVar10;
      iVar5 = *piVar8;
      uVar3 = (iVar2 - iVar6) / 0xc;
      if ((uint)((piVar7[-0x18] - iVar5) / 0xc) < uVar3) {
        iVar5 = FUN_0055f1e0(uVar3,iVar6,iVar2);
        iVar2 = piVar7[-0x19];
        for (iVar6 = *piVar8; iVar6 != iVar2; iVar6 = iVar6 + 0xc) {
          FUN_0047a7e0(0);
        }
        iVar2 = (piVar7[-0x18] - *piVar8) / 0xc;
        if (iVar2 != 0) {
          FUN_00402e90(*piVar8,iVar2 * 0xc);
        }
        *piVar8 = iVar5;
        piVar7[-0x18] = iVar5 + uVar3 * 0xc;
      }
      else {
        uVar4 = (piVar7[-0x19] - iVar5) / 0xc;
        if (uVar4 < uVar3) {
          FUN_00552510(iVar6,iVar6 + uVar4 * 0xc,iVar5,param_3,0);
          FUN_0055fe10(*piVar10 + ((piVar7[-0x19] - *piVar8) / 0xc) * 0xc,piVar9[-0x19],
                       piVar7[-0x19],param_3);
        }
        else {
          iVar6 = FUN_00552510(iVar6,iVar2,iVar5,param_3,0);
          iVar2 = piVar7[-0x19];
          for (; iVar6 != iVar2; iVar6 = iVar6 + 0xc) {
            FUN_0047a7e0(0);
          }
        }
      }
      piVar7[-0x19] = *piVar8 + uVar3 * 0xc;
    }
    FUN_004c7210(piVar9 + -0x17);
    piVar7[-0x14] = piVar9[-0x14];
    piVar7[-0x13] = piVar9[-0x13];
    piVar7[-0x12] = piVar9[-0x12];
    piVar7[-0x11] = piVar9[-0x11];
    piVar7[-0x10] = piVar9[-0x10];
    piVar7[-0xf] = piVar9[-0xf];
    piVar7[-0xe] = piVar9[-0xe];
    piVar7[-0xd] = piVar9[-0xd];
    piVar7[-0xc] = piVar9[-0xc];
    piVar7[-0xb] = piVar9[-0xb];
    piVar7[-10] = piVar9[-10];
    piVar7[-9] = piVar9[-9];
    piVar7[-8] = piVar9[-8];
    piVar7[-7] = piVar9[-7];
    piVar7[-6] = piVar9[-6];
    local_8 = local_8 + -1;
    piVar7[-5] = piVar9[-5];
    piVar7 = piVar8;
    piVar9 = piVar10;
  } while (local_8 != 0);
  return param_3;
}


