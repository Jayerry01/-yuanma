int __thiscall FUN_0049fef0(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  if (*param_1 != -1) {
    FUN_0050b6c7(*param_1);
  }
  iVar1 = FUN_0050be91(param_2,0x8000);
  *param_1 = iVar1;
  if (iVar1 != -1) {
    if (param_1[1] == 0) {
      pvVar2 = _malloc(0x2800);
      param_1[1] = (int)pvVar2;
    }
    iVar1 = FUN_0050b997(*param_1,param_1[1],0x2800);
    param_1[5] = iVar1;
    param_1[4] = 0;
    param_1[3] = 0;
    param_1[2] = param_1[1];
  }
  return *param_1;
}


