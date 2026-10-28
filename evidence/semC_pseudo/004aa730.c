undefined2 * __thiscall FUN_004aa730(int param_1,uint *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar6;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *piVar7;
  int iVar8;
  undefined2 *puVar9;
  int *piVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined1 local_45;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  undefined2 *local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059fd48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005005b0(&local_45);
  local_4 = 0;
  FUN_004b48c0(&local_44);
  if (local_44 != *(int *)(param_1 + 4)) {
    do {
      uVar1 = *(undefined4 *)(local_44 + 0xd8);
      local_34 = 0;
      puVar3 = (undefined4 *)FUN_004e8720(local_1c);
      FUN_0046ef50(*puVar3,uVar1,&local_34);
      local_40 = (*(int *)(local_44 + 0xd0) - *(int *)(local_44 + 0xcc)) / 0x48 + local_34;
      if ((short)local_40 != 0) {
        local_30 = CONCAT22((short)((uint)local_44 >> 0x10),*(undefined2 *)(local_44 + 0x10));
        if (local_14 == local_10) {
          FUN_004b57c0(local_14,&local_30);
        }
        else {
          FUN_004b5f30(local_14,&local_30);
          local_14 = local_14 + 1;
        }
        if (local_14 == local_10) {
          FUN_004b57c0(local_14,&local_40);
        }
        else {
          FUN_004b5f30(local_14,&local_40);
          local_14 = local_14 + 1;
        }
        piVar7 = *(int **)(local_44 + 0xd8);
        piVar10 = (int *)*piVar7;
        if (piVar10 != piVar7) {
          do {
            local_2c = CONCAT22((short)((uint)piVar7 >> 0x10),(short)piVar10[0xd]);
            if (local_14 == local_10) {
              FUN_004b57c0(local_14,&local_2c);
              uVar6 = extraout_var_00;
            }
            else {
              FUN_004b5f30(local_14,&local_2c);
              local_14 = local_14 + 1;
              uVar6 = extraout_var;
            }
            local_28 = CONCAT22(uVar6,(short)piVar10[0xc]);
            if (local_14 == local_10) {
              FUN_004b57c0(local_14,&local_28);
            }
            else {
              FUN_004b5f30(local_14,&local_28);
              local_14 = local_14 + 1;
            }
            piVar2 = (int *)piVar10[0xf];
            for (piVar7 = (int *)piVar10[0xe]; (piVar7 != piVar2 && (*piVar7 != 2));
                piVar7 = piVar7 + 3) {
            }
            local_3c = 0;
            uVar4 = -(uint)(piVar7 != piVar2) & (uint)piVar7;
            if (uVar4 != 0) {
              local_3c = CONCAT22((short)((uint)piVar2 >> 0x10),*(undefined2 *)(uVar4 + 4));
            }
            if (local_14 == local_10) {
              FUN_004b57c0(local_14,&local_3c);
              piVar7 = extraout_EDX_00;
            }
            else {
              FUN_004b5f30(local_14,&local_3c);
              local_14 = local_14 + 1;
              piVar7 = extraout_EDX;
            }
            piVar10 = (int *)*piVar10;
          } while (piVar10 != (int *)*(int *)(local_44 + 0xd8));
        }
        iVar11 = *(int *)(local_44 + 0xcc);
        iVar8 = *(int *)(local_44 + 0xd0);
        if (iVar11 != *(int *)(local_44 + 0xd0)) {
          do {
            local_24 = CONCAT22((short)((uint)iVar8 >> 0x10),*(undefined2 *)(iVar11 + 0x2c));
            if (local_14 == local_10) {
              FUN_004b57c0(local_14,&local_24);
              uVar6 = extraout_var_02;
            }
            else {
              FUN_004b5f30(local_14,&local_24);
              local_14 = local_14 + 1;
              uVar6 = extraout_var_01;
            }
            local_20 = CONCAT22(uVar6,*(undefined2 *)(iVar11 + 0x28));
            if (local_14 == local_10) {
              FUN_004b57c0(local_14,&local_20);
            }
            else {
              FUN_004b5f30(local_14,&local_20);
              local_14 = local_14 + 1;
            }
            piVar10 = *(int **)(iVar11 + 0x34);
            for (piVar7 = *(int **)(iVar11 + 0x30); (piVar7 != piVar10 && (*piVar7 != 2));
                piVar7 = piVar7 + 3) {
            }
            local_38 = 0;
            uVar4 = -(uint)(piVar7 != piVar10) & (uint)piVar7;
            if (uVar4 != 0) {
              local_38 = CONCAT22((short)((uint)piVar10 >> 0x10),*(undefined2 *)(uVar4 + 4));
            }
            if (local_14 == local_10) {
              FUN_004b57c0(local_14,&local_38);
            }
            else {
              FUN_004b5f30(local_14,&local_38);
              local_14 = local_14 + 1;
            }
            iVar11 = iVar11 + 0x48;
            iVar8 = local_44;
          } while (iVar11 != *(int *)(local_44 + 0xd0));
        }
      }
      FUN_0043c6c0();
    } while (local_44 != *(int *)(param_1 + 4));
  }
  uVar4 = ((int)local_14 - (int)local_18 >> 1) * 2;
  puVar12 = (undefined2 *)0x0;
  *param_2 = uVar4;
  if (uVar4 != 0) {
    puVar12 = operator_new(uVar4);
    puVar9 = puVar12;
    for (puVar5 = local_18; puVar5 != local_14; puVar5 = puVar5 + 1) {
      *puVar9 = *puVar5;
      puVar9 = puVar9 + 1;
    }
  }
  local_4 = 0xffffffff;
  iVar11 = (int)local_10 - (int)local_18 >> 1;
  if (iVar11 != 0) {
    FUN_00402e90(local_18,iVar11 * 2);
  }
  ExceptionList = local_c;
  return puVar12;
}


