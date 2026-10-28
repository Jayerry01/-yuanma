int * __thiscall FUN_0055ee90(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  if (param_2 != param_1) {
    iVar4 = param_2[1];
    iVar5 = *param_2;
    iVar3 = *param_1;
    uVar1 = (iVar4 - iVar5) / 0x68;
    if ((uint)((param_1[2] - iVar3) / 0x68) < uVar1) {
      iVar3 = FUN_0055f6a0(uVar1,iVar5,iVar4);
      iVar4 = param_1[1];
      for (iVar5 = *param_1; iVar5 != iVar4; iVar5 = iVar5 + 0x68) {
        FUN_005601b0();
      }
      iVar4 = (param_1[2] - *param_1) / 0x68;
      if (iVar4 != 0) {
        FUN_00402e90(*param_1,iVar4 * 0x68);
      }
      *param_1 = iVar3;
      param_1[2] = iVar3 + uVar1 * 0x68;
    }
    else {
      uVar2 = (param_1[1] - iVar3) / 0x68;
      if (uVar2 < uVar1) {
        local_4 = (int)(uVar2 * 0x68) / 0x68;
        if (0 < local_4) {
          do {
            FUN_0055fb60(iVar5);
            iVar5 = iVar5 + 0x68;
            local_4 = local_4 + -1;
          } while (local_4 != 0);
        }
        FUN_0055ff50(*param_2 + ((param_1[1] - *param_1) / 0x68) * 0x68,param_2[1],param_1[1],uVar1)
        ;
      }
      else {
        iVar4 = (iVar4 - iVar5) / 0x68;
        if (0 < iVar4) {
          do {
            FUN_0055fb60(iVar5);
            iVar5 = iVar5 + 0x68;
            iVar3 = iVar3 + 0x68;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar4 = param_1[1];
        for (; iVar3 != iVar4; iVar3 = iVar3 + 0x68) {
          FUN_005601b0();
        }
      }
    }
    param_1[1] = *param_1 + uVar1 * 0x68;
  }
  return param_1;
}


