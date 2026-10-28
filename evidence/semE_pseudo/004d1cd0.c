void __thiscall FUN_004d1cd0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  if (puVar1 != (undefined4 *)(*(int *)(param_1 + 0x20) + -8)) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 8;
    return;
  }
  FUN_004d2370();
  return;
}


