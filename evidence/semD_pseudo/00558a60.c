void __fastcall FUN_00558a60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1[0xe1] != 0) {
    FUN_00572e10();
    if (param_1[0x15] != 0) {
      puVar2 = (undefined4 *)(param_1[0xe1] + 0x3c);
      puVar4 = param_1 + 0x5b;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
    }
  }
  if (param_1[7] != 0) {
    FUN_00573ba0();
  }
  iVar1 = 0;
  if (0 < (int)param_1[8]) {
    iVar3 = 0;
    do {
      if (param_1[0xe1] != iVar3 + param_1[0xd5]) {
        FUN_00572e10();
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x2f0;
    } while (iVar1 < (int)param_1[8]);
  }
                    // WARNING: Could not recover jumptable at 0x00558adb. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)*param_1)();
  return;
}


