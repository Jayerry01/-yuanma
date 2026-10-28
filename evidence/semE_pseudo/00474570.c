void FUN_00474570(int param_1)

{
  DAT_005e04e4 = param_1;
  if (param_1 == 0) {
    DAT_005e07a8 = &DAT_005e04e8;
  }
  else if (param_1 == 2) {
    DAT_005e07a8 = &DAT_005e05a8 + DAT_005e0490 * 0x40;
  }
  else if (param_1 == 3) {
    DAT_005e07a8 = &DAT_005e0528;
  }
                    // WARNING: Could not recover jumptable at 0x004745b7. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7cac)();
  return;
}



void thunk_FUN_004e8500(void)

{
                    // WARNING: Could not recover jumptable at 0x004745c0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7cb4)();
  return;
}


