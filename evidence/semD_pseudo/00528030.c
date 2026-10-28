void FUN_00528030(uint param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  if (param_1 != 0) {
    uVar3 = FUN_00525980();
    FUN_00525610(uVar3);
    if (DAT_00667a58 < param_1) {
      FUN_005255b0(0xa003);
      FUN_00525620(uVar3);
      return;
    }
    uVar5 = 0;
    if (param_1 != 0) {
      do {
        cVar2 = FUN_00528130(*(undefined4 *)(param_2 + uVar5 * 4));
        if (cVar2 == '\0') {
          if (*(int *)(param_2 + uVar5 * 4) != 0) {
            uVar7 = 0xa001;
            goto LAB_00528104;
          }
        }
        else {
          puVar1 = *(undefined4 **)(param_2 + uVar5 * 4);
          if (puVar1[7] == 0) {
            if (puVar1[8] == 0) {
              DAT_00667a54 = puVar1[9];
            }
            else {
              *(undefined4 *)(puVar1[8] + 0x24) = puVar1[9];
            }
            if (puVar1[9] != 0) {
              *(undefined4 *)(puVar1[9] + 0x20) = puVar1[8];
            }
            if (puVar1[1] != 0) {
              FUN_005089fd(puVar1[1]);
            }
            puVar6 = puVar1;
            for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar6 = 0;
              puVar6 = puVar6 + 1;
            }
            DAT_00667a58 = DAT_00667a58 - 1;
            FUN_005089fd(puVar1);
          }
          else {
            uVar7 = 0xa004;
LAB_00528104:
            FUN_005255b0(uVar7);
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_1);
    }
    FUN_00525620(uVar3);
  }
  return;
}


