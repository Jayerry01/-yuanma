int * __thiscall FUN_00507f3f(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  int unaff_retaddr;
  
  iVar2 = FUN_00508682();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x14))
                      (param_2,param_3);
    if (iVar2 != unaff_retaddr) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 6;
    }
    FUN_005086f6();
  }
  return param_1;
}


