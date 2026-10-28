void FUN_00501e70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_00667564 == 0) {
    if (DAT_00667550 != DAT_00667554) {
      if (DAT_00667550 != (undefined4 *)0x0) {
        puVar2 = &DAT_00666ce8;
        puVar3 = DAT_00667550;
        for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
      DAT_00667550 = DAT_00667550 + 0x10;
      return;
    }
    FUN_005027e0(DAT_00667550,&DAT_00666ce8);
  }
  return;
}


