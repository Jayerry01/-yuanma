void FUN_00474e60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_005e04e0 = 10;
  puVar2 = &DAT_005e03a8;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
                    // WARNING: Could not recover jumptable at 0x00474e7e. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7c7c)();
  return;
}


