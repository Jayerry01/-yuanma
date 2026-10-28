int * __thiscall FUN_0054f7e0(int *param_1,int *param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_19;
  int local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  int local_8 [2];
  
  piVar4 = param_4;
  iVar6 = param_3;
  iVar5 = *param_1;
  if (param_3 != *(int *)(iVar5 + 8)) {
    if (param_3 == iVar5) {
      iVar6 = *(int *)(iVar5 + 0xc);
      if (*(int *)(iVar6 + 0x10) < *param_4) {
        if ((iVar6 == iVar5) || (*param_4 < *(int *)(iVar6 + 0x10))) {
          iVar2 = FUN_0054fda0(param_4);
          *(int *)(iVar6 + 8) = iVar2;
          iVar5 = *param_1;
          if (iVar6 == iVar5) {
            *(int *)(iVar5 + 4) = iVar2;
            *(int *)(*param_1 + 0xc) = iVar2;
          }
          else if (iVar6 == *(int *)(iVar5 + 8)) {
            *(int *)(iVar5 + 8) = iVar2;
          }
        }
        else {
          iVar2 = FUN_0054fda0(param_4);
          *(int *)(iVar6 + 0xc) = iVar2;
          if (iVar6 == *(int *)(*param_1 + 0xc)) {
            *(int *)(*param_1 + 0xc) = iVar2;
          }
        }
        *(int *)(iVar2 + 4) = iVar6;
        *(undefined4 *)(iVar2 + 8) = 0;
        *(undefined4 *)(iVar2 + 0xc) = 0;
        FUN_00460be0(iVar2,*param_1 + 4);
        param_1[1] = param_1[1] + 1;
        *param_2 = iVar2;
        return param_2;
      }
    }
    else {
      FUN_0044cf00();
      if ((*(int *)(param_3 + 0x10) < *param_4) && (*param_4 < *(int *)(iVar6 + 0x10))) {
        if (*(int *)(param_3 + 0xc) != 0) {
          FUN_0054fa60(param_2,iVar6,iVar6,param_4);
          return param_2;
        }
        FUN_0054fa60(param_2,0,param_3,param_4);
        return param_2;
      }
    }
    piVar4 = (int *)FUN_0054fc20(local_8,param_4);
    *param_2 = *piVar4;
    return param_2;
  }
  if ((param_1[1] != 0) && (*param_4 < *(int *)(param_3 + 0x10))) {
    iVar2 = FUN_0054fda0(param_4);
    *(int *)(iVar6 + 8) = iVar2;
    iVar5 = *param_1;
    if (iVar6 == iVar5) {
      *(int *)(iVar5 + 4) = iVar2;
      *(int *)(*param_1 + 0xc) = iVar2;
    }
    else if (iVar6 == *(int *)(iVar5 + 8)) {
      *(int *)(iVar5 + 8) = iVar2;
    }
    *(int *)(iVar2 + 4) = iVar6;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    FUN_00460be0(iVar2,*param_1 + 4);
    param_1[1] = param_1[1] + 1;
    *param_2 = iVar2;
    return param_2;
  }
  bVar1 = true;
  if (*(int *)(iVar5 + 4) != 0) {
    iVar6 = *(int *)(iVar5 + 4);
    do {
      iVar5 = iVar6;
      bVar1 = *param_4 < *(int *)(iVar5 + 0x10);
      if (bVar1) {
        iVar6 = *(int *)(iVar5 + 8);
      }
      else {
        iVar6 = *(int *)(iVar5 + 0xc);
      }
    } while (iVar6 != 0);
  }
  local_18 = iVar5;
  if (bVar1) {
    piVar3 = (int *)FUN_004b48c0(local_14);
    if (local_18 == *piVar3) {
      puVar7 = &param_4;
      param_4 = (int *)CONCAT31(param_4._1_3_,1);
      piVar4 = (int *)FUN_0054fa60(local_10,0,iVar5,piVar4);
      goto LAB_0054f904;
    }
    FUN_0044cf00();
  }
  if (*(int *)(local_18 + 0x10) < *piVar4) {
    puVar7 = &param_3;
    param_3 = CONCAT31(param_3._1_3_,1);
    piVar4 = (int *)FUN_0054fa60(local_c,0,iVar5,piVar4);
  }
  else {
    puVar7 = (undefined4 *)&local_19;
    piVar4 = &local_18;
    local_19 = 0;
  }
LAB_0054f904:
  FUN_0046ef70(piVar4,puVar7);
  *param_2 = local_8[0];
  return param_2;
}


