void FUN_00530c60(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  DAT_007242fc = (undefined4 *)FUN_0052c490();
  if (DAT_007242fc == (undefined4 *)0x0) {
    FUN_00530d00();
    return;
  }
  iVar1 = DAT_007242fc[4];
  *param_1 = 0x28;
  param_1[1] = *DAT_007242fc;
  uVar2 = DAT_007242fc[1];
  *(undefined2 *)(param_1 + 3) = 1;
  param_1[2] = uVar2;
  *(ushort *)((int)param_1 + 0xe) = (ushort)*(byte *)(DAT_007242fc + 3) << 3;
  param_1[4] = 0;
  iVar3 = DAT_007242fc[1];
  param_1[6] = 0;
  param_1[5] = iVar3 * iVar1;
  param_1[7] = 0;
  uVar4 = (-(uint)(*(char *)(DAT_007242fc + 3) != '\x01') & 0xffffff01) + 0xff;
  param_1[8] = uVar4;
  if (uVar4 < 0x18) {
    param_1[9] = uVar4;
    return;
  }
  param_1[9] = 0;
  return;
}


