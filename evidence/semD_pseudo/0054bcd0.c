void __fastcall FUN_0054bcd0(int param_1)

{
  undefined2 uVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  DWORD local_18;
  undefined1 local_14 [4];
  undefined2 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a45f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DVar2 = timeGetTime();
  FUN_00553830();
  DAT_0072489c = 7;
  local_18 = DVar2;
  FUN_005538e0(&local_18,4);
  FUN_00553920(*(undefined4 *)(param_1 + 0xbc));
  uVar1 = *(undefined2 *)(param_1 + 8);
  FUN_004736b0(&DAT_005c7c50);
  puVar5 = local_14;
  local_4 = 0;
  local_10 = uVar1;
  uVar3 = FUN_00553870(puVar5);
  uVar4 = FUN_00553880(uVar3);
  FUN_005547a0(uVar4,uVar3,puVar5);
  *(DWORD *)(param_1 + 0xd8) = DVar2;
  ExceptionList = local_c;
  return;
}


