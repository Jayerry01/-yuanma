void FUN_00419db0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_007eac64;
  if ((param_1 != 0) && ((*(byte *)(param_1 + 4) & 1) != 0)) {
    iVar3 = *(int *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x18);
    if (0 < iVar4) {
      uVar2 = __ftol();
      do {
        *(uint *)(iVar3 + 0x10) =
             (((uint)*(byte *)(iVar3 + 0x12) | (uVar2 & 0xff) << 8) << 8 |
             (uint)*(byte *)(iVar3 + 0x11)) << 8 | *(uint *)(iVar3 + 0x10) & 0xff;
        iVar3 = iVar3 + iVar1 * 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}


