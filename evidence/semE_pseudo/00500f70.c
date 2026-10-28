void __thiscall FUN_00500f70(int *param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = (int *)(**(code **)(*param_1 + 0x44))();
    if (piVar1 != (int *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00500f8e. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(*piVar1 + 0x4c))();
      return;
    }
  }
  return;
}


