void __fastcall FUN_004fa210(int param_1)

{
  DWORD DVar1;
  
  if (*(char *)(param_1 + 0x40) != '\0') {
    DVar1 = timeGetTime();
    if (*(uint *)(param_1 + 0x48) <= DVar1 - *(int *)(param_1 + 0x44)) {
      *(DWORD *)(param_1 + 0x44) = DVar1;
      if (*(int **)(param_1 + 0x38) != (int *)0x0) {
                    // WARNING: Could not recover jumptable at 0x004fa23a. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(**(int **)(param_1 + 0x38) + 4))();
        return;
      }
    }
  }
  return;
}


