void FUN_0054f670(int param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 5);
  if ((param_2 & 1) != 0) {
    bVar1 = bVar1 | 1;
  }
  if ((param_2 & 2) != 0) {
    bVar1 = bVar1 | 8;
  }
  if ((param_2 & 4) != 0) {
    bVar1 = bVar1 | 0x10;
  }
  if ((param_2 & 8) != 0) {
    bVar1 = bVar1 | 0x40;
  }
  *(byte *)(param_1 + 5) = bVar1;
  return;
}


