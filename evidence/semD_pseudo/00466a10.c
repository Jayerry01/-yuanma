undefined4 __thiscall FUN_00466a10(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 auStack_28 [5];
  undefined4 uStack_14;
  undefined4 uStack_10;
  int local_4;
  
  uVar3 = in_stack_00000018;
  local_4 = param_1;
  iVar5 = *(int *)(param_1 + 0x20);
  iVar2 = iVar5;
  iVar1 = *(int *)(iVar5 + 4);
  while (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x10) < in_stack_00000018) {
      iVar1 = *(int *)(iVar1 + 0xc);
    }
    else {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar1 + 8);
    }
  }
  in_stack_00000018 = iVar2;
  if ((iVar2 == iVar5) || (uVar3 < *(uint *)(iVar2 + 0x10))) {
    local_4 = iVar5;
    piVar4 = &local_4;
  }
  else {
    piVar4 = (int *)&stack0x00000018;
  }
  if ((*piVar4 != *(int *)(param_1 + 0x20)) && (*(int *)(*piVar4 + 0x14) != 0)) {
    uStack_10 = in_stack_00000020;
    uStack_14 = in_stack_0000001c;
    puVar6 = auStack_28;
    for (iVar5 = 5; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar5 != 0;
        iVar5 = iVar5 + -1) {
      *puVar6 = *(undefined4 *)register0x00000010;
      puVar6 = puVar6 + 1;
    }
    FUN_00466d70();
  }
  return 1;
}


