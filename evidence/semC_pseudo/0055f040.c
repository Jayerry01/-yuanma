int * __thiscall FUN_0055f040(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  if (param_2 != param_1) {
    iVar4 = param_2[1];
    puVar5 = (undefined4 *)*param_2;
    uVar1 = (iVar4 - (int)puVar5) / 0x18;
    local_8 = (undefined4 *)*param_1;
    if ((uint)((param_1[2] - (int)local_8) / 0x18) < uVar1) {
      iVar3 = FUN_0055f900(uVar1,puVar5,iVar4);
      iVar4 = (param_1[2] - *param_1) / 0x18;
      if (iVar4 != 0) {
        FUN_00402e90(*param_1,iVar4 * 0x18);
      }
      *param_1 = iVar3;
      param_1[2] = iVar3 + uVar1 * 0x18;
    }
    else {
      uVar2 = (param_1[1] - (int)local_8) / 0x18;
      if (uVar2 < uVar1) {
        iVar4 = (int)(uVar2 * 0x18) / 0x18;
        if (0 < iVar4) {
          do {
            puVar6 = puVar5;
            puVar7 = local_8;
            for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            local_8 = local_8 + 6;
            iVar4 = iVar4 + -1;
            puVar5 = puVar5 + 6;
          } while (iVar4 != 0);
        }
        FUN_00560120(*param_2 + ((param_1[1] - *param_1) / 0x18) * 0x18,param_2[1],param_1[1],
                     param_2);
      }
      else {
        iVar4 = (iVar4 - (int)puVar5) / 0x18;
        if (0 < iVar4) {
          do {
            puVar6 = puVar5;
            puVar7 = local_8;
            for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar5 = puVar5 + 6;
            local_8 = local_8 + 6;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
    }
    param_1[1] = *param_1 + uVar1 * 0x18;
  }
  return param_1;
}


