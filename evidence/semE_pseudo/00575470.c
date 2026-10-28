void __thiscall FUN_00575470(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0xa4);
  if (puVar2 == *(undefined4 **)(param_1 + 0xa8)) {
    FUN_00576170(puVar2,param_2);
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
    return;
  }
  if (puVar2 != (undefined4 *)0x0) {
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 0x18;
  *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
  return;
}


