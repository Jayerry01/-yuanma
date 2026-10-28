undefined4 __thiscall FUN_00469490(uint param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_4;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x68) == 0) {
    if (*(int *)(param_1 + 0x38) != 0) {
      local_4 = 0;
      FUN_0046ef50(**(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 8),&local_4);
      if (*(uint *)(param_1 + 0x34) < local_4 - *(int *)(param_1 + 0x1c)) {
        iVar2 = FUN_00469a00(param_2);
        if (iVar2 != 0) {
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        }
      }
      return 1;
    }
  }
  else {
    param_2 = (undefined4 *)0x0;
    local_4 = param_1;
    FUN_0046ef50(**(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 8),&param_2);
    if (*(uint *)(param_1 + 0x34) < (uint)((int)param_2 - *(int *)(param_1 + 0x1c))) {
      iVar1 = *(int *)(param_1 + 0x6c);
      if (iVar1 != 0) {
        *(int *)(param_1 + 0x6c) = iVar1 + -1;
      }
      local_4 = (uint)(iVar1 != 0);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      piVar3 = (int *)**(int **)(param_1 + 8);
      param_2 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
      puVar4 = param_2;
      if (piVar3 != *(int **)(param_1 + 8)) {
        do {
          iVar1 = *(int *)(param_1 + 0x6c);
          if (iVar2 - *(int *)(param_1 + 0x1c) == iVar1) {
            if (iVar1 == 0) {
              if (local_4 != 0) {
                *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
                FUN_00466190(0);
                *(undefined4 *)(param_1 + 0x44) = 0;
              }
              iVar1 = *(int *)(param_1 + 0x6c);
              if (iVar1 == 0) goto LAB_004695d7;
            }
            if (local_4 != 0) {
              if (iVar1 < *(int *)(param_1 + 0x34)) {
                FUN_00466190(1);
                *(undefined4 *)(param_1 + 0x44) = param_2[2];
                FUN_00466190(0);
              }
              if (*(int *)(param_1 + 0x6c) == *(int *)(param_1 + 0x34)) {
                FUN_00466190(1);
                *(undefined4 *)(param_1 + 0x44) = param_2[2];
              }
            }
          }
LAB_004695d7:
          if (((iVar2 - *(int *)(param_1 + 0x1c)) + 1 == *(int *)(param_1 + 0x6c)) &&
             (*(int *)(param_1 + 0x6c) == *(int *)(param_1 + 0x34))) {
            FUN_00466190(1);
            *(undefined4 *)(param_1 + 0x44) = puVar4[2];
          }
          puVar5 = puVar4;
          if (((*(int *)(param_1 + 0x1c) <= iVar2) &&
              (iVar2 < *(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x1c))) &&
             (puVar4 != *(undefined4 **)(param_1 + 0xc))) {
            FUN_00465730(piVar3[2]);
            puVar5 = (undefined4 *)*puVar4;
            param_2 = puVar4;
          }
          piVar3 = (int *)*piVar3;
          iVar2 = iVar2 + 1;
          puVar4 = puVar5;
        } while (piVar3 != (int *)*(int *)(param_1 + 8));
      }
    }
  }
  return 0;
}


