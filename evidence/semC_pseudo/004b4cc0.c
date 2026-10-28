void __thiscall FUN_004b4cc0(int *param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  bVar5 = true;
  iVar2 = *param_1;
  iVar4 = *(int *)(*param_1 + 4);
  while (iVar4 != 0) {
    iVar2 = FUN_004b5fc0(*param_3,param_3[1],*(undefined4 *)(iVar4 + 0x10),
                         *(undefined4 *)(iVar4 + 0x14));
    bVar5 = iVar2 < 0;
    iVar2 = iVar4;
    if (bVar5) {
      iVar4 = *(int *)(iVar4 + 8);
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xc);
    }
  }
  if (bVar5) {
    if (iVar2 == *(int *)(*param_1 + 8)) {
      if ((iVar2 == *param_1) || (cVar1 = FUN_004b5f50(param_3,iVar2 + 0x10), cVar1 != '\0')) {
        iVar3 = FUN_004b6020(param_3);
        *(int *)(iVar2 + 8) = iVar3;
        iVar4 = *param_1;
        if (iVar2 == iVar4) {
          *(int *)(iVar4 + 4) = iVar3;
          *(int *)(*param_1 + 0xc) = iVar3;
        }
        else if (iVar2 == *(int *)(iVar4 + 8)) {
          *(int *)(iVar4 + 8) = iVar3;
        }
      }
      else {
        iVar3 = FUN_004b6020(param_3);
        *(int *)(iVar2 + 0xc) = iVar3;
        if (iVar2 == *(int *)(*param_1 + 0xc)) {
          *(int *)(*param_1 + 0xc) = iVar3;
        }
      }
      *(int *)(iVar3 + 4) = iVar2;
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
  iVar4 = FUN_004b5fc0(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),*param_3,
                       param_3[1]);
  if (iVar4 < 0) {
    if ((iVar2 == *param_1) || (cVar1 = FUN_004b5f50(param_3,iVar2 + 0x10), cVar1 != '\0')) {
      iVar3 = FUN_004b6020(param_3);
      *(int *)(iVar2 + 8) = iVar3;
      iVar4 = *param_1;
      if (iVar2 == iVar4) {
        *(int *)(iVar4 + 4) = iVar3;
        *(int *)(*param_1 + 0xc) = iVar3;
      }
      else if (iVar2 == *(int *)(iVar4 + 8)) {
        *(int *)(iVar4 + 8) = iVar3;
      }
    }
    else {
      iVar3 = FUN_004b6020(param_3);
      *(int *)(iVar2 + 0xc) = iVar3;
      if (iVar2 == *(int *)(*param_1 + 0xc)) {
        *(int *)(*param_1 + 0xc) = iVar3;
      }
    }
    *(int *)(iVar3 + 4) = iVar2;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_00460be0(iVar3,*param_1 + 4);
    param_1[1] = param_1[1] + 1;
    *param_2 = iVar3;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *param_2 = iVar2;
  *(undefined1 *)(param_2 + 1) = 0;
  return;
}


