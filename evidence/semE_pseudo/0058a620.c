void FUN_0058a620(undefined1 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2;
  FUN_0050a118(&param_2,4,1,param_2);
  if (param_2 == 0) {
    *param_1 = 0;
    return;
  }
  FUN_0050a118(param_1,param_2,1,iVar1);
  param_1[param_2] = 0;
  return;
}


