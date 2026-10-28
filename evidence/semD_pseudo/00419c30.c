void FUN_00419c30(int param_1,undefined4 param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_1;
  if (0 < param_3) {
    uVar2 = __ftol();
    param_1 = param_3;
    do {
      bVar1 = __ftol();
      uVar3 = __ftol();
      uVar4 = __ftol();
      *(uint *)(iVar5 + 0x10) =
           (((uint)bVar1 | (uVar2 & 0xff) << 8) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff;
      *(undefined4 *)(iVar5 + 0x14) = 0;
      iVar5 = iVar5 + param_4 * 4;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


