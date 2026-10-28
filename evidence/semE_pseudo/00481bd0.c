undefined4 __thiscall FUN_00481bd0(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (((*(int *)(param_1 + 0xc) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x4c))) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) * param_2 + *(int *)(param_1 + 0xc));
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    return 1;
  }
  return 0;
}



undefined4 __thiscall