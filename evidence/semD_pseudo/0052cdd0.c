undefined4 FUN_0052cdd0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  DAT_007232a4 = FUN_0052c490();
  if (DAT_007232a4 == 0) {
    FUN_00530d00(0x506);
    return 0;
  }
  iVar2 = FUN_00530d80(*(undefined4 *)(DAT_007232a4 + 0x18));
  if (iVar2 != 0) {
    uVar7 = 0;
    iVar3 = DAT_007232a4;
    if (*(int *)(DAT_007232a4 + 8) != 0) {
      do {
        uVar1 = uVar7 + 1;
        puVar4 = (undefined1 *)(*(int *)(iVar3 + 0x1c) * uVar7 + iVar2);
        iVar8 = uVar1 * *(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0x14);
        uVar7 = 0;
        if (*(int *)(iVar3 + 4) != 0) {
          iVar5 = *(int *)(iVar3 + 0x10);
          do {
            iVar8 = iVar8 - iVar5;
            uVar9 = 0;
            if (iVar5 != 0) {
              puVar6 = puVar4;
              do {
                uVar9 = uVar9 + 1;
                *puVar6 = puVar6[iVar8 - (int)puVar4];
                puVar6 = puVar6 + 1;
                iVar3 = DAT_007232a4;
              } while (uVar9 < *(uint *)(DAT_007232a4 + 0x10));
            }
            iVar5 = *(int *)(iVar3 + 0x10);
            puVar4 = puVar4 + iVar5;
            uVar7 = uVar7 + 1;
          } while (uVar7 < *(uint *)(iVar3 + 4));
        }
        uVar7 = uVar1;
      } while (uVar1 < *(uint *)(iVar3 + 8));
    }
    FUN_00530db0(*(undefined4 *)(iVar3 + 0x14));
    *(int *)(DAT_007232a4 + 0x14) = iVar2;
    return 1;
  }
  return 0;
}


