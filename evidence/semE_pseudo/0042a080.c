void FUN_0042a080(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar2 = iVar2 + *(int *)(param_1 + 8);
      piVar1 = (int *)(param_1 + 0xc);
      param_1 = *(int *)(param_1 + 0x4c);
      iVar3 = iVar3 + *piVar1;
    } while (param_1 != 0);
    if (param_2 != (int *)0x0) {
      *param_2 = iVar2;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = iVar3;
    }
  }
  return;
}


