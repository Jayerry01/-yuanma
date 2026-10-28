int FUN_0047f340(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  iVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 / 2) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


