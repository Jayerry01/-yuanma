void FUN_00415d50(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_005089fd(*(int *)(param_1 + 0xc));
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    FUN_005089fd(param_1);
  }
  return;
}


