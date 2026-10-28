undefined4 __thiscall FUN_00558bd0(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xf8);
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0xfc);
  iVar1 = *(int *)(param_1 + 0xfc) + param_2;
  *(float *)(param_1 + 0x34) = (float)param_2;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0xfc) = iVar1;
  if (*(int *)(param_1 + 0x130) < iVar1) {
    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 300);
  }
  if (*(int *)(param_1 + 0xfc) < *(int *)(param_1 + 300)) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0x130);
  }
  *(float *)(param_1 + 0xf8) = (float)*(int *)(param_1 + 0xfc);
  *(float *)(param_1 + 0x108) = (float)param_2 / *(float *)(param_1 + 0x38);
  FUN_00558a60();
  return 1;
}


