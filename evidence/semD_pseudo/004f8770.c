void FUN_004f8770(undefined4 *param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *param_3 = *param_1;
  iVar1 = 2;
  iVar4 = param_2 - (int)param_1 >> 2;
  iVar2 = 0;
  iVar3 = iVar2;
  if (2 < iVar4) {
    do {
      iVar2 = iVar1;
      if (*(float *)(param_1[iVar1 + -1] + 0xc) < *(float *)(param_1[iVar1] + 0xc)) {
        iVar2 = iVar1 + -1;
      }
      param_1[iVar3] = param_1[iVar2];
      iVar1 = iVar2 * 2 + 2;
      iVar3 = iVar2;
    } while (iVar1 < iVar4);
  }
  if (iVar1 == iVar4) {
    param_1[iVar2] = param_1[iVar1 + -1];
    iVar2 = iVar1 + -1;
  }
  if (iVar2 < 1) {
    param_1[iVar2] = param_4;
    return;
  }
  do {
    iVar1 = (iVar2 + -1) / 2;
    if (*(float *)(param_1[iVar1] + 0xc) <= *(float *)(param_4 + 0xc)) break;
    param_1[iVar2] = param_1[iVar1];
    iVar2 = iVar1;
  } while (0 < iVar1);
  param_1[iVar2] = param_4;
  return;
}


