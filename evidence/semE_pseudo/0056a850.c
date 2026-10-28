void __fastcall FUN_0056a850(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x120);
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 0x38)) {
    iVar2 = 0;
    do {
      iVar3 = iVar3 + 1;
      *(undefined1 *)(*(int *)(iVar1 + 0x3c) + 0x21d + iVar2) = 0;
      iVar2 = iVar2 + 0x2b0;
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x120) + 0x3c) + -0x94 + iVar2) = 0;
      iVar1 = *(int *)(param_1 + 0x120);
    } while (iVar3 < *(int *)(iVar1 + 0x38));
  }
  return;
}


