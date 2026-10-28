int FUN_00510ff9(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00667864 = 1;
                    // WARNING: Could not recover jumptable at 0x00511013. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00667864 = 1;
                    // WARNING: Could not recover jumptable at 0x00511028. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00667854;
  }
  DAT_00667864 = (uint)bVar2;
  return param_1;
}


