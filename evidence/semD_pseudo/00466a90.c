undefined4 * __fastcall FUN_00466a90(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059c9b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005a8810;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x3f800000;
  local_4 = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar1 = FUN_00460900(8);
  FUN_00460910();
  piVar3 = (int *)(&DAT_005d59a8)[iVar1];
  local_4._0_1_ = 1;
  if (piVar3 == (int *)0x0) {
    uVar2 = FUN_004608f0(8);
    piVar3 = (int *)FUN_00403290(uVar2);
  }
  else {
    (&DAT_005d59a8)[iVar1] = *piVar3;
  }
  local_4._0_1_ = 0;
  FUN_00403060();
  param_1[9] = piVar3;
  param_1[10] = piVar3;
  param_1[0xb] = (int)piVar3 + 8;
  local_4 = CONCAT31(local_4._1_3_,5);
  FUN_00402a70();
  param_1[0xc] = 0;
  *param_1 = &PTR_FUN_005a8be0;
  param_1[0xd] = 0;
  ExceptionList = local_c;
  return param_1;
}


