int * FUN_0058c230(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a6d89;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  uStack_7 = 0;
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
  *unaff_FS_OFFSET = local_10;
  return param_3;
}



void Catch_0058c308(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  for (iVar2 = *(int *)(unaff_EBP + 0x10); iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    FUN_00402bd0();
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


