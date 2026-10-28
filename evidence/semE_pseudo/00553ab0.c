int __fastcall FUN_00553ab0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0x124b094;
  if (*(ushort *)(param_1 + 0xc) != 0) {
    do {
      iVar1 = iVar3 + 1;
      iVar2 = iVar2 + (*(char *)(param_1 + 0xe + iVar3) + 0xd) * iVar1 + iVar3;
      iVar3 = iVar1;
    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 0xc));
  }
  return iVar2;
}


