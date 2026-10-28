void FUN_004193e0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = param_2;
  iVar2 = *(int *)(param_2 + 0x38) * 6;
  if (DAT_007e0eac < iVar2) {
    DAT_007e0eac = iVar2;
    DAT_005d5adc = FUN_005099a7(DAT_005d5adc,*(int *)(param_2 + 0x38) * 0xc);
  }
  piVar5 = *(int **)(param_2 + 0x40);
  DAT_005c4618 = piVar5[1];
  FUN_0041a490(param_1,1);
  iVar2 = 0;
  DAT_007e2bdc = 0;
  param_2 = *(int *)(param_2 + 0x38);
  if (param_2 != 0) {
    do {
      if (*piVar5 == 1) {
        *(short *)(DAT_005d5adc + iVar2 * 2) = (short)piVar5[3];
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = (short)piVar5[4];
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = (short)piVar5[4];
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = (short)piVar5[5];
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = (short)piVar5[5];
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = (short)piVar5[3];
        iVar2 = DAT_007e2bdc + 1;
        DAT_007e2bdc = iVar2;
        iVar4 = DAT_005c4314;
      }
      else {
        iVar4 = 0;
        if (0 < piVar5[2]) {
          piVar3 = piVar5 + 4;
          do {
            *(short *)(DAT_005d5adc + iVar2 * 2) = (short)piVar3[-1];
            DAT_007e2bdc = DAT_007e2bdc + 1;
            *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = (short)*piVar3;
            iVar2 = DAT_007e2bdc + 1;
            iVar4 = iVar4 + 1;
            piVar3 = piVar3 + 2;
            DAT_007e2bdc = iVar2;
          } while (iVar4 < piVar5[2]);
        }
        iVar4 = piVar5[2] * 2 + 3;
      }
      piVar5 = piVar5 + iVar4;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (0 < iVar2) {
      (**(code **)(*param_1 + 0x74))
                (param_1,2,0x112,*(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(iVar1 + 0x18),
                 DAT_005d5adc,iVar2,param_3);
    }
  }
  return;
}


