void __thiscall FUN_00562520(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  
  if (0 < param_3) {
    puVar2 = (undefined4 *)(param_2 + 0x24);
    do {
      cVar1 = FUN_0056a8a0(puVar2[-6]);
      if (cVar1 != '\0') {
        FUN_005622f0(puVar2 + -9);
        if (*(char *)(param_1 + 0x255) == '\0') {
          FUN_004754f0(0,*(int *)(param_1 + 0x2f4) + puVar2[-4] * 0x18,*puVar2,puVar2[-1]);
        }
        thunk_FUN_0056adf0(puVar2 + -9);
        *(int *)(param_1 + 0x270) = *(int *)(param_1 + 0x270) + puVar2[-1];
        *(int *)(param_1 + 0x274) = *(int *)(param_1 + 0x274) + 1;
      }
      puVar2 = puVar2 + 0xc;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


