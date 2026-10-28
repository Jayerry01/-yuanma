void * FUN_0058b6f0(undefined4 param_1,int param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = _malloc(0x28);
  if (pvVar1 == (void *)0x0) {
    FUN_0057a750(s_out_of_dynamic_memory_in_yy_crea_005d1f10);
  }
  *(int *)((int)pvVar1 + 0xc) = param_2;
  pvVar2 = _malloc(param_2 + 2);
  *(void **)((int)pvVar1 + 4) = pvVar2;
  if (pvVar2 == (void *)0x0) {
    FUN_0057a750(s_out_of_dynamic_memory_in_yy_crea_005d1f10);
  }
  *(undefined4 *)((int)pvVar1 + 0x14) = 1;
  FUN_0058b750(pvVar1,param_1);
  return pvVar1;
}


