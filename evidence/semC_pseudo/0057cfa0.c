undefined4 * FUN_0057cfa0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_005a65e9;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x2b) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      param_3[6] = param_1[6];
      param_3[7] = param_1[7];
      param_3[8] = param_1[8];
      param_3[9] = param_1[9];
      FUN_004c5d40(param_1 + 10);
      local_8 = 2;
      FUN_00576df0(param_1 + 0xd);
      local_8 = 3;
      param_3[0x10] = param_1[0x10];
      param_3[0x11] = param_1[0x11];
      param_3[0x12] = param_1[0x12];
      param_3[0x13] = param_1[0x13];
      param_3[0x14] = param_1[0x14];
      param_3[0x15] = param_1[0x15];
      param_3[0x16] = param_1[0x16];
      param_3[0x17] = param_1[0x17];
      param_3[0x18] = param_1[0x18];
      param_3[0x19] = param_1[0x19];
      param_3[0x1a] = param_1[0x1a];
      param_3[0x1b] = param_1[0x1b];
      FUN_004c5d40(param_1 + 0x1c);
      local_8 = 4;
      FUN_0057c770(param_1 + 0x1f);
      local_8 = 5;
      FUN_0057c770(param_1 + 0x22);
      local_8 = 6;
      FUN_0057c880(param_1 + 0x25);
      local_8 = 7;
      FUN_0057c990(param_1 + 0x28);
    }
    param_3 = param_3 + 0x2b;
  }
  ExceptionList = local_10;
  return param_3;
}



void Catch_0057d101(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  for (iVar2 = *(int *)(unaff_EBP + 0x10); iVar2 != iVar1; iVar2 = iVar2 + 0xac) {
    FUN_00574ef0();
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


