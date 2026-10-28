undefined4 __thiscall FUN_004a5650(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (((((param_1[0x118] <= param_2) || (param_2 < 0)) || (param_1[0x7d] == 0)) ||
      (*(int *)(param_1[0x7d] + param_2 * 4) == 0)) ||
     ((param_3 == 2 &&
      ((iVar1 = param_1[0x10e] + param_2 * 0x18,
       *(int *)(iVar1 + 0x10) < *(int *)(param_1[0x10e] + 4 + param_2 * 0x18) ||
       (*(int *)(iVar1 + 8) < *(int *)(iVar1 + 0x14))))))) {
    return 0;
  }
  param_1[0x54] = 0;
  if (param_4 != 0) {
    if (param_4 == 0x10) {
      param_1[100] = 0;
      param_1[0x75] = param_2;
      iVar1 = *param_1;
      piVar3 = (int *)(param_1[0x10e] + param_2 * 0x18);
      piVar4 = param_1 + 0x55;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      (**(code **)(iVar1 + 0x50))(param_1[0x56]);
      if (param_3 != -1) {
        param_1[0x74] = param_3;
      }
      param_1[0x10a] = -1;
      param_1[0x5c] = 0;
      return 1;
    }
    if (param_4 != 0x20) {
      return 1;
    }
    param_1[0x5c] = 0x3f800000;
    param_1[0x5d] = (int)(1.0 / (float)(param_1[0x57] - param_1[0x76]));
  }
  param_1[0x74] = 0;
  param_1[0x10a] = param_2;
  if (param_3 == -1) {
    param_1[0x10b] = -1;
    return 1;
  }
  param_1[0x10b] = param_3;
  return 1;
}


