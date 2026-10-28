undefined4 __fastcall FUN_00578c10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 == 0) {
    return *(undefined4 *)(param_1 + 8);
  }
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 4)) {
    do {
      (**(code **)(**(int **)(*(int *)(iVar1 + 8) + iVar3 * 4) + 4))();
      iVar1 = *(int *)(param_1 + 0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 4));
  }
  if (*(int *)(param_1 + 4) == 0x23) {
    FUN_00570fc0(*(undefined4 *)(param_1 + 0x20));
    (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8);
  }
  else if (*(int *)(param_1 + 4) == 0x24) {
    uVar2 = (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 8) = uVar2;
    return 1;
  }
  return 1;
}


