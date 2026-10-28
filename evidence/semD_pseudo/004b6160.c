undefined4 * FUN_004b6160(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a09a9;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 6) {
    if (param_3 != (undefined4 *)0x0) {
      piVar1 = param_3 + 3;
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      *piVar1 = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      iVar2 = param_1[4];
      iVar3 = param_1[3];
      iVar4 = iVar2 - iVar3;
      local_8 = 2;
      iVar5 = iVar4 + 1;
      if (iVar5 == -1) {
        FUN_004030f0();
      }
      else if (iVar5 == 0) {
        *piVar1 = 0;
        param_3[4] = 0;
        param_3[5] = iVar4 + 1;
      }
      else {
        iVar5 = FUN_00402bf0(iVar5);
        *piVar1 = iVar5;
        param_3[4] = iVar5;
        param_3[5] = iVar5 + 1 + iVar4;
      }
      iVar5 = *piVar1;
      FUN_005092c0(iVar5,iVar3,iVar4);
      param_3[4] = (iVar5 - iVar3) + iVar2;
      FUN_00402a70();
    }
    param_3 = param_3 + 6;
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}



void Catch_004b6255(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(unaff_EBP + -0x18);
  if (*(undefined4 **)(unaff_EBP + 0x10) != puVar2) {
    puVar3 = *(undefined4 **)(unaff_EBP + 0x10) + 3;
    do {
      FUN_004d4a40(*puVar3,puVar3[1] + 1);
      FUN_00402bd0();
      puVar1 = puVar3 + 3;
      puVar3 = puVar3 + 6;
    } while (puVar1 != puVar2);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


