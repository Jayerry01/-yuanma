undefined4 __thiscall FUN_004a7290(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1[0x72] != 0) {
    if (*(int *)(param_1[0x72] + param_1[0x76] * 4) == 0) {
      (**(code **)(*param_1 + 0x10c))();
    }
    puVar2 = *(undefined4 **)(param_1[0x72] + param_1[0x76] * 4);
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    return 0;
  }
  return 0xffffffff;
}


