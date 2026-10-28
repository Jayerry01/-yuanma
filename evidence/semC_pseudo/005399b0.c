void FUN_005399b0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_c;
  int local_8;
  int *local_4;
  
  local_c = param_2;
  param_2 = param_2 - param_1;
  if (param_2 < -1) {
    param_2 = -1;
  }
  local_8 = param_1 + local_c;
  if (0x100 < local_8) {
    local_8 = 0x100;
  }
  iVar1 = local_c + -1;
  local_c = local_c + 1;
  piVar3 = &DAT_007232fc + iVar1 * 4;
  local_4 = &DAT_0072ce80;
  piVar5 = &DAT_007232fc + local_c * 4;
  iVar4 = local_c;
  param_1 = iVar1;
  while ((iVar4 < local_8 || (param_2 < iVar1))) {
    local_4 = local_4 + 1;
    iVar2 = *local_4;
    if (iVar4 < local_8) {
      iVar1 = (piVar5[-1] - param_3) * iVar2;
      piVar5[-1] = piVar5[-1] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (*piVar5 - param_4) * iVar2;
      *piVar5 = *piVar5 - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (piVar5[1] - param_5) * iVar2;
      iVar4 = local_c + 1;
      piVar5[1] = piVar5[1] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      piVar5 = piVar5 + 4;
      iVar1 = param_1;
      local_c = iVar4;
    }
    if (param_2 < iVar1) {
      iVar1 = (piVar3[-1] - param_3) * iVar2;
      piVar3[-1] = piVar3[-1] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (*piVar3 - param_4) * iVar2;
      *piVar3 = *piVar3 - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar2 = (piVar3[1] - param_5) * iVar2;
      iVar1 = param_1 + -1;
      piVar3[1] = piVar3[1] - ((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffffU)) >> 0x12);
      piVar3 = piVar3 + -4;
      iVar4 = local_c;
      param_1 = iVar1;
    }
  }
  return;
}


