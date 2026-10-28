void __thiscall FUN_005546c0(SOCKET *param_1,int param_2)

{
  SOCKET SVar1;
  
  if (*param_1 != 0xffffffff) {
    FUN_00554970();
  }
  if (param_2 == 1) {
    SVar1 = socket(2,2,0);
    *param_1 = SVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  if (param_2 == 2) {
    SVar1 = socket(2,1,0);
    *param_1 = SVar1;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


