undefined4 __thiscall FUN_00557f30(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x1c))) {
    iVar1 = *(int *)(param_1 + 0x350) + param_2 * 0x334;
    if (*(int *)(iVar1 + 0x2c) != 0) {
      puVar3 = (undefined4 *)(iVar1 + 0xe4);
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_3 = *puVar3;
        puVar3 = puVar3 + 1;
        param_3 = param_3 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x350) + 0x6c + param_2 * 0x334);
      *param_4 = *puVar3;
      param_4[1] = puVar3[1];
      param_4[2] = puVar3[2];
      return 1;
    }
  }
  return 0;
}


