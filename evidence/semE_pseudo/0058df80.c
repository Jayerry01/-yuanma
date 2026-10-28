void FUN_0058df80(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0058dfd0(param_1);
  *param_1 = param_2;
  param_1[8] = 1;
  if (param_2 != 0) {
    uVar1 = FUN_0059a17a(param_2);
    iVar2 = FUN_0051260f(uVar1);
    param_1[6] = (uint)(0 < iVar2);
    return;
  }
  param_1[6] = 0;
  return;
}


