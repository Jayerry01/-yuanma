void __fastcall FUN_00570f80(int param_1)

{
  int iVar1;
  
  FUN_0050ac20(s_Function__s_005d189c,*(undefined4 *)(param_1 + 0x18));
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x30)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x34) + iVar1 * 4) + 8))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x30));
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00570fbc. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    return;
  }
  return;
}


