FUN_0052c8c0(int *param_1,int param_2,int param_3,int param_4,byte param_5,int param_6,int param_7,
            undefined4 *param_8)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (int *)0x0) {
    FUN_00530d00(0x506);
    return 0;
  }
  bVar1 = FUN_00530f00(param_7);
  if (bVar1 == 0) {
    FUN_00530d00(0x509);
    return 0;
  }
  iVar3 = 1;
  if (param_2 != 0) {
    iVar3 = param_2;
  }
  *param_1 = iVar3;
  iVar3 = 1;
  if (param_3 != 0) {
    iVar3 = param_3;
  }
  param_1[1] = iVar3;
  iVar3 = 1;
  if (param_4 != 0) {
    iVar3 = param_4;
  }
  param_1[2] = iVar3;
  *(byte *)((int)param_1 + 0xd) = bVar1;
  *(byte *)(param_1 + 3) = param_5;
  param_1[10] = 0x601;
  param_2 = (uint)bVar1 * (uint)param_5 * param_2;
  param_1[4] = param_2;
  param_2 = param_2 * param_3;
  param_1[7] = param_2;
  param_1[6] = param_2 * param_4;
  param_1[8] = param_6;
  param_1[9] = param_7;
  if (((param_1[0xb] != 0) && (param_1[0xc] != 0)) && (param_1[0xd] != 0x400)) {
    FUN_00530db0(param_1[0xb]);
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0x400;
  }
  FUN_0052c1a0(param_1[0x10]);
  FUN_0052c1a0(param_1[0x11]);
  FUN_0052c1a0(param_1[0x12]);
  if (param_1[0x16] != 0) {
    FUN_00530db0(param_1[0x16]);
  }
  if (param_1[0x18] != 0) {
    FUN_00530db0(param_1[0x18]);
  }
  if (param_1[0x1c] != 0) {
    FUN_00530db0(param_1[0x1c]);
  }
  param_1[0x10] = 0;
  param_1[0x14] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0x70b;
  param_1[0x1e] = 0;
  if (param_1[5] != 0) {
    FUN_00530db0(param_1[5]);
  }
  puVar2 = (undefined4 *)FUN_00530d80(param_1[6]);
  param_1[5] = (int)puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_8 != (undefined4 *)0x0) {
    uVar5 = param_1[6];
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *param_8;
      param_8 = param_8 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_8;
      param_8 = (undefined4 *)((int)param_8 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  return 1;
}


