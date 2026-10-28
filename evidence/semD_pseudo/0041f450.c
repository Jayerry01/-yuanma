uint FUN_0041f450(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 local_80 [4];
  undefined4 local_7c [6];
  undefined4 local_64;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34 [8];
  int local_14;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_7c[0] = 0x7c;
  local_7c[1] = 0x21007;
  if (param_4 != 0) {
    local_7c[1] = 0x31007;
    local_3c = param_5;
    local_38 = param_5;
  }
  local_64 = param_6;
  local_14 = (-(uint)(param_3 != 0) & 0x4003800) + 0x401808;
  local_7c[3] = param_1;
  local_7c[2] = param_2;
  puVar2 = &DAT_007e22e0;
  puVar3 = local_34;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar4 = local_80;
  iVar1 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6ec) + 0x18))
                    (*(int **)(DAT_005d5a0c + 0x6ec),local_7c,puVar4,0);
  return (uint)puVar4 & (iVar1 < 0) - 1;
}


