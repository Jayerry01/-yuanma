void __thiscall FUN_0056dff0(int param_1,int param_2)

{
  int *piVar1;
  
  DAT_0072b730 = DAT_0072b730 + 1;
  *(int *)(param_2 + 8) = param_1;
  piVar1 = *(int **)(param_1 + 0x50);
  if (piVar1 != *(int **)(param_1 + 0x54)) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_2;
    }
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 4;
    FUN_0056df30();
    return;
  }
  FUN_0056f330(piVar1,&param_2);
  FUN_0056df30();
  return;
}



// WARNING: Removing unreachable block (ram,0x0056e094)
// WARNING: Removing unreachable block (ram,0x0056e099)
// WARNING: Removing unreachable block (ram,0x0056e0a4)
