void __thiscall FUN_0054c510(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_28 [7];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a4698;
  local_c = ExceptionList;
  puVar3 = local_28;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_4 = 0;
  ExceptionList = &local_c;
  if ((uint)(param_1[1] - (param_1[9] - *param_1 >> 2)) < 2) {
    ExceptionList = &local_c;
    FUN_0054cc30(1,0);
  }
  pvVar1 = _malloc(0x1f8);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_00403440(0x1f8);
  }
  *(void **)(param_1[9] + 4) = pvVar1;
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    puVar3 = local_28;
    puVar4 = (undefined4 *)param_1[6];
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  iVar2 = param_1[9];
  local_4 = 0xffffffff;
  param_1[9] = iVar2 + 4;
  iVar2 = *(int *)(iVar2 + 4);
  param_1[7] = iVar2;
  param_1[8] = iVar2 + 0x1f8;
  param_1[6] = param_1[7];
  FUN_004e8500();
  ExceptionList = local_c;
  return;
}


