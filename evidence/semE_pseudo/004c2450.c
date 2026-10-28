int __fastcall FUN_004c2450(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc);
  uVar4 = 0;
  iVar3 = iVar2 >> 0x1f;
  iVar1 = -iVar3;
  if (iVar2 / 0x24 + iVar3 != iVar3) {
    do {
      FUN_004c24b0(uVar4);
      iVar3 = *(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc);
      iVar1 = iVar3 * 0x38e38e39;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(iVar3 / 0x24));
  }
  return iVar1;
}


