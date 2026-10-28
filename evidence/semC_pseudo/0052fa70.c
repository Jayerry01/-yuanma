undefined4 FUN_0052fa70(uint param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (*DAT_00723290 < 2) {
    DAT_00723290[0x11] = 0;
    return 1;
  }
  puVar1 = (uint *)FUN_0052c740(param_1,1,1,*(undefined1 *)(DAT_007232a4 + 0xc),
                                CONCAT31((int3)(*DAT_00723290 >> 8),
                                         *(undefined1 *)(DAT_007232a4 + 0xd)));
  if (puVar1 != (uint *)0x0) {
    puVar1[10] = *(uint *)(DAT_007232a4 + 0x28);
    puVar1[8] = *(uint *)(DAT_007232a4 + 0x20);
    puVar1[9] = *(uint *)(DAT_007232a4 + 0x24);
    puVar1[0xc] = *(uint *)(DAT_007232a4 + 0x30);
    uVar4 = *(uint *)(DAT_007232a4 + 0x34);
    puVar1[0xd] = uVar4;
    if (((*(int *)(DAT_007232a4 + 0x2c) != 0) && (puVar1[0xc] != 0)) && (uVar4 != 0x400)) {
      puVar2 = (undefined4 *)FUN_00530d80(*(undefined4 *)(DAT_007232a4 + 0x30));
      puVar1[0xb] = (uint)puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        FUN_0052c1a0(puVar1);
        return 0;
      }
      uVar4 = puVar1[0xc];
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
    if (DAT_00723290 == (uint *)0x0) {
      *(uint **)(DAT_007232a4 + 0x40) = puVar1;
    }
    else {
      DAT_00723290[0x11] = (uint)puVar1;
    }
    uVar4 = 0;
    if ((char)DAT_00723290[3] != '\0') {
      do {
        uVar3 = 0;
        iVar7 = 0;
        if (param_1 != 0) {
          do {
            iVar5 = (uint)(byte)puVar1[3] * iVar7;
            iVar7 = iVar7 + 2;
            *(char *)((byte)puVar1[3] * uVar3 + puVar1[5] + uVar4) =
                 (char)((int)((uint)*(byte *)(iVar5 + DAT_00723290[5] + uVar4) * 2) >> 1);
            uVar3 = uVar3 + 1;
          } while (uVar3 < param_1);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (byte)DAT_00723290[3]);
    }
    DAT_00723290 = puVar1;
    FUN_0052fa70(*puVar1 >> 1);
    *(int *)(DAT_007dcb80 + 0x50) = *(int *)(DAT_007dcb80 + 0x50) + 1;
    return 1;
  }
  if (DAT_00723290 != (uint *)0x0) {
    DAT_00723290[0x11] = 0;
  }
  return 0;
}


