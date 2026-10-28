void FUN_004745d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_005e07a8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
                    // WARNING: Could not recover jumptable at 0x004745eb. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7cb0)();
  return;
}


