void __fastcall FUN_004c2120(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_14;
  int local_10;
  
  iVar3 = (*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24;
  if (0 < iVar3) {
    local_14 = 0;
    local_10 = iVar3;
    do {
      iVar6 = *(int *)(local_14 + 0x1c + *(int *)(param_1 + 0x4fc));
      piVar1 = (int *)(local_14 + 0x18 + *(int *)(param_1 + 0x4fc));
      iVar2 = piVar1[1];
      iVar5 = *piVar1;
      for (iVar4 = iVar5; iVar4 != iVar2; iVar4 = iVar4 + 8) {
        FUN_004c68d0(0);
      }
      local_14 = local_14 + 0x24;
      local_10 = local_10 + -1;
      piVar1[1] = piVar1[1] + (iVar6 - iVar5 >> 3) * -8;
    } while (local_10 != 0);
  }
  iVar6 = 0;
  if (0 < iVar3) {
    do {
      iVar5 = 0;
      if (0 < iVar6) {
        do {
          FUN_004c1900(iVar5,iVar6);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar6);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
  }
  FUN_004c2450();
  FUN_004c2a30();
  return;
}


