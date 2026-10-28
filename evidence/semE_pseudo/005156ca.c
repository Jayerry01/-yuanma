undefined4 FUN_005156ca(char *param_1)

{
  size_t sVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (param_1 != (char *)0x0) {
    sVar1 = _strlen(param_1);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0050f710(pvVar2,param_1);
      return uVar3;
    }
  }
  return 0;
}



void Direct3DCreate8(void)

{
                    // WARNING: Could not recover jumptable at 0x00515700. Too many branches
                    // WARNING: Treating indirect jump as call
  Direct3DCreate8();
  return;
}


