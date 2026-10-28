FUN_0050eb1e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005ac5d0;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0050ef73();
  FUN_0050ef73();
  iVar1 = FUN_0050ef73();
  *(undefined4 *)(iVar1 + 0x6c) = param_1;
  iVar1 = FUN_0050ef73();
  *(undefined4 *)(iVar1 + 0x70) = param_3;
  local_8 = 1;
  uVar2 = FUN_00508c0d(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_0050ebeb();
  ExceptionList = local_14;
  return uVar2;
}


