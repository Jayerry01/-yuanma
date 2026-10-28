void __fastcall FUN_0056ee30(int param_1)

{
  int iVar1;
  
  FUN_0056df00();
  FUN_0056e870(*(undefined4 *)(param_1 + 0x18));
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x40)) {
    do {
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x4c) + iVar1 * 4) + 4) == 9) {
        FUN_005870d0();
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x40));
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x0056eee4)
// WARNING: Removing unreachable block (ram,0x0056eee8)
// WARNING: Removing unreachable block (ram,0x0056eef3)
