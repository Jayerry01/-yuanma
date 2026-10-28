undefined4 * FUN_005775a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a6051;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  uStack_7 = 0;
  while( true ) {
    iVar3 = 0;
    if (param_1 == param_2) break;
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      iVar2 = param_1[3];
      iVar1 = param_1[2];
      param_3[2] = 0;
      param_3[3] = 0;
      iVar2 = iVar2 - iVar1 >> 2;
      param_3[4] = 0;
      if (iVar2 != 0) {
        iVar3 = FUN_00402bf0(iVar2 * 4);
      }
      param_3[2] = iVar3;
      param_3[3] = iVar3;
      param_3[4] = iVar3 + iVar2 * 4;
      iVar2 = ((int)(param_1[3] - param_1[2]) >> 2) * 4;
      FUN_005092c0(iVar3,param_1[2],iVar2);
      param_3[3] = iVar2 + iVar3;
    }
    param_1 = param_1 + 5;
    param_3 = param_3 + 5;
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}



void Catch_0057765e(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(unaff_EBP + -0x14);
  if (*(undefined4 **)(unaff_EBP + 0x10) != puVar2) {
    puVar3 = *(undefined4 **)(unaff_EBP + 0x10) + 2;
    do {
      FUN_004d4a40(*puVar3,puVar3[1]);
      FUN_004fe380();
      puVar1 = puVar3 + 3;
      puVar3 = puVar3 + 5;
    } while (puVar1 != puVar2);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


