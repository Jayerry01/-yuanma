void __thiscall FUN_00500c00(int *param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x44))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x94))();
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x1ac))(-param_2);
    }
  }
  return;
}


