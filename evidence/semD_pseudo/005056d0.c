undefined4 FUN_005056d0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_005056a0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_005054e0(*(undefined1 *)(iVar2 + 1));
  iVar4 = FUN_005056a0(param_1);
  iVar5 = FUN_005056a0(uVar3);
  iVar2 = *(int *)(iVar4 + 4);
  *(int *)(iVar5 + 4) = iVar2;
  if (-1 < iVar2) {
    piVar1 = (int *)(DAT_00667588 + 0x10 + iVar2 * 0x14);
    *piVar1 = *piVar1 + 1;
  }
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
  *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
  *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar4 + 0x14);
  *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar4 + 0x18);
  *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar4 + 0x1c);
  *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(iVar4 + 0x24);
  *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar4 + 0x28);
  *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar4 + 0x2c);
  *(undefined4 *)(iVar5 + 0x34) = *(undefined4 *)(iVar4 + 0x34);
  *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)(iVar4 + 0x30);
  return uVar3;
}


