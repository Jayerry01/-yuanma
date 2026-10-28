undefined4 __thiscall FUN_00558c50(int param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xf8);
  *(float *)(param_1 + 0xf8) = param_2 * *(float *)(param_1 + 0x10c) + *(float *)(param_1 + 0xf8);
  uVar2 = __ftol();
  iVar1 = *(int *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(float *)(param_1 + 0x34) = (float)extraout_ST1;
  if ((float10)iVar1 < extraout_ST0) {
    *(float *)(param_1 + 0xf8) = (float)*(int *)(param_1 + 300);
  }
  iVar4 = *(int *)(param_1 + 300);
  if (*(float *)(param_1 + 0xf8) < (float)iVar4) {
    *(float *)(param_1 + 0xf8) = (float)iVar1;
  }
  iVar3 = __ftol();
  *(int *)(param_1 + 0xfc) = iVar3;
  *(int *)(param_1 + 0x110) = iVar3;
  if (iVar3 < iVar1 + -1) {
    iVar4 = iVar3 + 1;
  }
  *(int *)(param_1 + 0x114) = iVar4;
  *(float *)(param_1 + 0x118) = *(float *)(param_1 + 0xf8) - (float)iVar3;
  *(float *)(param_1 + 0x108) = (float)(extraout_ST0_00 / (float10)*(float *)(param_1 + 0x38));
  FUN_00558ae0();
  return 1;
}


