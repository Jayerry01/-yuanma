int * FUN_0047a660(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_13c [268];
  undefined1 local_30 [12];
  int *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0059d341;
  local_10 = ExceptionList;
  local_14 = &stack0xfffffeb8;
  uStack_7 = 0;
  piVar4 = param_3;
  ExceptionList = &local_10;
  do {
    iVar2 = 0;
    if (param_1 == param_2) {
      ExceptionList = local_10;
      return piVar4;
    }
    if (piVar4 != (int *)0x0) {
      *piVar4 = 0;
      piVar4[1] = 0;
      piVar4[2] = 0;
      local_20 = param_1[1];
      local_18 = *param_1;
      iVar3 = local_20 - local_18;
      local_8 = 2;
      iVar1 = iVar3 + 1;
      local_24 = piVar4;
      local_1c = piVar4;
      if (iVar1 == -1) {
        FUN_00402570(s_basic_string_005c42c8,(int)&param_1 + 3);
        _local_8 = CONCAT31(uStack_7,3);
        FUN_0047a7a0(local_30);
                    // WARNING: Subroutine does not return
        __CxxThrowException_8(local_13c,&DAT_005b3c50);
      }
      if (iVar1 != 0) {
        iVar2 = FUN_00402bf0(iVar1);
      }
      *piVar4 = iVar2;
      piVar4[1] = iVar2;
      piVar4[2] = iVar2 + 1 + iVar3;
      FUN_005092c0(iVar2,local_18,iVar3);
      piVar4[1] = (iVar2 - local_18) + local_20;
      FUN_00402a70();
    }
    param_1 = param_1 + 3;
    piVar4 = piVar4 + 3;
  } while( true );
}



void Catch_0047a74e(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  for (puVar2 = *(undefined4 **)(unaff_EBP + 0x10); puVar2 != puVar1; puVar2 = puVar2 + 3) {
    FUN_004d4a40(*puVar2,puVar2[1] + 1);
    FUN_00402bd0();
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


