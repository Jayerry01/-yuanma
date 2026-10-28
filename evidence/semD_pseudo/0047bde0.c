void __thiscall FUN_0047bde0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int local_4;
  
  *(undefined1 *)(param_2 + 0xda) = 1;
  if (param_2 != param_1) {
    puVar1 = *(undefined4 **)(param_1 + 0x120);
    for (puVar2 = (undefined4 *)*puVar1; (puVar2 != puVar1 && (puVar2[2] != param_2));
        puVar2 = (undefined4 *)*puVar2) {
    }
    if (puVar2 == puVar1) {
      *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + 1;
      local_4 = param_1;
      FUN_004db820(&local_4);
      piVar3 = (int *)FUN_0047bf10(&param_2);
      *piVar3 = local_4;
      piVar3[1] = *(int *)(local_4 + 4);
      **(int **)(local_4 + 4) = (int)piVar3;
      *(int **)(local_4 + 4) = piVar3;
    }
  }
  return;
}


