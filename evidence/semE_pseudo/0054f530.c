undefined4 __thiscall FUN_0054f530(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_4;
  
  local_4 = param_1;
  local_4 = *(int *)(param_1 + 4);
  iVar2 = local_4;
  iVar1 = *(int *)(local_4 + 4);
  while (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x10) < param_2) {
      iVar1 = *(int *)(iVar1 + 0xc);
    }
    else {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar1 + 8);
    }
  }
  if ((iVar2 == local_4) || (param_2 < *(int *)(iVar2 + 0x10))) {
    piVar3 = &local_4;
  }
  else {
    piVar3 = &param_2;
  }
  if (*piVar3 != *(int *)(param_1 + 4)) {
    return *(undefined4 *)(*piVar3 + 0x14);
  }
  return 0;
}


