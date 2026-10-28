undefined4 * __thiscall FUN_0049fe50(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *param_1 = 0xffffffff;
  if (param_2 != 0) {
    pvVar1 = _malloc(0x2800);
    param_1[1] = pvVar1;
    if (pvVar1 != (void *)0x0) {
      *param_1 = 0xffffffff;
      FUN_0049fef0(param_2);
    }
  }
  return param_1;
}



void __fastcall thunk_FUN_0049feb0(int *param_1)

{
  if (param_1[1] != 0) {
    FUN_005089fd(param_1[1]);
    param_1[1] = 0;
  }
  if (*param_1 != -1) {
    FUN_0050b6c7(*param_1);
    *param_1 = -1;
  }
  return;
}


