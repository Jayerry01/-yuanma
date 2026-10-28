undefined4 * FUN_004ff000(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a3ec7;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      iVar1 = param_1[5];
      iVar2 = param_1[4];
      local_8 = 2;
      FUN_004608a0((iVar1 - iVar2) + 1);
      uVar3 = FUN_004da870(iVar2,iVar1,param_3[4]);
      param_3[5] = uVar3;
      FUN_00402a70();
      param_3[7] = 0;
      param_3[8] = 0;
      param_3[9] = 0;
      local_8 = 4;
      FUN_00402ac0(param_1[7],param_1[8]);
      param_3[10] = param_1[10];
      param_3[0xb] = param_1[0xb];
    }
    param_3 = param_3 + 0xc;
  }
  ExceptionList = local_10;
  return param_3;
}



void Catch_004ff0e3(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int iVar4;
  
  iVar4 = *(int *)(unaff_EBP + 0x10);
  iVar1 = *(int *)(unaff_EBP + -0x14);
  *(int *)(unaff_EBP + 0x10) = iVar4;
  while (iVar4 != iVar1) {
    iVar2 = *(int *)(iVar4 + 0x20);
    uVar3 = *(undefined4 *)(iVar4 + 0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004d4a40(uVar3,iVar2 + 1);
    FUN_00402bd0();
    iVar2 = *(int *)(iVar4 + 0x14);
    uVar3 = *(undefined4 *)(iVar4 + 0x10);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_004d4a40(uVar3,iVar2 + 1);
    FUN_00402bd0();
    iVar4 = iVar4 + 0x30;
    *(int *)(unaff_EBP + 0x10) = iVar4;
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


