bool __fastcall FUN_00421b30(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00421b00(param_1);
  if (iVar1 != 0) {
    iVar1 = cpuid_Version_info(1);
    return (*(uint *)(iVar1 + 8) & 0x800000) != 0;
  }
  return false;
}



// WARNING: Removing unreachable block (ram,0x00421bc0)
// WARNING: Removing unreachable block (ram,0x00421b93)
