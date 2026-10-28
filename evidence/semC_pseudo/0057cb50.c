void FUN_0057cb50(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 local_16;
  undefined1 local_15;
  undefined4 *local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar5 = param_2;
  puVar4 = param_1;
  puStack_8 = &LAB_005a6579;
  local_c = ExceptionList;
  local_10 = param_1;
  local_4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = param_1 + 10;
    ExceptionList = &local_c;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    param_1[7] = param_2[7];
    param_1[8] = param_2[8];
    puVar2 = param_2 + 9;
    param_2 = (undefined4 *)CONCAT31(param_2._1_3_,param_1._0_1_);
    param_1[9] = *puVar2;
    FUN_004da940((int)(puVar5[0xb] - puVar5[10]) >> 2,&param_2);
    iVar3 = *piVar1;
    local_14 = (undefined4 *)(((int)(puVar5[0xb] - puVar5[10]) >> 2) << 2);
    FUN_005092c0(iVar3,puVar5[10],local_14);
    puVar4[0xb] = (int)local_14 + iVar3;
    local_16 = param_1._0_1_;
    local_4._0_1_ = 1;
    local_14 = puVar4 + 0xd;
    FUN_00560170((int)(puVar5[0xe] - puVar5[0xd]) / 0xc,&local_16);
    local_4._0_1_ = 2;
    uVar6 = FUN_0055fe10(puVar5[0xd],puVar5[0xe],puVar4[0xd],param_1);
    puVar4[0xe] = uVar6;
    puVar4[0x10] = puVar5[0x10];
    puVar4[0x11] = puVar5[0x11];
    puVar4[0x12] = puVar5[0x12];
    puVar4[0x13] = puVar5[0x13];
    puVar4[0x14] = puVar5[0x14];
    puVar4[0x15] = puVar5[0x15];
    puVar4[0x16] = puVar5[0x16];
    puVar4[0x17] = puVar5[0x17];
    puVar4[0x18] = puVar5[0x18];
    puVar4[0x19] = puVar5[0x19];
    puVar4[0x1a] = puVar5[0x1a];
    local_15 = param_1._0_1_;
    puVar4[0x1b] = puVar5[0x1b];
    local_4._0_1_ = 3;
    FUN_004da940((int)(puVar5[0x1d] - puVar5[0x1c]) >> 2,&local_15);
    uVar6 = FUN_0049e5e0(puVar5[0x1c],puVar5[0x1d],puVar4[0x1c]);
    puVar4[0x1d] = uVar6;
    local_4._0_1_ = 4;
    local_14 = puVar4 + 0x1f;
    FUN_00560170((int)(puVar5[0x20] - puVar5[0x1f]) / 0xc,&param_1);
    local_4._0_1_ = 5;
    uVar6 = FUN_004f4800(puVar5[0x1f],puVar5[0x20],puVar4[0x1f],param_1);
    puVar4[0x20] = uVar6;
    local_4._0_1_ = 6;
    FUN_0057c770(puVar5 + 0x22);
    local_4._0_1_ = 7;
    FUN_0057c880(puVar5 + 0x25);
    local_4 = CONCAT31(local_4._1_3_,8);
    FUN_0057c990(puVar5 + 0x28);
  }
  ExceptionList = local_c;
  return;
}


