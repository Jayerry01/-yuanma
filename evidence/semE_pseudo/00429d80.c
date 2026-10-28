void FUN_00429d80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0042a010(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00434a60(*puVar1,param_2,param_3,param_4);
    puVar1[0x10] = param_5;
  }
  return;
}


