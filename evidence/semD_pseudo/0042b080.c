void FUN_0042b080(char *param_1,char *param_2,undefined1 *param_3,char *param_4,int param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  if ((param_1 != (char *)0x0) &&
     ((((param_3 != (undefined1 *)0x0 || (param_2 != (char *)0x0)) || (param_4 != (char *)0x0)) ||
      (param_5 != 0)))) {
    uVar3 = 0xffffffff;
    pcVar7 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar3 - 1;
    if (param_1[1] == ':') {
      if (param_2 != (char *)0x0) {
        *param_2 = *param_1;
        param_2[1] = param_1[1];
        param_2[2] = '\0';
      }
      iVar6 = 2;
    }
    else {
      if (param_2 != (char *)0x0) {
        *param_2 = '\0';
      }
      iVar6 = 0;
    }
    iVar5 = ~uVar3 - 2;
    if (iVar6 <= iVar5) {
LAB_0042b0f5:
      if (param_1[iVar5] != '\\') goto code_r0x0042b0fb;
      if (iVar6 <= iVar5) {
        if (param_3 != (undefined1 *)0x0) {
          iVar2 = iVar6;
          if (iVar6 <= iVar5) {
            do {
              param_3[iVar2 - iVar6] = param_1[iVar2];
              iVar2 = iVar2 + 1;
            } while (iVar2 <= iVar5);
          }
          param_3[iVar2 - iVar6] = 0;
        }
        iVar6 = iVar5 + 1;
        goto LAB_0042b103;
      }
    }
LAB_0042b100:
    *param_3 = 0;
LAB_0042b103:
    iVar5 = iVar6;
    pcVar7 = param_4;
    if (param_4 != (char *)0x0) {
      *param_4 = '\0';
    }
    for (; (iVar2 = iVar6, iVar5 < iVar4 && (iVar2 = iVar5, param_1[iVar5] != '.'));
        iVar5 = iVar5 + 1) {
      if (param_4 != (char *)0x0) {
        *pcVar7 = param_1[iVar5];
        pcVar7[1] = '\0';
      }
      pcVar7 = pcVar7 + 1;
    }
    if (iVar5 == iVar4) {
      iVar2 = iVar5;
    }
    if (param_5 != 0) {
      iVar6 = iVar2;
      if (iVar2 < iVar4) {
        do {
          *(char *)((param_5 - iVar2) + iVar6) = param_1[iVar6];
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
      *(undefined1 *)((iVar6 - iVar2) + param_5) = 0;
    }
  }
  return;
code_r0x0042b0fb:
  iVar5 = iVar5 + -1;
  if (iVar5 < iVar6) goto LAB_0042b100;
  goto LAB_0042b0f5;
}


