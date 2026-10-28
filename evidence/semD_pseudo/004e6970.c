void __thiscall FUN_004e6970(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar3 = param_1[2];
  piVar4 = (int *)param_1[3];
  iVar5 = param_1[1];
  iVar2 = (*param_1 - iVar5) / 0xc + param_3;
  if ((iVar2 < 0) || (0x29 < iVar2)) {
    if (iVar2 < 1) {
      iVar1 = -1 - (-iVar2 - 1U) / 0x2a;
    }
    else {
      iVar1 = iVar2 / 0x2a;
    }
    piVar4 = piVar4 + iVar1;
    iVar5 = *piVar4;
    iVar3 = iVar5 + 0x1f8;
    iVar2 = iVar5 + (iVar2 + iVar1 * -0x2a) * 0xc;
  }
  else {
    iVar2 = *param_1 + param_3 * 0xc;
  }
  param_2[1] = iVar5;
  *param_2 = iVar2;
  param_2[3] = (int)piVar4;
  param_2[2] = iVar3;
  return;
}


