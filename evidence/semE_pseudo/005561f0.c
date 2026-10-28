int FUN_005561f0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_00554be0();
  iVar3 = param_2;
  if (cVar1 == '\0') {
    return 0;
  }
  do {
    iVar2 = FUN_005548d0(param_1,iVar3);
    if (iVar2 < 0) {
      return -1;
    }
    if (iVar2 == 0) {
      FUN_0054fe90(1);
    }
    iVar3 = iVar3 - iVar2;
    param_1 = param_1 + iVar2;
  } while (0 < iVar3);
  return param_2;
}


