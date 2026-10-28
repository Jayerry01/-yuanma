int FUN_00478dd0(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((param_1 != 0) && (param_1 < 0x400)) {
    iVar3 = 0;
    if (param_1 < 2000) {
      iVar1 = param_1 * 0x30;
      if ((*(int *)(&DAT_005e0d44 + iVar1) != 0) || (*(int *)(&DAT_005e0d4c + iVar1) != 0)) {
        iVar2 = *(int *)(&DAT_005e0d40 + iVar1);
        iVar1 = (&DAT_005e0d34)[param_1 * 0xc] * *(int *)(&DAT_005e0d30 + iVar1) * 4;
        if (0 < iVar2) {
          do {
            iVar3 = iVar3 + iVar1;
            iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          return iVar3;
        }
      }
    }
    else {
      iVar1 = param_1 * 5 + -0x2715;
      iVar2 = (&DAT_005ecd64)[iVar1 * 2];
      if (0 < iVar2) {
        puVar4 = *(undefined4 **)(&DAT_005ecd68 + iVar1 * 8);
        do {
          iVar1 = FUN_00478dd0(*puVar4);
          iVar3 = iVar3 + iVar1;
          puVar4 = puVar4 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    return iVar3;
  }
  return 0;
}


