int * FUN_00432510(int *param_1)

{
  int iVar1;
  int *piVar2;
  int local_4;
  
  local_4 = 0;
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar1 = (**(code **)(*DAT_005d5b2c + 0x14))(DAT_005d5b2c,param_1[2]);
  if (iVar1 != 0) {
    return (int *)0x0;
  }
  piVar2 = (int *)FUN_00432910(param_1[1]);
  if (piVar2 == (int *)0x0) {
    (**(code **)(local_4 + 8))(&local_4);
    return (int *)0x0;
  }
  iVar1 = *param_1;
  *piVar2 = iVar1;
  piVar2[2] = (int)&local_4;
  piVar2[3] = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_004324a0(&local_4);
    piVar2[3] = iVar1;
    if (iVar1 == 0) {
      FUN_00410c60(s_LZCloneWaveDDK_query_3d_buffer_e_005c72dc);
    }
  }
  return piVar2;
}


