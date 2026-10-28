void * __thiscall FUN_004fade0(int param_1,uint param_2)

{
  void *pvVar1;
  
  FUN_004fae10();
  if ((int)param_2 < 1) {
    return (void *)0x0;
  }
  pvVar1 = operator_new(param_2);
  *(void **)(param_1 + 0xc) = pvVar1;
  if (pvVar1 != (void *)0x0) {
    *(uint *)(param_1 + 8) = param_2;
  }
  return pvVar1;
}


