void FUN_004200f0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  
  if ((-1 < param_1) && (param_1 < *(int *)(DAT_005d5a0c + 0x68c))) {
    iVar2 = param_3;
    if (param_3 < param_2) {
      iVar2 = param_2;
      param_2 = param_3;
    }
    if ((-1 < iVar2) && (iVar1 = *(int *)(DAT_005d5a0c + 0x690), param_2 < iVar1)) {
      if (param_2 < 0) {
        param_2 = 0;
      }
      if (iVar1 <= iVar2) {
        iVar2 = iVar1 + -1;
      }
      if (DAT_007eabe0 == 0x10) {
        puVar3 = (undefined2 *)(DAT_007e2c88 + DAT_007e28b0 * param_2 + param_1 * 2);
        if (param_2 < iVar2) {
          iVar2 = iVar2 - param_2;
          do {
            *puVar3 = (short)param_4;
            puVar3 = (undefined2 *)((int)puVar3 + DAT_007e28b0);
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          return;
        }
      }
      else {
        puVar4 = (undefined4 *)(DAT_007e2c88 + DAT_007e28b0 * param_2 + param_1 * 4);
        if (param_2 < iVar2) {
          iVar2 = iVar2 - param_2;
          do {
            *puVar4 = param_4;
            puVar4 = (undefined4 *)((int)puVar4 + DAT_007e28b0);
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
  }
  return;
}


