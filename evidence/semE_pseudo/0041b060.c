void FUN_0041b060(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0x7c;
  (**(code **)(*param_2 + 0x58))(param_2,param_1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
