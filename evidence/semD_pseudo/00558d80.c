undefined4 __thiscall FUN_00558d80(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == -1) {
    *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x100) = 0xbf800000;
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf8) = 0xbf800000;
  }
  else {
    iVar1 = FUN_00558d40(param_2);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_00558b60(param_2);
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xfc);
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xf8);
    *(float *)(param_1 + 0xf8) = (float)param_2;
    *(int *)(param_1 + 0xfc) = param_2;
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  FUN_00558a60();
  return 1;
}


