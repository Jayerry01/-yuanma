void __thiscall FUN_005622f0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  undefined4 *local_1c;
  float *local_18;
  int local_14;
  
  FUN_0056ad30(param_2);
  iVar4 = *(int *)(param_2 + 0xc);
  FUN_004748b0();
  if (*(int *)(iVar4 + 0x1e4) == 1) {
    local_18 = (float *)0x0;
    fVar1 = *(float *)(*(int *)(param_1 + 0x120) + 0xd0);
    fVar2 = *(float *)(iVar4 + 0x1f0);
    pfVar9 = (float *)(*(int *)(param_1 + 0x2f4) + *(int *)(param_2 + 0x14) * 0x18);
    fVar3 = *(float *)(iVar4 + 500);
    if (0 < *(int *)(param_2 + 0x20)) {
      do {
        iVar5 = FUN_0056aee0(*(undefined4 *)
                              (*(int *)(param_1 + 0x2f8) +
                              (*(int *)(param_2 + 0x18) + (int)local_18) * 4));
        local_1c = (undefined4 *)(iVar5 + 0x10);
        local_14 = 3;
        pfVar8 = pfVar9;
        do {
          pfVar6 = (float *)FUN_0056af20(*local_1c);
          fVar10 = (float10)FUN_00567360(iVar4,pfVar6,*(undefined4 *)(iVar4 + 0x1e8));
          local_1c = local_1c + 1;
          pfVar9 = pfVar8 + 6;
          local_14 = local_14 + -1;
          fVar10 = (float10)fsin(fVar10 * (float10)(1.0 / (fVar3 * 6.2831855)) +
                                 (float10)(fVar1 * fVar2 * 6.2831855));
          fVar10 = fVar10 * (float10)*(float *)(iVar4 + 0x1ec);
          *pfVar8 = (float)(fVar10 + (float10)*pfVar6);
          pfVar8[1] = (float)(fVar10 + (float10)pfVar6[1]);
          pfVar8[2] = (float)(fVar10 + (float10)pfVar6[2]);
          pfVar8 = pfVar9;
        } while (local_14 != 0);
        local_18 = (float *)((int)local_18 + 1);
      } while ((int)local_18 < *(int *)(param_2 + 0x20));
    }
  }
  if (*(char *)(iVar4 + 0x1c4) != '\0') {
    local_1c = (undefined4 *)0x0;
    if (0 < *(int *)(param_2 + 0x20)) {
      local_18 = (float *)(*(int *)(param_1 + 0x2f4) + *(int *)(param_2 + 0x14) * 0x18 + 0x10);
      do {
        iVar5 = FUN_0056aee0(*(undefined4 *)
                              (*(int *)(param_1 + 0x2f8) +
                              (*(int *)(param_2 + 0x18) + (int)local_1c) * 4));
        puVar7 = (undefined4 *)(iVar5 + 0x10);
        local_14 = 3;
        pfVar9 = local_18;
        do {
          iVar5 = FUN_0056af20(*puVar7);
          puVar7 = puVar7 + 1;
          fVar1 = *(float *)(*(int *)(param_1 + 0x120) + 0xd0);
          fVar2 = *(float *)(iVar4 + 0x1cc);
          fVar3 = *(float *)(iVar5 + 0x20);
          *pfVar9 = fVar1 * *(float *)(iVar4 + 0x1c8) + *(float *)(iVar5 + 0x1c);
          local_14 = local_14 + -1;
          pfVar9[1] = fVar1 * fVar2 + fVar3;
          pfVar9 = pfVar9 + 6;
        } while (local_14 != 0);
        local_1c = (undefined4 *)((int)local_1c + 1);
        local_18 = local_18 + 0x12;
      } while ((int)local_1c < *(int *)(param_2 + 0x20));
    }
  }
  return;
}



void __thiscall thunk_FUN_0056adf0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  if (((*(int *)(*(int *)(param_2 + 0xc) + 0x1d0) != 0) ||
      (*(int *)(*(int *)(param_2 + 0xc) + 0x1f8) == 2)) || (*(char *)(param_1 + 0x124) != '\0')) {
    FUN_00474470();
  }
  if (*(char *)(iVar1 + 0x10) != '\0') {
    FUN_00475590(2,1);
  }
  return;
}


