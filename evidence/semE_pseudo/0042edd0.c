void FUN_0042edd0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xc0);
  if ((*piVar1 <= param_2) && (param_2 <= piVar1[2] + *piVar1)) {
    iVar2 = piVar1[1];
    if ((iVar2 + 5 <= param_3) &&
       ((param_3 <= piVar1[3] + -5 + iVar2 &&
        (iVar2 = ((param_3 - iVar2) + -5) / (DAT_005c71e8 + 6), piVar1[iVar2 * 9 + 0xe] != 0)))) {
      piVar1[5] = iVar2;
      return;
    }
  }
  piVar1[5] = -1;
  return;
}


