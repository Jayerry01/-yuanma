undefined4 __thiscall FUN_004510e0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + iVar1 * 8) == param_2) {
      *(undefined4 *)(param_1 + 4 + iVar1 * 8) = param_3;
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1b);
  return 1;
}



// WARNING: Removing unreachable block (ram,0x004515a3)
// WARNING: Removing unreachable block (ram,0x004515ba)
