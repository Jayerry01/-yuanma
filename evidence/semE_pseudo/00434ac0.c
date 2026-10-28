void FUN_00434ac0(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      iVar1 = 0;
      if (0 < param_1[9]) {
        do {
          FUN_00433ea0(*(undefined4 *)(*param_1 + iVar1 * 4));
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_1[9]);
      }
      FUN_005089fd(*param_1);
    }
    FUN_005089fd(param_1);
  }
  return;
}


