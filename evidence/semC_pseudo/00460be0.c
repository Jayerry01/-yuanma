void FUN_00460be0(char *param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  *param_1 = '\0';
  if (param_1 == (char *)*param_2) {
    *(undefined1 *)*param_2 = 1;
    return;
  }
  do {
    pcVar1 = *(char **)(param_1 + 4);
    if (*pcVar1 != '\0') {
      *(undefined1 *)*param_2 = 1;
      return;
    }
    pcVar4 = *(char **)(*(int *)(pcVar1 + 4) + 8);
    if (pcVar1 == pcVar4) {
      pcVar4 = *(char **)(*(int *)(pcVar1 + 4) + 0xc);
      if ((pcVar4 != (char *)0x0) && (*pcVar4 == '\0')) goto LAB_00460c1b;
      if (param_1 == *(char **)(pcVar1 + 0xc)) {
        iVar3 = *(int *)(pcVar1 + 0xc);
        *(undefined4 *)(pcVar1 + 0xc) = *(undefined4 *)(iVar3 + 8);
        if (*(int *)(iVar3 + 8) != 0) {
          *(char **)(*(int *)(iVar3 + 8) + 4) = pcVar1;
        }
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(pcVar1 + 4);
        if (pcVar1 == (char *)*param_2) {
          *param_2 = iVar3;
        }
        else {
          iVar5 = *(int *)(pcVar1 + 4);
          if (pcVar1 == *(char **)(iVar5 + 8)) {
            *(int *)(iVar5 + 8) = iVar3;
          }
          else {
            *(int *)(iVar5 + 0xc) = iVar3;
          }
        }
        *(char **)(iVar3 + 8) = pcVar1;
        *(int *)(pcVar1 + 4) = iVar3;
        param_1 = pcVar1;
      }
      **(undefined1 **)(param_1 + 4) = 1;
      **(undefined1 **)(*(int *)(param_1 + 4) + 4) = 0;
      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);
      iVar5 = *(int *)(iVar3 + 8);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar5 + 0xc);
      if (*(int *)(iVar5 + 0xc) != 0) {
        *(int *)(*(int *)(iVar5 + 0xc) + 4) = iVar3;
      }
      *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar3 + 4);
      if (iVar3 == *param_2) {
        *param_2 = iVar5;
        *(int *)(iVar5 + 0xc) = iVar3;
      }
      else {
        iVar2 = *(int *)(iVar3 + 4);
        if (iVar3 == *(int *)(iVar2 + 0xc)) {
          *(int *)(iVar2 + 0xc) = iVar5;
          *(int *)(iVar5 + 0xc) = iVar3;
        }
        else {
          *(int *)(iVar2 + 8) = iVar5;
          *(int *)(iVar5 + 0xc) = iVar3;
        }
      }
LAB_00460d69:
      *(int *)(iVar3 + 4) = iVar5;
    }
    else {
      if ((pcVar4 == (char *)0x0) || (*pcVar4 != '\0')) {
        if (param_1 == *(char **)(pcVar1 + 8)) {
          iVar3 = *(int *)(pcVar1 + 8);
          *(undefined4 *)(pcVar1 + 8) = *(undefined4 *)(iVar3 + 0xc);
          if (*(int *)(iVar3 + 0xc) != 0) {
            *(char **)(*(int *)(iVar3 + 0xc) + 4) = pcVar1;
          }
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(pcVar1 + 4);
          if (pcVar1 == (char *)*param_2) {
            *param_2 = iVar3;
          }
          else {
            iVar5 = *(int *)(pcVar1 + 4);
            if (pcVar1 == *(char **)(iVar5 + 0xc)) {
              *(int *)(iVar5 + 0xc) = iVar3;
            }
            else {
              *(int *)(iVar5 + 8) = iVar3;
            }
          }
          *(char **)(iVar3 + 0xc) = pcVar1;
          *(int *)(pcVar1 + 4) = iVar3;
          param_1 = pcVar1;
        }
        **(undefined1 **)(param_1 + 4) = 1;
        **(undefined1 **)(*(int *)(param_1 + 4) + 4) = 0;
        iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);
        iVar5 = *(int *)(iVar3 + 0xc);
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar5 + 8);
        if (*(int *)(iVar5 + 8) != 0) {
          *(int *)(*(int *)(iVar5 + 8) + 4) = iVar3;
        }
        *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar3 + 4);
        if (iVar3 == *param_2) {
          *param_2 = iVar5;
        }
        else {
          iVar2 = *(int *)(iVar3 + 4);
          if (iVar3 == *(int *)(iVar2 + 8)) {
            *(int *)(iVar2 + 8) = iVar5;
          }
          else {
            *(int *)(iVar2 + 0xc) = iVar5;
          }
        }
        *(int *)(iVar5 + 8) = iVar3;
        goto LAB_00460d69;
      }
LAB_00460c1b:
      *pcVar1 = '\x01';
      *pcVar4 = '\x01';
      **(undefined1 **)(*(int *)(param_1 + 4) + 4) = 0;
      param_1 = *(char **)(*(int *)(param_1 + 4) + 4);
    }
    if (param_1 == (char *)*param_2) {
      *(char *)*param_2 = '\x01';
      return;
    }
  } while( true );
}


