void __thiscall FUN_0049c910(int *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = true;
  iVar1 = *param_1;
  iVar3 = iVar1;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    do {
      iVar3 = iVar2;
      bVar4 = *param_3 < *(uint *)(iVar3 + 0x10);
      if (bVar4) {
        iVar2 = *(int *)(iVar3 + 8);
      }
      else {
        iVar2 = *(int *)(iVar3 + 0xc);
      }
    } while (iVar2 != 0);
  }
  if (bVar4) {
    if (iVar3 == *(int *)(iVar1 + 8)) {
      if ((iVar3 == iVar1) || (*param_3 < *(uint *)(iVar3 + 0x10))) {
        iVar2 = FUN_0049f400(param_3);
        *(int *)(iVar3 + 8) = iVar2;
        iVar1 = *param_1;
        if (iVar3 == iVar1) {
          *(int *)(iVar1 + 4) = iVar2;
          *(int *)(*param_1 + 0xc) = iVar2;
        }
        else if (iVar3 == *(int *)(iVar1 + 8)) {
          *(int *)(iVar1 + 8) = iVar2;
        }
      }
      else {
        iVar2 = FUN_0049f400(param_3);
        *(int *)(iVar3 + 0xc) = iVar2;
        if (iVar3 == *(int *)(*param_1 + 0xc)) {
          *(int *)(*param_1 + 0xc) = iVar2;
        }
      }
      *(int *)(iVar2 + 4) = iVar3;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      FUN_00460be0(iVar2,*param_1 + 4);
      param_1[1] = param_1[1] + 1;
      *param_2 = iVar2;
      *(undefined1 *)(param_2 + 1) = 1;
      return;
    }
    FUN_0044cf00();
  }
  if (*(uint *)(iVar3 + 0x10) < *param_3) {
    if ((iVar3 == iVar1) || (*param_3 < *(uint *)(iVar3 + 0x10))) {
      iVar2 = FUN_0049f400(param_3);
      *(int *)(iVar3 + 8) = iVar2;
      iVar1 = *param_1;
      if (iVar3 == iVar1) {
        *(int *)(iVar1 + 4) = iVar2;
        *(int *)(*param_1 + 0xc) = iVar2;
      }
      else if (iVar3 == *(int *)(iVar1 + 8)) {
        *(int *)(iVar1 + 8) = iVar2;
      }
    }
    else {
      iVar2 = FUN_0049f400(param_3);
      *(int *)(iVar3 + 0xc) = iVar2;
      if (iVar3 == *(int *)(*param_1 + 0xc)) {
        *(int *)(*param_1 + 0xc) = iVar2;
      }
    }
    *(int *)(iVar2 + 4) = iVar3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    FUN_00460be0(iVar2,*param_1 + 4);
    param_1[1] = param_1[1] + 1;
    *param_2 = iVar2;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *param_2 = iVar3;
  *(undefined1 *)(param_2 + 1) = 0;
  return;
}


