void FUN_004209c0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = DAT_007eabe0 >> 3;
  if (DAT_007eabe0 == 0x10) {
    if (DAT_007f18e4 == 1) {
      iVar5 = (uint)(*(byte *)(DAT_005d5a0c + 0x70e) >> 3) +
              ((*(byte *)(DAT_005d5a0c + 0x70c) & 0xfffffff8) * 0x20 +
              (*(byte *)(DAT_005d5a0c + 0x70d) & 0xfffffffc)) * 8;
      goto LAB_00420b10;
    }
    if (DAT_007f18e4 == 2) {
      iVar5 = (uint)(*(byte *)(DAT_005d5a0c + 0x70c) >> 3) +
              ((*(byte *)(DAT_005d5a0c + 0x70e) & 0xfffffff8) * 0x20 +
              (*(byte *)(DAT_005d5a0c + 0x70d) & 0xfffffffc)) * 8;
      goto LAB_00420b10;
    }
    if (DAT_007f18e4 == 3) {
      iVar5 = (uint)(*(byte *)(DAT_005d5a0c + 0x70e) >> 3) +
              ((*(byte *)(DAT_005d5a0c + 0x70c) & 0xfffffff8) * 0x20 +
              (*(byte *)(DAT_005d5a0c + 0x70d) & 0xfffffff8)) * 4;
      goto LAB_00420b10;
    }
    if (DAT_007f18e4 != 5) {
      iVar5 = (uint)(*(byte *)(DAT_005d5a0c + 0x70c) >> 3) +
              ((*(byte *)(DAT_005d5a0c + 0x70e) & 0xfffffff8) * 0x20 +
              (*(byte *)(DAT_005d5a0c + 0x70d) & 0xfffffff8)) * 4;
      goto LAB_00420b10;
    }
    iVar5 = ((*(byte *)(DAT_005d5a0c + 0x70c) & 0xfffffff0) + 0xf00) * 0x10 +
            (*(byte *)(DAT_005d5a0c + 0x70d) & 0xfffffff0);
    bVar1 = *(byte *)(DAT_005d5a0c + 0x70e) >> 4;
  }
  else {
    iVar5 = ((uint)*(byte *)(DAT_005d5a0c + 0x70c) * 0x100 + (uint)*(byte *)(DAT_005d5a0c + 0x70d))
            * 0x100;
    bVar1 = *(byte *)(DAT_005d5a0c + 0x70e);
  }
  iVar5 = iVar5 + (uint)bVar1;
LAB_00420b10:
  iVar2 = *(int *)(param_3 + 8);
  iVar4 = *(int *)(param_3 + 0x18);
  if ((DAT_007eabe0 == 0x10) && (uVar6 = 0, *(int *)(param_3 + 0xc) != 0)) {
    do {
      FUN_0041bd00((uVar6 + param_2) * DAT_007e28b0 + DAT_007e2c88 + uVar3 * param_1,iVar4,
                   *(undefined4 *)(param_3 + 8),iVar5);
      iVar4 = iVar4 + iVar2 * uVar3;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_3 + 0xc));
  }
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack
