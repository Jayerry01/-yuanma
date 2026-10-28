undefined4 FUN_0052fbf0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (*(uint *)(DAT_00723290 + 4) < 2) {
    *(undefined4 *)(DAT_00723290 + 0x44) = 0;
    return 1;
  }
  iVar1 = FUN_0052c740(1,param_1,1,*(undefined1 *)(DAT_007232a4 + 0xc),
                       CONCAT31((int3)(*(uint *)(DAT_00723290 + 4) >> 8),
                                *(undefined1 *)(DAT_007232a4 + 0xd)));
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(DAT_007232a4 + 0x28);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(DAT_007232a4 + 0x20);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(DAT_007232a4 + 0x24);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(DAT_007232a4 + 0x30);
    iVar7 = *(int *)(DAT_007232a4 + 0x34);
    *(int *)(iVar1 + 0x34) = iVar7;
    if (((*(int *)(DAT_007232a4 + 0x2c) != 0) && (*(int *)(iVar1 + 0x30) != 0)) && (iVar7 != 0x400))
    {
      puVar2 = (undefined4 *)FUN_00530d80(*(undefined4 *)(DAT_007232a4 + 0x30));
      *(undefined4 **)(iVar1 + 0x2c) = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        FUN_0052c1a0(iVar1);
        return 0;
      }
      uVar4 = *(uint *)(iVar1 + 0x30);
      puVar6 = *(undefined4 **)(DAT_007232a4 + 0x2c);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar2 = puVar2 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
    }
    if (DAT_00723290 == 0) {
      *(int *)(DAT_007232a4 + 0x40) = iVar1;
    }
    else {
      *(int *)(DAT_00723290 + 0x44) = iVar1;
    }
    uVar4 = 0;
    if (*(char *)(DAT_00723290 + 0xc) != '\0') {
      do {
        uVar3 = 0;
        iVar7 = 0;
        if (param_1 != 0) {
          do {
            iVar5 = (uint)*(byte *)(iVar1 + 0xc) * iVar7;
            iVar7 = iVar7 + 2;
            *(char *)(*(byte *)(iVar1 + 0xc) * uVar3 + uVar4 + *(int *)(iVar1 + 0x14)) =
                 (char)((int)((uint)*(byte *)(iVar5 + *(int *)(DAT_00723290 + 0x14) + uVar4) * 2) >>
                       1);
            uVar3 = uVar3 + 1;
          } while (uVar3 < param_1);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(byte *)(DAT_00723290 + 0xc));
    }
    DAT_00723290 = iVar1;
    FUN_0052fbf0(*(uint *)(iVar1 + 4) >> 1);
    *(int *)(DAT_007dcb80 + 0x50) = *(int *)(DAT_007dcb80 + 0x50) + 1;
    return 1;
  }
  if (DAT_00723290 != 0) {
    *(undefined4 *)(DAT_00723290 + 0x44) = 0;
  }
  return 0;
}


