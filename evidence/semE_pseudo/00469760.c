undefined4 FUN_00469760(void)

{
  int *piVar1;
  int local_4;
  
  FUN_004db820(&local_4);
  piVar1 = (int *)FUN_0046eb60(&stack0x00000004);
  *piVar1 = local_4;
  piVar1[1] = *(int *)(local_4 + 4);
  **(int **)(local_4 + 4) = (int)piVar1;
  *(int **)(local_4 + 4) = piVar1;
  return 1;
}


