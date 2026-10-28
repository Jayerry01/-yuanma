undefined4 * __thiscall FUN_00589330(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a6bc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005811c0(param_2,param_3);
  *param_1 = &PTR_FUN_005b1368;
  DAT_0072bcec = DAT_0072bcec + 1;
  local_4 = 0;
  param_1[1] = 4;
  param_1[3] = 0x270;
  pcVar2 = (char *)FUN_0058a6d0(4);
  pcVar3 = (char *)(param_1 + 5);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  param_1[0x9b] = 0x41200000;
  param_1[0x9a] = 0x41200000;
  FUN_00581aa0(s_Board_005d2f74);
  ExceptionList = local_c;
  return param_1;
}



void __fastcall thunk_FUN_005813c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_005a678c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_005b0e18;
  uStack_4 = 1;
  FUN_005820a0();
  iVar2 = FUN_00580c30();
  if (iVar2 != 0) {
    param_1[0x7b] = 0;
  }
  piVar4 = *(int **)param_1[0x99];
  if (piVar4 != (undefined4 *)param_1[0x99]) {
    do {
      piVar3 = piVar4;
      piVar4 = (int *)*piVar3;
      FUN_00402330();
      *piVar3 = (int)DAT_005d59ac;
      DAT_005d59e8 = 0;
      DAT_005d59ac = piVar3;
    } while (piVar4 != (int *)param_1[0x99]);
  }
  *(undefined4 *)param_1[0x99] = param_1[0x99];
  *(undefined4 *)(param_1[0x99] + 4) = param_1[0x99];
  piVar4 = (int *)param_1[0x99];
  FUN_00402330();
  *piVar4 = (int)DAT_005d59ac;
  piVar3 = *(int **)param_1[0x98];
  DAT_005d59ac = piVar4;
  if (piVar3 != (int *)param_1[0x98]) {
    do {
      piVar4 = piVar3;
      DAT_005d59e8 = 0;
      piVar3 = (int *)*piVar4;
      FUN_00402330();
      *piVar4 = (int)DAT_005d59ac;
      DAT_005d59ac = piVar4;
    } while (piVar3 != (int *)param_1[0x98]);
  }
  DAT_005d59e8 = 0;
  *(undefined4 *)param_1[0x98] = param_1[0x98];
  *(undefined4 *)(param_1[0x98] + 4) = param_1[0x98];
  puVar1 = (undefined4 *)param_1[0x98];
  FUN_00402330();
  *puVar1 = DAT_005d59ac;
  DAT_005d59ac = puVar1;
  DAT_005d59e8 = 0;
  ExceptionList = pvStack_c;
  return;
}


