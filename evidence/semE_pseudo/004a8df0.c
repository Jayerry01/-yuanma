void FUN_004a8df0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  while (param_2 != param_3) {
    piVar1 = (int *)*param_2;
    piVar2 = (int *)param_2[1];
    iVar3 = *param_2;
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    FUN_00402e90(param_2,0xc);
    param_2 = piVar1;
  }
  *param_1 = param_3;
  return;
}


