void FUN_00478960(float *param_1)

{
  undefined4 *puVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_24 = -*param_1;
  local_20 = -param_1[1];
  local_1c = -param_1[2];
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  FUN_0047edc0(local_18,&local_30,&local_24);
  puVar1 = (undefined4 *)FUN_0047edc0(local_c,&local_24,local_18);
  local_30 = *puVar1;
  local_2c = puVar1[1];
  local_28 = puVar1[2];
  FUN_00477b90(0,local_18);
  FUN_00477b90(1,&local_30);
  FUN_00477b90(2,&local_24);
  FUN_00477f40(0x3fc90fdb);
  return;
}


