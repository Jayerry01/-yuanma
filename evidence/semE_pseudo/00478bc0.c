void __fastcall FUN_00478bc0(undefined1 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  if (iVar1 + -1 < 1) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    (*(code *)PTR_FUN_005c80b0)(param_1);
    *param_1 = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}


