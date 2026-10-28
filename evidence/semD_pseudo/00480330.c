uint FUN_00480330(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 local_80 [4];
  undefined4 local_7c [6];
  undefined4 local_64;
  undefined4 local_34 [8];
  undefined1 *local_14;
  undefined4 local_10;
  
  piVar1 = DAT_005e0d28;
  puVar3 = local_7c;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_7c[0] = 0x7c;
  local_7c[1] = 0x21007;
  local_7c[3] = param_1;
  local_7c[2] = param_2;
  puVar3 = &DAT_0062e558;
  puVar4 = local_34;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_14 = &LAB_00401005_3;
  local_10 = 0x10;
  local_64 = FUN_0047f340(param_1,param_2);
  uVar5 = 0;
  iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,local_7c,local_80);
  return ~-(uint)(iVar2 != 0) & uVar5;
}


