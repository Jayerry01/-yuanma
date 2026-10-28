void __thiscall FUN_00552c40(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  if ((uint)(iVar1 - iVar2) <= param_2) {
    FUN_00552f50(iVar1,(iVar2 - iVar1) + param_2,param_3);
    return;
  }
  param_1[1] = param_1[1] + ((param_2 + iVar2) - iVar1);
  return;
}


