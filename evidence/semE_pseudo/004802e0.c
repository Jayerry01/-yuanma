void FUN_004802e0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar1 = &DAT_0062e578;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = &DAT_0062e558;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  DAT_0062e678 = 0;
  puVar1 = &DAT_005c818c;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 8;
  } while ((int)puVar1 < 0x5c828c);
  puVar3 = &DAT_00628558;
  do {
    FUN_00478bc0();
    puVar3 = puVar3 + 0x30;
  } while ((int)puVar3 < 0x62e558);
  return;
}


