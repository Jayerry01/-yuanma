int __thiscall FUN_0056e230(int param_1,byte *param_2,int *param_3,undefined4 *param_4)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar4 = 5;
  bVar8 = true;
  pbVar5 = param_2;
  pbVar3 = &DAT_005c6888;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pbVar5 == *pbVar3;
    pbVar5 = pbVar5 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar8);
  if (!bVar8) {
    iVar4 = -1;
    pbVar5 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
    } while (bVar1 != 0);
    if (iVar4 != -2) {
      iVar4 = 10;
      bVar8 = true;
      pbVar5 = param_2;
      pbVar3 = (byte *)s_Character_005d1884;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar5 == *pbVar3;
        pbVar5 = pbVar5 + 1;
        pbVar3 = pbVar3 + 1;
      } while (bVar8);
      if (!bVar8) {
LAB_0056e2b0:
        iVar6 = 0;
        iVar4 = FUN_0056de30();
        if (0 < iVar4) {
          do {
            iVar7 = 0;
            iVar4 = FUN_0056de50(iVar6);
            if (0 < iVar4) {
              do {
                pbVar3 = (byte *)FUN_0056de70(iVar6,iVar7);
                pbVar5 = param_2;
                do {
                  bVar1 = *pbVar5;
                  bVar8 = bVar1 < *pbVar3;
                  if (bVar1 != *pbVar3) {
LAB_0056e2fe:
                    iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                    goto LAB_0056e303;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar5[1];
                  bVar8 = bVar1 < pbVar3[1];
                  if (bVar1 != pbVar3[1]) goto LAB_0056e2fe;
                  pbVar5 = pbVar5 + 2;
                  pbVar3 = pbVar3 + 2;
                } while (bVar1 != 0);
                iVar4 = 0;
LAB_0056e303:
                if (iVar4 == 0) {
                  if (param_4 != (undefined4 *)0x0) {
                    *param_4 = 1;
                  }
                  iVar4 = FUN_0056de90(iVar6,iVar7);
                  return iVar4;
                }
                iVar7 = iVar7 + 1;
                iVar4 = FUN_0056de50(iVar6);
              } while (iVar7 < iVar4);
            }
            iVar6 = iVar6 + 1;
            iVar4 = FUN_0056de30();
          } while (iVar6 < iVar4);
        }
        iVar4 = FUN_0056deb0(param_2);
        if (iVar4 != 0) {
          if (param_4 == (undefined4 *)0x0) {
            return iVar4;
          }
          *param_4 = 1;
          return iVar4;
        }
        iVar4 = 0;
        if (0 < *(int *)(param_1 + 0x40)) {
          do {
            piVar2 = *(int **)(*(int *)(param_1 + 0x4c) + iVar4 * 4);
            pbVar5 = (byte *)(piVar2 + 9);
            pbVar3 = param_2;
            do {
              bVar1 = *pbVar5;
              bVar8 = bVar1 < *pbVar3;
              if (bVar1 != *pbVar3) {
LAB_0056e3af:
                iVar6 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_0056e3b4;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar5[1];
              bVar8 = bVar1 < pbVar3[1];
              if (bVar1 != pbVar3[1]) goto LAB_0056e3af;
              pbVar5 = pbVar5 + 2;
              pbVar3 = pbVar3 + 2;
            } while (bVar1 != 0);
            iVar6 = 0;
LAB_0056e3b4:
            if ((iVar6 == 0) && (piVar2 != param_3)) {
              if (param_4 != (undefined4 *)0x0) {
                *param_4 = 2;
              }
              iVar4 = (**(code **)(*piVar2 + 0x30))();
              return iVar4;
            }
            if (piVar2[1] == 8) {
              iVar7 = 0;
              iVar6 = FUN_00587e50();
              if (0 < iVar6) {
                do {
                  pbVar3 = (byte *)FUN_00587ef0(iVar7);
                  pbVar5 = param_2;
                  do {
                    bVar1 = *pbVar5;
                    bVar8 = bVar1 < *pbVar3;
                    if (bVar1 != *pbVar3) {
LAB_0056e403:
                      iVar6 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                      goto LAB_0056e408;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar5[1];
                    bVar8 = bVar1 < pbVar3[1];
                    if (bVar1 != pbVar3[1]) goto LAB_0056e403;
                    pbVar5 = pbVar5 + 2;
                    pbVar3 = pbVar3 + 2;
                  } while (bVar1 != 0);
                  iVar6 = 0;
LAB_0056e408:
                  if (iVar6 == 0) {
                    if (param_4 != (undefined4 *)0x0) {
                      *param_4 = 2;
                    }
                    iVar4 = FUN_00587f10(iVar7);
                    return iVar4;
                  }
                  iVar7 = iVar7 + 1;
                  iVar6 = FUN_00587e50();
                } while (iVar7 < iVar6);
              }
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(int *)(param_1 + 0x40));
        }
        return param_1 + 0x5c;
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 2;
      }
      if (*(int *)(param_1 + 0x128) != 0) goto LAB_0056e2b0;
      if ((*(int **)(param_1 + 300))[0x9d] != 0) {
        iVar4 = (**(code **)(**(int **)(param_1 + 300) + 0x30))();
        return iVar4;
      }
      goto LAB_0056e47f;
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
LAB_0056e47f:
  return param_1 + 0x5c;
}


