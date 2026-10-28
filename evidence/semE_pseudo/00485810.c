void FUN_00485810(byte param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2;
  _param_1 = (uint)(byte)(param_1 ^ (byte)*param_2);
  *param_2 = uVar1 >> 8;
  *param_2 = *(uint *)(&DAT_005c8d00 + _param_1 * 4) ^ uVar1 >> 8;
  return;
}


