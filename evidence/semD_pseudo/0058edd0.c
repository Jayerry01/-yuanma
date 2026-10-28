void __fastcall FUN_0058edd0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2 != 0) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x80) + uVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
        *(undefined4 *)(*(int *)(param_1 + 0x80) + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2));
  }
  *(int *)(param_1 + 0x84) =
       *(int *)(param_1 + 0x84) + (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2) * -4;
  return;
}


