undefined4 __fastcall FUN_004f24b0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  int local_4;
  
  uVar1 = param_1[0x95];
  iVar2 = FUN_00487830();
  iVar2 = *(int *)(iVar2 + 0x22ec);
  local_8 = iVar2;
  iVar4 = *(int *)(iVar2 + 4);
  while (iVar4 != 0) {
    if (*(uint *)(iVar4 + 0x10) < uVar1) {
      iVar4 = *(int *)(iVar4 + 0xc);
    }
    else {
      local_8 = iVar4;
      iVar4 = *(int *)(iVar4 + 8);
    }
  }
  if ((local_8 == iVar2) || (uVar1 < *(uint *)(local_8 + 0x10))) {
    local_4 = iVar2;
    piVar3 = &local_4;
  }
  else {
    piVar3 = &local_8;
  }
  iVar2 = *piVar3;
  iVar4 = FUN_00487830();
  if ((iVar2 != *(int *)(iVar4 + 0x22ec)) &&
     (iVar4 = (**(code **)(*(int *)(iVar2 + 0x88) + 0x10))(), iVar4 != 0)) {
    (**(code **)(*param_1 + 0xa8))(*(undefined4 *)(*(int *)(iVar2 + 0xc4) + 0x28),1);
    return 1;
  }
  return 0;
}


