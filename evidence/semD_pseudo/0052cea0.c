undefined4 FUN_0052cea0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  if (DAT_0072329c == 0) {
    FUN_00530d00(0x506);
    return 0;
  }
  iVar2 = FUN_00530d80(*(undefined4 *)(DAT_0072329c + 0x18));
  if (iVar2 != 0) {
    *(uint *)(DAT_0072329c + 0x28) = (*(int *)(DAT_0072329c + 0x28) == 0x601) + 0x601;
    iVar9 = DAT_0072329c;
    if (*(int *)(DAT_0072329c + 8) != 0) {
      uVar4 = *(uint *)(DAT_0072329c + 4);
      uVar7 = 0;
      do {
        uVar1 = uVar7 + 1;
        puVar6 = (undefined4 *)(*(int *)(iVar9 + 0x1c) * uVar7 + iVar2);
        puVar3 = (undefined4 *)(uVar1 * *(int *)(iVar9 + 0x1c) + *(int *)(iVar9 + 0x14));
        uVar7 = 0;
        if (uVar4 != 0) {
          uVar5 = *(uint *)(iVar9 + 0x10);
          do {
            puVar3 = (undefined4 *)((int)puVar3 - uVar5);
            puVar8 = puVar3;
            puVar10 = puVar6;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
              puVar8 = (undefined4 *)((int)puVar8 + 1);
              puVar10 = (undefined4 *)((int)puVar10 + 1);
            }
            uVar5 = *(uint *)(DAT_0072329c + 0x10);
            uVar4 = *(uint *)(DAT_0072329c + 4);
            puVar6 = (undefined4 *)((int)puVar6 + uVar5);
            uVar7 = uVar7 + 1;
            iVar9 = DAT_0072329c;
          } while (uVar7 < uVar4);
        }
        uVar7 = uVar1;
      } while (uVar1 < *(uint *)(iVar9 + 8));
    }
    FUN_00530db0(*(undefined4 *)(iVar9 + 0x14));
    *(int *)(DAT_0072329c + 0x14) = iVar2;
    return 1;
  }
  return 0;
}


