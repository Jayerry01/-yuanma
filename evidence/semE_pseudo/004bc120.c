undefined4 __fastcall FUN_004bc120(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)FUN_00487830();
  iVar2 = (**(code **)(*piVar1 + 0x364))();
  if (iVar2 == 0) {
                    // WARNING: Could not recover jumptable at 0x004bc13f. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar3 = (**(code **)(**(int **)(param_1 + 0x3b8) + 0x20))();
    return uVar3;
  }
  return 0;
}


