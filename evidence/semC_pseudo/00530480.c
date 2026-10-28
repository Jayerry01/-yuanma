undefined4 FUN_00530480(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  
  iVar7 = 0;
  local_10 = 0;
  local_14 = 0;
  if (DAT_00723290 == (int *)0x0) {
    if ((uint)DAT_007232a4[1] < 2) {
      FUN_00530d00(0x506);
      return 0;
    }
  }
  else if ((*DAT_00723290 == 1) && (DAT_00723290[1] == 1)) {
    if (DAT_00723290[2] == 1) {
      DAT_00723290[0x11] = 0;
      return 1;
    }
  }
  else if (DAT_00723290[2] == 1) {
    uVar2 = FUN_0052fbf0(param_1);
    return uVar2;
  }
  if (param_1 == 0) {
    if (param_2 == 0) {
      FUN_00530d00(0x504);
      return 0;
    }
  }
  else if (param_2 == 0) {
    uVar2 = FUN_0052fbf0(param_1);
    return uVar2;
  }
  iVar3 = FUN_0052c740(1,param_1,param_2,(char)DAT_007232a4[3],
                       *(undefined1 *)((int)DAT_007232a4 + 0xd));
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x20) = DAT_007232a4[8];
    *(int *)(iVar3 + 0x24) = DAT_007232a4[9];
    *(int *)(iVar3 + 0x30) = DAT_007232a4[0xc];
    iVar1 = DAT_007232a4[0xd];
    *(int *)(iVar3 + 0x34) = iVar1;
    if (((DAT_007232a4[0xb] != 0) && (*(int *)(iVar3 + 0x30) != 0)) && (iVar1 != 0x400)) {
      puVar4 = (undefined4 *)FUN_00530d80(DAT_007232a4[0xc]);
      *(undefined4 **)(iVar3 + 0x2c) = puVar4;
      if (puVar4 == (undefined4 *)0x0) {
        FUN_0052c1a0(iVar3);
        return 0;
      }
      uVar6 = *(uint *)(iVar3 + 0x30);
      puVar8 = (undefined4 *)DAT_007232a4[0xb];
      for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar4 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar4 = puVar4 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar4 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
    if (DAT_00723290 == (int *)0x0) {
      DAT_007232a4[0x10] = iVar3;
      DAT_00723290 = DAT_007232a4;
    }
    else {
      DAT_00723290[0x11] = iVar3;
    }
    local_c = 0;
    if (param_2 != 0) {
      do {
        local_18 = 0;
        iVar1 = DAT_007232a4[7];
        iVar9 = iVar1 * local_14;
        if (param_1 != 0) {
          uVar6 = (uint)*(byte *)(iVar3 + 0xc);
          do {
            uVar5 = 0;
            if (uVar6 != 0) {
              do {
                *(char *)(*(int *)(iVar3 + 0x10) * local_18 + *(int *)(iVar3 + 0x14) + uVar5 +
                         iVar1 * local_c) =
                     (char)((int)(((uint)*(byte *)(DAT_00723290[4] * (iVar7 + 1) + DAT_00723290[5] +
                                                   uVar5 + iVar9) +
                                  (uint)*(byte *)(DAT_00723290[4] * local_10 + DAT_00723290[5] +
                                                  uVar5 + iVar9)) * 2) >> 2);
                uVar5 = uVar5 + 1;
                uVar6 = (uint)*(byte *)(iVar3 + 0xc);
                iVar7 = local_10;
              } while (uVar5 < uVar6);
            }
            iVar7 = iVar7 + 2;
            local_18 = local_18 + 1;
            local_10 = iVar7;
          } while (local_18 < param_1);
        }
        local_c = local_c + 1;
        local_14 = local_14 + 2;
      } while (local_c < param_2);
    }
    DAT_00723290 = (int *)iVar3;
    FUN_00530480(*(uint *)(iVar3 + 4) >> 1,*(uint *)(iVar3 + 8) >> 1);
    *(int *)(DAT_007dcb80 + 0x50) = *(int *)(DAT_007dcb80 + 0x50) + 1;
    return 1;
  }
  if (DAT_00723290 != (int *)0x0) {
    DAT_00723290[0x11] = 0;
  }
  return 0;
}


