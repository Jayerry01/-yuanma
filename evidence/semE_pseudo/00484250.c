undefined4 FUN_00484250(int param_1,undefined4 *param_2)

{
  DAT_00665900 = *(ushort *)(param_1 + 0x1a) + 0x1e + param_1 + (uint)*(ushort *)(param_1 + 0x1c);
  DAT_0066591c = 0;
  DAT_00665918 = 0;
  FUN_004842b0(0,param_1);
  FUN_004842b0(1,param_1);
  FUN_004842b0(2,param_1);
  *param_2 = *(undefined4 *)(param_1 + 0x16);
  return DAT_00665918;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
