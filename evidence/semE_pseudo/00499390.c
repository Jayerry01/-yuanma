void __thiscall FUN_00499390(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  if (puVar1 != (undefined4 *)(*(int *)(param_1 + 0x20) + -0xc)) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
      puVar1[2] = param_2[2];
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 0xc;
    return;
  }
  FUN_0049cc80();
  return;
}


