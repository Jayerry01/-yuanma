void __thiscall FUN_00593450(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar1 != *(undefined4 **)(param_1 + 0x20)) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_2;
    }
    iVar2 = *(int *)(param_1 + 0x1c) + 4;
    *(int *)(param_1 + 0x1c) = iVar2;
    *(int *)(param_1 + 0x24) = iVar2 - *(int *)(param_1 + 0x18) >> 2;
    return;
  }
  FUN_00578e10(puVar1,&param_2);
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2;
  return;
}


