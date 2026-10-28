void FUN_004f8260(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)*param_2;
      (puVar1 != (undefined4 *)param_2[1] && (*(ushort *)*puVar1 != param_1)); puVar1 = puVar1 + 1)
  {
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x004f82ae)
// WARNING: Removing unreachable block (ram,0x004f82b3)
// WARNING: Removing unreachable block (ram,0x004f82be)
