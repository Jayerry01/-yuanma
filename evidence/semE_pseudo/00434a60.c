void FUN_00434a60(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) || (param_1 = DAT_005d9b78, DAT_005d9b78 != (int *)0x0)) &&
     (iVar1 = 0, 0 < param_1[9])) {
    do {
      FUN_00433da0(*(undefined4 *)(*param_1 + iVar1 * 4),param_2,param_3,param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[9]);
  }
  return;
}


