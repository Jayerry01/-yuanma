void __fastcall FUN_004c2a30(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((0 < *(int *)(param_1 + 0x4d4)) && (0 < *(int *)(param_1 + 0x4d8))) {
    piVar6 = (int *)(param_1 + 0x28);
    local_14 = 10;
    local_10 = piVar6;
    do {
      local_18 = 10;
      piVar7 = piVar6;
      do {
        iVar8 = piVar7[-1];
        iVar2 = *piVar7;
        FUN_004b6360(iVar2,iVar2,iVar8,local_10,0);
        piVar6 = piVar7 + 3;
        local_18 = local_18 + -1;
        *piVar7 = *piVar7 + (iVar2 - iVar8 >> 1) * -2;
        piVar7 = piVar6;
      } while (local_18 != 0);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    iVar8 = 0;
    if (0 < (*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24) {
      local_14 = 0;
      do {
        iVar2 = FUN_004c2bf0(iVar8);
        local_c = *(undefined4 *)(iVar2 + 4);
        local_8 = *(undefined4 *)(iVar2 + 8);
        local_4 = *(undefined4 *)(iVar2 + 0xc);
        iVar2 = __ftol();
        iVar2 = iVar2 / *(int *)(param_1 + 0x4d4);
        iVar3 = __ftol();
        iVar3 = iVar3 / *(int *)(param_1 + 0x4d8);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else if (*(int *)(param_1 + 0x4f4) <= iVar2) {
          iVar2 = *(int *)(param_1 + 0x4f4) + -1;
        }
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        else if (*(int *)(param_1 + 0x4f8) <= iVar3) {
          iVar3 = *(int *)(param_1 + 0x4f8) + -1;
        }
        iVar2 = iVar3 + 3 + iVar2 * 10;
        puVar1 = *(undefined2 **)(param_1 + 4 + iVar2 * 0xc);
        local_14 = iVar8;
        if (puVar1 == *(undefined2 **)(param_1 + 8 + iVar2 * 0xc)) {
          FUN_004c4870(puVar1,&local_14);
        }
        else {
          if (puVar1 != (undefined2 *)0x0) {
            *puVar1 = (short)iVar8;
          }
          piVar6 = (int *)(param_1 + iVar2 * 0xc + 4);
          *piVar6 = *piVar6 + 2;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24);
    }
    iVar8 = *(int *)(param_1 + 0x4f4);
    if (0 < iVar8) {
      do {
        piVar6 = local_10;
        iVar2 = *(int *)(param_1 + 0x4f8);
        if (0 < *(int *)(param_1 + 0x4f8)) {
          do {
            uVar5 = 0;
            uVar4 = *piVar6 - piVar6[-1] >> 1;
            if (uVar4 != 0) {
              do {
                uVar5 = uVar5 + 1;
              } while (uVar5 < uVar4);
            }
            iVar2 = iVar2 + -1;
            piVar6 = piVar6 + 3;
          } while (iVar2 != 0);
        }
        local_10 = local_10 + 0x1e;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  return;
}


