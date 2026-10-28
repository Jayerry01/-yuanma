void FUN_005771e0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = (param_2 - (int)param_1) / 0x18;
  if (0 < iVar2) {
    do {
      iVar2 = iVar2 + -1;
      puVar3 = param_1;
      puVar4 = param_3;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      param_3 = param_3 + 6;
      param_1 = param_1 + 6;
    } while (iVar2 != 0);
  }
  return;
}


