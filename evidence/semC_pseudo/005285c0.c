void FUN_005285c0(int param_1,int *param_2,int *param_3,uint *param_4,int *param_5,
                 undefined1 *param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 local_4c;
  short sStack_3e;
  int local_3c [7];
  int local_20;
  
  *param_2 = 0x1101;
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0x5622;
  *param_6 = 0;
  if (param_1 != 0) {
    piVar6 = (int *)(param_1 + 0xc);
    for (iVar5 = (*(int *)(param_1 + 4) + 1U & 0xfffffffe) - 4; iVar5 != 0;
        iVar5 = iVar5 + (-8 - (uVar1 + 1 & 0xfffffffe))) {
      iVar4 = *piVar6;
      uVar1 = piVar6[1];
      piVar7 = piVar6 + 2;
      if (iVar4 == DAT_005cf58c) {
        iVar4 = *piVar7;
        iVar2 = piVar6[3];
        local_4c = iVar4;
        if ((short)iVar4 == 1) {
          local_4c._2_2_ = (short)((uint)iVar4 >> 0x10);
          sStack_3e = (short)((uint)piVar6[5] >> 0x10);
          if (local_4c._2_2_ == 1) {
            *param_2 = (sStack_3e != 8) + 0x1100;
            *param_5 = iVar2;
          }
          else {
            *param_2 = (sStack_3e != 8) + 0x1102;
            *param_5 = iVar2;
          }
        }
LAB_00528752:
        piVar7 = (int *)((int)piVar7 + uVar1);
      }
      else {
        if (iVar4 != DAT_005cf584) {
          if (iVar4 == DAT_005cf57c) {
            piVar6 = piVar7;
            piVar8 = local_3c;
            for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
              *piVar8 = *piVar6;
              piVar6 = piVar6 + 1;
              piVar8 = piVar8 + 1;
            }
            *param_6 = local_20 != 0;
          }
          goto LAB_00528752;
        }
        if ((short)local_4c == 1) {
          *param_4 = uVar1;
          piVar6 = _malloc(uVar1 + 0x1f);
          *param_3 = (int)piVar6;
          if (piVar6 != (int *)0x0) {
            piVar8 = piVar7;
            for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *piVar6 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar6 = piVar6 + 1;
            }
            for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(char *)piVar6 = (char)*piVar8;
              piVar8 = (int *)((int)piVar8 + 1);
              piVar6 = (int *)((int)piVar6 + 1);
            }
          }
          puVar9 = (undefined4 *)(*param_3 + uVar1);
          for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
          *(undefined2 *)puVar9 = 0;
          *(undefined1 *)((int)puVar9 + 2) = 0;
          goto LAB_00528752;
        }
      }
      piVar6 = (int *)((int)piVar7 + (uVar1 & 1));
    }
  }
  return;
}


