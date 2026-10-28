void FUN_004157a0(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x54) != 0) {
      FUN_005089fd(*(int *)(param_1 + 0x54));
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    if (*(int *)(param_1 + 0x58) != 0) {
      FUN_005089fd(*(int *)(param_1 + 0x58));
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
  }
  return;
}


