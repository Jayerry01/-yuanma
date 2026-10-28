undefined4 FUN_00554a70(char *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  iVar1 = gethostname(param_1,param_2);
  if (iVar1 != 0) {
    *param_1 = '\0';
    return 0;
  }
  return 1;
}


