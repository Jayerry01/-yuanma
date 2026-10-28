void FUN_0056d230(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int local_4;
  
  cVar1 = FUN_0056d200(param_1);
  if (cVar1 == '\0') {
    FUN_004db820(&local_4);
    piVar2 = (int *)FUN_0056da10(&param_1);
    *piVar2 = local_4;
    piVar2[1] = *(int *)(local_4 + 4);
    **(int **)(local_4 + 4) = (int)piVar2;
    *(int **)(local_4 + 4) = piVar2;
  }
  return;
}


