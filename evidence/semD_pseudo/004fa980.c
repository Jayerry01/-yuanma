undefined4 * FUN_004fa980(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a3b61;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      iVar1 = param_1[1];
      iVar2 = *param_1;
      local_8 = 2;
      FUN_004608a0((iVar1 - iVar2) + 1);
      uVar3 = FUN_004da870(iVar2,iVar1,*param_3);
      param_3[1] = uVar3;
      FUN_00402a70();
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      local_8 = 4;
      FUN_00402ac0(param_1[3],param_1[4]);
      param_3[6] = param_1[6];
    }
    param_3 = param_3 + 7;
  }
  ExceptionList = local_10;
  return param_3;
}



void Catch_004faa34(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(unaff_EBP + 0x10);
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  *(undefined4 **)(unaff_EBP + 0x10) = puVar4;
  while (puVar4 != puVar1) {
    iVar2 = puVar4[4];
    uVar3 = puVar4[3];
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004d4a40(uVar3,iVar2 + 1);
    FUN_00402bd0();
    iVar2 = puVar4[1];
    uVar3 = *puVar4;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_004d4a40(uVar3,iVar2 + 1);
    FUN_00402bd0();
    puVar4 = puVar4 + 7;
    *(undefined4 **)(unaff_EBP + 0x10) = puVar4;
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


