undefined4 FUN_0050b997(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 < DAT_007f2ec0) &&
     ((*(byte *)((&DAT_007f2dc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_005115b7(param_1);
    uVar1 = FUN_0050b9fc(param_1,param_2,param_3);
    FUN_00511616(param_1);
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_00510865();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_0051086e();
  *puVar2 = 0;
  return 0xffffffff;
}


