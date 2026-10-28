void __thiscall FUN_00501160(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x44))();
  if (piVar1 == (int *)0x0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    return;
  }
  iVar2 = (**(code **)(*piVar1 + 0x94))();
  if (iVar2 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    return;
  }
  *param_2 = *(undefined4 *)(iVar2 + 0x82c);
  param_2[1] = *(undefined4 *)(iVar2 + 0x830);
  param_2[2] = *(undefined4 *)(iVar2 + 0x834);
  return;
}


