int FUN_0041f6b0(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar1 = (byte)DAT_007e28a8;
  bVar2 = (byte)DAT_007e3350;
  bVar3 = (byte)DAT_007e339c;
  if (DAT_007eabe0 != 0x10) {
    return ((param_3 & 0xff) << (bVar1 & 0x1f)) + ((param_2 & 0xff) << (bVar2 & 0x1f)) +
           ((param_1 & 0xff) << (bVar3 & 0x1f));
  }
  if (DAT_007f18e4 == 5) {
    return (((param_3 & 0xff) >> 4) << (bVar1 & 0x1f)) + (((param_2 & 0xff) >> 4) << (bVar2 & 0x1f))
           + (((param_1 & 0xff) >> 4) << (bVar3 & 0x1f)) + (0xf << ((byte)DAT_007e280c & 0x1f));
  }
  if ((DAT_007f18e4 != 1) && (DAT_007f18e4 != 2)) {
    return (((param_3 & 0xff) >> 3) << (bVar1 & 0x1f)) + (((param_2 & 0xff) >> 3) << (bVar2 & 0x1f))
           + (((param_1 & 0xff) >> 3) << (bVar3 & 0x1f));
  }
  return (((param_3 & 0xff) >> 3) << (bVar1 & 0x1f)) + (((param_2 & 0xff) >> 2) << (bVar2 & 0x1f)) +
         (((param_1 & 0xff) >> 3) << (bVar3 & 0x1f));
}


