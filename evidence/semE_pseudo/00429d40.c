void FUN_00429d40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  DAT_005c679c = 1;
  iVar1 = FUN_0042a010(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x20) = param_2;
    *(undefined4 *)(iVar1 + 0x24) = param_3;
    *(undefined4 *)(iVar1 + 0x28) = param_4;
  }
  return;
}


