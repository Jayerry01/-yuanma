void FUN_00475980(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_005e0490;
  puVar3 = param_1;
  puVar4 = &DAT_005e0ce8;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = 1;
  _DAT_005e0404 = 0;
  _DAT_005e0408 = 1;
  if (iVar1 != 0) {
    FUN_00479f60(0);
  }
  FUN_00479f80(*param_1);
  if (param_1[1] == 1) {
    FUN_00475590(0,1);
    FUN_004756e0(&DAT_005c7dd0,0);
  }
  if (*(char *)(param_1 + 4) != '\0') {
    FUN_00475590(2,0);
  }
  if (*(char *)((int)param_1 + 0x11) != '\0') {
    FUN_00475590(1,1);
    FUN_00475820(param_1[5],param_1[6]);
  }
  if (1 < DAT_005e03f4) {
    do {
      if ((&DAT_005e046c)[iVar2] != 0) {
        FUN_00479f60(iVar2);
        thunk_FUN_00475590(5,0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005e03f4);
  }
  if (DAT_005e0490 != 0) {
    FUN_00479f60();
    return;
  }
  return;
}


