undefined4 __thiscall FUN_005693f0(undefined4 *param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((0.0 <= param_2) &&
     (iVar4 = param_1[0x48], fVar1 = (float)*(int *)(iVar4 + 8),
     fVar1 < param_2 == (fVar1 == param_2))) {
    if (param_2 == (float)param_1[0x50]) {
      return 1;
    }
    param_1[0x4f] = param_2;
    uVar2 = __ftol();
    param_1[0x4d] = uVar2;
    param_1[0x50] = param_2;
    param_1[0x4e] = uVar2;
    iVar3 = 0;
    if (0 < *(int *)(iVar4 + 0x38)) {
      do {
        FUN_0057e810(param_2,param_1);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1[0x48] + 0x38));
    }
    iVar4 = 0;
    if (0 < *(int *)(param_1[0x48] + 0x40)) {
      do {
        FUN_0057e810(param_2,param_1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1[0x48] + 0x40));
    }
    (**(code **)*param_1)();
    return 1;
  }
  return 0;
}


