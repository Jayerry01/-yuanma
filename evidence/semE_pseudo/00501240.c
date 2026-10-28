void __fastcall FUN_00501240(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x44))();
  if (piVar1 != (int *)0x0) {
    FUN_00500c60(0);
    FUN_00500fa0();
    FUN_005012a0(0);
                    // WARNING: Could not recover jumptable at 0x0050126e. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(*piVar1 + 400))();
    return;
  }
  return;
}


