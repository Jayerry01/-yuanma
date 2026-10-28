void __thiscall FUN_00571600(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x2c);
  if (puVar1 != *(undefined4 **)(param_1 + 0x30)) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_2;
    }
    iVar2 = *(int *)(param_1 + 0x2c) + 4;
    *(int *)(param_1 + 0x2c) = iVar2;
    *(int *)(param_1 + 0x24) = iVar2 - *(int *)(param_1 + 0x28) >> 2;
    return;
  }
  FUN_005716f0(puVar1,&param_2);
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28) >> 2;
  return;
}


