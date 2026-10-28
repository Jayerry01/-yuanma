undefined4 * FUN_0050d180(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_007f1d60 == DAT_007f1d50) {
    pvVar2 = HeapReAlloc(DAT_007f1d6c,0,DAT_007f1d64,(DAT_007f1d50 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_007f1d50 = DAT_007f1d50 + 0x10;
    DAT_007f1d64 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_007f1d64 + DAT_007f1d60 * 0x14);
  pvVar2 = HeapAlloc(DAT_007f1d6c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_007f1d60 = DAT_007f1d60 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_007f1d6c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


