int * __thiscall FUN_0054c2c0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (*param_1 - param_1[1]) / 0x18 + param_2;
  if ((-1 < iVar4) && (iVar4 < 0x15)) {
    *param_1 = *param_1 + param_2 * 0x18;
    return param_1;
  }
  if (iVar4 < 1) {
    iVar3 = -1 - (-iVar4 - 1U) / 0x15;
  }
  else {
    iVar3 = iVar4 / 0x15;
  }
  piVar1 = (int *)(param_1[3] + iVar3 * 4);
  param_1[3] = (int)piVar1;
  iVar2 = *piVar1;
  param_1[1] = iVar2;
  param_1[2] = iVar2 + 0x1f8;
  *param_1 = param_1[1] + (iVar4 + iVar3 * -0x15) * 0x18;
  return param_1;
}


