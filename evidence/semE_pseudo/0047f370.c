void __fastcall FUN_0047f370(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    iVar2 = FUN_0047f2f0(0);
    *(undefined4 *)(param_1 + 0xa8) = 1;
    iVar3 = (*(int *)(param_1 + 0x8c) + -1) * *(int *)(param_1 + 0x88);
    iVar1 = iVar2 + iVar3 * 4;
    *(uint *)(param_1 + 0xac) = (uint)*(byte *)(iVar2 + iVar3 * 4);
    *(uint *)(param_1 + 0xb0) = (uint)*(byte *)(iVar1 + 1);
    *(uint *)(param_1 + 0xb4) = (uint)*(byte *)(iVar1 + 2);
  }
  return;
}


