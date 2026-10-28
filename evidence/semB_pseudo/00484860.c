FUN_00484860(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  char local_584;
  undefined2 uStack_582;
  undefined2 uStack_580;
  uint local_57c;
  int local_578;
  uint local_574;
  uint local_570;
  uint *local_568;
  uint local_564;
  uint *local_55c;
  int local_554;
  uint local_550;
  uint local_548 [17];
  uint local_504 [16];
  uint auStack_4c4 [17];
  uint local_480 [288];
  
  uVar13 = CONCAT22(uStack_580,uStack_582);
  puVar6 = local_548;
  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar18 = 0;
  piVar8 = param_1;
  for (uVar15 = param_2; uVar15 != 0; uVar15 = uVar15 - 1) {
    iVar7 = *piVar8;
    piVar8 = piVar8 + 1;
    local_548[iVar7] = local_548[iVar7] + 1;
  }
  if (local_548[0] == param_2) {
    *param_6 = 0;
    *param_7 = 0;
    return 0;
  }
  local_574 = 1;
  do {
    if (local_548[local_574] != 0) break;
    local_574 = local_574 + 1;
  } while (local_574 < 0x11);
  local_57c = *param_7;
  if (*param_7 < local_574) {
    local_57c = local_574;
  }
  uVar15 = 0x10;
  do {
    if (local_548[uVar15] != 0) break;
    uVar15 = uVar15 - 1;
  } while (uVar15 != 0);
  if (uVar15 < local_57c) {
    local_57c = uVar15;
  }
  *param_7 = local_57c;
  iVar7 = 1 << ((byte)local_574 & 0x1f);
  for (uVar9 = local_574; uVar9 < uVar15; uVar9 = uVar9 + 1) {
    if ((int)(iVar7 - local_548[uVar9]) < 0) {
      return 1;
    }
    iVar7 = (iVar7 - local_548[uVar9]) * 2;
  }
  iVar7 = iVar7 - local_548[uVar15];
  if (iVar7 < 0) {
    return 1;
  }
  iVar3 = 0;
  local_548[uVar15] = local_548[uVar15] + iVar7;
  local_504[1] = 0;
  if (uVar15 != 0) {
    iVar7 = 0;
    uVar9 = uVar15;
    do {
      iVar3 = iVar3 + *(int *)((int)local_548 + iVar7 + 4);
      uVar9 = uVar9 - 1;
      *(int *)((int)local_504 + iVar7 + 8) = iVar3;
      iVar7 = iVar7 + 4;
    } while (uVar9 != 0);
  }
  uVar9 = 0;
  if (param_2 != 0) {
    do {
      iVar7 = *param_1;
      param_1 = param_1 + 1;
      if (iVar7 != 0) {
        uVar10 = local_504[iVar7];
        local_480[uVar10] = uVar9;
        local_504[iVar7] = uVar10 + 1;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_2);
  }
  local_568 = local_480;
  iVar7 = -1;
  local_564 = 0;
  iVar3 = -local_57c;
  local_504[0] = 0;
  local_578 = -1;
  auStack_4c4[1] = 0;
  local_550 = 0;
  if ((int)local_574 <= (int)uVar15) {
    local_554 = local_574 - 1;
    local_55c = local_548 + local_574;
    do {
      if (*local_55c != 0) {
        uVar9 = 1 << ((byte)local_554 & 0x1f);
        local_570 = *local_55c;
        do {
          uVar10 = local_570 - 1;
          if ((int)(iVar3 + local_57c) < (int)local_574) {
            iVar11 = iVar3 - local_57c;
            iVar17 = iVar7;
            iVar12 = iVar3 + local_57c;
            do {
              local_578 = iVar12;
              iVar11 = iVar11 + local_57c;
              iVar3 = iVar3 + local_57c;
              iVar7 = iVar17 + 1;
              iVar12 = local_578 + local_57c;
              uVar18 = uVar15 - iVar3;
              if (local_57c < uVar15 - iVar3) {
                uVar18 = local_57c;
              }
              uVar16 = local_574 - iVar3;
              uVar4 = 1 << ((byte)uVar16 & 0x1f);
              if (local_570 < uVar4) {
                iVar5 = uVar4 + (-1 - uVar10);
                puVar6 = local_55c;
                while (uVar16 = uVar16 + 1, uVar16 < uVar18) {
                  puVar1 = puVar6 + 1;
                  puVar6 = puVar6 + 1;
                  if ((uint)(iVar5 * 2) <= *puVar1) break;
                  iVar5 = iVar5 * 2 - *puVar1;
                }
              }
              uVar18 = 1 << ((byte)uVar16 & 0x1f);
              iVar5 = FUN_00484400((uVar18 * 3 + 3) * 2);
              local_550 = iVar5 + 6;
              puVar6 = (uint *)(iVar5 + 2);
              *param_6 = local_550;
              *puVar6 = 0;
              auStack_4c4[iVar17 + 2] = local_550;
              if (iVar7 != 0) {
                uStack_582 = (undefined2)local_550;
                uStack_580 = (undefined2)(local_550 >> 0x10);
                local_504[iVar7] = local_564;
                puVar14 = (undefined4 *)
                          (auStack_4c4[iVar7] + (local_564 >> ((byte)iVar11 & 0x1f)) * 6);
                *puVar14 = CONCAT22(uStack_582,CONCAT11((undefined1)local_57c,(byte)uVar16 + 0x10));
                *(undefined2 *)(puVar14 + 1) = uStack_580;
                uVar13 = local_550;
              }
              iVar17 = iVar7;
              param_6 = puVar6;
              local_578 = iVar7;
            } while (iVar12 < (int)local_574);
          }
          bVar2 = (byte)iVar3;
          if (local_568 < local_480 + param_2) {
            uVar13 = *local_568;
            if (uVar13 < param_3) {
              local_584 = (uVar13 < 0x100) + '\x0f';
            }
            else {
              iVar17 = (uVar13 - param_3) * 4;
              local_584 = *(char *)(iVar17 + param_5);
              uVar13 = *(uint *)(iVar17 + param_4);
            }
            local_568 = local_568 + 1;
          }
          else {
            local_584 = 'c';
          }
          uStack_580 = (undefined2)(uVar13 >> 0x10);
          uStack_582 = (undefined2)uVar13;
          iVar17 = 1 << ((char)local_574 - bVar2 & 0x1f);
          uVar16 = local_564 >> (bVar2 & 0x1f);
          if (uVar16 < uVar18) {
            puVar14 = (undefined4 *)(local_550 + uVar16 * 6);
            do {
              uVar16 = uVar16 + iVar17;
              *puVar14 = CONCAT22(uStack_582,CONCAT11((char)local_574 - bVar2,local_584));
              *(undefined2 *)(puVar14 + 1) = uStack_580;
              puVar14 = (undefined4 *)((int)puVar14 + iVar17 * 6);
              iVar7 = local_578;
            } while (uVar16 < uVar18);
          }
          uVar16 = local_564 & uVar9;
          uVar4 = uVar9;
          while (uVar16 != 0) {
            local_564 = local_564 ^ uVar4;
            uVar4 = uVar4 >> 1;
            uVar16 = local_564 & uVar4;
          }
          local_564 = local_564 ^ uVar4;
          if (((1 << (bVar2 & 0x1f)) - 1U & local_564) != local_504[iVar7]) {
            do {
              iVar3 = iVar3 - local_57c;
              iVar7 = iVar7 + -1;
              local_578 = iVar7;
            } while (((1 << ((byte)iVar3 & 0x1f)) - 1U & local_564) != local_504[iVar7]);
          }
          local_570 = uVar10;
        } while (uVar10 != 0);
      }
      local_55c = local_55c + 1;
      local_574 = local_574 + 1;
      local_554 = local_554 + 1;
    } while ((int)local_574 <= (int)uVar15);
  }
  return 0;
}


