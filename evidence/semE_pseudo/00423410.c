void FUN_00423410(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = DAT_007e24d8 * DAT_007e24e0;
  puVar3 = *(undefined4 **)(DAT_007e28a4 + 0x34);
  for (uVar2 = (uVar1 & 0x7fffffff) >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  for (uVar1 = uVar1 * 2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar3 = 0xff;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
