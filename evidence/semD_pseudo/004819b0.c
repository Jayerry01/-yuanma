void * __thiscall FUN_004819b0(int *param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  
  param_1[0x13] = param_2;
  if (param_1[1] == 0) {
    param_2 = param_1[4] * param_2;
  }
  else if (param_1[1] == 1) {
    param_2 = param_2 * 2;
  }
  else {
    param_2 = param_2 * param_2;
  }
  FUN_00481ac0();
  if (param_1[1] == 0) {
    if (*param_1 == 0) {
      pvVar2 = operator_new(param_2);
      param_1[2] = (int)pvVar2;
    }
    else if (*param_1 == 1) {
      iVar1 = thunk_FUN_004d5fb0(param_2);
      param_1[2] = iVar1;
      if (iVar1 == 0) {
        pvVar2 = operator_new(param_2);
        *param_1 = 0;
        param_1[2] = (int)pvVar2;
        return pvVar2;
      }
    }
  }
  else if (param_1[1] == 1) {
    if (*param_1 == 0) {
      pvVar2 = operator_new(param_2);
      param_1[2] = (int)pvVar2;
      return pvVar2;
    }
    if (*param_1 == 1) {
      iVar1 = thunk_FUN_004d5fb0(param_2);
      param_1[2] = iVar1;
      if (iVar1 == 0) {
        pvVar2 = operator_new(param_2);
        *param_1 = 0;
        param_1[2] = (int)pvVar2;
        return pvVar2;
      }
    }
  }
  return (void *)param_1[2];
}


