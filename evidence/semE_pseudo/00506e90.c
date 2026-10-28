undefined4 * FUN_00506e90(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = param_2 - (int)param_1 >> 6;
  if (iVar1 < 1) {
    return param_3;
  }
  do {
    puVar2 = param_3 + 0x10;
    iVar1 = iVar1 + -1;
    puVar4 = param_1;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *param_3 = *puVar4;
      puVar4 = puVar4 + 1;
      param_3 = param_3 + 1;
    }
    param_3 = puVar2;
    param_1 = param_1 + 0x10;
  } while (iVar1 != 0);
  return puVar2;
}


