undefined4 __thiscall FUN_004f2460(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x134))();
  if (iVar1 != 0) {
    if (param_2 < (uint)((*(int *)(iVar1 + 0xb8) - *(int *)(iVar1 + 0xb4)) / 0x48)) {
      return *(undefined4 *)(*(int *)(iVar1 + 0xb4) + 0x28 + param_2 * 0x48);
    }
  }
  return 0;
}


