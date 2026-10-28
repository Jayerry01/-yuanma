int FUN_0041f7f0(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar4;
  byte bVar2;
  byte bVar3;
  
  bVar1 = (byte)DAT_007e28a8;
  bVar2 = (byte)DAT_007e3350;
  bVar3 = (byte)DAT_007e339c;
  if (DAT_005c45b0 == 5) {
    return (((param_3 & 0xff) >> 4) << (bVar1 & 0x1f)) + (((param_2 & 0xff) >> 4) << (bVar2 & 0x1f))
           + (((param_1 & 0xff) >> 4) << (bVar3 & 0x1f)) + (0xf << ((byte)DAT_007e280c & 0x1f));
  }
  if ((DAT_005c45b0 == 1) || (DAT_005c45b0 == 2)) {
    uVar4 = (param_2 & 0xff) >> 2;
  }
  else {
    if ((DAT_005c45b0 != 3) && (DAT_005c45b0 != 4)) {
      if ((DAT_005c45b0 != 6) && (DAT_005c45b0 != 7)) {
        return -1;
      }
      return ((param_3 & 0xff) << (bVar1 & 0x1f)) + ((param_2 & 0xff) << (bVar2 & 0x1f)) +
             ((param_1 & 0xff) << (bVar3 & 0x1f));
    }
    uVar4 = (param_2 & 0xff) >> 3;
  }
  return (((param_3 & 0xff) >> 3) << (bVar1 & 0x1f)) + (uVar4 << (bVar2 & 0x1f)) +
         (((param_1 & 0xff) >> 3) << (bVar3 & 0x1f));
}


