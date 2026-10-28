void __thiscall FUN_004c1400(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((-1 < param_2) && (param_2 < (*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24))
  {
    if (DAT_005c9a68 != -1) {
      iVar1 = FUN_004c2bf0(DAT_005c9a68);
      *(undefined1 *)(iVar1 + 0x10) = 0;
    }
    DAT_005c9a68 = param_2;
    iVar1 = FUN_004c2bf0(param_2);
    *(undefined1 *)(iVar1 + 0x10) = 3;
    iVar2 = *(int *)(param_1 + 0x51c) - *(int *)(param_1 + 0x518);
    uVar3 = 0;
    iVar1 = iVar2 >> 0x1f;
    if (iVar2 / 0x124 + iVar1 != iVar1) {
      do {
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)((*(int *)(param_1 + 0x51c) - *(int *)(param_1 + 0x518)) / 0x124));
    }
  }
  return;
}


