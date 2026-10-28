bool FUN_004325f0(short param_1,int param_2,ushort param_3)

{
  ushort uVar1;
  int iVar2;
  undefined2 local_14;
  short local_12;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined2 local_4;
  
  if (DAT_005d5b30 == (int *)0x0) {
    return false;
  }
  local_12 = param_1;
  uVar1 = (param_3 >> 3) * param_1;
  local_8 = CONCAT22(param_3,uVar1);
  local_14 = 1;
  local_c = (uint)uVar1 * param_2;
  local_10 = param_2;
  local_4 = 0;
  iVar2 = (**(code **)(*DAT_005d5b30 + 0x38))(DAT_005d5b30,&local_14);
  return iVar2 == 0;
}


