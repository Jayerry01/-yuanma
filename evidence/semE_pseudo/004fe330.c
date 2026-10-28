void __thiscall FUN_004fe330(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 4) - param_3 >> 2;
  if (0 < iVar1) {
    puVar2 = param_2;
    do {
      *puVar2 = *(undefined4 *)((param_3 - (int)param_2) + (int)puVar2);
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - (int)param_2 >> 2) * -4;
  return;
}


