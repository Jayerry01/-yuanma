void __thiscall FUN_00460a60(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  bVar2 = true;
  iVar1 = *param_1;
  iVar4 = iVar1;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar3 = *(int *)(iVar1 + 4);
    do {
      iVar4 = iVar3;
      bVar2 = *param_3 < *(int *)(iVar4 + 0x10);
      if (bVar2) {
        iVar3 = *(int *)(iVar4 + 8);
      }
      else {
        iVar3 = *(int *)(iVar4 + 0xc);
      }
    } while (iVar3 != 0);
  }
  if (bVar2) {
    if (iVar4 == *(int *)(iVar1 + 8)) {
      if ((iVar4 == iVar1) || (*param_3 < *(int *)(iVar4 + 0x10))) {
        iVar3 = FUN_00461390(param_3);
        *(int *)(iVar4 + 8) = iVar3;
        iVar1 = *param_1;
        if (iVar4 == iVar1) {
          *(int *)(iVar1 + 4) = iVar3;
          *(int *)(*param_1 + 0xc) = iVar3;
        }
        else if (iVar4 == *(int *)(iVar1 + 8)) {
          *(int *)(iVar1 + 8) = iVar3;
        }
      }
      else {
        iVar3 = FUN_00461390(param_3);
        *(int *)(iVar4 + 0xc) = iVar3;
        if (iVar4 == *(int *)(*param_1 + 0xc)) {
          *(int *)(*param_1 + 0xc) = iVar3;
        }
      }
      *(int *)(iVar3 + 4) = iVar4;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_00460be0(iVar3,*param_1 + 4);
      param_1[1] = param_1[1] + 1;
      *param_2 = iVar3;
      *(undefined1 *)(param_2 + 1) = 1;
      return;
    }
    FUN_0044cf00();
  }
  if (*(int *)(iVar4 + 0x10) < *param_3) {
    if ((iVar4 == iVar1) || (*param_3 < *(int *)(iVar4 + 0x10))) {
      iVar3 = FUN_00461390(param_3);
      *(int *)(iVar4 + 8) = iVar3;
      iVar1 = *param_1;
      if (iVar4 == iVar1) {
        *(int *)(iVar1 + 4) = iVar3;
        *(int *)(*param_1 + 0xc) = iVar3;
      }
      else if (iVar4 == *(int *)(iVar1 + 8)) {
        *(int *)(iVar1 + 8) = iVar3;
      }
    }
    else {
      iVar3 = FUN_00461390(param_3);
      *(int *)(iVar4 + 0xc) = iVar3;
      if (iVar4 == *(int *)(*param_1 + 0xc)) {
        *(int *)(*param_1 + 0xc) = iVar3;
      }
    }
    *(int *)(iVar3 + 4) = iVar4;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_00460be0(iVar3,*param_1 + 4);
    param_1[1] = param_1[1] + 1;
    *param_2 = iVar3;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *param_2 = iVar4;
  *(undefined1 *)(param_2 + 1) = 0;
  return;
}


