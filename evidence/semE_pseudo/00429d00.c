void FUN_00429d00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_0042a010(param_1);
  if (iVar1 != 0) {
    DAT_005c67a0 = 1;
    DAT_005c679c = 1;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    *(undefined4 *)(iVar1 + 8) = param_2;
  }
  return;
}


