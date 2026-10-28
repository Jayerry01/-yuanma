int * __thiscall FUN_0049b400(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059f1d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 0;
  puVar3 = (undefined1 *)FUN_00402bf0(0x20);
  *param_1 = (int)puVar3;
  param_1[1] = 0;
  local_4 = 0;
  *(char *)(param_1 + 2) = (char)param_2[2];
  iVar1 = *(int *)(*param_2 + 4);
  *puVar3 = 0;
  if (iVar1 == 0) {
    *(undefined4 *)(*param_1 + 4) = 0;
    *(int *)(*param_1 + 8) = *param_1;
    *(int *)(*param_1 + 0xc) = *param_1;
  }
  else {
    iVar1 = *param_1;
    uVar4 = FUN_0049cd30(*(undefined4 *)(*param_2 + 4),iVar1);
    *(undefined4 *)(iVar1 + 4) = uVar4;
    iVar1 = *(int *)(*param_1 + 4);
    for (iVar2 = *(int *)(iVar1 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      iVar1 = iVar2;
    }
    *(int *)(*param_1 + 8) = iVar1;
    iVar1 = *(int *)(*param_1 + 4);
    for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      iVar1 = iVar2;
    }
    *(int *)(*param_1 + 0xc) = iVar1;
  }
  param_1[1] = param_2[1];
  ExceptionList = local_c;
  return param_1;
}


