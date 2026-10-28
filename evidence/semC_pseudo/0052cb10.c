uint FUN_0052cb10(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if ((param_1[0xb] != 0) && ((param_1[0xc] != 0 && (param_1[0xd] != 0x400)))) {
      FUN_00530db0(param_1[0xb]);
      param_1[0xb] = 0;
    }
    if (param_1[0x12] != 0) {
      FUN_0052c1a0(param_1[0x12]);
      param_1[0x12] = 0;
    }
    if (param_1[0x10] != 0) {
      FUN_0052c1a0(param_1[0x10]);
      param_1[0x10] = 0;
    }
    if (param_1[0x11] != 0) {
      FUN_0052c1a0(param_1[0x11]);
      param_1[0x11] = 0;
    }
    if (param_1[0x18] != 0) {
      FUN_00530db0(param_1[0x18]);
      param_1[0x18] = 0;
      param_1[0x19] = 0;
    }
    if (param_1[0x1c] != 0) {
      FUN_00530db0(param_1[0x1c]);
      param_1[0x1c] = 0;
      param_1[0x1d] = 0x70b;
      param_1[0x1e] = 0;
    }
    if ((param_2[0x16] != 0) && (param_2[0x17] != 0)) {
      puVar2 = (undefined4 *)FUN_00530d80(param_2[0x17] << 2);
      param_1[0x16] = puVar2;
      uVar3 = 0;
      if (puVar2 == (undefined4 *)0x0) goto LAB_0052cccd;
      puVar6 = (undefined4 *)param_2[0x16];
      for (uVar3 = param_2[0x17] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar2 = puVar2 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
    }
    if (param_2[0x18] != 0) {
      puVar2 = (undefined4 *)FUN_00530d80(param_2[0x19]);
      param_1[0x18] = puVar2;
      uVar3 = 0;
      if (puVar2 == (undefined4 *)0x0) goto LAB_0052cccd;
      uVar3 = param_2[0x19];
      puVar6 = (undefined4 *)param_2[0x18];
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar2 = puVar2 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
      param_1[0x19] = param_2[0x19];
    }
    if (param_2[0xb] == 0) {
      param_1[0xb] = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00530d80(param_2[0xc]);
      param_1[0xb] = puVar2;
      uVar3 = 0;
      if (puVar2 == (undefined4 *)0x0) goto LAB_0052cccd;
      uVar3 = param_2[0xc];
      puVar6 = (undefined4 *)param_2[0xb];
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar2 = puVar2 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
    }
    param_1[0xc] = param_2[0xc];
    param_1[0xd] = param_2[0xd];
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
    *(undefined1 *)((int)param_1 + 0xd) = *(undefined1 *)((int)param_2 + 0xd);
    param_1[4] = param_2[4];
    param_1[7] = param_2[7];
    param_1[6] = param_2[6];
    param_1[8] = param_2[8];
    param_1[9] = param_2[9];
    param_1[10] = param_2[10];
    param_1[0xe] = param_2[0xe];
    param_1[0xf] = param_2[0xf];
    uVar1 = param_2[0x17];
    param_1[0x17] = uVar1;
    param_1[0x1a] = param_2[0x1a];
    param_1[0x1b] = param_2[0x1b];
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  uVar3 = FUN_00530d00(0x509);
LAB_0052cccd:
  return uVar3 & 0xffffff00;
}


