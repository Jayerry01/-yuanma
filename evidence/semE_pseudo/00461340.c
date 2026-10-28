void FUN_00461340(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0xc);
  if (*(int *)(iVar1 + 0xc) != 0) {
    *(int *)(*(int *)(iVar1 + 0xc) + 4) = param_1;
  }
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 4);
  if (param_1 == *param_2) {
    *param_2 = iVar1;
    *(int *)(iVar1 + 0xc) = param_1;
    *(int *)(param_1 + 4) = iVar1;
    return;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(iVar2 + 0xc)) {
    *(int *)(iVar2 + 0xc) = iVar1;
    *(int *)(iVar1 + 0xc) = param_1;
    *(int *)(param_1 + 4) = iVar1;
    return;
  }
  *(int *)(iVar2 + 8) = iVar1;
  *(int *)(iVar1 + 0xc) = param_1;
  *(int *)(param_1 + 4) = iVar1;
  return;
}


