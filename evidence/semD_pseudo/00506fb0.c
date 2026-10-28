int * FUN_00506fb0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a4249;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  while( true ) {
    if (param_1 == param_2) break;
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      iVar2 = param_1[1];
      iVar3 = *param_1;
      iVar5 = iVar2 - iVar3;
      local_8 = 2;
      iVar1 = iVar5 + 1;
      if (iVar1 == -1) {
        FUN_004030f0();
      }
      else if (iVar1 == 0) {
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
      }
      else {
        iVar4 = FUN_00402bf0(iVar1);
        *param_3 = iVar4;
        param_3[1] = iVar4;
        param_3[2] = iVar4 + iVar1;
      }
      iVar1 = *param_3;
      FUN_005092c0(iVar1,iVar3,iVar5);
      param_3[1] = (iVar1 - iVar3) + iVar2;
      FUN_00402a70();
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
    }
    param_1 = param_1 + 5;
    param_3 = param_3 + 5;
  }
  ExceptionList = local_10;
  return param_3;
}



void Catch_00507088(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  for (puVar2 = *(undefined4 **)(unaff_EBP + 0x10); puVar2 != puVar1; puVar2 = puVar2 + 5) {
    FUN_004d4a40(*puVar2,puVar2[1] + 1);
    FUN_00402bd0();
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


