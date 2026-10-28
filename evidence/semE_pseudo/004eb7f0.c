void FUN_004eb7f0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      puVar2 = param_3;
      puVar3 = param_1;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      param_1 = param_1 + 8;
      param_3 = param_3 + 6;
    } while (param_2 != 0);
  }
  return;
}


