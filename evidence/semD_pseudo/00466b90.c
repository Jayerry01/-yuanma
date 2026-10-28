void __fastcall FUN_00466b90(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059c9d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005a8be0;
  local_4 = 0;
  if (param_1[0x11] == 0) {
    FUN_00429cb0(param_1[7]);
    FUN_00429cb0(param_1[8]);
  }
  piVar1 = (int *)param_1[9];
  uVar2 = param_1[0xb] - (int)piVar1;
  if ((piVar1 != (int *)0x0) && (uVar2 != 0)) {
    if (uVar2 < 0x81) {
      iVar3 = FUN_00460900(uVar2);
      FUN_00460910();
      *piVar1 = (&DAT_005d59a8)[iVar3];
      (&DAT_005d59a8)[iVar3] = piVar1;
      FUN_00403060();
    }
    else {
      FUN_0046ec20(piVar1,uVar2);
    }
  }
  *param_1 = &PTR_LAB_005a8810;
  ExceptionList = local_c;
  return;
}


