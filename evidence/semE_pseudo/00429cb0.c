void FUN_00429cb0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0042a010(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1[1] != 0) {
      FUN_005089fd(puVar1[1]);
    }
    FUN_0042a300(puVar1);
    FUN_00434ac0(*puVar1);
    FUN_005089fd(puVar1);
    FUN_0042a050(param_1,0);
  }
  return;
}


