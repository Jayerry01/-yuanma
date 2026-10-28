FUN_00466340(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_4;
  
  uVar4 = param_3;
  local_4 = param_1;
  iVar1 = *(int *)(param_1 + 0x20);
  iVar3 = iVar1;
  iVar2 = *(int *)(iVar1 + 4);
  while (iVar2 != 0) {
    if (*(uint *)(iVar2 + 0x10) < param_3) {
      iVar2 = *(int *)(iVar2 + 0xc);
    }
    else {
      iVar3 = iVar2;
      iVar2 = *(int *)(iVar2 + 8);
    }
  }
  if ((iVar3 == iVar1) || (param_3 < *(uint *)(iVar3 + 0x10))) {
    local_4 = iVar1;
    piVar5 = &local_4;
  }
  else {
    piVar5 = (int *)&param_3;
  }
  if ((*piVar5 != *(int *)(param_1 + 0x20)) && (*(int *)(*piVar5 + 0x14) != 0)) {
    param_3 = iVar3;
    FUN_00466c60(param_2,uVar4,param_4,param_5,param_6);
  }
  return 1;
}


