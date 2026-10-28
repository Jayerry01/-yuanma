int FUN_00432c70(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_80;
  undefined4 local_7c [20];
  uint uStack_2c;
  int local_14;
  
  iVar3 = 0;
  local_80 = 0;
  if (0 < DAT_005d9b70) {
    do {
      if ((&DAT_005d5b70)[iVar3] == 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_005d9b70);
    if (iVar3 == 0x800) {
      return -1;
    }
  }
  puVar4 = local_7c;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_7c[0] = 0x7c;
  local_7c[1] = 7;
  local_7c[3] = param_1;
  local_14 = (-(uint)(param_3 != 0) & 0xfffff800) + 0x840;
  local_7c[2] = param_2;
  puVar4 = &local_80;
  iVar2 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6ec) + 0x18))
                    (*(int **)(DAT_005d5a0c + 0x6ec),local_7c,puVar4,0);
  if (iVar2 < 0) {
    return -1;
  }
  if (unaff_EDI == (int *)0x0) {
    return -1;
  }
  if (iVar3 == DAT_005d9b70) {
    DAT_005d9b70 = DAT_005d9b70 + 1;
  }
  puVar5 = (undefined4 *)&stack0xffffff74;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  (**(code **)(*unaff_EDI + 0x58))(unaff_EDI,&stack0xffffff74);
  (&DAT_005d5b70)[iVar3] = puVar4;
  if ((uStack_2c & 0x4000) != 0) {
    uVar1 = FUN_00432bf0(param_1,param_2);
    (&DAT_005d7b70)[iVar3] = uVar1;
    return iVar3;
  }
  (&DAT_005d7b70)[iVar3] = 0;
  return iVar3;
}


