undefined4 * __fastcall FUN_004a2e10(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_15;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059f9df;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004e8a20();
  param_1[0xc] = &PTR_LAB_005a9a98;
  puVar4 = param_1 + 0xd;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  local_4._0_1_ = 4;
  local_4._1_3_ = 0;
  param_1[0x6a] = 0;
  puVar1 = (undefined1 *)FUN_00402bf0(0x18);
  param_1[0x6a] = puVar1;
  param_1[0x6b] = 0;
  *(undefined1 *)(param_1 + 0x6c) = local_15;
  *puVar1 = 0;
  *(undefined4 *)(param_1[0x6a] + 4) = 0;
  *(undefined4 *)(param_1[0x6a] + 8) = param_1[0x6a];
  *(undefined4 *)(param_1[0x6a] + 0xc) = param_1[0x6a];
  local_4._0_1_ = 5;
  param_1[0x6d] = 0;
  uVar2 = FUN_00402bf0(0x18);
  param_1[0x6d] = uVar2;
  local_4._0_1_ = 6;
  param_1[0x6e] = 0;
  *(undefined1 *)(param_1 + 0x6f) = local_15;
  FUN_004b4a30();
  param_1[0x103] = 0;
  param_1[0x104] = 0;
  param_1[0x105] = 0;
  local_4 = CONCAT31(local_4._1_3_,8);
  *param_1 = &PTR_FUN_005a9980;
  param_1[0xc] = &PTR_LAB_005a98f8;
  FUN_004a4b30();
  ExceptionList = local_c;
  return param_1;
}


