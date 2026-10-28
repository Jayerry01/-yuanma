undefined4 __thiscall FUN_00569330(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1[0x48] + 8))) {
    if (param_2 == param_1[0x4e]) {
      return 1;
    }
    param_1[0x4d] = param_2;
    param_1[0x4e] = param_2;
    iVar1 = 0;
    param_1[0x4f] = (float)param_2;
    param_1[0x50] = (float)param_2;
    if (0 < *(int *)(param_1[0x48] + 0x38)) {
      do {
        FUN_0057e590(param_2,param_1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1[0x48] + 0x38));
    }
    iVar1 = 0;
    if (0 < *(int *)(param_1[0x48] + 0x40)) {
      do {
        FUN_0057e590(param_2,param_1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1[0x48] + 0x40));
    }
    (**(code **)*param_1)();
    return 1;
  }
  return 0;
}


