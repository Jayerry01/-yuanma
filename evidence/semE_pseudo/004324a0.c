undefined4 * FUN_004324a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x279afa86;
  local_8 = 0x200021a5;
  local_4 = 0x60e50baf;
  local_c = 0x11ce4981;
  local_14 = 0;
  iVar1 = (**(code **)*param_1)(param_1,&local_10,&local_14);
  if (iVar1 != 0) {
    FUN_00410c60(s_query_direct_sound_3d_buffer_int_005c72ac);
    return (undefined4 *)0x0;
  }
  return param_1;
}



// WARNING: Restarted to delay deadcode elimination for space: stack
