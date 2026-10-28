undefined4 __thiscall FUN_00558e10(int param_1,float param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = __ftol();
  iVar3 = FUN_00558d40(iVar2);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_00558bb0(param_2);
  uVar1 = *(undefined4 *)(param_1 + 0xf8);
  *(float *)(param_1 + 0xf8) = param_2;
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x100) = uVar1;
  *(int *)(param_1 + 0xfc) = iVar2;
  *(int *)(param_1 + 0x110) = iVar2;
  iVar3 = iVar2 + 1;
  if (*(int *)(param_1 + 0x130) < iVar2 + 1) {
    iVar3 = *(int *)(param_1 + 0x130);
  }
  *(int *)(param_1 + 0x114) = iVar3;
  *(float *)(param_1 + 0x118) = param_2 - (float)iVar2;
  FUN_00558ae0();
  return 1;
}


