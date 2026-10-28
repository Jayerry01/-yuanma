void __thiscall FUN_004e4470(int *param_1,undefined4 *param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  
  if (((param_4 == *param_1) || (param_3 != 0)) || (*param_5 < *(uint *)(param_4 + 0x10))) {
    pcVar5 = (char *)FUN_004e46f0(param_5);
    *(char **)(param_4 + 8) = pcVar5;
    iVar1 = *param_1;
    if (param_4 == iVar1) {
      *(char **)(iVar1 + 4) = pcVar5;
      *(char **)(*param_1 + 0xc) = pcVar5;
    }
    else if (param_4 == *(int *)(iVar1 + 8)) {
      *(char **)(iVar1 + 8) = pcVar5;
    }
  }
  else {
    pcVar5 = (char *)FUN_004e46f0(param_5);
    *(char **)(param_4 + 0xc) = pcVar5;
    if (param_4 == *(int *)(*param_1 + 0xc)) {
      *(char **)(*param_1 + 0xc) = pcVar5;
    }
  }
  *(int *)(pcVar5 + 4) = param_4;
  pcVar5[8] = '\0';
  pcVar5[9] = '\0';
  pcVar5[10] = '\0';
  pcVar5[0xb] = '\0';
  pcVar5[0xc] = '\0';
  pcVar5[0xd] = '\0';
  pcVar5[0xe] = '\0';
  pcVar5[0xf] = '\0';
  iVar1 = *param_1;
  *pcVar5 = '\0';
  piVar8 = (int *)(iVar1 + 4);
  pcVar7 = pcVar5;
  if (pcVar5 != (char *)*piVar8) {
    do {
      pcVar2 = *(char **)(pcVar7 + 4);
      if (*pcVar2 != '\0') break;
      pcVar6 = *(char **)(*(int *)(pcVar2 + 4) + 8);
      if (pcVar2 == pcVar6) {
        pcVar6 = *(char **)(*(int *)(pcVar2 + 4) + 0xc);
        if ((pcVar6 == (char *)0x0) || (*pcVar6 != '\0')) {
          if (pcVar7 == *(char **)(pcVar2 + 0xc)) {
            iVar1 = *(int *)(pcVar2 + 0xc);
            *(undefined4 *)(pcVar2 + 0xc) = *(undefined4 *)(iVar1 + 8);
            if (*(int *)(iVar1 + 8) != 0) {
              *(char **)(*(int *)(iVar1 + 8) + 4) = pcVar2;
            }
            *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(pcVar2 + 4);
            if (pcVar2 == (char *)*piVar8) {
              *piVar8 = iVar1;
            }
            else {
              iVar3 = *(int *)(pcVar2 + 4);
              if (pcVar2 == *(char **)(iVar3 + 8)) {
                *(int *)(iVar3 + 8) = iVar1;
              }
              else {
                *(int *)(iVar3 + 0xc) = iVar1;
              }
            }
            *(char **)(iVar1 + 8) = pcVar2;
            *(int *)(pcVar2 + 4) = iVar1;
            pcVar7 = pcVar2;
          }
          **(undefined1 **)(pcVar7 + 4) = 1;
          **(undefined1 **)(*(int *)(pcVar7 + 4) + 4) = 0;
          iVar1 = *(int *)(*(int *)(pcVar7 + 4) + 4);
          iVar3 = *(int *)(iVar1 + 8);
          *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar3 + 0xc);
          if (*(int *)(iVar3 + 0xc) != 0) {
            *(int *)(*(int *)(iVar3 + 0xc) + 4) = iVar1;
          }
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar1 + 4);
          if (iVar1 == *piVar8) {
            *piVar8 = iVar3;
            *(int *)(iVar3 + 0xc) = iVar1;
            *(int *)(iVar1 + 4) = iVar3;
          }
          else {
            iVar4 = *(int *)(iVar1 + 4);
            if (iVar1 == *(int *)(iVar4 + 0xc)) {
              *(int *)(iVar4 + 0xc) = iVar3;
              *(int *)(iVar3 + 0xc) = iVar1;
              *(int *)(iVar1 + 4) = iVar3;
            }
            else {
              *(int *)(iVar4 + 8) = iVar3;
              *(int *)(iVar3 + 0xc) = iVar1;
              *(int *)(iVar1 + 4) = iVar3;
            }
          }
        }
        else {
LAB_004e4516:
          *pcVar2 = '\x01';
          *pcVar6 = '\x01';
          **(undefined1 **)(*(int *)(pcVar7 + 4) + 4) = 0;
          pcVar7 = *(char **)(*(int *)(pcVar7 + 4) + 4);
        }
      }
      else {
        if ((pcVar6 != (char *)0x0) && (*pcVar6 == '\0')) goto LAB_004e4516;
        if (pcVar7 == *(char **)(pcVar2 + 8)) {
          FUN_00461340(pcVar2,piVar8);
          pcVar7 = pcVar2;
        }
        **(undefined1 **)(pcVar7 + 4) = 1;
        **(undefined1 **)(*(int *)(pcVar7 + 4) + 4) = 0;
        FUN_004612f0(*(undefined4 *)(*(int *)(pcVar7 + 4) + 4),piVar8);
      }
    } while (pcVar7 != (char *)*piVar8);
  }
  *(undefined1 *)*piVar8 = 1;
  param_1[1] = param_1[1] + 1;
  *param_2 = pcVar5;
  return;
}


