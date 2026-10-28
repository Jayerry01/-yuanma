uint FUN_0047fd10(uint param_1)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    in_EAX = 1;
    iVar1 = 0;
    while (((param_1 & in_EAX) == 0 || (iVar2 = iVar2 + 1, iVar2 < 2))) {
      in_EAX = in_EAX * 2;
      iVar1 = iVar1 + 1;
      if (0x1f < iVar1) {
        return CONCAT31((int3)(in_EAX >> 8),1);
      }
    }
  }
  return in_EAX & 0xffffff00;
}


