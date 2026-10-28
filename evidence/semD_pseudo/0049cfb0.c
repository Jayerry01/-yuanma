int * __thiscall FUN_0049cfb0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != param_2) {
    if (param_1[1] != 0) {
      FUN_0049cf70(*(undefined4 *)(*param_1 + 4));
      *(int *)(*param_1 + 8) = *param_1;
      *(undefined4 *)(*param_1 + 4) = 0;
      *(int *)(*param_1 + 0xc) = *param_1;
      param_1[1] = 0;
    }
    param_1[1] = 0;
    *(char *)(param_1 + 2) = (char)param_2[2];
    if (*(int *)(*param_2 + 4) == 0) {
      *(undefined4 *)(*param_1 + 4) = 0;
      *(int *)(*param_1 + 8) = *param_1;
      *(int *)(*param_1 + 0xc) = *param_1;
      return param_1;
    }
    iVar1 = *param_1;
    uVar3 = FUN_0049cd30(*(int *)(*param_2 + 4),iVar1);
    *(undefined4 *)(iVar1 + 4) = uVar3;
    iVar1 = *(int *)(*param_1 + 4);
    for (iVar2 = *(int *)(iVar1 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      iVar1 = iVar2;
    }
    *(int *)(*param_1 + 8) = iVar1;
    iVar1 = *(int *)(*param_1 + 4);
    for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      iVar1 = iVar2;
    }
    *(int *)(*param_1 + 0xc) = iVar1;
    param_1[1] = param_2[1];
  }
  return param_1;
}


