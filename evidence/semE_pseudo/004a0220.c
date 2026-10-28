int __thiscall FUN_004a0220(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  bVar1 = **(byte **)(param_1 + 8);
  while (0x20 < bVar1) {
    *(byte *)(iVar4 + param_2) = bVar1;
    iVar4 = iVar4 + 1;
    pbVar2 = (byte *)(*(int *)(param_1 + 8) + 1);
    *(byte **)(param_1 + 8) = pbVar2;
    if (iVar4 == 0x3f) break;
    bVar1 = *pbVar2;
  }
  *(undefined1 *)(iVar4 + param_2) = 0;
  if (param_3 != 3) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar4;
    iVar3 = FUN_004a00b0(param_3);
    return iVar4 + iVar3;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - iVar4;
  return iVar4;
}


