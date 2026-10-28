uint __fastcall FUN_005088cd(int *param_1)

{
  uint uVar1;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      (**(code **)(*param_1 + 0x20))();
    }
    uVar1 = (**(code **)(*param_1 + 0x20))();
    param_1[3] = uVar1;
    return uVar1;
  }
  if ((param_1[0xb] == 0) || ((uint)param_1[0xb] <= (uint)param_1[10])) {
    (**(code **)(*param_1 + 0x20))();
  }
  param_1[10] = param_1[10] + 1;
  if ((byte *)param_1[10] < (byte *)param_1[0xb]) {
    return (uint)*(byte *)param_1[10];
  }
  uVar1 = (**(code **)(*param_1 + 0x20))();
  return uVar1;
}


