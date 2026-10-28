void FUN_005433c0(int *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iStack_10;
  undefined1 uStack_c;
  
  puVar4 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xa0);
  param_1[0x68] = (int)puVar4;
  *puVar4 = &LAB_005435b0;
  puVar4[1] = FUN_005435d0;
  *(undefined1 *)(puVar4 + 2) = 0;
  if (*(char *)((int)param_1 + 0x10a) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x19;
    (**(code **)*param_1)(param_1);
  }
  if (((char)param_1[0x12] == '\0') || (bVar3 = true, param_1[0x46] < 2)) {
    bVar3 = false;
  }
  iStack_10 = 0;
  if (0 < param_1[9]) {
    piVar9 = (int *)(param_1[0x31] + 0x24);
    puVar8 = puVar4 + 0xd;
    do {
      iVar5 = (piVar9[-7] * *piVar9) / param_1[0x46];
      iVar6 = (piVar9[-6] * *piVar9) / param_1[0x46];
      iVar1 = param_1[0x45];
      iVar2 = param_1[0x44];
      puVar8[0xc] = iVar6;
      if ((char)piVar9[3] == '\0') {
        *puVar8 = &LAB_005436d0;
      }
      else if ((iVar5 == iVar2) && (iVar6 == iVar1)) {
        *puVar8 = &LAB_005436c0;
      }
      else {
        if (iVar5 * 2 == iVar2) {
          if (iVar6 == iVar1) {
            if ((bVar3) && (2 < (uint)piVar9[1])) {
              *puVar8 = &LAB_005438d0;
            }
            else {
              *puVar8 = &LAB_005437f0;
            }
          }
          else {
            if ((iVar5 * 2 != iVar2) || (iVar6 * 2 != iVar1)) goto LAB_0054350d;
            if ((bVar3) && (2 < (uint)piVar9[1])) {
              *puVar8 = &LAB_005439a0;
              *(undefined1 *)(puVar4 + 2) = 1;
            }
            else {
              *puVar8 = &LAB_00543850;
            }
          }
        }
        else {
LAB_0054350d:
          if ((iVar2 % iVar5 == 0) && (iVar1 % iVar6 == 0)) {
            uStack_c = (undefined1)(iVar2 / iVar5);
            *puVar8 = &LAB_005436e0;
            *(undefined1 *)(iStack_10 + 0x8c + (int)puVar4) = uStack_c;
            *(char *)(iStack_10 + 0x96 + (int)puVar4) = (char)(iVar1 / iVar6);
          }
          else {
            *(undefined4 *)(*param_1 + 0x14) = 0x26;
            (**(code **)*param_1)(param_1);
          }
        }
        iVar1 = param_1[1];
        uVar7 = FUN_0053e5c0(param_1[0x17],param_1[0x44],param_1[0x45]);
        uVar7 = (**(code **)(iVar1 + 8))(param_1,1,uVar7);
        puVar8[-10] = uVar7;
      }
      iStack_10 = iStack_10 + 1;
      puVar8 = puVar8 + 1;
      piVar9 = piVar9 + 0x15;
    } while (iStack_10 < param_1[9]);
  }
  return;
}


