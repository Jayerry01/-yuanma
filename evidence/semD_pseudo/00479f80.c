undefined4 FUN_00479f80(uint param_1)

{
  int iVar1;
  
  _DAT_005e0494 = param_1;
  if (1999 < param_1) {
    if (0x8d0 < param_1) {
      return 0;
    }
    iVar1 = param_1 * 5 + -0x2715;
    param_1 = *(uint *)(*(int *)(&DAT_005ecd68 + iVar1 * 8) + (&DAT_005ecd6c)[iVar1 * 2] * 4);
  }
  if ((param_1 != 0) && (param_1 < 0x401)) {
    (*(code *)PTR_FUN_005c809c)(&DAT_005e0d20 + param_1 * 0xc);
    return 1;
  }
  (*(code *)PTR_FUN_005c809c)(0);
  return 0;
}


