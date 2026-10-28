void __fastcall FUN_00561f90(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int local_34;
  uint local_30;
  undefined4 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  
  puVar7 = *(undefined4 **)(param_1 + 0x4b8);
  if (puVar7 != (undefined4 *)0x0) {
    piVar5 = (int *)*puVar7;
    iVar6 = puVar7[1];
    iVar8 = 0;
    local_24 = 0;
    local_28 = 0;
    local_20 = 0;
    *(undefined4 *)(param_1 + 0x26c) = 0;
    if (*(char *)(param_1 + 0x256) == '\0') {
      local_10 = *(int *)(param_1 + 0x2f4);
    }
    local_34 = 0;
    if (0 < iVar6) {
      do {
        bVar1 = *(byte *)(local_34 + (int)piVar5);
        local_30 = (uint)bVar1;
        if (bVar1 == 0xaa) {
          bVar1 = *(byte *)(local_34 + 1 + (int)piVar5);
          local_34 = local_34 + 1;
          if (bVar1 == 0) {
            local_30 = 0xaa;
LAB_00562029:
            local_14 = 0;
            local_2c = (undefined4 *)(local_10 + iVar8 * 0x18);
            local_18 = local_2c;
            do {
              if (((local_30 & 1 << ((byte)local_14 & 0x1f)) != 0) &&
                 (iVar8 = local_14 + -1 + local_20, -1 < iVar8)) {
                iVar2 = FUN_0056aee0(iVar8);
                *(int *)(*(int *)(param_1 + 0x2f8) + local_28 * 4) = iVar8;
                puVar7 = (undefined4 *)(iVar2 + 0x10);
                local_1c = 3;
                puVar9 = local_2c + 4;
                do {
                  puVar3 = (undefined4 *)FUN_0056af20(*puVar7);
                  puVar7 = puVar7 + 1;
                  *local_2c = *puVar3;
                  local_2c[1] = puVar3[1];
                  local_2c[2] = puVar3[2];
                  puVar9[-1] = puVar3[6];
                  *puVar9 = puVar3[7];
                  puVar9[1] = puVar3[8];
                  local_2c = local_2c + 6;
                  local_1c = local_1c + -1;
                  puVar9 = puVar9 + 6;
                } while (local_1c != 0);
                local_28 = local_28 + 1;
                local_24 = local_24 + 3;
                local_2c = local_18 + 0x12;
                *(int *)(param_1 + 0x26c) = *(int *)(param_1 + 0x26c) + 1;
                local_18 = local_2c;
              }
              local_14 = local_14 + 1;
              iVar8 = local_24;
            } while (local_14 < 8);
            goto LAB_00562131;
          }
          local_20 = local_20 + (uint)bVar1 * 8;
        }
        else {
          if (bVar1 != 0) goto LAB_00562029;
LAB_00562131:
          local_20 = local_20 + 8;
        }
        local_34 = local_34 + 1;
      } while (local_34 < iVar6);
    }
    piVar4 = (int *)FUN_0056aee0(**(undefined4 **)(param_1 + 0x2f8));
    piVar10 = *(int **)(param_1 + 0x288);
    iVar6 = 0;
    local_20 = 0;
    *(undefined4 *)(param_1 + 0x280) = 0;
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x27c) = 0;
    *(undefined4 *)(param_1 + 0x278) = 0;
    local_34 = 0;
    if (0 < *(int *)(param_1 + 0x26c)) {
      do {
        piVar5 = (int *)FUN_0056aee0(*(undefined4 *)(*(int *)(param_1 + 0x2f8) + local_34 * 4));
        if ((piVar4[2] != piVar5[2]) || (*piVar4 != *piVar5)) {
          *piVar10 = piVar4[2];
          piVar10[2] = piVar4[3];
          piVar10[1] = *piVar4;
          piVar10[3] = piVar4[1];
          piVar10[8] = iVar6;
          piVar10[6] = local_34 - iVar6;
          piVar10[10] = iVar6 * 3;
          piVar10[9] = iVar6 * 3;
          piVar10[5] = (local_34 - iVar6) * 3;
          if (*(char *)(piVar10[2] + 0x11) == '\0') {
            if (*(int *)(piVar10[2] + 4) == 1) {
              *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + 1;
            }
          }
          else {
            *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;
          }
          piVar10 = piVar10 + 0xc;
          local_20 = local_20 + iVar6;
          *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
          iVar6 = 0;
          piVar4 = piVar5;
        }
        iVar6 = iVar6 + 1;
        local_34 = local_34 + 1;
      } while (local_34 < *(int *)(param_1 + 0x26c));
    }
    if (local_20 < *(int *)(param_1 + 0x26c)) {
      *piVar10 = piVar5[2];
      piVar10[2] = piVar5[3];
      piVar10[1] = *piVar5;
      piVar10[3] = piVar5[1];
      piVar10[8] = iVar6;
      piVar10[6] = local_34 - iVar6;
      piVar10[5] = (local_34 - iVar6) * 3;
      piVar10[10] = iVar6 * 3;
      piVar10[9] = iVar6 * 3;
      if (*(char *)(piVar10[2] + 0x11) == '\0') {
        if (*(int *)(piVar10[2] + 4) == 1) {
          *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + 1;
        }
      }
      else {
        *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;
      }
      *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
    }
    *(int *)(param_1 + 0x27c) =
         (*(int *)(param_1 + 0x278) - *(int *)(param_1 + 0x280)) - *(int *)(param_1 + 0x284);
    FUN_0050af1e(*(undefined4 *)(param_1 + 0x288),*(int *)(param_1 + 0x278),0x30,FUN_0056a040);
    *(undefined4 *)(param_1 + 0x4bc) = *(undefined4 *)(param_1 + 0x4b8);
  }
  return;
}


