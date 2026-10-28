undefined4 __thiscall FUN_00493de0(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_4;
  
  local_4 = param_1;
  local_4 = *(int *)(param_1 + 0x2188);
  iVar2 = local_4;
  iVar1 = *(int *)(local_4 + 4);
  while (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x10) < param_2) {
      iVar1 = *(int *)(iVar1 + 0xc);
    }
    else {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar1 + 8);
    }
  }
  if ((iVar2 == local_4) || (param_2 < *(uint *)(iVar2 + 0x10))) {
    piVar3 = &local_4;
  }
  else {
    piVar3 = (int *)&param_2;
  }
  if (*piVar3 != *(int *)(param_1 + 0x2188)) {
    return *(undefined4 *)(*piVar3 + 0x14);
  }
  return 0;
}


