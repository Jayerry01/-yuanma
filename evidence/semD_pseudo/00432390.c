undefined4 * FUN_00432390(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24 [4];
  undefined4 local_14;
  
  puVar1 = (undefined4 *)0x0;
  local_28 = 0;
  if (DAT_005d5b2c != (int *)0x0) {
    puVar1 = local_24;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    local_24[1] = param_1;
    local_14 = param_2;
    puVar1 = local_24;
    local_24[0] = 0x24;
    local_24[2] = param_3;
    iVar2 = (**(code **)(*DAT_005d5b2c + 0xc))(DAT_005d5b2c,puVar1,&local_28,0);
    if (iVar2 < 0) {
      puVar1 = (undefined4 *)0x0;
      FUN_0058e140(s_CreateSoundBuffer_error_005c7264);
    }
  }
  return puVar1;
}


