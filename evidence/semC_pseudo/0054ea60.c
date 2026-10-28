int __thiscall FUN_0054ea60(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *local_1c;
  void *local_18;
  int local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a490b;
  local_c = ExceptionList;
  puVar7 = (undefined4 *)0x1;
  local_1c = (undefined4 *)0x1;
  ExceptionList = &local_c;
  iVar3 = FUN_0054f530(1);
  puVar2 = local_1c;
  while (iVar3 != 0) {
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    iVar3 = FUN_0054f530(puVar7);
    puVar2 = puVar7;
  }
  local_1c = puVar2;
  local_18 = operator_new(0xa4);
  local_4 = 0;
  if (local_18 == (void *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = (undefined4 *)FUN_0054f6e0();
  }
  puVar2 = param_2;
  iVar3 = -1;
  local_4 = 0xffffffff;
  if (puVar7 != (undefined4 *)0x0) {
    piVar1 = puVar7 + 4;
    *puVar7 = *param_2;
    puVar7[1] = param_2[1];
    puVar7[2] = *param_3;
    puVar7[3] = param_3[1];
    *piVar1 = (int)local_1c;
    DVar4 = timeGetTime();
    puVar7[6] = DVar4;
    FUN_00553dc0(param_1 + 6);
    uVar5 = FUN_0054f630(puVar2,param_3);
    FUN_00554660(uVar5);
    *(undefined1 *)(puVar7 + 0x27) = 0;
    FUN_0054fa30(&param_3,piVar1);
    if ((param_3 == (undefined4 *)param_1[1]) || (puVar6 = param_3, *piVar1 < (int)param_3[4])) {
      local_14 = *piVar1;
      local_10 = 0;
      FUN_0049a680(&param_3);
      piVar8 = &local_14;
      piVar9 = piVar8;
      FUN_0049a680(&param_2);
      FUN_0054f7e0(&local_1c,piVar8,piVar9);
      puVar6 = local_1c;
    }
    puVar6[5] = puVar7;
    param_1[4] = param_1[4] + 1;
    FUN_00553830();
    DAT_00724e24 = 3;
    local_18 = (void *)*piVar1;
    FUN_005538e0(&local_18,4);
    FUN_0054f2d0(&DAT_00724e20,puVar2);
    (**(code **)(*param_1 + 4))(*piVar1);
    iVar3 = *piVar1;
  }
  ExceptionList = local_c;
  return iVar3;
}


