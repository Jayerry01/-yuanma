void FUN_0042a1a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(DAT_005d5a0c + 0x6d0);
    if (iVar2 == 0) {
      *(int *)(DAT_005d5a0c + 0x6d0) = param_1;
      *(int *)(DAT_005d5a0c + 0x6cc) = param_1;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      return;
    }
    iVar4 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x18);
    iVar5 = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c);
    iVar2 = FUN_0042a550(iVar4,iVar5,*(undefined4 *)(param_1 + 0x28),
                         *(int *)(iVar2 + 0x20) + *(int *)(iVar2 + 0x18),
                         *(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x1c),
                         *(undefined4 *)(iVar2 + 0x28));
    if (0 < iVar2) {
      *(int *)(*(int *)(DAT_005d5a0c + 0x6d0) + 0x5c) = param_1;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(DAT_005d5a0c + 0x6d0);
      *(int *)(DAT_005d5a0c + 0x6d0) = param_1;
      return;
    }
    iVar2 = *(int *)(DAT_005d5a0c + 0x6cc);
    iVar2 = FUN_0042a550(iVar4,iVar5,*(undefined4 *)(param_1 + 0x28),
                         *(int *)(iVar2 + 0x20) + *(int *)(iVar2 + 0x18),
                         *(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x1c),
                         *(undefined4 *)(iVar2 + 0x28));
    if (iVar2 < 1) {
      *(int *)(*(int *)(DAT_005d5a0c + 0x6cc) + 0x58) = param_1;
      uVar1 = *(undefined4 *)(DAT_005d5a0c + 0x6cc);
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = uVar1;
      *(int *)(DAT_005d5a0c + 0x6cc) = param_1;
      return;
    }
    iVar2 = *(int *)(DAT_005d5a0c + 0x6d0);
    while ((iVar2 != 0 &&
           (iVar3 = FUN_0042a550(iVar4,iVar5,*(undefined4 *)(param_1 + 0x28),
                                 *(int *)(iVar2 + 0x20) + *(int *)(iVar2 + 0x18),
                                 *(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x1c),
                                 *(undefined4 *)(iVar2 + 0x28)), iVar3 < 1))) {
      iVar2 = *(int *)(iVar2 + 0x58);
    }
    uVar1 = *(undefined4 *)(iVar2 + 0x5c);
    *(int *)(param_1 + 0x58) = iVar2;
    *(undefined4 *)(param_1 + 0x5c) = uVar1;
    *(int *)(*(int *)(iVar2 + 0x5c) + 0x58) = param_1;
    *(int *)(iVar2 + 0x5c) = param_1;
  }
  return;
}


