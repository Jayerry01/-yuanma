void FUN_005178cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00518f77(1);
  (*(code *)PTR_FUN_005cd924)(param_1,param_2,param_3,param_4);
  return;
}



void thunk_FUN_005178cc(void)

{
                    // WARNING: Could not recover jumptable at 0x005178f0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005cd924)();
  return;
}


