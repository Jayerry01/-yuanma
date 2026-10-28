void FUN_00528cf0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  if (param_1 != 0) {
    iVar5 = FUN_00525980();
    FUN_00525610(iVar5);
    iVar6 = FUN_005259a0(iVar5);
    if (iVar6 == 0) {
      FUN_005255b0(0xa004);
      FUN_00525620(iVar5);
      return;
    }
    if (*(uint *)(iVar5 + 0x3c) < param_1) {
      FUN_005255b0(0xa003);
      FUN_00525620(iVar5);
      return;
    }
    uVar7 = 0;
    if (param_1 != 0) {
      do {
        cVar4 = FUN_00528e40(*(undefined4 *)(param_2 + uVar7 * 4));
        if (cVar4 == '\0') {
          FUN_005255b0(0xa001);
        }
        else {
          puVar2 = *(undefined4 **)(param_2 + uVar7 * 4);
          FUN_005297f0(puVar2);
          piVar3 = (int *)puVar2[0x385];
          while (piVar3 != (int *)0x0) {
            if (*piVar3 != 0) {
              piVar1 = (int *)(*piVar3 + 0x1c);
              *piVar1 = *piVar1 + -1;
            }
            puVar2[0x385] = piVar3[3];
            FUN_005089fd(piVar3);
            piVar3 = (int *)puVar2[0x385];
          }
          puVar2[0x38c] = 0x1000;
          FUN_005260b0(iVar5,1,puVar2);
          if (puVar2[0x398] == 0) {
            *(undefined4 *)(iVar5 + 0x38) = puVar2[0x399];
          }
          else {
            *(undefined4 *)(puVar2[0x398] + 0xe64) = puVar2[0x399];
          }
          if (puVar2[0x399] != 0) {
            *(undefined4 *)(puVar2[0x399] + 0xe60) = puVar2[0x398];
          }
          puVar8 = puVar2;
          for (iVar6 = 0x39b; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
          }
          *(int *)(iVar5 + 0x3c) = *(int *)(iVar5 + 0x3c) + -1;
          FUN_005089fd(puVar2);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_1);
    }
    FUN_00525620(iVar5);
  }
  return;
}


