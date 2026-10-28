undefined4 FUN_00530730(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int local_20;
  int local_1c;
  uint *local_18;
  uint local_14;
  uint local_10;
  
  local_1c = 0;
  if (DAT_00723290 == (uint *)0x0) {
    if ((*DAT_007232a4 < 2) && (DAT_007232a4[1] < 2)) {
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
    uVar1 = FUN_0052fa70(param_1);
    return uVar1;
  }
  if (param_1 == 0) {
    if (param_2 == 0) {
      FUN_00530d00(0x504);
      return 0;
    }
  }
  else if (param_2 == 0) {
    uVar1 = FUN_0052fa70(param_1);
    return uVar1;
  }
  puVar2 = (uint *)FUN_0052c740(param_1,1,param_2,(char)DAT_007232a4[3],
                                *(undefined1 *)((int)DAT_007232a4 + 0xd));
  if (puVar2 != (uint *)0x0) {
    puVar2[8] = DAT_007232a4[8];
    puVar2[9] = DAT_007232a4[9];
    puVar2[0xc] = DAT_007232a4[0xc];
    uVar6 = DAT_007232a4[0xd];
    puVar2[0xd] = uVar6;
    if (((DAT_007232a4[0xb] != 0) && (puVar2[0xc] != 0)) && (uVar6 != 0x400)) {
      puVar3 = (undefined4 *)FUN_00530d80(DAT_007232a4[0xc]);
      puVar2[0xb] = (uint)puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        FUN_0052c1a0(puVar2);
        return 0;
      }
      uVar6 = puVar2[0xc];
      puVar7 = (undefined4 *)DAT_007232a4[0xb];
      for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar3 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar3 = puVar3 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar3 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
    }
    if (DAT_00723290 == (uint *)0x0) {
      DAT_007232a4[0x10] = (uint)puVar2;
      local_18 = DAT_007232a4;
    }
    else {
      DAT_00723290[0x11] = (uint)puVar2;
      local_18 = DAT_00723290;
    }
    local_10 = 0;
    if (param_2 != 0) {
      do {
        local_14 = 0;
        local_20 = 0;
        uVar6 = DAT_007232a4[7];
        iVar8 = uVar6 * local_1c;
        if (param_1 != 0) {
          uVar5 = (uint)(byte)puVar2[3];
          do {
            uVar4 = 0;
            if (uVar5 != 0) {
              do {
                *(char *)(uVar5 * local_14 + puVar2[5] + uVar4 + uVar6 * local_10) =
                     (char)((int)(((uint)*(byte *)((local_20 + 1) * uVar5 + local_18[5] + uVar4 +
                                                  iVar8) +
                                  (uint)*(byte *)(uVar5 * local_20 + local_18[5] + uVar4 + iVar8)) *
                                 2) >> 2);
                uVar5 = (uint)(byte)puVar2[3];
                uVar4 = uVar4 + 1;
              } while (uVar4 < uVar5);
            }
            local_14 = local_14 + 1;
            local_20 = local_20 + 2;
          } while (local_14 < param_1);
        }
        local_10 = local_10 + 1;
        local_1c = local_1c + 2;
      } while (local_10 < param_2);
    }
    DAT_00723290 = puVar2;
    FUN_00530730(*puVar2 >> 1,puVar2[2] >> 1);
    *(int *)(DAT_007dcb80 + 0x50) = *(int *)(DAT_007dcb80 + 0x50) + 1;
    return 1;
  }
  if (DAT_00723290 != (uint *)0x0) {
    DAT_00723290[0x11] = 0;
  }
  return 0;
}


