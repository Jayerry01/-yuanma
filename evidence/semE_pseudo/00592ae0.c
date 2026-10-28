undefined4 __fastcall FUN_00592ae0(int param_1)

{
  int iVar1;
  
  (**(code **)(**(int **)(param_1 + 0x18) + 4))();
  iVar1 = *(int *)(param_1 + 0x18);
  if (*(int *)(iVar1 + 4) == 0xb) {
    iVar1 = FUN_00578030();
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 8);
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
    return 1;
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 8);
  return 1;
}


