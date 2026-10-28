void __fastcall FUN_0049b380(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)*param_1;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      (**(code **)piVar2[2])(0);
      FUN_00402e90(piVar2,0x50);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  *(int *)*param_1 = *param_1;
  *(int *)(*param_1 + 4) = *param_1;
  FUN_00402e90(*param_1,0x50);
  return;
}


