void __thiscall FUN_0047b9c0(int param_1,int param_2)

{
  int *piVar1;
  int local_4;
  
  if (param_2 != param_1) {
    local_4 = param_1;
    FUN_004db820(&local_4);
    piVar1 = (int *)FUN_0047bf10(&param_2);
    *piVar1 = local_4;
    piVar1[1] = *(int *)(local_4 + 4);
    **(int **)(local_4 + 4) = (int)piVar1;
    *(int **)(local_4 + 4) = piVar1;
  }
  return;
}


