undefined4 __thiscall FUN_00464600(int param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  
  cVar6 = (char)param_2;
  if (cVar6 == '\x1b') {
    return 1;
  }
  if ((short)param_2 == 0x1003) {
    return 1;
  }
  if ((short)param_2 == 0x1004) {
    return 1;
  }
  if ((param_2 & 0xffff) == 0x1001) {
    if ((DAT_005e021c == (code *)0x0) || (iVar3 = (*DAT_005e021c)(), iVar3 == 0)) {
      iVar3 = *(int *)(param_1 + 0x6c);
      if (iVar3 == 0) {
        return 1;
      }
      *(undefined4 *)(param_1 + 0x58) = 1;
      if (iVar3 == 1) {
        *(undefined4 *)(param_1 + 0x6c) = 0;
        return 1;
      }
      if (iVar3 == 2) {
        iVar3 = FUN_00434ec0(*(undefined1 *)(param_1 + 9),2);
        iVar8 = FUN_00434ec0(*(undefined1 *)(param_1 + 6 + *(int *)(param_1 + 0x6c)),0);
        if ((iVar3 == 3) && (iVar8 == 2)) {
          *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -2;
          return 1;
        }
        *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
        return 1;
      }
      cVar6 = *(char *)(iVar3 + 7 + param_1);
      if ((cVar6 < '\x01') || (cVar6 == '\x7f')) {
LAB_00464b58:
        *(int *)(param_1 + 0x6c) = iVar3 + -2;
        return 1;
      }
      iVar8 = 0;
      if (iVar3 != 1 && -1 < iVar3 + -1) {
        do {
          iVar3 = FUN_00434ec0(*(undefined1 *)(param_1 + 8 + iVar8),0);
          iVar4 = FUN_00434ec0(*(undefined1 *)(param_1 + 9 + iVar8),2);
          if ((iVar3 == 2) && (iVar4 == 3)) {
            iVar8 = iVar8 + 2;
          }
          else {
            iVar8 = iVar8 + 1;
          }
        } while (iVar8 < *(int *)(param_1 + 0x6c) + -1);
      }
      iVar3 = *(int *)(param_1 + 0x6c);
      if (iVar8 == iVar3) goto LAB_00464b58;
    }
    else {
      if (*(int *)(param_1 + 0x6c) < 1) {
        return 1;
      }
      for (iVar3 = FUN_00434e00(1,*(int *)(param_1 + 0x6c) + 7 + param_1); iVar3 < 1;
          iVar3 = FUN_00434e00(1,iVar3 + 6 + param_1)) {
        iVar3 = *(int *)(param_1 + 0x6c);
        iVar8 = iVar3 + -1;
        *(int *)(param_1 + 0x6c) = iVar8;
        if (iVar8 < 1) break;
      }
      iVar3 = *(int *)(param_1 + 0x6c);
      *(undefined4 *)(param_1 + 0x58) = 1;
    }
    *(int *)(param_1 + 0x6c) = iVar3 + -1;
  }
  else if ((param_2 & 0xffff) == 0x1002) {
    if ((DAT_005e021c == (code *)0x0) || (iVar3 = (*DAT_005e021c)(), iVar3 == 0)) {
      iVar3 = *(int *)(param_1 + 0x6c);
      if (iVar3 != *(int *)(param_1 + 0x1c)) {
        if (iVar3 != *(int *)(param_1 + 0x1c) + -1) {
          iVar8 = FUN_00434ec0(*(undefined1 *)(iVar3 + 8 + param_1),0);
          iVar3 = *(int *)(param_1 + 0x6c);
          if (iVar8 == 2) {
            *(undefined4 *)(param_1 + 0x58) = 1;
            *(int *)(param_1 + 0x6c) = iVar3 + 2;
            return 1;
          }
        }
        *(int *)(param_1 + 0x6c) = iVar3 + 1;
        goto LAB_00464a01;
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x6c);
      if (iVar3 != *(int *)(param_1 + 0x1c)) {
        *(int *)(param_1 + 0x6c) = iVar3 + 1;
        iVar3 = FUN_00434e00(1,iVar3 + 9 + param_1);
        if (iVar3 < 1) {
          while (iVar3 = *(int *)(param_1 + 0x6c), iVar3 != *(int *)(param_1 + 0x1c)) {
            *(int *)(param_1 + 0x6c) = iVar3 + 1;
            iVar3 = FUN_00434e00(1,iVar3 + 9 + param_1);
            if (0 < iVar3) {
              *(undefined4 *)(param_1 + 0x58) = 1;
              return 1;
            }
          }
        }
LAB_00464a01:
        *(undefined4 *)(param_1 + 0x58) = 1;
        return 1;
      }
    }
  }
  else if (cVar6 == '\b') {
    if ((DAT_005e021c == (code *)0x0) || (iVar3 = (*DAT_005e021c)(), iVar3 == 0)) {
      if ((*(int *)(param_1 + 0x1c) != 0) && (iVar3 = *(int *)(param_1 + 0x6c), iVar3 != 0)) {
        cVar6 = *(char *)(iVar3 + 7 + param_1);
        if (('\0' < cVar6) && (cVar6 != '\x7f')) {
          iVar8 = 0;
          if (iVar3 != 1 && -1 < iVar3 + -1) {
            do {
              iVar3 = FUN_00434ec0(*(undefined1 *)(param_1 + 8 + iVar8),0);
              iVar4 = FUN_00434ec0(*(undefined1 *)(param_1 + 9 + iVar8),2);
              if ((iVar3 == 2) && (iVar4 == 3)) {
                iVar8 = iVar8 + 2;
              }
              else {
                iVar8 = iVar8 + 1;
              }
            } while (iVar8 < *(int *)(param_1 + 0x6c) + -1);
          }
          iVar3 = *(int *)(param_1 + 0x6c);
          if (iVar8 != iVar3) {
            if (iVar3 < 1) {
              return 1;
            }
            *(int *)(param_1 + 0x6c) = iVar3 + -1;
            *(undefined1 *)(iVar3 + 7 + param_1) = 0;
            iVar3 = *(int *)(param_1 + 0x6c);
            if (iVar3 < *(int *)(param_1 + 0x1c) + -1) {
              do {
                *(undefined1 *)(param_1 + 8 + iVar3) = *(undefined1 *)(param_1 + 9 + iVar3);
                iVar3 = iVar3 + 1;
              } while (iVar3 < *(int *)(param_1 + 0x1c) + -1);
            }
            goto LAB_00464926;
          }
        }
        if (1 < iVar3) {
          *(int *)(param_1 + 0x6c) = iVar3 + -1;
          *(undefined1 *)(iVar3 + 7 + param_1) = 0;
          iVar3 = *(int *)(param_1 + 0x6c);
          *(int *)(param_1 + 0x6c) = iVar3 + -1;
          *(undefined1 *)(iVar3 + 7 + param_1) = 0;
          iVar3 = *(int *)(param_1 + 0x6c);
          if (iVar3 < *(int *)(param_1 + 0x1c) + -2) {
            do {
              *(undefined1 *)(param_1 + 8 + iVar3) = *(undefined1 *)(param_1 + 10 + iVar3);
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(int *)(param_1 + 0x1c) + -2);
          }
          *(undefined1 *)(param_1 + 7 + *(int *)(param_1 + 0x1c)) = 0;
          *(undefined1 *)(param_1 + 6 + *(int *)(param_1 + 0x1c)) = 0;
          *(undefined4 *)(param_1 + 0x58) = 1;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -2;
          return 1;
        }
      }
    }
    else if (((*(int *)(param_1 + 0x1c) != 0) && (iVar3 = *(int *)(param_1 + 0x6c), iVar3 != 0)) &&
            (0 < iVar3)) {
      *(int *)(param_1 + 0x6c) = iVar3 + -1;
      *(undefined1 *)(iVar3 + 7 + param_1) = 0;
      iVar3 = *(int *)(param_1 + 0x6c);
      if (iVar3 < *(int *)(param_1 + 0x1c) + -1) {
        do {
          *(undefined1 *)(param_1 + 8 + iVar3) = *(undefined1 *)(param_1 + 9 + iVar3);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x1c) + -1);
      }
LAB_00464926:
      *(undefined1 *)(param_1 + 7 + *(int *)(param_1 + 0x1c)) = 0;
      *(undefined4 *)(param_1 + 0x58) = 1;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      return 1;
    }
  }
  else if ((cVar6 != '\t') && (cVar6 != '\r')) {
    pcVar1 = (char *)(param_1 + 8);
    uVar5 = 0xffffffff;
    pcVar7 = pcVar1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    if (0x10 < ~uVar5 - 1) {
LAB_004647ad:
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined1 *)(param_1 + 0x50) = 0;
      return 1;
    }
    if (*(char *)(param_1 + 0x50) != '\0') {
      uVar5 = 0xffffffff;
      pcVar7 = pcVar1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      if (0xf < ~uVar5 - 1) goto LAB_004647ad;
    }
    if (*(int *)(param_1 + 0x4c) == 0) {
      iVar3 = FUN_00434ec0(param_2,0);
      if (iVar3 == 1) {
        iVar3 = *(int *)(param_1 + 0x1c) + 1;
        if (*(int *)(param_1 + 0x6c) + 1 <= iVar3) {
          do {
            pcVar1[iVar3] = pcVar1[iVar3 + -1];
            iVar3 = iVar3 + -1;
          } while (*(int *)(param_1 + 0x6c) + 1 <= iVar3);
        }
        *(char *)(param_1 + 8 + *(int *)(param_1 + 0x6c)) = cVar6;
        *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        *(undefined4 *)(param_1 + 0x58) = 1;
        return 1;
      }
      if (iVar3 == 2) {
        *(char *)(param_1 + 0x50) = cVar6;
        *(undefined4 *)(param_1 + 0x4c) = 2;
        return 1;
      }
    }
    else if (*(int *)(param_1 + 0x4c) == 2) {
      iVar3 = FUN_00434ec0(param_2,2);
      if (iVar3 == 3) {
        iVar3 = *(int *)(param_1 + 0x1c) + 2;
        if (*(int *)(param_1 + 0x6c) + 2 <= iVar3) {
          do {
            pcVar1[iVar3] = pcVar1[iVar3 + -2];
            iVar3 = iVar3 + -1;
          } while (*(int *)(param_1 + 0x6c) + 2 <= iVar3);
        }
        *(undefined1 *)(param_1 + 8 + *(int *)(param_1 + 0x6c)) = *(undefined1 *)(param_1 + 0x50);
        iVar3 = *(int *)(param_1 + 0x6c);
        *(int *)(param_1 + 0x6c) = iVar3 + 1;
        *(char *)(iVar3 + 9 + param_1) = cVar6;
        *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        *(undefined1 *)(param_1 + 0x50) = 0;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
        *(undefined4 *)(param_1 + 0x58) = 1;
        return 1;
      }
      if (iVar3 == 4) {
        *(undefined1 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        return 1;
      }
    }
  }
  return 1;
}


