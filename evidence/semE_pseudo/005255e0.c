uint FUN_005255e0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = DAT_00667a28;
  if (DAT_00667a2c != 0) {
    do {
      if (uVar1 == param_1) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      uVar1 = *(uint *)(uVar1 + 0x68);
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_00667a2c);
  }
  return uVar1 & 0xffffff00;
}


