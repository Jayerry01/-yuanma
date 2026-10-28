FUN_004a1fc0(int param_1,int *param_2,undefined4 *param_3,int *param_4,int *param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  int local_4;
  
  piVar5 = param_5;
  if ((undefined1 *)*param_4 != (undefined1 *)param_4[1]) {
    *(undefined1 *)*param_4 = 0;
    param_4[1] = *param_4;
  }
  if ((undefined1 *)*param_5 != (undefined1 *)param_5[1]) {
    *(undefined1 *)*param_5 = 0;
    param_5[1] = *param_5;
  }
  if (param_2[1] == *param_2) {
    return 0;
  }
  local_4 = param_1;
  if (param_2 != param_5) {
    FUN_00403200(*param_2,param_2[1]);
  }
  pcVar8 = (char *)*param_2;
  bVar4 = false;
  if (pcVar8 != (char *)param_2[1]) {
    do {
      pcVar6 = (char *)*param_3;
      pcVar2 = (char *)param_3[1];
      if (pcVar6 == pcVar2) {
LAB_004a2057:
        if (bVar4) {
          return 1;
        }
        cVar1 = *pcVar8;
        if (param_4[1] + 1 == param_4[2]) {
          param_5 = (int *)0x1;
          local_4 = param_4[1] - *param_4;
          piVar7 = (int *)&param_5;
          if (local_4 != 0) {
            piVar7 = &local_4;
          }
          FUN_0049be40(*piVar7 + local_4);
        }
        FUN_00402bc0(param_4[1] + 1);
        *(char *)param_4[1] = cVar1;
        param_4[1] = param_4[1] + 1;
      }
      else {
        do {
          if (*pcVar8 == *pcVar6) {
            if (param_4[1] != *param_4) {
              bVar4 = true;
            }
            break;
          }
          pcVar6 = pcVar6 + 1;
        } while (pcVar6 != pcVar2);
        if (pcVar6 == pcVar2) goto LAB_004a2057;
      }
      iVar3 = *piVar5;
      FUN_005092c0(iVar3,iVar3 + 1,piVar5[1] - iVar3);
      pcVar8 = pcVar8 + 1;
      piVar5[1] = piVar5[1] + -1;
    } while (pcVar8 != (char *)param_2[1]);
  }
  return 1;
}


