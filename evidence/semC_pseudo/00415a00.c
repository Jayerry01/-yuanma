void FUN_00415a00(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = 0;
  if (param_3[0x17] < 1) {
    if (0 < DAT_007f18dc) {
      do {
        piVar1 = (int *)(&DAT_007f0680)[iVar2];
        if ((((piVar1 != (int *)0x0) && (piVar1 != param_3)) && (0xfe < piVar1[0xd])) &&
           (((param_1 <= piVar1[8] && ((int)param_2 <= piVar1[9])) && (piVar1[0x10] != 0)))) {
          if ((*(int *)((&DAT_007f0680)[iVar2] + 0x60) == 1) &&
             (piVar1 = *(int **)((&DAT_007f0680)[iVar2] + 0x44), piVar1 != (int *)0x0)) {
            param_3 = (int *)0x0;
            local_10 = 0x20000;
            local_4 = 0;
            local_8 = 0;
            local_c = 0;
            (**(code **)(*piVar1 + 0x30))(piVar1,&local_10,&param_3);
            if (param_3 != (int *)0x0) {
              (**(code **)(*param_3 + 8))(param_3);
            }
          }
          goto LAB_00415b2f;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_007f18dc);
    }
    param_1 = param_1 * (int)param_2;
    iVar2 = 0;
    if (0 < DAT_007f18dc) {
      do {
        piVar1 = (int *)(&DAT_007f0680)[iVar2];
        if ((((piVar1 != (int *)0x0) && (piVar1 != param_3)) && (0x7f < piVar1[0xd])) &&
           (piVar1[0x10] != 0)) {
          if ((piVar1[0x18] == 1) && (piVar1 = (int *)piVar1[0x11], piVar1 != (int *)0x0)) {
            param_2 = (int *)0x0;
            local_10 = 0x20000;
            local_4 = 0;
            local_8 = 0;
            local_c = 0;
            (**(code **)(*piVar1 + 0x30))(piVar1,&local_10,&param_2);
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
            }
          }
          piVar1 = *(int **)((&DAT_007f0680)[iVar2] + 0x40);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)((&DAT_007f0680)[iVar2] + 0x40) = 0;
          }
          piVar1 = *(int **)((&DAT_007f0680)[iVar2] + 0x44);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)((&DAT_007f0680)[iVar2] + 0x44) = 0;
          }
          param_1 = param_1 - *(int *)((&DAT_007f0680)[iVar2] + 0x24) *
                              *(int *)((&DAT_007f0680)[iVar2] + 0x20);
          if (param_1 < 0) {
            return;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_007f18dc);
    }
  }
  else {
    iVar4 = (param_1 * (int)param_2 * 4) / 3;
    if (0 < DAT_007f18dc) {
      do {
        piVar1 = (int *)(&DAT_007f0680)[iVar2];
        if ((piVar1 != (int *)0x0) && (piVar1 != param_3)) {
          if (piVar1[0x17] < 1) {
            if (0xfe < piVar1[0xd]) {
              iVar3 = piVar1[9] * piVar1[8];
              goto LAB_00415a88;
            }
          }
          else if (0xfe < piVar1[0xd]) {
            iVar3 = (piVar1[9] * piVar1[8] * 4) / 3;
LAB_00415a88:
            if ((iVar4 < iVar3) && (piVar1[0x10] != 0)) {
LAB_00415b2f:
              piVar1 = *(int **)((&DAT_007f0680)[iVar2] + 0x40);
              if (piVar1 != (int *)0x0) {
                (**(code **)(*piVar1 + 8))(piVar1);
                *(undefined4 *)((&DAT_007f0680)[iVar2] + 0x40) = 0;
              }
              piVar1 = *(int **)((&DAT_007f0680)[iVar2] + 0x44);
              if (piVar1 == (int *)0x0) {
                return;
              }
              (**(code **)(*piVar1 + 8))(piVar1);
              *(undefined4 *)((&DAT_007f0680)[iVar2] + 0x44) = 0;
              return;
            }
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_007f18dc);
    }
    iVar3 = 0;
    iVar2 = DAT_007f18dc;
    if (0 < DAT_007f18dc) {
      do {
        piVar1 = (int *)(&DAT_007f0680)[iVar3];
        if ((((piVar1 != (int *)0x0) && (piVar1 != param_3)) && (0x7f < piVar1[0xd])) &&
           (piVar1 = (int *)piVar1[0x10], piVar1 != (int *)0x0)) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)((&DAT_007f0680)[iVar3] + 0x40) = 0;
          piVar1 = *(int **)((&DAT_007f0680)[iVar3] + 0x44);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)((&DAT_007f0680)[iVar3] + 0x44) = 0;
          }
          iVar2 = (&DAT_007f0680)[iVar3];
          if (*(int *)(iVar2 + 0x5c) < 1) {
            iVar2 = -(*(int *)(iVar2 + 0x24) * *(int *)(iVar2 + 0x20));
          }
          else {
            iVar2 = (*(int *)(iVar2 + 0x24) * *(int *)(iVar2 + 0x20) * -4) / 3;
          }
          iVar4 = iVar4 + iVar2;
          iVar2 = DAT_007f18dc;
          if (iVar4 < 0) {
            return;
          }
        }
        iVar3 = iVar3 + 1;
        if (iVar2 <= iVar3) {
          return;
        }
      } while( true );
    }
  }
  return;
}


