void FUN_00553a10(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  iVar1 = param_3;
  do {
    *(char *)((int)&param_3 + iVar3) = (char)iVar1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 0xffU)) >> 8;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  uVar2 = 0;
  if (0 < param_2) {
    do {
      uVar4 = uVar2 & 0x80000003;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
      }
      *(byte *)(uVar2 + param_1) = *(byte *)(uVar2 + param_1) ^ *(byte *)((int)&param_3 + uVar4);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < param_2);
  }
  return;
}


