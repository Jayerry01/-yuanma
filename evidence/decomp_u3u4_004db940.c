
undefined4 * __thiscall
FUN_004db920(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005a2736;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0055bd60();
  param_1[0x197] = &PTR_FUN_005a9a98;
  puVar2 = param_1 + 0x198;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_4 = 1;
  FUN_005498c0();
  FUN_005498c0();
  FUN_005498c0();
  *param_1 = &PTR_FUN_005aa9f8;
  param_1[0x197] = &PTR_FUN_005aa970;
  FUN_004db9e0();
  FUN_004dbc30(param_2,param_3,param_4,param_5,param_6);
  ExceptionList = local_c;
  return param_1;
}

