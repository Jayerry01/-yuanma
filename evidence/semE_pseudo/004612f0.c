void FUN_004612f0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 8);
  if (*(int *)(iVar1 + 8) != 0) {
    *(int *)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 4);
  if (param_1 == *param_2) {
    *param_2 = iVar1;
    *(int *)(iVar1 + 8) = param_1;
    *(int *)(param_1 + 4) = iVar1;
    return;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(iVar2 + 8)) {
    *(int *)(iVar2 + 8) = iVar1;
    *(int *)(iVar1 + 8) = param_1;
    *(int *)(param_1 + 4) = iVar1;
    return;
  }
  *(int *)(iVar2 + 0xc) = iVar1;
  *(int *)(iVar1 + 8) = param_1;
  *(int *)(param_1 + 4) = iVar1;
  return;
}


