void FUN_00474410(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  thunk_FUN_004e8500(local_40);
  if (DAT_005e0cd8 == (undefined4 *)(DAT_005e0ce0 + -0x40)) {
    FUN_00476470(local_40);
    return;
  }
  if (DAT_005e0cd8 != (undefined4 *)0x0) {
    puVar2 = local_40;
    puVar3 = DAT_005e0cd8;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  DAT_005e0cd8 = DAT_005e0cd8 + 0x10;
  return;
}


