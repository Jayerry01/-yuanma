int __thiscall FUN_00555e00(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_24 [6];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4ea8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(byte *)(param_2 + 5) & 0x40) != 0) {
    ExceptionList = &local_c;
    FUN_00553ae0();
  }
  if ((*(byte *)(param_2 + 5) & 8) != 0) {
    FUN_005539c0();
  }
  if ((*(byte *)(param_2 + 5) & 0x10) != 0) {
    FUN_005539e0(*(undefined4 *)(param_1 + 0x5bc));
  }
  if ((*(int *)(param_1 + 0x5a4) - *(int *)(param_1 + 0x59c)) / 0x18 +
      (*(int *)(param_1 + 0x5ac) - *(int *)(param_1 + 0x5b0)) / 0x18 +
      (*(int *)(param_1 + 0x5b8) - *(int *)(param_1 + 0x5a8) >> 2) * 0x15 == 0x15) {
    uVar1 = FUN_00553870();
    uVar2 = FUN_00553880(uVar1);
    iVar3 = FUN_005561f0(uVar2,uVar1);
    if (iVar3 != 0) {
      ExceptionList = local_c;
      return iVar3;
    }
  }
  FUN_00554c90();
  local_4 = 0;
  FUN_00554cd0(param_2);
  puVar5 = *(undefined4 **)(param_1 + 0x5ac);
  if (puVar5 == (undefined4 *)(*(int *)(param_1 + 0x5b4) + -0x18)) {
    FUN_0054c510(local_24);
  }
  else {
    if (puVar5 != (undefined4 *)0x0) {
      puVar4 = local_24;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    *(int *)(param_1 + 0x5ac) = *(int *)(param_1 + 0x5ac) + 0x18;
  }
  local_4 = 0xffffffff;
  FUN_004e8500();
  ExceptionList = local_c;
  return 0;
}


