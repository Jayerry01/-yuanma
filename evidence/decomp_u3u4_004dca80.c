
/* WARNING: Removing unreachable block (ram,0x004dcb82) */
/* WARNING: Removing unreachable block (ram,0x004dcbdf) */
/* WARNING: Removing unreachable block (ram,0x004dcb6c) */
/* WARNING: Removing unreachable block (ram,0x004dcbdb) */

code * __thiscall FUN_004dca80(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  char *pcVar7;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  void *pvStack_18;
  int iStack_10;
  void *pvStack_c;
  code *pcStack_8;
  uint *puStack_4;
  
  piVar2 = param_2;
  puStack_4 = (uint *)0xffffffff;
  pcStack_8 = thunk_ilt_005A2810;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 4))(param_2,param_2 + 0xba,&param_2);
  puVar6 = puStack_4;
  if (puStack_4 == (uint *)0x0) {
    ExceptionList = pvStack_18;
    return pcStack_8;
  }
  if (pcStack_8 == (code *)0x1869f) {
    ExceptionList = pvStack_18;
    return (code *)0x1869f;
  }
  *puStack_4 = 0;
  for (piVar5 = (int *)param_1[10]; piVar5 != (int *)param_1[0xb]; piVar5 = piVar5 + 1) {
    if ((code *)*piVar5 == pcStack_8) {
      iVar3 = (**(code **)(*piVar2 + 0x170))();
      if (iVar3 == 0) {
        uVar4 = 0xffffffff;
        pcVar7 = &DAT_005c6838;
        goto code_r0x004dcb1d;
      }
      *puVar6 = 1;
      break;
    }
  }
  goto LAB_004dcbed;
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    if (cVar1 == '\0') break;
code_r0x004dcc62:
    if (uVar4 == 0) break;
  }
  iStack_10 = 2;
  puStack_20 = puStack_24;
  puStack_1c = puStack_24;
  FUN_00402ac0(&DAT_005c6838,~uVar4 + 0x5c6837);
  iStack_10 = 3;
  iVar3 = (**(code **)(*piVar2 + 0x130))();
  if ((iVar3 == 0) || (piVar2[0xd8] == 0)) {
    if (puStack_20 + 1 == puStack_1c) {
      piVar5 = (int *)&stack0xffffffcc;
      if ((int)puStack_20 - (int)puStack_24 != 0) {
        piVar5 = (int *)&stack0xffffffc8;
      }
      FUN_0049be40(*piVar5 + ((int)puStack_20 - (int)puStack_24));
    }
    FUN_00402bc0(puStack_20 + 1);
    *puStack_20 = 0x61;
    puStack_20 = puStack_20 + 1;
  }
  (**(code **)(*param_1 + 4))(piVar2,&puStack_24,&pcStack_8);
  iStack_10 = 0xffffffff;
  if (puStack_24 == (undefined1 *)0x0) {
    ExceptionList = pvStack_18;
    return pcStack_8;
  }
  if ((int)puStack_1c - (int)puStack_24 == 0) {
    ExceptionList = pvStack_18;
    return pcStack_8;
  }
  FUN_00402e90(puStack_24,(int)puStack_1c - (int)puStack_24);
  ExceptionList = pvStack_18;
  return pcStack_8;
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    if (cVar1 == '\0') break;
code_r0x004dcb1d:
    if (uVar4 == 0) break;
  }
  iStack_10 = iVar3;
  FUN_00402ac0(&DAT_005c6838,~uVar4 + 0x5c6837);
  iStack_10 = 1;
  iVar3 = (**(code **)(*piVar2 + 0x130))();
  if ((iVar3 == 0) || (piVar2[0xd8] == 0)) {
    FUN_00402bc0(1);
    uRam00000000 = 0x61;
  }
  (**(code **)(*param_1 + 4))(piVar2,&stack0xffffffd0,&pcStack_8);
  iStack_10 = 0xffffffff;
  puVar6 = puStack_4;
LAB_004dcbed:
  if ((piVar5 == (int *)param_1[0xb]) &&
     (puStack_4 = *(uint **)(param_1[0xd] + 8), puStack_4 != (uint *)param_1[0xd])) {
    do {
      if (*(code **)((int)puStack_4 + 0x10) == pcStack_8) {
        puStack_24 = (undefined1 *)
                     (**(code **)(*piVar2 + 0x174))(*(undefined4 *)((int)puStack_4 + 0x14));
        if (puStack_24 != (undefined1 *)0x0) {
          *puVar6 = 2;
          *puVar6 = *(int *)((int)puStack_4 + 0x14) << 8 | 2;
          ExceptionList = pvStack_18;
          return pcStack_8;
        }
        uVar4 = 0xffffffff;
        pcVar7 = &DAT_005c6838;
        goto code_r0x004dcc62;
      }
      FUN_0043c6c0();
    } while (puStack_4 != (uint *)param_1[0xd]);
  }
  ExceptionList = pvStack_18;
  return pcStack_8;
}

