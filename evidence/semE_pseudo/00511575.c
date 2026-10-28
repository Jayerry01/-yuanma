undefined4 FUN_00511575(uint param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < DAT_007f2ec0) &&
     ((*(byte *)((&DAT_007f2dc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_007f2dc0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  puVar1 = (undefined4 *)FUN_00510865();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0051086e();
  *puVar1 = 0;
  return 0xffffffff;
}


