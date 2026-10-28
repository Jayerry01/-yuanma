undefined4 __thiscall FUN_0044ee60(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    return 1;
  }
  if (*(int **)(param_1 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x38) + 4))(param_2);
    (**(code **)(**(int **)(param_1 + 0x38) + 8))(param_2);
  }
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    return 1;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0xc))(param_2);
  if (iVar1 == 1) {
    (**(code **)(**(int **)(param_1 + 4) + 0x58))(0);
    iVar1 = FUN_00463190();
    if (iVar1 == 0) goto LAB_0044eedd;
    uVar2 = FUN_00463190();
  }
  else {
    if (iVar1 != 2) {
      return 1;
    }
    (**(code **)(**(int **)(param_1 + 4) + 0x58))(0);
    iVar1 = FUN_00463010();
    if (iVar1 == 0) goto LAB_0044eedd;
    uVar2 = FUN_00463010();
  }
  *(undefined4 *)(param_1 + 4) = uVar2;
LAB_0044eedd:
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 0x58))(1);
    FUN_0046a4d0();
  }
  return 1;
}


