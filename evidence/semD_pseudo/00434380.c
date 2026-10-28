undefined4 FUN_00434380(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [4];
  undefined4 uStack_6c;
  undefined4 uStack_58;
  
  if ((param_1 == 0) && (param_1 = DAT_005d9b74, DAT_005d9b74 == 0)) {
    return 0;
  }
  if (*(int *)(param_1 + 0x34) == 0) {
    return 0;
  }
  puVar2 = local_7c;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_7c[0] = 0x7c;
  do {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x34) + 100))
                      (*(int **)(param_1 + 0x34),0,local_7c,0,0);
  } while (iVar1 == -0x7789fde4);
  DAT_005d9b7c = uStack_6c;
  DAT_005d9b80 = local_7c[3];
  DAT_005d9b84 = local_7c[2];
  return uStack_58;
}


