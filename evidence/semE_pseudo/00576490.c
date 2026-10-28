undefined4 * FUN_00576490(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = (param_2 - param_1) / 0xc;
  if (0 < iVar3) {
    param_1 = param_1 - (int)param_3;
    puVar2 = param_3;
    do {
      puVar1 = (undefined4 *)(param_1 + (int)puVar2);
      param_3 = puVar2 + 3;
      iVar3 = iVar3 + -1;
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      puVar2[2] = puVar1[2];
      puVar2 = param_3;
    } while (iVar3 != 0);
  }
  return param_3;
}


