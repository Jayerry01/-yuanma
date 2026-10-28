uint FUN_00595770(int param_1,double param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_c;
  uint local_8;
  
  local_c = param_3;
  local_8 = param_4;
  uVar1 = local_c;
  while (local_c = uVar1, local_c + 1 < local_8) {
    uVar2 = local_8 + local_c >> 1;
    uVar1 = uVar2;
    if (param_2 < *(double *)(param_1 + uVar2 * 8)) {
      uVar1 = local_c;
      local_8 = uVar2;
    }
  }
  return local_c;
}


