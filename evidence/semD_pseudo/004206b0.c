void FUN_004206b0(int param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 < 0) {
    param_3 = param_3 + param_2;
    param_2 = 0;
  }
  if (*(int *)(DAT_005d5a0c + 0x690) <= param_2 + param_3) {
    param_3 = *(int *)(DAT_005d5a0c + 0x690) - param_2;
  }
  if ((DAT_007eabe0 == 0x10) && (iVar2 = DAT_007e28b0 * param_2 + DAT_007e2c88, param_3 != 0)) {
    piVar3 = (int *)(param_1 + 4);
    do {
      iVar1 = piVar3[-1];
      if (iVar1 <= *piVar3) {
        do {
          *(undefined2 *)(iVar2 + iVar1 * 2) = param_4;
          iVar1 = iVar1 + 1;
        } while (iVar1 <= *piVar3);
      }
      piVar3 = piVar3 + 2;
      iVar2 = iVar2 + DAT_007e28b0;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


