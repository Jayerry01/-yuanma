undefined4 __thiscall FUN_00461e50(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *local_8;
  int local_4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[2] == param_2) {
      return 1;
    }
  }
  local_8 = (undefined4 *)*puVar1;
  if (local_8 != puVar1) {
    do {
      iVar3 = FUN_00462f60(local_8[2]);
      if ((iVar3 != 0) || (iVar3 = FUN_00462f80(local_8[2]), iVar3 != 0)) {
        FUN_0049a680(&local_8);
        piVar4 = (int *)FUN_004632c0(&param_2);
        *piVar4 = local_4;
        piVar4[1] = *(int *)(local_4 + 4);
        **(int **)(local_4 + 4) = (int)piVar4;
        *(int **)(local_4 + 4) = piVar4;
        FUN_00462fa0(param_1);
        break;
      }
      local_8 = (undefined4 *)*local_8;
    } while (local_8 != *(undefined4 **)(param_1 + 0x14));
  }
  if (local_8 == *(undefined4 **)(param_1 + 0x14)) {
    FUN_004db820(&local_4);
    piVar4 = (int *)FUN_004632c0(&param_2);
    *piVar4 = local_4;
    piVar4[1] = *(int *)(local_4 + 4);
    **(int **)(local_4 + 4) = (int)piVar4;
    *(int **)(local_4 + 4) = piVar4;
    FUN_00462fa0(param_1);
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    *(int *)(param_1 + 0xc) = param_2;
  }
  return 1;
}


