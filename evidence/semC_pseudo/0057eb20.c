void __fastcall FUN_0057eb20(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  undefined1 local_98 [64];
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  FUN_00477d30(3,&local_a4);
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0x3f800000;
  if (*(int *)(param_1 + 0x1d0) == 1) {
    local_d4 = local_a4 - *(float *)(param_1 + 0x1b8);
    local_d0 = local_a0 - *(float *)(param_1 + 0x1bc);
    local_cc = local_9c - *(float *)(param_1 + 0x1c0);
    local_c8 = local_d4;
    local_c4 = local_d0;
    local_c0 = local_cc;
    FUN_0047ec40();
    puVar1 = (undefined4 *)FUN_0047edc0(local_58,&local_b0,&local_c8);
    local_bc = *puVar1;
    local_b8 = puVar1[1];
    local_b4 = puVar1[2];
    FUN_0047ec40();
    puVar1 = (undefined4 *)FUN_0047edc0(local_4c,&local_c8,&local_bc);
    local_b0 = *puVar1;
    local_ac = puVar1[1];
    local_a8 = puVar1[2];
  }
  else {
    if (*(int *)(param_1 + 0x1d0) != 2) goto LAB_0057ecae;
    local_d4 = local_a4 - *(float *)(param_1 + 0x1b8);
    local_d0 = local_a0 - *(float *)(param_1 + 0x1bc);
    local_cc = local_9c - *(float *)(param_1 + 0x1c0);
    local_c0 = 0.0;
    local_c8 = local_d4;
    local_c4 = local_d0;
    FUN_0047ec40();
    puVar1 = (undefined4 *)FUN_0047edc0(&local_d4,&local_b0,&local_c8);
    local_bc = *puVar1;
    local_b8 = puVar1[1];
    local_b4 = 0;
  }
  FUN_0047ec40();
LAB_0057ecae:
  FUN_00477200();
  FUN_00477b90(0,&local_bc);
  FUN_00477b90(1,&local_b0);
  FUN_00477b90(2,&local_c8);
  FUN_00477b90(3,param_1 + 0x1b8);
  puVar1 = (undefined4 *)FUN_00476f00(local_40,param_1 + 0xd8,local_98);
  puVar3 = (undefined4 *)(param_1 + 0x118);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


