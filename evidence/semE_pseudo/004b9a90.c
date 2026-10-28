void __fastcall FUN_004b9a90(int param_1)

{
  undefined4 *puVar1;
  
  FUN_004ed900();
  puVar1 = *(undefined4 **)(param_1 + 0x3c8 + *(int *)(param_1 + 0x3f0) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
    *(undefined4 *)(param_1 + 0x3c8 + *(int *)(param_1 + 0x3f0) * 4) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x3c8 + *(int *)(param_1 + 0x3f0) * 4) = 0;
  return;
}


