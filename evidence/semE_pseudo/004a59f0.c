undefined4 __fastcall FUN_004a59f0(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_1[0x118]) {
    do {
      (**(code **)(*param_1 + 200))(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x118]);
  }
  return 1;
}



// WARNING: Removing unreachable block (ram,0x004a62f6)
// WARNING: Removing unreachable block (ram,0x004a62fb)
// WARNING: Removing unreachable block (ram,0x004a6306)
