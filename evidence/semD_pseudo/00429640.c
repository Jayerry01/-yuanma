undefined4 FUN_00429640(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((DAT_005d5a58 == 0) || (DAT_005d5a94 == 0)) {
    return 0;
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = &DAT_007e2ca0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_1;
      param_1 = param_1 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = &DAT_007e2ea0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    puVar2 = &DAT_007e30a0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  if (DAT_005d5a5c != 0) {
    (**(code **)(**(int **)(DAT_005d5a0c + 0x700) + 0x10))(*(int **)(DAT_005d5a0c + 0x700),1);
    return 1;
  }
  (**(code **)(**(int **)(DAT_005d5a0c + 0x700) + 0x10))
            (*(int **)(DAT_005d5a0c + 0x700),0,&DAT_007e2ca0);
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
