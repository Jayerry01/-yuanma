void __fastcall FUN_0054bd90(int param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  DWORD DStack_20;
  int iStack_1c;
  DWORD DStack_18;
  int aiStack_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_005a4618;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd0) + 0x38))();
  if (iVar1 != 0) {
    iStack_1c = iVar1;
    DVar2 = timeGetTime();
    DStack_18 = DVar2;
    FUN_00553830();
    DAT_0072489c = 7;
    DStack_20 = DVar2;
    FUN_005538e0(&DStack_20,4);
    FUN_00553920(*(undefined4 *)(param_1 + 0xbc));
    if (iVar1 <= *(int *)(param_1 + 0xd4)) {
      *(undefined4 *)(param_1 + 0xd4) = 0;
    }
    DStack_20 = 0;
    do {
      if (iVar1 <= *(int *)(param_1 + 0xd4)) break;
      FUN_004736a0();
      uStack_4 = 0;
      (**(code **)(**(int **)(param_1 + 0xd0) + 0x3c))(*(undefined4 *)(param_1 + 0xd4),aiStack_14);
      *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
      uVar7 = 0;
      iVar3 = *(int *)(param_1 + 0x150) - *(int *)(param_1 + 0x14c);
      iVar6 = iVar3 >> 0x1f;
      if (iVar3 / 0x18 + iVar6 != iVar6) {
        iVar6 = 0;
        do {
          iVar1 = iStack_1c;
          if ((*(int *)(iVar6 + *(int *)(param_1 + 0x14c)) == aiStack_14[0]) &&
             (*(short *)(iVar6 + 4 + *(int *)(param_1 + 0x14c)) == (short)aiStack_14[1]))
          goto LAB_0054befb;
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 0x18;
        } while (uVar7 < (uint)((*(int *)(param_1 + 0x150) - *(int *)(param_1 + 0x14c)) / 0x18));
      }
      piVar8 = aiStack_14;
      uVar4 = FUN_00553870(piVar8);
      uVar5 = FUN_00553880(uVar4);
      FUN_005547a0(uVar5,uVar4,piVar8);
      DStack_20 = DStack_20 + 1;
LAB_0054befb:
      uStack_4 = 0xffffffff;
    } while ((int)DStack_20 < 0x14);
    if ((0x14 < iVar1) && (*(int *)(param_1 + 0xd4) == iVar1)) {
      *(DWORD *)(param_1 + 0xd8) = DStack_18 + 3000;
      ExceptionList = pvStack_c;
      return;
    }
    *(DWORD *)(param_1 + 0xd8) = DStack_18;
  }
  ExceptionList = pvStack_c;
  return;
}


