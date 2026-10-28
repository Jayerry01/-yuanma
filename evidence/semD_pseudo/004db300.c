undefined4 * FUN_004db300(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a267d;
  local_10 = ExceptionList;
  uStack_7 = 0;
  puVar1 = param_3;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xd) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
      puVar1[1] = param_1[1];
      puVar1[2] = param_1[2];
      *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_1 + 3);
      *(undefined1 *)((int)puVar1 + 0xd) = *(undefined1 *)((int)param_1 + 0xd);
      *(undefined1 *)((int)puVar1 + 0xe) = *(undefined1 *)((int)param_1 + 0xe);
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      local_8 = 2;
      FUN_00402ac0(param_1[4],param_1[5]);
      FUN_005005b0((int)&param_3 + 3);
      local_8 = 4;
      FUN_00402ac0(param_1[7],param_1[8]);
      local_8 = 5;
      FUN_0047a270(param_1 + 10);
    }
    puVar1 = puVar1 + 0xd;
  }
  ExceptionList = local_10;
  return puVar1;
}



void Catch_004db3c7(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + 0x10);
  iVar1 = *(int *)(unaff_EBP + -0x14);
  *(int *)(unaff_EBP + 0x10) = iVar2;
  while (iVar2 != iVar1) {
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_00402bd0();
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_00402bd0();
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_00402bd0();
    iVar2 = iVar2 + 0x34;
    *(int *)(unaff_EBP + 0x10) = iVar2;
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


