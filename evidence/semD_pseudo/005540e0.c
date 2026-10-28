undefined4 __thiscall FUN_005540e0(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_2;
  uVar1 = *(ushort *)(param_2 + 6);
  if (*(short *)(param_2 + 8) != 0) {
    FUN_005541f0(*(short *)(param_2 + 8));
  }
  if ((*(byte *)(iVar2 + 5) & 2) == 0) {
    uVar3 = 300;
  }
  else {
    uVar3 = 0;
  }
  uVar3 = FUN_005542f0(uVar3);
  if (uVar1 != 0) {
    if ((*(byte *)(iVar2 + 5) & 1) != 0) {
      param_2 = CONCAT22((short)((uint)uVar3 >> 0x10),*(ushort *)(param_1 + 0xe));
      if (uVar1 == *(ushort *)(param_1 + 0xe)) {
        return 0;
      }
      FUN_00554630(&param_2);
      if (uVar1 != (ushort)param_2) {
        *(undefined1 *)(param_1 + 0x1c) = 1;
        *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
        return 0;
      }
      *(undefined1 *)(param_1 + 0x1c) = 0;
      *(ushort *)(param_1 + 0xe) = (ushort)param_2;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
      iVar2 = FUN_00553870();
      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + iVar2;
      return 1;
    }
    if (uVar1 == *(ushort *)(param_1 + 0xc)) {
      return 0;
    }
    iVar2 = (uint)uVar1 - (uint)*(ushort *)(param_1 + 0xc);
    if ((iVar2 < 0) && (-30000 < iVar2)) {
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
      return 0;
    }
    if (1 < iVar2) {
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + iVar2 + -1;
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    iVar2 = FUN_00553870();
    *(ushort *)(param_1 + 0xc) = uVar1;
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + iVar2;
  }
  return 1;
}


