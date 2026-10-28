void FUN_00525720(uint param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar3 = param_1;
  cVar4 = FUN_005255e0(param_1);
  if (cVar4 == '\0') {
    FUN_00525630();
    return;
  }
  FUN_00525610(param_1);
  if (DAT_0072c218 != 0) {
    timeKillEvent(DAT_0072c218);
  }
  timeEndPeriod(DAT_0072c1f8);
  piVar1 = (int *)(param_1 + 0x3c);
  puVar6 = *(undefined4 **)(param_1 + 0x38);
  param_1 = 0;
  if (*piVar1 != 0) {
    do {
      piVar1 = (int *)puVar6[0x38d];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x48))(piVar1);
        piVar1 = (int *)puVar6[0x38f];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          puVar6[0x38f] = 0;
        }
        piVar1 = (int *)puVar6[0x38e];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          puVar6[0x38e] = 0;
        }
        (**(code **)(*(int *)puVar6[0x38d] + 8))((int *)puVar6[0x38d]);
        puVar6[0x38d] = 0;
      }
      puVar2 = (undefined4 *)puVar6[0x399];
      puVar7 = puVar6;
      for (iVar5 = 0x39b; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      FUN_005089fd(puVar6);
      param_1 = param_1 + 1;
      puVar6 = puVar2;
    } while (param_1 < *(uint *)(iVar3 + 0x3c));
  }
  *(undefined4 *)(iVar3 + 0x40) = 0;
  *(undefined1 *)(iVar3 + 0x44) = 0;
  *(undefined1 *)(iVar3 + 0x45) = 1;
  FUN_00525620(iVar3);
  return;
}


