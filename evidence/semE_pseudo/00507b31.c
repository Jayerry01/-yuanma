int * __fastcall FUN_00507b31(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x13] != -1) {
    if (param_1[0xc] < 0) {
      FUN_00508015(param_1 + 0xd);
    }
    iVar1 = (**(code **)(*param_1 + 4))();
    iVar2 = FUN_0050b6c7(param_1[0x13]);
    if ((iVar2 != -1) && (iVar1 != -1)) {
      param_1[0x13] = -1;
      if (-1 < param_1[0xc]) {
        return param_1;
      }
      FUN_00508020(param_1 + 0xd);
      return param_1;
    }
    if (param_1[0xc] < 0) {
      FUN_00508020(param_1 + 0xd);
    }
  }
  return (int *)0x0;
}


