bool FUN_0052cd50(int *param_1,int param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_00530d00(0x509);
    return false;
  }
  if (param_1[5] != 0) {
    FUN_00530db0(param_1[5]);
  }
  *(byte *)(param_1 + 3) = param_5;
  *(byte *)((int)param_1 + 0xd) = param_6;
  iVar1 = (uint)param_5 * (uint)param_6 * param_2;
  param_1[4] = iVar1;
  iVar1 = iVar1 * param_3;
  param_1[7] = iVar1;
  iVar1 = iVar1 * param_4;
  param_1[2] = param_4;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[6] = iVar1;
  iVar1 = FUN_00530d80(iVar1);
  param_1[5] = iVar1;
  return iVar1 != 0;
}


