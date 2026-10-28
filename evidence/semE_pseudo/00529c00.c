int FUN_00529c00(float param_1)

{
  undefined4 local_8;
  
  local_8 = SUB84((double)(param_1 + 6.7553994e+15),0);
  if (0x7fff < local_8) {
    return 0x7fff;
  }
  if (local_8 < -0x8000) {
    local_8 = -0x8000;
  }
  return local_8;
}


