uint FUN_00432bf0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_80 [4];
  undefined4 local_7c [26];
  undefined4 local_14;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_7c[0] = 0x7c;
  local_7c[1] = 7;
  local_14 = 0x840;
  local_7c[3] = param_1;
  local_7c[2] = param_2;
  puVar2 = local_7c;
  iVar1 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6ec) + 0x18))
                    (*(int **)(DAT_005d5a0c + 0x6ec),puVar2,local_80,0);
  return (uint)puVar2 & (iVar1 < 0) - 1;
}


