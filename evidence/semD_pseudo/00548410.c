void FUN_00548410(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = FUN_00410af0(param_1);
  if (iVar1 != 0) {
    if ((param_2 != (undefined4 *)0x0) && (*(undefined4 **)(iVar1 + 4) != (undefined4 *)0x0)) {
      *param_2 = **(undefined4 **)(iVar1 + 4);
      param_2[1] = *(undefined4 *)(*(int *)(iVar1 + 4) + 4);
      param_2[2] = *(undefined4 *)(*(int *)(iVar1 + 4) + 8);
    }
    if ((param_3 != (undefined4 *)0x0) && (*(undefined4 **)(iVar1 + 8) != (undefined4 *)0x0)) {
      *param_3 = **(undefined4 **)(iVar1 + 8);
      param_3[1] = *(undefined4 *)(*(int *)(iVar1 + 8) + 4);
      param_3[2] = *(undefined4 *)(*(int *)(iVar1 + 8) + 8);
    }
    if ((param_4 != (undefined4 *)0x0) && (*(undefined4 **)(iVar1 + 0xc) != (undefined4 *)0x0)) {
      *param_4 = **(undefined4 **)(iVar1 + 0xc);
      param_4[1] = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4);
      param_4[2] = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 8);
    }
    if ((param_5 != (undefined4 *)0x0) && (*(undefined4 **)(iVar1 + 0x10) != (undefined4 *)0x0)) {
      *param_5 = **(undefined4 **)(iVar1 + 0x10);
      param_5[1] = *(undefined4 *)(*(int *)(iVar1 + 0x10) + 4);
      param_5[2] = *(undefined4 *)(*(int *)(iVar1 + 0x10) + 8);
    }
  }
  return;
}


