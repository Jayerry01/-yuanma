void __fastcall FUN_004a3350(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_4;
  
  puVar4 = *(undefined4 **)(param_1 + 0x19c);
  local_4 = param_1;
  if (puVar4 != *(undefined4 **)(param_1 + 0x1a0)) {
    do {
      FUN_0049d3c0(&local_4,puVar4);
      if ((local_4 == *(int *)(param_1 + 0x1a8)) || (*(int *)(local_4 + 0x14) == 0)) {
        FUN_0040f870(*puVar4);
      }
      puVar4 = puVar4 + 1;
    } while (puVar4 != *(undefined4 **)(param_1 + 0x1a0));
  }
  iVar5 = *(int *)(param_1 + 0x19c);
  iVar3 = *(int *)(param_1 + 0x1a0);
  FUN_004a8b00(iVar3,iVar3,iVar5);
  piVar1 = (int *)(param_1 + 0x1a8);
  *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + (iVar3 - iVar5 >> 2) * -4;
  if (*(int *)(param_1 + 0x1ac) != 0) {
    FUN_0049c2f0(*(undefined4 *)(*piVar1 + 4));
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(int *)(*piVar1 + 0xc) = *piVar1;
    *(undefined4 *)(param_1 + 0x1ac) = 0;
  }
  piVar1 = (int *)(param_1 + 0x1b4);
  iVar5 = *(int *)(*(int *)(param_1 + 0x1b4) + 8);
  if (iVar5 != *(int *)(param_1 + 0x1b4)) {
    do {
      FUN_0040f870(*(undefined4 *)(iVar5 + 0x14));
      iVar3 = *(int *)(iVar5 + 0xc);
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar5 + 4);
        if (iVar5 == *(int *)(iVar3 + 0xc)) {
          do {
            iVar5 = iVar3;
            iVar3 = *(int *)(iVar5 + 4);
          } while (iVar5 == *(int *)(iVar3 + 0xc));
        }
        if (*(int *)(iVar5 + 0xc) != iVar3) {
          iVar5 = iVar3;
        }
      }
      else {
        for (iVar2 = *(int *)(iVar3 + 8); iVar5 = iVar3, iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          iVar3 = iVar2;
        }
      }
    } while (iVar5 != *piVar1);
  }
  if (*(int *)(param_1 + 0x1b8) != 0) {
    iVar5 = *(int *)(*piVar1 + 4);
    while (iVar5 != 0) {
      FUN_0049c2f0(*(undefined4 *)(iVar5 + 0xc));
      iVar3 = *(int *)(iVar5 + 8);
      FUN_00402e90(iVar5,0x18);
      iVar5 = iVar3;
    }
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(int *)(*piVar1 + 0xc) = *piVar1;
    *(undefined4 *)(param_1 + 0x1b8) = 0;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
