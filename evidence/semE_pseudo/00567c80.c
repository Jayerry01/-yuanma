void FUN_00567c80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  FUN_0050a118(&param_1,4,1,param_1);
  iVar2 = param_2;
  FUN_0050a118(param_2,param_1,1,iVar1);
  *(undefined1 *)(param_1 + iVar2) = 0;
  return;
}


