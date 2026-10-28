void FUN_00430980(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      FUN_005089fd(param_1[1]);
      FUN_005089fd(param_1);
      return;
    }
    if (iVar1 == 3) {
      FUN_005089fd(*(undefined4 *)param_1[1]);
      FUN_005089fd(param_1[1]);
      FUN_005089fd(param_1);
      return;
    }
    if (iVar1 == 4) {
      FUN_005089fd(param_1[1]);
      FUN_005089fd(param_1);
      return;
    }
    if (iVar1 != 5) goto LAB_004309fc;
  }
  FUN_005089fd(param_1[1]);
LAB_004309fc:
  FUN_005089fd(param_1);
  return;
}


