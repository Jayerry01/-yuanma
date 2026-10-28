void __thiscall FUN_004eb820(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)
            (*(int *)(*(int *)(param_1 + 0x4c) + 0x28 + param_3 * 0x2c) + param_4 * 4);
  if (0 < param_5) {
    do {
      param_5 = param_5 + -1;
      puVar3 = puVar1;
      puVar4 = param_2;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar1 = puVar1 + 6;
      param_2 = param_2 + 8;
    } while (param_5 != 0);
  }
  return;
}


