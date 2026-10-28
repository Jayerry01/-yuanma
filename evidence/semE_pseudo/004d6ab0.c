void FUN_004d6ab0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *unaff_retaddr;
  
  piVar1 = (int *)param_2[1];
  iVar2 = *param_2;
  *piVar1 = iVar2;
  *(int **)(iVar2 + 4) = piVar1;
  (**(code **)param_2[2])(0);
  FUN_00402e90(param_2,0x50);
  *unaff_retaddr = iVar2;
  return;
}


