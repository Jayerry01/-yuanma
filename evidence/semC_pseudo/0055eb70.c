int * __thiscall FUN_0055eb70(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_4;
  
  if (param_2 != param_1) {
    iVar5 = param_2[1];
    puVar7 = (undefined4 *)*param_2;
    puVar4 = (undefined4 *)*param_1;
    uVar1 = (iVar5 - (int)puVar7) / 0xc;
    if ((uint)((param_1[2] - (int)puVar4) / 0xc) < uVar1) {
      iVar3 = FUN_0055f1e0(uVar1,puVar7,iVar5);
      iVar5 = param_1[1];
      for (iVar6 = *param_1; iVar6 != iVar5; iVar6 = iVar6 + 0xc) {
        FUN_004026e0();
      }
      iVar5 = (param_1[2] - *param_1) / 0xc;
      if (iVar5 != 0) {
        FUN_00402e90(*param_1,iVar5 * 0xc);
      }
      *param_1 = iVar3;
      param_1[2] = iVar3 + uVar1 * 0xc;
    }
    else {
      uVar2 = (param_1[1] - (int)puVar4) / 0xc;
      if (uVar2 < uVar1) {
        local_4 = (int)(uVar2 * 0xc) / 0xc;
        if (0 < local_4) {
          do {
            if (puVar7 != puVar4) {
              FUN_00403200(*puVar7,puVar7[1]);
            }
            puVar7 = puVar7 + 3;
            puVar4 = puVar4 + 3;
            local_4 = local_4 + -1;
          } while (local_4 != 0);
        }
        FUN_0055fe10(*param_2 + ((param_1[1] - *param_1) / 0xc) * 0xc,param_2[1],param_1[1],uVar1);
      }
      else {
        iVar5 = (iVar5 - (int)puVar7) / 0xc;
        if (0 < iVar5) {
          do {
            FUN_00473340(puVar7);
            puVar7 = puVar7 + 3;
            puVar4 = puVar4 + 3;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        puVar7 = (undefined4 *)param_1[1];
        for (; puVar4 != puVar7; puVar4 = puVar4 + 3) {
          FUN_004026e0();
        }
      }
    }
    param_1[1] = *param_1 + uVar1 * 0xc;
  }
  return param_1;
}


