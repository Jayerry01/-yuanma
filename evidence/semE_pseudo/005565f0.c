void __thiscall FUN_005565f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_3 = *(undefined4 *)(param_1 + 0x1b8);
  param_3[1] = *(undefined4 *)(param_1 + 0x1bc);
  param_3[2] = *(undefined4 *)(param_1 + 0x1c0);
  puVar2 = (undefined4 *)(param_1 + 0x248);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


