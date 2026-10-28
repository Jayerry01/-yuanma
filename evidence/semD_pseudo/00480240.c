void FUN_00480240(void)

{
  int iVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  int *piStack_208;
  undefined1 *apuStack_204 [2];
  uint uStack_18c;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 auStack_108 [66];
  
  apuStack_204[1] = (undefined1 *)0x48024c;
  FUN_004802e0();
  apuStack_204[1] = (undefined1 *)0x0;
  apuStack_204[0] = &LAB_00480140;
  piStack_208 = DAT_005e0d20;
  ppiVar2 = &piStack_208;
  (**(code **)(*DAT_005e0d20 + 0x20))();
  for (iVar1 = 0x3f; ppiVar2 = ppiVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0x0;
  }
  puVar3 = auStack_108;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  apuStack_204[0] = (undefined1 *)0xfc;
  auStack_108[0] = 0xfc;
  (**(code **)(*DAT_005e0d20 + 0xc))(DAT_005e0d20,apuStack_204,auStack_108);
  DAT_005e03e4 = uStack_15c;
  DAT_005e03e8 = uStack_158;
  DAT_005e03f4 = 1;
  DAT_005e03ec = uStack_18c & 0x20;
  return;
}


