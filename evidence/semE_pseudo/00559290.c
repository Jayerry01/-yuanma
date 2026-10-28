void __fastcall FUN_00559290(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      FUN_00572450();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x20));
  }
  return;
}


