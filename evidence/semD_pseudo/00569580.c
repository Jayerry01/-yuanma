void __thiscall FUN_00569580(int param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(char *)(param_1 + 0x124) != '\0') &&
     (piVar1 = *(int **)(param_1 + 0x150), piVar1 != (int *)0x0)) {
    iVar2 = *(int *)(param_1 + 0x14c);
    param_2 = (float)*(int *)(*(int *)(param_1 + 0x120) + 4) * param_2 + *(float *)(param_1 + 0x13c)
    ;
    if (iVar2 == 0) {
      iVar2 = piVar1[1];
      if (*piVar1 == iVar2) {
        FUN_005693f0();
        return;
      }
      if ((float)iVar2 < param_2) {
        do {
          param_2 = param_2 - (float)(iVar2 - *piVar1);
        } while ((float)iVar2 < param_2);
      }
    }
    else if (iVar2 == 1) {
      if ((float)piVar1[1] < param_2) {
        *(undefined4 *)(param_1 + 0x14c) = 2;
        FUN_005693f0();
        return;
      }
    }
    else if (iVar2 == 2) {
      FUN_005693f0();
      return;
    }
    FUN_005693f0();
    return;
  }
  return;
}


