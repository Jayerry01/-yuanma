undefined4 * __thiscall FUN_0058f5f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_0058eba0(param_2);
  *param_1 = &PTR_FUN_005b2548;
  param_1[2] = param_2;
  param_1[1] = 1;
  puVar1 = param_1 + 0x26;
  iVar2 = 3;
  do {
    puVar1[-3] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x2c] = 0;
  param_1[0x2b] = 0;
  param_1[0x2a] = 0;
  param_1[0x29] = 0;
  return param_1;
}


