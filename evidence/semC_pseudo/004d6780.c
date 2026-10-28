void __fastcall FUN_004d6780(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_38;
  int local_34;
  undefined1 local_30 [8];
  int local_28 [4];
  int local_18;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a1f30;
  local_c = ExceptionList;
  iVar4 = *(int *)(param_1 + 4);
  ExceptionList = &local_c;
  local_34 = param_1;
  if (iVar4 != *(int *)(param_1 + 8)) {
    do {
      if (*(int *)(iVar4 + 0x2c) == 1) {
        piVar2 = *(int **)(iVar4 + 0x30);
        piVar5 = *(int **)(iVar4 + 0x34);
        if (piVar2 != piVar5) {
          do {
            if (*piVar2 == 0xb) break;
            piVar2 = piVar2 + 3;
          } while (piVar2 != piVar5);
          if ((piVar2 != piVar5) && (piVar2 != (int *)0x0)) {
            piVar5 = (int *)(local_34 + 0x10);
            FUN_0049d3c0(&local_38,piVar2 + 1);
            if (local_38 == *piVar5) {
              local_28[0] = 0;
              local_28[1] = 0;
              local_28[2] = 0;
              local_4 = 0;
              FUN_0049c640(0,iVar4 + 0x28);
              local_28[3] = piVar2[1];
              FUN_004b4940(local_28);
              local_4._0_1_ = 1;
              FUN_004b4a50(local_30,local_28 + 3);
              local_4 = (uint)local_4._1_3_ << 8;
              iVar3 = local_10 - local_18 >> 2;
              if (iVar3 != 0) {
                FUN_00402e90(local_18,iVar3 << 2);
              }
              local_4 = 0xffffffff;
              iVar3 = local_28[2] - local_28[0] >> 2;
              if (iVar3 != 0) {
                FUN_00402e90(local_28[0],iVar3 * 4);
              }
            }
            else {
              puVar1 = *(undefined4 **)(local_38 + 0x18);
              if (puVar1 == *(undefined4 **)(local_38 + 0x1c)) {
                FUN_0049c640(puVar1,iVar4 + 0x28);
              }
              else {
                if (puVar1 != (undefined4 *)0x0) {
                  *puVar1 = *(undefined4 *)(iVar4 + 0x28);
                }
                *(int *)(local_38 + 0x18) = *(int *)(local_38 + 0x18) + 4;
              }
            }
          }
        }
      }
      iVar4 = iVar4 + 0x48;
    } while (iVar4 != *(int *)(local_34 + 8));
  }
  ExceptionList = local_c;
  return;
}


