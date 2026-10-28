int __thiscall FUN_005084e5(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (param_1[2] == 0) {
    while ((param_3 != 0 && (iVar1 = (**(code **)(*param_1 + 0x20))(), iVar1 != -1))) {
      iVar1 = param_1[0xb] - param_1[10];
      if (param_3 <= iVar1) {
        iVar1 = param_3;
      }
      if (0 < iVar1) {
        FUN_0050c1e0(param_2,param_1[10],iVar1);
        param_2 = param_2 + iVar1;
        param_1[10] = param_1[10] + iVar1;
        local_8 = local_8 + iVar1;
        param_3 = param_3 - iVar1;
      }
    }
  }
  else {
    if (param_1[3] == -1) {
      iVar1 = (**(code **)(*param_1 + 0x20))();
      param_1[3] = iVar1;
    }
    while ((param_3 != 0 && (param_3 = param_3 + -1, param_1[3] != -1))) {
      *param_2 = (char)param_1[3];
      param_2 = param_2 + 1;
      local_8 = local_8 + 1;
      iVar1 = (**(code **)(*param_1 + 0x20))();
      param_1[3] = iVar1;
    }
  }
  return local_8;
}


