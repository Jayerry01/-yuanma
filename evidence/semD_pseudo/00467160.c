undefined4 * __fastcall FUN_00467160(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 local_11;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059ca0e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005a8810;
  param_1[1] = 0;
  local_4 = 0;
  uVar1 = FUN_00402bf0(0xc);
  param_1[2] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(param_1[2] + 4) = param_1[2];
  local_4._0_1_ = 1;
  uVar1 = FUN_00402bf0(0xc);
  param_1[3] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(param_1[3] + 4) = param_1[3];
  local_4 = CONCAT31(local_4._1_3_,2);
  param_1[4] = 0;
  puVar2 = (undefined1 *)FUN_00402bf0(0x18);
  param_1[4] = puVar2;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 6) = local_11;
  *puVar2 = 0;
  *(undefined4 *)(param_1[4] + 4) = 0;
  *(undefined4 *)(param_1[4] + 8) = param_1[4];
  *(undefined4 *)(param_1[4] + 0xc) = param_1[4];
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0x3f800000;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_005a8c38;
  ExceptionList = local_c;
  return param_1;
}


