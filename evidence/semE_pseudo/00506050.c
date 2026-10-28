uint FUN_00506050(char param_1)

{
  int iVar1;
  uint local_4;
  
  FUN_00525570();
  if (param_1 == '\0') {
    FUN_00528cb0(1,&local_4);
  }
  else {
    FUN_00528cd0(1,&local_4);
  }
  iVar1 = FUN_00525570();
  return ~-(uint)(iVar1 != 0) & local_4;
}


