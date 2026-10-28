int FUN_004c7f80(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a16e1;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  uStack_7 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_004c7a30(param_3);
    }
    param_1 = param_1 + 0x124;
  }
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



void Catch_004c7fd8(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  for (puVar2 = *(undefined4 **)(unaff_EBP + 8); puVar2 != puVar1; puVar2 = puVar2 + 0x49) {
    (**(code **)*puVar2)(0);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


